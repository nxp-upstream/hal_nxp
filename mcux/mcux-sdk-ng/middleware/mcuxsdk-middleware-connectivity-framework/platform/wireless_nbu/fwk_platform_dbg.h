/*!
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _PLATFORM_DBG_H_
#define _PLATFORM_DBG_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

/*!
 * \brief  Informs the Host that the NBU is encountering a fault.
 *
 * \return 0 if success
 */
int PLATFORM_Nbu2HostFaultIndication(void);

#ifdef __cplusplus
}
#endif

#endif /* _PLATFORM_DBG_H_ */
