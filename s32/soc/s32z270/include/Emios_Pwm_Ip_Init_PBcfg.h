/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Gtm Emios Etimer FlexPwm
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
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef EMIOS_PWM_IP_INIT_PBCFG_H
#define EMIOS_PWM_IP_INIT_PBCFG_H

/**
*   @file       Emios_Pwm_Ip_Init_PBcfg.h
*
*   @addtogroup emios_pwm_ip Emios Pwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <zephyr/devicetree.h>

#include "Emios_Pwm_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_INIT_PB_CFG_VENDOR_ID                       43
#define EMIOS_PWM_IP_INIT_PB_CFG_MODULE_ID                       121
#define EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_PWM_IP_INIT_PB_CFG_SW_MAJOR_VERSION                2
#define EMIOS_PWM_IP_INIT_PB_CFG_SW_MINOR_VERSION                0
#define EMIOS_PWM_IP_INIT_PB_CFG_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Emios_Pwm_Ip_Types header file are of the same vendor */
#if (EMIOS_PWM_IP_INIT_PB_CFG_VENDOR_ID != EMIOS_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip_Init_PBcfg.h and Emios_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Types header file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_MAJOR_VERSION    != EMIOS_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_MINOR_VERSION    != EMIOS_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_REVISION_VERSION != EMIOS_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip_Init_PBcfg.h and Emios_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Types header file are of the same software version */
#if ((EMIOS_PWM_IP_INIT_PB_CFG_SW_MAJOR_VERSION != EMIOS_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_INIT_PB_CFG_SW_MINOR_VERSION != EMIOS_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (EMIOS_PWM_IP_INIT_PB_CFG_SW_PATCH_VERSION != EMIOS_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip_Init_PBcfg.h and Emios_Pwm_Ip_Types.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

#define DT_DRV_COMPAT                     nxp_s32_emios_pwm

#define EMIOS_OPWFMB_MODE_USED(node_id)                                                    \
            COND_CODE_1(DT_NODE_HAS_PROP(node_id, pwm_mode),                               \
                       (DT_ENUM_HAS_VALUE(node_id, pwm_mode, OPWFMB)),                     \
                       (0)) ||

#define IS_EMIOS_OPWFMB_MODE_USED(n)                                                       \
            DT_INST_FOREACH_CHILD_STATUS_OKAY(n, EMIOS_OPWFMB_MODE_USED)

#define EMIOS_OPWMB_MODE_USED(node_id)                                                     \
            COND_CODE_1(DT_NODE_HAS_PROP(node_id, pwm_mode),                               \
                       (DT_ENUM_HAS_VALUE(node_id, pwm_mode, OPWMB)),                      \
                       (0)) ||

#define IS_EMIOS_OPWMB_MODE_USED(n)                                                        \
            DT_INST_FOREACH_CHILD_STATUS_OKAY(n, EMIOS_OPWMB_MODE_USED)

#define EMIOS_OPWMCB_MODE_USED(node_id)                                                    \
            COND_CODE_1(DT_NODE_HAS_PROP(node_id, pwm_mode),                               \
                       (DT_ENUM_HAS_VALUE(node_id, pwm_mode, OPWMCB_TRAIL_EDGE) ||         \
                        DT_ENUM_HAS_VALUE(node_id, pwm_mode, OPWMCB_LEAD_EDGE)             \
                        ),(0)) ||

#define IS_EMIOS_OPWMCB_MODE_USED(n)                                                       \
            DT_INST_FOREACH_CHILD_STATUS_OKAY(n, EMIOS_OPWMCB_MODE_USED)
/* Macro to enable the mode operations. */
#if DT_INST_FOREACH_STATUS_OKAY(IS_EMIOS_OPWFMB_MODE_USED) 0
#define EMIOS_PWM_IP_MODE_OPWFMB_USED
#endif

#if DT_INST_FOREACH_STATUS_OKAY(IS_EMIOS_OPWMB_MODE_USED) 0
#define EMIOS_PWM_IP_MODE_OPWMB_USED
#endif

#if DT_INST_FOREACH_STATUS_OKAY(IS_EMIOS_OPWMCB_MODE_USED) 0
#define EMIOS_PWM_IP_MODE_OPWMCB_USED
#endif

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_PWM_IP_INIT_PBCFG_H */

