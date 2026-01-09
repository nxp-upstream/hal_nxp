/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __FWK_DEBUG_STRUCT_H__
#define __FWK_DEBUG_STRUCT_H__

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include <stdint.h>

/* -------------------------------------------------------------------------- */
/*                                Public macros                               */
/* -------------------------------------------------------------------------- */
#define NBUDBG_USE_LEGACY_STRUCT     1
#define NBUDBG_BLE_STRUCT_SIZE       sizeof(nbu_debug_struct_t)
#define NBUDBG_SET_REG(reg, val)     ((debug_struct)->dbg_info.exception_data.dbg_exception.reg = (val))
#define NBUDBG_SET_EXCEPTION_ID(val) ((debug_struct)->dbg_info.exception_data.exception_id = (val))
#define NBUDBG_SET_XFAR(reg, val)    ((debug_struct)->dbg_info.exception_data.dbg_exception.xfar.reg = (val))
#define NBUDBG_SET_SHA(val)          ((debug_struct)->nbu_sha1 = (val))
#define NBUDBG_BLE_STRUCT            debug_struct
/* Not supported macro */
#define NBUDBG_SET_HANDLER_MODE_IRQ(irq_nbr)
#define NBUDBG_SetThreadContext(a, b)

/* -------------------------------------------------------------------------- */
/*                            Public type definitions                         */
/* -------------------------------------------------------------------------- */
typedef struct
{
    uint32_t cfsr;
    union
    {
        uint32_t mmfar;
        uint32_t bfar;
    } xfar;
    uint32_t pc;
    uint32_t lr;
    uint32_t sp;
    uint32_t psr;
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;
    uint32_t r12;
} regs_status_t;

typedef struct
{
    /*6 x 32 bit*/
    uint16_t reserved_0;
    uint16_t exception_id;
    uint32_t reserved_1[5];
    /*19 x 32 bit*/
    regs_status_t dbg_exception;
} exception_status_t;

union dbg_info_u
{
    exception_status_t exception_data;
    uint32_t           reserved[26];
};

typedef struct
{
    /*2 x 32 bit*/
    uint32_t reserved_1[2];
    /*1 x 32 bit*/
    uint32_t nbu_sha1;
    /*26 x 32 bit maximum*/
    union dbg_info_u dbg_info;

    /*1 x 32 bit*/
    uint32_t reserved_2;
} nbu_debug_struct_t;

extern nbu_debug_struct_t *debug_struct;

#endif /*  __FWK_DEBUG_STRUCT_H__ */
