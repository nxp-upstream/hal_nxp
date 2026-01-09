/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2025 NXP                          */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdbool.h>

#include "fwk_config.h"
#include "fwk_platform.h"
#include "fwk_platform_lowpower.h"
#include "fwk_platform_ics.h"
#include "fwk_debug.h"

/* SDK drivers */
#include "fsl_spc.h"
#include "fsl_wuu.h"
#include "fsl_cmc.h"
#include "fsl_vbat.h"

/* SDK components */
#include "fsl_pm_core.h"
#include "fsl_component_mem_manager.h"

/* FWK services */
#include "FunctionLib.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#define SPC_VD_STAT_CLEAR_MASK                                                                    \
    (SPC_VD_STAT_COREVDD_LVDF_MASK | SPC_VD_STAT_SYSVDD_LVDF_MASK | SPC_VD_STAT_IOVDD_LVDF_MASK | \
     SPC_VD_STAT_COREVDD_HVDF_MASK | SPC_VD_STAT_SYSVDD_HVDF_MASK | SPC_VD_STAT_IOVDD_HVDF_MASK)

#define PLATFORM_LPWKUP_DELAY_10MHz (0xAAU)

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Initializes wake up sources
 *
 */
static void PLATFORM_InitWakeUpSources(void);

/*!
 * \brief Callback registered to SDK Power Manager to get notified of entry/exit of low power modes
 *
 * \param[in] eventType event specifying if we entered or exited from low power mode
 * \param[in] powerState low power mode used during low power period
 * \param[in] data Optional data passed when the callback got registered (not used currently)
 * \return status_t
 */
static status_t PLATFORM_LowPowerCallback(pm_event_type_t eventType, uint8_t powerState, void *data);

/*!
 * \brief Shutdown Radio domain
 *        To be used when the current application is ready to go to RAMOFF
 *
 */
static void PLATFORM_ShutdownRadio(void);

/*!
 * \brief Set low power constraint to the SDK PowerManager
 *
 * \param[in] powerMode power mode ID
 *                      0: WFI
 *                      1: SLEEP
 *                      2: DEEP SLEEP
 *                      3: POWER DOWN
 *                      4: DEEP POWER DOWN
 * \return int32_t int 0 if success, negative if error.
 */
static int32_t PLATFORM_SetLowPowerConstraint(int32_t powerMode);

/*!
 * \brief Release low power constraint to the SDK PowerManager
 *
 * \param[in] powerMode power mode ID
 *                      0: WFI
 *                      1: SLEEP
 *                      2: DEEP SLEEP
 *                      3: POWER DOWN
 *                      4: DEEP POWER DOWN
 * \return int32_t int 0 if success, negative if error.
 */
static int32_t PLATFORM_ReleaseLowPowerConstraint(int32_t powerMode);

void WUU0_IRQHandler(void);

/* -------------------------------------------------------------------------- */
/*                             Private variables                              */
/* -------------------------------------------------------------------------- */
static pm_notify_element_t platformLpNotifyGroup = {
    .notifyCallback = PLATFORM_LowPowerCallback,
    .data           = NULL,
};

static const uint32_t TCM_START_ADDR_tab[] = {
    PLATFORM_BANK_START_ADDR,
};

static const uint32_t TCM_END_ADDR_tab[] = {
    PLATFORM_BANK_END_ADDR,
};

#if defined(gPlatformShutdownEccRamInLowPower) && (gPlatformShutdownEccRamInLowPower > 0)
static const bool TCM_IS_ECC[] = {
    PLATFORM_BANK_IS_ECC,
};

static uint32_t last_bank_mask = ~0u;
#endif /* gPlatformShutdownEccRamInLowPower */

static const spc_power_domain_id_t pd_name_2_id[2U] = {
    [PLATFORM_MainDomain]   = kSPC_PowerDomain0, /*!<  Main Power domain containing the main processor        */
    [PLATFORM_WakeupDomain] = kSPC_PowerDomain1, /*!<  Wake up Power domain containing the wake up peripheral */
};

static const PLATFORM_PowerDomainState_t spc_lp_name_2_pd_state[9U] = {
    [kSPC_SleepWithSYSClockRunning] = PLATFORM_NO_LOWPOWER, /*!<   Power domain has not been in Low power mode       */
    [kSPC_SleepWithSysClockOff]     = PLATFORM_SLEEP_MODE,  /*!<   Power domain has not been in Sleep mode           */
    [kSPC_DeepSleepSysClockOff] = PLATFORM_DEEP_SLEEP_MODE, /*!<   Power domain has not been in Deep Sleep mode      */
    [kSPC_PowerDownWithSysClockOff] = PLATFORM_POWER_DOWN_MODE, /*!<   Power domain has not been in Power Down mode */
    [kSPC_DeepPowerDownWithSysClockOff] =
        PLATFORM_DEEP_POWER_DOWN_MODE, /*!<   Power domain has not been in Deep Power Down mode */
};

static const FwkSrv_LowPowerConstraintCallbacks_t fwkSrvLowPowerConstraintCallbacks = {
    .fwkSrvSetLowPowerConstraint     = PLATFORM_SetLowPowerConstraint,
    .fwkSrvReleaseLowPowerConstraint = PLATFORM_ReleaseLowPowerConstraint,
};

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

void PLATFORM_LowPowerInit(void)
{
    status_t status;

    /* Register the low power Notify callback as high priority (kPM_NotifyGroup2) */
    status = PM_RegisterNotify(kPM_NotifyGroup2, &platformLpNotifyGroup);
    assert(status == kStatus_Success);
    (void)status;

    /* Initialize required wake up sources */
    PLATFORM_InitWakeUpSources();

    /* Clear voltage detect status */
    SPC_ClearVoltageDetectStatusFlag(SPC0, SPC_VD_STAT_CLEAR_MASK);

    /* Set number of SPC timer clock cycles to wait on exit from lowpower mode */
    SPC_SetLowPowerWakeUpDelay(SPC0, PLATFORM_LPWKUP_DELAY_10MHz);

    /* When low power is enabled on the host core, the radio core may need to set/release low power constraints
     * as some resources needed by it are in the host power domain
     * This needs to be done before starting the radio core to avoid any race condition */
    PLATFORM_FwkSrvRegisterLowPowerCallbacks(&fwkSrvLowPowerConstraintCallbacks);
}

void PLATFORM_EnterLowPower(void)
{
    return;
}

void PLATFORM_ExitLowPower(void)
{
    return;
}

void PLATFORM_EnterPowerDown(void)
{
    /* Warning : For power down, it requires gLowpowerPowerDownEnable_d variable to be set to 1 in linker file.
     *    Generate assertion if not the case */
    extern uint32_t gLowpowerPowerDownEnable_d[];
    assert((uint32_t)&gLowpowerPowerDownEnable_d == 1);
    (void)gLowpowerPowerDownEnable_d;

    /* Transmit a message to the nbu via the shared memory to warn it that the host go in power down */
    static bool_t power_down_on_host_message_sent = false;
    if (!power_down_on_host_message_sent)
    {
        PLATFORM_RemoteActiveReq();
        PLATFORM_SetLowPowerFlag(true);
        PLATFORM_RemoteActiveRel();
        power_down_on_host_message_sent = true;
    }

    return;
}

void PLATFORM_ExitPowerDown(void)
{
    return;
}

void PLATFORM_EnterDeepPowerDown(void)
{
    /* Put NBU domain in Deep Power Down */
    PLATFORM_ShutdownRadio();
}

void WUU0_IRQHandler(void)
{
    status_t status;

    // PWR_DBG_LOG("");

    /* The Power Manager will parse all the registered and enabled wake up sources
     * and determine if they triggered the WUU IRQ. If so, it will call each
     * wake up source's callback */
    status = PM_HandleWakeUpEvent();
    assert(status == kStatus_PMSuccess);
    (void)status;

    /* Clear WUU pin status flag */
    WUU_ClearExternalWakeUpPinsFlag(WUU0, WUU_GetExternalWakeUpPinsFlag(WUU0));
}

PLATFORM_status_t PLATFORM_GetLowpowerMode(PLATFORM_PowerDomain_t power_domain, PLATFORM_PowerDomainState_t *pd_state)
{
    spc_power_domain_id_t pd_id  = pd_name_2_id[power_domain];
    PLATFORM_status_t     status = PLATFORM_Successful;

    if (SPC_CheckPowerDomainLowPowerRequest(SPC0, pd_id) == true)
    {
        spc_power_domain_low_power_mode_t spcLowPowermode;
        spcLowPowermode = SPC_GetPowerDomainLowPowerMode(SPC0, pd_id);

        if ((uint32_t)spcLowPowermode >= ARRAY_SIZE(spc_lp_name_2_pd_state))
        {
            status = PLATFORM_Error;
        }
        else
        {
            *pd_state = spc_lp_name_2_pd_state[spcLowPowermode];
        }
    }
    else
    {
        *pd_state = PLATFORM_NO_LOWPOWER;
    }

    return status;
}

int PLATFORM_GetDefaultRamBanksRetained(void)
{
    uint32_t          ram_upper_limit;
    uint32_t          ram_lower_limit;
    int               bank_mask = ~0; // Retain everything by default
    volatile uint32_t heap_end;

    /* Those symbols should be exported by the Linker Script */
    extern uint32_t firmware_ram_upper_limit[];
    extern uint32_t firmware_ram_lower_limit[];
    extern uint32_t __HEAP_end__[];

    /* Some compilers can try to optimize the comparison between two external addresses because they will think that
     * they come from two global values and therefore that it is impossible for them to have the same address, but in
     * our case these values come from our linker. That's why we used a local volatile value to make sure it won't be
     * optimized */
    heap_end = (uint32_t)&__HEAP_end__;

    /* Lower ram limit is not necessarily in the first RAM bank
     * On KW45, the 2 first banks are Code TCM banks, but usually not used */
    ram_lower_limit = (uint32_t)&firmware_ram_lower_limit;

    /* Optimized linker script and memory manager, the heap is placed on the top of the RAM */
    if ((uint32_t)&firmware_ram_upper_limit == heap_end)
    {
        ram_upper_limit = MEM_GetHeapUpperLimit();
    }
    else
    {
        ram_upper_limit = (uint32_t)&firmware_ram_upper_limit;
    }

    /* TCM_ADDR macro are defined in non-secure addresses, in order to do a proper comparison we need to ensure ram
     * limits are also defined in non-secure addresses (bit 28 equal to 0) */
    ram_lower_limit &= ~PLATFORM_ADDRESS_SECURE_MASK;
    ram_upper_limit &= ~PLATFORM_ADDRESS_SECURE_MASK;

    assert(ram_upper_limit > ram_lower_limit);

    /* Go through each selectable RAM bank and check if we can shutdown some
     * of them */
    for (uint8_t i = PLATFORM_SELECT_RAM_RET_START_IDX; i <= PLATFORM_SELECT_RAM_RET_END_IDX; i++)
    {
        if ((TCM_START_ADDR_tab[i] >= ram_upper_limit) || (TCM_END_ADDR_tab[i] <= ram_lower_limit))
        {
            /* This RAM bank is outside current used RAM range, so we can
             * shut it down during low power */
            bank_mask &= ~(1 << i);
        }
    }

    return bank_mask;
}

void PLATFORM_SetRamBanksRetained(uint32_t bank_mask)
{
    bool vbat_ldo_ram_required = ((bank_mask & ((uint32_t)1U << PLATFORM_VBAT_LDORAM_IDX)) != 0u);

    /* Set SRAM retention config handled by the CMC module */
    CMC_PowerOffSRAMLowPowerOnly(CMC0, ~bank_mask);

    /* One RAM bank is handled by VBAT module */
    VBAT_EnableSRAMArrayRetained(VBAT0, vbat_ldo_ram_required);

#if defined(gPlatformShutdownEccRamInLowPower) && (gPlatformShutdownEccRamInLowPower > 0)
    last_bank_mask = bank_mask;
#endif
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Initializes wake up sources
 *
 */
static void PLATFORM_InitWakeUpSources(void)
{
    /* Enable low power timers (LPTMR) as wake up source */
    WUU_SetInternalWakeUpModulesConfig(WUU0, 0U, kWUU_InternalModuleInterrupt);

    /* Enable Radio Async Wakeup request
     * This is needed to correctly wake up SOC XBAR bus when CM3 needs it */
    WUU_SetInternalWakeUpModulesConfig(WUU0, 2U, kWUU_InternalModuleDMATrigger);

    /* WUU Irq interrupt is required for proper wakeup functionality from lowpower */
    NVIC_EnableIRQ(WUU0_IRQn);
}

#if defined(gDbg_Enabled_d) && (gDbg_Enabled_d > 0)
static int lp_nb = 0;
#endif

static void PLATFORM_EnteringLowPowerCb(uint8_t powerState)
{
#if defined(gDbg_Enabled_d) && (gDbg_Enabled_d > 0)
    PWR_DBG_LOG("[%d] evt=%d pwrstate=%d", lp_nb, eventType, powerState);
#endif
    if (powerState >= PLATFORM_DEEP_SLEEP_STATE)
    {
        /* Platform module can implement platform specific methods to execute
         * when entering and exiting any low power mode.
         * Those methods should implement only mandatory procedures for the
         * platform, compatible with any connectivity protocol */

#if defined(gDbg_Enabled_d) && (gDbg_Enabled_d > 0)
        /* NXP logging dump */
#define DUMP_EVERY_X_TIMES 4
        static int count = DUMP_EVERY_X_TIMES;
        if (--count == 0)
        {
            DBG_LOG_DUMP();
            count = DUMP_EVERY_X_TIMES;
        }
#endif

#if 0
        {
            uint8_t mode;
            mode = PM_GetAllowedLowestPowerMode();
            if (mode  == (PLATFORM_DEEP_POWER_DOWN_STATE))
            {
                BOARD_DbgStopLoggingTimer();
            }
        }
#endif

        PLATFORM_EnterLowPower();

        if (powerState == PLATFORM_POWER_DOWN_STATE)
        {
            /* Power gated low power modes often require extra specific
             * entry/exit low power procedures, those should be implemented
             * in the following PLATFORM API */
            PLATFORM_EnterPowerDown();
        }

        if (powerState == PLATFORM_DEEP_POWER_DOWN_STATE)
        {
            /* Perform specific procedures when entering RAMOFF such as
             * powering off the radio domain */
            PLATFORM_EnterDeepPowerDown();
        }
    }
}

static void PLATFORM_ExitingLowPowerLpCb(uint8_t powerState)
{
#if defined(gPlatformEnableFro6MCalLowpower_d) && (gPlatformEnableFro6MCalLowpower_d > 0)
    PLATFORM_PowerDomainState_t wakeup_pd_state = PLATFORM_NO_LOWPOWER;
    /* Exiting low power : read wake power domain state so as to determine
     * whether FRO6M was cut or not */
    if (PLATFORM_GetLowpowerMode(PLATFORM_WakeupDomain, &wakeup_pd_state) == PLATFORM_Successful)
    {
        if (wakeup_pd_state > PLATFORM_NO_LOWPOWER)
        {
            /* FRO6M was cut : calibrate */
            if (PLATFORM_StartFro6MCalibration() < 0)
            {
                assert(0);
                /* might do nothing in release build */
            }
        }
    }
    else
    {
        assert(0);
    }
#endif
    /* kPM_EventExitingSleep */
    if (powerState >= PLATFORM_DEEP_SLEEP_STATE)
    {
        /* Check if Main power domain domain really went to Power down,
         *   powerState variable is just an indication, Lowpower mode could have been skipped by an immediate wakeup
         */
        PLATFORM_PowerDomainState_t main_pd_state = PLATFORM_NO_LOWPOWER;
        if (PLATFORM_GetLowpowerMode(PLATFORM_MainDomain, &main_pd_state) == PLATFORM_Successful)
        {
#if 0
            PLATFORM_PowerDomainState_t   wakeup_pd_state;
            (void)PLATFORM_GetLowpowerMode(PLATFORM_WakeupDomain, &wakeup_pd_state);
            PWR_DBG_LOG("main_pd=%d wakeup_pd=%d", main_pd_state, wakeup_pd_state);
#endif

            if (main_pd_state == PLATFORM_POWER_DOWN_MODE)
            {
                /* Power gated low power modes often require specific
                 * entry/exit low power procedures, those should be implemented
                 * in the following PLATFORM API */
                PLATFORM_ExitPowerDown();
            }
        }
        else
        {
            assert(0);
        }

        // DBG_LOG_WAKEUP_CHECK();

        /* Platform specific procedures to execute when exiting low power mode
         * any low power mode */
        PLATFORM_ExitLowPower();

    } /* if (powerState >= PLATFORM_DEEP_SLEEP_STATE) */

#if defined(gPlatformEnableFro6MCalLowpower_d) && (gPlatformEnableFro6MCalLowpower_d > 0)
    if (wakeup_pd_state > PLATFORM_NO_LOWPOWER)
    {
        if (PLATFORM_EndFro6MCalibration() < 0)
        {
            assert(false);
            /* Might do nothing in release mode */
        }
    }
#endif
    /* Debug Only */
#if defined(gDbg_Enabled_d) && (gDbg_Enabled_d > 0)
    /* On wakeup, display pending interrupts */
    {
        lp_nb++;
        BOARD_DbgCheckIrqPending(false);
    }
#endif
}

static status_t PLATFORM_LowPowerCallback(pm_event_type_t eventType, uint8_t powerState, void *data)
{
    (void)data;

    if (eventType == kPM_EventEnteringSleep)
    {
        PLATFORM_EnteringLowPowerCb(powerState);
    }
    else /* if (eventType == kPM_EventEnteringSleep) */
    {
        PLATFORM_ExitingLowPowerLpCb(powerState);
    }

    return kStatus_Success;
}

static void PLATFORM_ShutdownRadio(void)
{
    /* Reset all RFMC registers and put the NBU CM3 in reset */
    RFMC->CTRL |= RFMC_CTRL_RFMC_RST(0x1U);
    /* Wait for a few microseconds before releasing the NBU reset,
     * without this the system may hang in the loop waiting for FRO clock valid */
    PLATFORM_Delay(31u);
    /* Release NBU reset */
    RFMC->CTRL &= ~RFMC_CTRL_RFMC_RST_MASK;

    /* NBU was probably in low power before the RFMC reset, so we need to wait for the FRO clock to be valid before
     * accessing RF_CMC */
    while ((RFMC->RF2P4GHZ_STAT & RFMC_RF2P4GHZ_STAT_FRO_CLK_VLD_STAT_MASK) == 0U)
    {
        ;
    }

    /* Configure the RF_CMC1 where the NBU, FRO and flash are not used */
    RF_CMC1->RADIO_LP |= RF_CMC1_RADIO_LP_CK(0x2);

    /* Force low power entry request to the radio domain */
    RFMC->RF2P4GHZ_CTRL |= RFMC_RF2P4GHZ_CTRL_LP_ENTER(0x1U);
}

#if defined(gPlatformShutdownEccRamInLowPower) && (gPlatformShutdownEccRamInLowPower > 0)
void MEM_ReinitRamBank(uint32_t startAddress, uint32_t endAddress)
{
    bool     indexFound = false;
    uint32_t startIndex = 0xFFU;
    uint32_t endIndex   = 0xFFU;

    /* This for loop will find the RAM banks which cover the requested address range.
     * The range could be large enough to contain more than one bank */
    for (uint32_t i = PLATFORM_SELECT_RAM_RET_START_IDX; i <= PLATFORM_SELECT_RAM_RET_END_IDX; i++)
    {
        if ((startAddress >= TCM_START_ADDR_tab[i]) && (startAddress <= TCM_END_ADDR_tab[i]))
        {
            /* The start address is contained in this bank */
            startIndex = i;
        }

        if ((endAddress >= TCM_START_ADDR_tab[i]) && (endAddress <= TCM_END_ADDR_tab[i]))
        {
            /* The end address is contained in this bank */
            endIndex = i;
        }

        if ((startIndex != 0xFFU) && (endIndex != 0xFFU))
        {
            /* Both indexes have be found, we can proceed further */
            indexFound = true;
            break;
        }
    }

    if (indexFound == true)
    {
        /* This loop will go through the different RAM banks based on the indexes found
         * right before. If the current bank is an ECC bank and if it has been shutdown
         * during last low power period, then we proceed with the memset to force ECC
         * calculation */
        for (uint32_t i = startIndex; i <= endIndex; i++)
        {
            if (TCM_IS_ECC[i] == true)
            {
                if ((last_bank_mask & ((uint32_t)1U << i)) == 0U)
                {
                    uint32_t size, bankAdressToReinit;

                    size = TCM_END_ADDR_tab[i] - TCM_START_ADDR_tab[i] + 1U;

                    bankAdressToReinit = TCM_START_ADDR_tab[i];

                    /* Write to ECC RAM bank to force ECC calculation
                        Warning : This is mandatory to write word per word (not by byte per byte),  so use a proprietary
                        FuncLib API to make sure the memory set is done by word */
                    FLib_MemSet32Aligned((uint32_t *)bankAdressToReinit, 0U, (size / 4U));

                    /* Remove this bank from the last shutdown during low power as
                     * it has been reinitialized */
                    last_bank_mask |= ((uint32_t)1U << i);
                }
            }
        }
    }
}
#endif /* gPlatformShutdownEccRamInLowPower */

static int32_t PLATFORM_SetLowPowerConstraint(int32_t powerMode)
{
    int32_t  ret = 0;
    status_t st  = kStatus_Success;

    switch (powerMode)
    {
        case 0:
            st = PM_SetConstraints(PLATFORM_WFI_STATE, PLATFORM_WFI_CONSTRAINTS);
            break;

        case 1:
            st = PM_SetConstraints(PLATFORM_SLEEP_STATE, PLATFORM_SLEEP_CONSTRAINTS);
            break;

        case 2:
            st = PM_SetConstraints(PLATFORM_DEEP_SLEEP_STATE, PLATFORM_DEEP_SLEEP_CONSTRAINTS);
            break;

        case 3:
            st = PM_SetConstraints(PLATFORM_POWER_DOWN_STATE, PLATFORM_POWER_DOWN_CONSTRAINTS);
            break;

        case 4:
            st = PM_SetConstraints(PLATFORM_DEEP_POWER_DOWN_STATE, PLATFORM_DEEP_POWER_DOWN_CONSTRAINTS);
            break;

        default:
            ret = -1;
            break;
    }

    if (st != kStatus_Success)
    {
        ret = -1;
    }

    return ret;
}

static int32_t PLATFORM_ReleaseLowPowerConstraint(int32_t powerMode)
{
    int32_t  ret = 0;
    status_t st  = kStatus_Success;

    switch (powerMode)
    {
        case 0:
            st = PM_ReleaseConstraints(PLATFORM_WFI_STATE, PLATFORM_WFI_CONSTRAINTS);
            break;

        case 1:
            st = PM_ReleaseConstraints(PLATFORM_SLEEP_STATE, PLATFORM_SLEEP_CONSTRAINTS);
            break;

        case 2:
            st = PM_ReleaseConstraints(PLATFORM_DEEP_SLEEP_STATE, PLATFORM_DEEP_SLEEP_CONSTRAINTS);
            break;

        case 3:
            st = PM_ReleaseConstraints(PLATFORM_POWER_DOWN_STATE, PLATFORM_POWER_DOWN_CONSTRAINTS);
            break;

        case 4:
            st = PM_ReleaseConstraints(PLATFORM_DEEP_POWER_DOWN_STATE, PLATFORM_DEEP_POWER_DOWN_CONSTRAINTS);
            break;

        default:
            ret = -1;
            break;
    }

    if (st != kStatus_Success)
    {
        ret = -1;
    }

    return ret;
}
