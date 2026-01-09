/*!
 * Copyright 2021-2024 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * \file fwk_platform_sensors.c
 * \brief PLATFORM abstraction for Sensors service
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>

#include "fsl_device_registers.h"
#include "fwk_platform_sensors.h"

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

volatile bool initialized = false;

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

bool PLATFORM_IsAdcInitialized(void)
{
    return initialized;
}

void PLATFORM_InitAdc(void)
{
    if (initialized == false)
    {
        SENSOR_CTRL->MISC_CTRL_REG |= SENSOR_CTRL_MISC_CTRL_REG_TIMER_1_ENABLE_MASK;
        initialized = true;
    }
}

void PLATFORM_DeinitAdc(void)
{
    SENSOR_CTRL->MISC_CTRL_REG &= ~SENSOR_CTRL_MISC_CTRL_REG_TIMER_1_ENABLE_MASK;
    initialized = false;
}

void PLATFORM_StartBatteryMonitor(void)
{
    ;
}

void PLATFORM_GetBatteryLevel(uint8_t *battery_level)
{
    *battery_level = 100U;
}

void PLATFORM_StartTemperatureMonitor(void)
{
    ;
}

void PLATFORM_GetTemperatureValue(int32_t *temperature_value)
{
    uint32_t temperature = 0U;

    temperature = (((SENSOR_CTRL->TSEN_CTRL_1_REG_2) & SENSOR_CTRL_TSEN_CTRL_1_REG_2_TSEN_TEMP_VALUE_MASK) >>
                   SENSOR_CTRL_TSEN_CTRL_1_REG_2_TSEN_TEMP_VALUE_SHIFT);

    /* (temperature * 0.480561F - 220.7074F) */
    *temperature_value = (int32_t)((temperature * 481U) / 1000U - 221U);
}
