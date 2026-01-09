/*
 * Copyright 2020-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_common.h"
#include "fwk_hal_macros.h"
#include "fwk_platform_ota.h"
#include "mflash_drv.h"
#include "fwk_platform_extflash.h"
#include "fwk_config.h"
#include "FunctionLib.h"

#ifdef OTA_DEBUG
#include "fsl_debug_console.h"
#endif
/************************************************************************************
*************************************************************************************
* Private type definitions and macros
*************************************************************************************
************************************************************************************/

/* mflash_drv.h defines MFLASH_REMAP_ACTIVE and MFLASH_REMAP_OFFSET if remap is
 * supported by the platform */
#if !defined MFLASH_REMAP_ACTIVE
#define MFLASH_REMAP_ACTIVE() false
#endif

#if !defined MFLASH_REMAP_OFFSET
#define MFLASH_REMAP_OFFSET() 0U
#endif

/*!
 * \brief The following symbols give information on the firmware update storage section location
 *        and size must be provided by the linker.
 *        FW_UPDATE_STORAGE_OFFSET: Offset address of the firmware update storage
 *        relative to the start address of the flash
 *        FW_UPDATE_STORAGE_SIZE: Size of the whole firmware update storage section.
 *
 */
extern uint32_t FW_UPDATE_STORAGE_OFFSET[];
extern uint32_t FW_UPDATE_STORAGE_SIZE[];
extern uint32_t FW_ACTIVE_APP_OFFSET[];
extern uint32_t FW_ACTIVE_APP_SIZE[];

#define gExtFlash_OtaStartOffset_c ((uint32_t)FW_UPDATE_STORAGE_OFFSET)

#define gExtFlash_TotalSize_c  ((uint32_t)FW_UPDATE_STORAGE_SIZE)
#define gExtFlash_SectorSize_c KB(4)

#ifndef _SECTOR_ADDR
#define _SECTOR_ADDR(x) (((x) & ~(PLATFORM_EXTFLASH_SECTOR_SIZE - 1U)))
#endif
#ifndef _PAGE_ADDR
#define _PAGE_ADDR(x) (((x) & ~(PLATFORM_EXTFLASH_PAGE_SIZE - 1U)))
#endif
#define _ROUND_TO_UPPER_SECT(x) _SECTOR_ADDR(((x) + (PLATFORM_EXTFLASH_SECTOR_SIZE - 1U)))
#define _ROUND_TO_LOWER_SECT(x) _SECTOR_ADDR((x))

/* Stuff related to OTA */
#define FLASH_CONFIG_OFFSET 0x400U  /* The Flash Config is placed in the 1rst sector */
#define BOOTLOADER_OFFSET   0U      /* MCU boot is located at a sector frontier */
#define BOOTLOADER_SIZE     KB(128) /* MCU boot Stated size */

/* Image size if rounded to a size multiple of sectors size (4kB) */
#define IMAGE_SIZE ((uint32_t)FW_ACTIVE_APP_SIZE)

/* Offset of Slot#1 partition */
#define FLASH_AREA_IMAGE_1_OFFSET ((uint32_t)FW_ACTIVE_APP_OFFSET)
#define FLASH_AREA_IMAGE_1_SIZE   IMAGE_SIZE
/* Offset of Slot#2 partition */
#define FLASH_AREA_IMAGE_2_OFFSET ((uint32_t)FW_UPDATE_STORAGE_OFFSET)
#define FLASH_AREA_IMAGE_2_SIZE   IMAGE_SIZE /* But slots are equally sized */

/* Start offset of the active application is the primary slot if no remap is active, otherwise it must be the secondary
 * slot */
#define ACTIVE_IMAGE_OFFSET(_remap_) ((_remap_) ? FLASH_AREA_IMAGE_2_OFFSET : FLASH_AREA_IMAGE_1_OFFSET)
/* Start offset of the secondary application partition (Candidate App) */
#define CANDIDATE_IMAGE_OFFSET(_remap_) ((_remap_) ? FLASH_AREA_IMAGE_1_OFFSET : FLASH_AREA_IMAGE_2_OFFSET)

/* Image Header */
#define IMAGE_MAGIC       0x96f3b83dU
#define IMAGE_HEADER_SIZE 32

/* Image trailer */
#define BOOT_MAX_ALIGN 8
#define BOOT_FLAG_SET  0x01u
#define BOOT_FLAG_CLR  0x00u

/*
    Image trailer contents combinations:
    Magic SET   – image_ok=0x01  – copy_done=0x01 => valid permanent image
    Magic SET   – image_ok=0x00  – copy_done=0x01 => image runs for first time (testing), second time run without image
   ok 1 leads to revert Magic SET   – image_ok=0x00  – copy_done=0x00 => image marked for test (ReadyForTest) Magic
   UNSET – image_ok=0xff  – copy done=0xff => invalid for DIRECT-XIP mode when an image is detected (SWAP mode by design
   somehow it evaluates as ReadyForTest state)
*/

struct image_version
{
    uint8_t  iv_major;
    uint8_t  iv_minor;
    uint16_t iv_revision;
    uint32_t iv_build_num;
};

/** Image header.  All fields are in little endian byte order. */
struct image_header
{
    uint32_t             ih_magic;
    uint32_t             ih_load_addr;
    uint16_t             ih_hdr_size;         /* Size of image header (bytes). */
    uint16_t             ih_protect_tlv_size; /* Size of protected TLV area (bytes). */
    uint32_t             ih_img_size;         /* Does not include header. */
    uint32_t             ih_flags;            /* IMAGE_F_[...]. */
    struct image_version ih_ver;
    uint32_t             _pad1;
};

#define BOOT_TLV_OFF(hdr) ((hdr)->ih_hdr_size + (hdr)->ih_img_size)

#define IMAGE_TLV_INFO_MAGIC      0x6907
#define IMAGE_TLV_PROT_INFO_MAGIC 0x6908

/** Image TLV header.  All fields in little endian. */
struct image_tlv_info
{
    uint16_t it_magic;
    uint16_t it_tlv_tot; /* size of TLV area (including tlv_info header) */
};

struct image_trailer
{
    uint8_t swap_type;
    uint8_t pad1[BOOT_MAX_ALIGN - 1];
    uint8_t copy_done;
    uint8_t pad2[BOOT_MAX_ALIGN - 1];
    uint8_t image_ok;
    uint8_t pad3[BOOT_MAX_ALIGN - 1];
    uint8_t magic[16];
};

#if gPlatformMcuBootUseRemap_d
#define ACTIVE_TRAILER_OFFSET(_remap_)                                                       \
    (ACTIVE_IMAGE_OFFSET(_remap_) + FLASH_AREA_IMAGE_1_SIZE - sizeof(struct image_trailer) + \
     PLATFORM_EXTFLASH_SECTOR_SIZE)
#define CANDIDATE_TRAILER_OFFSET(_remap_)                                                       \
    (CANDIDATE_IMAGE_OFFSET(_remap_) + FLASH_AREA_IMAGE_2_SIZE - sizeof(struct image_trailer) + \
     PLATFORM_EXTFLASH_SECTOR_SIZE)
#else /* gPlatformMcuBootUseRemap_d */
#define ACTIVE_TRAILER_OFFSET(_remap_) \
    (ACTIVE_IMAGE_OFFSET(_remap_) + FLASH_AREA_IMAGE_1_SIZE - sizeof(struct image_trailer))
#define CANDIDATE_TRAILER_OFFSET(_remap_) \
    (CANDIDATE_IMAGE_OFFSET(_remap_) + FLASH_AREA_IMAGE_2_SIZE - sizeof(struct image_trailer))
#endif /* gPlatformMcuBootUseRemap_d*/

/** Remap configuration structure : used to read or potentially write FlexSPI configuration for remap capable platforms.
 */
typedef struct
{
    uint32_t start_addr;
    uint32_t end_addr;
    uint32_t offset;
} RemapConfig_t;

/************************************************************************************
 * Private memory declarations
 ************************************************************************************/

const uint32_t trailer_img_magic[] = {
    0xf395c277,
    0x7fefd260,
    0x0f505235,
    0x8079b62c,
};
/*
 * If the FlexSPI remap mechanism is being used the OTA is to be performed in place in the alternate slot.
 * The OTA partition location depends on the application that is currently running : if remapping is active the active
 * image is located in the secondary slot, so the OTA must occur in the primary slot.
 */
static OtaPartition_t ota_partition_cfg = {.start_offset   = gExtFlash_OtaStartOffset_c,
                                           .size           = gExtFlash_TotalSize_c,
                                           .sector_size    = gExtFlash_SectorSize_c,
                                           .page_size      = 256u,
                                           .internal_flash = false};

/************************************************************************************
*************************************************************************************
* Function prototypes
*************************************************************************************
************************************************************************************/

/*
 * \brief Tell whether active application is set.
 * Note: Must be used when MCUBOOT remap is used for OTA.
 * Indeed direct flash access to remapped flash areas is not possible.
 * \return true if remapping is active.
 */
extern bool PLATFORM_IsActiveApplicationRemapped(void);

/************************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
************************************************************************************/
static int trailer_img_magic_check(uint8_t *p)
{
    return FLib_MemCmp(p, (uint8_t *)trailer_img_magic, sizeof(trailer_img_magic));
}

static int check_unset(uint8_t *p, uint32_t length)
{
    return FLib_MemCmpToVal(p, 0xFFU, length);
}

static status_t boot_wipe_candidate_trailer(void)
{
    bool     is_app_remapped  = MFLASH_REMAP_ACTIVE();
    uint32_t candidate_offset = CANDIDATE_TRAILER_OFFSET(is_app_remapped);
    return PLATFORM_EraseExternalFlash(candidate_offset, PLATFORM_EXTFLASH_SECTOR_SIZE);
}

#if OTA_DEBUG
extern uint8_t copy_done_setpoint;
extern uint8_t image_ok_setpoint;
#endif

static status_t boot_swap_test(void)
{
    uint32_t              off;
    status_t              status;
    struct image_trailer *image_trailer_p;

    uint32_t buf[PLATFORM_EXTFLASH_PAGE_SIZE / 4]; /* ensure the buffer is word aligned */
    image_trailer_p = (struct image_trailer *)&buf[(PLATFORM_EXTFLASH_PAGE_SIZE - sizeof(struct image_trailer)) / 4];
    do
    {
        bool is_app_remapped = MFLASH_REMAP_ACTIVE();
        off                  = CANDIDATE_TRAILER_OFFSET(is_app_remapped);

        memset(buf, 0xff, PLATFORM_EXTFLASH_PAGE_SIZE);
        memcpy(image_trailer_p->magic, trailer_img_magic, sizeof(trailer_img_magic));
        image_trailer_p->copy_done = 0xff; /* explicit but useless because image_trailer is with buf[] that is preset */
        image_trailer_p->copy_done = 0xff;

        status = PLATFORM_EraseExternalFlash(off, sizeof(trailer_img_magic));
        if (status != kStatus_Success)
        {
#ifdef OTA_DEBUG
            PRINTF("%s: failed to erase trailer2\r\n", __FUNCTION__);
#endif
            break;
        }

        status = PLATFORM_WriteExternalFlash((uint8_t *)buf, PLATFORM_EXTFLASH_PAGE_SIZE, _PAGE_ADDR(off));
        if (status != kStatus_Success)
        {
#ifdef OTA_DEBUG
            PRINTF("%s: failed to write trailer2\r\n", __FUNCTION__);
#endif
            break;
        }
        else
        {
#ifdef OTA_DEBUG
            uint8_t read_buf[PLATFORM_EXTFLASH_PAGE_SIZE];
            PRINTF("%s: Wrote trailer at offset %08x %08x", __FUNCTION__, off, _PAGE_ADDR(off));
            status =
                PLATFORM_ReadExternalFlash((uint8_t *)read_buf, PLATFORM_EXTFLASH_PAGE_SIZE, _PAGE_ADDR(off), false);
            struct image_trailer *img_trailer_rd;
            img_trailer_rd =
                (struct image_trailer *)&read_buf[PLATFORM_EXTFLASH_PAGE_SIZE - sizeof(struct image_trailer)];
            PRINTF("Read trailer from %x\r\n", off);
            PRINTF("trailer_magic = %x %x %x %x\r\n", *(uint32_t *)&img_trailer_rd->magic[0],
                   *(uint32_t *)&img_trailer_rd->magic[4], *(uint32_t *)&img_trailer_rd->magic[8],
                   *(uint32_t *)&img_trailer_rd->magic[12]);
#endif
        }
    } while (false);
    return status;
}

int PLATFORM_OtaClearBootInterface(void)
{
    uint32_t off;
    status_t status;

    bool is_app_remapped = MFLASH_REMAP_ACTIVE();

    off = CANDIDATE_TRAILER_OFFSET(is_app_remapped);

    status = PLATFORM_EraseExternalFlash(off, sizeof(trailer_img_magic));
    if (status != kStatus_Success)
    {
#ifdef OTA_DEBUG
        PRINTF("%s: failed to erase trailer2\r\n", __FUNCTION__);
#endif
    }

    return (int)status;
}

status_t boot_swap_perm(void)
{
    status_t status;

    uint32_t              buf[PLATFORM_EXTFLASH_PAGE_SIZE / 4]; /* ensure the buffer is word aligned */
    struct image_trailer *image_trailer_p =
        (struct image_trailer *)((uint8_t *)buf + PLATFORM_EXTFLASH_PAGE_SIZE - sizeof(struct image_trailer));

    memset(buf, 0xff, PLATFORM_EXTFLASH_PAGE_SIZE);
    memcpy(image_trailer_p->magic, trailer_img_magic, sizeof(trailer_img_magic));
    image_trailer_p->image_ok  = BOOT_FLAG_SET;
    image_trailer_p->copy_done = BOOT_FLAG_SET;

    do
    {
        uint32_t off;
        bool     is_app_remapped = MFLASH_REMAP_ACTIVE();

        off = CANDIDATE_TRAILER_OFFSET(is_app_remapped);

        status = PLATFORM_EraseExternalFlash(off, sizeof(trailer_img_magic));
        if (status != kStatus_Success)
        {
            break;
        }

        status = PLATFORM_WriteExternalFlash((uint8_t *)buf, PLATFORM_EXTFLASH_PAGE_SIZE, _PAGE_ADDR(off));
        if (status != kStatus_Success)
        {
#ifdef OTA_DEBUG
            PRINTF("%s: failed to write trailer2\r\n", __FUNCTION__);
#endif
            break;
        }
    } while (false);

    return status;
}

static status_t boot_swap_ok(void)
{
    status_t status;

    uint32_t              buf[PLATFORM_EXTFLASH_PAGE_SIZE / 4]; /* ensure the buffer is word aligned */
    struct image_trailer *image_trailer_p =
        (struct image_trailer *)((uint8_t *)buf + PLATFORM_EXTFLASH_PAGE_SIZE - sizeof(struct image_trailer));

    do
    {
        uint32_t page_off;
        bool     is_app_remapped = MFLASH_REMAP_ACTIVE();
        page_off                 = ACTIVE_TRAILER_OFFSET(is_app_remapped);
        page_off                 = _PAGE_ADDR(page_off);
        status = PLATFORM_ReadExternalFlash((uint8_t *)buf, PLATFORM_EXTFLASH_PAGE_SIZE, page_off, false);
        if (status != kStatus_Success)
        {
#ifdef OTA_DEBUG
            PRINTF("%s: failed to read trailer\r\n", __FUNCTION__);
#endif
            break;
        }

        if ((trailer_img_magic_check(image_trailer_p->magic) == 0) || (image_trailer_p->copy_done != 0x01))
        {
            /* the image in the slot is likely incomplete (or none) */
#ifdef OTA_DEBUG
            PRINTF("%s: no image awaiting confirmation\r\n", __FUNCTION__);
#endif
            status = kStatus_Fail; /* No data */
            break;
        }

        if (image_trailer_p->image_ok == BOOT_FLAG_SET)
        {
            /* nothing to be done, report it and return */
#ifdef OTA_DEBUG
            PRINTF("%s: image already confirmed\r\n", __FUNCTION__);
#endif
            status = kStatus_Success; /* set it explicitly */
            break;
        }

        /* mark image ok */
        image_trailer_p->image_ok = BOOT_FLAG_SET;

        /* erase trailer */
        status = PLATFORM_EraseExternalFlash(_SECTOR_ADDR(page_off), PLATFORM_EXTFLASH_SECTOR_SIZE);
        if (status != kStatus_Success)
        {
#ifdef OTA_DEBUG
            PRINTF("%s: failed to erase trailer\r\n", __FUNCTION__);
#endif
            break;
        }

        /* write trailer */
        status = PLATFORM_WriteExternalFlash((uint8_t *)buf, PLATFORM_EXTFLASH_PAGE_SIZE, page_off);
        if (status != kStatus_Success)
        {
#ifdef OTA_DEBUG
            PRINTF("%s: failed to write trailer\r\n", __FUNCTION__);
#endif
            break;
        }
    } while (false);
    return status;
}

/*! *********************************************************************************
 * \brief  Patch candidate image's trailer to mark it 'ready for test' or 'permanent'
 *
 * \param[in] img_state: kPlatOtaImg_CandidateRdy or kPlatOtaImg_Permanent are expected
 *
 * \return    kStatus_InvalidArgument is cur_state out of expected set.
 *            k_Status_Success if flash operations succeed.
 *********************************************************************************** */
int PLATFORM_OtaUpdateImageState(uint8_t img_state)
{
    status_t ret;

    switch (img_state)
    {
        case kPlatOtaImg_CandidateRdy:
            ret = boot_swap_test();
            break;

        case kPlatOtaImg_Permanent:
            ret = boot_swap_ok();
            break;

        default:
            ret = kStatus_InvalidArgument;
            break;
    }

    return (int)ret;
}

/*! *********************************************************************************
 * \brief  Read the primary and secondary slot image trailers and determine image state
 *         checking the contents.
 *
 *
 *
 * \param[in] p_state: pointer on state enum to pass value deduced from current and
 *           candidate application trailer contents.
 *           The value returned in p_state can be one of:
 *           - kPlatOtaImg_CandidateRdy: if candidate trailer is correct but the remainder unset.
 *           - kPlatOtaImg_Permanent: if candidate trailer's magic is correct and image marked OK.
 *           - kPlatOtaImg_RunCandidate:  if active image has magic set and copy_done, it is an application
 *             under probation, waiting for confirmation to become permanent.
 *           - kPlatOtaImg_None in other cases if no error.
 *           - kPlatOtaImg_Fail if an error occurs while reading the external flash
 *.
 *
 * \return    kStatus_Success if flash operations succeed otherwise status of failing operation.
 *            Disregard *p_state if not kStatus_Success.
 *********************************************************************************** */
int PLATFORM_OtaGetImageState(uint8_t *p_state)
{
    int ret = -1;

    do
    {
        uint32_t             trailer_offset[2];
        struct image_trailer image_trailer[2];

        bool is_app_remapped = MFLASH_REMAP_ACTIVE();

        /* 0 is the active trailer, 1: the other */
        /* If the active partition does not  */
        trailer_offset[0] = ACTIVE_TRAILER_OFFSET(is_app_remapped);
        trailer_offset[1] = CANDIDATE_TRAILER_OFFSET(is_app_remapped);

        PlatOtaImgState_t state;
        if (p_state == NULL)
        {
            ret = kStatus_InvalidArgument;
            break;
        }
        state = (PlatOtaImgState_t)*p_state;
        if (state == kPlatOtaImg_None)
        {
            *p_state = kPlatOtaImg_Fail;
            ret      = PLATFORM_ReadExternalFlash((uint8_t *)&image_trailer[0], sizeof(struct image_trailer),
                                                  trailer_offset[0], false);
            if (ret != kStatus_Success)
            {
#ifdef OTA_DEBUG
                PRINTF("%s: failed to read trailer%d\r\n", __FUNCTION__, 1);
#endif
                break;
            }

            ret = PLATFORM_ReadExternalFlash((uint8_t *)&image_trailer[1], sizeof(struct image_trailer),
                                             trailer_offset[1], false);
            if (ret != kStatus_Success)
            {
#ifdef OTA_DEBUG
                PRINTF("%s: failed to read trailer$d\r\n", __FUNCTION__, 2);
#endif
                break;
            }
            /* Check the running active image : if the boot loader has let it */
            if (trailer_img_magic_check(image_trailer[0].magic))
            {
                if (image_trailer[0].image_ok == 0xffu)
                {
                    if (image_trailer[0].copy_done == 0x01u)
                    {
                        /* State I (request for swapping upon next reboot) */
                        *p_state = kPlatOtaImg_RunCandidate;
                        ret      = kStatus_Success;
                        break;
                    }
                    else
                    {
                        *p_state = kPlatOtaImg_Fatal;
                        ret      = kStatus_Success;
                        break;
                    }
                }
                else if (image_trailer[0].image_ok == 0x00u)
                {
                    *p_state = kPlatOtaImg_Fatal;
                    ret      = kStatus_Success;
                    break;
                }
                else if (image_trailer[0].image_ok == 0x01u)
                {
                    *p_state = kPlatOtaImg_Permanent;
                    ret      = kStatus_Success;
                    break;
                }
            }
            else if (check_unset(image_trailer[1].magic, sizeof(image_trailer[1].magic)))
            {
                if (trailer_img_magic_check(image_trailer[0].magic) && (image_trailer[0].image_ok == 0xff) &&
                    (image_trailer[0].copy_done == 0x01))
                {
                    /* State III (revert scheduled for next reboot => image is under test) */
                    *p_state = kPlatOtaImg_RunCandidate;
                    ret      = kStatus_Success;
                    break;
                }
            }
            *p_state = kPlatOtaImg_None; /* State IV default */
        }
        ret = kStatus_Success;
    } while (false);

    return ret;
}

/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/

int PLATFORM_OtaBootDataUpdateOnCommit(const OtaLoaderInfo_t *ota_loader_info)
{
    uint32_t size = ota_loader_info->image_sz;
    return PLATFORM_OtaCheckImageValidity((const uint8_t *)ota_loader_info->image_addr, size);
}

int PLATFORM_OtaNotifyNewImageReady(const OtaLoaderInfo_t *ota_loader_info)
{
    int st = -1;
    NOT_USED(ota_loader_info);
    status_t status;
    status = PLATFORM_OtaUpdateImageState(kPlatOtaImg_CandidateRdy);
    if (status == kStatus_Success)
    {
        st = 0;
    }
    return st;
}

int PLATFORM_OtaClearBootFlags(void)
{
    int st = -1;
    if (boot_wipe_candidate_trailer() == kStatus_Success)
    {
        st = 0;
    }
    return st;
}

uint32_t PLATFORM_OtaGetImageOffset(void)
{
    return 0u;
}

const OtaPartition_t *PLATFORM_OtaGetOtaInternalPartitionConfig(void)
{
    return NULL;
}

const OtaPartition_t *PLATFORM_OtaGetOtaExternalPartitionConfig(void)
{
    bool is_app_remapped           = MFLASH_REMAP_ACTIVE();
    ota_partition_cfg.start_offset = CANDIDATE_IMAGE_OFFSET(is_app_remapped);
    return &ota_partition_cfg;
}

/*! *********************************************************************************
 * \brief  Perform validity checks on candidate image header
 *
 * \param[in] img_addr: byte pointer on candidate image - actually offset in flash not address)
 * \param[in] size: image size including header.
 *
 * \return    0 if image is valid , -1 otherwise
 *
 *********************************************************************************** */
int PLATFORM_OtaCheckImageValidity(const uint8_t *img_addr, uint32_t size)
{
    struct image_header   ih;
    struct image_tlv_info info;
    int                   ret = -1;

    do
    {
        int      st;
        uint32_t img_offset = (uint32_t)img_addr;
        uint32_t tlv_info_offset;

        /* do we have at least the header */
        if (size < sizeof(struct image_header))
        {
            break;
        }
        st = PLATFORM_ReadExternalFlash((uint8_t *)&ih, sizeof(ih), img_offset, false);
        if (st != kStatus_Success)
        {
            break;
        }
        /* check magic number in image header */
        if (ih.ih_magic != IMAGE_MAGIC)
        {
            break;
        }

        if (size < (BOOT_TLV_OFF(&ih) + sizeof(info)))
        {
            break;
        }

        /* check that we have at least the amount of data declared by the header */
        /* Read the TLV found at after image header and image content */
        tlv_info_offset = img_offset + BOOT_TLV_OFF(&ih);

        st = PLATFORM_ReadExternalFlash((uint8_t *)&info, sizeof(info), tlv_info_offset, false);
        if (st != kStatus_Success)
        {
            break;
        }

        if (info.it_magic == IMAGE_TLV_PROT_INFO_MAGIC)
        {
            if (ih.ih_protect_tlv_size != info.it_tlv_tot)
            {
                break;
            }
            /* Re-read TLV from protected TLV offset */
            if (size < tlv_info_offset + info.it_tlv_tot)
            {
                break;
            }
            st = PLATFORM_ReadExternalFlash((uint8_t *)&info, sizeof(info), (tlv_info_offset + info.it_tlv_tot), false);
            if (st != kStatus_Success)
            {
                break;
            }
        }
        else
        {
            if (ih.ih_protect_tlv_size != 0)
            {
                /* if magic does not say protected TLV ih_protect_tlv_size must be 0 */
                if (info.it_magic != IMAGE_TLV_INFO_MAGIC)
                {
                    break;
                }

                break;
            }
        }

        ret = 0;

    } while (false);
    return ret;
}