/*
 * Copyright 2024-2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include <stdint.h>
#if defined(gDBG_LogInLinkLayerDebugStructEnabled_d) && (gDBG_LogInLinkLayerDebugStructEnabled_d == 1)
#include "fwk_debug_struct.h"
#include "fwk_platform_dbg.h"
#else
/* Definition for PRINTF */
#include "fsl_debug_console.h"
#endif

/* -------------------------------------------------------------------------- */
/*                               Public macros                                */
/* -------------------------------------------------------------------------- */
#if defined(gDBG_LogInLinkLayerDebugStructEnabled_d) && (gDBG_LogInLinkLayerDebugStructEnabled_d == 1)
/* No debug console on NBU core on KW45 */
#undef PRINTF
#define PRINTF(...)
#endif /* gDBG_LogInLinkLayerDebugStructEnabled_d */

#define _TEXT_START m_text_start
#define _TEXT_END   m_text_end
#define _STACK_TOP  m_cstack_end

/* -------------------------------------------------------------------------- */
/*                         Public memory declarations                         */
/* -------------------------------------------------------------------------- */
extern unsigned int m_text_start[];
extern unsigned int m_text_end[];
extern unsigned int m_cstack_end[];

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

/**
 * \brief Parses a stack and dumps addresses that are possibly part of the call stack
 *
 * This function scans through a stack memory range and prints addresses that fall
 * within the text (code) section, which are likely to be part of the call stack.
 * It helps with debugging by showing the sequence of function calls that led to
 * the current execution point.
 *
 * \param[in] stack_ptr Starting address of the stack to analyze (lower address)
 * \param[in] stack_top Ending address of the stack to analyze (higher address)
 */
void sys_dump_callstack(unsigned int stack_ptr, unsigned int stack_top);

/**
 * \brief Dumps the exception call stack from the current exception context
 *
 * This function retrieves the Main Stack Pointer (MSP) from the current exception
 * context and uses it to analyze the call stack from the exception point to the
 * top of the stack. It's specifically designed to be called from exception handlers
 * to help debug what sequence of function calls led to the exception.
 */
void sys_dump_exception_callstack(void);

/**
 * \brief Dumps the current interrupt status showing pending and active IRQs
 *
 * This function iterates through all available IRQ numbers and checks their status
 * using NVIC functions. It prints information about any pending or active interrupts,
 * which is useful for debugging interrupt-related issues or understanding the system
 * state during fault conditions.
 */
void sys_dump_interrupt_status(void);
