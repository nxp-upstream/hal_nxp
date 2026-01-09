/* -------------------------------------------------------------------------- */
/*                     Copyright 2021-2022, 2024-2025 NXP                     */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "board_platform.h"
#include "fwk_platform_genfsk.h"
#include "fwk_platform.h"

#if defined(FPGA_TARGET) && (FPGA_TARGET == 1)
#include "hdi.h"
#endif

/* -------------------------------------------------------------------------- */
/*                                   Macros                                   */
/* -------------------------------------------------------------------------- */

/* Check if __st is negative,  if true, apply 4 bits shit and add new __error_code,
    assert in debug and break
   Shall be called in a do while(false) bracket */
#define CHECK_AND_RAISE_ERROR(__st, __error_code)                                              \
    if ((__st) < 0)                                                                            \
    {                                                                                          \
        assert(0);                                                                             \
        (__st) = -(int)((uint32_t)(((uint32_t)(-(__st)) << 4) | (uint32_t)(-(__error_code)))); \
        break;                                                                                 \
    }

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

void PLATFORM_InitGenfsk(void)
{
    int status = 0;

#if defined(FPGA_TARGET) && (FPGA_TARGET == 1)
    /* Select GENFSK radio mode */
    (void)HDI_Init();
    HDI_Set_Mode_Gfsk();
#endif

    do
    {
        status = PLATFORM_InitTimerManager();
        CHECK_AND_RAISE_ERROR(status, -1);

        /* Init NBU domain and related component
           needed for it (HCI transport, IPC for channel switch..) */
        status = PLATFORM_InitNbu();
        CHECK_AND_RAISE_ERROR(status, -2);

        PLATFORM_SetGenfskMaxTxPower(gAppMaxTxPowerDbm_c);

#if !defined(gBoardUseFro32k_d) || (gBoardUseFro32k_d == 0)
        /* Make sure OSC32k is ready and select it as clock source */
        status = PLATFORM_SwitchToOsc32k();
        CHECK_AND_RAISE_ERROR(status, -3);
#endif
    } while (false);
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

void PLATFORM_SetGenfskMaxTxPower(int8_t max_tx_power)
{
    uint8_t ldo_ana_trim;

    if (max_tx_power <= 0)
    {
        // 0 dBm
        ldo_ana_trim = 3U;
    }
    else if (max_tx_power <= 7)
    {
        // 7dBm
        ldo_ana_trim = 9U;
    }
    else
    {
        // 10dBm
        ldo_ana_trim = 15U;
    }

    uint32_t temp_trim;
    temp_trim = XCVR_ANALOG->LDO_1;
    temp_trim &= ~(XCVR_ANALOG_LDO_1_LDO_ANT_TRIM_MASK);
    temp_trim |= XCVR_ANALOG_LDO_1_LDO_ANT_TRIM(ldo_ana_trim);
    XCVR_ANALOG->LDO_1 = temp_trim;
}
