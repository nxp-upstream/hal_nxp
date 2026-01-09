/* -------------------------------------------------------------------------- */
/*                             Copyright 2023 NXP                             */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fwk_platform.h"
#include "fsl_adapter_time_stamp.h"
#include "fsl_clock.h"
#include "fsl_lpi2c.h"
#include "fsl_component_timer_manager.h"

/* -------------------------------------------------------------------------- */
/*                                 Definitions                                */
/* -------------------------------------------------------------------------- */

#define I2C_MASTER_BASE (LPI2C1_BASE)

/* Select USB1 PLL (480 MHz) as master lpi2c clock source */
#define LPI2C_CLOCK_SOURCE_SELECT (0U)
/* Clock divider for master lpi2c clock source */
#define LPI2C_CLOCK_SOURCE_DIVIDER (5U)
/* Get frequency of lpi2c clock */
#define LPI2C_CLOCK_FREQUENCY ((CLOCK_GetFreq(kCLOCK_Usb1PllClk) / 8) / (LPI2C_CLOCK_SOURCE_DIVIDER + 1U))

#define I2C_MASTER     ((LPI2C_Type *)I2C_MASTER_BASE)
#define LPI2C_BAUDRATE 100000U
#define WAIT_TIME      10U

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static TIME_STAMP_HANDLE_DEFINE(timestampHandle);
static volatile bool timerManagerInitialized = false;
static volatile bool timestampInitialized    = false;

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

static void PLATFORM_I2CInit(void);
static int  PLATFORM_I2CSend(uint8_t address, uint8_t byte1, uint8_t byte2);

/* -------------------------------------------------------------------------- */
/*                              Private functions                              */
/* -------------------------------------------------------------------------- */

static void PLATFORM_I2CInit(void)
{
    lpi2c_master_config_t masterConfig;

    /*Clock setting for LPI2C*/
    CLOCK_SetMux(kCLOCK_Lpi2cMux, LPI2C_CLOCK_SOURCE_SELECT);
    CLOCK_SetDiv(kCLOCK_Lpi2cDiv, LPI2C_CLOCK_SOURCE_DIVIDER);

    /*
     * masterConfig.debugEnable = false;
     * masterConfig.ignoreAck = false;
     * masterConfig.pinConfig = kLPI2C_2PinOpenDrain;
     * masterConfig.baudRate_Hz = 100000U;
     * masterConfig.busIdleTimeout_ns = 0;
     * masterConfig.pinLowTimeout_ns = 0;
     * masterConfig.sdaGlitchFilterWidth_ns = 0;
     * masterConfig.sclGlitchFilterWidth_ns = 0;
     */
    LPI2C_MasterGetDefaultConfig(&masterConfig);

    /* Change the default baudrate configuration */
    masterConfig.baudRate_Hz = LPI2C_BAUDRATE;

    /* Initialize the LPI2C master peripheral */
    LPI2C_MasterInit(I2C_MASTER, &masterConfig, LPI2C_CLOCK_FREQUENCY);
}

static int PLATFORM_I2CSend(uint8_t address, uint8_t byte1, uint8_t byte2)
{
    size_t   txCount = 0xFFU;
    status_t reVal   = kStatus_Success;
    /* Send master blocking data to slave */
    if (kStatus_Success == LPI2C_MasterStart(I2C_MASTER, address, kLPI2C_Write))
    {
        /* Check master tx FIFO empty or not */
        LPI2C_MasterGetFifoCounts(I2C_MASTER, NULL, &txCount);
        while (txCount)
        {
            LPI2C_MasterGetFifoCounts(I2C_MASTER, NULL, &txCount);
        }
        /* Check communicate with slave successful or not */
        if (LPI2C_MasterGetStatusFlags(I2C_MASTER) & kLPI2C_MasterNackDetectFlag)
        {
            return kStatus_LPI2C_Nak;
        }

        reVal = LPI2C_MasterSend(I2C_MASTER, &byte1, 1);
        if (reVal != kStatus_Success)
        {
            if (reVal == kStatus_LPI2C_Nak)
            {
                LPI2C_MasterStop(I2C_MASTER);
            }
            return reVal;
        }

        /* Check master tx FIFO empty or not */
        LPI2C_MasterGetFifoCounts(I2C_MASTER, NULL, &txCount);
        while (txCount)
        {
            LPI2C_MasterGetFifoCounts(I2C_MASTER, NULL, &txCount);
        }
        /* Check communicate with slave successful or not */
        if (LPI2C_MasterGetStatusFlags(I2C_MASTER) & kLPI2C_MasterNackDetectFlag)
        {
            return kStatus_LPI2C_Nak;
        }

        reVal = LPI2C_MasterSend(I2C_MASTER, &byte2, 1);
        if (reVal != kStatus_Success)
        {
            if (reVal == kStatus_LPI2C_Nak)
            {
                LPI2C_MasterStop(I2C_MASTER);
            }
            return reVal;
        }

        LPI2C_MasterStop(I2C_MASTER);
    }
    return reVal;
}

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitTimerManager(void)
{
    /* Initialize timer manager */
    int            ret = -1;
    timer_config_t timerConfig;
    timer_status_t status = kStatus_TimerError;

    if (timerManagerInitialized == false)
    {
        timerConfig.instance    = PLATFORM_TM_INSTANCE;
        timerConfig.srcClock_Hz = CLOCK_GetFreq(kCLOCK_OscClk);

        status = TM_Init(&timerConfig);
        if (status == kStatus_TimerSuccess)
        {
            timerManagerInitialized = true;
            ret                     = 0;
        }
    }
    return ret;
}

void PLATFORM_DeinitTimerManager(void)
{
    if (timerManagerInitialized == true)
    {
        TM_Deinit();
        timerManagerInitialized = false;
    }
}

void PLATFORM_InitTimeStamp(void)
{
    hal_time_stamp_config_t config;

    if (timestampInitialized == false)
    {
        config.instance    = 0U;
        config.srcClock_Hz = CLOCK_GetPerClkFreq();

        HAL_TimeStampInit(timestampHandle, &config);

        timestampInitialized = true;
    }
}

uint64_t PLATFORM_GetTimeStamp(void)
{
    return HAL_GetTimeStamp(timestampHandle);
}

uint64_t PLATFORM_GetMaxTimeStamp(void)
{
    /* The timestamp module always converts the timer counter to microsec. As the GPT is a 32bits timer,
     * and the calculations are 64 bit, no overflow is to be taken into account */
    return (uint64_t)COUNT_TO_USEC(~0UL, CLOCK_GetPerClkFreq());
}

int PLATFORM_IOEXP_I2C_program(uint8_t addr, uint8_t reg, uint8_t val)
{
    int ret;

    /* Initialize the LPI2C peripheral */
    PLATFORM_I2CInit();

    /* Set Configuration Register of IO_Expander */
    ret = PLATFORM_I2CSend(addr, reg, val);

    return ret;
}
