/* -------------------------------------------------------------------------- */
/*                           Copyright 2020-2025 NXP                          */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_SFC_H_
#define _FWK_SFC_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>

/* -------------------------------------------------------------------------- */
/*                                Public types                                */
/* -------------------------------------------------------------------------- */

/*!
 * \struct sfc_config_t
 * \brief SFC configuration structure passed in SFC_Init or SFC_UpdateConfig
 * \var sfc_config_t::filterSize
 * Defines number of samples used in the filter
 * Note: it will be converted to power of two to allow for bit-shift operations
 * \var sfc_config_t::ppmTarget
 * Defines the ppm target
 * \var sfc_config_t::maxCalibrationIntervalMs
 * Defines the maximum time between 2 calibration in msec.
 * \var sfc_config_t::trigSampleNumber
 * Number of samples required in the filter to swicth from convergence to monitor mode.
 */
typedef struct
{
    uint32_t filterSize;
    uint32_t ppmTarget;
    uint32_t maxCalibrationIntervalMs;
    uint32_t trigSampleNumber;
} sfc_config_t;

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Configures SFC and runs a calibration
 *
 */
void SFC_Init(void);

/*!
 * \brief Enables/Disables SFC calibrations
 *
 * \param[in] enable
 */
void SFC_Enable(bool enable);

/*!
 * \brief Processes available measurement results
 *        Measurement results are not processed in the SFA IRQ to not spend too much time in the IRQ handler
 *        This function can be called from low priority tasks such as Idle task
 *
 */
void SFC_Process(void);

/*!
 * \brief Indicates if SFC module is busy, can be used by low power policy manager to cancel low power entry
 *
 * \return true Calibration is ongoing
 * \return false SFC is idling
 */
bool SFC_IsBusy(void);

/*!
 * \brief Updates the SFC config with the config passed by the user
 *        Allows to change the ppm target and the filter period
 *        Note: if the filter period is changed, the filter is reset
 *
 * \param[in] config
 */
void SFC_UpdateConfig(const sfc_config_t *config);

/*!
 * \brief Enanbles/Disables SFC notification by messages send to the host core.
 * \details It will send the frequency mesured, the mean ppm, and the instant values of ppm
 *
 * \param[in] enable
 */
void SFC_EnableNotification(int enable);

/*!
 * \brief Indicates if SFC module has an available measurement to process
 *
 * \return true measurement is available
 * \return false measure not started or a calibration is ongoing
 */
bool SFC_IsMeasureAvailable(void);

#endif /* _FWK_SFC_H_ */
