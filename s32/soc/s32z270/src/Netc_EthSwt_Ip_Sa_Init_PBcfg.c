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
 *   @file Netc_EthSwt_IpSA__Init_PBcfg.c
 *   @internal
 *   @addtogroup NETC_ETHSWT_IP NETC_ETHSWT Driver
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
#include "Netc_EthSwt_Ip_Sa_Init_PBcfg.h"
#include "Netc_EthSwt_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_VENDOR_ID_C                    43
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_MODULE_ID_C                    89
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION_C     4
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION_C     7
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION_C  0
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION_C             2
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_MINOR_VERSION_C             0
#define NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Netc_EthSwt_Ip_Sa_Init_PBcfg.h */
#if (NETC_ETHSWT_IP_SA_INIT_PBCFG_VENDOR_ID_C != NETC_ETHSWT_IP_SA_INIT_PBCFG_VENDOR_ID)
    #error "Netc_EthSwt_Ip_Sa_Init_PBcfg.c and Netc_EthSwt_Ip_Sa_Init_PBcfg.h have different vendor ids"
#endif
#if ((NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION_C    != NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION_C != NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Netc_EthSwt_Ip_Sa_Init_PBcfg.h and Netc_EthSwt_Ip_Sa_Init_PBcfg.c are different"
#endif
#if ((NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION_C != NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION) || \
     (NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_MINOR_VERSION_C != NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_MINOR_VERSION) || \
     (NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_PATCH_VERSION_C != NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Netc_EthSwt_Ip_Sa_Init_PBcfg.c and Netc_EthSwt_Ip_Sa_Init_PBcfg.h are different"
#endif

/* Checks against Netc_EthSwt_Ip_Types.h */
#if (NETC_ETHSWT_IP_SA_INIT_PBCFG_VENDOR_ID_C != NETC_ETHSWT_IP_TYPES_VENDOR_ID)
    #error "Netc_EthSwt_Ip_Sa_Init_PBcfg.c and Netc_EthSwt_Ip_Types.h have different vendor ids"
#endif
#if ((NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != NETC_ETHSWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION_C    != NETC_ETHSWT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETHSWT_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION_C != NETC_ETHSWT_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Netc_EthSwt_Ip_Sa_Init_PBcfg.c and Netc_EthSwt_Ip_Types.h are different"
#endif
#if ((NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION_C != NETC_ETHSWT_IP_TYPES_SW_MAJOR_VERSION) || \
     (NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_MINOR_VERSION_C != NETC_ETHSWT_IP_TYPES_SW_MINOR_VERSION) || \
     (NETC_ETHSWT_IP_SA_INIT_PBCFG_SW_PATCH_VERSION_C != NETC_ETHSWT_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Netc_EthSwt_Ip_Sa_Init_PBcfg.c and Netc_EthSwt_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define ETHSWT_43_NETC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "EthSwt_43_NETC_MemMap.h"


/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
static Netc_EthSwt_Ip_PriorityRegenerationType Netc_EthSwt_0_Port_0_PriorityRegenerationConfig_INIT[8U] = \
{
	{ 
		/*!< EthSwtPriorityRegenerationIngressPriority */ 0U, \
		/*!< EthSwtPriorityRegenerationRegeneratedPriority */ 0U \
	}, \
	{ 
		/*!< EthSwtPriorityRegenerationIngressPriority */ 1U, \
		/*!< EthSwtPriorityRegenerationRegeneratedPriority */ 1U \
	}, \
	{ 
		/*!< EthSwtPriorityRegenerationIngressPriority */ 2U, \
		/*!< EthSwtPriorityRegenerationRegeneratedPriority */ 2U \
	}, \
	{ 
		/*!< EthSwtPriorityRegenerationIngressPriority */ 3U, \
		/*!< EthSwtPriorityRegenerationRegeneratedPriority */ 3U \
	}, \
	{ 
		/*!< EthSwtPriorityRegenerationIngressPriority */ 4U, \
		/*!< EthSwtPriorityRegenerationRegeneratedPriority */ 4U \
	}, \
	{ 
		/*!< EthSwtPriorityRegenerationIngressPriority */ 5U, \
		/*!< EthSwtPriorityRegenerationRegeneratedPriority */ 5U \
	}, \
	{ 
		/*!< EthSwtPriorityRegenerationIngressPriority */ 6U, \
		/*!< EthSwtPriorityRegenerationRegeneratedPriority */ 6U \
	}, \
	{ 
		/*!< EthSwtPriorityRegenerationIngressPriority */ 7U, \
		/*!< EthSwtPriorityRegenerationRegeneratedPriority */ 7U \
	}
};

static Netc_EthSwt_Ip_PortIngressType Netc_EthSwt_0_Port_0_IngressConfig_INIT = \
{
	/*!< EthSwtPortIngressDefaultPriority */1U, \
	/*!< EthSwtPortIngressDefaultVlan */	1U, \
	/*!< SentUntaggedFrames */	(boolean)FALSE, \
	/*!< portIngressAllowCutThroughFrames */	(boolean)FALSE, \
	/*!< EthSwtPortIngressDropUntagged */	(boolean)FALSE, \
	/*!< EthSwtDropDoubleTagged */	(boolean)FALSE, \
	/*!< EthSwtPortIngressDropSingleTagged */	(boolean)FALSE, \
	/*!< EthSwtPortIngressDropPriorityTagged */	(boolean)FALSE, \
	/*!< EthSwtPortIngressVlanModification */	1U, \
	/*!< EthSwtPortTrafficClassAssignment */	1U, \
	/*!< policer */	NULL_PTR, \
	/*!< (*priorityRegeneration)[8U] */&Netc_EthSwt_0_Port_0_PriorityRegenerationConfig_INIT, \
	/*!< PriorityTrafficClassAssignment[8U] */
	{ \
		 	{	{ (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U }	}, \
		 	{	{ (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U }	}, \
		 	{	{ (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U }	}, \
		 	{	{ (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U }	}, \
		 	{	{ (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U }	}, \
		 	{	{ (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U }	}, \
		 	{	{ (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U }	}, \
		 	{	{ (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U, (uint8)0U }	} \
	}, \
	/*!< vlanEnable */	(boolean)FALSE, \
	/*!< vlanDefaultIpv */	0U, \
	/*!< vlanDefaultDr */	0U, \
	/*!< vlanMappingProfile */	0U, \
	/*!< vlanEnableIngressPcpToPcpMapping */	(boolean)FALSE, \
	/*!< vlanIngressPcpToPcpProfile */	0U, 
	/*!< EthSwtPortIngressStreamLookUpConfig */
	{ \
	/*!< PortIngressStreamEnableLookUp */	(boolean)FALSE,\
	/*!< PortIngressStreamDefaultEntryID */	 0xFFFFU,\
	/*!< PortIngressStreamUseFirstLookUp */	(boolean)FALSE,\
	/*!< PortIngressStreamUseSecondLookUp */	(boolean)FALSE,\
	/*!< PortIngressStreamUseSecondKeyConstructionPair */	(boolean)FALSE\
	} \
};

static uint8 Netc_EthSwt_0_Port_0_VlanDrToDei_INIT[NETC_ETHSWT_IP_NUMBER_OF_DR] = \
{
	0U, 0U, 0U, 0U \
};

static Netc_EthSwt_Ip_PortEgressType Netc_EthSwt_0_Port_0_EgressConfig_INIT = \
{
	/*!< portScheduler */NULL_PTR, \
	/*!< portShaper[8U] */NULL_PTR, \
	/*!< portEgressAllowCutThroughFrames */	(boolean)FALSE, \
	/*!< enablePreemption */	(boolean)FALSE, \
	/*!< preemptionTCprofiles */	0U, \
	/*!< updateEgressDr */	(boolean)FALSE, \
	/*!< (*vlanDrToDei)[NETC_ETHSWT_IP_NUMBER_OF_DR] */	&Netc_EthSwt_0_Port_0_VlanDrToDei_INIT, \
	/*!< vlanMappingProfile */	0U, \
	/*!< vlanEnableEgressPcpToPcpMapping */	(boolean)FALSE, \
	/*!< vlanEgressPcpToPcpProfile */	0U, \
	/*!< portPPDUByteCountOverhead */	20U, \
	/*!< portMACSecByteCountOverhead */	0U, \
	/*!< portTimeGateSchedulingAdvanceTimeOffsetReg */	0U, \
	/*!< portTimeAwareShaperEnable */	(boolean)FALSE, \
	/*!< portEgressAdminBaseTime */	0U, \
	/*!< portEgressAdminCycleTime */	0U, \
	/*!< portEgressAdminCycleTimeExt */	0U, 
#if (NETC_ETHSWT_MAX_NUMBER_OF_GATECONTROLLIST_ENTRIES > 0U)
	/*!< numberOfGateControlListEntries */	0U, \
	/*!< (*TimeGateControlListEntries)[numberOfGateControlListEntries] */	NULL_PTR 
#endif
};

static Netc_EthSwt_Ip_PortType Netc_EthSwt_0_portConfigs_INIT[NETC_ETHSWT_IP_NUMBER_OF_PORTS] = \
{
	{
		/*!< EthSwtPortMacLayerPortEnable */	(boolean)FALSE, \
		/*!< ePort */	&Netc_EthSwt_0_Port_0_EgressConfig_INIT, \
		/*!< iPort */	&Netc_EthSwt_0_Port_0_IngressConfig_INIT, \
		/*!< EthSwtPortMacLayerSpeed */	ETHTRCV_BAUD_RATE_1000MBIT, \
		/* EthSwtPortMacLayerDuplexMode */	NETC_ETHSWT_PORT_FULL_DUPLEX, \
		/* EthSwtPortPhysicalLayerType */NETC_ETHSWT_RGMII_MODE, \
		/* .EthSwtPortMacAddresses[6U]= */	{0x66U, 0x55U, 0x44U, 0x33U, 0x22U, 0x11U}, \
		/* .EthSwtPortMaxDynamicEntries= */	(uint16)0U, \
		/* .EthSwtPortEnableMagicPacketDetection= */	(boolean)FALSE, \
		/* .EthSwtPortTimeStampSupport= */	(boolean)FALSE, \
		/* .EthSwtPortPruningEnable= */	(boolean)FALSE, \
		/* .EthSwtEnableFreeRunningTimer= */	(boolean)FALSE, \
		/* .EthSwtPortLoopbackEnable= */	(boolean)FALSE, \
		/* .EthSwtPortDisallowMacStationMove= */	(boolean)FALSE \
	}};

const Netc_EthSwt_Ip_ConfigType Netc_EthSwt_0_ConfigPB_INIT = \
{
	/* .MacLearningOption= */	ETHSWT_MACLEARNINGOPTION_HWDISABLED, \
	/* .EthSwtForwardingOptions= */	ETHSWT_NO_FDB_LOOKUP_FLOOD_FRAME, \
	/* .EthSwtMaxDynamicEntries= */	0U, \
	/* .EthSwtArlTableEntryTimeout= */	300U, \
	/* .EthSwtEnableSharedLearning= */	(boolean)FALSE, \
	/* .EthSwtCustomVlanEtherType1= */	(uint32)0x0U, \
	/* .EthSwtCustomVlanEtherType2= */	(uint32)0x0U, \
	/* .(*port)[NETC_ETHSWT_IP_NUMBER_OF_PORTS]= */	&Netc_EthSwt_0_portConfigs_INIT,
	/* .(*EthSwtKeyConstruction)[4U]= */	NULL_PTR,
#if (NETC_ETHSWT_NUMBER_OF_STREAMIDENTIFICATION_ENTRIES > 0U)
	/* .NumberOfIsiEntries= */	0U,
	/* .(*IsiEntries)[NETC_ETHSWT_NUMBER_OF_STREAMIDENTIFICATION_ENTRIES]= */	NULL_PTR,
#endif
#if (NETC_ETHSWT_NUMBER_OF_SEQTAG_ENTRIES > 0U)
	/* .NumberOfSeqTagEntries= */	0U,
	/* .(*SeqTagEntries)[NETC_ETHSWT_NUMBER_OF_SEQTAG_ENTRIES]= */	NULL_PTR,
#endif
#if (NETC_ETHSWT_NUMBER_OF_SEQRECOVERY_ENTRIES > 0U)
	/* .NumberOfSeqRecoveryEntries= */	0U,
	/* .(*SeqRecoveryEntries)[NETC_ETHSWT_NUMBER_OF_SEQRECOVERY_ENTRIES]= */	NULL_PTR,
#endif
#if (NETC_ETHSWT_NUMBER_OF_IPFT_ENTRIES > 0U)
	/* .NumberOfIPFTEntries= */	0U,
	/* .(*IngressPortFilterEntries)[NETC_ETHSWT_NUMBER_OF_IPFT_ENTRIES]= */	NULL_PTR,
#endif
#if (NETC_ETHSWT_NUMBER_OF_RP_ENTRIES > 0U)
	/* .NumberOfRPEntries= */	0U,
	/* .(*EthSwtRatePolicerEntries)[NETC_ETHSWT_NUMBER_OF_RP_ENTRIES]= */	NULL_PTR,
#endif
#if (NETC_ETHSWT_NUMBER_OF_SGCL_ENTRIES > 0U)
	/* .NumberOfSGCLEntries= */	0U,
	/* .(*StreamGateControlListEntries)[NETC_ETHSWT_NUMBER_OF_SGCL_ENTRIES]= */	NULL_PTR,
#endif
#if (NETC_ETHSWT_NUMBER_OF_SGI_ENTRIES > 0U)
	/* .NumberOfSGIEntries= */	0U,
	/* .(*StreamGateInstanceEntries)[NETC_ETHSWT_NUMBER_OF_SGI_ENTRIES]= */	NULL_PTR,
#endif
#if (NETC_ETHSWT_NUMBER_OF_FRAMEMODIFICATION_ENTRIES > 0U)
	/* .NumberOfFrmModifEntries= */	0U,
	/* .(*FrameModificationEntries)[NETC_ETHSWT_NUMBER_OF_FRAMEMODIFICATION_ENTRIES]= */	NULL_PTR,
#endif
#if (NETC_ETHSWT_NUMBER_OF_EGRESSTREATMENT_ENTRIES > 0U)
	/* .NumberOfEgrTreatmentEntries= */	0U,
	/* .(*EgressTreatmentEntries)[NETC_ETHSWT_NUMBER_OF_EGRESSTREATMENT_ENTRIES]= */	NULL_PTR,
#endif
#if (NETC_ETHSWT_NUMBER_OF_INGRESSSTREAM_ENTRIES > 0U)
	/* .NumberOfIngrStreamEntries= */	0U,
	/* .(*IngressStreamEntries)[NETC_ETHSWT_NUMBER_OF_INGRESSSTREAM_ENTRIES]= */	NULL_PTR,
#endif
#if (NETC_ETHSWT_NUMBER_OF_STREAMFILTER_ENTRIES > 0U)
	/* .NumberOfIngrStreamFilterEntries= */	0U,
	/* .(*IngressStreamFilterEntries)[NETC_ETHSWT_NUMBER_OF_STREAMFILTER_ENTRIES]= */	NULL_PTR,
#endif
#if (NETC_ETHSWT_NUMBER_OF_STREAMCOUNT_ENTRIES > 0U)
	/* .NumberOfIngrStreamCountEntries= */	0U,
#endif
#if (NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES > 0U)
	/* .NumberOfFdbEntries= */	0U,
	/* .(*FdbEntries)[NETC_ETHSWT_NUMBER_OF_FDB_ENTRIES]= */	NULL_PTR,
#endif
#if (NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES > 0U)
	/* .NumberOfVlanFilterEntries= */	0U,
	/* .(*VlanFilterEntries)[NETC_ETHSWT_NUMBER_OF_VLANFILTER_ENTRIES]= */	NULL_PTR,
#endif
	/* .(*vlanPcpDei2IpvProfile)[NETC_ETHSWT_IP_NUMBER_OF_PROFILES][NETC_ETHSWT_IP_NUMBER_OF_PCP_DEI]= */	NULL_PTR,
	/* .(*VlanPcpDei2DrProfile)[NETC_ETHSWT_IP_NUMBER_OF_PROFILES][NETC_ETHSWT_IP_NUMBER_OF_PCP_DEI]= */	NULL_PTR,
	/* .(*vlanPcp2PcpProfile)[NETC_ETHSWT_IP_NUMBER_OF_PROFILES][NETC_ETHSWT_IP_NUMBER_OF_PCP]= */	NULL_PTR,
	/* .(*vlanIpvDr2PcpProfile)[NETC_ETHSWT_IP_NUMBER_OF_PROFILES][NETC_ETHSWT_IP_NUMBER_OF_IPV][NETC_ETHSWT_IP_NUMBER_OF_DR]= */	NULL_PTR,
	/* .netcClockFrequency= */	300000000UL, \
	/* .netcExternalClockFrequency= */	200000000UL, \
	/* .Timer1588ClkSrc= */	ETHSWT_REFERENCE_CLOCK_DISABLED

};


#define ETHSWT_43_NETC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "EthSwt_43_NETC_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

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

