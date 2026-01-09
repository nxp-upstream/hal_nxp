/*
 * Copyright 2024-2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include "fsl_common.h"
#include "EmbeddedTypes.h"
#include "fwk_debug.h"
#include "fwk_fault_handlers_utils.h"
#if defined(SDK_OS_FREE_RTOS) || defined(FSL_RTOS_THREADX)
#include "fwk_fault_handlers_rtos_port.h"
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                         Public memory declarations                         */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */
static int sys_debug_panic_triggered = 0;

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */
/**
 * HardFaultHandler:
 * This is called from the HardFault_HandlerAsm with a pointer the Fault stack
 * as the parameter. We can then read the values from the stack and place them
 * into local variables for ease of reading.
 * We then read the various Fault Status and Address Registers to help decode
 * cause of the fault.
 */
void HardFaultHandler(unsigned long *hardfault_args)
{
    volatile unsigned int stacked_r0;
    volatile unsigned int stacked_r1;
    volatile unsigned int stacked_r2;
    volatile unsigned int stacked_r3;
    volatile unsigned int stacked_r4;
    volatile unsigned int stacked_r5;
    volatile unsigned int stacked_r6;
    volatile unsigned int stacked_r7;
    volatile unsigned int stacked_r8;
    volatile unsigned int stacked_r9;
    volatile unsigned int stacked_r10;
    volatile unsigned int stacked_r11;
    volatile unsigned int stacked_r12;
    volatile unsigned int stacked_lr;
    volatile unsigned int stacked_pc;
    volatile unsigned int stacked_sp;
    volatile unsigned int stacked_psr;
    volatile unsigned int EXEC_RETURN;
    unsigned int          stack_frame_size;

    stacked_r0  = ((unsigned int)hardfault_args[0]);
    stacked_r1  = ((unsigned int)hardfault_args[1]);
    stacked_r2  = ((unsigned int)hardfault_args[2]);
    stacked_r3  = ((unsigned int)hardfault_args[3]);
    stacked_r12 = ((unsigned int)hardfault_args[4]);
    stacked_lr  = ((unsigned int)hardfault_args[5]);
    stacked_pc  = ((unsigned int)hardfault_args[6]);
    stacked_psr = ((unsigned int)hardfault_args[7]);

    __asm volatile(" mov %0, r4" : "=r"(stacked_r4));
    __asm volatile(" mov %0, r5" : "=r"(stacked_r5));
    __asm volatile(" mov %0, r6" : "=r"(stacked_r6));
    __asm volatile(" mov %0, r7" : "=r"(stacked_r7));
    __asm volatile(" mov %0, r8" : "=r"(stacked_r8));
    __asm volatile(" mov %0, r9" : "=r"(stacked_r9));
    __asm volatile(" mov %0, r10" : "=r"(stacked_r10));
    __asm volatile(" mov %0, r11" : "=r"(stacked_r11));

    __asm volatile(" mov %0, lr" : "=r"(EXEC_RETURN));

    /* Calculate the correct stack pointer based on FPU usage
     * Basic stack frame: 8 words (32 bytes)
     * Extended stack frame (with FPU): 26 words (104 bytes)
     * EXC_RETURN[4] == 0 means FPU state was saved (extended frame)
     */
    if ((EXEC_RETURN & 0x10U) == 0U)
    {
        stack_frame_size = 26U; /* Extended frame with FPU registers */
    }
    else
    {
        stack_frame_size = 8U; /* Basic frame without FPU registers */
    }
    /* need to remove the stacked words from sp to get the initial SP value when the fault occurred */
    stacked_sp = (unsigned int)hardfault_args + (stack_frame_size * 4U);

    /* Dump the cortex register first in case of issues in the logging dump */
    PRINTF("\r\n============\r\n");
    PRINTF("HardFault from pc    = 0x%08x (%d)\r\n", stacked_pc, stacked_pc);

    PRINTF("r0    = 0x%08x\r\n", stacked_r0);
    PRINTF("r1    = 0x%08x\r\n", stacked_r1);
    PRINTF("r2    = 0x%08x\r\n", stacked_r2);
    PRINTF("r3    = 0x%08x\r\n", stacked_r3);

    PRINTF("r4    = 0x%08x\r\n", stacked_r4);
    PRINTF("r5    = 0x%08x\r\n", stacked_r5);
    PRINTF("r6    = 0x%08x\r\n", stacked_r6);
    PRINTF("r7    = 0x%08x\r\n", stacked_r7);
    PRINTF("r8    = 0x%08x\r\n", stacked_r8);
    PRINTF("r9    = 0x%08x\r\n", stacked_r9);
    PRINTF("r10   = 0x%08x\r\n", stacked_r10);
    PRINTF("r11   = 0x%08x\r\n", stacked_r11);

    PRINTF("r12   = 0x%08x\r\n", stacked_r12);
    PRINTF("lr    = 0x%08x (%d)\r\n", stacked_lr, stacked_lr);
    PRINTF("sp    = 0x%08x\r\n", stacked_sp);
    PRINTF("psr   = 0x%08x\r\n", stacked_psr);

#if defined(gDBG_LogInLinkLayerDebugStructEnabled_d) && (gDBG_LogInLinkLayerDebugStructEnabled_d == 1)
    NBUDBG_SET_REG(pc, stacked_pc);
    NBUDBG_SET_REG(lr, stacked_lr);
    NBUDBG_SET_REG(sp, stacked_sp);
    NBUDBG_SET_REG(psr, stacked_psr);
    NBUDBG_SET_REG(r0, stacked_r0);
    NBUDBG_SET_REG(r1, stacked_r1);
    NBUDBG_SET_REG(r2, stacked_r2);
    NBUDBG_SET_REG(r3, stacked_r3);
    NBUDBG_SET_REG(r4, stacked_r4);
    NBUDBG_SET_REG(r5, stacked_r5);
    NBUDBG_SET_REG(r6, stacked_r6);
    NBUDBG_SET_REG(r7, stacked_r7);
    NBUDBG_SET_REG(r8, stacked_r8);
    NBUDBG_SET_REG(r9, stacked_r9);
    NBUDBG_SET_REG(r10, stacked_r10);
    NBUDBG_SET_REG(r11, stacked_r11);
    NBUDBG_SET_REG(r12, stacked_r12);
#endif /* gDBG_LogInLinkLayerDebugStructEnabled_d */

#if (__CORTEX_M == 33) || (__CORTEX_M == 3)

#if defined(gDBG_LogInLinkLayerDebugStructEnabled_d) && (gDBG_LogInLinkLayerDebugStructEnabled_d == 1)
    NBUDBG_SET_EXCEPTION_ID(__get_IPSR());
    NBUDBG_SET_REG(cfsr, SCB->CFSR);
#endif

    PRINTF("_CFSR = 0x%08x (Configurable Fault Status Register: UFSR|BFSR|MMSR)\r\n", SCB->CFSR);
    PRINTF("_HFSR = 0x%08x (Hard Fault Status Register)\r\n", SCB->HFSR);
    PRINTF("_DFSR = 0x%08x (Debug Fault Status Register)\r\n", SCB->DFSR);
    PRINTF("_AFSR = 0x%08x (Auxiliary Fault Status Register)\r\n", SCB->AFSR);
    PRINTF("_SHCSR= 0x%08x (System Handler Control and State Register)\r\n", (unsigned int)SCB->SHCSR);

    if ((SCB->CFSR & SCB_CFSR_MMARVALID_Msk) != 0U)
    {
        PRINTF("_MMAR = 0x%08x (MemManage Fault Address Register)\r\n", SCB->MMFAR);
#if defined(gDBG_LogInLinkLayerDebugStructEnabled_d) && (gDBG_LogInLinkLayerDebugStructEnabled_d == 1)
        NBUDBG_SET_XFAR(mmfar, SCB->MMFAR);
#endif
    }
    if ((SCB->CFSR & SCB_CFSR_BFARVALID_Msk) != 0U)
    {
        PRINTF("_BFAR = 0x%08x (Bus Fault Address Register)\r\n", SCB->BFAR);
#if defined(gDBG_LogInLinkLayerDebugStructEnabled_d) && (gDBG_LogInLinkLayerDebugStructEnabled_d == 1)
        NBUDBG_SET_XFAR(bfar, SCB->BFAR);
#endif
    }
    if ((SCB->CFSR & SCB_CFSR_DIVBYZERO_Msk) != 0U)
    {
        PRINTF("Division by zero\r\n");
    }
    if ((SCB->CFSR & SCB_CFSR_UNALIGNED_Msk) != 0U)
    {
        PRINTF("Unaligned access\r\n");
    }

    PRINTF("Exception_id = 0x%08x \r\n", __get_IPSR());
#endif

    PRINTF("EXEC_RETURN  = 0x%08x (%d current lr)\r\n", EXEC_RETURN, EXEC_RETURN);
    PRINTF("comming from %s\r\n", (EXEC_RETURN & 0x4) ? "Thread mode (Process stack)" : "Handler mode (Main Stack)");

    /* If gLoggingActive_d is set, Dump the log now */
    DBG_LOG_DUMP();

    /* Avoid recursive panic/fault */
    if (sys_debug_panic_triggered < 1)
    {
        sys_debug_panic_triggered++;

        if (EXEC_RETURN & 0x4)
        {
            /* Thread mode */
#if defined(SDK_OS_FREE_RTOS) || defined(FSL_RTOS_THREADX)
            sys_dump_task_stats();
#endif
        }
        else
        {
            /* Print diagnostics */
            sys_dump_interrupt_status();
#if !defined(gDBG_LogInLinkLayerDebugStructEnabled_d) || (gDBG_LogInLinkLayerDebugStructEnabled_d == 0)
            /* Handler mode */
            sys_dump_exception_callstack();
#endif
        }
        PRINTF("\r\n");
        PRINTF(
            "Command for parsing a stack:\r\n>arm-none-eabi-addr2line.exe -e <your_project>.elf "
            "<paste_stack_line_above>\r\nadd option -f to show the function and line\r\n");
    }
#if defined(gDBG_LogInLinkLayerDebugStructEnabled_d) && (gDBG_LogInLinkLayerDebugStructEnabled_d == 1)
    /* NBU failure indication to host core */
    PLATFORM_Nbu2HostFaultIndication();
#endif
    while (true)
    {
    }
}

#if ((__CORTEX_M == 33) || (__CORTEX_M == 3))
void HardFault_Handler(void)
{
    __asm volatile(
        "movs r0, #4\t\n"
        "mov  r1, lr\t\n"
        "tst  r0, r1\t\n" /* Check EXC_RETURN[2] */
        "beq 1f\t\n"
        "mrs r0, psp\t\n"
        "ldr r1,=HardFaultHandler\t\n"
        "bx r1\t\n"
        "1:mrs r0,msp\t\n"
        "ldr r1,=HardFaultHandler\t\n"
        "bx r1\t\n");
}

void NMI_Handler(void)
{
    __asm volatile("  b HardFault_Handler \n");
}

void MemManage_Handler(void)
{
    __asm volatile("  b HardFault_Handler \n");
}

void BusFault_Handler(void)
{
    __asm volatile(" b HardFault_Handler \n");
}

void UsageFault_Handler(void)
{
    __asm volatile(" b HardFault_Handler \n");
}
#endif

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */
