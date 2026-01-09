/*!
 * Copyright 2021, 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fwk_platform_lcl.h"
#include "fwk_platform_definitions.h"
#include "FunctionLib.h"
#include "RNG_Interface.h"

#if defined(gAppLowpowerEnabled_d) && (gAppLowpowerEnabled_d > 0)
// TODO : remove dependancy
#include "board_lp.h"
#endif

#include "pin_mux.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "nxp_xcvr_ext_ctrl.h"

/*******************************************************************************
 * Private macros
 ******************************************************************************/
#define DTEST_TSM      (0x03)
#define DTEST_RSM0     (0x04)
#define DTEST_RSM1     (0x05)
#define DTEST_RSM2     (0x06)
#define DTEST_XCVR_DMA (0x07)
#define DTEST_RX_IQ    (0x17)
#define DTEST_NBU_LL   (0x43)

#define DTEST_OVRD_TSM_COMBO_TX_EN 0x4U
#define DTEST_OVRD_TSM_COMBO_RX_EN 0x5U

/* DTEST signal selectors for use with dtest_pins_init() */
#define DTEST0    (1UL << 0UL)
#define DTEST1    (1UL << 1UL)
#define DTEST2    (1UL << 2UL)
#define DTEST3    (1UL << 3UL)
#define DTEST4    (1UL << 4UL)
#define DTEST5    (1UL << 5UL)
#define DTEST6    (1UL << 6UL)
#define DTEST7    (1UL << 7UL)
#define DTEST8    (1UL << 8UL)
#define DTEST9    (1UL << 9UL)
#define DTEST10   (1UL << 10UL)
#define DTEST11   (1UL << 11UL)
#define DTEST12   (1UL << 12UL)
#define DTEST13   (1UL << 13UL)
#define DTEST_ALL (0x1FFFUL)

/* DTEST5 conflicts with PTC1 (SW2) on localization board */
#if defined(BOARD_LOCALIZATION_REVISION_SUPPORT) && (BOARD_LOCALIZATION_REVISION_SUPPORT > 0)
#undef DTEST1
#define DTEST1 0UL

/* DTEST13 conflicts with PTC7 (SW3) on localization board */
#if (defined(gAppButtonCnt_c) && (gAppButtonCnt_c > 1))
#undef DTEST13
#define DTEST13 0UL
#endif
#endif

/*
 * DTEST2 & DTEST3 conflict with UART1
 * DTEST4 (PTC4) is used for GPIO debug on CM33
 * DTEST6 conflicts with PTC6 (SW3)
 * DTEST7 (aa_matched_to_ll in DTEST_RSM2) conflicts with PTB0 = monochrome LED (LED2)
 * PTA19, PTA20, PTA21 (RGB LED) conflicts with RF_GPO (antenna switching)
 */
#if (defined(DEFAULT_APP_UART) && (DEFAULT_APP_UART == 0))
#define DTEST_LIST_BASE                                                                                            \
    (DTEST0 | DTEST1 | DTEST2 | DTEST3 | /* DTEST4 |*/ DTEST5 | /*DTEST7 |*/ DTEST8 | DTEST9 | DTEST10 | DTEST11 | \
     DTEST12 | DTEST13)
#else
#define DTEST_LIST_BASE                                                                                                \
    (DTEST0 | DTEST1 | /*DTEST2 | DTEST3 |*/ /* DTEST4 |*/ DTEST5 | /*DTEST7 |*/ DTEST8 | DTEST9 | DTEST10 | DTEST11 | \
     DTEST12 | DTEST13)
#endif

#if (!defined(gAppLedCnt_c) || (gAppLedCnt_c == 0))
#define DTEST_LIST (DTEST_LIST_BASE | DTEST7) /* DTEST7 may be used as no LED is active */
#else
#define DTEST_LIST DTEST_LIST_BASE
#endif

#define BIT_10   (BIT0 | BIT1)
#define BIT_210  (BIT0 | BIT1 | BIT2)
#define BIT_3210 (BIT0 | BIT1 | BIT2 | BIT3)
#define BIT_54   (BIT4 | BIT5)
#define BIT_654  (BIT4 | BIT5 | BIT6)
#define BIT_7654 (BIT4 | BIT5 | BIT6 | BIT7)

/* Defines for field RF2p4GHz_COEXT's RFGPO_OBE for Localization, COEX and FEM.
   The purpose is to propose the default values without conflict of pin setting
   between these active features. They could be overrided by customer through APIs.
*/
#if defined(FWK_KW47_MCXW72_FAMILIES) || (FWK_KW47_MCXW72_FAMILIES == 1)
#if defined(BOARD_LOCALIZATION_REVISION_SUPPORT) && (BOARD_LOCALIZATION_REVISION_SUPPORT > 0)
#define gAppRfGpoSRC RFMC_GPO_LANT_3_0_COEX_3_0 /* hardware dependancy: LCL uses group RF_GPO[7:4] */
#else
#define gAppRfGpoSRC RFMC_GPO_COEX_3_0_LANT_3_0 /* hardware dependancy: LCL uses group RF_GPO[3:0] */
#endif
#else
#define gAppRfGpoSRC RFMC_GPO_COEX_3_0_LANT_3_0 /* hardware dependancy: LCL uses group RF_GPO[3:0] */
#endif

#define gAppRfGpoFEM RFMC_GPO_INVALID /* FEM uses RF_GPO[11..8] */

/* Total size of COEX config including several XCVR structures which could be changed */
#define COEX_CONFIG_LEN                                                                                      \
    (6 + sizeof(coexRfSignalInvert_t) + sizeof(coexRfNotAllowedConfig_t) + sizeof(coexRfActiveTsmConfig_t) + \
     sizeof(coexRfActiveRfmcConfig_t) + sizeof(coexRfStatusConfig_t) + sizeof(coexRfPriorityConfig_t) + 2)

/* Default COEX configuration including several XCVR structures + output/input signals setting + RF_GPO option.
   Details: all output signals activated without inversion/muxing, TSM is source, high priority TX/RX,
            RF_ACTIVE aligned with RF_STATUS & RF_PRIO in RX but TX, RF_NOT_ALLOWED active HIGH on PTC7.
 */
const uint8_t default_COEX_config[COEX_CONFIG_LEN] = {
    /* wiring configuration */
    0x01,         /* uint8 rf_active_used;  When set to 1, RF_ACTIVE signal will be active */
    0x01,         /* rf_status_used;        When set to 1 RF_STATUS signal will be active */
    0x01,         /* rf_prio_used;          0 if not used, 1 if only priority[0] used, 2 for priority[1:0] */
    gAppRfGpoSRC, /* rfmcGpoCoex;   [0,5]=RF_GPO[6:4]=PORTD[3,2,1]=(*)J14-[16,14,12] as [RF_PRIO,RF_STATUS,RF_ACTIVE]
                                    [1,4]=RF_GPO[2:0]=PORTA[20,19,18]=(*)J14-[8,6,4]. (*) for FPGA */
    0x01,         /* tsm_controls_coex;     When set to 1, TSM will control output signals */
    /* -------- */
    0x01, /* rfactSrc;                  coexRfactSrc_t 0..2 */
/* coexRfSignalInvert_t: */
#if defined(KW45B41Z82_SERIES) || defined(KW45B41Z83_SERIES)
    0x01, /* rfna_invert;               KW45 HW bug - RF_NALLOWED is active LOW instead of HIGH */
#else
    0x00, /* rfna_invert;               When set to 1, inverts the RF_NOT_ALLOWED signal in RFMC muxing logic */
#endif
    0x00, /* rfact_invert;              When set to 1, inverts the RF_ACTIVE signal in RFMC muxing logic */
    0x00, /* rfstat_invert;             When set to 1, inverts the RF_STATUS signal in RFMC muxing logic */
    0x00, /* rfpri_invert[0];           When set to 1, inverts the RF_PRIORITY signals in RFMC muxing logic */
    0x00, /* rfpri_invert[1];           When set to 1, inverts the RF_PRIORITY signals in RFMC muxing logic */
    /* coexRfNotAllowedConfig_t: */
    0x04, /* rfna_pin_enable;           coexRfNotAllowPin_t 1=PTA16, 2=PTA17, 4=PTC7. N/A for FPGA: PTD6 J14-19 */
    0x01, /* link_layer_rfna_select;    Enable bits for RF_NOT_ALLOWED signal to LLs. Value is the OR'd together of any
                                        ::coexRfNotAllowLL_t entries 0,1,4,8. */
    /* coexRfActiveTsmConfig_t: */
    0x37, /* rf_act_extend;             RF_ACTIVE remains asserted this many microseconds after the end of TSM RX or TX
                                        sequences. Must be <=255. */
    0x5D, /* rf_act_tx_advance;         RF_ACTIVE aserts this many microseconds before the end of TX warm up. If this
                                        value is > than the number of microseconds before end of TX warm  ramp up in
                                        the TSM timing sequence then an error will be returned. */
    0x5A, /* rf_act_rx_advance;         RF_ACTIVE aserts this many microseconds before the RX digital is enabled. If
                                        this value is > than the number of microseconds before end of RX warm  ramp up
                                        in the TSM timing sequence then an error will be returned. */
    /* coexRfActiveRfmcConfig_t: */
    0x00, /* deassert_when_tsm_idle;    When set to 1, RFMS will deassert RF_ACTIVE if the TSM is idle. Otherwise
                                        deassertion is on next low power entry. */
    0x00, /* wakeup_delay;              RF_ACTIVE asserts this many 32KHz ref. clocks after the XO is enabled.
                                        Must be less <= 63. */
    /* coexRfStatusConfig_t: */
    0x5A, /* rf_stat_tx_advance;        RF_STATUS aserts this many microseconds before the end of TX warm up.
                                        Must < TX_WU=0x70. */
    /* coexRfPriorityConfig_t: */
    0x5A, /* rf_pri_tx_advance;         RF_PRIORITY aserts this many microseconds before the end of TX warm up. If this
                                        value is > than the number of microseconds before end of TX warm  ramp up in the
                                        TSM timing sequence then an error will be returned. */
    0x5A, /* rf_pri_rx_advance;         RF_PRIORITY aserts this many microseconds before the RX digital is enabled. If
                                        this value is > than the number of microseconds before end of RX warm  ramp up
                                        in the TSM timing sequence then an error will be returned. */
    0x00, /* rf_pri_on_rf_stat;         When set to 1, RF_PRIORITY signal is muxed on  the RF_STATUS signal. */
    /* -------- */
    0x01, /* rf_pri_rx;                 priority level of RX. 0 LOW, 1 HIGH */
    0x01, /* rf_pri_tx;                 priority level of TX. 0 LOW, 1 HIGH */
};

/* Total size of FEM config, equals to (xcvr_pa_fem_config_t + 1) */
#define FEM_CONFIG_LEN (1 + sizeof(xcvr_pa_fem_config_t))

/* Default FEM configuration which is xcvr_pa_fem_config_t + RF_GPO option */
/* Remark: gAppRfGpoFEM = RFMC_GPO_INVALID is a valid parameter, see PLATFORM_FEM_pin_init() ! */

const uint8_t default_FEM_config[FEM_CONFIG_LEN] = {
    1U, /* dual mode  XCVR_ANTX_MODE_T op_mode;  operating mode for the PA/FEM interface */
    0U, /* Disabled   uint8_t ant_sel_pins_enable;  control whether ANT_A & ANT_B pads should be active
                      (0=Disabled, 1=Enabled) */
    1U, /* Enabled    uint8_t tx_rx_switch_pins_enable; control whether TX and RX_SWITCH pads should be active
                      (0=Disabled, 1=Enabled) */
    0U, /* Disabled   uint8_t high_z_enable;  control whether FEM/PA  pads should use High Z (0=Disabled, =Enabled) */
    0U, /* Disabled   uint8_t use_fad_state_machine;  control whether FAD state machine is active (0=Disabled,
                      1=Enabled) */
    0U, /* TSM GPIO   XCVR_FAD_NOT_GPIO_MODE_T ant_a_pad_control;  control whether ANT_A pad should be controlled by FAD
                      state machine or TSM GPIO */
    0U, /* TSM GPIO   XCVR_FAD_NOT_GPIO_MODE_T ant_b_pad_control;  control whether ANT_B pad should be controlled by FAD
                      state machine or TSM GPIO */
    0U, /* TSM GPIO   XCVR_FAD_NOT_GPIO_MODE_T tx_switch_pad_control; control whether TX_SWITCH pad should be controlled
                      by FAD state machine or TSM GPIO  */
    0U, /* TSM GPIO   XCVR_FAD_NOT_GPIO_MODE_T rx_switch_pad_control; control whether RX_SWITCH pad should be
                      controlled by FAD state machine or TSM GPIO  */
    0U, /* ?          uint8_t pa_tx_wu;  Number of usec to start external PA warmup ahead of internal PA warmup start */
    0U, /* MUST=0     uint8_t pa_tx_wd;  Number of usec to start external PA warmdown ahead of internal PA warmdown
                      completion */
    0U, /* ?          uint8_t lna_rx_wu; Number of usec to start external LNA warmup ahead of internal LNA warmup start
         */
    0U, /* MUST=0     uint8_t lna_rx_wd; Number of usec to start external LNA warmdown ahead of internal LNA warmdown
                      completion */
    0U, /* HIGH       XCVR_RX_TX_POLARITY_MODE_T tx_switch_pol_control;  control whether TX_SWITCH pad should be active
                      high or low  (0=Active HIGH, 1=Active LOW) */
    0U, /* HIGH       XCVR_RX_TX_POLARITY_MODE_T rx_switch_pol_control;  control whether RX_SWITCH pad should be active
                      high or low  (0=Active HIGH, 1=Active LOW) */
    gAppRfGpoFEM, /* RF_GPO[11:8]   uint8_t  control which RF_GPOs to use, [0,2]=RF_GPO[3:0], [1,3]=RF_GPO[7:4],
                     6=RF_GPO[11:8], otherwise invalid */
};

/*******************************************************************************
 * Private memory declarations
 ******************************************************************************/

/* variables to detect conflict between Localisation, Coexistence and FEM */
static rfmcGpoCoex_t rfmcGpoSRC = RFMC_GPO_INVALID; /* the current RFMC_GPO value */
static uint8_t       rfmcGpoOBE = 0U;               /* the current COEXT_RFGPO_OBE value */

/*******************************************************************************
 *  private functions
 ******************************************************************************/
#ifdef ENABLE_DTEST
static void dtest_pins_init(uint32_t option)
{
    if ((option & DTEST0) != 0U) /* PTC0 alt 8 */
    {
        PORT_SetPinMux(PORTC, 0U, kPORT_MuxAlt8);
    }
    if ((option & DTEST1) != 0U) /* PTC1 alt 8 */
    {
        PORT_SetPinMux(PORTC, 1U, kPORT_MuxAlt8);
    }
    if ((option & DTEST2) != 0U) /* PTC2 alt 8 */
    {
        PORT_SetPinMux(PORTC, 2U, kPORT_MuxAlt8);
    }
    if ((option & DTEST3) != 0U) /* PTC3 alt 8 */
    {
        PORT_SetPinMux(PORTC, 3U, kPORT_MuxAlt8);
    }
    if ((option & DTEST4) != 0U) /* PTC4 alt 8 */
    {
        PORT_SetPinMux(PORTC, 4U, kPORT_MuxAlt8);
    }
    if ((option & DTEST5) != 0U) /* PTC5 alt 8 */
    {
        PORT_SetPinMux(PORTC, 5U, kPORT_MuxAlt8);
    }
    if ((option & DTEST6) != 0U) /* PTC6 alt 8 */
    {
        PORT_SetPinMux(PORTC, 6U, kPORT_MuxAlt8);
    }
    if ((option & DTEST7) != 0U) /* PTB0 alt 8*/
    {
        PORT_SetPinMux(PORTB, 0U, kPORT_MuxAlt8);
    }
    if ((option & DTEST8) != 0U) /* PTB1 alt 8 */
    {
        PORT_SetPinMux(PORTB, 1U, kPORT_MuxAlt8);
    }
    if ((option & DTEST9) != 0U) /* PTB2 alt 8 */
    {
        PORT_SetPinMux(PORTB, 2U, kPORT_MuxAlt8);
    }
    if ((option & DTEST10) != 0U) /* PTB3 alt 8 */
    {
        PORT_SetPinMux(PORTB, 3U, kPORT_MuxAlt8);
    }
    if ((option & DTEST11) != 0U) /* PTB4 alt 8 */
    {
        PORT_SetPinMux(PORTB, 4U, kPORT_MuxAlt8);
    }
    if ((option & DTEST12) != 0U) /* PTCB5 alt 8  */
    {
        PORT_SetPinMux(PORTB, 5U, kPORT_MuxAlt8);
    }
    if ((option & DTEST13) != 0U) /* PTC7 alt 8 */
    {
        PORT_SetPinMux(PORTC, 7U, kPORT_MuxAlt8);
    }
}

static void set_dtest_page(uint32_t dtest_page)
{
    uint32_t temp;

    /* Set the DTEST page selection and DTEST enable */
    temp = RADIO_CTRL->DTEST_CTRL;
    temp &= ~(RADIO_CTRL_DTEST_CTRL_DTEST_PAGE_MASK | RADIO_CTRL_DTEST_CTRL_DTEST_EN_MASK);
    temp |= RADIO_CTRL_DTEST_CTRL_DTEST_PAGE(dtest_page) | RADIO_CTRL_DTEST_CTRL_DTEST_EN(1);
    RADIO_CTRL->DTEST_CTRL = temp;
}

/* DTEST setting to get TX & RX_EN signals on PTB3 & PTB4 respectively */
void PLATFORM_Init_Dtest_TX_RX_EN(void)
{
    set_dtest_page(DTEST_TSM);

    /* custom override to put TX_EN on DTEST 10 */
    RADIO_CTRL->DTEST_PIN_CTRL2 &= ~RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN10_OVRD_SEL_MASK;
    RADIO_CTRL->DTEST_PIN_CTRL2 |= RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN10_OVRD_SEL(DTEST_OVRD_TSM_COMBO_TX_EN);

    /* custom override to put RX_EN on DTEST 11 */
    RADIO_CTRL->DTEST_PIN_CTRL2 &= ~RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN11_OVRD_SEL_MASK;
    RADIO_CTRL->DTEST_PIN_CTRL2 |= RADIO_CTRL_DTEST_PIN_CTRL2_DTEST_PIN11_OVRD_SEL(DTEST_OVRD_TSM_COMBO_RX_EN);

    dtest_pins_init(DTEST10 | DTEST11); /* TX_EN on (PORTB, 3U, kPORT_MuxAlt8) | RX_EN on (PORTB, 4U, kPORT_MuxAlt8) */
}

void PLATFORM_InitLclDtest(void)
{
    // dtest_page usually one of DTEST_RSM2, DTEST_NBU_LL, DTEST_RX_IQ
    set_dtest_page(DTEST_RSM2);
    dtest_pins_init(DTEST_LIST);

#ifdef BT51_TEST_MODE_AOA_AOD
    PORT_SetPinMux(PORTD, 1U, kPORT_MuxAlt4);
    PORT_SetPinMux(PORTD, 2U, kPORT_MuxAlt4);
    PORT_SetPinMux(PORTD, 3U, kPORT_MuxAlt4);

    // See Generation 4.5 Radio Platform Manual, Figure 78. Radio Coexistence/FEM/LANT Mux diagram
    // LCL_GPIO_SEL: 1b - Select NBU requestAntenna[3:0] as radio lant_gpio[3:0] output.
    XCVR_MISC->LCL_CFG0 =
        (XCVR_MISC->LCL_CFG0 & ~XCVR_MISC_LCL_CFG0_LCL_GPIO_SEL_MASK) | XCVR_MISC_LCL_CFG0_LCL_GPIO_SEL(1);

    /* RFMC_RFGPO_SRC[2:0]
      010b - RF_GPO[7:0] = {lant_lut_gpio[3:0], fem_ctrl[3:0]}
      011b - RF_GPO[7:0] = {fem_ctrl[3:0], lant_lut_gpio[3:0]}
      100b - RF_GPO[7:0] = {lant_lut_gpio[3:0], coext[3:0]}
      101b - RF_GPO[7:0] = {coext[3:0], lant_lut_gpio[3:0]} */
    RFMC->RF2P4GHZ_COEXT =
        (RFMC->RF2P4GHZ_COEXT & ~RFMC_RF2P4GHZ_COEXT_RFGPO_SRC_MASK) | RFMC_RF2P4GHZ_COEXT_RFGPO_SRC(2);

    // Enable RF_GPO[7:4]
    RFMC->RF2P4GHZ_COEXT =
        (RFMC->RF2P4GHZ_COEXT & ~RFMC_RF2P4GHZ_COEXT_RFGPO_OBE_MASK) | RFMC_RF2P4GHZ_COEXT_RFGPO_OBE(0xf0);

#ifdef BT51_TEST_MODE_AOA_AOD_DTEST
    // Enable DTEST
    // CLOCK_EnableClock(kCLOCK_PortA);
    CLOCK_EnableClock(kCLOCK_PortB);
    CLOCK_EnableClock(kCLOCK_PortC);
    // CLOCK_EnableClock(kCLOCK_PortD);

    PORT_SetPinMux(PORTC, 0U, kPORT_MuxAlt8);
    PORT_SetPinMux(PORTC, 1U, kPORT_MuxAlt8);
    PORT_SetPinMux(PORTC, 2U, kPORT_MuxAlt8);
    PORT_SetPinMux(PORTC, 3U, kPORT_MuxAlt8);
    PORT_SetPinMux(PORTC, 4U, kPORT_MuxAlt8);
    PORT_SetPinMux(PORTC, 5U, kPORT_MuxAlt8);
    PORT_SetPinMux(PORTC, 6U, kPORT_MuxAlt8);
    PORT_SetPinMux(PORTB, 0U, kPORT_MuxAlt8);
    PORT_SetPinMux(PORTB, 1U, kPORT_MuxAlt8);
    PORT_SetPinMux(PORTB, 2U, kPORT_MuxAlt8);
    PORT_SetPinMux(PORTB, 3U, kPORT_MuxAlt8);
    PORT_SetPinMux(PORTB, 4U, kPORT_MuxAlt8);
    PORT_SetPinMux(PORTB, 5U, kPORT_MuxAlt8);
    // PORT_SetPinMux(PORTD, 2U, kPORT_MuxAlt8);

    RADIO_CTRL->DTEST_CTRL = (RADIO_CTRL->DTEST_CTRL & ~RADIO_CTRL_DTEST_CTRL_DTEST_PAGE_MASK) |
                             RADIO_CTRL_DTEST_CTRL_DTEST_EN(1) | RADIO_CTRL_DTEST_CTRL_DTEST_PAGE(0);
#endif // BT51_TEST_MODE_AOA_AOD_DTEST
#endif // BT51_TEST_MODE_AOA_AOD
}
#endif

/*!
 * @brief Function to setup RF GPO pins for a combination of coexistence.
 *
 * This function configures the RF GPO pins to support only coexistence.
 *
 * @param rfmcGpoCoex - control RF_GPO group to use
 * @param rf_active_used - control if RF_ACTIVE is used
 * @param rf_status_used - control if RF_STATUS is used
 * @param rf_status_used - control if RF_PRIO is used
 * @param coexRfNotAllowPin - control RF_NALLOWED pin
 *
 * @return The status of the configuration process. 0/1 is success/failure correspondingly.
 *
 *@note coext[3:0] = {rf_priority[1:0], rf_status, rf_active}.
 *      See KW45 Reference Manual, Section "19.2 Package pinout" for pin muxing.
 */
static uint8_t PLATFORM_COEX_pin_init(rfmcGpoCoex_t       rfmcGpoCoex,
                                      bool                rf_active_used,
                                      bool                rf_status_used,
                                      bool                rf_prio_used,
                                      coexRfNotAllowPin_t coexRfNotAllowPin)
{
    uint8_t      status = 1U;
    uint8_t      prio_stat_active;
    rfmcStatus_t rfmcStatus = gRfmcConfigurationFailure_c;

    /* Please check PLATFORM_InitLclRfGpo() & PLATFORM_InitLclDtest() to avoid conflict */

    /* create bitmap for field RF2p4GHz_COEXT's RFGPO_OBE */
    prio_stat_active = (rf_active_used ? 1U : 0U) | (rf_status_used ? 2U : 0U) | (rf_prio_used ? 4U : 0U);

    if (prio_stat_active == 0U)
    {
        /* none of RF_ACTIVE, RF_STATUS, RF_PRIO[0] is used, go to RF_NALLOWED setting */
        rfmcStatus = gRfmcSuccess_c;
    }
    else if ((rfmcGpoCoex == RFMC_GPO_FEM_3_0_COEX_3_0) || (rfmcGpoCoex == RFMC_GPO_LANT_3_0_COEX_3_0))
    {
        /* detect collision with Localization, FEM */
        if (rfmcGpoSRC == RFMC_GPO_COEX_3_0_FEM_3_0 || rfmcGpoSRC == RFMC_GPO_LANT_3_0_FEM_3_0 ||
            rfmcGpoSRC == RFMC_GPO_FEM_3_0_LANT_3_0 || rfmcGpoSRC == RFMC_GPO_COEX_3_0_LANT_3_0)
        {
            return 1U;
        }
        if ((rfmcGpoOBE & BIT_3210) != 0U)
        {
            return 1U;
        }

#if (!defined(FPGA_TARGET) || (FPGA_TARGET == 0))
        if (rf_active_used)
        {
            PORT_SetPinMux(PORTA, 18U, kPORT_MuxAlt6); /* RF_GPO 0 J2-2 RF_ACTIVE */
        }
        if (rf_status_used)
        {
            PORT_SetPinMux(PORTA, 19U, kPORT_MuxAlt6); /* RF_GPO 1 J1-5 RF_STATUS */
        }
        if (rf_prio_used)
        {
            PORT_SetPinMux(PORTA, 20U, kPORT_MuxAlt6); /* RF_GPO 2 J1-7 RF_PRIO[0] */
        }
        // PORT_SetPinMux(PORTA, 21U, kPORT_MuxAlt6);  /* RF_GPO 3 J1-8 RF_PRIO[1] useless */

        rfmcGpoOBE |= prio_stat_active; /* set b2b1b0 to RFGPO_OBE */

        rfmcStatus = RFMC_SetRfGpoConfig(rfmcGpoCoex, rfmcGpoOBE);

        rfmcGpoSRC = rfmcGpoCoex;
#else
        rfmcStatus = RFMC_SetRfGpoConfig(rfmcGpoCoex, 0xFF);
#endif /* FPGA_TARGET */
    }
    else if ((rfmcGpoCoex == RFMC_GPO_COEX_3_0_FEM_3_0) || (rfmcGpoCoex == RFMC_GPO_COEX_3_0_LANT_3_0))
    {
        /* detect collision with Localization, FEM */
        if (rfmcGpoSRC == RFMC_GPO_FEM_3_0_COEX_3_0 || rfmcGpoSRC == RFMC_GPO_LANT_3_0_FEM_3_0 ||
            rfmcGpoSRC == RFMC_GPO_FEM_3_0_LANT_3_0 || rfmcGpoSRC == RFMC_GPO_LANT_3_0_COEX_3_0)
        {
            return 1U;
        }
        if ((rfmcGpoOBE & BIT_7654) != 0U)
        {
            return 1U;
        }

#if (!defined(FPGA_TARGET) || (FPGA_TARGET == 0))
        if (rf_active_used)
        {
            PORT_SetPinMux(PORTD, 1U, kPORT_MuxAlt4); /* RF_GPO 4 J4-1 RF_ACTIVE */
        }
        if (rf_status_used)
        {
            PORT_SetPinMux(PORTD, 2U, kPORT_MuxAlt4); /* RF_GPO 5 J4-2 RF_STATUS */
        }
        if (rf_prio_used)
        {
            PORT_SetPinMux(PORTD, 3U, kPORT_MuxAlt4); /* RF_GPO 6 J4-3 RF_PRIO[0] */
        }

        rfmcGpoOBE |=
            (prio_stat_active << 4); /* set b6b5b4 to RFGPO_OBE. Don't turn on output 7, taken by RF_NOT_ALLOWED */

        rfmcStatus = RFMC_SetRfGpoConfig(rfmcGpoCoex, rfmcGpoOBE);

        rfmcGpoSRC = rfmcGpoCoex;
#else
        rfmcStatus = RFMC_SetRfGpoConfig(rfmcGpoCoex, 0xFF);
#endif /* FPGA_TARGET */
    }
    else
    {
        /* return error */
    }

    /* Configure RF_NOT_ALLOWED input pin */
    if (rfmcStatus == gRfmcSuccess_c)
    {
#if (!defined(FPGA_TARGET) || (FPGA_TARGET == 0))
        if (coexRfNotAllowPin == coexRfNotAllowPinPta16)
        {
            PORT_SetPinMux(PORTA, 16U, kPORT_MuxAsGpio); /* J1-1, PTA16 */
        }
        else if (coexRfNotAllowPin == coexRfNotAllowPinPta17)
        {
            PORT_SetPinMux(PORTA, 17U, kPORT_MuxAlt7); /* J1-2, PTA17 */
        }
        else if (coexRfNotAllowPin == coexRfNotAllowPinPtc7)
        {
            PORT_SetPinMux(PORTC, 7U, kPORT_MuxAsGpio); /* J6-10, PTC7 */
        }
        else
        {
            rfmcStatus = gRfmcConfigurationFailure_c; /* return error */
        }
#else
        PORT_SetPinMux(PORTD, 6U, kPORT_MuxAlt5); /* J14-19 on FPGA, PTD6 */
#endif /* FPGA_TARGET */
    }

    if (rfmcStatus == gRfmcSuccess_c)
    {
        status = 0U;
    }
    return status;
}

/*!
 * @brief Function to setup RF GPO pins for FEM.
 *
 * This function configures the RF GPO pins to support only FEM. May conflict with Localization, Coex!
 *
 * @param rfgpo_sel - control RF_GPO group to use
 * @param ant_sel_pins_enable - control if ANT_B and ANT_A are used
 *
 * @return The status of the configuration process. 0/1 is success/failure correspondingly.
 *
 *@note Pin order fem_ctrl[3:0] = {ant_b, ant_b, rx_switch, tx_switch}.
 *      See KW45 Reference Manual, Section "19.2 Package pinout" for pin muxing.
 */
static uint8_t PLATFORM_FEM_pin_init(rfmcGpoCoex_t rfgpo_sel, uint8_t ant_sel_pins_enable)
{
    uint8_t      status     = 1U;
    rfmcStatus_t rfmcStatus = gRfmcConfigurationFailure_c;

    if (rfgpo_sel == RFMC_GPO_INVALID)
    {
        PORT_SetPinMux(PORTA, 16U, kPORT_MuxAlt7); /* RF_GPO 8  J1-1 TX_SWITCH */
        PORT_SetPinMux(PORTA, 4U, kPORT_MuxAlt3);  /* RF_GPO 9  J4-4 RX_SWITCH */
        if (ant_sel_pins_enable == 1U)
        {
            PORT_SetPinMux(PORTA, 21U, kPORT_MuxAlt9); /* RF_GPO 10 J1-8 ANT_B */
            // PORT_SetPinMux(PORTA,  1U, kPORT_MuxAlt4); /* RF_GPO 10 J?-? ANT_B other option ? */
            PORT_SetPinMux(PORTA, 0U, kPORT_MuxAlt4); /* RF_GPO 11 J?-? ANT_A */
        }
        status = 0U;
    }
    else
    {
        if (rfgpo_sel == RFMC_GPO_COEX_3_0_FEM_3_0 || rfgpo_sel == RFMC_GPO_LANT_3_0_FEM_3_0)
        {
            /* detect collision with Localization, Coex */
            if (rfmcGpoSRC == RFMC_GPO_FEM_3_0_COEX_3_0 || rfmcGpoSRC == RFMC_GPO_FEM_3_0_LANT_3_0 ||
                rfmcGpoSRC == RFMC_GPO_LANT_3_0_COEX_3_0 || rfmcGpoSRC == RFMC_GPO_COEX_3_0_LANT_3_0)
            {
                return 1U;
            }
            if ((rfmcGpoOBE & BIT_3210) != 0U)
            {
                return 1U;
            }

            PORT_SetPinMux(PORTA, 18U, kPORT_MuxAlt6); /* RF_GPO 0 J2-2 TX_SWITCH */
            PORT_SetPinMux(PORTA, 19U, kPORT_MuxAlt6); /* RF_GPO 1 J1-5 RX_SWITCH */
            if (ant_sel_pins_enable == 1U)
            {
                PORT_SetPinMux(PORTA, 20U, kPORT_MuxAlt6); /* RF_GPO 2 J1-7 ANT_B */
                PORT_SetPinMux(PORTA, 21U, kPORT_MuxAlt6); /* RF_GPO 3 J1-8 ANT_A */
                rfmcGpoOBE |= BIT_3210;                    /* set b3b2b1b0 to RFGPO_OBE */
            }
            else
            {
                rfmcGpoOBE |= BIT_10; /* set b1b0 to RFGPO_OBE */
            }

            rfmcStatus = RFMC_SetRfGpoConfig(rfgpo_sel, rfmcGpoOBE);

            rfmcGpoSRC = rfgpo_sel;
        }
        else if (rfgpo_sel == RFMC_GPO_FEM_3_0_COEX_3_0 || rfgpo_sel == RFMC_GPO_FEM_3_0_LANT_3_0)
        {
            /* detect collision with Localization, Coex */
            if (rfmcGpoSRC == RFMC_GPO_COEX_3_0_FEM_3_0 || rfmcGpoSRC == RFMC_GPO_LANT_3_0_FEM_3_0 ||
                rfmcGpoSRC == RFMC_GPO_LANT_3_0_COEX_3_0 || rfmcGpoSRC == RFMC_GPO_COEX_3_0_LANT_3_0)
            {
                return 1U;
            }
            if ((rfmcGpoOBE & BIT_7654) != 0U)
            {
                return 1U;
            }

            PORT_SetPinMux(PORTD, 1U, kPORT_MuxAlt4); /* RF_GPO 4 J4-1 TX_SWITCH */
            PORT_SetPinMux(PORTD, 2U, kPORT_MuxAlt4); /* RF_GPO 5 J4-2 RX_SWITCH */
            if (ant_sel_pins_enable == 1U)
            {
                PORT_SetPinMux(PORTD, 3U, kPORT_MuxAlt4);  /* RF_GPO 6 J4-3 ANT_B */
                PORT_SetPinMux(PORTA, 17U, kPORT_MuxAlt7); /* RF_GPO 7 J1-2 ANT_A */
                // PORT_SetPinMux(PORTA, 21U, kPORT_MuxAlt7);  /* RF_GPO 7 J1-8 ANT_A other option ? */
                rfmcGpoOBE |= BIT_7654; /* set b7b6b5b4 to RFGPO_OBE */
            }
            else
            {
                rfmcGpoOBE |= BIT_54; /* set b5b4 to RFGPO_OBE */
            }

            rfmcStatus = RFMC_SetRfGpoConfig(rfgpo_sel, rfmcGpoOBE); /* output 7 may be taken by RF_NOT_ALLOWED ! */

            rfmcGpoSRC = rfgpo_sel;
        }
        else
        {
            rfmcStatus = gRfmcConfigurationFailure_c;
        }

        if (rfmcStatus == gRfmcSuccess_c)
        {
            status = 0U;
        }
    }

    return status;
}

/*******************************************************************************
 * API
 ******************************************************************************/

uint8_t PLATFORM_InitLclRfGpo(uint8_t rfgpo_id)
{
    uint8_t      status;
    rfmcStatus_t rfmc_status = gRfmcSuccess_c;

    if (rfgpo_id > LCL_RFGPO_7_4)
    {
        status = 1U; /* out of range */
    }
    else if (rfgpo_id == LCL_RFGPO_NONE)
    {
        /* nothing to do */
        status = 0U;
    }
    else
    {
        if (rfgpo_id == LCL_RFGPO_3_0)
        {
            /* detect conflict between Localisation, Coexistence and FEM */
            if ((rfmcGpoSRC != RFMC_GPO_INVALID) && (rfmcGpoSRC != RFMC_GPO_FEM_3_0_LANT_3_0) &&
                (rfmcGpoSRC != RFMC_GPO_COEX_3_0_LANT_3_0))
            {
                return 1U;
            }

            rfmcGpoOBE |= BIT_210;
        }
        else
        {
            /* detect conflict between Localisation, Coexistence and FEM */
            if ((rfmcGpoSRC != RFMC_GPO_INVALID) && (rfmcGpoSRC != RFMC_GPO_LANT_3_0_FEM_3_0) &&
                (rfmcGpoSRC != RFMC_GPO_LANT_3_0_COEX_3_0))
            {
                return 1U;
            }

            rfmcGpoOBE |= BIT_654;
        }

        /* keep rfmcGpoSRC as is if valid & compatible */
        rfmcGpoSRC = (rfmcGpoSRC != RFMC_GPO_INVALID) ? rfmcGpoSRC : gAppRfGpoSRC;

        /* Configure RFMC to route lant_lut_gpio[3:0] to SoC RF_GPO[3:0] or RF_GPO[7:4] */
        rfmc_status = RFMC_SetRfGpoConfig(rfmcGpoSRC, rfmcGpoOBE);
        status      = (rfmc_status == gRfmcSuccess_c) ? 0U : 1U;
    }

    return status;
}

void PLATFORM_InitLclGpioDebug(bool_t debug)
{
#if !defined(NDEBUG)
    /* TRDC initialized during NBU initialization */
    if (debug)
    {
        const gpio_pin_config_t config = {
            .pinDirection = kGPIO_DigitalOutput,
            .outputLogic  = 0,
        };

        PORT_SetPinMux(PORTD, 2U, kPORT_MuxAsGpio);
        PORT_SetPinMux(PORTD, 3U, kPORT_MuxAsGpio);
        GPIO_PinInit(GPIOD, 3U, &config);
        GPIO_PinInit(GPIOD, 2U, &config);

        /* Enable GPIO for application core debugging */
        PORT_SetPinMux(PORTC, 4U, kPORT_MuxAsGpio);
        GPIO_PinInit(GPIOC, 4U, &config);
    }
    else
    {
#if defined(FWK_KW47_MCXW72_FAMILIES) || (FWK_KW47_MCXW72_FAMILIES == 1)
#if defined(BOARD_LOCALIZATION_REVISION_SUPPORT) && (BOARD_LOCALIZATION_REVISION_SUPPORT > 0)
        /* only KW47-LOC needs PTD2 */
        PORT_SetPinMux(PORTD, 2U, kPORT_MuxAlt4);
#endif
#endif
    }
#endif
}

uint8_t PLATFORM_InitLcl(void)
{
    uint8_t rfgpo_id;

    /* set debug pins first which could be overriden later */
    PLATFORM_InitLclGpioDebug(true);

#if defined(KW45B41Z82_SERIES) || defined(KW45B41Z83_SERIES)
    rfgpo_id = LCL_RFGPO_3_0;

    CLOCK_EnableClock(kCLOCK_PortA);
    /* enable RF_GPO[2:0] */
    PORT_SetPinMux(PORTA, 18U, kPORT_MuxAlt6);
    PORT_SetPinMux(PORTA, 19U, kPORT_MuxAlt6);
    PORT_SetPinMux(PORTA, 20U, kPORT_MuxAlt6);
#else /* KW47 and more series */
#if defined(BOARD_LOCALIZATION_REVISION_SUPPORT) && (BOARD_LOCALIZATION_REVISION_SUPPORT > 0)
    rfgpo_id = LCL_RFGPO_7_4;

    /* enable RF_GPO[6:4] */
    /* PLATFORM_InitLclGpioDebug() may set PORTD 2 & 3 as kPORT_MuxAsGpio */
    //PORT_SetPinMux(PORTD, 1U, kPORT_MuxAlt4);
    PORT_SetPinMux(PORTD, 2U, kPORT_MuxAlt4);
    PORT_SetPinMux(PORTD, 3U, kPORT_MuxAlt4);

    /* need to power PTD1 as VDD to RF Switch */
    const gpio_pin_config_t config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic  = 1,
    };
    GPIO_PinInit(GPIOD, 1U, &config);
    PORT_SetPinMux(PORTD, 1U, kPORT_MuxAsGpio);
    //PORT_SetPinMux(PORTD, 2U, kPORT_MuxAlt4);
#else
    rfgpo_id = LCL_RFGPO_3_0;

    CLOCK_EnableClock(kCLOCK_PortA);
    /* enable RF_GPO[2:0] */
    PORT_SetPinMux(PORTA, 18U, kPORT_MuxAlt6);
    PORT_SetPinMux(PORTA, 19U, kPORT_MuxAlt6);
    PORT_SetPinMux(PORTA, 20U, kPORT_MuxAlt6);
#endif
#endif
    uint8_t status = PLATFORM_InitLclRfGpo(rfgpo_id);

#ifdef ENABLE_DTEST
    /* Enable DTEST when building debug target */
    PLATFORM_InitLclDtest();
#endif

    return status;
}

uint8_t PLATFORM_InitCOEX(const uint8_t *p_config, uint8_t config_len)
{
    const uint8_t           *config_ptr;
    uint8_t                  status         = 1U;
    xcvrCoexStatus_t         xcvrCoexStatus = gXcvrCoexStatusFail;
    bool                     rf_active_used, rf_status_used, rf_prio_used, tsm_controls_coex;
    rfmcGpoCoex_t            rfmcGpoCoex;
    coexRfactSrc_t           rfactSrc;
    coexRfSignalInvert_t     signal_invert_cfg;
    coexRfNotAllowedConfig_t rf_not_allowed_cfg;
    coexRfActiveTsmConfig_t  rfact_tsm_cfg;
    // coexRfActiveRfmcConfig_t rfact_rfmc_cfg;
    coexRfStatusConfig_t   rfstat_tsm_cfg;
    coexRfPriorityConfig_t rfpri_on_stat_tsm_cfg;
    XCVR_COEX_PRIORITY_T   rxPriority, txPriority;

    /* use the input configuration if provided and its length is correct, otherwise use the default */
    if (p_config != NULL)
    {
        /* check the coherence in size of COEX config coming from application w.r.t XCVR */
        if (config_len == COEX_CONFIG_LEN)
        {
            config_ptr = p_config;
        }
        else
        {
            return 1U;
        }
    }
    else
    {
        config_ptr = default_COEX_config;
    }

    /* convert config data to XCVR parameters */
    rf_active_used    = (bool)config_ptr[0];
    rf_status_used    = (bool)config_ptr[1];
    rf_prio_used      = (bool)config_ptr[2];
    rfmcGpoCoex       = (rfmcGpoCoex_t)config_ptr[3];
    tsm_controls_coex = (bool)config_ptr[4];
    rfactSrc          = (coexRfactSrc_t)config_ptr[5];

    signal_invert_cfg.rfna_invert     = (bool)config_ptr[6];
    signal_invert_cfg.rfact_invert    = (bool)config_ptr[7];
    signal_invert_cfg.rfstat_invert   = (bool)config_ptr[8];
    signal_invert_cfg.rfpri_invert[0] = (bool)config_ptr[9];
    signal_invert_cfg.rfpri_invert[1] = (bool)config_ptr[10];

    rf_not_allowed_cfg.rfna_pin_enable        = (coexRfNotAllowPin_t)config_ptr[11];
    rf_not_allowed_cfg.link_layer_rfna_select = (coexRfNotAllowLL_t)config_ptr[12];

    rfact_tsm_cfg.rf_act_extend     = config_ptr[13];
    rfact_tsm_cfg.rf_act_tx_advance = config_ptr[14];
    rfact_tsm_cfg.rf_act_rx_advance = config_ptr[15];

    // rfact_rfmc_cfg.deassert_when_tsm_idle = config_ptr[16];
    // rfact_rfmc_cfg.wakeup_delay = config_ptr[17];

    rfstat_tsm_cfg.rf_stat_tx_advance = config_ptr[18];

    rfpri_on_stat_tsm_cfg.rf_pri_rx_advance = config_ptr[19];
    rfpri_on_stat_tsm_cfg.rf_pri_tx_advance = config_ptr[20];
    rfpri_on_stat_tsm_cfg.rf_pri_on_rf_stat = (bool)config_ptr[21];

    rxPriority = (XCVR_COEX_PRIORITY_T)config_ptr[22];
    txPriority = (XCVR_COEX_PRIORITY_T)config_ptr[23];

    /* configure the source of output signals and their inversions */
    xcvrCoexStatus = XCVR_COEX_SelectController(tsm_controls_coex, rfactSrc, &signal_invert_cfg);

    if (xcvrCoexStatus == gXcvrCoexStatusSuccess)
    {
        if (rf_not_allowed_cfg.link_layer_rfna_select == coexRfNotAllowLLBluetooth)
        {
            xcvrCoexStatus = XCVR_COEX_RfNotAllowedInit(&rf_not_allowed_cfg);
        }
        else
        {
            xcvrCoexStatus = gXcvrCoexStatusFail; /* TBD, actually return error */
        }
    }

    if (xcvrCoexStatus == gXcvrCoexStatusSuccess)
    {
        xcvrCoexStatus = gXcvrCoexStatusSuccess;

        if (rfactSrc == coexRfactTsmLl)
        {
            /* configure RF_ACTIVE signal if requested */
            if (rf_active_used)
            {
                xcvrCoexStatus = XCVR_COEX_RfActiveTsmInit(&rfact_tsm_cfg);
            }

            /* configure RF_STATUS signal if requested */
            if ((xcvrCoexStatus == gXcvrCoexStatusSuccess) && rf_status_used)
            {
                xcvrCoexStatus = XCVR_COEX_RfStatusTsmInit(&rfstat_tsm_cfg);
            }

            /* configure RF_PRIO's signal if requested */
            if ((xcvrCoexStatus == gXcvrCoexStatusSuccess) && rf_prio_used)
            {
                if (xcvrCoexStatus == gXcvrCoexStatusSuccess)
                {
                    xcvrCoexStatus = XCVR_COEX_RfPriorityTsmInit(&rfpri_on_stat_tsm_cfg);
                }
                /* configure TX and RX priorities */
                if (xcvrCoexStatus == gXcvrCoexStatusSuccess)
                {
                    xcvrCoexStatus = XCVR_COEX_SetPriority(rxPriority, txPriority);
                }
            }
        }
        else /* TBD, actually return error */
        {
            xcvrCoexStatus = gXcvrCoexStatusFail;
        }

        /* configure output and input signals to RF_GPO[7:0] */
        if (xcvrCoexStatus == gXcvrCoexStatusSuccess)
        {
            uint8_t pin_status = PLATFORM_COEX_pin_init(rfmcGpoCoex, rf_active_used, rf_status_used, rf_prio_used,
                                                        rf_not_allowed_cfg.rfna_pin_enable);
            xcvrCoexStatus     = (pin_status != 0U) ? gXcvrCoexStatusFail : gXcvrCoexStatusSuccess;
        }
    }

    if (xcvrCoexStatus == gXcvrCoexStatusSuccess)
    {
        status = 0U;

#ifdef ENABLE_DTEST
        PLATFORM_Init_Dtest_TX_RX_EN(); /* Enable DTEST when building debug target */
#endif
    }

    return status;
}

uint8_t PLATFORM_InitFEM(const uint8_t *p_config, uint8_t config_len)
{
    uint8_t              status = 1U;
    const uint8_t       *config_ptr;
    xcvrStatus_t         xcvr_status;
    xcvr_pa_fem_config_t pa_fem_settings;
    rfmcGpoCoex_t        rfgpo_sel;

    /* use the input configuration if provided and its length is correct, otherwise use the default */
    if (p_config != NULL)
    {
        if (config_len == FEM_CONFIG_LEN)
        {
            config_ptr = p_config;
        }
        else
        {
            return 1U;
        }
    }
    else
    {
        config_ptr = default_FEM_config;
    }
    assert(config_ptr[2] == 1); /* tx_rx_switch_pins_enable must enabled */

    /* convert config data to xcvr_pa_fem_config_t */
    pa_fem_settings.op_mode                  = (XCVR_ANTX_MODE_T)config_ptr[0];
    pa_fem_settings.ant_sel_pins_enable      = config_ptr[1];
    pa_fem_settings.tx_rx_switch_pins_enable = config_ptr[2];
    pa_fem_settings.high_z_enable            = config_ptr[3];
    pa_fem_settings.use_fad_state_machine    = config_ptr[4];
    pa_fem_settings.ant_a_pad_control        = (XCVR_FAD_NOT_GPIO_MODE_T)config_ptr[5];
    pa_fem_settings.ant_b_pad_control        = (XCVR_FAD_NOT_GPIO_MODE_T)config_ptr[6];
    pa_fem_settings.tx_switch_pad_control    = (XCVR_FAD_NOT_GPIO_MODE_T)config_ptr[7];
    pa_fem_settings.rx_switch_pad_control    = (XCVR_FAD_NOT_GPIO_MODE_T)config_ptr[8];
    pa_fem_settings.pa_tx_wu                 = config_ptr[9];
    pa_fem_settings.pa_tx_wd                 = config_ptr[10];
    pa_fem_settings.lna_rx_wu                = config_ptr[11];
    pa_fem_settings.lna_rx_wd                = config_ptr[12];
    pa_fem_settings.tx_switch_pol_control    = (XCVR_RX_TX_POLARITY_MODE_T)config_ptr[13];
    pa_fem_settings.rx_switch_pol_control    = (XCVR_RX_TX_POLARITY_MODE_T)config_ptr[14];

    rfgpo_sel = (rfmcGpoCoex_t)config_ptr[15];

    /* configure XCVR part */
    xcvr_status = XCVR_ExternalFadPaFemInit(&pa_fem_settings);

    if (xcvr_status == gXcvrSuccess_c)
    {
        /* configure RF_GPO pins for the output signals */
        status = PLATFORM_FEM_pin_init(rfgpo_sel, pa_fem_settings.ant_sel_pins_enable);

#ifdef ENABLE_DTEST
        PLATFORM_Init_Dtest_TX_RX_EN(); /* Enable DTEST when building debug target */
#endif
    }
    else
    {
        status = 1U;
    }
    return status;
}