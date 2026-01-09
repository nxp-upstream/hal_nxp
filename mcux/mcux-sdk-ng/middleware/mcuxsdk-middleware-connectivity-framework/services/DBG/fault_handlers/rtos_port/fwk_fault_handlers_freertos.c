/*
 * Copyright 2024-2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include "fwk_fault_handlers_rtos_port.h"
#include "fwk_fault_handlers_utils.h"
#include "FreeRTOS.h"
#include "task.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */
#ifndef SYS_CALLSTACK_DEPTH
#define SYS_CALLSTACK_DEPTH 300
#endif

/* -------------------------------------------------------------------------- */
/*                         Public memory declarations                         */
/* -------------------------------------------------------------------------- */
extern unsigned int __HEAP_end__[];

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */
static uint8_t TaskStatusList[SYS_DEBUG_MAX_TASKS_NB * sizeof(TaskStatus_t)];

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */
static void sys_dump_callstack_ext(unsigned int stack_pointer, unsigned int *task_hdl);

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */
void sys_dump_task_stats(void)
{
    static const char task_state_char[] = {
        'r', /* Running, never returned by uxTaskGetSystemState */
        'R', /* Ready */
        'B', /* Blocked */
        'S', /* Suspended */
        'D', /* Deleted */
        'I', /* Invalid */
    };

    TaskStatus_t        *pxTaskStatusArray = (TaskStatus_t *)&TaskStatusList;
    volatile UBaseType_t uxArraySize, x;
    uint32_t             ulTotalRunTime;

    PRINTF("==========TASK STATUS==========\r\n");

    {
        /* Generate raw status information about each task. */
        uxArraySize = uxTaskGetSystemState(pxTaskStatusArray, SYS_DEBUG_MAX_TASKS_NB, &ulTotalRunTime);
        if (uxArraySize == SYS_DEBUG_MAX_TASKS_NB)
        {
            PRINTF("WARNING: SYS_DEBUG_MAX_TASKS_NB too small - task list incomplete !!\r\n");
        }
        /* For percentage calculations.*/
        ulTotalRunTime /= 100UL;

        /* For each populated position in the pxTaskStatusArray array,
           format the raw data as human readable ASCII data */
        PRINTF("%s\t\t%s  %s  %s   %s   %s      %s\r\n", "Task Name", "State", "PRI", "Base_PRI", "Time", "Watermark",
               "SP");
        for (x = 0; x < uxArraySize; x++)
        {
            int task_state;
#if defined(INCLUDE_xTaskGetHandle) && (INCLUDE_xTaskGetHandle > 0)
            unsigned int *task_hdl;
            task_hdl = (unsigned int *)xTaskGetHandle((const char *)pxTaskStatusArray[x].pcTaskName);
#endif
            task_state = pxTaskStatusArray[x].eCurrentState;
            if (task_state > eInvalid)
            {
                task_state = eInvalid;
            }

            /* If the percentage is zero here then the task has
               consumed less than 1% of the total run time. */
            PRINTF(
#if defined(INCLUDE_xTaskGetHandle) && (INCLUDE_xTaskGetHandle > 0)
                "%s%s%s\t%c\t%d\t%d\t%d\t%d\t0x%8x\r\n",
#else
                "%s%s%s\t%c\t%d\t%d\t%d\t%d\r\n",
#endif
                pxTaskStatusArray[x].pcTaskName,
                (strlen(pxTaskStatusArray[x].pcTaskName) < 8) ? "\t" : "",  /* Adjust tabulation */
                (strlen(pxTaskStatusArray[x].pcTaskName) < 16) ? "\t" : "", /* Adjust tabulation */
                task_state_char[task_state], pxTaskStatusArray[x].uxCurrentPriority,
                pxTaskStatusArray[x].uxBasePriority, pxTaskStatusArray[x].ulRunTimeCounter,
                pxTaskStatusArray[x].usStackHighWaterMark
#if defined(INCLUDE_xTaskGetHandle) && (INCLUDE_xTaskGetHandle > 0)
                /* by construction, first word in taskHandle is the last stack pointer saved in last context switch */
                ,
                task_hdl[0]);
#else
            );
#endif
        }

        PRINTF("\r\n==========Thread Callstacks========== (code start=0x%x code end=0x%x)\r\n",
               (unsigned int)_TEXT_START, (unsigned int)_TEXT_END);
#if defined(INCLUDE_xTaskGetHandle) && (INCLUDE_xTaskGetHandle > 0)
        for (x = 0; x < uxArraySize; x++)
        {
            unsigned int *task_hdl = (void *)xTaskGetHandle((const char *)pxTaskStatusArray[x].pcTaskName);

            /* Current stack pointer of the thread is given by the first word in task handle */
            unsigned int CurrentSP = (unsigned int)task_hdl[0];

            PRINTF("%s : ", pxTaskStatusArray[x].pcTaskName);
            sys_dump_callstack_ext(CurrentSP, task_hdl);
        }
#endif
    }
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */
static void sys_dump_callstack_ext(unsigned int stack_pointer, unsigned int *task_hdl)
{
    /* During task creation, the stack is allocated before the task context in FreeRTOS,
     * The task context does not contain the top of the stack neither the stack size.
     * to get the top of the stack, Assumption is that the task context is at the top of the stack.
     */
    unsigned int topOfStack =
        (((stack_pointer + SYS_CALLSTACK_DEPTH) > (unsigned int)task_hdl) && (stack_pointer < (unsigned int)task_hdl)) ?
            (unsigned int)task_hdl :
            (stack_pointer + SYS_CALLSTACK_DEPTH);

    /* Ensure that computed top of stack is not outside data memory (case for exception context) */
    if (topOfStack > (unsigned int)__HEAP_end__)
    {
        topOfStack = (unsigned int)__HEAP_end__;
    }

    sys_dump_callstack(stack_pointer, topOfStack);
    PRINTF("\r\n");
}
