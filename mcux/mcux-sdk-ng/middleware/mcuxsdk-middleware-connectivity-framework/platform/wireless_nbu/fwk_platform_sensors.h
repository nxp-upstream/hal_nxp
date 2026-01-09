/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FWK_PLATFORM_SENSORS_H_
#define _FWK_PLATFORM_SENSORS_H_

/*!
 * @addtogroup FWK_Platform_module_CM3
 * @{
 */
/*!
 * @addtogroup FWK_Platform_CM3_Sensors
 * The FWK_Platform_Sensors module
 *
 * FWK_Platform_Sensors module provides APIs for temperature access on the CM3.
 *
 * @{
 */

#include "EmbeddedTypes.h"

/*!
 * Value used to indicated that temperature is unknown
 */
#define PLATFORM_SENSOR_UNKNOWN_TEMPERATURE ((int32_t)999999)

/************************************************************************************
*************************************************************************************
* API
*************************************************************************************
************************************************************************************/
/*!
 * @brief Get the last temperature value sent by the CM33 from RAM
 * Value returned may be set to PLATFORM_SENSOR_UNKNOWN_TEMPERATURE if no temperature is available.
 *
 * @param  [out] temperature_value       The temperature value is returned by reference in tenths of degree celsius
 */
void PLATFORM_GetTemperatureValue(int32_t *temperature_value);

/*!
 * @brief Save the temperature value sent by the CM33 in RAM
 *
 * @param  [in] l_temperature_value     Array in which the temperature is sent by the CM33
 */
void PLATFORM_SaveTemperatureValue(int32_t l_temperature_value);

/*!
 * @}  end of FWK_Platform_CM3_Sensors addtogroup
 */
/*!
 * @}  end of FWK_Platform_module_CM3 addtogroup
 */

#endif /* _FWK_PLATFORM_SENSORS_H_ */