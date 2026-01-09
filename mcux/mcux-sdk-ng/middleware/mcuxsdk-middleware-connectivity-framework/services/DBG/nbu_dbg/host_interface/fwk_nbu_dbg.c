/*
 * Copyright 2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fwk_nbu_dbg.h"
#include "fwk_platform.h"
#include "fwk_debug_struct.h"
#include "fwk_platform_dbg.h"
#include <string.h>

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                         Public memory declarations                         */
/* -------------------------------------------------------------------------- */
extern unsigned int m_sqram_debug_start[];
nbu_debug_struct_t *debug_struct = (nbu_debug_struct_t *)(m_sqram_debug_start);

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */
static nbu_dbg_system_err_cb_t nbu_dbg_system_err_cb = (nbu_dbg_system_err_cb_t)NULL;

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

void NBUDBG_StateCheck(void)
{
    if (PLATFORM_IsNbuFaultSet())
    {
        if (nbu_dbg_system_err_cb != NULL)
        {
            nbu_dbg_system_err_cb(fatal_error);
        }
    }
}

void NBUDBG_RegisterSystemErrorCb(nbu_dbg_system_err_cb_t cb)
{
    nbu_dbg_system_err_cb = cb;
}

int NBUDBG_StructDump(nbu_debug_struct_t *debug_info)
{
    int status = 0;

    if (debug_info == NULL)
    {
        status = -1; /* Invalid parameter */
    }
    else
    {
        PLATFORM_RemoteActiveReq();
        /* Need to wake NBU domain to access the debug structure */
        memcpy(debug_info, debug_struct, sizeof(nbu_debug_struct_t));
        PLATFORM_RemoteActiveRel();
    }

    return status;
}
