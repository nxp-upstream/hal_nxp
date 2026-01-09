/*!
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _PLATFORM_DCDC_H_
#define _PLATFORM_DCDC_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "EmbeddedTypes.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

/*!
 * \brief  Configure High power mode voltage located in RF_CMC depending the Tx power in Dbm and if the application core is allowing it.
 *
 * \param[in] power_dBm  Tx power of the radio in Dbm
 *
 */
void PLATFORM_ConfigureSpcHighPowerMode(uint8_t power_dBm);

/*!
 * \brief  Enable/disable High power mode mode
 *
 * \param[in] enable boolean
 * true  : enable high power mode
 * false : disable high power mode
 *
 */
void PLATFORM_EnableSpcHighPowerMode(bool enable);

#ifdef __cplusplus
}
#endif

#endif /* _PLATFORM_DCDC_H_ */
