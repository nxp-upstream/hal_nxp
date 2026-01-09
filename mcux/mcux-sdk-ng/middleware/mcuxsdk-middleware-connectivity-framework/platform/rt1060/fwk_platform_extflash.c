/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* RT1060 FLASH driver imposes that all accesses be multiple of 32 bits */
#define PLATFORM_ACCESS_ALIGNMENT_CONSTRAINT_LOG 2u

#include "../Common/fwk_platform_mflash.ch"
