/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * This auto-generated file is not used by Zephyr integration, so a minimal
 * manually modified version is kept in order to build. ADC configuration
 * is generated in the Zephyr shim driver, see zephyr/drivers/adc/adc_nxp_s32_adc_sar.c
 */

#ifndef ADC_SAR_IP_INIT_PBCFG_H
#define ADC_SAR_IP_INIT_PBCFG_H

/**
*   @file
*
*   @addtogroup adc_sar_ip_config Adc Sar IPL Configuration
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
#include "Adc_Sar_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_SAR_IP_VENDOR_ID_INIT_PBCFG                     43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG      4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG      7
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG   0
#define ADC_SAR_IP_SW_MAJOR_VERSION_INIT_PBCFG              2
#define ADC_SAR_IP_SW_MINOR_VERSION_INIT_PBCFG              0
#define ADC_SAR_IP_SW_PATCH_VERSION_INIT_PBCFG              1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Sar_Ip_Init_PBcfg.h file and Adc_Sar_Ip_Types.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID_INIT_PBCFG != ADC_SAR_IP_VENDOR_ID_TYPES)
    #error "Adc_Sar_Ip_Init_PBcfg.h and Adc_Sar_Ip_Types.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip_Init_PBcfg.h file and Adc_Sar_Ip_Types.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_Init_PBcfg.h and Adc_Sar_Ip_Types.h are different"
#endif

/* Check if Adc_Sar_Ip_Init_PBcfg.h file and Adc_Sar_Ip_Types.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION_INIT_PBCFG != ADC_SAR_IP_SW_MAJOR_VERSION_TYPES) || \
     (ADC_SAR_IP_SW_MINOR_VERSION_INIT_PBCFG != ADC_SAR_IP_SW_MINOR_VERSION_TYPES) || \
     (ADC_SAR_IP_SW_PATCH_VERSION_INIT_PBCFG != ADC_SAR_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip_Init_PBcfg.h and Adc_Sar_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define ADCHWUNIT_0_INIT_INSTANCE    (0U)

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
* @brief          ADC SAR Ip Config for Hardware Unit ADC0 for configuration variant Init.
*/
extern const Adc_Sar_Ip_ConfigType AdcHwUnit_0_Init;


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_SAR_IP_INIT_PBCFG_H */

