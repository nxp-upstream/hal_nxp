/* -------------------------------------------------------------------------- */
/*                           Copyright 2023 NXP                               */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_PLATFORM_LOWPOWER_TIMER_H_
#define _FWK_PLATFORM_LOWPOWER_TIMER_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>

/* -------------------------------------------------------------------------- */
/*                              Public prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Initialize a wake up timer
 *        Should be called during low power initialization.
 *
 */
void PLATFORM_InitWakeUpTimer(void);

/*!
 * \brief Start a wake up timer for next tickless idle period
 *        Should be called during low power entry procedure.
 *
 * \param[in] timeoutUs maximum timeout in microsec
 */
void PLATFORM_StartWakeUpTimer(uint64_t timeOutUs);

/*!
 * \brief Stops previously started wake up timer if the tickless period ended
 *         earlier than expected. Should be called after exiting low power.
 *
 */
void PLATFORM_StopWakeUpTimer(void);

/*!
 * \brief Returns current timestamp in us, usually called before and after tickless
 *        period to compute the number of ticks to update RTOS timebase.
 *
 * \return uint64_t Timestamp value in us
 */
uint64_t PLATFORM_GetLowPowerTimestampUs(void);

/*!
 * \brief Converts timestamp values returned by PLATFORM_GetLowPowerTimestamp to
 *        a duration in us and handles counter wrapping.
 *
 * \param[in] enterLowPowerTimestamp Timestamp measured before entering tickless period
 * \param[in] exitLowPowerTimestamp Timestamp measured after exiting tickless period
 * \return uint64_t Computed duration in us
 */
uint64_t PLATFORM_GetLowPowerDurationUs(uint64_t enterLowPowerTimestamp, uint64_t exitLowPowerTimestamp);

#endif /* _FWK_PLATFORM_LOWPOWER_TIMER_H_ */
