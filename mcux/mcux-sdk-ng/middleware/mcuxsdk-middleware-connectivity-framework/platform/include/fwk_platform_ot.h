/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2022 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_PLATFORM_OT_H_
#define _FWK_PLATFORM_OT_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>

/* -------------------------------------------------------------------------- */
/*                                Public types                                */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Low level initialization for OpenThread/15.4, can be used to initialize 15.4 Controller
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_InitOt(void);

/*!
 * \brief Low level deinitialization for OpenThread/15.4, can be used to deinitialize 15.4 Controller
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_TerminateOt(void);

/*!
 * \brief Low level reset for OpenThread/15.4, can be used to reset the CPU2
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_ResetOt(void);

/*!
 * \brief Get MAC address for OpenThread/15.4
 *
 * \param  eui64_address at least 8 byte of storage to receive 64 bit address.
 */
void PLATFORM_GetIeee802_15_4Addr(uint8_t *eui64_address);

#ifdef __ZEPHYR__
#define ZBOSS_HEADER_LEN       8
#define MAC_ADDRESS_OFFSET     ZBOSS_HEADER_LEN
#define MAC_ADDRESS_LEN        8
#define ZBOSS_CHMASKS_LEN      40
#define ZBOSS_TXPOWER_LEN      270
#define ZBOSS_OPTIONS_LEN      1
#define ZBOSS_INSTALLCODE_LEN  18
#define ZBOSS_PASSCODE_LEN     4

typedef struct __attribute__ ((packed)) PLATFORM_zboss_factory_settings_s {
  /* Created for Zboss */
  uint8_t zboss_header[ZBOSS_HEADER_LEN];
  uint8_t mac_addr[MAC_ADDRESS_LEN];                /* Shared by ieee802154 driver & Zboss */
  uint8_t zboss_ch_masks[ZBOSS_CHMASKS_LEN];
  uint8_t zboss_tw_power[ZBOSS_TXPOWER_LEN];
  uint8_t zboss_options[ZBOSS_OPTIONS_LEN];

  /* Created for Zboss, to be stored in blobs */
  uint8_t zboss_installcode[ZBOSS_INSTALLCODE_LEN];
  uint8_t zboss_passcode[ZBOSS_PASSCODE_LEN];
} PLATFORM_zboss_factory_settings_t;

/*!
 * \brief Return Zboss factory settings
 *
 * \param settings_buf pointer on buffer storage supplied by caller to receive Zboss
 * factory settings.
 *
 */
int PLATFORM_GetZbossFactorySettings(PLATFORM_zboss_factory_settings_t *settings_buf);
#endif

#ifdef __cplusplus
}
#endif

#endif /* _FWK_PLATFORM_OT_H_ */
