/*
 * Copyright 2024-2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                               Public macros                                */
/* -------------------------------------------------------------------------- */
/* Maximum number of tasks to display/track during fault analysis */
#ifndef SYS_DEBUG_MAX_TASKS_NB
#define SYS_DEBUG_MAX_TASKS_NB 15
#endif

/* -------------------------------------------------------------------------- */
/*                         Public memory declarations                         */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */
/**
 * \brief Dumps comprehensive task/thread statistics and call stacks for debugging
 *
 * This function provides detailed information about tasks/threads in the system,
 * including their current state, priority, runtime statistics, and stack information.
 * It also generates call stacks for each task/thread to help with debugging.
 *
 * \note This function is only available when using FreeRTOS or ThreadX RTOS
 * \warning If SYS_DEBUG_MAX_TASKS_NB is too small, the task list may be incomplete
 */
void sys_dump_task_stats(void);
