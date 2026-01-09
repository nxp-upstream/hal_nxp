/* -------------------------------------------------------------------------- */
/*                        Copyright 2023, 2025 NXP                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdbool.h>

#include "fwk_platform_reset.h"

#if defined(gPlatResetMethod_c) && (gPlatResetMethod_c == gUseResetByDeepPowerDown_c)
/* SDK drivers */
#include "fsl_wuu.h"
#include "fsl_lptmr.h"
#include "fsl_cmc.h"
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */
#define LPTMR_LOW_POWER_ISO_DOMAINS (0x7U)
#define MILLISECONDS_TO_32kTICKS(x) ((x)*4096u / 125u)
#define SECONDS_TO_32kTICKS(x)      ((x)*32768u)

/* Program wake reset after 10ms */
#define RESET_WAKE_DELAY MILLISECONDS_TO_32kTICKS(10u)

/* Binding beetween WUU register and LPTMR modules */
#define PLATFORM_WUU_MOD_LPTMR_IDX 0u

#define TS_READ_ADDR ((volatile uint64_t *)(void *)TSTMR0)

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

#if defined(gPlatResetMethod_c) && (gPlatResetMethod_c == gUseResetByDeepPowerDown_c)
static const cmc_power_domain_config_t CmcDeepPowerDownModeCfg = {
    .clock_mode = kCMC_GateAllSystemClocksEnterLowPowerMode,
    /* force main and wake domain in deep power down mode */
    .main_domain = kCMC_DeepPowerDown,
    .wake_domain = kCMC_DeepPowerDown,
};
#endif

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

static bool IsTimeoutExpired(uint64_t timestamp, uint64_t delayUs)
{
    volatile uint64_t now;
    uint64_t          duration;

    /* A complete read operation should include both TSTMR LOW and HIGH reads. If a HIGH read does not follow a LOW
     * read, then any other Time Stamp value read will be locked at a fixed value. The TSTMR LOW read should occur
     * first, followed by the TSTMR HIGH read.  */
    now = *TS_READ_ADDR;

    if (now < timestamp)
    {
        /* Handle counter wrapping */

        duration = ((uint64_t)UINT64_MAX) - timestamp + now;
    }
    else
    {
        duration = now - timestamp;
    }
    return (duration >= delayUs);
}

static void WaitTimeout(uint64_t timestamp, uint64_t delayUs)
{
    while (!(IsTimeoutExpired(timestamp, delayUs)))
    {
    }
}

static void DelayUs(uint64_t delayUs)
{
    /* PLATFORM_Delay() is similar to PLATFORM_WaitTimeout() but timestamp is taken right now */
    WaitTimeout(*TS_READ_ADDR, delayUs);
}

#if defined(gPlatResetMethod_c) && \
    ((gPlatResetMethod_c == gUseResetByLvdForce_c) || (gPlatResetMethod_c == gUseResetByDeepPowerDown_c))
static void PLATFORM_DisableAllIrqs(void)
{
    for (uint8_t irq = 0u; irq <= (NUMBER_OF_INT_VECTORS - 16u); irq++)
    {
        NVIC_DisableIRQ((IRQn_Type)irq);
        NVIC_ClearPendingIRQ((IRQn_Type)irq);
    }

    SysTick->CTRL = 0u;
    NVIC_DisableIRQ(SysTick_IRQn);
    NVIC_ClearPendingIRQ(SysTick_IRQn);
}

static void PLATFORM_ShutdownRadio(void)
{
    /* Reset all RFMC registers and put the NBU CM3 in reset */
    RFMC->CTRL |= RFMC_CTRL_RFMC_RST(0x1U);
    /* Wait for a few microseconds before releasing the NBU reset,
     * without this the system may hang in the loop waiting for FRO clock valid */
    DelayUs(31u);
    /* Release RFMC / NBU reset */
    RFMC->CTRL &= ~RFMC_CTRL_RFMC_RST_MASK;

    /* NBU was probably in low power before the RFMC reset, so we need to wait for the FRO clock to be valid before
     * accessing RF_CMC */
    while ((RFMC->RF2P4GHZ_STAT & RFMC_RF2P4GHZ_STAT_FRO_CLK_VLD_STAT_MASK) == 0U)
    {
        ;
    }

    /* Configure the RF_CMC1 where the NBU, FRO and flash are not used */
    RF_CMC1->RADIO_LP |= RF_CMC_RADIO_LP_SHUTDOWN;

    /* Force low power entry request to the radio domain */
    RFMC->RF2P4GHZ_CTRL |= RFMC_RF2P4GHZ_CTRL_LP_ENTER(0x1U);
}
#endif /* (gPlatResetMethod_c == gUseResetByLvdForce_c) || (gPlatResetMethod_c == gUseResetByDeepPowerDown_c) */

#if defined(gPlatResetMethod_c) && (gPlatResetMethod_c == gUseResetByDeepPowerDown_c)
static void PLATFORM_DisableWakeSources(void)
{
    WUU0->PE1  = 0U;
    WUU0->PE2  = 0U;
    WUU0->ME   = 0U;
    WUU0->DE   = 0U;
    WUU0->PDC1 = 0U;
    WUU0->PDC2 = 0U;
    WUU0->FDC &= ~(WUU_FDC_FILTC1_MASK | WUU_FDC_FILTC2_MASK);
    WUU0->PMC = 0U;
    WUU0->FMC = 0U;
    /* Wipe clean WUU PF status bit before resetting because the DeepPowerDown reset does not clear those and
     * they might have raised at this stage */
    /* WUF1 bits [0..15] and WUF2 bits [27..28] are cleared by W1C */
    uint32_t reg_val = WUU0->PF;
    WUU0->PF         = reg_val;

    WUU0->FILT |= (WUU_FILT_FILTF1_SHIFT | WUU_FILT_FILTF2_SHIFT); /* 2 bits cleared by W1C */
}

static void PLATFORM_DisableAndClearLpTmr(uint8_t lptmr_mask)
{
    LPTMR_Type *lptmr_inst[] = LPTMR_BASE_PTRS;

    for (uint8_t i = 0; i < sizeof(lptmr_inst) / sizeof(LPTMR_Type *); i++)
    {
        if ((lptmr_mask & (uint8_t)(1u << i)) != 0u)
        {
            volatile uint32_t reg;
            reg = lptmr_inst[i]->CSR;
            reg &= ~LPTMR_CSR_TEN_MASK;
            /* Keep W1C bits of the CSR register */
            reg |= LPTMR_CSR_TCF_MASK;
            lptmr_inst[i]->CSR = reg;
        }
    }
}

static void PLATFORM_LaunchLpTmrWake(uint32_t nb_32kticks_to_reset)
{
    lptmr_config_t lptmrConfig;

    LPTMR_GetDefaultConfig(&lptmrConfig);
    lptmrConfig.prescalerClockSource = (lptmr_prescaler_clock_select_t)2u;

    /* Initialize the LPTMR */
    LPTMR_Init(LPTMR0, &lptmrConfig);

    LPTMR_SetTimerPeriod(LPTMR0, nb_32kticks_to_reset);
    LPTMR_EnableInterrupts(LPTMR0, (uint32_t)kLPTMR_TimerInterruptEnable);
    LPTMR_StartTimer(LPTMR0);
    WUU_SetInternalWakeUpModulesConfig(WUU0, PLATFORM_WUU_MOD_LPTMR_IDX, kWUU_InternalModuleInterrupt);

    (void)EnableIRQ(LPTMR0_IRQn);
}

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

void PLATFORM_ForceDeepPowerDownReset(void)
{
    (void)__set_BASEPRI(0);
    PLATFORM_DisableAllIrqs();

    PLATFORM_ShutdownRadio();

    /* *Wait for 500us for radio to shutdown */
    DelayUs(500U);

    /* Cancel all wake sources */
    PLATFORM_DisableWakeSources();

    /* prevent spurious LPTMR1 wake since it does not have a specific WUU Module mask  */
    PLATFORM_DisableAndClearLpTmr((1u << 1u) | (1u << 0u));

    PLATFORM_LaunchLpTmrWake(RESET_WAKE_DELAY);

    CMC_SetPowerModeProtection(CMC0, (uint32_t)kCMC_AllowAllLowPowerModes);
    CMC_EnterLowPowerMode(CMC0, &CmcDeepPowerDownModeCfg);

    /* Deliberate infinite loop : should never be reached */
    while (0 == 0)
    {
        __NOP();
    }
}

void PLATFORM_CheckAndForceDeepPowerDownResetOnResetPin(void)
{
    uint32_t val = CMC_GetStickySystemResetStatus(CMC0);
    if ((val & CMC_SRS_PIN_MASK) != 0u)
    {
        PLATFORM_ForceDeepPowerDownReset();
    }
}
#endif /* (gPlatResetMethod_c == gUseResetByDeepPowerDown_c) */

#if defined(gPlatResetMethod_c) && (gPlatResetMethod_c == gUseResetByLvdForce_c)
void PLATFORM_ForceLvdReset(void)
{
    (void)__set_BASEPRI(0);
    PLATFORM_DisableAllIrqs();

    PLATFORM_ShutdownRadio();

    /* *Wait for 500us for radio to shutdown */
    DelayUs(500U);

    /* Allow write to SPC_TEST */
    *((volatile uint32_t *)SPC_TRIM_LOCK) = 0x5a5a0001u;
    /* Cause LVD reset */
    *((volatile uint32_t *)SPC_TEST_ADDR) |= 0x00000001u;

    while (0 == 0)
    {
        __NOP();
    }
}

void PLATFORM_ForceLvdResetFromResetPin(void)
{
    uint32_t val = CMC_GetStickySystemResetStatus(CMC0);
    if ((val & CMC_SRS_PIN_MASK) != 0u)
    {
        PLATFORM_ForceLvdReset();
    }
}
#endif

void PLATFORM_NvicSystemReset(void)
{
    /* Disable IRQ using PRIMASK */
    __disable_irq();
    DelayUs(500U);

    NVIC_SystemReset();
}

void PLATFORM_ResetCpu(void)
{
#if defined(gPlatResetMethod_c) && (gPlatResetMethod_c == gUseResetByLvdForce_c)
    PLATFORM_ForceLvdReset();
#elif defined(gPlatResetMethod_c) && (gPlatResetMethod_c == gUseResetByDeepPowerDown_c)
    PLATFORM_ForceDeepPowerDownReset();
#else
    PLATFORM_NvicSystemReset();
#endif
}