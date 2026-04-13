/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2023 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>
#ifdef __ZEPHYR__
#include <zephyr/drivers/flash.h>
#include <zephyr/random/random.h>

#define IFR0_FLASH_NODE      DT_CHOSEN(zephyr_flash_controller)
#define IFR0_FLASH_BASE      DT_REG_ADDR(DT_NODELABEL(ifr0))
#endif

#include "fwk_platform_ot.h"
#include "fwk_platform_coex.h"
#include "fwk_platform_ble.h"
#include "fwk_platform_hdlc.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                Private types                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static bool initialized = false;

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

#ifdef __ZEPHYR__
static const struct device *get_ifr0_flash_device(void);
#endif


/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitOt(void)
{
    int ret = 0;

    do
    {
        if (initialized == true)
        {
            break;
        }

        /* Initialize the 802.15.4 controller */
        if (PLATFORM_InitControllers(conn802_15_4_c) != 0)
        {
            ret = -1;
            break;
        }

        /* Initialize the BLE Controller as it is part of the same combo firmware */
        if (PLATFORM_InitBle() != 0)
        {
            ret = -2;
            break;
        }

        /* Setup HCI link and make sure it is ready
         * Used for low power control of the BLE/15.4 firmware */
        if (PLATFORM_StartHci() != 0)
        {
            ret = -3;
            break;
        }

        initialized = true;
    } while (false);

    return ret;
}

int PLATFORM_TerminateOt(void)
{
    int ret = 0;

    do
    {
        if (PLATFORM_TerminateHdlcInterface() != 0)
        {
            ret = -1;
            break;
        }

        if (PLATFORM_TerminateBle() != 0)
        {
            ret = -2;
            break;
        }

    } while (false);

    return ret;
}

int PLATFORM_ResetOt(void)
{
    int ret = 0;

    initialized = false;

    do
    {
        if (PLATFORM_TerminateOt() != 0)
        {
            ret = -1;
            break;
        }

        if (PLATFORM_InitOt() != 0)
        {
            ret = -2;
            break;
        }

        if (PLATFORM_ResetHdlcInterface() != 0)
        {
            ret = -3;
            break;
        }

    } while (false);

    return ret;
}

#ifdef __ZEPHYR__
int PLATFORM_GetZbossFactorySettings(PLATFORM_zboss_factory_settings_t *settings_buf)
{
    const struct device *flash_dev;
    int rc;

    flash_dev = get_ifr0_flash_device();
    if (flash_dev == NULL) {
        return -ENODEV;
    }

    rc = flash_read(flash_dev, IFR0_FLASH_BASE + IFR_USER_ADDR, settings_buf, sizeof(PLATFORM_zboss_factory_settings_t));
    if (rc != 0) {
        return -EIO;
    }

    return sizeof(PLATFORM_zboss_factory_settings_t);
}
#endif

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

#ifdef __ZEPHYR__
/**
 * @brief Get the IFR0 flash device
 *
 * @return Pointer to flash device, or NULL if not ready
 */
static const struct device *get_ifr0_flash_device(void)
{
    const struct device *flash_dev = DEVICE_DT_GET(IFR0_FLASH_NODE);

    if (!device_is_ready(flash_dev)) {
        return NULL;
    }

    return flash_dev;
}

#endif
