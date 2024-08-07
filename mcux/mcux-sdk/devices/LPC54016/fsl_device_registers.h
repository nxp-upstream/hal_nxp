/*
 * Copyright 2014-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __FSL_DEVICE_REGISTERS_H__
#define __FSL_DEVICE_REGISTERS_H__

/*
 * Include the cpu specific register header files.
 *
 * The CPU macro should be declared in the project or makefile.
 */
#if (defined(CPU_LPC54016JBD100) || defined(CPU_LPC54016JBD208) || defined(CPU_LPC54016JET100) || \
    defined(CPU_LPC54016JET180))

#define LPC54016_SERIES

/* CMSIS-style register definitions */
#include "LPC54016.h"
/* CPU specific feature definitions */
#include "LPC54016_features.h"

#else
    #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
