/*!
 * Copyright 2024 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * \file fwk_platform_zb.c
 * \brief PLATFORM abstraction implementation for Zigbee
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#include "fwk_platform_zb.h"
#include "fwk_platform.h"
#include "fsl_adapter_rpmsg.h"
#include "fsl_common.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#ifndef PLATFORM_ZB_MAC_RPMSG_LOCAL_ADDR
#define PLATFORM_ZB_MAC_RPMSG_LOCAL_ADDR 12
#endif

#ifndef PLATFORM_ZB_MAC_RPMSG_REMOTE_ADDR
#define PLATFORM_ZB_MAC_RPMSG_REMOTE_ADDR 22
#endif

#ifndef PLATFORM_ZB_PHY_RPMSG_LOCAL_ADDR
#define PLATFORM_ZB_PHY_RPMSG_LOCAL_ADDR 10
#endif

#ifndef PLATFORM_ZB_PHY_RPMSG_REMOTE_ADDR
#define PLATFORM_ZB_PHY_RPMSG_REMOTE_ADDR 20
#endif

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Initialize Zigbee MAC or PHY RPMSG channel
 *
 * \param[in] rpmsgHandle MAC or PHY RPMSG handle
 * \param[in] rpmsgConfig MAC or PHY RPMSG config
 * \return int return status: >=0 for success, <0 for errors
 */
static int PLATFORM_InitZbRpmsg(hal_rpmsg_handle_t rpmsgHandle, hal_rpmsg_config_t rpmsgConfig);

/*!
 * \brief Send Zigbee message to either MAC or PHY
 *
 * \param[in] rpmsgHandle MAC or PHY RPMSG handle
 * \param[in] msg pointer to the message to send
 * \param[in] len size of the message buffer
 * \return int return status: >=0 for success, <0 for errors
 */
static int PLATFORM_SendZbMessage(hal_rpmsg_handle_t rpmsgHandle, uint8_t *msg, uint32_t len);

/*!
 * \brief RPMSG Rx callback used to receive Zigbee MAC and PHY messages from Controller
 *        This callback is used for both MAC and PHY links, so we use the "param" input
 *        to get the remote addr of the link
 *
 * \param[in] param remote_addr of the link
 * \param[in] data pointer to data buffer
 * \param[in] len size of the data
 * \return hal_rpmsg_return_status_t tells RPMSG to free or hold the buffer
 */
static hal_rpmsg_return_status_t PLATFORM_ZbRpmsgRxCallback(void *param, uint8_t *data, uint32_t len);

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static platform_zb_rx_callback_t zbMacRxCallback;
static platform_zb_rx_callback_t zbPhyRxCallback;
static void                     *zbMacCallbackParam = NULL;
static void                     *zbPhyCallbackParam = NULL;

static RPMSG_HANDLE_DEFINE(zbMacRpmsgHandle);
static const hal_rpmsg_config_t zbMacRpmsgConfig = {
    .local_addr  = PLATFORM_ZB_MAC_RPMSG_LOCAL_ADDR,
    .remote_addr = PLATFORM_ZB_MAC_RPMSG_REMOTE_ADDR,
    .imuLink     = (uint8_t)kIMU_LinkCpu1Cpu2,
    .callback    = &PLATFORM_ZbRpmsgRxCallback,
    .param       = (void *)PLATFORM_ZB_MAC_RPMSG_REMOTE_ADDR,
};

static RPMSG_HANDLE_DEFINE(zbPhyRpmsgHandle);
static const hal_rpmsg_config_t zbPhyRpmsgConfig = {
    .local_addr  = PLATFORM_ZB_PHY_RPMSG_LOCAL_ADDR,
    .remote_addr = PLATFORM_ZB_PHY_RPMSG_REMOTE_ADDR,
    .imuLink     = (uint8_t)kIMU_LinkCpu1Cpu2,
    .callback    = &PLATFORM_ZbRpmsgRxCallback,
    .param       = (void *)PLATFORM_ZB_PHY_RPMSG_REMOTE_ADDR,
};

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitZigbee(void)
{
    int ret = 0;

    /* NOT IMPLEMENTED */

    return ret;
}

int PLATFORM_InitZbMacInterface(platform_zb_rx_callback_t callback, void *param)
{
    int ret = 0;

    zbMacRxCallback    = callback;
    zbMacCallbackParam = param;

    do
    {
        /* Init RPMSG interface */
        if (PLATFORM_InitZbRpmsg((hal_rpmsg_handle_t)zbMacRpmsgHandle, zbMacRpmsgConfig) != 0)
        {
            ret = -1;
            break;
        }
    } while (false);

    if (ret != 0)
    {
        zbMacRxCallback    = NULL;
        zbMacCallbackParam = NULL;
    }

    return ret;
}

int PLATFORM_TerminateZbMacInterface(void)
{
    int ret = 0;

    /* NOT IMPLEMENTED */

    return ret;
}

int PLATFORM_ResetZbMacInterface(void)
{
    int ret = 0;

    /* NOT IMPLEMENTED */

    return ret;
}

int PLATFORM_SendZbMacMessage(uint8_t *msg, uint32_t len)
{
    return PLATFORM_SendZbMessage((hal_rpmsg_handle_t)zbMacRpmsgHandle, msg, len);
}

int PLATFORM_InitZbPhyInterface(platform_zb_rx_callback_t callback, void *param)
{
    int ret = 0;

    zbPhyRxCallback    = callback;
    zbPhyCallbackParam = param;

    do
    {
        /* Init RPMSG interface */
        if (PLATFORM_InitZbRpmsg((hal_rpmsg_handle_t)zbPhyRpmsgHandle, zbPhyRpmsgConfig) != 0)
        {
            ret = -1;
            break;
        }
    } while (false);

    if (ret != 0)
    {
        zbPhyRxCallback    = NULL;
        zbPhyCallbackParam = NULL;
    }

    return ret;
}

int PLATFORM_TerminateZbPhyInterface(void)
{
    /* NOT IMPLEMENTED */
    return 0;
}

int PLATFORM_ResetZbPhyInterface(void)
{
    /* NOT IMPLEMENTED */
    return 0;
}

int PLATFORM_SendZbPhyMessage(uint8_t *msg, uint32_t len)
{
    return PLATFORM_SendZbMessage((hal_rpmsg_handle_t)zbPhyRpmsgHandle, msg, len);
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

static int PLATFORM_InitZbRpmsg(hal_rpmsg_handle_t rpmsgHandle, hal_rpmsg_config_t rpmsgConfig)
{
    hal_rpmsg_status_t rpmsgStatus;
    int                ret = 0;

    do
    {
        /* Init RPMSG/IMU Channel */
        rpmsgStatus = HAL_RpmsgInit(rpmsgHandle, &rpmsgConfig);
        if (rpmsgStatus != kStatus_HAL_RpmsgSuccess)
        {
            ret = -1;
            break;
        }
    } while (false);

    return ret;
}

int PLATFORM_SendZbMessage(hal_rpmsg_handle_t rpmsgHandle, uint8_t *msg, uint32_t len)
{
    hal_rpmsg_status_t rpmsgStatus;
    int                ret = 0;

    PLATFORM_RemoteActiveReq();

    do
    {
        rpmsgStatus = HAL_RpmsgSend(rpmsgHandle, msg, len);
        if (rpmsgStatus != kStatus_HAL_RpmsgSuccess)
        {
            ret = -1;
            break;
        }
    } while (false);

    PLATFORM_RemoteActiveRel();

    return ret;
}

static hal_rpmsg_return_status_t PLATFORM_ZbRpmsgRxCallback(void *param, uint8_t *data, uint32_t len)
{
    uint32_t remoteAddr = (uint32_t)param;

    PLATFORM_RemoteActiveReq();

    if (remoteAddr == PLATFORM_ZB_MAC_RPMSG_REMOTE_ADDR)
    {
        /* this is a MAC message */
        if (zbMacRxCallback != NULL)
        {
            zbMacRxCallback(data, len, zbMacCallbackParam);
        }
    }
    else if (remoteAddr == PLATFORM_ZB_PHY_RPMSG_REMOTE_ADDR)
    {
        /* This is a PHY message */
        if (zbPhyRxCallback != NULL)
        {
            zbPhyRxCallback(data, len, zbPhyCallbackParam);
        }
    }
    else
    {
        /* this must not happen */
        assert(0);
        __NOP();
    }

    PLATFORM_RemoteActiveRel();

    return kStatus_HAL_RL_RELEASE;
}
