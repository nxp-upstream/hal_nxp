/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2024 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_PLATFORM_LOWPOWER_H_
#define _FWK_PLATFORM_LOWPOWER_H_

/*!
 * @addtogroup FWK_Platform_module
 * @{
 */
/*!
 * @addtogroup FWK_Platform_LowPower
 * The FWK_Platform_LowPower module
 *
 * FWK_Platform_LowPower module provides APIs to handle Low Power .
 * @{
 */
/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "EmbeddedTypes.h"
#include "fsl_pm_device.h"

/* -------------------------------------------------------------------------- */
/*                                Public macros                               */
/* -------------------------------------------------------------------------- */

#define PLATFORM_WFI_STATE             PM_LP_STATE_SLEEP
#define PLATFORM_SLEEP_STATE           PM_LP_STATE_SLEEP
#define PLATFORM_DEEP_SLEEP_STATE      PM_LP_STATE_DEEP_SLEEP
#define PLATFORM_POWER_DOWN_STATE      PM_LP_STATE_POWER_DOWN
#define PLATFORM_DEEP_POWER_DOWN_STATE PM_LP_STATE_DEEP_POWER_DOWN

/* In order to set WFI constraint, we need to set the SLEEP constraint with the Bus clock ON
 * This will has the effect to keep the main domain and wakeup domain in active    */
#define PLATFORM_WFI_CONSTRAINTS 1, PM_RESC_BUS_SYS_CLK_ON

#define PLATFORM_SLEEP_CONSTRAINTS 0

#define PLATFORM_DEEP_SLEEP_CONSTRAINTS 0

#define PLATFORM_POWER_DOWN_CONSTRAINTS 0

#define PLATFORM_DEEP_POWER_DOWN_CONSTRAINTS 0

/* -------------------------------------------------------------------------- */
/*                              Public type definition                        */
/* -------------------------------------------------------------------------- */

/*!
 * \brief  type definition for the list of power domains in the device
 *
 */
typedef enum
{
    PLATFORM_MainDomain,   /*!<  Main Power domain containing the main processor        */
    PLATFORM_WakeupDomain, /*!<  Wake up Power domain containing the wake up peripheral */
} PLATFORM_PowerDomain_t;

/*!
 * \brief  type definition for the list of low power mode that a power domain can go inti
 *
 */
typedef enum
{
    PLATFORM_NO_LOWPOWER,          /*!<   Power domain has not been in Low power mode       */
    PLATFORM_SLEEP_MODE,           /*!<   Power domain has not been in Sleep mode           */
    PLATFORM_DEEP_SLEEP_MODE,      /*!<   Power domain has not been in Deep Sleep mode      */
    PLATFORM_POWER_DOWN_MODE,      /*!<   Power domain has not been in Power Down mode      */
    PLATFORM_DEEP_POWER_DOWN_MODE, /*!<   Power domain has not been in Deep Power Down mode */
} PLATFORM_PowerDomainState_t;

/*!
 * \brief  returned status code
 *
 */
typedef enum
{
    PLATFORM_Successful, /*!<  Function reports success        */
    PLATFORM_Error,      /*!<  Function reports Error          */
} PLATFORM_status_t;
/* -------------------------------------------------------------------------- */
/*                              Public prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Initialize platform specific ressources for low power support
 *
 */
void PLATFORM_LowPowerInit(void);

/*!
 * \brief Platform module can implement platform specific methods to execute
 *        when entering and exiting any low power mode. \n
 *        Those methods should implement only mandatory procedures for the
 *        platform, compatible with any connectivity protocol.
 */
void PLATFORM_EnterLowPower(void);

/*!
 * \brief Platform specific procedures to execute when exiting any low power mode
 *
 */
void PLATFORM_ExitLowPower(void);

/*!
 * \brief Power gated low power modes often require specific
 *        entry/exit low power procedures, those should be implemented
 *        in the following API.
 *
 */
void PLATFORM_EnterPowerDown(void);

/*!
 * \brief Power gated low power modes often require specific
 *        entry/exit low power procedures, those should be implemented
 *        in the following API.
 *
 */
void PLATFORM_ExitPowerDown(void);

/*!
 * \brief Specific low power entry procedure when going to Deep Power Down mode (RAMOFF)
 *
 */
void PLATFORM_EnterDeepPowerDown(void);

/*!
 * \brief Get the low power state of a power domain in the previous lowpower period
 * \note Shall be called from the lowpower exit callbacks, state returned after the wakeup
 *          process may no longer be accurate
 *
 * \param[in]  power_domain which we want to obtain the lowpower state
 * \param[out] pd_state Lowpower state
 * \return     PLATFORM_status_t error status
 */
PLATFORM_status_t PLATFORM_GetLowpowerMode(PLATFORM_PowerDomain_t power_domain, PLATFORM_PowerDomainState_t *pd_state);

/*!
 * \brief Check which banks need to be retained
 * \note This function is linker script specific.\n
 *       Amelioration handle by this function :\n
 *       - There is a free block at the end of the heap, so if the heap is on
 *       the top of the RAM. No need to retain all banks upper that the last one
 *       used by the heap.
 *
 * \return uint8_t mask of which bank needs to be retained
 */
int PLATFORM_GetDefaultRamBanksRetained(void);

/*!
 * \brief Set the banks that need to be retained in lowpower
 *
 * \param[in] bank_mask mask of which bank needs to be retained
 */
void PLATFORM_SetRamBanksRetained(uint32_t bank_mask);

/*!
 * @}  end of FWK_Platform_LowPower addtogroup
 */
/*!
 * @}  end of FWK_Platform_module addtogroup
 */

#endif /* _FWK_PLATFORM_LOWPOWER_H_ */
