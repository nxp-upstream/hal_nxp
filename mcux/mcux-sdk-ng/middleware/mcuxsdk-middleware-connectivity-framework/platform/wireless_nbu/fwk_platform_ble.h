/*
 * Copyright 2020, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FWK_PLATFORM_BLE_H_
#define _FWK_PLATFORM_BLE_H_

#include "fsl_adapter_rpmsg.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * \brief Low level initialization for BLE Controller
 *
 */
void PLATFORM_InitBle(void);

/*!
 * \brief Registers HCI RX callback for upper layers, likely called from
 *        Controller HCI transport layers. The callback is called when PLATFORM
 *        has received a message from lower transport layers such as RPMSG/UART
 *
 * \param[in] callback function pointer to callback
 */
void PLATFORM_SetHciRxCallback(void (*callback)(uint8_t packetType, uint8_t *data, uint16_t len));

/*!
 * \brief Sends a HCI message to Controller.
 *        This is usually called from Host's HCI transport layers.
 *        This allows complete abstraction of physical transport layers from one
 *        platform to another.
 *
 * \param[in] msg pointer to HCI message buffer
 * \param[in] len size of the message
 * \return int 0 if success, negative value if error
 */
int PLATFORM_SendHciMessage(uint8_t *msg, uint32_t len);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _FWK_PLATFORM_BLE_H_ */
