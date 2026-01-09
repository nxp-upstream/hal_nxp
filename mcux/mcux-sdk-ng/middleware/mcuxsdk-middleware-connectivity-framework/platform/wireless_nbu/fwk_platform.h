/*
 * Copyright 2020-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FWK_PLATFORM_H_
#define _FWK_PLATFORM_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "EmbeddedTypes.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/* -------------------------------------------------------------------------- */
/*                           Public type definitions                          */
/* -------------------------------------------------------------------------- */

#define PLATFORM_MAX_INTERRUPT_PRIORITY         3U
#define PLATFORM_MAX_INTERRUPT_PRIORITY_BASEPRI (PLATFORM_MAX_INTERRUPT_PRIORITY << (8 - __NVIC_PRIO_BITS))
#define PLATFORM_SET_INTERRUPT_MASK()                       \
    __get_BASEPRI();                                        \
    __set_BASEPRI(PLATFORM_MAX_INTERRUPT_PRIORITY_BASEPRI); \
    __DSB();                                                \
    __ISB()
#define PLATFORM_CLEAR_INTERRUPT_MASK(x) \
    __set_BASEPRI(x);                    \
    __DSB();                             \
    __ISB()

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Reset all platform variables to their initial state.
 * This function only resets the software state, no hardware reset is performed.
 * Also, only variables that don't need synchronization with the host will be reset.
 *
 * \note This function is thread-safe but not protected against interrupts
 * with higher priority than PLATFORM_MAX_INTERRUPT_PRIORITY. Do not call
 * this function from higher priority interrupt contexts.
 *
 */
void PLATFORM_ResetContext(void);

/*!
 * \brief  Request main domain to be active
 *
 *  On return from this function, the main domain and all its HW ressources can be accessed safely
 *    until PLATFORM_RemoteActiveRel() is called
 *
 */
void PLATFORM_RemoteActiveReq(void);

/*!
 * \brief  Request main domain to be active
 *
 *  On return from this function, the request to the main domain and all its HW ressources
 *    has been requested
 *
 * \note An additional delay can be required if you want to access to the HW ressources
 *    of the main domain see PLATFORM_RemoteActiveReq() function
 *
 */
void PLATFORM_RemoteActiveReqWithoutDelay(void);

/*!
 * \brief  Release main domain from being active
 *
 *  On return from this function, the main domain and all its HW ressources can not be accessed
 *    if the main domain has turned into lowpower,
 *   Need to call PLATFORM_RemoteActiveReq() for accessing safely to the ressources it contains
 *
 */
void PLATFORM_RemoteActiveRel(void);

/*!
 * \brief Returns the last XTAL32M applied by PLATFORM_UpdateXtal32MTrim().
 * Note: this might not be accurate if the XTAL32M was updated by another
 * API or by the host core. We want to avoid reading directly the RFMC
 * because we would need to wake up the host core, increasing the power consumption.
 *
 * \return trimming value of the Xtal 32MHz
 *
 */
uint8_t PLATFORM_GetXtal32MhzTrim(void);

/*!
 * \brief Register a new XTAL32M trimming value.
 * Note: the trimming value won't be applied immediately, it will only register the value.
 * The new trimming value will be applied by PLATFORM_UpdateXtal32MTrim().
 * We can't update the XTAL32M right now because the radio might be active
 * The XTAL32M trimming must be updated during the optimal window
 *
 * \param[in] trim  trimming value to be set
 *
 */
void PLATFORM_SetXtal32MhzTrim(uint8_t trim);

/*!
 * \brief Apply a new XTAL32M trimming value if a new trimming was registered
 * with PLATFORM_SetXtal32MhzTrim()
 *
 */
void PLATFORM_UpdateXtal32MTrim(void);

/*!
 * \brief Lock the XTAL32M trimming to prevent updates
 *
 * Increments the lock counter to prevent XTAL32M trimming updates
 * through PLATFORM_UpdateXtal32MTrim().
 *
 * \note This function is thread-safe but not protected against interrupts
 * with higher priority than PLATFORM_MAX_INTERRUPT_PRIORITY. Do not call
 * this function from higher priority interrupt contexts.
 */
void PLATFORM_LockXtal32MTrim(void);

/*!
 * \brief Unlock the XTAL32M trimming to allow updates
 *
 * Decrements the lock counter. When the counter reaches zero,
 * XTAL32M trimming updates through PLATFORM_UpdateXtal32MTrim() are allowed.
 *
 * \note This function is thread-safe but not protected against interrupts
 * with higher priority than PLATFORM_MAX_INTERRUPT_PRIORITY. Do not call
 * this function from higher priority interrupt contexts.
 */
void PLATFORM_UnlockXtal32MTrim(void);

/*!
 * \brief  Set chip revision
 *
 * \param[in] chip revision, 0 : A0, 1 : A1
 *
 */
void PLATFORM_SetChipRevision(uint8_t chip_rev);

/*!
 * \brief  Set chip revision
 *
 * \return chip revision, 0 : A0, 1 : A1
 *
 */
uint8_t PLATFORM_GetChipRevision(void);

/*!
 * \brief Returns current timestamp in us
 *
 * \return uint64_t timestamp in us
 */
uint64_t PLATFORM_GetTimeStamp(void);

/*!
 * \brief Returns current timestamp in 32kHz ticks
 *
 * \return uint64_t timestamp (raw TSTMR 32kHz ticks)
 * \note implemented on KW43/MCXW70 platforms not KW45, KW47, MCXW71, MCXW72
 */
uint64_t PLATFORM_Get32KTimeStamp(void);

/*!
 * \brief Returns the max timestamp value that can be returned by PLATFORM_GetTimeStamp
 *        Can be used by the user to handle timestamp wrapping
 *
 * \return uint64_t the max timestamp value
 */
uint64_t PLATFORM_GetMaxTimeStamp(void);

/*!
 * \brief Compute number of microseconds between 2 timestamps expressed in number of 32kHz TSTMR ticks
 *
 * \param [in] timestamp0 start timestamp from which duration is assessed.
 * \param [in] timestamp1 end timestamp till which duration is assessed.
 *
 * \return uint64_t number of microseconds - May return ~0ULL if not implemented.
 *
 *  \note only implemented on platforms having a 32kHz TSTMR instance (KW43/MCXW70)
 *
 */
uint64_t PLATFORM_Get32kTimeStampDeltaUs(uint64_t timestamp0, uint64_t timestamp1);

/*!
 * \brief  wait for the given delay in us
 *
 * \param[in] delayUs time delay in us
 *
 */
void PLATFORM_Delay(uint64_t delayUs);

/*!
 * \brief  wait for the given delay in us starting from
 *  given Timestamp. Timestamp shall be get from PLATFORM_GetTimeStamp()
 *
 * \param[in] timestamp in us
 * \param[in] delayUs time delay in us
 *
 */
void PLATFORM_WaitTimeout(uint64_t timestamp, uint64_t delayUs);

/*!
 * \brief Init and configure FRO192M
 *
 */
void PLATFORM_InitFro192M(void);

/*!
 * \brief Set the nbu frequency constraint for the host and update the core
 *        frequency consequently
 *
 * \param[in] range 0 : 16MHz, 1 : 24MHz, 2 : 32MHz, 3 : 48MHz, 4 : 64MHz
 *
 */
void PLATFORM_SetFrequencyConstraintFromHost(uint8_t freq_constraint);

/*!
 * \brief  Set the nbu frequency constraint for the controller and update the core
 *         frequency consequently
 *
 * \note 64MHz is not supported as you need to ensure that LDO core output voltage is 1.1V if you want to run to this
 *frequency
 *
 * \param[in] range 0 : 16MHz, 1 : 24MHz, 2 : 32MHz, 3 : 48MHz
 *
 */
void PLATFORM_SetFrequencyConstraintFromController(uint8_t freq_constraint);

/*!
 * \brief Returns current frequency constraint set by the host
 *
 * \return uint8_t 0 : 16MHz, 1 : 24MHz, 2 : 32MHz, 3 : 48MHz
 */
uint8_t PLATFORM_GetFrequencyConstraintFromHost(void);

#if (defined(gPlatformUseLptmr_d)) && (gPlatformUseLptmr_d == 1U)

/*!
 * \brief  Initialize Timer Manager
 *
 *    This API will initialize the Timer Manager and the required clocks
 *
 * \return int 0 if success, 1 if already initialized, negative value if error.
 */
int PLATFORM_InitTimerManager(void);

/*!
 * \brief  Deinitialize Timer Manager
 *
 *    This API will deinitialize the Timer Manager
 *
 */
void PLATFORM_DeinitTimerManager(void);

#endif

/*!
 * \brief  get 4 words of information that uniquely identifies the MCU
 *
 * \param[out] aOutUid16B pointer to UID bytes
 * \param[out] pOutLen pointer to UID length
 *
 * \return int 0 if success, negative value if error.
 */
int PLATFORM_GetMCUUid(uint8_t *aOutUid16B, uint8_t *pOutLen);

/*!
 * @brief Configures the SMU DMEM mapping.
 *
 * This function sets the mapping configuration for the SMU (Shared Memory Unit)
 * DMEM (Data Memory) according to the value found in the linker file.
 *
 * @param[in] None
 *
 * @return None
 *
 * @note This function should be called during platform initialization before
 *       accessing SMU DMEM regions.
 */

void PLATFORM_ConfigureSmuDmemMapping(void);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _FWK_PLATFORM_H_ */
