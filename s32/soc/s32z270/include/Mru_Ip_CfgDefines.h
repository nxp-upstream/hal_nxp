/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
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
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
#ifndef MRU_IP_CFG_DEFINES_H_
#define MRU_IP_CFG_DEFINES_H_

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MRU_IP_CFG_DEFINES_VENDOR_ID                          43
#define CDD_PLATFORM_MRU_IP_CFG_DEFINES_SW_MAJOR_VERSION                   2
#define CDD_PLATFORM_MRU_IP_CFG_DEFINES_SW_MINOR_VERSION                   0
#define CDD_PLATFORM_MRU_IP_CFG_DEFINES_SW_PATCH_VERSION                   1
#define CDD_PLATFORM_MRU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION           4
#define CDD_PLATFORM_MRU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION           7
#define CDD_PLATFORM_MRU_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION        0
/*==================================================================================================
                                            CONSTANTS
==================================================================================================*/
 
/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/

/** @brief    IP enablement checking */
#define PLATFORM_IP_ENABLE_MRU      (STD_ON)

/**
* @brief          Enable User Mode Support.
* @details        When GeneralConfiguration/PlatformEnableUserModeSupport = TRUE,
*                 the MRU driver can be executed from both supervisor and user mode.
*
* @api
*/
#define MRU_IP_ENABLE_USER_MODE_SUPPORT  (STD_OFF)
/**
* @brief Switches ON or OFF for the detection and reporting of development errors(API parameter checking) at IP level.
*/
/** @implements MRU_IP_DEV_ERROR_DETECT_define  */
#define MRU_IP_DEV_ERROR_DETECT     (STD_OFF)

/** @brief Adds or removes the service Mru_Ip_ResetChannel(). */
#define MRU_IP_CHANNEL_RESET_API     (STD_OFF)

/** @brief Adds or removes the service Mru_Ip_ResetInstance(). */
#define MRU_IP_INSTANCE_RESET_API     (STD_OFF)

/** @brief Adds or removes the service Mru_Ip_EnableChannel(). */
#define MRU_IP_CHANNEL_ENABLE_API     (STD_OFF)

/** @brief Adds or removes the service Mru_Ip_DisableChannel(). */
#define MRU_IP_CHANNEL_DISABLE_API     (STD_OFF)

#define NOTIFY_STATUS_COUNT (2U)
#define INTERRUPT_GROUP_0                 (0U)
#define INTERRUPT_GROUP_1                 (1U)

#define MRU_IP_CH_CFG0_CHE_MASK                 (0x1U)
#define MRU_IP_CH_CFG0_IE_MASK                  (0x4U)
#define MRU_IP_CH_MBSTAT_MBS0_MASK              (0x10000U)
#define MRU_IP_CH_CFG0_MBE0_MASK                (0x10000U)
#define MRU_CH_MBSTAT_MBS0_WIDTH                (1U)
#define MRU_IP_MRU_CH_CFG0_MBE0_SHIFT           (16U)
#define MRU_IP_CH_MBSTAT_MBS0_SHIFT             (16U)
#define MRU_IP_CH_CFG1_MBIC0_MASK               (0x10000U)
#define MRU_IP_CH_CFG1_MBIC0_SHIFT              (16U)
#define MRU_CH_CFG1_MBIC0_WIDTH                 (1U)

#define MRU_IP_NOTIFY_CH1_IS_MASK               (0x1U) /*The notify status mask of first channel*/

/**
* @brief    MRU timeout type
*/
#define PLATFORM_TIMEOUT_TYPE                   (OSIF_COUNTER_DUMMY)

#ifdef __cplusplus
}
#endif

#endif /* MRU_IP_CFG_DEFINES_H_ */

/** @} */


