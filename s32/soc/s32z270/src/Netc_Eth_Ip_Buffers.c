/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : NETC
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

/**
*   @file Netc_Eth_Ip_Buffers.c
*
*   @addtogroup Netc_Eth_Ip
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
#include "Netc_Eth_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_IP_BUFFERS_VENDOR_ID_C                     43
#define NETC_IP_BUFFERS_AR_RELEASE_MAJOR_VERSION_C      4
#define NETC_IP_BUFFERS_AR_RELEASE_MINOR_VERSION_C      7
#define NETC_IP_BUFFERS_AR_RELEASE_REVISION_VERSION_C   0
#define NETC_IP_BUFFERS_SW_MAJOR_VERSION_C              2
#define NETC_IP_BUFFERS_SW_MINOR_VERSION_C              0
#define NETC_IP_BUFFERS_SW_PATCH_VERSION_C              1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Netc_Eth_Ip_Types.h */
#if (NETC_IP_BUFFERS_VENDOR_ID_C != NETC_ETH_IP_TYPES_VENDOR_ID)
    #error "Netc_Eth_Ip_Buffers.h and Netc_Eth_Ip_Types.h have different vendor ids"
#endif
#if ((NETC_IP_BUFFERS_AR_RELEASE_MAJOR_VERSION_C    != NETC_ETH_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_IP_BUFFERS_AR_RELEASE_MINOR_VERSION_C    != NETC_ETH_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (NETC_IP_BUFFERS_AR_RELEASE_REVISION_VERSION_C != NETC_ETH_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Netc_Eth_Ip_Buffers.h and Netc_Eth_Ip_Types.h are different"
#endif
#if ((NETC_IP_BUFFERS_SW_MAJOR_VERSION_C != NETC_ETH_IP_TYPES_SW_MAJOR_VERSION) || \
     (NETC_IP_BUFFERS_SW_MINOR_VERSION_C != NETC_ETH_IP_TYPES_SW_MINOR_VERSION) || \
     (NETC_IP_BUFFERS_SW_PATCH_VERSION_C != NETC_ETH_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Netc_Eth_Ip_Buffers.h and Netc_Eth_Ip_Types.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define ETH_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_NETC_MemMap.h"
/* ---------------------------------- BEGIN: Timestamp information  ---------------------------------- */
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
volatile Netc_Eth_Ip_TxManagementInfoType Netc_Eth_Ip_TxManagementInfoBuff[NETC_ETH_IP_NUM_OF_PHYSICAL_CTRLS][NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR / NETC_ETH_IP_PRODUCER_INCR];
volatile Netc_Eth_Ip_TxTimestampInfoType Netc_Eth_Ip_TxTimestampInfoBuff[NETC_ETH_IP_NUM_OF_PHYSICAL_CTRLS][NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR / NETC_ETH_IP_PRODUCER_INCR];
#endif /* NETC_ETH_0_USED */
volatile Netc_Eth_Ip_RxTimestampInfoType Netc_Eth_Ip_RxTimestampInfoBuff[FEATURE_NETC_ETH_NUMBER_OF_CTRLS][NETC_ETH_IP_MAX_NUMBER_OF_RXRINGS][NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS];
#endif /* (STD_ON == NETC_ETH_IP_EXTENDED_BUFF) */
/* ---------------------------------- END: Timestamp information  ---------------------------------- */

#define ETH_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_NETC_MemMap.h"

#if (STD_OFF == NETC_ETH_IP_HAS_CACHE_MANAGEMENT)
#define ETH_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_NETC_MemMap.h"
#else
#define ETH_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"
#endif
/* ---------------------------------- BEGIN: TX generation ---------------------------------- */
#ifdef NETC_ETH_0_TXBDATA_0
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_0_DataBuffer[(NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_1
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_1_DataBuffer[(NETC_ETH_0_TXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_2
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_2_DataBuffer[(NETC_ETH_0_TXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_3
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_3_DataBuffer[(NETC_ETH_0_TXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_4
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_4_DataBuffer[(NETC_ETH_0_TXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_5
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_5_DataBuffer[(NETC_ETH_0_TXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_6
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_6_DataBuffer[(NETC_ETH_0_TXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_7
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_7_DataBuffer[(NETC_ETH_0_TXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_8
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_8_DataBuffer[(NETC_ETH_0_TXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_9
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_9_DataBuffer[(NETC_ETH_0_TXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_10
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_10_DataBuffer[(NETC_ETH_0_TXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_11
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_11_DataBuffer[(NETC_ETH_0_TXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_12
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_12_DataBuffer[(NETC_ETH_0_TXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_13
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_13_DataBuffer[(NETC_ETH_0_TXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_14
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_14_DataBuffer[(NETC_ETH_0_TXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_15
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_15_DataBuffer[(NETC_ETH_0_TXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_16
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_16_DataBuffer[(NETC_ETH_0_TXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDATA_17
	/*! @brief Transmission data buffers for Tx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_TxRing_17_DataBuffer[(NETC_ETH_0_TXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_0
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_0_DataBuffer[(NETC_ETH_1_TXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_1
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_1_DataBuffer[(NETC_ETH_1_TXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_2
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_2_DataBuffer[(NETC_ETH_1_TXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_3
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_3_DataBuffer[(NETC_ETH_1_TXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_4
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_4_DataBuffer[(NETC_ETH_1_TXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_5
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_5_DataBuffer[(NETC_ETH_1_TXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_6
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_6_DataBuffer[(NETC_ETH_1_TXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_7
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_7_DataBuffer[(NETC_ETH_1_TXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_8
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_8_DataBuffer[(NETC_ETH_1_TXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_9
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_9_DataBuffer[(NETC_ETH_1_TXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_10
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_10_DataBuffer[(NETC_ETH_1_TXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_11
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_11_DataBuffer[(NETC_ETH_1_TXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_12
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_12_DataBuffer[(NETC_ETH_1_TXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_13
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_13_DataBuffer[(NETC_ETH_1_TXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_14
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_14_DataBuffer[(NETC_ETH_1_TXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_15
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_15_DataBuffer[(NETC_ETH_1_TXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_16
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_16_DataBuffer[(NETC_ETH_1_TXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDATA_17
	/*! @brief Transmission data buffers for Tx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_TxRing_17_DataBuffer[(NETC_ETH_1_TXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_1_TXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_0
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_0_DataBuffer[(NETC_ETH_2_TXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_1
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_1_DataBuffer[(NETC_ETH_2_TXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_2
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_2_DataBuffer[(NETC_ETH_2_TXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_3
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_3_DataBuffer[(NETC_ETH_2_TXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_4
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_4_DataBuffer[(NETC_ETH_2_TXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_5
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_5_DataBuffer[(NETC_ETH_2_TXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_6
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_6_DataBuffer[(NETC_ETH_2_TXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_7
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_7_DataBuffer[(NETC_ETH_2_TXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_8
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_8_DataBuffer[(NETC_ETH_2_TXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_9
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_9_DataBuffer[(NETC_ETH_2_TXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_10
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_10_DataBuffer[(NETC_ETH_2_TXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_11
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_11_DataBuffer[(NETC_ETH_2_TXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_12
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_12_DataBuffer[(NETC_ETH_2_TXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_13
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_13_DataBuffer[(NETC_ETH_2_TXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_14
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_14_DataBuffer[(NETC_ETH_2_TXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_15
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_15_DataBuffer[(NETC_ETH_2_TXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_16
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_16_DataBuffer[(NETC_ETH_2_TXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDATA_17
	/*! @brief Transmission data buffers for Tx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_TxRing_17_DataBuffer[(NETC_ETH_2_TXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_2_TXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_0
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_0_DataBuffer[(NETC_ETH_3_TXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_1
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_1_DataBuffer[(NETC_ETH_3_TXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_2
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_2_DataBuffer[(NETC_ETH_3_TXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_3
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_3_DataBuffer[(NETC_ETH_3_TXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_4
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_4_DataBuffer[(NETC_ETH_3_TXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_5
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_5_DataBuffer[(NETC_ETH_3_TXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_6
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_6_DataBuffer[(NETC_ETH_3_TXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_7
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_7_DataBuffer[(NETC_ETH_3_TXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_8
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_8_DataBuffer[(NETC_ETH_3_TXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_9
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_9_DataBuffer[(NETC_ETH_3_TXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_10
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_10_DataBuffer[(NETC_ETH_3_TXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_11
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_11_DataBuffer[(NETC_ETH_3_TXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_12
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_12_DataBuffer[(NETC_ETH_3_TXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_13
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_13_DataBuffer[(NETC_ETH_3_TXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_14
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_14_DataBuffer[(NETC_ETH_3_TXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_15
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_15_DataBuffer[(NETC_ETH_3_TXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_16
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_16_DataBuffer[(NETC_ETH_3_TXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDATA_17
	/*! @brief Transmission data buffers for Tx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_TxRing_17_DataBuffer[(NETC_ETH_3_TXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_3_TXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_0
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_0_DataBuffer[(NETC_ETH_4_TXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_1
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_1_DataBuffer[(NETC_ETH_4_TXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_2
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_2_DataBuffer[(NETC_ETH_4_TXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_3
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_3_DataBuffer[(NETC_ETH_4_TXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_4
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_4_DataBuffer[(NETC_ETH_4_TXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_5
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_5_DataBuffer[(NETC_ETH_4_TXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_6
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_6_DataBuffer[(NETC_ETH_4_TXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_7
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_7_DataBuffer[(NETC_ETH_4_TXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_8
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_8_DataBuffer[(NETC_ETH_4_TXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_9
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_9_DataBuffer[(NETC_ETH_4_TXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_10
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_10_DataBuffer[(NETC_ETH_4_TXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_11
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_11_DataBuffer[(NETC_ETH_4_TXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_12
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_12_DataBuffer[(NETC_ETH_4_TXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_13
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_13_DataBuffer[(NETC_ETH_4_TXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_14
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_14_DataBuffer[(NETC_ETH_4_TXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_15
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_15_DataBuffer[(NETC_ETH_4_TXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_16
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_16_DataBuffer[(NETC_ETH_4_TXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDATA_17
	/*! @brief Transmission data buffers for Tx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_TxRing_17_DataBuffer[(NETC_ETH_4_TXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_4_TXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_0
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_0_DataBuffer[(NETC_ETH_5_TXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_1
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_1_DataBuffer[(NETC_ETH_5_TXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_2
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_2_DataBuffer[(NETC_ETH_5_TXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_3
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_3_DataBuffer[(NETC_ETH_5_TXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_4
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_4_DataBuffer[(NETC_ETH_5_TXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_5
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_5_DataBuffer[(NETC_ETH_5_TXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_6
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_6_DataBuffer[(NETC_ETH_5_TXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_7
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_7_DataBuffer[(NETC_ETH_5_TXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_8
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_8_DataBuffer[(NETC_ETH_5_TXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_9
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_9_DataBuffer[(NETC_ETH_5_TXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_10
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_10_DataBuffer[(NETC_ETH_5_TXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_11
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_11_DataBuffer[(NETC_ETH_5_TXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_12
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_12_DataBuffer[(NETC_ETH_5_TXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_13
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_13_DataBuffer[(NETC_ETH_5_TXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_14
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_14_DataBuffer[(NETC_ETH_5_TXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_15
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_15_DataBuffer[(NETC_ETH_5_TXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_16
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_16_DataBuffer[(NETC_ETH_5_TXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDATA_17
	/*! @brief Transmission data buffers for Tx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_TxRing_17_DataBuffer[(NETC_ETH_5_TXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_5_TXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_0
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_0_DataBuffer[(NETC_ETH_6_TXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_1
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_1_DataBuffer[(NETC_ETH_6_TXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_2
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_2_DataBuffer[(NETC_ETH_6_TXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_3
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_3_DataBuffer[(NETC_ETH_6_TXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_4
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_4_DataBuffer[(NETC_ETH_6_TXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_5
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_5_DataBuffer[(NETC_ETH_6_TXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_6
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_6_DataBuffer[(NETC_ETH_6_TXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_7
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_7_DataBuffer[(NETC_ETH_6_TXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_8
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_8_DataBuffer[(NETC_ETH_6_TXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_9
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_9_DataBuffer[(NETC_ETH_6_TXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_10
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_10_DataBuffer[(NETC_ETH_6_TXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_11
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_11_DataBuffer[(NETC_ETH_6_TXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_12
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_12_DataBuffer[(NETC_ETH_6_TXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_13
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_13_DataBuffer[(NETC_ETH_6_TXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_14
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_14_DataBuffer[(NETC_ETH_6_TXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_15
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_15_DataBuffer[(NETC_ETH_6_TXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_16
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_16_DataBuffer[(NETC_ETH_6_TXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDATA_17
	/*! @brief Transmission data buffers for Tx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_TxRing_17_DataBuffer[(NETC_ETH_6_TXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_6_TXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_0
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_0_DataBuffer[(NETC_ETH_7_TXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_1
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_1_DataBuffer[(NETC_ETH_7_TXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_2
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_2_DataBuffer[(NETC_ETH_7_TXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_3
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_3_DataBuffer[(NETC_ETH_7_TXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_4
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_4_DataBuffer[(NETC_ETH_7_TXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_5
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_5_DataBuffer[(NETC_ETH_7_TXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_6
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_6_DataBuffer[(NETC_ETH_7_TXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_7
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_7_DataBuffer[(NETC_ETH_7_TXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_8
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_8_DataBuffer[(NETC_ETH_7_TXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_9
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_9_DataBuffer[(NETC_ETH_7_TXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_10
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_10_DataBuffer[(NETC_ETH_7_TXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_11
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_11_DataBuffer[(NETC_ETH_7_TXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_12
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_12_DataBuffer[(NETC_ETH_7_TXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_13
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_13_DataBuffer[(NETC_ETH_7_TXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_14
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_14_DataBuffer[(NETC_ETH_7_TXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_15
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_15_DataBuffer[(NETC_ETH_7_TXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_16
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_16_DataBuffer[(NETC_ETH_7_TXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDATA_17
	/*! @brief Transmission data buffers for Tx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_TxRing_17_DataBuffer[(NETC_ETH_7_TXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_7_TXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
/* ---------------------------------- END: TX generation ---------------------------------- */


/* ---------------------------------- BEGIN: RX generation ---------------------------------- */
#ifdef NETC_ETH_0_RXBDATA_0
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_0_DataBuffer[(NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_1
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_1_DataBuffer[(NETC_ETH_0_RXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_2
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_2_DataBuffer[(NETC_ETH_0_RXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_3
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_3_DataBuffer[(NETC_ETH_0_RXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_4
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_4_DataBuffer[(NETC_ETH_0_RXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_5
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_5_DataBuffer[(NETC_ETH_0_RXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_6
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_6_DataBuffer[(NETC_ETH_0_RXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_7
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_7_DataBuffer[(NETC_ETH_0_RXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_8
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_8_DataBuffer[(NETC_ETH_0_RXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_9
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_9_DataBuffer[(NETC_ETH_0_RXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_10
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_10_DataBuffer[(NETC_ETH_0_RXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_11
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_11_DataBuffer[(NETC_ETH_0_RXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_12
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_12_DataBuffer[(NETC_ETH_0_RXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_13
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_13_DataBuffer[(NETC_ETH_0_RXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_14
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_14_DataBuffer[(NETC_ETH_0_RXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_15
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_15_DataBuffer[(NETC_ETH_0_RXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_16
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_16_DataBuffer[(NETC_ETH_0_RXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDATA_17
	/*! @brief Transmission data buffers for Rx Ring 0 */
	VAR_ALIGN(uint8 Netc_Eth_0_RxRing_17_DataBuffer[(NETC_ETH_0_RXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_0
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_0_DataBuffer[(NETC_ETH_1_RXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_1
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_1_DataBuffer[(NETC_ETH_1_RXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_2
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_2_DataBuffer[(NETC_ETH_1_RXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_3
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_3_DataBuffer[(NETC_ETH_1_RXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_4
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_4_DataBuffer[(NETC_ETH_1_RXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_5
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_5_DataBuffer[(NETC_ETH_1_RXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_6
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_6_DataBuffer[(NETC_ETH_1_RXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_7
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_7_DataBuffer[(NETC_ETH_1_RXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_8
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_8_DataBuffer[(NETC_ETH_1_RXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_9
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_9_DataBuffer[(NETC_ETH_1_RXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_10
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_10_DataBuffer[(NETC_ETH_1_RXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_11
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_11_DataBuffer[(NETC_ETH_1_RXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_12
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_12_DataBuffer[(NETC_ETH_1_RXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_13
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_13_DataBuffer[(NETC_ETH_1_RXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_14
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_14_DataBuffer[(NETC_ETH_1_RXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_15
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_15_DataBuffer[(NETC_ETH_1_RXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_16
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_16_DataBuffer[(NETC_ETH_1_RXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDATA_17
	/*! @brief Transmission data buffers for Rx Ring 1 */
	VAR_ALIGN(uint8 Netc_Eth_1_RxRing_17_DataBuffer[(NETC_ETH_1_RXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_1_RXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_0
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_0_DataBuffer[(NETC_ETH_2_RXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_1
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_1_DataBuffer[(NETC_ETH_2_RXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_2
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_2_DataBuffer[(NETC_ETH_2_RXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_3
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_3_DataBuffer[(NETC_ETH_2_RXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_4
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_4_DataBuffer[(NETC_ETH_2_RXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_5
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_5_DataBuffer[(NETC_ETH_2_RXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_6
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_6_DataBuffer[(NETC_ETH_2_RXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_7
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_7_DataBuffer[(NETC_ETH_2_RXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_8
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_8_DataBuffer[(NETC_ETH_2_RXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_9
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_9_DataBuffer[(NETC_ETH_2_RXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_10
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_10_DataBuffer[(NETC_ETH_2_RXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_11
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_11_DataBuffer[(NETC_ETH_2_RXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_12
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_12_DataBuffer[(NETC_ETH_2_RXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_13
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_13_DataBuffer[(NETC_ETH_2_RXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_14
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_14_DataBuffer[(NETC_ETH_2_RXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_15
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_15_DataBuffer[(NETC_ETH_2_RXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_16
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_16_DataBuffer[(NETC_ETH_2_RXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDATA_17
	/*! @brief Transmission data buffers for Rx Ring 2 */
	VAR_ALIGN(uint8 Netc_Eth_2_RxRing_17_DataBuffer[(NETC_ETH_2_RXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_2_RXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_0
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_0_DataBuffer[(NETC_ETH_3_RXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_1
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_1_DataBuffer[(NETC_ETH_3_RXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_2
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_2_DataBuffer[(NETC_ETH_3_RXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_3
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_3_DataBuffer[(NETC_ETH_3_RXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_4
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_4_DataBuffer[(NETC_ETH_3_RXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_5
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_5_DataBuffer[(NETC_ETH_3_RXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_6
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_6_DataBuffer[(NETC_ETH_3_RXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_7
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_7_DataBuffer[(NETC_ETH_3_RXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_8
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_8_DataBuffer[(NETC_ETH_3_RXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_9
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_9_DataBuffer[(NETC_ETH_3_RXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_10
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_10_DataBuffer[(NETC_ETH_3_RXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_11
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_11_DataBuffer[(NETC_ETH_3_RXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_12
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_12_DataBuffer[(NETC_ETH_3_RXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_13
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_13_DataBuffer[(NETC_ETH_3_RXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_14
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_14_DataBuffer[(NETC_ETH_3_RXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_15
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_15_DataBuffer[(NETC_ETH_3_RXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_16
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_16_DataBuffer[(NETC_ETH_3_RXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDATA_17
	/*! @brief Transmission data buffers for Rx Ring 3 */
	VAR_ALIGN(uint8 Netc_Eth_3_RxRing_17_DataBuffer[(NETC_ETH_3_RXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_3_RXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_0
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_0_DataBuffer[(NETC_ETH_4_RXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_1
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_1_DataBuffer[(NETC_ETH_4_RXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_2
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_2_DataBuffer[(NETC_ETH_4_RXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_3
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_3_DataBuffer[(NETC_ETH_4_RXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_4
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_4_DataBuffer[(NETC_ETH_4_RXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_5
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_5_DataBuffer[(NETC_ETH_4_RXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_6
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_6_DataBuffer[(NETC_ETH_4_RXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_7
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_7_DataBuffer[(NETC_ETH_4_RXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_8
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_8_DataBuffer[(NETC_ETH_4_RXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_9
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_9_DataBuffer[(NETC_ETH_4_RXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_10
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_10_DataBuffer[(NETC_ETH_4_RXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_11
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_11_DataBuffer[(NETC_ETH_4_RXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_12
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_12_DataBuffer[(NETC_ETH_4_RXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_13
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_13_DataBuffer[(NETC_ETH_4_RXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_14
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_14_DataBuffer[(NETC_ETH_4_RXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_15
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_15_DataBuffer[(NETC_ETH_4_RXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_16
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_16_DataBuffer[(NETC_ETH_4_RXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDATA_17
	/*! @brief Transmission data buffers for Rx Ring 4 */
	VAR_ALIGN(uint8 Netc_Eth_4_RxRing_17_DataBuffer[(NETC_ETH_4_RXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_4_RXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_0
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_0_DataBuffer[(NETC_ETH_5_RXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_1
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_1_DataBuffer[(NETC_ETH_5_RXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_2
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_2_DataBuffer[(NETC_ETH_5_RXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_3
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_3_DataBuffer[(NETC_ETH_5_RXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_4
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_4_DataBuffer[(NETC_ETH_5_RXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_5
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_5_DataBuffer[(NETC_ETH_5_RXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_6
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_6_DataBuffer[(NETC_ETH_5_RXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_7
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_7_DataBuffer[(NETC_ETH_5_RXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_8
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_8_DataBuffer[(NETC_ETH_5_RXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_9
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_9_DataBuffer[(NETC_ETH_5_RXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_10
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_10_DataBuffer[(NETC_ETH_5_RXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_11
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_11_DataBuffer[(NETC_ETH_5_RXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_12
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_12_DataBuffer[(NETC_ETH_5_RXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_13
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_13_DataBuffer[(NETC_ETH_5_RXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_14
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_14_DataBuffer[(NETC_ETH_5_RXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_15
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_15_DataBuffer[(NETC_ETH_5_RXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_16
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_16_DataBuffer[(NETC_ETH_5_RXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDATA_17
	/*! @brief Transmission data buffers for Rx Ring 5 */
	VAR_ALIGN(uint8 Netc_Eth_5_RxRing_17_DataBuffer[(NETC_ETH_5_RXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_5_RXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_0
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_0_DataBuffer[(NETC_ETH_6_RXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_1
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_1_DataBuffer[(NETC_ETH_6_RXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_2
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_2_DataBuffer[(NETC_ETH_6_RXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_3
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_3_DataBuffer[(NETC_ETH_6_RXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_4
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_4_DataBuffer[(NETC_ETH_6_RXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_5
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_5_DataBuffer[(NETC_ETH_6_RXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_6
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_6_DataBuffer[(NETC_ETH_6_RXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_7
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_7_DataBuffer[(NETC_ETH_6_RXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_8
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_8_DataBuffer[(NETC_ETH_6_RXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_9
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_9_DataBuffer[(NETC_ETH_6_RXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_10
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_10_DataBuffer[(NETC_ETH_6_RXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_11
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_11_DataBuffer[(NETC_ETH_6_RXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_12
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_12_DataBuffer[(NETC_ETH_6_RXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_13
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_13_DataBuffer[(NETC_ETH_6_RXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_14
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_14_DataBuffer[(NETC_ETH_6_RXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_15
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_15_DataBuffer[(NETC_ETH_6_RXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_16
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_16_DataBuffer[(NETC_ETH_6_RXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDATA_17
	/*! @brief Transmission data buffers for Rx Ring 6 */
	VAR_ALIGN(uint8 Netc_Eth_6_RxRing_17_DataBuffer[(NETC_ETH_6_RXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_6_RXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_0
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_0_DataBuffer[(NETC_ETH_7_RXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_1
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_1_DataBuffer[(NETC_ETH_7_RXBDR_1_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_1_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_2
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_2_DataBuffer[(NETC_ETH_7_RXBDR_2_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_2_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_3
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_3_DataBuffer[(NETC_ETH_7_RXBDR_3_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_3_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_4
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_4_DataBuffer[(NETC_ETH_7_RXBDR_4_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_4_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_5
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_5_DataBuffer[(NETC_ETH_7_RXBDR_5_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_5_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_6
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_6_DataBuffer[(NETC_ETH_7_RXBDR_6_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_6_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_7
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_7_DataBuffer[(NETC_ETH_7_RXBDR_7_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_7_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_8
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_8_DataBuffer[(NETC_ETH_7_RXBDR_8_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_8_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_9
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_9_DataBuffer[(NETC_ETH_7_RXBDR_9_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_9_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_10
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_10_DataBuffer[(NETC_ETH_7_RXBDR_10_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_10_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_11
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_11_DataBuffer[(NETC_ETH_7_RXBDR_11_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_11_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_12
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_12_DataBuffer[(NETC_ETH_7_RXBDR_12_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_12_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_13
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_13_DataBuffer[(NETC_ETH_7_RXBDR_13_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_13_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_14
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_14_DataBuffer[(NETC_ETH_7_RXBDR_14_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_14_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_15
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_15_DataBuffer[(NETC_ETH_7_RXBDR_15_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_15_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_16
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_16_DataBuffer[(NETC_ETH_7_RXBDR_16_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_16_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDATA_17
	/*! @brief Transmission data buffers for Rx Ring 7 */
	VAR_ALIGN(uint8 Netc_Eth_7_RxRing_17_DataBuffer[(NETC_ETH_7_RXBDR_17_MAX_NUM_OF_DESCR * NETC_ETH_7_RXBDR_17_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
#endif
/* ---------------------------------- END: RX generation ---------------------------------- */


#if (STD_OFF == NETC_ETH_IP_HAS_CACHE_MANAGEMENT)
#define ETH_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_NETC_MemMap.h"
#else
#define ETH_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"
#endif

#define ETH_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_NETC_MemMap.h"
/* ---------------------------------- BEGIN: TX generation ---------------------------------- */
#ifdef NETC_ETH_0_TXBDR_0
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_0_DescBuffer[NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_1
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_1_DescBuffer[NETC_ETH_0_TXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_2
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_2_DescBuffer[NETC_ETH_0_TXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_3
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_3_DescBuffer[NETC_ETH_0_TXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_4
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_4_DescBuffer[NETC_ETH_0_TXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_5
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_5_DescBuffer[NETC_ETH_0_TXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_6
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_6_DescBuffer[NETC_ETH_0_TXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_7
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_7_DescBuffer[NETC_ETH_0_TXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_8
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_8_DescBuffer[NETC_ETH_0_TXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_9
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_9_DescBuffer[NETC_ETH_0_TXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_10
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_10_DescBuffer[NETC_ETH_0_TXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_11
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_11_DescBuffer[NETC_ETH_0_TXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_12
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_12_DescBuffer[NETC_ETH_0_TXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_13
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_13_DescBuffer[NETC_ETH_0_TXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_14
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_14_DescBuffer[NETC_ETH_0_TXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_15
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_15_DescBuffer[NETC_ETH_0_TXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_16
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_16_DescBuffer[NETC_ETH_0_TXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_TXBDR_17
	/*! @brief Transmission buffer descriptors for Tx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_17_DescBuffer[NETC_ETH_0_TXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_0
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_0_DescBuffer[NETC_ETH_1_TXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_1
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_1_DescBuffer[NETC_ETH_1_TXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_2
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_2_DescBuffer[NETC_ETH_1_TXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_3
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_3_DescBuffer[NETC_ETH_1_TXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_4
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_4_DescBuffer[NETC_ETH_1_TXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_5
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_5_DescBuffer[NETC_ETH_1_TXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_6
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_6_DescBuffer[NETC_ETH_1_TXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_7
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_7_DescBuffer[NETC_ETH_1_TXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_8
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_8_DescBuffer[NETC_ETH_1_TXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_9
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_9_DescBuffer[NETC_ETH_1_TXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_10
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_10_DescBuffer[NETC_ETH_1_TXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_11
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_11_DescBuffer[NETC_ETH_1_TXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_12
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_12_DescBuffer[NETC_ETH_1_TXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_13
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_13_DescBuffer[NETC_ETH_1_TXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_14
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_14_DescBuffer[NETC_ETH_1_TXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_15
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_15_DescBuffer[NETC_ETH_1_TXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_16
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_16_DescBuffer[NETC_ETH_1_TXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_TXBDR_17
	/*! @brief Transmission buffer descriptors for Tx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_1_TxRing_17_DescBuffer[NETC_ETH_1_TXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_0
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_0_DescBuffer[NETC_ETH_2_TXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_1
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_1_DescBuffer[NETC_ETH_2_TXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_2
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_2_DescBuffer[NETC_ETH_2_TXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_3
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_3_DescBuffer[NETC_ETH_2_TXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_4
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_4_DescBuffer[NETC_ETH_2_TXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_5
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_5_DescBuffer[NETC_ETH_2_TXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_6
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_6_DescBuffer[NETC_ETH_2_TXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_7
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_7_DescBuffer[NETC_ETH_2_TXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_8
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_8_DescBuffer[NETC_ETH_2_TXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_9
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_9_DescBuffer[NETC_ETH_2_TXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_10
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_10_DescBuffer[NETC_ETH_2_TXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_11
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_11_DescBuffer[NETC_ETH_2_TXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_12
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_12_DescBuffer[NETC_ETH_2_TXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_13
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_13_DescBuffer[NETC_ETH_2_TXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_14
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_14_DescBuffer[NETC_ETH_2_TXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_15
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_15_DescBuffer[NETC_ETH_2_TXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_16
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_16_DescBuffer[NETC_ETH_2_TXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_TXBDR_17
	/*! @brief Transmission buffer descriptors for Tx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_2_TxRing_17_DescBuffer[NETC_ETH_2_TXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_0
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_0_DescBuffer[NETC_ETH_3_TXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_1
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_1_DescBuffer[NETC_ETH_3_TXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_2
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_2_DescBuffer[NETC_ETH_3_TXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_3
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_3_DescBuffer[NETC_ETH_3_TXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_4
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_4_DescBuffer[NETC_ETH_3_TXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_5
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_5_DescBuffer[NETC_ETH_3_TXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_6
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_6_DescBuffer[NETC_ETH_3_TXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_7
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_7_DescBuffer[NETC_ETH_3_TXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_8
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_8_DescBuffer[NETC_ETH_3_TXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_9
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_9_DescBuffer[NETC_ETH_3_TXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_10
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_10_DescBuffer[NETC_ETH_3_TXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_11
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_11_DescBuffer[NETC_ETH_3_TXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_12
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_12_DescBuffer[NETC_ETH_3_TXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_13
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_13_DescBuffer[NETC_ETH_3_TXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_14
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_14_DescBuffer[NETC_ETH_3_TXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_15
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_15_DescBuffer[NETC_ETH_3_TXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_16
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_16_DescBuffer[NETC_ETH_3_TXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_TXBDR_17
	/*! @brief Transmission buffer descriptors for Tx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_3_TxRing_17_DescBuffer[NETC_ETH_3_TXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_0
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_0_DescBuffer[NETC_ETH_4_TXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_1
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_1_DescBuffer[NETC_ETH_4_TXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_2
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_2_DescBuffer[NETC_ETH_4_TXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_3
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_3_DescBuffer[NETC_ETH_4_TXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_4
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_4_DescBuffer[NETC_ETH_4_TXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_5
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_5_DescBuffer[NETC_ETH_4_TXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_6
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_6_DescBuffer[NETC_ETH_4_TXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_7
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_7_DescBuffer[NETC_ETH_4_TXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_8
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_8_DescBuffer[NETC_ETH_4_TXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_9
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_9_DescBuffer[NETC_ETH_4_TXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_10
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_10_DescBuffer[NETC_ETH_4_TXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_11
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_11_DescBuffer[NETC_ETH_4_TXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_12
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_12_DescBuffer[NETC_ETH_4_TXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_13
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_13_DescBuffer[NETC_ETH_4_TXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_14
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_14_DescBuffer[NETC_ETH_4_TXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_15
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_15_DescBuffer[NETC_ETH_4_TXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_16
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_16_DescBuffer[NETC_ETH_4_TXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_TXBDR_17
	/*! @brief Transmission buffer descriptors for Tx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_4_TxRing_17_DescBuffer[NETC_ETH_4_TXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_0
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_0_DescBuffer[NETC_ETH_5_TXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_1
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_1_DescBuffer[NETC_ETH_5_TXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_2
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_2_DescBuffer[NETC_ETH_5_TXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_3
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_3_DescBuffer[NETC_ETH_5_TXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_4
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_4_DescBuffer[NETC_ETH_5_TXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_5
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_5_DescBuffer[NETC_ETH_5_TXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_6
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_6_DescBuffer[NETC_ETH_5_TXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_7
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_7_DescBuffer[NETC_ETH_5_TXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_8
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_8_DescBuffer[NETC_ETH_5_TXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_9
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_9_DescBuffer[NETC_ETH_5_TXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_10
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_10_DescBuffer[NETC_ETH_5_TXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_11
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_11_DescBuffer[NETC_ETH_5_TXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_12
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_12_DescBuffer[NETC_ETH_5_TXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_13
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_13_DescBuffer[NETC_ETH_5_TXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_14
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_14_DescBuffer[NETC_ETH_5_TXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_15
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_15_DescBuffer[NETC_ETH_5_TXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_16
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_16_DescBuffer[NETC_ETH_5_TXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_TXBDR_17
	/*! @brief Transmission buffer descriptors for Tx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_5_TxRing_17_DescBuffer[NETC_ETH_5_TXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_0
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_0_DescBuffer[NETC_ETH_6_TXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_1
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_1_DescBuffer[NETC_ETH_6_TXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_2
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_2_DescBuffer[NETC_ETH_6_TXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_3
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_3_DescBuffer[NETC_ETH_6_TXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_4
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_4_DescBuffer[NETC_ETH_6_TXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_5
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_5_DescBuffer[NETC_ETH_6_TXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_6
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_6_DescBuffer[NETC_ETH_6_TXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_7
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_7_DescBuffer[NETC_ETH_6_TXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_8
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_8_DescBuffer[NETC_ETH_6_TXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_9
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_9_DescBuffer[NETC_ETH_6_TXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_10
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_10_DescBuffer[NETC_ETH_6_TXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_11
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_11_DescBuffer[NETC_ETH_6_TXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_12
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_12_DescBuffer[NETC_ETH_6_TXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_13
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_13_DescBuffer[NETC_ETH_6_TXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_14
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_14_DescBuffer[NETC_ETH_6_TXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_15
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_15_DescBuffer[NETC_ETH_6_TXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_16
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_16_DescBuffer[NETC_ETH_6_TXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_TXBDR_17
	/*! @brief Transmission buffer descriptors for Tx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_6_TxRing_17_DescBuffer[NETC_ETH_6_TXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_0
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_0_DescBuffer[NETC_ETH_7_TXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_1
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_1_DescBuffer[NETC_ETH_7_TXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_2
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_2_DescBuffer[NETC_ETH_7_TXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_3
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_3_DescBuffer[NETC_ETH_7_TXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_4
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_4_DescBuffer[NETC_ETH_7_TXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_5
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_5_DescBuffer[NETC_ETH_7_TXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_6
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_6_DescBuffer[NETC_ETH_7_TXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_7
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_7_DescBuffer[NETC_ETH_7_TXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_8
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_8_DescBuffer[NETC_ETH_7_TXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_9
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_9_DescBuffer[NETC_ETH_7_TXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_10
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_10_DescBuffer[NETC_ETH_7_TXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_11
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_11_DescBuffer[NETC_ETH_7_TXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_12
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_12_DescBuffer[NETC_ETH_7_TXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_13
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_13_DescBuffer[NETC_ETH_7_TXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_14
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_14_DescBuffer[NETC_ETH_7_TXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_15
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_15_DescBuffer[NETC_ETH_7_TXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_16
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_16_DescBuffer[NETC_ETH_7_TXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_TXBDR_17
	/*! @brief Transmission buffer descriptors for Tx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_7_TxRing_17_DescBuffer[NETC_ETH_7_TXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
/* ---------------------------------- END: TX generation ---------------------------------- */


/* ---------------------------------- BEGIN: RX generation ---------------------------------- */
#ifdef NETC_ETH_0_RXBDR_0
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_0_DescBuffer[NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_1
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_1_DescBuffer[NETC_ETH_0_RXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_2
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_2_DescBuffer[NETC_ETH_0_RXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_3
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_3_DescBuffer[NETC_ETH_0_RXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_4
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_4_DescBuffer[NETC_ETH_0_RXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_5
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_5_DescBuffer[NETC_ETH_0_RXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_6
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_6_DescBuffer[NETC_ETH_0_RXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_7
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_7_DescBuffer[NETC_ETH_0_RXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_8
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_8_DescBuffer[NETC_ETH_0_RXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_9
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_9_DescBuffer[NETC_ETH_0_RXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_10
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_10_DescBuffer[NETC_ETH_0_RXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_11
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_11_DescBuffer[NETC_ETH_0_RXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_12
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_12_DescBuffer[NETC_ETH_0_RXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_13
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_13_DescBuffer[NETC_ETH_0_RXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_14
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_14_DescBuffer[NETC_ETH_0_RXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_15
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_15_DescBuffer[NETC_ETH_0_RXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_16
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_16_DescBuffer[NETC_ETH_0_RXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_0_RXBDR_17
	/*! @brief Transmission buffer descriptors for Rx Ring 0 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_17_DescBuffer[NETC_ETH_0_RXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_0
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_0_DescBuffer[NETC_ETH_1_RXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_1
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_1_DescBuffer[NETC_ETH_1_RXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_2
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_2_DescBuffer[NETC_ETH_1_RXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_3
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_3_DescBuffer[NETC_ETH_1_RXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_4
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_4_DescBuffer[NETC_ETH_1_RXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_5
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_5_DescBuffer[NETC_ETH_1_RXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_6
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_6_DescBuffer[NETC_ETH_1_RXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_7
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_7_DescBuffer[NETC_ETH_1_RXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_8
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_8_DescBuffer[NETC_ETH_1_RXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_9
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_9_DescBuffer[NETC_ETH_1_RXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_10
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_10_DescBuffer[NETC_ETH_1_RXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_11
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_11_DescBuffer[NETC_ETH_1_RXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_12
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_12_DescBuffer[NETC_ETH_1_RXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_13
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_13_DescBuffer[NETC_ETH_1_RXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_14
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_14_DescBuffer[NETC_ETH_1_RXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_15
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_15_DescBuffer[NETC_ETH_1_RXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_16
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_16_DescBuffer[NETC_ETH_1_RXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_1_RXBDR_17
	/*! @brief Transmission buffer descriptors for Rx Ring 1 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_1_RxRing_17_DescBuffer[NETC_ETH_1_RXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_0
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_0_DescBuffer[NETC_ETH_2_RXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_1
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_1_DescBuffer[NETC_ETH_2_RXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_2
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_2_DescBuffer[NETC_ETH_2_RXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_3
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_3_DescBuffer[NETC_ETH_2_RXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_4
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_4_DescBuffer[NETC_ETH_2_RXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_5
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_5_DescBuffer[NETC_ETH_2_RXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_6
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_6_DescBuffer[NETC_ETH_2_RXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_7
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_7_DescBuffer[NETC_ETH_2_RXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_8
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_8_DescBuffer[NETC_ETH_2_RXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_9
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_9_DescBuffer[NETC_ETH_2_RXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_10
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_10_DescBuffer[NETC_ETH_2_RXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_11
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_11_DescBuffer[NETC_ETH_2_RXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_12
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_12_DescBuffer[NETC_ETH_2_RXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_13
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_13_DescBuffer[NETC_ETH_2_RXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_14
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_14_DescBuffer[NETC_ETH_2_RXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_15
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_15_DescBuffer[NETC_ETH_2_RXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_16
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_16_DescBuffer[NETC_ETH_2_RXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_2_RXBDR_17
	/*! @brief Transmission buffer descriptors for Rx Ring 2 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_2_RxRing_17_DescBuffer[NETC_ETH_2_RXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_0
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_0_DescBuffer[NETC_ETH_3_RXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_1
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_1_DescBuffer[NETC_ETH_3_RXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_2
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_2_DescBuffer[NETC_ETH_3_RXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_3
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_3_DescBuffer[NETC_ETH_3_RXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_4
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_4_DescBuffer[NETC_ETH_3_RXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_5
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_5_DescBuffer[NETC_ETH_3_RXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_6
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_6_DescBuffer[NETC_ETH_3_RXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_7
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_7_DescBuffer[NETC_ETH_3_RXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_8
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_8_DescBuffer[NETC_ETH_3_RXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_9
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_9_DescBuffer[NETC_ETH_3_RXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_10
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_10_DescBuffer[NETC_ETH_3_RXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_11
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_11_DescBuffer[NETC_ETH_3_RXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_12
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_12_DescBuffer[NETC_ETH_3_RXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_13
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_13_DescBuffer[NETC_ETH_3_RXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_14
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_14_DescBuffer[NETC_ETH_3_RXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_15
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_15_DescBuffer[NETC_ETH_3_RXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_16
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_16_DescBuffer[NETC_ETH_3_RXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_3_RXBDR_17
	/*! @brief Transmission buffer descriptors for Rx Ring 3 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_3_RxRing_17_DescBuffer[NETC_ETH_3_RXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_0
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_0_DescBuffer[NETC_ETH_4_RXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_1
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_1_DescBuffer[NETC_ETH_4_RXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_2
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_2_DescBuffer[NETC_ETH_4_RXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_3
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_3_DescBuffer[NETC_ETH_4_RXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_4
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_4_DescBuffer[NETC_ETH_4_RXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_5
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_5_DescBuffer[NETC_ETH_4_RXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_6
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_6_DescBuffer[NETC_ETH_4_RXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_7
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_7_DescBuffer[NETC_ETH_4_RXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_8
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_8_DescBuffer[NETC_ETH_4_RXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_9
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_9_DescBuffer[NETC_ETH_4_RXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_10
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_10_DescBuffer[NETC_ETH_4_RXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_11
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_11_DescBuffer[NETC_ETH_4_RXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_12
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_12_DescBuffer[NETC_ETH_4_RXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_13
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_13_DescBuffer[NETC_ETH_4_RXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_14
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_14_DescBuffer[NETC_ETH_4_RXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_15
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_15_DescBuffer[NETC_ETH_4_RXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_16
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_16_DescBuffer[NETC_ETH_4_RXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_4_RXBDR_17
	/*! @brief Transmission buffer descriptors for Rx Ring 4 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_4_RxRing_17_DescBuffer[NETC_ETH_4_RXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_0
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_0_DescBuffer[NETC_ETH_5_RXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_1
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_1_DescBuffer[NETC_ETH_5_RXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_2
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_2_DescBuffer[NETC_ETH_5_RXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_3
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_3_DescBuffer[NETC_ETH_5_RXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_4
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_4_DescBuffer[NETC_ETH_5_RXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_5
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_5_DescBuffer[NETC_ETH_5_RXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_6
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_6_DescBuffer[NETC_ETH_5_RXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_7
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_7_DescBuffer[NETC_ETH_5_RXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_8
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_8_DescBuffer[NETC_ETH_5_RXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_9
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_9_DescBuffer[NETC_ETH_5_RXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_10
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_10_DescBuffer[NETC_ETH_5_RXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_11
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_11_DescBuffer[NETC_ETH_5_RXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_12
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_12_DescBuffer[NETC_ETH_5_RXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_13
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_13_DescBuffer[NETC_ETH_5_RXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_14
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_14_DescBuffer[NETC_ETH_5_RXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_15
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_15_DescBuffer[NETC_ETH_5_RXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_16
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_16_DescBuffer[NETC_ETH_5_RXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_5_RXBDR_17
	/*! @brief Transmission buffer descriptors for Rx Ring 5 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_5_RxRing_17_DescBuffer[NETC_ETH_5_RXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_0
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_0_DescBuffer[NETC_ETH_6_RXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_1
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_1_DescBuffer[NETC_ETH_6_RXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_2
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_2_DescBuffer[NETC_ETH_6_RXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_3
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_3_DescBuffer[NETC_ETH_6_RXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_4
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_4_DescBuffer[NETC_ETH_6_RXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_5
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_5_DescBuffer[NETC_ETH_6_RXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_6
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_6_DescBuffer[NETC_ETH_6_RXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_7
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_7_DescBuffer[NETC_ETH_6_RXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_8
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_8_DescBuffer[NETC_ETH_6_RXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_9
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_9_DescBuffer[NETC_ETH_6_RXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_10
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_10_DescBuffer[NETC_ETH_6_RXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_11
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_11_DescBuffer[NETC_ETH_6_RXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_12
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_12_DescBuffer[NETC_ETH_6_RXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_13
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_13_DescBuffer[NETC_ETH_6_RXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_14
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_14_DescBuffer[NETC_ETH_6_RXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_15
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_15_DescBuffer[NETC_ETH_6_RXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_16
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_16_DescBuffer[NETC_ETH_6_RXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_6_RXBDR_17
	/*! @brief Transmission buffer descriptors for Rx Ring 6 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_6_RxRing_17_DescBuffer[NETC_ETH_6_RXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_0
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_0_DescBuffer[NETC_ETH_7_RXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_1
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_1_DescBuffer[NETC_ETH_7_RXBDR_1_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_2
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_2_DescBuffer[NETC_ETH_7_RXBDR_2_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_3
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_3_DescBuffer[NETC_ETH_7_RXBDR_3_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_4
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_4_DescBuffer[NETC_ETH_7_RXBDR_4_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_5
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_5_DescBuffer[NETC_ETH_7_RXBDR_5_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_6
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_6_DescBuffer[NETC_ETH_7_RXBDR_6_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_7
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_7_DescBuffer[NETC_ETH_7_RXBDR_7_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_8
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_8_DescBuffer[NETC_ETH_7_RXBDR_8_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_9
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_9_DescBuffer[NETC_ETH_7_RXBDR_9_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_10
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_10_DescBuffer[NETC_ETH_7_RXBDR_10_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_11
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_11_DescBuffer[NETC_ETH_7_RXBDR_11_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_12
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_12_DescBuffer[NETC_ETH_7_RXBDR_12_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_13
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_13_DescBuffer[NETC_ETH_7_RXBDR_13_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_14
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_14_DescBuffer[NETC_ETH_7_RXBDR_14_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_15
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_15_DescBuffer[NETC_ETH_7_RXBDR_15_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_16
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_16_DescBuffer[NETC_ETH_7_RXBDR_16_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef NETC_ETH_7_RXBDR_17
	/*! @brief Transmission buffer descriptors for Rx Ring 7 */
	VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_7_RxRing_17_DescBuffer[NETC_ETH_7_RXBDR_17_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
#endif
/* ---------------------------------- END: RX generation ---------------------------------- */


/* ---------------------------------- BEGIN: General stuctures  ---------------------------------- */
#ifdef NETC_ETH_0_USED
	Netc_Eth_Ip_StateType Netc_Eth_0_StateStructure;
	volatile VAR_ALIGN(Netc_Eth_Ip_VsiToPsiMsgType Netc_Eth_Ip_Psi_RxVsi1MsgCmd, FEATURE_NETC_ETH_VSI_MSG_ALIGNMENT)
#endif /* NETC_ETH_0_USED */
/* ---------------------------------- END: State structures ---------------------------------- */


/* ---------------------------------- BEGIN: MAC Filter Tables  ---------------------------------- */

#if (NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES > 0)
/* Table of hash value and MAC address for 0 controller. */
static Netc_Eth_Ip_MACFilterHashTableEntryType Netc_Eth_Ip_Ctrl_0_MACFilterHashTable[NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES];
/* Table of hash value and MAC address for 1 controller. */
static Netc_Eth_Ip_MACFilterHashTableEntryType Netc_Eth_Ip_Ctrl_1_MACFilterHashTable[NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES];
/* Table of hash value and MAC address for 2 controller. */
static Netc_Eth_Ip_MACFilterHashTableEntryType Netc_Eth_Ip_Ctrl_2_MACFilterHashTable[NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES];
/* Table of hash value and MAC address for 3 controller. */
static Netc_Eth_Ip_MACFilterHashTableEntryType Netc_Eth_Ip_Ctrl_3_MACFilterHashTable[NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES];
/* Table of hash value and MAC address for 4 controller. */
static Netc_Eth_Ip_MACFilterHashTableEntryType Netc_Eth_Ip_Ctrl_4_MACFilterHashTable[NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES];
/* Table of hash value and MAC address for 5 controller. */
static Netc_Eth_Ip_MACFilterHashTableEntryType Netc_Eth_Ip_Ctrl_5_MACFilterHashTable[NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES];
/* Table of hash value and MAC address for 6 controller. */
static Netc_Eth_Ip_MACFilterHashTableEntryType Netc_Eth_Ip_Ctrl_6_MACFilterHashTable[NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES];
/* Table of hash value and MAC address for 7 controller. */
static Netc_Eth_Ip_MACFilterHashTableEntryType Netc_Eth_Ip_Ctrl_7_MACFilterHashTable[NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES];

Netc_Eth_Ip_MACFilterHashTableEntryType *MACFilterHashTableAddrs[FEATURE_NETC_ETH_NUMBER_OF_CTRLS] = \
{ 
	&Netc_Eth_Ip_Ctrl_0_MACFilterHashTable[0U],
	&Netc_Eth_Ip_Ctrl_1_MACFilterHashTable[0U],
	&Netc_Eth_Ip_Ctrl_2_MACFilterHashTable[0U],
	&Netc_Eth_Ip_Ctrl_3_MACFilterHashTable[0U],
	&Netc_Eth_Ip_Ctrl_4_MACFilterHashTable[0U],
	&Netc_Eth_Ip_Ctrl_5_MACFilterHashTable[0U],
	&Netc_Eth_Ip_Ctrl_6_MACFilterHashTable[0U],
	&Netc_Eth_Ip_Ctrl_7_MACFilterHashTable[0U]
};

#endif /* (NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES > 0) */
/* ---------------------------------- END: MAC Filter Tables  ---------------------------------- */


#define ETH_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_NETC_MemMap.h"

#define ETH_43_NETC_START_SEC_CONFIG_DATA_32
#include "Eth_43_NETC_MemMap.h"
/* ----------------------------------START: Rx External Buffers Addresses  ---------------------------------- */

#ifdef NETC_ETH_0_USED
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
uint32 Netc_Eth_0_RxExternalDataBuffAdd[NETC_ETH_MAX_NUMBER_OF_RXBD * 1U];
#endif /* if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS) */
#endif /* NETC_ETH_0_USED */
/* ----------------------------------END: Rx External Buffers Addresses  ---------------------------------- */

#define ETH_43_NETC_STOP_SEC_CONFIG_DATA_32
#include "Eth_43_NETC_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

