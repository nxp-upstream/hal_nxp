/*!
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fwk_platform_sensors.h"
#include "fwk_debug.h"

/************************************************************************************
 * Private memory declarations
 ************************************************************************************/

static int32_t last_temperature_value = PLATFORM_SENSOR_UNKNOWN_TEMPERATURE; /* value in tenths of degree Celsius */

/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/

void PLATFORM_GetTemperatureValue(int32_t *temperature_value)
{
    *temperature_value = last_temperature_value;
}

void PLATFORM_SaveTemperatureValue(int32_t l_temperature_value)
{
    PWR_DBG_LOG("temperature received:%d", l_temperature_value);
    last_temperature_value = l_temperature_value;
}