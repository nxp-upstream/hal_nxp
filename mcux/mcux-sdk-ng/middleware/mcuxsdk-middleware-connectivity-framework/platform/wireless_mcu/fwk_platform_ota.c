/*
 * Copyright 2020 - 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "board.h"
#include "fwk_platform_ota.h"
#include "fsl_adapter_flash.h"
#include "fwk_hal_macros.h"
#include "EmbeddedTypes.h"
#include "fwk_platform_definitions.h"
#include "fwk_config.h"

/************************************************************************************
*************************************************************************************
* Private type definitions and macros
*************************************************************************************
************************************************************************************/

/* Boot ROM interface is in IFR0 OTA configuration data are passed there */

#define IFR_OTACFG_DATA ((ifr0_otacfg_data_t *)IFR_OTA_CFG_ADDR)

#define UPDATE_REQ_MAGIC_WORD         (0x746f4278u) /* "xBot" characters in little endian format */
#define UPDATE_SB_AVAILABLE_EXT_FLASH (0x74784578u) /* "xExt" characters in little endian format */
#define UPD_KEY_SZ                    16
#define UPD_KEY_PATTERN                                                                       \
    0x61, 0x63, 0x74, 0x69, 0x76, 0x61, 0x74, 0x65, 0x53, 0x65, 0x63, 0x72, 0x65, 0x74, 0x78, \
        0x4D                                 /* activateSecretxM */

#define OTACFG_FW_UDPATE_SUCCESS 0x5ac3c35aU /*!< Indicates update was success */
#define OTACFG_FW_UDPATE_FAILURE \
    0x4412d283U /*!<Indicates failure to process sb3 file OR failure to erase/write update status to OTACFG page */

#if defined(__CC_ARM)
extern uint32_t Image$$INT_STORAGE$$Base[];
extern uint32_t Image$$INT_STORAGE$$Length[];
#define gIntFlash_StartOffset_c ((uint32_t)Image$$INT_STORAGE$$Base)
#define gIntFlash_TotalSize_c   ((uint32_t)Image$$INT_STORAGE$$Length)
#else /* defined(__CC_ARM) */
extern uint32_t INT_STORAGE_SIZE[];
extern uint32_t INT_STORAGE_START[];
extern uint32_t INT_STORAGE_SECTOR_SIZE[];
#define gIntFlash_StartOffset_c ((uint32_t)INT_STORAGE_START)
#define gIntFlash_TotalSize_c   ((uint32_t)INT_STORAGE_SIZE)
#endif /* defined(__CC_ARM) */

#define gIntFlash_SectorSize_c ((uint32_t)INT_STORAGE_SECTOR_SIZE)

#define gExtFlash_TotalSize_c   KB(BOARD_OtaExtStoragePartitionKbSize_c)
#define gExtFlash_SectorSize_c  KB(4)
#define gExtFlash_StartOffset_c BOARD_OtaExtStoragePartitionOffset_c

typedef struct
{
    uint32_t updateAvailable;    /*!< 0x0: UPDATE_REQ_MAGIC_WORD */
    uint32_t reserved0[3];
    uint32_t intOrExt;           /*!< 0x10: UPDATE_SB_AVAILBLE_EXT_FLASH */
    uint32_t baudRate;           /*!< 0x14: Baud rate in bps */
    uint32_t updateDumpAddr;     /*!< 0x18: Start address sb3 dumped */
    uint32_t updateFileBytes;    /*!< 0x1C: NoOfBytes of sb3 update file */
    uint32_t updateStatus;       /*!< 0x20: Status after sb3 update by xBoot */
    uint32_t reserved1[3];
    uint8_t  updKey[UPD_KEY_SZ]; /*!< 0x30: secret key to enable ROM FW update instead of xBoot one */
    // uint8_t otaConfig[8128u];
} ifr0_otacfg_data_t;

/************************************************************************************
 * Private memory declarations
 ************************************************************************************/
#if (!(defined(__CC_ARM) || defined(__UVISION_VERSION)))
extern uint32_t NV_STORAGE_START_ADDRESS[];
#else
extern uint32_t Image$$NVM_region$$ZI$$Base[];
#endif /* __CC_ARM */
/************************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
************************************************************************************/
static const OtaPartition_t ext_ota_partition_cfg = {
    .start_offset   = gExtFlash_StartOffset_c,
    .size           = gExtFlash_TotalSize_c,
    .sector_size    = gExtFlash_SectorSize_c,
    .page_size      = 256u,
    .internal_flash = false,
    .spi_baudrate   = MHz(24),
};

static const OtaPartition_t int_ota_partition_cfg = {
    .start_offset   = gIntFlash_StartOffset_c,
    .size           = gIntFlash_TotalSize_c,
    .sector_size    = gIntFlash_SectorSize_c,
    .page_size      = 256u,
    .internal_flash = true,
    .spi_baudrate   = 0,
};

/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/

int PLATFORM_OtaBootDataUpdateOnCommit(const OtaLoaderInfo_t *ota_loader_info)
{
    NOT_USED(ota_loader_info);
    return 0;
}

int PLATFORM_OtaClearBootInterface(void)
{
#ifndef FPGA_TARGET
    return (int)HAL_FlashEraseSector((uint32_t)IFR_OTACFG_DATA, sizeof(ifr0_otacfg_data_t));
#else
    return 0;
#endif
}

int PLATFORM_OtaNotifyNewImageReady(const OtaLoaderInfo_t *ota_loader_info)
{
#ifndef FPGA_TARGET
    int st = -1;
#if defined gOtaCheckEccFaults_d && (gOtaCheckEccFaults_d > 0)
    uint8_t nb_write_attempts = 0u;
#endif
    ifr0_otacfg_data_t otacfg = {
        .updateAvailable = UPDATE_REQ_MAGIC_WORD,
        .reserved0       = {0xffffffffu, 0xffffffffu, 0xffffffffu},
        .intOrExt        = ~UPDATE_SB_AVAILABLE_EXT_FLASH, /* Internal flash OTA by default */
        .baudRate        = 0,
        .updateStatus    = 0xffffffffu, /* Clear it so that xBoot can update Status after sb3 update */
        .reserved1       = {0xffffffffu, 0xffffffffu, 0xffffffffu},
        .updKey          = {UPD_KEY_PATTERN},
    };

    if (!ota_loader_info->partition_desc->internal_flash)
    {
        otacfg.intOrExt = UPDATE_SB_AVAILABLE_EXT_FLASH;
        otacfg.baudRate = ota_loader_info->partition_desc->spi_baudrate;
    }
    otacfg.updateDumpAddr  = ota_loader_info->image_addr; /* SB3 Start address */
    otacfg.updateFileBytes = ota_loader_info->image_sz;   /* SB3 byte size */

    do
    {
        hal_flash_status_t status;

        status = HAL_FlashInit();
        if (kStatus_HAL_Flash_Success != status)
        {
            break;
        }
        status = (hal_flash_status_t)PLATFORM_OtaClearBootInterface();
        if (kStatus_HAL_Flash_Success != status)
        {
            break;
        }
        status = HAL_FlashProgram((uint32_t)IFR_OTACFG_DATA, sizeof(ifr0_otacfg_data_t), (uint8_t *)&otacfg);
        if (kStatus_HAL_Flash_Success != status)
        {
            break;
        }
#if defined gOtaCheckEccFaults_d && (gOtaCheckEccFaults_d > 0)
        /* reading back in place is sufficient to detect ECC faults,
           memory comparison not required, so reusing otacfg as read back buffer */
        status = HAL_FlashReadCheckEccFaults((uint32_t)IFR_OTACFG_DATA, sizeof(ifr0_otacfg_data_t), (uint8_t *)&otacfg);
        if (kStatus_HAL_Flash_Success != status)
        {
            /* ECC error occurred */
            st = -2;
            nb_write_attempts++;
            if (nb_write_attempts < 2u)
            {
                /* retry : status is still -2 */
                continue;
            }
            else
            {
                /* bail out at second failure */
                break;
            }
        }
#endif
        st = 0;
#if defined gOtaCheckEccFaults_d && (gOtaCheckEccFaults_d > 0)
    } while (st < 0);
#else
    } while (false);
#endif

    return st;
#else
    NOT_USED(ota_loader_info);
    return 0;
#endif
}

int PLATFORM_OtaClearBootFlags(void)
{
#ifndef FPGA_TARGET
    int st = -1;
    do
    {
        hal_flash_status_t status;
        uint32_t           updateStatus = 0U;
        status                          = HAL_FlashInit();
        if (kStatus_HAL_Flash_Success != status)
        {
            break;
        }
#if defined gOtaCheckEccFaults_d && (gOtaCheckEccFaults_d > 0)
        status = HAL_FlashReadCheckEccFaults((uint32_t)&IFR_OTACFG_DATA->updateStatus, sizeof(uint32_t),
                                             (uint8_t *)&updateStatus);
        if (kStatus_HAL_Flash_Success != status)
        {
            /* may return kStatus_HAL_Flash_EccError */
            st = -2;
            break;
        }
#else
        updateStatus = IFR_OTACFG_DATA->updateStatus;
#endif
        if (updateStatus == ~0UL)
        {
            st = 1; /* Update Status has remained unscathed */
            break;
        }

        status = HAL_FlashEraseSector((uint32_t)IFR_OTACFG_DATA, sizeof(ifr0_otacfg_data_t));
        if (kStatus_HAL_Flash_Success != status)
        {
            break;
        }
        switch (updateStatus)
        {
            case OTACFG_FW_UDPATE_SUCCESS:
                st = 0;
                break;
            case OTACFG_FW_UDPATE_FAILURE:
                st = 2;
                break;
            default:
                st = 3;
                break;
        }
    } while (false);
    return st;
#else
    return 0;
#endif
}

uint32_t PLATFORM_OtaGetImageOffset(void)
{
    return 0U;
}

const OtaPartition_t *PLATFORM_OtaGetOtaExternalPartitionConfig(void)
{
    return &ext_ota_partition_cfg;
}

const OtaPartition_t *PLATFORM_OtaGetOtaInternalPartitionConfig(void)
{
    return &int_ota_partition_cfg;
}

/*! *********************************************************************************
 * \brief  Perform platfom specific OTA image verification.
 *
 * \param[in] data: byte pointer on candidate image
 * \param[in] size: image size including headers and signatures.
 *
 * \return    0 if image is valid , -1 otherwise
 *
 *********************************************************************************** */
int PLATFORM_OtaCheckImageValidity(const uint8_t *data, uint32_t size)
{
    int ret = 0;
    NOT_USED(data);
    NOT_USED(size);
    /* On KW45 the actual OTA image verification is delegated to the ROM code .
     * This makes a functional difference because the verification is performed on reset only.
     */
    return ret;
}

int PLATFORM_OtaGetImageState(uint8_t *p_state)
{
    int st = PLATFORM_OtaClearBootFlags();
    do
    {
        PlatOtaImgState_t state;
        if (p_state == NULL)
        {
            st = -kStatus_InvalidArgument;
            break;
        }
        state = (PlatOtaImgState_t)*p_state;
        switch (st)
        {
            case 0: /* Previous OTA was successful : running in new image */
            case 1: /* The IFR status is cleared : no OTA was signaled at last reboot : boot leave unchanged */
            case 2: /* Previous OTA failed : remained on previous image */
                if (state == kPlatOtaImg_None)
                {
                    *p_state = (uint8_t)kPlatOtaImg_Permanent;
                }
                break;

            case 3: /* Post reboot the IFR contains an unexpected status */
            default:
                *p_state = (uint8_t)kPlatOtaImg_Fail;
                break;
        }
        st = 0;
    } while (false);
    return st;
}

int PLATFORM_OtaUpdateImageState(uint8_t img_state)
{
    NOT_USED(img_state);
    return 1;
}
