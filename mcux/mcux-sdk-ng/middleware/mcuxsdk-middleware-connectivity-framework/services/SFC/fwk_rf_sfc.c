/* -------------------------------------------------------------------------- */
/*                        Copyright 2020-2023, 2025 NXP                       */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include <stdlib.h>

#include "fwk_config.h"
#include "fsl_common.h"
#include "fwk_platform.h"
#include "fwk_platform_ics.h"
#include "fwk_rf_sfc.h"
#include "fsl_sfa.h"
#include "fsl_ccm32k.h"
#include "fwk_debug.h"
#include "fwk_hal_macros.h"
#include "fwk_debug.h"
#include "ll_types.h"
#include "controller_api_ll.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#define RF_SFA_IRQ_PRIORITY      4
#define HOST_LOWPOWER_CONSTRAINT 2U

#ifndef RF_SFC_MAXIMAL_PPM_TARGET
#define RF_SFC_MAXIMAL_PPM_TARGET 360U
#endif

#define RF_SFC_MINIMAL_FILTER_SIZE 1U
#define RF_SFC_MAXIMAL_FILTER_SIZE 256U

#define RF_SFC_DEFAULT_PPM_TARGET              RF_SFC_MAXIMAL_PPM_TARGET
#define RF_SFC_DEFAULT_FILTER_SIZE             128U
#define RF_SFC_DEFAULT_CALIBRATION_INTERVAL_MS 1000U

/* Number of sample that should be in the filter before switching to monitor mode. Doing multiple measurements allow us
 * to build confidence in the calibration we have done */
#define RF_SFC_DEFAULT_TRIG_SAMPLE_NUMBER 3U

/* -------------------------------------------------------------------------- */
/*                          Private type definitions                          */
/* -------------------------------------------------------------------------- */

typedef struct
{
    uint32_t sampleNumber;
    int32_t  sum;
    uint32_t shift;
} sfc_filter_state_t;

typedef struct
{
    uint32_t           freq;
    uint32_t           fro_trim;
    uint32_t           lastCalibrationTimestamp;
    int32_t            ppm;
    int32_t            hostLpConstraintCount;
    uint16_t           lastFreq;
    int16_t            lastPpm;
    bool               ppmTargetReached;
    bool               enable;
    bool               measureAvailable;
    bool               osc32kUsed;
    bool               osc32kSwitchPending;
    sfc_filter_state_t filterState;
} sfc_handle_t;

typedef struct
{
    uint16_t lastFreqMeasured;
    int16_t  averagePpm;
} sfc_log_t;

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

static void     SFC_HandleHostLowPowerConstraint(bool setConstraint);
static void     SFC_StartCalibration(void);
static void     SFC_MeasureFreqBlocking(void);
static void     SFC_Calibrate(void);
static void     SFC_MeasureCallback(status_t status);
static int32_t  SFC_ComputeMMA(int32_t sample);
static void     SFC_ResetFilterState(void);
static uint32_t SFC_GetTimestamp(void);

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

/*!
 * \brief SFA measure configuration used to measure FRO32K clock compared to
 *        32MHz clock. This configuration uses the RF_SFA trigger input from RFMC.
 *        This means the RF_SFA will start a measurement on next wake up from low power.
 *        The measurement period is 2ms, which roughly corresponds to an empty BLE connection
 *        event, this has been choosen to minimize impact of consumption while the NBU is
 *        performing radio event.
 *        This period of 1ms is pretty tight, meaning it will be noisy, so the Moving Average shall
 *        be configured with enough sample to smoothen the noise (\ref RF_SFC_DEFAULT_FILTER_SIZE samples is
 * recommended). This measurement configuration is not used directly on cold boot, because after a cold boot, the FRO
 * frequency will not be precise at all, so we need to perform a lot of measurement with less noise, until we reach an
 * appropriate precision. This will be done with the measureConfigurationImmediate configuration. This configuration is
 * meant to be used when the ppm target has been reached and we can go in a "monitor" mode, meaning it will be used to
 * regularly check if the frequency drifts out of the target. Note: The REF target must take into account that the CUT
 * can take up to 2 periods of sync before starting counting so it must be larger than expected otherwise it could reach
 * its target before the CUT, leading to a timeout
 */
#if (!defined(gNbuDisableLowpower_d) || (gNbuDisableLowpower_d == 0))
static const sfa_config_t measureConfigurationTrig = {
    .mode                  = kSFA_FrequencyMeasurement0,
    .cutSelect             = kSFA_CUTSelect0, // 32K_CLK
    .refSelect             = kSFA_REFSelect0, // OSC_RF
    .prediv                = 0U,
    .trigStart             = kSFA_TriggerStartSelect0,
    .startPolarity         = kSFA_TriggerStartPolarityRiseEdge,
    .trigEnd               = kSFA_TriggerEndSelect0,
    .endPolarity           = kSFA_TriggerEndPolarityRiseEdge,
    .enableTrigMeasurement = true,
    .enableCUTPin          = false,
    .cutTarget             = 64U,    // ~1.95ms @ 32768Hz
    .refTarget             = 68000U, // ~2.12ms @ 32MHz
};
#endif                               /* gNbuDisableLowpower_d */

/*!
 * \brief SFA measure configuration used to measure FRO32K clock compared to
 *        32MHz clock. This configuration doesn't use the trigger mechanism from the RFMC
 *        which means the RF_SFA measurement will not wait for the trigger to start.
 *        The measurement period is smaller (0.5 ms), which allows for convergence time reduction.
 *        This configuration is meant to be used at cold boot because the clock will likely be out of the ppm target.
 *        Also, this will be used when the frequency goes out of the ppm target and this until the precision goes
 *        back to the window.
 *        Note: The REF target must take into account that the CUT can take up to 2 periods of sync before starting
 *        counting so it must be larger than expected otherwise it could reach its target before the CUT, leading to
 *        a timeout
 *
 */
static const sfa_config_t measureConfigurationImmediate = {
    .mode                  = kSFA_FrequencyMeasurement0,
    .cutSelect             = kSFA_CUTSelect0, // 32K_CLK
    .refSelect             = kSFA_REFSelect0, // OSC_RF
    .prediv                = 0U,
    .trigStart             = kSFA_TriggerStartSelect0,
    .startPolarity         = kSFA_TriggerStartPolarityRiseEdge,
    .trigEnd               = kSFA_TriggerEndSelect0,
    .endPolarity           = kSFA_TriggerEndPolarityRiseEdge,
    .enableTrigMeasurement = false,
    .enableCUTPin          = false,
    .cutTarget             = 16U,    // ~0.49ms @ 32768Hz
    .refTarget             = 20000U, // 0.62ms @ 32MHz
};

/* Config passed by the user during init */
static volatile sfc_config_t sfcConfig = {
    .filterSize               = RF_SFC_DEFAULT_FILTER_SIZE,
    .ppmTarget                = RF_SFC_DEFAULT_PPM_TARGET,
    .maxCalibrationIntervalMs = RF_SFC_DEFAULT_CALIBRATION_INTERVAL_MS,
    .trigSampleNumber         = RF_SFC_DEFAULT_TRIG_SAMPLE_NUMBER,
};

/*!
 * \brief Structure describing current fro32k calibration state
 *
 */
static volatile sfc_handle_t sfcHandle = {
    .freq                     = 0U,
    .fro_trim                 = 0U,
    .lastCalibrationTimestamp = 0U,
    .ppm                      = 0,
    .hostLpConstraintCount    = 0,
    .lastFreq                 = 0U,
    .lastPpm                  = 0,
    .ppmTargetReached         = false,
    .enable                   = false,
    .measureAvailable         = false,
    .osc32kUsed               = false,
    .osc32kSwitchPending      = false,
    .filterState =
        {
            .sampleNumber = 0U,
            .sum          = 0,
            .shift        = 0U,
        },
};

extern uint32_t            m_sfc_log_start[];
static volatile sfc_log_t *sfcLog = (volatile sfc_log_t *)m_sfc_log_start;

static int sfcNotificationEnabled = 0;
/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

void SFC_Init(void)
{
    ccm32k_clock_source_t currentClockSource;
    ccm32k_state_t        currentState;

    /* Init SFA for frequency measurement */
    SFA_Init(RF_SFA);
    SFA_InstallCallback(RF_SFA, SFC_MeasureCallback);
    NVIC_ClearPendingIRQ(RF_SFA_IRQn);
    NVIC_EnableIRQ(RF_SFA_IRQn);
    NVIC_SetPriority(RF_SFA_IRQn, RF_SFA_IRQ_PRIORITY);

    /* Enable SFC calibration */
    SFC_Enable(true);

    /* Initialize the filter shift based on the default filter size */
    sfcHandle.filterState.shift = HAL_GETPOWEROF2SHIFT(sfcConfig.filterSize);

    PLATFORM_RemoteActiveReq();

    /* Retrieve current FRO32K trim value */
    sfcHandle.fro_trim = CCM32K_Get32kFroTrimValue(CCM32K);
    currentState       = CCM32K_GetCurrentState(CCM32K);
    currentClockSource = CCM32K_GetClockSource(CCM32K);

    PLATFORM_RemoteActiveRel();

    if ((currentState & kCCM32K_Only32kOscEnabled) != 0U)
    {
        /* If the osc32k is enabled, it means the application core wants to use this clock source as soon as it is ready
         * So here, to avoid accessing CCM32K later on (and impact power consumption by waking up host core), we tag
         * this information
         * SFC_Process will poll the RDY status of the osc32k and switch to it as clock source when it is */
        sfcHandle.osc32kSwitchPending = true;
    }

    if (currentClockSource != kCCM32K_ClockSource32kFro)
    {
        /* Check if the current 32k clock source is the fro32k, is yes the measurement can be started
         * otherwise the SFC can be disabled */
        SFC_Enable(false);
    }
    else
    {
        /* Perform a first blocking calibration to make sure the fro32k is within the target ppm before performing
         * any RF activity */
        do
        {
            SFC_MeasureFreqBlocking();
            SFC_Calibrate();
        } while (abs(sfcHandle.ppm) > sfcConfig.ppmTarget);
    }

    SFC_DBG_LOG("SFC Init: osc32kPending=%d curSrc=%d ppm=%d", sfcHandle.osc32kSwitchPending, currentClockSource,
                sfcHandle.ppm);
}

void SFC_Enable(bool enable)
{
    if (enable == true)
    {
        if (sfcHandle.enable == false)
        {
            /* Set host low power constraint as the calibration is restarted */
            SFC_HandleHostLowPowerConstraint(true);

            /* Start calibration */
            sfcHandle.enable = true;
            SFC_StartCalibration();
        }
    }
    else
    {
        if (sfcHandle.enable == true)
        {
            /* Release low power constraint to the host core */
            SFC_HandleHostLowPowerConstraint(false);
            /* If the SFC module is disabled, we need to clear the measure available flag */
            sfcHandle.measureAvailable = false;
            sfcHandle.enable           = false;
        }

        if (SFC_IsBusy() == true)
        {
            SFA_AbortMeasureSequence(RF_SFA);
        }
    }
}

void SFC_Process(void)
{
    uint64_t lastCalibrationTimestampDiffInQuarterUs;
    uint32_t currentTimestamp;

    /* Check the time before next BLE LL event
     * If it returns 0xFFFFFFFFU, it means the LL has nothing to do, meaning no radio event is scheduled
     * We can allow the host core to go to power gated modes */
    if (LL_API_SCHED_GetSleepTime() == 0xFFFFFFFFU)
    {
        SFC_Enable(false);
    }
    else if (sfcHandle.osc32kUsed == false)
    {
        SFC_Enable(true);
        if (sfcHandle.measureAvailable == true)
        {
            if (sfcNotificationEnabled != 0)
            {
                PLATFORM_FwkSrvFroInfo(sfcHandle.lastFreq, sfcHandle.ppm, sfcHandle.lastPpm,
                                       (uint16_t)sfcHandle.fro_trim);
            }
            SFC_DBG_LOG("SFC MeasAvail: lastFreq=%d sfcHandle.ppm=%d sfcHandle.lastPpm=%d", sfcHandle.lastFreq,
                        sfcHandle.ppm, sfcHandle.lastPpm);
            SFC_Calibrate();

            /* Reset the measureAvailable flag */
            sfcHandle.measureAvailable = false;

            /* Restart a calibration (either direct measure or trigger based measure) */
            SFC_StartCalibration();
        }
        else if (!SFC_IsBusy())
        {
            currentTimestamp = SFC_GetTimestamp();

            if (sfcHandle.lastCalibrationTimestamp < currentTimestamp)
            {
                lastCalibrationTimestampDiffInQuarterUs =
                    (uint64_t)currentTimestamp - (uint64_t)sfcHandle.lastCalibrationTimestamp;
            }
            else
            {
                /* Handle wrapping */
                lastCalibrationTimestampDiffInQuarterUs = (uint64_t)UINT32_MAX + (uint64_t)currentTimestamp -
                                                          (uint64_t)sfcHandle.lastCalibrationTimestamp + 1ULL;
            }

            if ((lastCalibrationTimestampDiffInQuarterUs) > ((uint64_t)(sfcConfig.maxCalibrationIntervalMs) * 4000ULL))
            {
                SFC_DBG_LOG("SFC TimeOverdue, Resetfilter %d>%d", (uint32_t)lastCalibrationTimestampDiffInQuarterUs,
                            (uint32_t)((uint64_t)(sfcConfig.maxCalibrationIntervalMs) * 4000ULL));

                /* As it's been a long time since last calibration, there's a risk the FRO frequency drifted a lot
                 * If that's the case, it could take time to detect the drift due to the delay introduced by the filter
                 * So, we reset the filter before performing a forced calibration to be able to react quickly */
                SFC_ResetFilterState();

                /* Start a calibration, it will use an immediate measure as the filter has been reset */
                SFC_StartCalibration();
            }
        }
        else
        {
            ; /* For MISRA compliancy */
        }
    }

    if (sfcHandle.osc32kSwitchPending == true)
    {
        PLATFORM_RemoteActiveReq();

        if ((CCM32K_GetStatusFlag(CCM32K) & (uint32_t)kCCM32K_32kOscReadyStatusFlag) != 0U)
        {
            /* Select osc32k as clock source and disable fro32k */
            CCM32K_SelectClockSource(CCM32K, kCCM32K_ClockSourceSelectOsc32k);
            CCM32K_Enable32kFro(CCM32K, false);
            sfcHandle.osc32kSwitchPending = false;
            sfcHandle.osc32kUsed          = true;

            /* Disable SFC calibration, it is not needed when using osc32k as a clock source */
            SFC_Enable(false);

            /* Disable SFA IRQ and deinit SFA driver to avoid having any pending SFA activity later on*/
            NVIC_DisableIRQ(RF_SFA_IRQn);
            SFA_Deinit(RF_SFA);

            SFC_DBG_LOG("SFC Switch to Osc32k");
        }

        PLATFORM_RemoteActiveRel();
    }
}

bool SFC_IsBusy(void)
{
    bool     ret   = false;
    uint32_t state = SFA_GetStatusFlags(RF_SFA);

    if (state & SFA_CNT_STAT_MEAS_STARTED_MASK)
    {
        ret = true;
    }

    return ret;
}

void SFC_UpdateConfig(const sfc_config_t *config)
{
    uint32_t ppmTarget                = config->ppmTarget;
    uint32_t filterSize               = config->filterSize;
    uint32_t maxCalibrationIntervalMs = config->maxCalibrationIntervalMs;
    uint32_t trigSampleNumber         = config->trigSampleNumber;

    uint32_t irqMask = DisableGlobalIRQ();

    assert(config != NULL);

    if ((ppmTarget != sfcConfig.ppmTarget) && (ppmTarget != 0U))
    {
        if (ppmTarget <= RF_SFC_MAXIMAL_PPM_TARGET)
        {
            /* Make sure to not configure a ppm target we cannot achieve */
            ppmTarget = RF_SFC_MAXIMAL_PPM_TARGET;
        }
        /* Register the new ppm target */
        sfcConfig.ppmTarget = ppmTarget;
    }

    if ((filterSize != sfcConfig.filterSize) && (filterSize != 0U))
    {
        if (filterSize < RF_SFC_MINIMAL_FILTER_SIZE)
        {
            /* Make sure the filter is big enough */
            filterSize = RF_SFC_MINIMAL_FILTER_SIZE;
        }
        else if (filterSize > RF_SFC_MAXIMAL_FILTER_SIZE)
        {
            /* Make sure the filter size is not higher than the maximum allowed */
            filterSize = RF_SFC_MAXIMAL_FILTER_SIZE;
        }

        /* Update the filter properties and reset it */
        sfcConfig.filterSize        = filterSize;
        sfcHandle.filterState.shift = HAL_GETPOWEROF2SHIFT(sfcConfig.filterSize);
        SFC_ResetFilterState();
    }

    if ((maxCalibrationIntervalMs != sfcConfig.maxCalibrationIntervalMs) && (maxCalibrationIntervalMs != 0U))
    {
        /* Register the new max interval between 2 calibration */
        sfcConfig.maxCalibrationIntervalMs = maxCalibrationIntervalMs;
    }

    if ((trigSampleNumber != sfcConfig.trigSampleNumber) && trigSampleNumber != 0U)
    {
        if (trigSampleNumber >= sfcConfig.filterSize)
        {
            /* Ensure we are at least using monitor mode on the last sample when the filter is full  */
            sfcConfig.trigSampleNumber = sfcConfig.filterSize;
        }
        else
        {
            /* Register the new number of samples required in the filter to go to monitor mode */
            sfcConfig.trigSampleNumber = trigSampleNumber;
        }
    }

    EnableGlobalIRQ(irqMask);
}

void SFC_EnableNotification(int enable)
{
    sfcNotificationEnabled = enable;
}

bool SFC_IsMeasureAvailable(void)
{
    return sfcHandle.measureAvailable;
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

static void SFC_HandleHostLowPowerConstraint(bool setConstraint)
{
    if (setConstraint == true)
    {
        sfcHandle.hostLpConstraintCount++;

        if (sfcHandle.hostLpConstraintCount == 1)
        {
            (void)PLATFORM_FwkSrvSetLowPowerConstraint(HOST_LOWPOWER_CONSTRAINT);
        }
    }
    else
    {
        sfcHandle.hostLpConstraintCount--;

        if (sfcHandle.hostLpConstraintCount == 0)
        {
            (void)PLATFORM_FwkSrvReleaseLowPowerConstraint(HOST_LOWPOWER_CONSTRAINT);
        }
    }
}

static void SFC_MeasureFreqBlocking(void)
{
    uint32_t freq = 0U;
    int32_t  ppm  = 0;

    SFA_SetMeasureConfig(RF_SFA, &measureConfigurationImmediate);
    SFA_MeasureBlocking(RF_SFA);

    freq          = SFA_CalculateFrequencyOrPeriod(RF_SFA, 32000000U);
    int64_t tmp64 = ((int64_t)32768 - (int64_t)freq) * 1000000;
    ppm           = tmp64 / 32768;

    sfcHandle.freq = freq;
    sfcHandle.ppm  = ppm;
}

/*!
 * \brief Starts a non blocking frequency measure of the FRO32K
 *
 */
static void SFC_StartCalibration(void)
{
    uint32_t intMask;

    SFC_DBG_LOG("SFC StartCalib: fro_trim=%d force=%d ENA=%d", sfcHandle.fro_trim, force = % d, sfcHandle.enable);

    if (sfcHandle.enable == true)
    {
#if (!defined(gNbuDisableLowpower_d) || (gNbuDisableLowpower_d == 0))
        if (sfcHandle.ppmTargetReached == true)
        {
            if (((RF_CMC1->RADIO_LP & RF_CMC1_RADIO_LP_BLE_WKUP_MASK) == 0U) &&
                (sfcHandle.filterState.sampleNumber >= sfcConfig.trigSampleNumber))
            {
                /* When the current precision is within the ppm target, we use the trigger based configuration to
                 * monitor the clock at each wake up from low power if the NBU is allowed to enter low power
                 * If at some point the clock goes out of the ppm target again, the SFC will switch to the NoTrig config
                 */
                SFA_SetMeasureConfig(RF_SFA, &measureConfigurationTrig);
            }
            else
            {
                /* Low power is not allowed by the host, so we use the immediate measurement config as the trigger
                 * is based on low power wake up signal */
                SFA_SetMeasureConfig(RF_SFA, &measureConfigurationImmediate);
            }
        }
        else
#endif /* gNbuDisableLowpower_d */
        {
            /* Until the frequency is not within the ppm target, we use the direct measurement configuration
             * The SFC will measure and calibration the FRO consecutively until the ppm target is reached
             * SFC_IsBusy will likely return true until then as the measurements are started one after the other */
            SFA_SetMeasureConfig(RF_SFA, &measureConfigurationImmediate);
        }

        SFA_ClearStatusFlag(RF_SFA, SFA_GetStatusFlags(RF_SFA));

        /* Call SFA_MeasureNonBlocking() under critical section to avoid the completion of a measure during the setup of
         * a new measurement */
        intMask = PLATFORM_SET_INTERRUPT_MASK();
        SFA_MeasureNonBlocking(RF_SFA);
        PLATFORM_CLEAR_INTERRUPT_MASK(intMask);
    }
}

/*!
 * \brief Performs FRO32K calibration. Checks the last measured frequency error
 *         in ppm and adjust the FRO32K trim value accordingly
 *
 */
static void SFC_Calibrate(void)
{
    uint32_t irqMask;
    uint32_t rf2p4ghz_timer;

    /* Get a timestamp each time a calibration is performed
     * this allows the module to know the last time the calibration was performed and decide to force a calibration
     * process if too much time elapsed since the last calibration */
    sfcHandle.lastCalibrationTimestamp = SFC_GetTimestamp();

    /* Check if the FRO needs to be trimmed according to ppm target */
    if (abs(sfcHandle.ppm) > sfcConfig.ppmTarget)
    {
        if (sfcHandle.ppmTargetReached == true)
        {
            /* The current ppm is out of the ppm target
             * Doing so will make the SFC to start consecutive measurement and calibration so the clock can reach the
             * target quickly During this time, the SFC_IsBusy function will return true, so low power can be avoided
             * until the clock is correctly calibrated */
            sfcHandle.ppmTargetReached = false;
        }

        /* Access to RFMC and CCM32K require the XBAR bus to be awake */
        PLATFORM_RemoteActiveReq();

        if (CCM32K_GetClockSource(CCM32K) == kCCM32K_ClockSource32kFro)
        {
            /* Check ppm direction and change trimming value accordingly */
            if (sfcHandle.ppm > 0)
            {
                sfcHandle.fro_trim--;
            }
            else
            {
                sfcHandle.fro_trim++;
            }

            irqMask = DisableGlobalIRQ();

            /* Normally, FRO32K should be disabled before changing the trimming
             * value, but we can avoid this by syncing on the timer counter increment
             * This will avoid glitches on the output clock */
            rf2p4ghz_timer = RFMC->RF2P4GHZ_TIMER;
            while (RFMC->RF2P4GHZ_TIMER == rf2p4ghz_timer)
                ;

            /* apply new fro trim value */
            CCM32K->FRO32K_TRIM = sfcHandle.fro_trim & CCM32K_FRO32K_TRIM_FREQ_TRIM_MASK;

            EnableGlobalIRQ(irqMask);

            /* As we change the FRO trimming value, we changed its frequency, so the averaging filter must be reset
             * as all previous measures are invalid now */
            SFC_ResetFilterState();
        }
        else
        {
            /* If the clock source switches to another source than fro32k (like osc32k), we disable the SFC module
             * The SFC can be re-enabled by calling SFC_Enable function */
            SFC_Enable(false);
        }
        PLATFORM_RemoteActiveRel();
    }
    else
    {
        if (sfcHandle.ppmTargetReached == false)
        {
            /* The current ppm is in the ppm target window
             * In this situation, the SFC will program measurement only on next wake up from low power with the RFMC
             * trigger
             * */
            sfcHandle.ppmTargetReached = true;
        }
    }
}

/*!
 * \brief Callback called once the non blocking SFA measure is done, retrieves
 *        the frequency measured and computes the error in ppm
 *
 * \param[in] status status of the measure, expected is
 *                   kStatus_SFA_MeasurementCompleted
 */
static void SFC_MeasureCallback(status_t status)
{
    uint32_t freq = 0U;
    int32_t  ppm  = 0U;

    if (status == kStatus_SFA_MeasurementCompleted)
    {
        /* Get the frequency and compute the error in ppm compared to 32768 */
        freq          = SFA_CalculateFrequencyOrPeriod(RF_SFA, 32000000U);
        int64_t tmp64 = ((int64_t)32768 - (int64_t)freq) * 1000000;
        ppm           = (int32_t)(tmp64 >> 15); // dividing by 32768

        /* Update ppm and freq values
         * Apply FIR moving average filter to smoothen the measure error */
        sfcHandle.ppm  = SFC_ComputeMMA(ppm);
        sfcHandle.freq = freq;

        sfcLog->averagePpm       = (int16_t)sfcHandle.ppm;
        sfcLog->lastFreqMeasured = (uint16_t)freq;

        sfcHandle.lastFreq = (uint16_t)freq;
        sfcHandle.lastPpm  = (int16_t)ppm;

        /* Set the measureAvailable flag so the result can be processed in SFC_Process function */
        sfcHandle.measureAvailable = true;
    }

    SFA_ClearStatusFlag(RF_SFA, SFA_GetStatusFlags(RF_SFA));
}

/*!
 * \brief Computes 1 iteration of a Modified Moving Average filter
 *        This filtering method can be associated with an Exponential Moving
 *        Average which decrease factor (alpha) is 1/N (N being the number of
 *        samples). This is also known as an Infinite Impulse Response filter
 *        It tries to approximate a Moving Average of N samples
 *
 * \param[in] sample Input sample from last measure
 * \return int32_t Current average value
 */
static int32_t SFC_ComputeMMA(int32_t sample)
{
    if (sfcHandle.filterState.sampleNumber == 0U)
    {
        sfcHandle.filterState.sum = sample << sfcHandle.filterState.shift;
    }
    else
    {
        sfcHandle.filterState.sum -= sfcHandle.filterState.sum >> sfcHandle.filterState.shift;
        sfcHandle.filterState.sum += sample;
    }

    if (sfcHandle.filterState.sampleNumber < sfcConfig.filterSize)
    {
        sfcHandle.filterState.sampleNumber++;
    }

    return sfcHandle.filterState.sum >> sfcHandle.filterState.shift;
}

static void SFC_ResetFilterState(void)
{
    sfcHandle.filterState.sampleNumber = 0U;
    sfcHandle.filterState.sum          = 0;
}

extern void LL_API_GetBleTiming(uint32_t *pNativeClock, uint16_t *pNativeClockOffset);

static uint32_t SFC_GetTimestamp(void)
{
    uint32_t hslot;
    uint16_t qus;
    uint32_t timestampInQuarterUs;

    /* The timing returned by this API can be wrong if called just after a lowpower wakeup as the native clock of the LL
     * needs some time to update */
    LL_API_GetBleTiming(&hslot, &qus);

    /* Return value is in quarter of us to ease the way  of handling the wrapping of the LL timer
     * hslot_max_value = 0xFFFF_FFFF ; qus_max_value = 1249 => timestampInQuarterUs_max_value = 0xFFFF_FFFF
     */
    timestampInQuarterUs = (hslot * 1250U + (uint32_t)qus);

    return timestampInQuarterUs;
}