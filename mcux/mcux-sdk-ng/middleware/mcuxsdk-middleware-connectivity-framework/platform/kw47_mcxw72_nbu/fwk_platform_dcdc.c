/*!
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fwk_platform_dcdc.h"
#include "fwk_platform.h"
#include "fsl_device_registers.h"

/************************************************************************************
 * Private memory declarations
 ************************************************************************************/

static bool high_power_mode_enabled = false;

/************************************************************************************
 * Public functions
 ************************************************************************************/

void PLATFORM_ConfigureSpcHighPowerMode(uint8_t power_dBm)
{
    uint32_t rf_cmc_hp_ctrl;
    uint32_t spc_high_power_mode_enabled;

    /* Disable by default the high power mode feature*/
    high_power_mode_enabled = false;

    /* SPC register is located in app core power domain, need to ensure the power domain is accessible before reading
     * it*/
    PLATFORM_RemoteActiveReq();
    spc_high_power_mode_enabled = SPC0->HP_CNFG_CTRL & SPC_HP_CNFG_CTRL_HP_REQ_EN_MASK;
    PLATFORM_RemoteActiveRel();

    rf_cmc_hp_ctrl = RF_CMC1->SPC_HP_CTRL;
    rf_cmc_hp_ctrl &= ~RF_CMC1_SPC_HP_CTRL_SPC_HP_MODE_MASK;

    do
    {
        if (spc_high_power_mode_enabled == 0U)
        {
            /* If the high power mode request has not been enabled by app core, disable the feature on NBU */
            break;
        }

        /* If the Tx power target is 0 no need to enable high power mode. If Tx power target is higher than 7dBm this
         * cannot be handled by high power mode of RF_CMC only */
        if (power_dBm > 0U && power_dBm <= 7U)
        {
            /* Enable High power mode at 1.8V */
            high_power_mode_enabled = true;
            rf_cmc_hp_ctrl |= RF_CMC1_SPC_HP_CTRL_SPC_HP_MODE(4U);
        }

    } while (false);

    RF_CMC1->SPC_HP_CTRL = rf_cmc_hp_ctrl;

    /* Enable SPC high power mode right away to fit the Tx power targeted */
    PLATFORM_EnableSpcHighPowerMode(true);
}

void PLATFORM_EnableSpcHighPowerMode(bool enable)
{
    /* No need to do anything if the feature is disabled on NBU */
    if (high_power_mode_enabled)
    {
        if (enable)
        {
            RF_CMC1->SPC_HP_CTRL |= RF_CMC1_SPC_HP_CTRL_SPC_HP_REQ_MASK;

            /* Wait for the High power mode target to be achieved before releasing to the software
             * /!\ If the ramp is really smooth it can take up to 2ms to ramp up */
            while ((RF_CMC1->SPC_HP_STAT & RF_CMC1_SPC_HP_STAT_SPC_HP_ACK_MASK) == 0)
                ;
        }
        else
        {
            RF_CMC1->SPC_HP_CTRL &= ~RF_CMC1_SPC_HP_CTRL_SPC_HP_REQ_MASK;
        }
    }
}