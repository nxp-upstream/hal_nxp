/* -------------------------------------------------------------------------- */
/*                        Copyright 2021-2022, 2024 NXP                       */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_PLATFORM_GENFSK_H_
#define _FWK_PLATFORM_GENFSK_H_

#include "fsl_common.h"

/* -------------------------------------------------------------------------- */
/*                                Public macros                               */
/* -------------------------------------------------------------------------- */

#if !defined(gAppMaxTxPowerDbm_c)
/*!
 * \brief Default max tx power used in case of GenFSK
 *        this is required to correctly configure voltages output
 */
#define gAppMaxTxPowerDbm_c 10
#endif /* gAppMaxTxPowerDbm_c */

/* -------------------------------------------------------------------------- */
/*                              Public prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Low level initialization required for GenFSK
 *
 */
void PLATFORM_InitGenfsk(void);

/*!
 * \brief Configure max TX power in dBm for GenFSK
 *
 * \param[in] max_tx_power Desired max TX power in dBm
 */
void PLATFORM_SetGenfskMaxTxPower(int8_t max_tx_power);

#endif /* _FWK_PLATFORM_GENFSK_H_ */
