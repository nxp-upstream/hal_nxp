/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FWK_CONFIG_H_
#define _FWK_CONFIG_H_

/*********************************************************************
 *        SecLib
 *********************************************************************/

/*
 * No Secure subsystem on KW43
 */
#define gRngUseSecureSubSystem_d 0

/*
 * NBU core is without DSP extension -> prevents the use of the NXP UltraFast EC P256 library on this core
 */
#define gSecLibUseDspExtension_d 0

/* If SecLib.c is used, prevent from using LTC HW as this module is located on NBU side and is used exclusively
 by Ble controller and 15.4 MAC/Phy code */
#undef FSL_FEATURE_SOC_LTC_COUNT

/*
 * On KW45/K32W148 NBU avoid usage of SecLib in RNG to prevent calls to SHA256, HMAC or AES-CTR when not required.
 * Call Lehmer LCG random generation instead.
 */
#define gRngUseSecLib_d 0

/*********************************************************************
 *        FPGA
 *********************************************************************/
#define gUseSfcRf_d 0

/*********************************************************************
 *        PLATFORM
 *********************************************************************/
/* Enable ICS RX processing in the system workqueue thread
 * If enabled, the ICS will use the system workqueue to process its received data. This allows to reduce the time spent
 * in the ISR and reduces impact on system activities.
 * Note: the system workqueue requires a dedicated thread, so enabling this feature will consume a bit of RAM for the
 * thread stack (this can be configured).
 */
#ifndef gPlatformIcsUseWorkqueueRxProcessing_d
#define gPlatformIcsUseWorkqueueRxProcessing_d 1
#endif

#endif /* _FWK_CONFIG_H_ */
