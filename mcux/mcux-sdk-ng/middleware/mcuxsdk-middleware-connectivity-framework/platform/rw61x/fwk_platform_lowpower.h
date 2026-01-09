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

#include <stdint.h>
#include "fsl_pm_device.h"

/* -------------------------------------------------------------------------- */
/*                                Public macros                               */
/* -------------------------------------------------------------------------- */

#define PLATFORM_WFI_STATE             PM_LP_STATE_PM1
#define PLATFORM_SLEEP_STATE           PM_LP_STATE_PM2
#define PLATFORM_DEEP_SLEEP_STATE      PM_LP_STATE_PM2
#define PLATFORM_POWER_DOWN_STATE      PM_LP_STATE_PM3
#define PLATFORM_DEEP_POWER_DOWN_STATE PM_LP_STATE_PM4

/* No constraints in WFI mode, all peripherals are available */
#define PLATFORM_WFI_CONSTRAINTS 0

/* No specific constraints necessary for Sleep (PM2)
 * RAM cannot be shutdown in this mode
 */
#define PLATFORM_SLEEP_CONSTRAINTS 0

/* No specific constraints necessary for DeepSleep (PM2)
 * RAM cannot be shutdown in this mode
 */
#define PLATFORM_DEEP_SLEEP_CONSTRAINTS 0

/*!
 * RAM retention select for PowerDown (PM3):
 * 0 -> Full RAM retention(default)
 * 1 -> 512k RAM retention
 * >1 -> No RAM retention
 *
 */
#ifndef APP_PM3_RAM_RET_SEL
#define APP_PM3_RAM_RET_SEL 0
#endif

#if defined(APP_PM3_RAM_RET_SEL) && (APP_PM3_RAM_RET_SEL == 0)
/* Full RAM retention for PowerDown (PM3)*/
#define PLATFORM_POWER_DOWN_CONSTRAINTS                                                                        \
    7, PM_RESC_SRAM_0K_384K_RETENTION, PM_RESC_SRAM_384K_448K_RETENTION, PM_RESC_SRAM_448K_512K_RETENTION,     \
        PM_RESC_SRAM_512K_640K_RETENTION, PM_RESC_SRAM_640K_896K_RETENTION, PM_RESC_SRAM_896K_1216K_RETENTION, \
        PM_RESC_CAU_SOC_SLP_REF_CLK_ON
#elif defined(APP_PM3_RAM_RET_SEL) && (APP_PM3_RAM_RET_SEL == 1)
/* 512k RAM retention for PowerDown (PM3) */
#define PLATFORM_POWER_DOWN_CONSTRAINTS                                                                    \
    4, PM_RESC_SRAM_0K_384K_RETENTION, PM_RESC_SRAM_384K_448K_RETENTION, PM_RESC_SRAM_448K_512K_RETENTION, \
        PM_RESC_CAU_SOC_SLP_REF_CLK_ON
#else
/* No RAM retention for PowerDown (PM3) */
#define PLATFORM_POWER_DOWN_CONSTRAINTS 1, PM_RESC_CAU_SOC_SLP_REF_CLK_ON
#endif

/* No specific constraints necessary for DeepPowerDown (PM4)
 * All RAM are shutdown in this mode
 */
#define PLATFORM_DEEP_POWER_DOWN_CONSTRAINTS 0

/* Macro for Platform RTC handler maximum number */
#define PLATFORM_RTC_HANDLE_MAX 1U

/* -------------------------------------------------------------------------- */
/*                              Public type definition                        */
/* -------------------------------------------------------------------------- */
/*! \brief The handle for Platform RTC */
struct _platform_rtc_handle;

/*! \brief Define Callback function for Platform RTC.
 *
 * handle: Pointer to the Platform RTC handle.
 * userData: The userData registered.
 */
typedef void (*platform_rtc_callback_t)(struct _platform_rtc_handle *handle);

/*! \brief Platform RTC handle structure */
typedef struct _platform_rtc_handle
{
    uint8_t                 index;    /*!< Platform RTC handler index */
    platform_rtc_callback_t callback; /*!< Callback function. Invoked interrupt happens. */
    void                   *userData; /*!< Callback function parameter */
} platform_rtc_handle_t;

/* -------------------------------------------------------------------------- */
/*                              Public prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Initialize platform specific ressources for low power support
 *
 */
void PLATFORM_LowPowerInit(void);

/*!
 * \brief Initialize a wake up timer
 *        Should be called during low power initialization.
 *
 */
void PLATFORM_InitWakeUpTimer(void);

/*!
 * \brief Start a wake up timer for next tickless idle period
 *        Should be called during low power entry procedure.
 *
 * \param[in] timeOutUs maximum timeout in microsec
 */
void PLATFORM_StartWakeUpTimer(uint64_t timeOutUs);

/*!
 * \brief Stops previously started wake up timer if the tickless period ended
 *         earlier than expected. Should be called after exiting low power.
 *
 */
void PLATFORM_StopWakeUpTimer(void);

/*!
 * \brief Returns current timestamp in us, usually called before and after tickless
 *        period to compute the number of ticks to update RTOS timebase.
 *
 * \return uint64_t Timestamp value in us
 */
uint64_t PLATFORM_GetLowPowerTimestampUs(void);

/*!
 * \brief Converts timestamp values returned by PLATFORM_GetLowPowerTimestamp to
 *        a duration in us and handles counter wrapping.
 *
 * \param[in] enterLowPowerTimestamp Timestamp measured before entering tickless period
 * \param[in] exitLowPowerTimestamp Timestamp measured after exiting tickless period
 * \return uint64_t Computed duration in us
 */
uint64_t PLATFORM_GetLowPowerDurationUs(uint64_t enterLowPowerTimestamp, uint64_t exitLowPowerTimestamp);

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
 * \brief Check which banks need to be retained
 * \note This function is linker script specific.\n
 *       Amelioration handle by this function :\n
 *       - There is a free block at the end of the heap, so if the heap is on
 *       the top of the RAM. No need to retain all banks upper that the last one
 *       used by the heap.
 *
 * \return uint8_t mask of which bank needs to be retained
 */
uint8_t PLATFORM_GetDefaultRamBanksRetained(void);

/*!
 * \brief Set the banks that need to be retained in lowpower
 *
 * \param[in] uint8_t mask of which bank needs to be retained
 */
void PLATFORM_SetRamBanksRetained(uint8_t bank_mask);

/*!
 * \brief  Register a Platform RTC handle.
 *
 * \param[in] handle Platform RTC handle pointer.
 *
 * \return int 0 if success, negative value if error.
 */
int PLATFORM_RegisterRtcHandle(platform_rtc_handle_t *handle);

/*!
 * @}  end of FWK_Platform_LowPower addtogroup
 */
/*!
 * @}  end of FWK_Platform_module addtogroup
 */

#endif /* _FWK_PLATFORM_LOWPOWER_H_ */
