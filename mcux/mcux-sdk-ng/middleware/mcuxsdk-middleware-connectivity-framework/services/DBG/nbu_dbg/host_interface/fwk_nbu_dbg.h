/*
 * Copyright 2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __FWK_DEBUG_NBU_H__
#define __FWK_DEBUG_NBU_H__

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include <stdint.h>
#include <stdbool.h>
#include "fwk_debug_struct.h"

/* -------------------------------------------------------------------------- */
/*                           Public type definitions                          */
/* -------------------------------------------------------------------------- */
/*!
 * \brief NBU debug event id
 *
 */
typedef enum
{
    fatal_error,
    reserved
} nbu_dbg_event_id_t;

typedef void (*nbu_dbg_system_err_cb_t)(nbu_dbg_event_id_t event_id);

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Check if a fault has occured on NBU side
 *
 * \note NBU shall be using fault handlers to be able to check its status.
 */
void NBUDBG_StateCheck(void);

/*!
 * \brief Register a system error callback. Will be called when NBU crashes.
 *
 * \param[in] cb callback to be registered
 */
void NBUDBG_RegisterSystemErrorCb(nbu_dbg_system_err_cb_t cb);

/*!
 * \brief Extract NBU debug information.
 *
 * \param[out] debug_struct structure to be filled with the extracted debug information from NBU.
 *
 * \return int 0 if success, negative value if error
 */
int NBUDBG_StructDump(nbu_debug_struct_t *debug_struct);

#endif /*  __FWK_DEBUG_NBU_H__ */
