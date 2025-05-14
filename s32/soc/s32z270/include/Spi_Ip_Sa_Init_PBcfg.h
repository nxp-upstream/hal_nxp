/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DSPI
*   Dependencies         : 
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

#ifndef SPI_IP_SA_INIT_PBCFG_H
#define SPI_IP_SA_INIT_PBCFG_H

/**
*   @file    Spi_Ip_PBcfg.h
*   @version 2.0.1
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup SPI_IP_DRIVER_CONFIGURATION Spi Ip Driver Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IP_SA_INIT_VENDOR_ID_PBCFG                        43
#define SPI_IP_SA_INIT_AR_RELEASE_MAJOR_VERSION_PBCFG         4
#define SPI_IP_SA_INIT_AR_RELEASE_MINOR_VERSION_PBCFG         7
#define SPI_IP_SA_INIT_AR_RELEASE_REVISION_VERSION_PBCFG      0
#define SPI_IP_SA_INIT_SW_MAJOR_VERSION_PBCFG                 2
#define SPI_IP_SA_INIT_SW_MINOR_VERSION_PBCFG                 0
#define SPI_IP_SA_INIT_SW_PATCH_VERSION_PBCFG                 1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define SPI_IP_SA_CONFIG_INIT_PB \
    extern const Spi_Ip_ExternalDeviceType Spi_Ip_DeviceAttributes_SpiExternalDevice_0_Instance_0_Init; \
    extern const Spi_Ip_ExternalDeviceType Spi_Ip_DeviceAttributes_SpiExternalDevice_1_Instance_1_Init; \
    extern const Spi_Ip_ExternalDeviceType Spi_Ip_DeviceAttributes_SpiExternalDevice_2_Instance_4_Init; \
    extern const Spi_Ip_ConfigType Spi_Ip_PhyUnitConfig_SPI_0_Instance_0_Init; \
    extern const Spi_Ip_ConfigType Spi_Ip_PhyUnitConfig_SPI_1_Instance_1_Init; \
    extern const Spi_Ip_ConfigType Spi_Ip_PhyUnitConfig_SPI_4_Instance_4_Init;
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif

/** @} */


