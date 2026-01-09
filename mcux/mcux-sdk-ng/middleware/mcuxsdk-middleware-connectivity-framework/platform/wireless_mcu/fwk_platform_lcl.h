/*!
 * Copyright 2021,2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _PLATFORM_LCL_H_
#define _PLATFORM_LCL_H_

#include "EmbeddedTypes.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* RF_GPO group for IO pins to control antenna diversity RF switch */
#define LCL_RFGPO_NONE 0U /* no RF switch    */
#define LCL_RFGPO_3_0  1U /* use RF_GPO[3:0] */
#define LCL_RFGPO_7_4  2U /* use RF_GPO[7:4] */

#if !defined(NDEBUG) || (defined(gValidationBuildOptions) && (gValidationBuildOptions == 1))
#define ENABLE_DTEST
#endif
/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * \brief Setup debug GPIOs and antenna switching IOs for BLE localization apps
 * \param[in]  none
 *
 * \return 0/1 which is Success/Failure correspondingly
 ********************************************************************************** */
uint8_t PLATFORM_InitLcl(void);

/*!
 * \brief Setup RF_GPO group (antenna switching IOs) for BLE localization apps
 * \param[in]  rfgpo_id    ID to LCL antenna configuration
 *                         LCL_RFGPO_NONE - no RF_GPO used
 *                         LCL_RFGPO_3_0  - PTA18, PTA19, PTA20 (KW45-LOC)
 *                         LCL_RFGPO_7_4  - PTD1, PTD2, PTD3 (KW47-LOC)
 *
 * \return 0/1 which is Success/Failure correspondingly
 ********************************************************************************** */
uint8_t PLATFORM_InitLclRfGpo(uint8_t rfgpo_id);

/*!
 * \brief Setup debug GPIOs for BLE localization apps
 * \param[in]  debug       False to requisite PORTD2 for antenna switch, True to restore
 *
 * \return None
 ********************************************************************************** */
void PLATFORM_InitLclGpioDebug(bool_t debug);

/*! *********************************************************************************
 * \brief  Configure COEX control
 * \param[in]  p_config     pointer to COEX configuration
 * \param[in]  config_len   length of configuration, for checking
 *
 * \return 0/1 which is Success/Failure correspondingly
 * \remarks Must be called after NBU initiation since it relies on common RF parameters.
 ********************************************************************************** */
uint8_t PLATFORM_InitCOEX(const uint8_t *p_config, uint8_t config_len);

/*! *********************************************************************************
 * \brief  Configure FEM control
 * \param[in]  config_ptr   pointer to FEM configuration
 *
 * \return 0/1 which is Success/Failure correspondingly
 * \remarks Must be called after NBU initiation since it relies on common RF parameters.
 ********************************************************************************** */
uint8_t PLATFORM_InitFEM(const uint8_t *p_config, uint8_t config_len);

#endif /* _PLATFORM_LCL_H_ */
