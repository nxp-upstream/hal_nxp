/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2025 NXP                          */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fwk_platform_genfsk.h"
#if defined(gPlatformEnableDcdcOnNbu_d) && (gPlatformEnableDcdcOnNbu_d == 1)
#include "fwk_platform_dcdc.h"
#endif
#include "nxp2p4_xcvr.h"

/* -------------------------------------------------------------------------- */
/*                                   Macros                                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
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

#if defined(gPlatformEnableDcdcOnNbu_d) && (gPlatformEnableDcdcOnNbu_d == 1)
    /* Configure SPC high power mode depending the targeted tx power and if the application core is allowing it */
    PLATFORM_ConfigureSpcHighPowerMode(max_tx_power);
#endif

    XCVR_setLdoAntTrim(ldo_ana_trim);
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */
