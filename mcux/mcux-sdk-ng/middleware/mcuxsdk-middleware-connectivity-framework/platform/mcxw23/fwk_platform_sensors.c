/* -------------------------------------------------------------------------- */
/*                           Copyright 2025 NXP                               */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fsl_common.h"
#include "fwk_platform_sensors.h"

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

bool PLATFORM_IsAdcInitialized(void)
{
    /* Not implemented because no ADC available on MCXW23 */
    return true;
}

void PLATFORM_InitAdc(void)
{
    /* Not implemented because no ADC available on MCXW23 */
}

void PLATFORM_DeinitAdc(void)
{
    /* Not implemented because no ADC available on MCXW23 */
}

void PLATFORM_ReinitAdc(void)
{
    /* Not implemented because no ADC available on MCXW23 */
}

void PLATFORM_StartBatteryMonitor(void)
{
    /* Not implemented because no ADC available on MCXW23 */
}

void PLATFORM_GetBatteryLevel(uint8_t *battery_level)
{
    *battery_level = PLATFORM_SENSOR_UNKNOWN_BATTERY_LVL;
}

void PLATFORM_StartTemperatureMonitor(void)
{
    /* Not implemented because no ADC available on MCXW23 */
}

void PLATFORM_GetTemperatureValue(int32_t *temperature_value)
{
    *temperature_value = (int32_t)PLATFORM_SENSOR_UNKNOWN_TEMPERATURE;
}

void PLATFORM_RegisterTemperatureReadyEventCb(temp_ready_event_callback_t cb)
{
    /* Not implemented because no ADC available on MCXW23 */
    (void)cb;
}
