/* -------------------------------------------------------------------------- */
/*                        Copyright 2021-2022, 2025 NXP                       */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fsl_common.h"
#include "fsl_adapter_rpmsg.h"

#include "fwk_platform.h"
#include "fwk_platform_ble.h"

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */

static RPMSG_HANDLE_DEFINE(hciRpmsgHandle);
const static hal_rpmsg_config_t hciRpmsgConfig = {
    .local_addr  = 30,
    .remote_addr = 40,
};

static void (*hci_rx_callback)(uint8_t packetType, uint8_t *data, uint16_t len);

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Init NBU BLE specific components (HCI RPMSG channel...)
 *
 */
static void PLATFORM_InitHciLink(void);

/*!
 * \brief RPMSG Rx callback used to receive HCI messages from Host
 *
 * \param[in] param Usually NULL
 * \param[in] data pointer to data buffer
 * \param[in] len size of the data
 * \return hal_rpmsg_return_status_t tells RPMSG to free or hold the buffer
 */
static hal_rpmsg_return_status_t PLATFORM_HciRpmsgRxCallback(void *param, uint8_t *data, uint32_t len);

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

void PLATFORM_InitBle(void)
{
    /* Initializes the RPMSG adapter module for dual core communication */
    (void)HAL_RpmsgMcmgrInit();

    /* Init hci link*/
    PLATFORM_InitHciLink();

#if (defined(gPlatformUseLptmr_d)) && (gPlatformUseLptmr_d == 1U)
    /* Init lptmr2*/
    PLATFORM_InitTimerManager();
#endif
}

void PLATFORM_SetHciRxCallback(void (*callback)(uint8_t packetType, uint8_t *data, uint16_t len))
{
    hci_rx_callback = callback;
}

int PLATFORM_SendHciMessage(uint8_t *msg, uint32_t len)
{
    /* Wake up host before sending the message */
    PLATFORM_RemoteActiveReqWithoutDelay();

    /* Send HCI Packet through RPMSG channel */
    (void)HAL_RpmsgSend(hciRpmsgHandle, msg, len);

    /* Release wake up request */
    PLATFORM_RemoteActiveRel();

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

/* Initialize hci Rpmsg */
static void PLATFORM_InitHciLink(void)
{
    if (kStatus_HAL_RpmsgSuccess !=
        HAL_RpmsgInit((hal_rpmsg_handle_t)hciRpmsgHandle, (hal_rpmsg_config_t *)&hciRpmsgConfig))
    {
        assert(0);
        return;
    }

    /* Set RX Callback */
    if (HAL_RpmsgInstallRxCallback((hal_rpmsg_handle_t)hciRpmsgHandle, PLATFORM_HciRpmsgRxCallback, NULL) !=
        kStatus_HAL_RpmsgSuccess)
    {
        assert(0);
    }
}

static hal_rpmsg_return_status_t PLATFORM_HciRpmsgRxCallback(void *param, uint8_t *data, uint32_t len)
{
    if (hci_rx_callback != NULL)
    {
        hci_rx_callback(data[0], &data[1], len - 1);
    }

    (void)param;

    return kStatus_HAL_RL_RELEASE;
}
