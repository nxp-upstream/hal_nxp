/*
 * Copyright 2022-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LINFLEXD_UART_IP_CFG_H
#define LINFLEXD_UART_IP_CFG_H

/**
*   @file
*   @defgroup linflexd_uart_ip Linflexd UART IPL
*   @addtogroup  linflexd_uart_ip Linflexd UART IPL
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                        INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
 4) user callback header files
==================================================================================================*/

#include "Linflexd_Uart_Ip_Sa_Init_PBcfg.h"

#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_UART_IP_CFG_VENDOR_ID                     43
#define LINFLEXD_UART_IP_CFG_AR_RELEASE_MAJOR_VERSION      4
#define LINFLEXD_UART_IP_CFG_AR_RELEASE_MINOR_VERSION      7
#define LINFLEXD_UART_IP_CFG_AR_RELEASE_REVISION_VERSION   0
#define LINFLEXD_UART_IP_CFG_SW_MAJOR_VERSION              2
#define LINFLEXD_UART_IP_CFG_SW_MINOR_VERSION              0
#define LINFLEXD_UART_IP_CFG_SW_PATCH_VERSION              1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Linflexd_Uart_Ip_Init_PBcfg.h */
#if (LINFLEXD_UART_IP_CFG_VENDOR_ID != LINFLEXD_UART_IP_SA_INIT_PBCFG_VENDOR_ID)
    #error "Linflexd_Uart_Ip_Cfg.h and Linflexd_Uart_Ip_Sa_Init_PBcfg.h have different vendor ids"
#endif
#if ((LINFLEXD_UART_IP_CFG_AR_RELEASE_MAJOR_VERSION    != LINFLEXD_UART_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_CFG_AR_RELEASE_MINOR_VERSION    != LINFLEXD_UART_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_CFG_AR_RELEASE_REVISION_VERSION != LINFLEXD_UART_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Linflexd_Uart_Ip_Cfg.h and Linflexd_Uart_Ip_Sa_Init_PBcfg.h are different"
#endif
#if ((LINFLEXD_UART_IP_CFG_SW_MAJOR_VERSION != LINFLEXD_UART_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_CFG_SW_MINOR_VERSION != LINFLEXD_UART_IP_SA_INIT_PBCFG_SW_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_CFG_SW_PATCH_VERSION != LINFLEXD_UART_IP_SA_INIT_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Uart_Ip_Cfg.h and Linflexd_Uart_Ip_Sa_Init_PBcfg.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types.h header file are of the same Autosar version */
    #if ((LINFLEXD_UART_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LINFLEXD_UART_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Linflexd_Uart_Ip_Cfg.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define LINFLEXD_UART_IP_CONFIG_EXT \
     LINFLEXD_UART_IP_SA_CONFIG_INIT_PB \
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define UART_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Uart_MemMap.h"

extern Linflexd_Uart_Ip_StateStructureType Linflexd_Uart_Ip_apStateStructure[LINFLEXD_UART_IP_NUMBER_OF_INSTANCES];

/** @brief Array of pointers to UART driver runtime state structures */
extern Linflexd_Uart_Ip_StateStructureType* Linflexd_Uart_Ip_apStateStructuresArray[LINFLEXD_IP_INSTANCE_COUNT];

#define UART_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Uart_MemMap.h"

#define UART_START_SEC_CODE
#include "Uart_MemMap.h"
extern void nxp_s32_uart_callback(uint8 HwInstance, Linflexd_Uart_Ip_EventType Event, const void *UserData);
#define UART_STOP_SEC_CODE
#include "Uart_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LINFLEXD_UART_IP_CFG_H */
