/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _S32Z270_FEATURES_H_
#define _S32Z270_FEATURES_H_

/* SOC module features */

/* @brief PIT availability on the SoC. */
#define FSL_FEATURE_SOC_PIT_COUNT (2)

/* PIT module features */

/* @brief Number of channels (related to number of registers LDVALn, CVALn, TCTRLn, TFLGn). */
#define FSL_FEATURE_PIT_TIMER_COUNT (6)
/* @brief Has lifetime timer (related to existence of registers LTMR64L and LTMR64H). */
#define FSL_FEATURE_PIT_HAS_LIFETIME_TIMER (1)
/* @brief Has chain mode (related to existence of register bit field TCTRLn[CHN]). */
#define FSL_FEATURE_PIT_HAS_CHAIN_MODE (1)
/* @brief Has shared interrupt handler (has not individual interrupt handler for each channel). */
#define FSL_FEATURE_PIT_HAS_SHARED_IRQ_HANDLER (1)
/* @brief Has timer enable control. */
#define FSL_FEATURE_PIT_HAS_MDIS (1)

/* I3C module features */
/* @brief SOC has no reset driver. */
#define FSL_FEATURE_I3C_HAS_NO_RESET (1)
/* @brief Has ERRATA_051617. */
#define FSL_FEATURE_I3C_HAS_ERRATA_051617 (1)
/* @brief Has SCL delay after START. */
#define FSL_FEATURE_I3C_HAS_START_SCL_DELAY (0)
/* @brief SOC doesn't support slave IBI/MR/HJ. */
#define FSL_FEATURE_I3C_HAS_NO_SLAVE_IBI_MR_HJ (1)
/* @brief SOC doesn't support MASTER IBI response. */
#define FSL_FEATURE_I3C_HAS_NO_MASTER_IBIRESP (1)
/* @brief SOC doesn't support In-band Common Comand Codes. */
#define FSL_FEATURE_I3C_HAS_NO_CCC (1)
/* @brief SOC doesn't support Dynamic Address. */
#define FSL_FEATURE_I3C_HAS_NO_MDYNADDR (1)

/* @brief Register MCONFIG do not have ODSTOP bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_MCONFIG_ODSTOP (1)
/* @brief Register MCONFIG do not have ODHPP bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_MCONFIG_ODHPP (1)
/* @brief Use fixed BAMATCH count, do not provide editable BAMATCH. */
#define FSL_FEATURE_I3C_HAS_NO_SCONFIG_BAMATCH (0)
/* @brief Register SCONFIG do not have OFFLINE bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SCONFIG_OFFLINE (1)
/* @brief Register SCONFIG do not have IDRAND bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SCONFIG_IDRAND (1)
/* @brief Register SCONFIG do not have S0IGNORE bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SCONFIG_S0IGNORE (1)
/* @brief Register SCONFIG has HDROK bitfield. */
#define FSL_FEATURE_I3C_HAS_HDROK (0)
/* @brief Register SCONFIG do not have DDROK bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_DDROK (1)
/* @brief Register SSTATUS do not have STDAA bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SSTATUS_STDAA (1)
/* @brief Register SSTATUS do not have STHDR bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SSTATUS_STHDR (1)
/* @brief Register SSTATUS do not have DACHG bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SSTATUS_DACHG (1)
/* @brief Register SSTATUS do not have CCC bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SSTATUS_CCC (1)
/* @brief Register SSTATUS do not have HDRMATCH bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SSTATUS_HDRMATCH (1)
/* @brief Register SSTATUS do not have CHANDLED bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SSTATUS_CHANDLED (1)
/* @brief Register SSTATUS do not have EVENT bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SSTATUS_EVENT (1)
/* @brief Register SSTATUS do not have IBIDIS bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SSTATUS_IBIDIS (1)
/* @brief Register SSTATUS do not have MRDIS bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SSTATUS_MRDIS (1)
/* @brief Register SSTATUS do not have HJDIS bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SSTATUS_HJDIS (1)
/* @brief Register SSTATUS do not have EVDET bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SSTATUS_EVDET (1)
/* @brief Register SSTATUS do not have ACTSTATE bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SSTATUS_ACTSTATE (1)
/* @brief Register SSTATUS do not have TIMECTRL bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SSTATUS_TIMECTRL (1)
/* @brief Register SERRWARN do not have HPAR bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SERRWARN_HPAR (1)
/* @brief Register SERRWARN do not have HCRC bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SERRWARN_HCRC (1)
/* @brief Register SERRWARN do not have S0S1 bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SERRWARN_S0S1 (1)
/* @brief Register MSTATUS do not have SLVSTART bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_MSTATUS_SLVSTART (1)
/* @brief Register MSTATUS do not have IBIWON bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_MSTATUS_IBIWON (1)
/* @brief Register MSTATUS do not have IBITYPE bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_MSTATUS_IBITYPE (1)
/* @brief Register MSTATUS do not have NOWMASTER bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_MSTATUS_NOWMASTER (1)
/* @brief Register MERRWARN do not have HPAR bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_MERRWARN_HPAR (1)
/* @brief Register MERRWARN do not have HCRC bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_MERRWARN_HCRC (1)
/* @brief Register MERRWARN do not have INVREQ bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_MERRWARN_INVREQ (1)
/* @brief Has TERM bitfile in MERRWARN register. */
#define FSL_FEATURE_I3C_HAS_NO_MERRWARN_TERM (1)
/* @brief Has no register SMAXLIMITS. */
#define FSL_FEATURE_I3C_HAS_NO_SMAXLIMITS (1)
/* @brief Has no register SIDPARTNO. */
#define FSL_FEATURE_I3C_HAS_NO_SIDPARTNO (1)
/* @brief Has no register SIDEXT. */
#define FSL_FEATURE_I3C_HAS_NO_SIDEXT (1)
/* @brief Has no register SVENDORID. */
#define FSL_FEATURE_I3C_HAS_NO_SVENDORID (1)

#endif /* _S32Z270_FEATURES_H_ */
