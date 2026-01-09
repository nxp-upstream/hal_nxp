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
#include <string.h>

/* -------------------------------------------------------------------------- */
/*                                Public macros                               */
/* -------------------------------------------------------------------------- */
#define NBUDBG_COMMON_STRUCT_SIZE    sizeof(regs_status_t)
#define NBUDBG_BLE_STRUCT_SIZE       0x100
#define NBUDBG_15_4_STRUCT_SIZE      0x40
#define NBUDBG_SET_REG(reg, val)     ((debug_struct)->reg_dump.reg = (val))
#define NBUDBG_SET_EXCEPTION_ID(val) ((debug_struct)->reg_dump.exception_id = (val))
#define NBUDBG_SET_XFAR(reg, val)    ((debug_struct)->reg_dump.xfar.reg = (val))
#define NBUDBG_SET_SHA(val)          ((debug_struct)->reg_dump.nbu_sha1 = (val))
#define NBUDBG_BLE_STRUCT            debug_struct->dbg_ble
#define NBUDBG_15_4_STRUCT           debug_struct->dbg_15_4

/* Magic pattern to identify handler mode faults */
#define NBUDBG_HANDLER_MODE_MAGIC 0xCAFE0000U
/* Mask to extract magic pattern from handler_irq */
#define NBUDBG_MODE_MAGIC_MASK 0xFFFF0000U
/* Mask to extract actual IRQ number (will not exceed 16 bits)*/
#define NBUDBG_IRQ_NUMBER_MASK 0x0000FFFFU
/* Helper macro to set IRQ number when in handler mode */
#define NBUDBG_SET_HANDLER_MODE_IRQ(irq_nbr) \
    ((debug_struct)->reg_dump.execution_context.handler_irq = ((irq_nbr) | NBUDBG_HANDLER_MODE_MAGIC))
/* Helper macro to extract actual IRQ number when in handler mode */
#define NBUDBG_GET_IRQ_NUMBER(handler_irq) ((handler_irq)&NBUDBG_IRQ_NUMBER_MASK)
/* Execution context detection macro */
#define NBUDBG_IS_HANDLER_MODE(handler_irq) (((handler_irq)&NBUDBG_MODE_MAGIC_MASK) == NBUDBG_HANDLER_MODE_MAGIC)
/* -------------------------------------------------------------------------- */
/*                            Public type definitions                         */
/* -------------------------------------------------------------------------- */
typedef struct
{
    uint32_t exception_id;
    uint32_t nbu_sha1;
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
    union
    {
        /* Encoded execution context:
         * - Handler mode: Upper bits contain magic number + IRQ number in lower bits
         * - Thread mode : Thread info in separate fields (no magic pattern)
         */
        /* Fault from handler mode */
        uint32_t handler_irq; /* IRQ number with handler mode magic in upper 16 bits */
        /* Fault from thread mode */
        struct
        {
            uint32_t thread_addr;    /* Thread address */
            char     thread_name[8]; /* Thread name (null-terminated) */
        } thread_info;
    } execution_context;
} regs_status_t;

typedef struct
{
    regs_status_t reg_dump;
    uint8_t       dbg_ble[NBUDBG_BLE_STRUCT_SIZE];
    uint8_t       dbg_15_4[NBUDBG_15_4_STRUCT_SIZE];
} nbu_debug_struct_t;

extern nbu_debug_struct_t *debug_struct;

/**
 * \brief Set thread context information in debug structure
 *
 * \param[in] thread_entry_addr Thread entry function address
 * \param[in] thread_name_ptr Pointer to thread name string (can be NULL)
 */
static inline void NBUDBG_SetThreadContext(uint32_t thread_entry_addr, const char *thread_name_ptr)
{
    /* Set thread function address */
    debug_struct->reg_dump.execution_context.thread_info.thread_addr = thread_entry_addr;

    /* Set thread name - copy first 7 bytes and ensure null termination */
    if (thread_name_ptr != NULL)
    {
        /* Copy up to 7 characters and ensure null termination */
        strncpy(debug_struct->reg_dump.execution_context.thread_info.thread_name, thread_name_ptr, 7);
    }
    else
    {
        /* No thread name available, set default */
        strncpy(debug_struct->reg_dump.execution_context.thread_info.thread_name, "UNKNOWN", 7);
    }
    debug_struct->reg_dump.execution_context.thread_info.thread_name[7] = '\0';
}

#endif /*  __FWK_DEBUG_STRUCT_H__ */
