/* -------------------------------------------------------------------------- */
/*                             Copyright 2024 NXP                             */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fwk_platform_rng.h"
#include "fwk_platform_ics.h"
#include "fwk_platform.h"

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

int PLATFORM_RequestRngSeed(void)
{
    /* Not implemented */
    return 1;
}

int PLATFORM_SendRngSeed(uint8_t *seed, uint16_t seed_size)
{
    int status = 2;

    /* status will be kept to 2 if the nbu is not started */
    if (PLATFORM_IsNbuStarted() == 1)
    {
        status = PLATFORM_FwkSrvSendPacket(gFwkSrvRngReseed_c, (void *)seed, seed_size);
    }

    return status;
}
