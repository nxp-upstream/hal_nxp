/*
 * Copyright 2022-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETH_IP_SA_INIT_PBCFG_H
#define NETC_ETH_IP_SA_INIT_PBCFG_H

/**
*   @file Netc_Eth_Ip_Sa_INIT_PBcfg.h
*
*   @addtogroup NETC_ETH_DRIVER NETC_ETH Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETH_IP_SA_INIT_PBCFG_VENDOR_ID                     43
#define NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define NETC_ETH_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION              2
#define NETC_ETH_IP_SA_INIT_PBCFG_SW_MINOR_VERSION              0
#define NETC_ETH_IP_SA_INIT_PBCFG_SW_PATCH_VERSION              1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#ifndef NETC_ETH_0_USED
	#define NETC_ETH_0_USED
#endif /* NETC_ETH_0_USED */

/* ---------------------------------- BEGIN: TX generation ---------------------------------- */
/* Generate TX BDR defines for all rings used for each controller. */
/* NETC_ETH_#CONTROLLER_INDEX#_TXBDR_#RING_INDEX# */
#ifndef NETC_ETH_0_TXBDR_0
	#define NETC_ETH_0_TXBDR_0
#endif /* NETC_ETH_0_TXBDR_0 */

#ifndef NETC_ETH_0_TXBDATA_0
	#define NETC_ETH_0_TXBDATA_0
#endif /* NETC_ETH_0_TXBDATA_0 */

/* Generate the maximum number of descriptors between variants(VS) for each ring. */
#ifndef NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR */

/* Maximum number of TX rings between all controllers on the current variant. */
#ifndef NETC_ETH_IP_MAX_NUMBER_OF_TXRINGS
#define NETC_ETH_IP_MAX_NUMBER_OF_TXRINGS     (1U)
#elif (NETC_ETH_IP_MAX_NUMBER_OF_TXRINGS < (1U))
#undef NETC_ETH_IP_MAX_NUMBER_OF_TXRINGS
#define NETC_ETH_IP_MAX_NUMBER_OF_TXRINGS     (1U)
#endif /* NETC_ETH_IP_MAX_NUMBER_OF_TXRINGS */
/* Generate the maximum buffer length between variants(VS) for each ring. */
#ifndef NETC_ETH_0_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_0_TXBDR_0_MAX_BUFFLEN (64U)
#elif (NETC_ETH_0_TXBDR_0_MAX_BUFFLEN < (64U))
	#undef NETC_ETH_0_TXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_0_TXBDR_0_MAX_BUFFLEN (64U)
#endif /* NETC_ETH_0_TXBDR_0_MAX_BUFFLEN */

/* Maximum number of TX descriptors from all controllers on the current variant. */
#ifndef NETC_ETH_MAX_NUMBER_OF_TXBD
	#define NETC_ETH_MAX_NUMBER_OF_TXBD (8U)
#elif (NETC_ETH_MAX_NUMBER_OF_TXBD < (8U))
	#undef NETC_ETH_MAX_NUMBER_OF_TXBD
	#define NETC_ETH_MAX_NUMBER_OF_TXBD (8U)
#endif /* NETC_ETH_MAX_NUMBER_OF_TXBD */

/* ---------------------------------- END: TX generation ---------------------------------- */

/* ---------------------------------- BEGIN: RX generation ---------------------------------- */
/* Generate RX BDR defines for all rings used for each controller. */
/* NETC_ETH_#CONTROLLER_INDEX#_RXBDR_#RING_INDEX# */
#ifndef NETC_ETH_0_RXBDR_0
	#define NETC_ETH_0_RXBDR_0
#endif /* NETC_ETH_0_RXBDR_0 */

#ifndef NETC_ETH_0_RXBDATA_0
	#define NETC_ETH_0_RXBDATA_0
#endif /* NETC_ETH_0_RXBDATA_0 */

/* Generate the maximum number of descriptors between variants(VS) for each ring. */
#ifndef NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#elif (NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR < (8U))
	#undef NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR
	#define NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR (8U)
#endif /* NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR */

/* Generate the maximum buffer length between variants(VS) for each ring. */
#ifndef NETC_ETH_0_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_0_RXBDR_0_MAX_BUFFLEN (64U + FEATURE_NETC_ETH_CUSTOM_TAG_SIZE)
#elif (NETC_ETH_0_RXBDR_0_MAX_BUFFLEN < (64U + FEATURE_NETC_ETH_CUSTOM_TAG_SIZE))
	#undef NETC_ETH_0_RXBDR_0_MAX_BUFFLEN
	#define NETC_ETH_0_RXBDR_0_MAX_BUFFLEN (64U + FEATURE_NETC_ETH_CUSTOM_TAG_SIZE)
#endif /* NETC_ETH_0_RXBDR_0_MAX_BUFFLEN */

/* Maximum number of RX rings between all controllers on the current variant. */
#ifndef NETC_ETH_IP_MAX_NUMBER_OF_RXRINGS
#define NETC_ETH_IP_MAX_NUMBER_OF_RXRINGS     (1U)
#elif (NETC_ETH_IP_MAX_NUMBER_OF_RXRINGS < (1U))
#undef NETC_ETH_IP_MAX_NUMBER_OF_RXRINGS
#define NETC_ETH_IP_MAX_NUMBER_OF_RXRINGS     (1U)
#endif /* NETC_ETH_IP_MAX_NUMBER_OF_RXRINGS */
/* Maximum number of RX descriptors between all controllers on the current variant. */
#ifndef NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS
#define NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS     (8U)
#elif (NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS < (8U))
#undef NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS
#define NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS (8U)
#endif /* NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS */
/* Maximum number of RX descriptors from all controllers on the current variant. */
#ifndef NETC_ETH_MAX_NUMBER_OF_RXBD
	#define NETC_ETH_MAX_NUMBER_OF_RXBD (8U)
#elif (NETC_ETH_MAX_NUMBER_OF_RXBD < (8U))
	#undef NETC_ETH_MAX_NUMBER_OF_RXBD
	#define NETC_ETH_MAX_NUMBER_OF_RXBD (8U)
#endif /* NETC_ETH_MAX_NUMBER_OF_RXBD */

/* ---------------------------------- END: RX generation ---------------------------------- */


/* Create define to export varaint specific configuration. */
#define NETC_ETH_IP_CONFIG_SA_INIT_PB \
    extern const Netc_Eth_Ip_ConfigType Netc_Eth_0_ConfigPB_INIT; 

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

#endif /* NETC_ETH_IP_SA_INIT_PBCFG_H */

