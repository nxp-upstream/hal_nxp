/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_QSPI
*   Dependencies         : None
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.1
*   Build Version        : S32ZE_RTD_2_0_1_D2505_ASR_REL_4_7_REV_0000_20250508
*
*   Copyright 2021-2025 NXP
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef QSPI_IP_CFG_H
#define QSPI_IP_CFG_H

/**
*   @file Qspi_Ip_Cfg.h
*
*   @addtogroup MEM_EXFLS
*   Qspi_Ip_Cfg.h_Artifact
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Qspi_Ip_Types.h"
#include <zephyr/devicetree.h>


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_VENDOR_ID_CFG                    43
#define QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG     7
#define QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG  0
#define QSPI_IP_SW_MAJOR_VERSION_CFG             2
#define QSPI_IP_SW_MINOR_VERSION_CFG             0
#define QSPI_IP_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Number of serial flash devices */
#define QSPI_IP_MEM_INSTANCE_COUNT        DT_NUM_INST_STATUS_OKAY(nxp_s32_qspi_hyperflash)

/* Maximum number of retries for Write Enable command */
#define QSPI_IP_MAX_RETRY                 (3U)

/* Development error detection for QSPI Ip API */
#define QSPI_IP_DEV_ERROR_DETECT          (STD_OFF)

/* Timeout for DLL lock sequence */
#define QSPI_IP_DLL_LOCK_TIMEOUT          (10000000U)

/* Timeout for QSPI command completion */
#define QSPI_IP_CMD_COMPLETE_TIMEOUT      (10000000U)

/* After the FRAD checks pass we wait for QSPI to become idle */
#define QSPI_IP_QSPI_IDLE_TIMEOUT         (100U)

/* Timeout for external flash software reset completion */
#define QSPI_IP_RESET_TIMEOUT             (2000000U)

/* Timeout for external flash startup initialization sequence completion */
#define QSPI_IP_FLS_INIT_TIMEOUT          (2000000U)

/* Timeout for a complete read operation */
#define QSPI_IP_READ_TIMEOUT              (2147483647U)

/* OsIf counter type used in timeout detection for QSPI IP operations  */
#define QSPI_IP_TIMEOUT_TYPE              (OSIF_COUNTER_DUMMY)

/* Delay after changing the value of the QSPI software reset bits */
#define QSPI_IP_SOFTWARE_RESET_DELAY      (21U)

/*! @brief Minimum delay in CPU cycles between Tx FIFO reset and Tx FIFO push */
#define QSPI_IP_TX_BUFFER_RESET_DELAY     (0U)


/* QSPI user mode support macro */
#define QSPI_IP_ENABLE_USER_MODE_SUPPORT  (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == QSPI_IP_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Fls in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
    #endif
#endif

#define QSPI_IP_PERFORM_DEVICE_CONFIG                      (STD_ON)


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define MEM_43_EXFLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

/* Controller connections */
extern const Qspi_Ip_ControllerConfigType Qspi_Ip_paQspiUnitCfg[1U];
/* Memory configurations */
extern const Qspi_Ip_MemoryConfigType Qspi_Ip_paFlashCfg[1U];
/* Memory-controller connections */
extern const Qspi_Ip_MemoryConnectionType Qspi_Ip_paFlashConnectionCfg[1U];

#define MEM_43_EXFLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

#define MEM_43_EXFLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

/* Using the fixed command sets from Qspi_Ip_Hyperflash.c */
extern Qspi_Ip_InstrOpType Qspi_Ip_HyperflashLutTable[];

#define MEM_43_EXFLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QSPI_IP_CFG_H */


