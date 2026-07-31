/**
 * Copyright 2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************
 * EdgeLock Enclave Firmware - this file selects the correct FW for runtime apps
 ******************************************************************************/
#ifndef __ELE_200_FW_H__
#define __ELE_200_FW_H__

#if defined(ELEMU_HAS_LOADABLE_FW) && ELEMU_HAS_LOADABLE_FW

const uint8_t fw[] = {
/* This file is generated during build from the appropriate SB3 binary. */
#include "edgelock_firmware.inc"
};

#endif /* ELEMU_HAS_LOADABLE_FW */

#endif /* __ELE_200_FW_H__ */
