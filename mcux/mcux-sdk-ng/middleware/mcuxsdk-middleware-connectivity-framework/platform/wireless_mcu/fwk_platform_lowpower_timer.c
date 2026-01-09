/* -------------------------------------------------------------------------- */
/*                           Copyright 2023 NXP                               */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fwk_platform.h"
#include "fwk_platform_lowpower_timer.h"
#include "fsl_component_timer_manager.h"

/* -------------------------------------------------------------------------- */
/*                             Private variables                              */
/* -------------------------------------------------------------------------- */

static TIMER_MANAGER_HANDLE_DEFINE(wakeUpTimerId);

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

void PLATFORM_InitWakeUpTimer(void)
{
    timer_status_t timer_status;

    timer_status = TM_Open((timer_handle_t)wakeUpTimerId);
    assert(timer_status == kStatus_TimerSuccess);
    (void)timer_status;
}

void PLATFORM_StartWakeUpTimer(uint64_t timeOutUs)
{
    TM_EnterTickless((timer_handle_t)wakeUpTimerId, timeOutUs);
}

void PLATFORM_StopWakeUpTimer(void)
{
    TM_ExitTickless((timer_handle_t)wakeUpTimerId);
}

uint64_t PLATFORM_GetLowPowerTimestampUs(void)
{
    return TM_GetTimestamp();
}

uint64_t PLATFORM_GetLowPowerDurationUs(uint64_t enterLowPowerTimestamp, uint64_t exitLowPowerTimestamp)
{
    uint64_t lowPowerDurationUs;

    if (exitLowPowerTimestamp < enterLowPowerTimestamp)
    {
        /* Handle counter wrapping */
        lowPowerDurationUs =
            COUNT_TO_USEC(0xFFFFFFFFU, PLATFORM_TM_CLK_FREQ) - enterLowPowerTimestamp + exitLowPowerTimestamp;
    }
    else
    {
        lowPowerDurationUs = exitLowPowerTimestamp - enterLowPowerTimestamp;
    }

    return lowPowerDurationUs;
}
