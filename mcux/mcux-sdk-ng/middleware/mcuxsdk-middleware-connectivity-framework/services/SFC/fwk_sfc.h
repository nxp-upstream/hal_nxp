/* -------------------------------------------------------------------------- */
/*                        Copyright 2020-2023, 2025 NXP                       */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_SFC_H_
#define _FWK_SFC_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>

/* -------------------------------------------------------------------------- */
/*                       RF SFC Default parametrization                       */
/* -------------------------------------------------------------------------- */

#define RF_SFC_MAXIMAL_PPM_TARGET  360U
#define RF_SFC_MINIMAL_FILTER_SIZE 1U
#define RF_SFC_MAXIMAL_FILTER_SIZE 256U

#define RF_SFC_DEFAULT_PPM_TARGET              RF_SFC_MAXIMAL_PPM_TARGET
#define RF_SFC_DEFAULT_FILTER_SIZE             128U
#define RF_SFC_DEFAULT_CALIBRATION_INTERVAL_MS 1000U

/* Number of sample that should be in the filter before switching to monitor mode. Doing multiple measurements allow us
 * to build confidence in the calibration we have done */
#define RF_SFC_DEFAULT_TRIG_SAMPLE_NUMBER 3U

/* -------------------------------------------------------------------------- */
/*                                Public types                                */
/* -------------------------------------------------------------------------- */

/*!
 * \struct sfc_config_t
 * \brief SFC configuration structure passed to PLATFORM_FwkSrvSetRfSfcConfig
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

/*!
 * \struct sfc_log_t
 * \brief SFC log structure stored in shared memory at 0x489C0078 (see m_sfc_log_start linker symbol)
 * \var sfc_log_t::lastFreqMeasured
 * Last frequency measurement result
 * \var sfc_log_t::averagePpm
 * Current averaged ppm value (output of the filter)
 */
typedef struct
{
    uint16_t lastFreqMeasured;
    int16_t  averagePpm;
} sfc_log_t;

#endif /* _FWK_SFC_H_ */
