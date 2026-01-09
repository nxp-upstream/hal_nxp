/* -------------------------------------------------------------------------- */
/*                             Copyright 2024 NXP                             */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_PLATFORM_INTFLASH_H_
#define _FWK_PLATFORM_INTFLASH_H_

/*!
 * @addtogroup FWK_Platform_module
 * The FWK_Platform_Intflash module
 *
 * FWK_Platform module provides APIs to set platform parameters.
 * @{
 */
/*!
 * @addtogroup FWK_Platform_Intflash
 * The FWK_Platform_Intflash module
 *
 * FWK_Platform_Intflash module provides APIs to set flash platform parameters.
 * @{
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "EmbeddedTypes.h"

/* -------------------------------------------------------------------------- */
/*                                 Definitions                                */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                        Public functions declaration                        */
/* -------------------------------------------------------------------------- */
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * \brief  Allow interception of Bus Fault handler.
 *         Adhoc handler must be implemented and called from BusFault vector.
 */
void PLATFORM_EnableBusFault(void);

/*!
 * \brief  Sweep range to detect ECC fault infected phrase.
 *
 * \param[in] start_addr start of studied range
 * \param[in] size range size in bytes
 * \return 0 if not fault raised at all.
 *         0xffffffff : ECC fault exists but not in range
 *         address of ECC fault.
 */
uint32_t PLATFORM_SeekForEccFaultsInRange(uint32_t start_addr, uint32_t size);

/*!
 * \brief  Remove ECC fault in faulty sector. Implements the radical way by erasing sector containing fault.
 * This is provided as a sample example with weak linkage so that it can easily but overridden.
 * The ECC fault can be rid of by erasing the sector it is affecting. Yet the whole  NV storage may require a full
 * reformat.
 *
 * \param[in] ecc_fault_addr address of ECC fault
 */
void PLATFORM_TreatEccFault(uint32_t ecc_fault_addr);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*!
 * @}  end of FWK_Platform_Intflash addtogroup
 */
/*!
 * @}  end of FWK_Platform_module addtogroup
 */
#endif /* _FWK_PLATFORM_INTFLASH_H_ */
