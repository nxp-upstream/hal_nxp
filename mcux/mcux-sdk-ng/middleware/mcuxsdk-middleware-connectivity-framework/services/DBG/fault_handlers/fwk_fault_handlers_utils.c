/*
 * Copyright 2024-2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include <stdbool.h>
#include "fsl_common.h"
#include "fsl_device_registers.h"
#include "EmbeddedTypes.h"
#include "fwk_fault_handlers_utils.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */
/* Determine the highest IRQ number by subtracting system exceptions and adjusting for zero-based indexing */
#define IRQN_TYPE_MAX               NUMBER_OF_INT_VECTORS - 16 - 1
#define SYS_DEBUG_CALLSTACK_KEYWORD ">>>"

/* -------------------------------------------------------------------------- */
/*                         Public memory declarations                         */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

/* Parses a stack and dump addresses that are possibly part of the call stack
 * (each address in the text range)
 */
void sys_dump_callstack(unsigned int stack_ptr, unsigned int stack_top)
{
    unsigned int *addr;

    PRINTF("CallStack from sp=0x%x to top=0x%x (approximate):\r\n", stack_ptr, stack_top);
    PRINTF(SYS_DEBUG_CALLSTACK_KEYWORD);

    /* Search for possible backtrace addresses in the stack */
    for (addr = (unsigned int *)stack_ptr; addr < (unsigned int *)stack_top; addr++)
    {
        unsigned int val = *addr;
        if ((val > (unsigned int)_TEXT_START) && (val < (unsigned int)_TEXT_END))
        {
            PRINTF("0x%x ", val);
        }
    }
    PRINTF("\r\n");
}

void sys_dump_interrupt_status(void)
{
    unsigned int IRQn;
    bool_t       irq_pending_running = FALSE;

    PRINTF("\r\n==========INTERRUPT STATUS==========\r\n");

    for (IRQn = 0U; IRQn < IRQN_TYPE_MAX; IRQn++)
    {
        if (NVIC_GetPendingIRQ((IRQn_Type)IRQn))
        {
            PRINTF("IRQ pending: %d\r\n", IRQn);
            irq_pending_running = TRUE;
        }
        if (NVIC_GetActive((IRQn_Type)IRQn))
        {
#if defined(gDBG_LogInLinkLayerDebugStructEnabled_d) && (gDBG_LogInLinkLayerDebugStructEnabled_d == 1)
            NBUDBG_SET_HANDLER_MODE_IRQ((uint32_t)IRQn);
#endif
            PRINTF("IRQ active : %d\r\n", IRQn);
            irq_pending_running = TRUE;
        }
    }

    if (!irq_pending_running)
    {
        PRINTF("No IRQ pending or running\r\n");
    }
}

void sys_dump_exception_callstack(void)
{
    volatile unsigned int exception_sp;
    __asm volatile(" mrs r0, msp");
    __asm volatile(" mov %0, r0" : "=r"(exception_sp));

    PRINTF("Exception Callstack from 0x%x to 0x%x\r\n", exception_sp, (unsigned int)_STACK_TOP);
    sys_dump_callstack(exception_sp, (unsigned int)_STACK_TOP);
    PRINTF("\r\n");
}
