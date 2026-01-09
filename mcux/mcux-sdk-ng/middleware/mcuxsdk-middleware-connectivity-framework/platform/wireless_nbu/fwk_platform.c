/*
 * Copyright 2020-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*${header:start}*/
#include "fwk_config.h"
#include "fwk_platform.h"
#include "fwk_debug.h"
#include "nxp2p4_xcvr.h"

#if !defined(BOARD_DBGPLTIOSET)
#define BOARD_DBGPLTIOSET(__x, __y)
#endif

#include "FunctionLib.h"

#if (defined(gPlatformUseLptmr_d)) && (gPlatformUseLptmr_d == 1U)
#include "fsl_component_timer_manager.h"
#endif

/************************************************************************************
*************************************************************************************
* Private type definitions
*************************************************************************************
************************************************************************************/

/** IFR1 - Layout Typedef */
typedef struct
{
    uint8_t RESERVED_0[6160];
    struct
    {
        volatile uint32_t PHRASE[4];
    } SOCTRIM1; /**< SOCTRIM1 IFR field, offset: 0x1810 */
} IFR1_Type;

/** SMU DMEM Configuration Entry Typedef */
typedef struct smu_dmem_config
{
    uint32_t dmem_size;       /**< DMEM size in bytes */
    uint32_t shared_ram_size; /**< Shared RAM size in bytes */
    uint32_t mapping_value;   /**< Corresponding mapping register value */
} smu_dmem_config_t;

/************************************************************************************
*************************************************************************************
* Private macros
*************************************************************************************
************************************************************************************/

#define IFR1_BASE (0x00048000U)
#define IFR1      ((IFR1_Type *)IFR1_BASE)

#define PLATFORM_SOC_ACTIVE_DELAY_US 120U

#define PLATFORM_HOST_USE_POWER_DOWN (0xA5A5A5A5U)

/*! @brief The configuration of timer. */
#define PLATFORM_TM_INSTANCE 2U

#ifndef PLATFORM_TM_CLK_FREQ
#define PLATFORM_TM_CLK_FREQ 32768U
#endif

#ifndef PLATFORM_TM_CLK_SELECT
#define PLATFORM_TM_CLK_SELECT 2U /*Lptmr timer use (kLPTMR_PrescalerClock_2) 32k clock*/
#endif

#define RAISE_ERROR(__st, __error_code) -(int)((uint32_t)(((uint32_t)(__st) << 4) | (uint32_t)(__error_code)));

#define PLATFORM_XTAL32M_TRIM_INVALID 0xFFU

#if (defined(FSL_FEATURE_SOC_TSTMR_COUNT) && (FSL_FEATURE_SOC_TSTMR_COUNT > 1))
#define gPlatformHasTstmr32K_d 1
#endif

#define TSTMR_MAX_VAL ((uint64_t)0x00FFFFFFFFFFFFFFULL)

/************************************************************************************
 * Private memory declarations
 ************************************************************************************/

#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
/* We have to adapt the divide register of the FRO depending the frequency of the core to keep a frequency for flash APB
 * clock & RF_CMC clock between 16MHz and 32MHz */
static const uint8_t PLATFORM_FroDiv[] = {1U, 1U, 2U, 2U, 3U};
#endif

/* tracks the last XTAL32M trimming value updated with PLATFORM_UpdateXtal32MTrim function */
static uint8_t lastXtal32MTrim = PLATFORM_XTAL32M_TRIM_INVALID;
/* saves a new XTAL32M trimming value to be applied when possible with PLATFORM_UpdateXtal32MTrim function */
static uint8_t         newXtal32MTrim  = PLATFORM_XTAL32M_TRIM_INVALID;
static volatile int8_t xtal32MTrimLock = 0;

static volatile int8_t active_request_nb = 0;
static uint8_t         chip_revision     = 0xFFU;

/* By default the frequency constraints are 16MHz */
static uint8_t freq_constraint_from_host       = 0U;
static uint8_t freq_constraint_from_controller = 0U;

static volatile int timer_manager_initialized = 0;

static void PLATFORM_UpdateFrequency(void);
#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
static void PLATFORM_SetClock(uint8_t range);

static void PLATFORM_RemoteActiveReqOptionalDelay(bool withDelay);
#endif

#if (defined(FWK_KW47_MCXW72_NBU_FAMILIES)) && (FWK_KW47_MCXW72_NBU_FAMILIES == 1)
/** SMU DMEM mapping configuration lookup table */
static const smu_dmem_config_t smu_dmem_lookup_table[] = {
    {.dmem_size = 0x14000U, .shared_ram_size = 0x14000U, .mapping_value = 0x3e0U}, /* SMU = 80kB,  DMEM = 80kB */
    {.dmem_size = 0x18000U, .shared_ram_size = 0x10000U, .mapping_value = 0x3f0U}, /* SMU = 64kB,  DMEM = 96kB */
    {.dmem_size = 0x20000U, .shared_ram_size = 0x8000U, .mapping_value = 0x3f8U},  /* SMU = 32kB,  DMEM = 128kB */
    {.dmem_size = 0x24000U, .shared_ram_size = 0x4000U, .mapping_value = 0x3fcU},  /* SMU = 16kB,  DMEM = 144kB */
    {.dmem_size = 0x26000U, .shared_ram_size = 0x2000U, .mapping_value = 0x3feU},  /* SMU = 8kB,   DMEM = 152kB */
    {.dmem_size = 0x28000U, .shared_ram_size = 0x0000U, .mapping_value = 0x3ffU},  /* SMU = 0kB,   DMEM = 160kB */
    {.dmem_size = 0x10000U, .shared_ram_size = 0x18000U, .mapping_value = 0x3c0U}, /* SMU = 96kB,  DMEM = 64kB */
    {.dmem_size = 0x8000U, .shared_ram_size = 0x20000U, .mapping_value = 0x380U},  /* SMU = 128kB, DMEM = 32kB */
    {.dmem_size = 0x4000U, .shared_ram_size = 0x24000U, .mapping_value = 0x300U},  /* SMU = 144kB, DMEM = 16kB */
    {.dmem_size = 0x2000U, .shared_ram_size = 0x26000U, .mapping_value = 0x200U},  /* SMU = 152kB, DMEM = 8kB */
    {.dmem_size = 0x0000U, .shared_ram_size = 0x28000U, .mapping_value = 0x000U}   /* SMU = 160kB, DMEM = 0kB */

};
#endif

/************************************************************************************
 * Private functions forward declarations
 ************************************************************************************/
#if defined     gPlatformHasTstmr32K_d && (gPlatformHasTstmr32K_d > 0)
static uint64_t u64ReadTimeStamp(TSTMR_Type *base);
static uint64_t GetTimeStampDeltaTicks(uint64_t timestamp0, uint64_t timestamp1);
#endif
/************************************************************************************
 * Public functions
 ************************************************************************************/

void PLATFORM_ResetContext(void)
{
    uint32_t intMask = PLATFORM_SET_INTERRUPT_MASK();

    /* Reset XTAL32M trim related variables */
    xtal32MTrimLock = 0;

    PLATFORM_CLEAR_INTERRUPT_MASK(intMask);
}

void PLATFORM_RemoteActiveReq(void)
{
#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
    PLATFORM_RemoteActiveReqOptionalDelay(true);
#endif
}

void PLATFORM_RemoteActiveReqWithoutDelay(void)
{
#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
    PLATFORM_RemoteActiveReqOptionalDelay(false);
#endif
}

void PLATFORM_RemoteActiveRel(void)
{
#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
    uint32_t intMask = PLATFORM_SET_INTERRUPT_MASK();

    // PWR_DBG_LOG("<--active_request_nb RELEASE=%d", active_request_nb);

    assert(active_request_nb > 0);
    active_request_nb--;

    if (active_request_nb == 0)
    {
        RF_CMC1->SOC_LP = 0;
    }
    else
    {
    }

    PLATFORM_CLEAR_INTERRUPT_MASK(intMask);
#endif
}

uint8_t PLATFORM_GetXtal32MhzTrim(void)
{
    /* The current XTAL32M trimming value is supposed to be the last trimming
     * applied with PLATFORM_UpdateXtal32MTrim().
     * Note that this might not be accurate if the XTAL32M was updated by another
     * API or by the host core.
     * We want to avoid reading directly the RFMC because we would need to wake up
     * the host core and therefore increase the power consumption. */
    return lastXtal32MTrim;
}

void PLATFORM_SetXtal32MhzTrim(uint8_t trim)
{
    /* Register the new trimming value
     * The trimming will be updated with PLATFORM_UpdateXtal32MTrim()
     * We can't update the XTAL32M right now because the radio might be active
     * The XTAL32M trimming must be updated during the optimal window */
    newXtal32MTrim = trim & (RFMC_XO_TEST_CDAC_MASK >> RFMC_XO_TEST_CDAC_SHIFT);
}

void PLATFORM_UpdateXtal32MTrim(void)
{
    uint32_t rfmc_xo;

    if ((newXtal32MTrim != lastXtal32MTrim) && (xtal32MTrimLock == 0))
    {
        PLATFORM_RemoteActiveReq();
        rfmc_xo = RFMC->XO_TEST;
        rfmc_xo &= ~(RFMC_XO_TEST_CDAC_MASK);
        rfmc_xo |= RFMC_XO_TEST_CDAC(newXtal32MTrim);
        RFMC->XO_TEST   = rfmc_xo;
        lastXtal32MTrim = newXtal32MTrim;
        PLATFORM_RemoteActiveRel();
    }
}

void PLATFORM_LockXtal32MTrim(void)
{
    uint32_t intMask = PLATFORM_SET_INTERRUPT_MASK();

    xtal32MTrimLock++;

    PLATFORM_CLEAR_INTERRUPT_MASK(intMask);
}

void PLATFORM_UnlockXtal32MTrim(void)
{
    uint32_t intMask = PLATFORM_SET_INTERRUPT_MASK();

    xtal32MTrimLock--;
    assert(xtal32MTrimLock >= 0);

    PLATFORM_CLEAR_INTERRUPT_MASK(intMask);
}

void PLATFORM_SetChipRevision(uint8_t chip_rev_l)
{
    chip_revision = chip_rev_l;

    PWR_DBG_LOG("chip rev received:%d", chip_revision);
}

uint8_t PLATFORM_GetChipRevision(void)
{
    return chip_revision;
}

uint64_t PLATFORM_Get32KTimeStamp(void)
{
#if defined gPlatformHasTstmr32K_d && (gPlatformHasTstmr32K_d > 0)
    /* u64ReadTimeStamp mimics TSTMR_ReadTimeStamp(TSTMR0) but copied to avoid dependency
     * with fsl_tstmr.h not present in include path
     */
    return u64ReadTimeStamp(TSTMR1_1);
#else
    return 0ULL;
#endif
}

/*!
 * \brief Compute number of microseconds between 2 timestamps expressed in number of TSTM 32kHz ticks
 *
 * \param [in] timestamp0 start timestamp from which duration is assessed.
 * \param [in] timestamp1 end timestamp till which duration is assessed.
 *
 * \return uint64_t number of microseconds
 *
 */
uint64_t PLATFORM_Get32kTimeStampDeltaUs(uint64_t timestamp0, uint64_t timestamp1)
{
#if defined gPlatformHasTstmr32K_d && (gPlatformHasTstmr32K_d > 0)

    uint64_t duration_us;

    duration_us = GetTimeStampDeltaTicks(timestamp0, timestamp1);
    /* Prevent overflow */
    duration_us &= TSTMR_MAX_VAL;
    /* Normally useless but let Coverity know that the input is necessarily less than 2^56 */
    /* Multiply by 1000000 (2^6 * 5^6) and divide by 32768 (2^15) can be be simplified to Multiplication by 125*125 and
     * division by 512 */
    /* Multiply by 125, inserting the division by 64 and then multiply again by 125 and finally divide by 8 prevents the
     * overflow considering the argument is smaller than 2^56
     */
    duration_us *= 125ULL; /* Since timestamps are no more than 56 bit wide, multiplying by 125 is smaller than 2^63 */
    duration_us >>= 6;     /* Dividing by 64 (2^6) yields a result strictly smaller than 2^57 */
    duration_us *= 125ULL; /* Multiplying by 125 is necessarily strictly smaller than 2^64-1 */
    duration_us >>= 3;     /* Divide by 8 (2^3)  */

    return duration_us;
#else
    return ~0ULL;
#endif
}

uint64_t PLATFORM_GetTimeStamp(void)
{
    return (uint64_t)COUNT_TO_USEC(SysTick->VAL, CLOCK_GetRfFro192MFreq());
}

uint64_t PLATFORM_GetMaxTimeStamp(void)
{
    return (uint64_t)COUNT_TO_USEC(SysTick->LOAD, CLOCK_GetRfFro192MFreq());
}

void PLATFORM_WaitTimeout(uint64_t timestamp, uint64_t delayUs)
{
    uint64_t now, duration;
    do
    {
        now = PLATFORM_GetTimeStamp();

        if (now > timestamp)
        {
            /* Handle counter wrapping */
            duration = PLATFORM_GetMaxTimeStamp() - now + timestamp;
        }
        else
        {
            duration = timestamp - now;
        }
    } while (duration < delayUs);
}

void PLATFORM_Delay(uint64_t delayUs)
{
    /* PLATFORM_Delay() is similar to PLATFORM_WaitTimeout() but timestamp is taken right now */
    PLATFORM_WaitTimeout(PLATFORM_GetTimeStamp(), delayUs);
}

void PLATFORM_InitFro192M(void)
{
#ifdef KW45B41Z83_NBU_SERIES
    uint64_t soctrim1_01;
    uint32_t ifr1_soctrim1_0 = IFR1->SOCTRIM1.PHRASE[0];
    uint32_t ifr1_soctrim1_1 = IFR1->SOCTRIM1.PHRASE[1];

    /* check if NBU IFR1 is blank (no SOCTRIM1 values) */
    if ((ifr1_soctrim1_0 == 0xFFFFFFFFUL) && (ifr1_soctrim1_1 == 0xFFFFFFFFUL))
    {
        /* use default values */
        ifr1_soctrim1_0 = 0x14ffffff;
        ifr1_soctrim1_1 = 0xfffffdba;
    }

    /* Workaround to solve IFR load issue leading to FRO192M using a wrong trim value, See KFOURWONE_3731
     * On impacted parts, this workaround will correct the clock rate from ~24M to expected 32M
     * The FROTRIM can be retrieved from IFR1, in the SOCTRIM1 field (16 bytes)
     * The FROTRIM is written in SOCTRIM1 in the following order:
     * TRIMTEMP = SOCTRIM1[27:22]
     * TRIMCOAR = SOCTRIM1[33:28]
     * TRIMFINE = SOCTRIM1[41:34]
     * We have to read the 2 first 32bits phrases from SOCTRIM1 in order to recover the FROTRIM value
     * */
    soctrim1_01 = (uint64_t)(ifr1_soctrim1_0) | (((uint64_t)(ifr1_soctrim1_1)) << 32);

    FRO192M0->FROTRIM = FRO192M_FROTRIM_TRIMTEMP((uint32_t)((soctrim1_01 >> 22) & 0x3FU)) |
                        FRO192M_FROTRIM_TRIMCOAR((uint32_t)((soctrim1_01 >> 28) & 0x3FU)) |
                        FRO192M_FROTRIM_TRIMFINE((uint32_t)((soctrim1_01 >> 34) & 0xFFU));
#endif
}

void PLATFORM_SetFrequencyConstraintFromHost(uint8_t freq_constraint)
{
    freq_constraint_from_host = freq_constraint;
    PLATFORM_UpdateFrequency();
}

void PLATFORM_SetFrequencyConstraintFromController(uint8_t freq_constraint)
{
    freq_constraint_from_controller = freq_constraint;
    PLATFORM_UpdateFrequency();
}

uint8_t PLATFORM_GetFrequencyConstraintFromHost(void)
{
    return freq_constraint_from_host;
}

#if (defined(gPlatformUseLptmr_d)) && (gPlatformUseLptmr_d == 1U)
int PLATFORM_InitTimerManager(void)
{
    int status = 0;

    if (timer_manager_initialized == 0)
    {
        timer_status_t tm_st;
        timer_config_t timerConfig;

        timerConfig.instance       = PLATFORM_TM_INSTANCE;
        timerConfig.srcClock_Hz    = PLATFORM_TM_CLK_FREQ;
        timerConfig.clockSrcSelect = PLATFORM_TM_CLK_SELECT;

#if (defined(TM_ENABLE_TIME_STAMP) && (TM_ENABLE_TIME_STAMP > 0U))
        timerConfig.timeStampSrcClock_Hz    = PLATFORM_TM_STAMP_CLK_FREQ;
        timerConfig.timeStampInstance       = PLATFORM_TM_STAMP_INSTANCE;
        timerConfig.timeStampClockSrcSelect = PLATFORM_TM_STAMP_CLK_SELECT;
#endif

        tm_st = TM_Init(&timerConfig);
        if (tm_st != kStatus_TimerSuccess)
        {
            status = RAISE_ERROR(tm_st, 1);
            assert(0);
        }
        else
        {
            PLATFORM_RemoteActiveReq();
            /* Enable radio wakeup by lptimer in RFMC */
            RFMC->RF2P4GHZ_CFG |= RFMC_RF2P4GHZ_CFG_RFMC_EXT_WAKEUP_EN(0x1U);
            PLATFORM_RemoteActiveRel();

            /* Timer Manager initialization completed */
            timer_manager_initialized = 1;
        }
    }
    else
    {
        /* Timer Manager already initialized */
        status = 1;
    }
    return status;
}

void PLATFORM_DeinitTimerManager(void)
{
    if (timer_manager_initialized == 1)
    {
        TM_Deinit();
        timer_manager_initialized = 0;
    }
}
#endif

/* get 4 words of information that uniquely identifies the MCU */
int PLATFORM_GetMCUUid(uint8_t *aOutUid16B, uint8_t *pOutLen)
{
    uint32_t uid[4] = {0};

    /* Get the MCU uid */
    uid[0] = MSCM->UID[0];
    uid[1] = MSCM->UID[1];
    uid[2] = MSCM->UID[2];
    uid[3] = MSCM->UID[3];

    FLib_MemCpy(aOutUid16B, (uint8_t *)uid, sizeof(uid));
    /* Get the uid length */
    *pOutLen = (uint8_t)sizeof(uid);

    return 0;
}

void PLATFORM_ConfigureSmuDmemMapping(void)
{
#if (defined(FWK_KW47_MCXW72_NBU_FAMILIES)) && (FWK_KW47_MCXW72_NBU_FAMILIES == 1)
    /* Object definitions at the top of the function */
    extern uint32_t m_dmem_start[];
    extern uint32_t m_dmem_end[];
    extern uint32_t m_shared_ram_start[];
    extern uint32_t m_shared_ram_end[];

    const size_t table_size = sizeof(smu_dmem_lookup_table) / sizeof(smu_dmem_lookup_table[0]);

    uint32_t m_dmem_size;
    uint32_t m_shared_ram_size;
    uint32_t smuDmemMapping;
    uint32_t ram_mux_ctrl;
    size_t   i;
    bool     config_found;

    /* Ensure the start symbols are correct */
    if (((uint32_t)&m_dmem_start != 0x140000U) || ((uint32_t)&m_shared_ram_start != 0xB0000000U))
    {
        assert(0);
    }

    m_dmem_size       = (uint32_t)&m_dmem_end - (uint32_t)&m_dmem_start + 1U;
    m_shared_ram_size = (uint32_t)&m_shared_ram_end - (uint32_t)&m_shared_ram_start + 1U;

    /* Default value is SMU and DMEM to 80kB both */
    smuDmemMapping = 0x3e0U;
    config_found   = false;

    /* Search through lookup table for matching configuration */
    for (i = 0U; i < table_size; i++)
    {
        if ((m_dmem_size == smu_dmem_lookup_table[i].dmem_size) &&
            (m_shared_ram_size == smu_dmem_lookup_table[i].shared_ram_size))
        {
            smuDmemMapping = smu_dmem_lookup_table[i].mapping_value;
            config_found   = true;
            break;
        }
    }

    /* Assert if no valid configuration found */
    if (!config_found)
    {
        assert(0);
    }

    ram_mux_ctrl = RF_CMC1->RAM_MUX_CTRL;

    /* Unlock register to perform a write operation later */
    RF_CMC1->RAM_MUX_CTRL = RF_CMC1_RAM_MUX_CTRL_UNLOCK(5U);

    ram_mux_ctrl &= ~RF_CMC1_RAM_MUX_CTRL_SMU_MEM_SEL_MASK;
    ram_mux_ctrl |= smuDmemMapping;

    RF_CMC1->RAM_MUX_CTRL = ram_mux_ctrl;
#endif
}

/************************************************************************************
 * Private functions
 ************************************************************************************/
#if defined     gPlatformHasTstmr32K_d && (gPlatformHasTstmr32K_d > 0)
static uint64_t u64ReadTimeStamp(TSTMR_Type *base)
{
    uint32_t reg_l;
    uint32_t reg_h;
    uint32_t regPrimask;

    regPrimask = DisableGlobalIRQ();

    /* A complete read operation should include both TSTMR LOW and HIGH reads. If a HIGH read does not follow a LOW
     * read, then any other Time Stamp value read will be locked at a fixed value. The TSTMR LOW read should occur
     * first, followed by the TSTMR HIGH read.
     * */
    reg_l = base->L;
    __DMB();
    reg_h = base->H;

    EnableGlobalIRQ(regPrimask);

    return (uint64_t)reg_l | (((uint64_t)reg_h) << 32U);
}

/*!
 * \brief Compute number of ticks between 2 timestamps expressed in number of TSTMR ticks
 *
 * \param [in] timestamp0 start timestamp.
 * \param [in] timestamp1 end timestamp.
 *
 * \return uint64_t number of TSTMR ticks
 *
 */
static uint64_t GetTimeStampDeltaTicks(uint64_t timestamp0, uint64_t timestamp1)
{
    uint64_t delta_ticks;

    timestamp0 &= TSTMR_MAX_VAL; /* sanitize arguments */
    timestamp1 &= TSTMR_MAX_VAL;

    if (timestamp1 >= timestamp0)
    {
        delta_ticks = timestamp1 - timestamp0;
    }
    else
    {
        /* In case the 56-bit counter has wrapped */
        delta_ticks = TSTMR_MAX_VAL - timestamp0 + timestamp1 + 1ULL;
    }
    return delta_ticks;
}
#endif

static void PLATFORM_UpdateFrequency(void)
{
#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
    /* Take the higher frequency between the constraint set by the controller and the one from the host and apply it */
    uint8_t frequency = (freq_constraint_from_host > freq_constraint_from_controller) ? freq_constraint_from_host :
                                                                                        freq_constraint_from_controller;
    PLATFORM_SetClock(frequency);
#else
    (void)freq_constraint_from_controller;
#endif
}
#if !defined(FPGA_TARGET) || (FPGA_TARGET == 0)
static void PLATFORM_SetClock(uint8_t range)
{
    uint32_t fro192M_clock_ctrl;
    uint32_t fro192M_div;

    fro192M_clock_ctrl = FRO192M0->FROCCSR;
    fro192M_clock_ctrl &= ~(FRO192M_FROCCSR_POSTDIV_SEL_MASK);

    fro192M_div = FRO192M0->FRODIV;
    fro192M_div &= ~(FRO192M_FRODIV_FRODIV_MASK);

    if (range <= 4U)
    {
        fro192M_clock_ctrl |= FRO192M_FROCCSR_POSTDIV_SEL(range);
        fro192M_div |= FRO192M_FRODIV_FRODIV(PLATFORM_FroDiv[range]);
    }
    else
    {
        /* The range selected by default is 32Mhz and 16MHz for flash APB clock & RF_CMC clock*/
        fro192M_clock_ctrl |= FRO192M_FROCCSR_POSTDIV_SEL(2);
        fro192M_div |= FRO192M_FRODIV_FRODIV(PLATFORM_FroDiv[2]);
    }

    FRO192M0->FROCCSR = fro192M_clock_ctrl;
    FRO192M0->FRODIV  = fro192M_div;

    /* Wait for RF FRO192M clock to be valid. */
    while ((FRO192M0->FROCCSR & FRO192M_FROCCSR_VALID_MASK) != FRO192M_FROCCSR_VALID_MASK)
    {
    }
}

uint32_t PLATFORM_GetClockFreq(void)
{
    uint32_t fro192M_clock_ctrl;
    uint32_t fro192M_div;
    uint32_t post_div;
    uint32_t fro_freq = 0uL;

    while (TRUE)
    {
        fro192M_clock_ctrl = FRO192M0->FROCCSR;

        if ((fro192M_clock_ctrl & FRO192M_FROCCSR_VALID_MASK))
        {
            /* Read back FOR 192 divisor from FROCCSR whereas it was set from FRODIV */
            fro192M_div = (fro192M_clock_ctrl & FRO192M_FRODIV_FRODIV_MASK) >> FRO192M_FRODIV_FRODIV_SHIFT;
            fro192M_div += 1u;
            post_div = ((fro192M_clock_ctrl & FRO192M_FROCCSR_POSTDIV_SEL_MASK) >> FRO192M_FROCCSR_POSTDIV_SEL_SHIFT);
            const uint32_t fro_freq_tb[5] = {16000000, 24000000, 32000000, 48000000, 64000000};

            if (post_div < sizeof(fro_freq_tb) / sizeof(fro_freq_tb[0]))
            {
                fro_freq = fro_freq_tb[post_div];
            }
            break;
        }
    }
    return fro_freq;
}

static uint32_t PLATFORM_GetLowPowerFlag(void)
{
    extern uint32_t    m_lowpower_flag_start[]; /* defined by linker */
    volatile uint32_t *p_lp_flag = (volatile uint32_t *)(uint32_t)m_lowpower_flag_start;

    return *p_lp_flag;
}

static void PLATFORM_RemoteActiveReqOptionalDelay(bool withDelay)
{
    uint32_t intMask = PLATFORM_SET_INTERRUPT_MASK();

    if (active_request_nb == 0)
    {
        /* Request access to SOC XBAR bus - only this bit is writeable */
        RF_CMC1->SOC_LP = RF_CMC1_SOC_LP_BUS_REQ(0x1);

        while ((RF_CMC1->SOC_LP & RF_CMC1_SOC_LP_BUS_AWAKE_MASK) == 0)
        {
            asm("NOP");
        }
        /* If the host is in power down, we need to wait an additional delay on OEM part for the SOC to be ready */
        if ((PLATFORM_GetLowPowerFlag() == PLATFORM_HOST_USE_POWER_DOWN) && withDelay)
        {
            PLATFORM_Delay(PLATFORM_SOC_ACTIVE_DELAY_US);
        }
    }

    active_request_nb++;

    PLATFORM_CLEAR_INTERRUPT_MASK(intMask);

    // PWR_DBG_LOG("-->active_request_nb REQUEST=%d", active_request_nb);
}
#endif
/*${function:end}*/
