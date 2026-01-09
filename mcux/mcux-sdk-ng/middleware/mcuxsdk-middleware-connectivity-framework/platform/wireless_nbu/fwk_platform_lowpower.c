/* -------------------------------------------------------------------------- */
/*                        Copyright 2021-2023, 2025 NXP                       */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdbool.h>

#include "fwk_config.h"
#include "fsl_common.h"
#include "ll_types.h"
#include "fwk_platform_lowpower.h"
#include "fwk_platform.h"
#include "fwk_rf_sfc.h"
#include "controller_api_ll.h"
#include "fwk_debug.h"
#include "fwk_workq.h"
#include "fwk_platform_ics.h"
#if defined(gPlatformEnableDcdcOnNbu_d) && (gPlatformEnableDcdcOnNbu_d == 1)
#include "fwk_platform_dcdc.h"
#endif

#if defined(PHY_15_4_LOW_POWER_ENABLED) && (PHY_15_4_LOW_POWER_ENABLED == 1)
extern bool PHY_XCVR_AllowLowPower(void);
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */
#define BLE_MINIMAL_SLEEP_TIME_ALLOWED         16U
#define ST_INIT                                0x11U
#define HANDLE_INIT                            0x000EU
#define PLATFORM_SWITCH_SLEEP_CLOCK_TIMEOUT_US 200U

#define PLATFORM_BTRTU1_ISR_ADDR 0xA8009424U

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */
static void PLATFORM_HandleLowPowerEntry(void);
static void PLATFORM_HandleWFI(void);
static int  PLATFORM_LowPowerModeAllowed(void);
static bool PLATFORM_IsRemoteAllowingLowPower(void);
static bool PLATFORM_IsBleAllowingLowPower(uint32_t *outSleepTime);
#if defined(PHY_15_4_LOW_POWER_ENABLED) && (PHY_15_4_LOW_POWER_ENABLED == 1)
static bool PLATFORM_Is_15_4_AllowingLowPower(void);
#endif
static void PLATFORM_RemoteLowPowerIndication(bool enter);
static void PLATFORM_ConfigureRamRetention(void);
static int  PLATFORM_SwitchSleepClockSource(bool switchTo32k);
static void PLATFORM_XtalWarningIndicationWorkHandler(fwk_work_t *work);

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */
static bool       initialized                  = false;
static uint8_t    chipRevision                 = 0xFFU;
static uint8_t    delayLpoCycle                = 0x3U;
static uint32_t   bleMinimalSleepTimeAllowedHs = BLE_MINIMAL_SLEEP_TIME_ALLOWED;
static fwk_work_t xtal_warning_ind_work        = {
           .handler = PLATFORM_XtalWarningIndicationWorkHandler,
};

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

#if defined(gPlatformLowpowerEnableWakeUpInterrupt_d) && (gPlatformLowpowerEnableWakeUpInterrupt_d == 1)
void T1_INT_IRQHandler(void)
{
    /* Clear the BTRTU timer 1 interrupt*/
    *(uint32_t *)PLATFORM_BTRTU1_ISR_ADDR &= ~(BTRTU1_BTRTU1_ISR_T1_INT_MASK);
}
#endif

void PLATFORM_LowPowerInit(void)
{
    if (initialized == false)
    {
        /* Retrieve current chip revision (required to perform extra check on
         * A0). 0xFF means the chip revision hasn't been received yet, so it
         * blocks until it is received */
        do
        {
            chipRevision = PLATFORM_GetChipRevision();
        } while (chipRevision == 0xFFU);

        /* This is required for the bt_clk_req signal to be asserted when exiting
         * low power */
        BTU2_REG->BTU_RIF_BLE_CLK_CTRL |= BTU2_REG_BTU_RIF_BLE_CLK_CTRL_BLE_CLK_REQ_EARLY_ASSERT(0x1);

        BLE2_REG->BLE_REG_TMR_WAKEUP_DELAY_LPO_CYCLES = delayLpoCycle;

        /* Enable interrupt of the XTAL ready, necessary to read instant value of XTAL_RDY */
        RF_CMC1->IRQ_CTRL |= RF_CMC1_IRQ_CTRL_RDY_IE_MASK;

#if defined(gPlatformLowpowerEnableWakeUpInterrupt_d) && (gPlatformLowpowerEnableWakeUpInterrupt_d == 1)
        /* Initialize BTRTU timer 1 interrupt (classic bluetooth interrupt) that is not used on this platform. It will
         * be triggered by PLATFORM_RemoteActiveReq() on host core each time it needs to access to NBU power domain */
        BTRTU1->BTRTU1_TIMER1_LEN = 1U;
        BTRTU1->BTRTU1_IMR |= BTRTU1_BTRTU1_IMR_T1_INT_MASK;
        NVIC_EnableIRQ(T1_INT_IRQn);
#endif
        /* WorkQ used to schedule warning/error indications to Host */
        if (WORKQ_InitSysWorkQ() < 0)
        {
            assert(0);
        }
        initialized = true;
    }

    PWR_DBG_LOG("chipRevision: %x", chipRevision);
}

void PLATFORM_EnterLowPower(void)
{
    uint32_t irqMask      = DisableGlobalIRQ();
    int      stateAllowed = PLATFORM_LowPowerModeAllowed();
    if (stateAllowed == 0)
    {
        /* Indicate remote CPU the radio is going to low power */
        PLATFORM_RemoteLowPowerIndication(true);

        /* Check and update the XTAL32M CDAC if needed */
        PLATFORM_UpdateXtal32MTrim();

        /* Configure RAM retention */
        PLATFORM_ConfigureRamRetention();

        /* Execute low power entry procedure */
        PLATFORM_HandleLowPowerEntry();

        /* Indicate remote CPU the radio is active */
        PLATFORM_RemoteLowPowerIndication(false);
    }
    else if (stateAllowed == 1)
    {
        // PWR_DBG_LOG("WFI only is allowed");

        PLATFORM_HandleWFI();
    }
    else
    {
        /* Neither lowpower nor WFI is authorized, it will loop in Idle until one is authorized */
    }

    EnableGlobalIRQ(irqMask);
}

void PLATFORM_SetWakeupDelay(uint8_t wakeupDelayReceivedFromHost)
{
    delayLpoCycle = wakeupDelayReceivedFromHost;
    /* Configure BLE timer wakeup delay of 3.2Khz period */
    BLE2_REG->BLE_REG_TMR_WAKEUP_DELAY_LPO_CYCLES = delayLpoCycle;

    /* update variable with wthe wape time of the 32 mHz crystal and few half slot of margin to ensure sleeping and
     * wakeup timings */
    bleMinimalSleepTimeAllowedHs = wakeupDelayReceivedFromHost + 6U;
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Starts the low power entry procedure
 *
 */

static void PLATFORM_HandleLowPowerEntry(void)
{
    /* Save FRO192M settings before changing it for lowpower */
    uint32_t fro192M_clock_ctrl = FRO192M0->FROCCSR;
    uint32_t fro192M_frodiv     = FRO192M0->FRODIV;

    /* Force sleep clock source to 32k */
    if (PLATFORM_SwitchSleepClockSource(true) == 0)
    {
#if defined(gPlatformEnableDcdcOnNbu_d) && (gPlatformEnableDcdcOnNbu_d == 1)
        /* Disable SPC high power mode */
        PLATFORM_EnableSpcHighPowerMode(false);
#endif

        /* Disable and clear Systicks */
        SysTick->CTRL = 0U;
        SysTick->VAL  = SysTick->LOAD;

        /* Clear pending status of the systick interrupt to avoid having an unrequired wakeup if the systick was pending
         * before disabling it */
        SCB->ICSR |= SCB_ICSR_PENDSTCLR_Msk;

        SCB->SCR &= ~SCB_SCR_SLEEPONEXIT_Msk;
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

        /* update sleep entry timestamp: required to know if native clock is valid after wakeup (HW issue: LL-2953) */
        LL_API_UpdateLastNativeClkBeforeSleep();

        /* Request low power entry to RFMC */
        RF_CMC1->RADIO_LP |= RF_CMC1_RADIO_LP_SLEEP_EN_MASK;

        /* The host allows the NBU to downgrade its frequency to 16MHz
         * So we can select the 16MHz range and use the highest divider */
        FRO192M0->FROCCSR = 0U;
        FRO192M0->FRODIV  = FRO192M_FRODIV_FRODIV_MASK;

        /* WFI will trigger low power entry procedure */
        __DSB();
        __WFI();
        __ISB();

        /* Needs to be cleared first after exiting lowpower (HW issue: MCSE-484) */
        SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
        __ISB();

        /* Restore previous CPU frequency */
        FRO192M0->FROCCSR = fro192M_clock_ctrl;
        FRO192M0->FRODIV  = fro192M_frodiv;

        /* Unset bit to prevent lowpower now */
        RF_CMC1->RADIO_LP &= ~RF_CMC1_RADIO_LP_SLEEP_EN_MASK;

        /* Re-enable systicks */
        SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
#if defined(gPlatformEnableDcdcOnNbu_d) && (gPlatformEnableDcdcOnNbu_d == 1)
        /* Enable SPC high power mode */
        PLATFORM_EnableSpcHighPowerMode(true);
#endif

        if ((RF_CMC1->IRQ_CTRL & RF_CMC1_IRQ_CTRL_XTAL_RDY_MASK) == 0U)
        {
            /* This is a critical section. avoid calling RPMSG which may call OS APIs in here */
            /* Postpone the indication and use workqueue to notify the host that the 32MHz crystal is not ready after
             * the NBU wakeup */
            if (WORKQ_Submit(&xtal_warning_ind_work) < 0)
            {
                assert(0);
            }
            /* Wait for the XTAL to be ready before running anything else */
            while ((RF_CMC1->IRQ_CTRL & RF_CMC1_IRQ_CTRL_XTAL_RDY_MASK) == 0U)
            {
            }
        }
    }

    /* Set sleep clock source to auto */
    PLATFORM_SwitchSleepClockSource(false);
}

/*!
 * \brief Handles Entry/Exit WFI to save minimal amount of power for short period of time
 *
 */
static void PLATFORM_HandleWFI(void)
{
    uint32_t fro192M_clock_ctrl = FRO192M0->FROCCSR;
    uint32_t fro192M_frodiv     = FRO192M0->FRODIV;

    /* Make sure core Deep Sleep is disabled */
    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;

    if (PLATFORM_GetFrequencyConstraintFromHost() == 0U)
    {
        /* The host allows the NBU to downgrade its frequency to 16MHz
         * So we can select the 16MHz range and use the highest divider */
        FRO192M0->FROCCSR = 0U;
        FRO192M0->FRODIV  = FRO192M_FRODIV_FRODIV_MASK;

        /* Enter simple WFI to save minimal power */
        __DSB();
        __WFI();
        __ISB();

        /* Restore previous CPU frequency */
        FRO192M0->FROCCSR = fro192M_clock_ctrl;
        FRO192M0->FRODIV  = fro192M_frodiv;
    }
    else
    {
        /* Enter simple WFI to save minimal power */
        __DSB();
        __WFI();
        __ISB();
    }
}

/*!
 * \brief Checks from various sources if the radio can enter low power
 *
 * \return 0  : lowpower allowed
 * \return 1  : WFI allowed
 * \return -1 : Neither lowpower nor WFI is allowed
 */
static int PLATFORM_LowPowerModeAllowed(void)
{
    int      ret          = 0;
    uint32_t bleSleepTime = 0U;

    do
    {
        if (initialized == false)
        {
            /* Do not allow low power if the module hasn't been initialized */
            ret = 1;
            break;
        }
        else if (PLATFORM_IsBleAllowingLowPower(&bleSleepTime) == false)
        {
            if (bleSleepTime > bleMinimalSleepTimeAllowedHs)
            {
                /* Disallow WFI when the LL sleep time is large enough but the LL is still not ready for deep sleep
                 * When the LL is done with an activity, the sleep time can be higher than bleMinimalSleepTimeAllowedHs
                 * meaning we can go to deep sleep, but the LL sched still needs to update its internal state machine so
                 * LL_API_SCHED_IsSleepAllowed can return true
                 * In such case, if we go to WFI, then we will stay in WFI until the next interrupt, even if we could
                 * already go to deep sleep
                 * This condition helps to avoid this case and will let the device loop in idle until the LL sched is
                 * correctly updated */
                ret = -1;
            }
            else
            {
                /* BLE sleep is not allowed or sleep time not large enough */
                ret = 1;
            }
            break;
        }
#if defined(PHY_15_4_LOW_POWER_ENABLED) && (PHY_15_4_LOW_POWER_ENABLED == 1)
        else if (PLATFORM_Is_15_4_AllowingLowPower() == false)
        {
            /* 15.4 PHY may not be ready for low power */
            ret = 1;
            break;
        }
#endif
        else if (PLATFORM_IsRemoteAllowingLowPower() == false)
        {
            /* Remote CPU can prevent low power */
            ret = 1;
            break;
        }
        else if (SFC_IsBusy() == true)
        {
            ret = 1;
            break;
        }
        else if (SFC_IsMeasureAvailable() == true)
        {
            ret = -1;
            break;
        }
    } while (false);

    return ret;
}

/*!
 * \brief Checks if the remote CPU allows radio low power
 *
 * \return true
 * \return false
 */
static bool PLATFORM_IsRemoteAllowingLowPower(void)
{
    bool ret = true;

    do
    {
        if ((RF_CMC1->RADIO_LP & RF_CMC1_RADIO_LP_BLE_WKUP_MASK) != 0U)
        {
            /* Remote CPU can disallow CM3 to go to low power by setting the following
             * bit */
            ret = false;
            break;
        }
    } while (false);

    return ret;
}

/*!
 * \brief Checks if BLE LL allows radio low power
 *
 * \return true
 * \return false
 */
static bool PLATFORM_IsBleAllowingLowPower(uint32_t *outSleepTime)
{
    bool ret = true;

    do
    {
        uint8_t  sleepAllowed = LL_API_SCHED_IsSleepAllowed();
        uint32_t sleepTime    = LL_API_SCHED_GetSleepTime();
#if defined(gPlatformLowpowerCheckHciPendingCommand) && (gPlatformLowpowerCheckHciPendingCommand == 1)
        uint8_t pendingCmd = LL_API_BLE_HCI_GetNofPendingCommand();
#endif

        if (outSleepTime != NULL)
        {
            *outSleepTime = sleepTime;
        }

        if (sleepAllowed == 1u)
        {
            PWR_DBG_LOG("Slp allowed, SleepTime=%d pendingCmd=%d", sleepTime, pendingCmd);
        }

        if (sleepAllowed != 1)
        {
            // PWR_DBG_LOG("sleepAllowed %x", sleepAllowed);
            ret = false;
            break;
        }
        else if (sleepTime <= bleMinimalSleepTimeAllowedHs)
        {
            ret = false;
            break;
        }
#if defined(gPlatformLowpowerCheckHciPendingCommand) && (gPlatformLowpowerCheckHciPendingCommand == 1)
        else if (pendingCmd > 0U)
        {
            /* Some HCI event are not sent directly when receiving an HCI command
             * The HCI task delays the HCI event and increments the number of pending
             * commands. This should be used to disallow low power so the Host doesnt'
             * wait for the HCI event. */
            PWR_DBG_LOG("pendingCmd %x", pendingCmd);
            ret = false;
            break;
        }
#endif
    } while (false);

    return ret;
}

#if defined(PHY_15_4_LOW_POWER_ENABLED) && (PHY_15_4_LOW_POWER_ENABLED == 1)
/*!
 * \brief Checks if 15.4 LL allows radio low power
 *
 * \return true
 * \return false
 */
static bool PLATFORM_Is_15_4_AllowingLowPower(void)
{
    return PHY_XCVR_AllowLowPower();
}
#endif

/*!
 * \brief Indicates to remote CPU if the radio is entering or exiting low power
 *
 * \param[in] enter true to indicate low power entry, false to indicate low
 *                  power exit
 */
static void PLATFORM_RemoteLowPowerIndication(bool enter)
{
    static uint32_t lowPowerEntryNb = 0U;

    if (enter == true)
    {
        /* CM3 indicates to CM33 it's going to low power so the CM33 will need
         * to request radio wake up if it needs to access radio domain.
         * WOR registers are not used, so we can use them for this purpose.
         * OR with 0x1U to avoid issue when counter wraps. */
        WOR_REGS->WKUP_TIME = ((++lowPowerEntryNb << 1U) | 0x1U) & WOR_WKUP_TIME_WKUP_TIME_MASK;
    }
    else
    {
        /* Notify LL of the NBU wake up */
        LL_API_NotifyWakeUp();
        /* Ensure API call completes before updating register and notifying application core*/
        __ISB();
        /* Indicate to CM33 the radio is awake, so the CM33 can avoid
         * waiting for the radio domain */
        WOR_REGS->WKUP_TIME = 0U;
    }
}

/*!
 * \brief Configures RAM retention for low power period
 *
 */
static void PLATFORM_ConfigureRamRetention(void)
{
    /* Keep all ram banks in retention,  Set SD_EN (Shutdown enable) bits to zero and DS_EN (Deep Sleep enable) bits to
     * one */
    uint32_t ram_pwr = RF_CMC1_RAM_PWR_DS_EN_MASK;
    ram_pwr &= ~RF_CMC1_RAM_PWR_SD_EN_MASK;
    RF_CMC1->RAM_PWR = ram_pwr;
}

static int PLATFORM_SwitchSleepClockSource(bool switchTo32k)
{
    int      ret = 0;
    uint64_t start;
    uint64_t now;
    uint64_t duration;

    if (switchTo32k == true)
    {
        CIU2->CIU2_LBC_CTRL |= CIU2_CIU2_LBC_CTRL_MAN_SEL_NCO_MASK;

        start = PLATFORM_GetTimeStamp();

        while (CIU2->CIU2_LBC_CTRL & CIU2_CIU2_LBC_CTRL_LPO_CLK_SEL_FSM_MASK)
        {
            now = PLATFORM_GetTimeStamp();
            if (now > start)
            {
                duration = PLATFORM_GetMaxTimeStamp() - now + start;
            }
            else
            {
                duration = start - now;
            }

            if (duration > PLATFORM_SWITCH_SLEEP_CLOCK_TIMEOUT_US)
            {
                ret = -1;
                break;
            }
        }
    }
    else
    {
        CIU2->CIU2_LBC_CTRL &= ~CIU2_CIU2_LBC_CTRL_MAN_SEL_NCO_MASK;
    }

    return ret;
}

static void PLATFORM_XtalWarningIndicationWorkHandler(fwk_work_t *work)
{
    (void)work;
    NbuEvent_t event = {};

    event.eventType = gNbuWarningXtal32MhzNotReadyAtWakeUp;

    if (PLATFORM_NotifyNbuEvent(&event) < 0)
    {
        assert(0);
    }
}
