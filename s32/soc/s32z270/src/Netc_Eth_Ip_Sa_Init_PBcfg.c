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
*   @file Netc_Eth_Ip_Sa_Init_PBcfg.c
*
*   @addtogroup Netc_Eth_Ip
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
#include "Netc_Eth_Ip_Sa_Init_PBcfg.h"
#include "Netc_Eth_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETH_IP_SA_INIT_PBCFG_VENDOR_ID_C                     43
#define NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define NETC_ETH_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION_C              2
#define NETC_ETH_IP_SA_INIT_PBCFG_SW_MINOR_VERSION_C              0
#define NETC_ETH_IP_SA_INIT_PBCFG_SW_PATCH_VERSION_C              1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Netc_Eth_Ip_Sa_Init_PBcfg.h */
#if (NETC_ETH_IP_SA_INIT_PBCFG_VENDOR_ID_C != NETC_ETH_IP_SA_INIT_PBCFG_VENDOR_ID)
    #error "Netc_Eth_Ip_Sa_Init_PBcfg.c and Netc_Eth_Ip_Sa_Init_PBcfg.h have different vendor ids"
#endif
#if ((NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION_C    != NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION_C != NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Netc_Eth_Ip_Sa_Init_PBcfg.c and Netc_Eth_Ip_Sa_Init_PBcfg.h are different"
#endif
#if ((NETC_ETH_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION_C != NETC_ETH_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION) || \
     (NETC_ETH_IP_SA_INIT_PBCFG_SW_MINOR_VERSION_C != NETC_ETH_IP_SA_INIT_PBCFG_SW_MINOR_VERSION) || \
     (NETC_ETH_IP_SA_INIT_PBCFG_SW_PATCH_VERSION_C != NETC_ETH_IP_SA_INIT_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Netc_Eth_Ip_Sa_Init_PBcfg.c and Netc_Eth_Ip_Sa_Init_PBcfg.h are different"
#endif

/* Checks against Netc_Eth_Ip_Types.h */
#if (NETC_ETH_IP_SA_INIT_PBCFG_VENDOR_ID_C != NETC_ETH_IP_TYPES_VENDOR_ID)
    #error "Netc_Eth_Ip_Sa_Init_PBcfg.c and Netc_Eth_Ip_Types.h have different vendor ids"
#endif
#if ((NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != NETC_ETH_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION_C    != NETC_ETH_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETH_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION_C != NETC_ETH_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Netc_Eth_Ip_Sa_Init_PBcfg.c and Netc_Eth_Ip_Types.h are different"
#endif
#if ((NETC_ETH_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION_C != NETC_ETH_IP_TYPES_SW_MAJOR_VERSION) || \
     (NETC_ETH_IP_SA_INIT_PBCFG_SW_MINOR_VERSION_C != NETC_ETH_IP_TYPES_SW_MINOR_VERSION) || \
     (NETC_ETH_IP_SA_INIT_PBCFG_SW_PATCH_VERSION_C != NETC_ETH_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Netc_Eth_Ip_Sa_Init_PBcfg.c and Netc_Eth_Ip_Types.h are different"
#endif


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (STD_OFF == NETC_ETH_IP_HAS_CACHE_MANAGEMENT)
#define ETH_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_NETC_MemMap.h"
#else
#define ETH_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"
#endif
/* ---------------------------------- BEGIN: TX generation ---------------------------------- */
extern VAR_ALIGN(Netc_Eth_Ip_TxBDRType Netc_Eth_0_TxRing_0_DescBuffer[NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
extern VAR_ALIGN(uint8 Netc_Eth_0_TxRing_0_DataBuffer[(NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_0_TXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
/* ---------------------------------- END: TX generation ---------------------------------- */

/* ---------------------------------- BEGIN: RX generation ---------------------------------- */
extern VAR_ALIGN(Netc_Eth_Ip_RxBDRType Netc_Eth_0_RxRing_0_DescBuffer[NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)
extern VAR_ALIGN(uint8 Netc_Eth_0_RxRing_0_DataBuffer[(NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR * NETC_ETH_0_RXBDR_0_MAX_BUFFLEN)], FEATURE_NETC_BUFF_ALIGNMENT_BYTES)
/* ---------------------------------- END: RX generation ---------------------------------- */
#if (STD_OFF == NETC_ETH_IP_HAS_CACHE_MANAGEMENT)
#define ETH_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_NETC_MemMap.h"
#else
#define ETH_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"
#endif

#define ETH_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"
extern Netc_Eth_Ip_StateType Netc_Eth_0_StateStructure;
#define ETH_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"


#define ETH_43_NETC_START_SEC_CONFIG_DATA_32
#include "Eth_43_NETC_MemMap.h"
/* ---------------------------------- BEGIN: Rx External Buffers Addresses ---------------------------------- */
#ifdef NETC_ETH_0_USED
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
extern uint32 Netc_Eth_0_RxExternalDataBuffAdd[NETC_ETH_MAX_NUMBER_OF_RXBD * 1U];
#endif /*(STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS) */
#endif /* NETC_ETH_0_USED */
/* ---------------------------------- END: Rx External Buffers Addresses ---------------------------------- */

#define ETH_43_NETC_STOP_SEC_CONFIG_DATA_32
#include "Eth_43_NETC_MemMap.h"


#define ETH_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"
extern volatile VAR_ALIGN(Netc_Eth_Ip_VsiToPsiMsgType Netc_Eth_Ip_Psi_RxVsi1MsgCmd, FEATURE_NETC_ETH_VSI_MSG_ALIGNMENT)
#define ETH_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"
/*==================================================================================================
*                                  GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/
#define ETH_43_NETC_START_SEC_CODE
#include "Eth_43_NETC_MemMap.h"
#define ETH_43_NETC_STOP_SEC_CODE
#include "Eth_43_NETC_MemMap.h"
/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define ETH_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_NETC_MemMap.h"

/** @brief Vector with all the command BDR used. */
VAR_ALIGN(static Netc_Eth_Ip_NTMPMessageHeaderFormatType Netc_Eth_CommandBDR[NETC_ETH_IP_ACTUAL_CBDR_SIZE], FEATURE_NETC_BUFFDESCR_ALIGNMENT_BYTES)

#define ETH_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_NETC_MemMap.h"

#define ETH_43_NETC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"

static const Netc_Eth_Ip_RxRingConfigType Netc_Eth_0_aRxRingConfig[1U] = \
{
	{
		/* .ringDesc= */	Netc_Eth_0_RxRing_0_DescBuffer,
		/* .callback= */	NULL_PTR,
		/* .buffer= */	Netc_Eth_0_RxRing_0_DataBuffer,
		/* .ringSize= */	8U,
		/* .maxRingSize= */	NETC_ETH_0_RXBDR_0_MAX_NUM_OF_DESCR,
		/* .bufferLen= */	64U + FEATURE_NETC_ETH_CUSTOM_TAG_SIZE,
		/* .maxBuffLen= */	NETC_ETH_0_RXBDR_0_MAX_BUFFLEN,
		/* .TimerThreshold= */	(uint32)1U,
		/* .PacketsThreshold= */	1U
	}
};

static const Netc_Eth_Ip_TxRingConfigType Netc_Eth_0_aTxRingConfig[1U] = \
{
	{
		/* .ringDesc= */	Netc_Eth_0_TxRing_0_DescBuffer,
		/* .callback= */	NULL_PTR,
		/* .buffer= */	Netc_Eth_0_TxRing_0_DataBuffer,
		/* .ringSize= */	8U,
		/* .maxRingSize= */	NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR,
		/* .bufferLen= */	64U,
		/* .maxBuffLen= */	NETC_ETH_0_TXBDR_0_MAX_BUFFLEN,
		/* .Weight= */	0U,
		/* .Priority= */	0U,
		/* .TimerThreshold= */	(uint32)0U,
		/* .PacketsThreshold= */	(uint8)0U
	}
};





static const Netc_Eth_Ip_GeneralSIConfigType Netc_Eth_0_GeneralSIConfig[8U] = \
{
	{
		/* .SIId= */	0U,
		/* .EnableSI= */	(boolean)TRUE,
		/* .numberOfRxBDR= */	1U,
		/* .numberOfTxBDR= */	1U,
		/* .SIBandwidthWeight= */	0U,
		/* .numberOfMSIs= */	1U,
		/* .VSITCtoTransmitTrafficClass= */	{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },
		/* .primaryMACAddress= */	{ 0x66, 0x55, 0x44, 0x33, 0x22, 0x11},
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
		/* .EnableSIVlan= */	(boolean)FALSE,
		/* .SiVLANConfig= */
		{
			/* .ProtocolIdentifier= */	NETC_ETH_IP_STANDARD_CVLAN,
			/* .PriorityCodePoint= */	0U,
			/* .DropIndicator= */	(boolean)FALSE,
			/* .VlanIdentifier= */	0U
		},
		/* .EnableSoftwareVlanInsert= */	(boolean)FALSE,
		/* .SIVlanControl= */	3U,
		/* .EnableVLANTagExtract= */	(boolean)FALSE,
#endif
		/* .enableAntiSpoofing= */	(boolean)FALSE,
		/* .changeMACAllowed= */	(boolean)TRUE,
		/* .hashFilterUpdateAllowed= */	(boolean)TRUE,
		/* .multicastPromiscuousChangeAllowed= */	(boolean)TRUE,
		/* .enableSIPruning= */	(boolean)FALSE,
	},
	{
		/* .SIId= */	1U,
		/* .EnableSI= */	(boolean)TRUE,
		/* .numberOfRxBDR= */	1U,
		/* .numberOfTxBDR= */	1U,
		/* .SIBandwidthWeight= */	0U,
		/* .numberOfMSIs= */	1U,
		/* .VSITCtoTransmitTrafficClass= */	{ 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
		/* .primaryMACAddress= */	{ 0x66, 0x55, 0x44, 0x33, 0x22, 0x22},
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
		/* .EnableSIVlan= */	(boolean)FALSE,
		/* .SiVLANConfig= */
		{
			/* .ProtocolIdentifier= */	NETC_ETH_IP_STANDARD_CVLAN,
			/* .PriorityCodePoint= */	0U,
			/* .DropIndicator= */	(boolean)FALSE,
			/* .VlanIdentifier= */	0U
		},
		/* .EnableSoftwareVlanInsert= */	(boolean)FALSE,
		/* .SIVlanControl= */	0U,
		/* .EnableVLANTagExtract= */	(boolean)FALSE,
#endif
		/* .enableAntiSpoofing= */	(boolean)FALSE,
		/* .changeMACAllowed= */	(boolean)FALSE,
		/* .hashFilterUpdateAllowed= */	(boolean)FALSE,
		/* .multicastPromiscuousChangeAllowed= */	(boolean)FALSE,
		/* .enableSIPruning= */	(boolean)FALSE,
	},
	{
		/* .SIId= */	2U,
		/* .EnableSI= */	(boolean)FALSE,
		/* .numberOfRxBDR= */	1U,
		/* .numberOfTxBDR= */	1U,
		/* .SIBandwidthWeight= */	0U,
		/* .numberOfMSIs= */	1U,
		/* .VSITCtoTransmitTrafficClass= */	{ 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
		/* .primaryMACAddress= */	{ 0x66, 0x55, 0x44, 0x33, 0x22, 0x11},
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
		/* .EnableSIVlan= */	(boolean)FALSE,
		/* .SiVLANConfig= */
		{
			/* .ProtocolIdentifier= */	NETC_ETH_IP_STANDARD_CVLAN,
			/* .PriorityCodePoint= */	0U,
			/* .DropIndicator= */	(boolean)FALSE,
			/* .VlanIdentifier= */	0U
		},
		/* .EnableSoftwareVlanInsert= */	(boolean)FALSE,
		/* .SIVlanControl= */	0U,
		/* .EnableVLANTagExtract= */	(boolean)FALSE,
#endif
		/* .enableAntiSpoofing= */	(boolean)FALSE,
		/* .changeMACAllowed= */	(boolean)FALSE,
		/* .hashFilterUpdateAllowed= */	(boolean)FALSE,
		/* .multicastPromiscuousChangeAllowed= */	(boolean)FALSE,
		/* .enableSIPruning= */	(boolean)FALSE,
	},
	{
		/* .SIId= */	3U,
		/* .EnableSI= */	(boolean)FALSE,
		/* .numberOfRxBDR= */	1U,
		/* .numberOfTxBDR= */	1U,
		/* .SIBandwidthWeight= */	0U,
		/* .numberOfMSIs= */	1U,
		/* .VSITCtoTransmitTrafficClass= */	{ 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
		/* .primaryMACAddress= */	{ 0x66, 0x55, 0x44, 0x33, 0x22, 0x11},
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
		/* .EnableSIVlan= */	(boolean)FALSE,
		/* .SiVLANConfig= */
		{
			/* .ProtocolIdentifier= */	NETC_ETH_IP_STANDARD_CVLAN,
			/* .PriorityCodePoint= */	0U,
			/* .DropIndicator= */	(boolean)FALSE,
			/* .VlanIdentifier= */	0U
		},
		/* .EnableSoftwareVlanInsert= */	(boolean)FALSE,
		/* .SIVlanControl= */	0U,
		/* .EnableVLANTagExtract= */	(boolean)FALSE,
#endif
		/* .enableAntiSpoofing= */	(boolean)FALSE,
		/* .changeMACAllowed= */	(boolean)FALSE,
		/* .hashFilterUpdateAllowed= */	(boolean)FALSE,
		/* .multicastPromiscuousChangeAllowed= */	(boolean)FALSE,
		/* .enableSIPruning= */	(boolean)FALSE,
	},
	{
		/* .SIId= */	4U,
		/* .EnableSI= */	(boolean)FALSE,
		/* .numberOfRxBDR= */	1U,
		/* .numberOfTxBDR= */	1U,
		/* .SIBandwidthWeight= */	0U,
		/* .numberOfMSIs= */	1U,
		/* .VSITCtoTransmitTrafficClass= */	{ 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
		/* .primaryMACAddress= */	{ 0x66, 0x55, 0x44, 0x33, 0x22, 0x11},
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
		/* .EnableSIVlan= */	(boolean)FALSE,
		/* .SiVLANConfig= */
		{
			/* .ProtocolIdentifier= */	NETC_ETH_IP_STANDARD_CVLAN,
			/* .PriorityCodePoint= */	0U,
			/* .DropIndicator= */	(boolean)FALSE,
			/* .VlanIdentifier= */	0U
		},
		/* .EnableSoftwareVlanInsert= */	(boolean)FALSE,
		/* .SIVlanControl= */	0U,
		/* .EnableVLANTagExtract= */	(boolean)FALSE,
#endif
		/* .enableAntiSpoofing= */	(boolean)FALSE,
		/* .changeMACAllowed= */	(boolean)FALSE,
		/* .hashFilterUpdateAllowed= */	(boolean)FALSE,
		/* .multicastPromiscuousChangeAllowed= */	(boolean)FALSE,
		/* .enableSIPruning= */	(boolean)FALSE,
	},
	{
		/* .SIId= */	5U,
		/* .EnableSI= */	(boolean)FALSE,
		/* .numberOfRxBDR= */	1U,
		/* .numberOfTxBDR= */	1U,
		/* .SIBandwidthWeight= */	0U,
		/* .numberOfMSIs= */	1U,
		/* .VSITCtoTransmitTrafficClass= */	{ 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
		/* .primaryMACAddress= */	{ 0x66, 0x55, 0x44, 0x33, 0x22, 0x11},
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
		/* .EnableSIVlan= */	(boolean)FALSE,
		/* .SiVLANConfig= */
		{
			/* .ProtocolIdentifier= */	NETC_ETH_IP_STANDARD_CVLAN,
			/* .PriorityCodePoint= */	0U,
			/* .DropIndicator= */	(boolean)FALSE,
			/* .VlanIdentifier= */	0U
		},
		/* .EnableSoftwareVlanInsert= */	(boolean)FALSE,
		/* .SIVlanControl= */	0U,
		/* .EnableVLANTagExtract= */	(boolean)FALSE,
#endif
		/* .enableAntiSpoofing= */	(boolean)FALSE,
		/* .changeMACAllowed= */	(boolean)FALSE,
		/* .hashFilterUpdateAllowed= */	(boolean)FALSE,
		/* .multicastPromiscuousChangeAllowed= */	(boolean)FALSE,
		/* .enableSIPruning= */	(boolean)FALSE,
	},
	{
		/* .SIId= */	6U,
		/* .EnableSI= */	(boolean)FALSE,
		/* .numberOfRxBDR= */	1U,
		/* .numberOfTxBDR= */	1U,
		/* .SIBandwidthWeight= */	0U,
		/* .numberOfMSIs= */	1U,
		/* .VSITCtoTransmitTrafficClass= */	{ 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
		/* .primaryMACAddress= */	{ 0x66, 0x55, 0x44, 0x33, 0x22, 0x11},
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
		/* .EnableSIVlan= */	(boolean)FALSE,
		/* .SiVLANConfig= */
		{
			/* .ProtocolIdentifier= */	NETC_ETH_IP_STANDARD_CVLAN,
			/* .PriorityCodePoint= */	0U,
			/* .DropIndicator= */	(boolean)FALSE,
			/* .VlanIdentifier= */	0U
		},
		/* .EnableSoftwareVlanInsert= */	(boolean)FALSE,
		/* .SIVlanControl= */	0U,
		/* .EnableVLANTagExtract= */	(boolean)FALSE,
#endif
		/* .enableAntiSpoofing= */	(boolean)FALSE,
		/* .changeMACAllowed= */	(boolean)FALSE,
		/* .hashFilterUpdateAllowed= */	(boolean)FALSE,
		/* .multicastPromiscuousChangeAllowed= */	(boolean)FALSE,
		/* .enableSIPruning= */	(boolean)FALSE,
	},
	{
		/* .SIId= */	7U,
		/* .EnableSI= */	(boolean)FALSE,
		/* .numberOfRxBDR= */	1U,
		/* .numberOfTxBDR= */	1U,
		/* .SIBandwidthWeight= */	0U,
		/* .numberOfMSIs= */	1U,
		/* .VSITCtoTransmitTrafficClass= */	{ 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
		/* .primaryMACAddress= */	{ 0x66, 0x55, 0x44, 0x33, 0x22, 0x11},
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
		/* .EnableSIVlan= */	(boolean)FALSE,
		/* .SiVLANConfig= */
		{
			/* .ProtocolIdentifier= */	NETC_ETH_IP_STANDARD_CVLAN,
			/* .PriorityCodePoint= */	0U,
			/* .DropIndicator= */	(boolean)FALSE,
			/* .VlanIdentifier= */	0U
		},
		/* .EnableSoftwareVlanInsert= */	(boolean)FALSE,
		/* .SIVlanControl= */	0U,
		/* .EnableVLANTagExtract= */	(boolean)FALSE,
#endif
		/* .enableAntiSpoofing= */	(boolean)FALSE,
		/* .changeMACAllowed= */	(boolean)FALSE,
		/* .hashFilterUpdateAllowed= */	(boolean)FALSE,
		/* .multicastPromiscuousChangeAllowed= */	(boolean)FALSE,
		/* .enableSIPruning= */	(boolean)FALSE,
	}
};
    
static const Netc_Eth_Ip_StationInterfaceConfigType Netc_Eth_0_StationInterfaceConfig = \
{
		/* .enableVlanToIpvMapping= */	(boolean)FALSE,
		/* .discardBroadcastFrames= */	(boolean)FALSE,
		/* .discardMulticastFrames= */	(boolean)FALSE,
		/* .discardUnicastFrames= */	(boolean)FALSE,
		/* .vlanToIpv= */ {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U},
		/* .ipvToBDR= */ {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U},
		/* .numberOfRxBDR= */	1U,
		/* .numberOfTxBDR= */	1U,
		/* .commandBDConfig= */	{ &Netc_Eth_CommandBDR[0U], NETC_ETH_IP_COMMAND_BDR_LENGTH },
		/* .VSItoPSIMsgCommand= */	NULL_PTR,
		/* .ctrlLogicalIndex= */	0U,
		/* .txMruMailboxAddr= */	NULL_PTR,
		/* .rxMruMailboxAddr= */	NULL_PTR,
		/* .siMsgMruMailboxAddr= */	NULL_PTR,
		/* .EnableSIMsgInterrupt= */(boolean)TRUE,
#if (0U != NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES)
	/* .NumberOfConfiguredMulticastMacHashFilterEntries */	0U,
	/* .(*MulticastMACFilterEntries)[NETC_ETH_IP_MAX_NUMBER_OF_MULTICAST_MAC_HASH_FILTER_ENTRIES] */	NULL_PTR, 
#endif
		/* .RxInterrupts= */	(uint32)1UL,
		/* .TxInterrupts= */	(uint32)0UL
};




static const Netc_Eth_Ip_EnetcGeneralConfigType Netc_Eth_0_GeneralConfig = \
{
		/* .numberOfConfiguredSis= */	8U,
		/* .stationInterfaceGeneralConfig[NETC_F3_NUM_SI_COUNT]= */	&Netc_Eth_0_GeneralSIConfig,
		/* .VSItoPSIMsgCommand= */	{ &Netc_Eth_Ip_Psi_RxVsi1MsgCmd, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR },
		/* .priorityToICM[NETC_ETH_IP_NUMBER_OF_PRIORITIES]= */	{ ICM_LOW_PRIORITY, ICM_LOW_PRIORITY, ICM_LOW_PRIORITY, ICM_LOW_PRIORITY, ICM_LOW_PRIORITY, ICM_LOW_PRIORITY, ICM_LOW_PRIORITY, ICM_LOW_PRIORITY },
		/* .priorityToTrafficClass[NETC_ETH_IP_NUMBER_OF_PRIORITIES]= */	{ 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
		/* .pcpToIpv[NETC_ETH_IP_NUMBER_OF_PRIORITIES]= */	{ 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
		/*!< .portPPDUByteCountOverhead= */	20U, 
		/*!< .portMACSecByteCountOverhead= */	0U, 
		/*!< .portTimeGateSchedulingAdvanceTimeOffsetReg= */	(uint32)0U, 
		/*!< .portTimeAwareShaperEnable= */	(boolean)FALSE, 
		/*!< .portEgressAdminBaseTime= */	0U, 
		/*!< .portEgressAdminCycleTime= */	0U, 
		/*!< .portEgressAdminCycleTimeExt= */	0U, 
		/*!< .numberOfGateControlListEntries= */	0U, 
		/*!< .(*TimeGateControlListEntries)[numberOfGateControlListEntries]= */	NULL_PTR, 
#if (NETC_ETH_MAX_NUMBER_OF_IPFTABLE_LIST > 0U)
		/*!< .numberOfIPFTableList= */	0U, 
		/*!< .(*IngressPortFilterTableList)[NETC_ETH_MAX_NUMBER_OF_IPFTABLE_LIST]= */	NULL_PTR,
#endif
		/* .(*cbsConfig)[NETC_ETH_IP_NUMBER_OF_PRIORITIES]= */	NULL_PTR,
	/* .(*EthKeyConstruction)[2U]= */	NULL_PTR,
#if (NETC_ETH_IP_NUMBER_OF_MAC_FILTER_TABLE_ENTRIES > 0U)
	/* .NumberOfMacFilterEntries= */	0U,
	/* .(*MacTableEntries)[NETC_ETH_IP_NUMBER_OF_MAC_FILTER_TABLE_ENTRIES]= */	NULL_PTR, 
#endif
#if (NETC_ETH_IP_NUMBER_OF_VLAN_FILTER_ENTRIES > 0U)
	/* .NumberOfVLANFilterEntries= */	0U,
	/* .(*VLANTableEntries)[NETC_ETH_IP_NUMBER_OF_VLAN_FILTER_ENTRIES]= */	NULL_PTR, 
#endif
#if (NETC_ETH_IP_NUMBER_OF_RP_ENTRIES > 0U)
	/* .NumberOfRPTableEntries= */	0U,
	/* .(*RPTableEntries)[NETC_ETH_IP_NUMBER_OF_RP_ENTRIES]= */	NULL_PTR, 
#endif
#if (NETC_ETH_NUMBER_OF_SGCL_ENTRIES > 0U)
	/* .NumberOfSGCLEntries= */	0U,
	/* .(*StreamGateControlListEntries)[NETC_ETH_NUMBER_OF_SGCL_ENTRIES]= */	NULL_PTR,
#endif
#if (NETC_ETH_NUMBER_OF_SGI_ENTRIES > 0U)
	/* .NumberOfSGIEntries= */	0U,
	/* .(*StreamGateInstanceEntries)[NETC_ETH_NUMBER_OF_SGI_ENTRIES]= */	NULL_PTR,
#endif
#if (NETC_ETH_NUMBER_OF_STREAMIDENTIFICATION_ENTRIES > 0U)
	/* .NumberOfIsiEntries= */	0U,
	/* .(*IsiEntries)[NETC_ETH_NUMBER_OF_STREAMIDENTIFICATION_ENTRIES]= */	NULL_PTR,
#endif
#if (NETC_ETH_NUMBER_OF_INGRESSSTREAM_ENTRIES > 0U)
	/* .NumberOfIngrStreamEntries= */	0U,
	/* .(*IngressStreamEntries)[NETC_ETH_NUMBER_OF_INGRESSSTREAM_ENTRIES]= */	NULL_PTR,
#endif
		/* .maskMACPromiscuousMulticastEnable= */	(uint16)0x0U,
		/* .maskMACPromiscuousUnicastEnable= */	(uint16)0x0U,
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
		/* .CustomVlanEthertype1= */0UL,
		/* .CustomVlanEthertype2= */0UL,
		/* .maskMACVLANPromiscuousEnable= */	(uint16)0x3U,
		/* .maskVLANAllowUntaggedEnable= */	(uint32)0x30000U,
#endif
		/* .rxCheckSumOffloadingTCPUDP= */1U,
		/* .rxCheckSumOffloadingIPV4= */1U,
		/* .enableUncorrectableErrors= */(boolean)FALSE,
		/* .enableCorrectableErrors= */(boolean)FALSE,
		/* .errorReportigSingleECCErrorsThreshold=    */0U,
		/* .errorReportingMultiBitECCErrorsThreshold=    */0U,
		/* .errorReportigIntegrityErrorsThreshold=    */0U,
		/* .errorReportingSystemBusErrorsThreshold=    */0U,
		/* .errorReportingCallback=     */		NULL_PTR,
#if ((STD_ON == NETC_ETH_IP_EXTENDED_BUFF) && (STD_ON == NETC_ETH_IP_CUSTOM_TAG_SUPPORT))
		/* .CustomTPID= */	(uint16)U,
		/* .CustomIPV= */	(uint8)0U,
		/* .CustomDR= */	(uint8)0U,
#endif
		/* .DefaultIPV= */	(uint8)0U,
		/* .DefaultDR= */	(uint8)0U,
#if (STD_ON == NETC_ETH_IP_MANAGEMENT_SUPPORT_API)
		/* .EthSwtManagementIpv= */	(uint8)0U
#endif
};

const Netc_Eth_Ip_ConfigType Netc_Eth_0_ConfigPB_INIT = \
{
		/* .siType= */	NETC_ETH_IP_PHYSICAL_SI,
		/* .generalConfig= */	&Netc_Eth_0_GeneralConfig,
		/* .siConfig= */	&Netc_Eth_0_StationInterfaceConfig,
		/* .stateStructure= */	&Netc_Eth_0_StateStructure,
		/* .paCtrlRxRingConfig= */	&Netc_Eth_0_aRxRingConfig,
		/* .paCtrlTxRingConfig= */	&Netc_Eth_0_aTxRingConfig,
		/* .netcClockFrequency= */	300000000UL, 
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
		/* .rxExternalBuffersAddr= */	Netc_Eth_0_RxExternalDataBuffAdd,
#endif
		/* .RfsEntriesNb= */	0U,
		/* .RfsConfigTable= */	NULL_PTR
};

#define ETH_43_NETC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

