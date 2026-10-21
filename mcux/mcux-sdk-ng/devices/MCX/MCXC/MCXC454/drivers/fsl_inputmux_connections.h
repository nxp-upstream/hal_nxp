/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_INPUTMUX_CONNECTIONS_
#define _FSL_INPUTMUX_CONNECTIONS_

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.inputmux_connections"
#endif

/*! @name Driver version */
/*@{*/
/*! @brief INPUTMUX_CONNECTION driver version 2.0.0. */
#define FSL_INPUTMUX_CONNECTION_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

#define INPUTMUX_GpioPortPinToPintsel(port, pin) ((pin) + (PINTSEL_PMUX_ID << PMUX_SHIFT))

/*!
 * @addtogroup inputmux_driver
 * @{
 */

/*!
 * @name Input multiplexing connections
 * @{
 */

/*! @brief Periphinmux IDs */
#define CTIMER0CAPn_REG  0x20U
#define CTIMER1CAPn_REG  0x40U
#define CTIMER2CAPn_REG  0x60U
#define ADC0_TRIGn_REG   0x280U
#define EXT_TRIGn_REG    0x4C0U
#define AOI0INPUTn_REG   0x440U
#define CTIMER0TRIG_REG  0x30U
#define CTIMER1TRIG_REG  0x50U
#define CTIMER2TRIG_REG  0x70U
#define FREQMEAS_REF_REG 0x180U
#define FREQMEAS_TAR_REG 0x184U
#define LPCMP0_TRIG_REG  0x260U
#define FlexPWM0_SM0_EXTA0_REG 0x3A0U
#define FlexPWM0_SM0_EXTSYNC_REG 0x3A4U
#define FlexPWM0_SM1_EXTA_REG 0x3A8U
#define FlexPWM0_SM1_EXTSYNC_REG 0x3ACU
#define FlexPWM0_SM2_EXTA_REG 0x3B0U
#define FlexPWM0_SM2_EXTSYNC_REG 0x3B4U
#define FlexPWM0_SM3_EXTA_REG 0x3B8U
#define FlexPWM0_SM3_EXTSYNC_REG 0x3BCU
#define FlexPWM0_FAULT0_REG 0x3C0U
#define FlexPWM0_FAULT1_REG 0x3C4U
#define FlexPWM0_FAULT2_REG 0x3C8U
#define FlexPWM0_FAULT3_REG 0x3CCU
#define FlexPWM0_FORCE_REG 0x3D0U
#define PWM0_EXT_CLK_REG 0x420U
#define LPI2C0_TRIG_REG  0x5A0U
#define LPI2C1_TRIG_REG  0x5C0U
#define LPI2C2_TRIG_REG  0x540U
#define LPSPI0_TRIG_REG  0x5E0U
#define LPSPI1_TRIG_REG  0x600U
#define LPUART0_REG      0x620U
#define LPUART1_REG      0x640U
#define LPUART2_REG      0x660U
#define LPUART3_REG      0x680U
#define LPUART4_REG      0x6A0U
#define TSI0_REG         0x4A0U


#define PMUX_SHIFT 20U

typedef enum _inputmux_index_t
{
    kINPUTMUX_INDEX_CTIMER0CAP0      = 0U,
    kINPUTMUX_INDEX_CTIMER0CAP1      = 1U,
    kINPUTMUX_INDEX_CTIMER0CAP2      = 2U,
    kINPUTMUX_INDEX_CTIMER0CAP3      = 3U,
    kINPUTMUX_INDEX_CTIMER1CAP0      = 0U,
    kINPUTMUX_INDEX_CTIMER1CAP1      = 1U,
    kINPUTMUX_INDEX_CTIMER1CAP2      = 2U,
    kINPUTMUX_INDEX_CTIMER1CAP3      = 3U,
    kINPUTMUX_INDEX_CTIMER2CAP0      = 0U,
    kINPUTMUX_INDEX_CTIMER2CAP1      = 1U,
    kINPUTMUX_INDEX_CTIMER2CAP2      = 2U,
    kINPUTMUX_INDEX_CTIMER2CAP3      = 3U,
    kINPUTMUX_INDEX_ADC0_TRIG0       = 0U,
    kINPUTMUX_INDEX_ADC0_TRIG1       = 1U,
    kINPUTMUX_INDEX_ADC0_TRIG2       = 2U,
    kINPUTMUX_INDEX_ADC0_TRIG3       = 3U,
    kINPUTMUX_INDEX_EXT_TRIG0        = 0U,
    kINPUTMUX_INDEX_EXT_TRIG1        = 1U,
    kINPUTMUX_INDEX_EXT_TRIG2        = 2U,
    kINPUTMUX_INDEX_EXT_TRIG3        = 3U,
    kINPUTMUX_INDEX_EXT_TRIG4        = 4U,
    kINPUTMUX_INDEX_EXT_TRIG5        = 5U,
    kINPUTMUX_INDEX_EXT_TRIG6        = 6U,
    kINPUTMUX_INDEX_EXT_TRIG7        = 7U,
    kINPUTMUX_INDEX_AOI0INPUT0       = 0U,
    kINPUTMUX_INDEX_AOI0INPUT1       = 1U,
    kINPUTMUX_INDEX_AOI0INPUT2       = 2U,
    kINPUTMUX_INDEX_AOI0INPUT3       = 3U,
    kINPUTMUX_INDEX_AOI0INPUT4       = 4U,
    kINPUTMUX_INDEX_AOI0INPUT5       = 5U,
    kINPUTMUX_INDEX_AOI0INPUT6       = 6U,
    kINPUTMUX_INDEX_AOI0INPUT7       = 7U,
    kINPUTMUX_INDEX_AOI0INPUT8       = 8U,
    kINPUTMUX_INDEX_AOI0INPUT9       = 9U,
    kINPUTMUX_INDEX_AOI0INPUT10      = 10U,
    kINPUTMUX_INDEX_AOI0INPUT11      = 11U,
    kINPUTMUX_INDEX_AOI0INPUT12      = 12U,
    kINPUTMUX_INDEX_AOI0INPUT13      = 13U,
    kINPUTMUX_INDEX_AOI0INPUT14      = 14U,
    kINPUTMUX_INDEX_AOI0INPUT15      = 15U,
    kINPUTMUX_INDEX_CTIMER0TRIG      = 0U,
    kINPUTMUX_INDEX_CTIMER1TRIG      = 0U,
    kINPUTMUX_INDEX_CTIMER2TRIG      = 0U,
    kINPUTMUX_INDEX_FREQMEAS_REF     = 0U,
    kINPUTMUX_INDEX_FREQMEAS_TAR     = 0U,
    kINPUTMUX_INDEX_LPCMP0_TRIG      = 0U,
    kINPUTMUX_INDEX_FlexPWM0_SM0_EXTA0 = 0U,
    kINPUTMUX_INDEX_FlexPWM0_SM0_EXTSYNC = 0U,
    kINPUTMUX_INDEX_FlexPWM0_SM1_EXTA = 0U,
    kINPUTMUX_INDEX_FlexPWM0_SM1_EXTSYNC = 0U,
    kINPUTMUX_INDEX_FlexPWM0_SM2_EXTA = 0U,
    kINPUTMUX_INDEX_FlexPWM0_SM2_EXTSYNC = 0U,
    kINPUTMUX_INDEX_FlexPWM0_SM3_EXTA = 0U,
    kINPUTMUX_INDEX_FlexPWM0_SM3_EXTSYNC = 0U,
    kINPUTMUX_INDEX_FlexPWM0_FAULT0  = 0U,
    kINPUTMUX_INDEX_FlexPWM0_FAULT1  = 0U,
    kINPUTMUX_INDEX_FlexPWM0_FAULT2  = 0U,
    kINPUTMUX_INDEX_FlexPWM0_FAULT3  = 0U,
    kINPUTMUX_INDEX_FlexPWM0_FORCE   = 0U,
    kINPUTMUX_INDEX_PWM0_EXT_CLK     = 0U,
    kINPUTMUX_INDEX_LPI2C0_TRIG      = 0U,
    kINPUTMUX_INDEX_LPI2C1_TRIG      = 0U,
    kINPUTMUX_INDEX_LPI2C2_TRIG      = 0U,
    kINPUTMUX_INDEX_LPSPI0_TRIG      = 0U,
    kINPUTMUX_INDEX_LPSPI1_TRIG      = 0U,
    kINPUTMUX_INDEX_LPUART0          = 0U,
    kINPUTMUX_INDEX_LPUART1          = 0U,
    kINPUTMUX_INDEX_LPUART2          = 0U,
    kINPUTMUX_INDEX_LPUART3          = 0U,
    kINPUTMUX_INDEX_LPUART4          = 0U,
    kINPUTMUX_INDEX_TSI0             = 0U,
} inputmux_index_t;

/*! @brief INPUTMUX connections type */
typedef enum _inputmux_connection_t
{
    /*!< CTIMER0CAPn: Capture select register for CTIMER0 inputs */
    kINPUTMUX_CtInp0ToCTIMER0CAP = 1U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp0 input is selected */
    kINPUTMUX_CtInp1ToCTIMER0CAP = 2U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp1 input is selected */
    kINPUTMUX_CtInp2ToCTIMER0CAP = 3U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp2 input is selected */
    kINPUTMUX_CtInp3ToCTIMER0CAP = 4U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp3 input is selected */
    kINPUTMUX_CtInp4ToCTIMER0CAP = 5U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp4 input is selected */
    kINPUTMUX_CtInp5ToCTIMER0CAP = 6U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp5 input is selected */
    kINPUTMUX_CtInp6ToCTIMER0CAP = 7U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp6 input is selected */
    kINPUTMUX_CtInp7ToCTIMER0CAP = 8U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp7 input is selected */
    kINPUTMUX_CtInp8ToCTIMER0CAP = 9U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp8 input is selected */
    kINPUTMUX_CtInp9ToCTIMER0CAP = 10U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp9 input is selected */
    kINPUTMUX_CtInp10ToCTIMER0CAP = 11U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp10 input is selected */
    kINPUTMUX_CtInp11ToCTIMER0CAP = 12U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp11 input is selected */
    kINPUTMUX_CtInp12ToCTIMER0CAP = 13U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp12 input is selected */
    kINPUTMUX_CtInp13ToCTIMER0CAP = 14U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp13 input is selected */
    kINPUTMUX_CtInp14ToCTIMER0CAP = 15U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp14 input is selected */
    kINPUTMUX_CtInp15ToCTIMER0CAP = 16U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp15 input is selected */
    kINPUTMUX_CtInp16ToCTIMER0CAP = 17U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp16 input is selected */
    kINPUTMUX_CtInp17ToCTIMER0CAP = 18U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp17 input is selected */
    kINPUTMUX_CtInp18ToCTIMER0CAP = 19U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp18 input is selected */
    kINPUTMUX_CtInp19ToCTIMER0CAP = 20U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp19 input is selected */
    kINPUTMUX_Aoi0Out0ToCTIMER0CAP = 22U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToCTIMER0CAP = 23U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToCTIMER0CAP = 24U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToCTIMER0CAP = 25U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Adc0Tcomp0ToCTIMER0CAP = 26U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[0] input is selected */
    kINPUTMUX_Adc0Tcomp1ToCTIMER0CAP = 27U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[1] input is selected */
    kINPUTMUX_Adc0Tcomp2ToCTIMER0CAP = 28U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[2] input is selected */
    kINPUTMUX_Adc0Tcomp3ToCTIMER0CAP = 29U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[3] input is selected */
    kINPUTMUX_Cmp0OutToCTIMER0CAP = 30U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Lpi2c2MeopToCTIMER0CAP = 31U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpi2c2 master end of packet input is selected */
    kINPUTMUX_Lpi2c2SeopToCTIMER0CAP = 32U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpi2c2 slave end of packet input is selected */
    kINPUTMUX_Ctimer1Mat1ToCTIMER0CAP = 33U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat2ToCTIMER0CAP = 34U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToCTIMER0CAP = 35U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat1ToCTIMER0CAP = 36U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat2ToCTIMER0CAP = 37U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToCTIMER0CAP = 38U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig0ToCTIMER0CAP = 44U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig0ToCTIMER0CAP = 45U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig0ToCTIMER0CAP = 46U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig0ToCTIMER0CAP = 47U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig0 input is selected */
    kINPUTMUX_Lpi2c0MeopToCTIMER0CAP = 48U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpi2c0 master end of packet input is selected */
    kINPUTMUX_Lpi2c0SeopToCTIMER0CAP = 49U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpi2c0 slave end of packet input is selected */
    kINPUTMUX_Lpi2c1MeopToCTIMER0CAP = 50U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpi2c1 master end of packet input is selected */
    kINPUTMUX_Lpi2c1SeopToCTIMER0CAP = 51U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpi2c1 slave end of packet input is selected */
    kINPUTMUX_Lpspi0EofToCTIMER0CAP = 52U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpspi0 end of frame input is selected */
    kINPUTMUX_Lpspi0RdwToCTIMER0CAP = 53U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpspi0 received data word input is selected */
    kINPUTMUX_Lpspi1EofToCTIMER0CAP = 54U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpspi1 end of frame input is selected */
    kINPUTMUX_Lpspi1RdwToCTIMER0CAP = 55U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpspi1 received data word input is selected */
    kINPUTMUX_Lpuart0RdwToCTIMER0CAP = 56U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 received data word input is selected */
    kINPUTMUX_Lpuart0TdwToCTIMER0CAP = 57U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word input is selected */
    kINPUTMUX_Lpuart0RliToCTIMER0CAP = 58U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle input is selected */
    kINPUTMUX_Lpuart1RdwToCTIMER0CAP = 59U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 received data word input is selected */
    kINPUTMUX_Lpuart1TdwToCTIMER0CAP = 60U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 transmitted data word input is selected */
    kINPUTMUX_Lpuart1RliToCTIMER0CAP = 61U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 receive line idle input is selected */
    kINPUTMUX_Lpuart2RdwToCTIMER0CAP = 62U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart2 received data word input is selected */
    kINPUTMUX_Lpuart2TdwToCTIMER0CAP = 63U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart2 transmitted data word input is selected */
    kINPUTMUX_Lpuart2RliToCTIMER0CAP = 64U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart2 receive line idle input is selected */
    kINPUTMUX_TrigIn0ToCTIMER0CAP = 65U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToCTIMER0CAP = 66U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToCTIMER0CAP = 67U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToCTIMER0CAP = 68U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToCTIMER0CAP = 69U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToCTIMER0CAP = 70U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToCTIMER0CAP = 71U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToCTIMER0CAP = 72U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToCTIMER0CAP = 73U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToCTIMER0CAP = 74U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToCTIMER0CAP = 75U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToCTIMER0CAP = 76U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Lpuart3RdwToCTIMER0CAP = 77U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart3 received data word input is selected */
    kINPUTMUX_Lpuart3TdwToCTIMER0CAP = 78U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart3 transmitted data word input is selected */
    kINPUTMUX_Lpuart3RliToCTIMER0CAP = 79U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart3 receive line idle input is selected */
    kINPUTMUX_Lpuart4RdwToCTIMER0CAP = 80U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart4 received data word input is selected */
    kINPUTMUX_Lpuart4TdwToCTIMER0CAP = 81U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart4 transmitted data word input is selected */
    kINPUTMUX_Lpuart4RliToCTIMER0CAP = 82U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart4 receive line idle input is selected */

    /*!< CTIMER1CAPn: Capture select register for CTIMER1 inputs */
    kINPUTMUX_CtInp0ToCTIMER1CAP = 1U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp0 input is selected */
    kINPUTMUX_CtInp1ToCTIMER1CAP = 2U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp1 input is selected */
    kINPUTMUX_CtInp2ToCTIMER1CAP = 3U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp2 input is selected */
    kINPUTMUX_CtInp3ToCTIMER1CAP = 4U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp3 input is selected */
    kINPUTMUX_CtInp4ToCTIMER1CAP = 5U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp4 input is selected */
    kINPUTMUX_CtInp5ToCTIMER1CAP = 6U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp5 input is selected */
    kINPUTMUX_CtInp6ToCTIMER1CAP = 7U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp6 input is selected */
    kINPUTMUX_CtInp7ToCTIMER1CAP = 8U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp7 input is selected */
    kINPUTMUX_CtInp8ToCTIMER1CAP = 9U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp8 input is selected */
    kINPUTMUX_CtInp9ToCTIMER1CAP = 10U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp9 input is selected */
    kINPUTMUX_CtInp10ToCTIMER1CAP = 11U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp10 input is selected */
    kINPUTMUX_CtInp11ToCTIMER1CAP = 12U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp11 input is selected */
    kINPUTMUX_CtInp12ToCTIMER1CAP = 13U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp12 input is selected */
    kINPUTMUX_CtInp13ToCTIMER1CAP = 14U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp13 input is selected */
    kINPUTMUX_CtInp14ToCTIMER1CAP = 15U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp14 input is selected */
    kINPUTMUX_CtInp15ToCTIMER1CAP = 16U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp15 input is selected */
    kINPUTMUX_CtInp16ToCTIMER1CAP = 17U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp16 input is selected */
    kINPUTMUX_CtInp17ToCTIMER1CAP = 18U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp17 input is selected */
    kINPUTMUX_CtInp18ToCTIMER1CAP = 19U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp18 input is selected */
    kINPUTMUX_CtInp19ToCTIMER1CAP = 20U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp19 input is selected */
    kINPUTMUX_Aoi0Out0ToCTIMER1CAP = 22U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToCTIMER1CAP = 23U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToCTIMER1CAP = 24U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToCTIMER1CAP = 25U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Adc0Tcomp0ToCTIMER1CAP = 26U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[0] input is selected */
    kINPUTMUX_Adc0Tcomp1ToCTIMER1CAP = 27U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[1] input is selected */
    kINPUTMUX_Adc0Tcomp2ToCTIMER1CAP = 28U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[2] input is selected */
    kINPUTMUX_Adc0Tcomp3ToCTIMER1CAP = 29U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[3] input is selected */
    kINPUTMUX_Cmp0OutToCTIMER1CAP = 30U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Lpi2c2MeopToCTIMER1CAP = 31U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpi2c2 master end of packet input is selected */
    kINPUTMUX_Lpi2c2SeopToCTIMER1CAP = 32U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpi2c2 slave end of packet input is selected */
    kINPUTMUX_Ctimer0Mat1ToCTIMER1CAP = 33U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer0Mat2ToCTIMER1CAP = 34U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToCTIMER1CAP = 35U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat1ToCTIMER1CAP = 36U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat2ToCTIMER1CAP = 37U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToCTIMER1CAP = 38U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig0ToCTIMER1CAP = 44U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig0ToCTIMER1CAP = 45U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig0ToCTIMER1CAP = 46U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig0ToCTIMER1CAP = 47U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig0 input is selected */
    kINPUTMUX_Lpi2c0MeopToCTIMER1CAP = 48U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpi2c0 master end of packet input is selected */
    kINPUTMUX_Lpi2c0SeopToCTIMER1CAP = 49U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpi2c0 slave end of packet input is selected */
    kINPUTMUX_Lpi2c1MeopToCTIMER1CAP = 50U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpi2c1 master end of packet input is selected */
    kINPUTMUX_Lpi2c1SeopToCTIMER1CAP = 51U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpi2c1 slave end of packet input is selected */
    kINPUTMUX_Lpspi0EofToCTIMER1CAP = 52U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpspi0 end of frame input is selected */
    kINPUTMUX_Lpspi0RdwToCTIMER1CAP = 53U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpspi0 received data word input is selected */
    kINPUTMUX_Lpspi1EofToCTIMER1CAP = 54U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpspi1 end of frame input is selected */
    kINPUTMUX_Lpspi1RdwToCTIMER1CAP = 55U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpspi1 received data word input is selected */
    kINPUTMUX_Lpuart0RdwToCTIMER1CAP = 56U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 received data word input is selected */
    kINPUTMUX_Lpuart0TdwToCTIMER1CAP = 57U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word input is selected */
    kINPUTMUX_Lpuart0RliToCTIMER1CAP = 58U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle input is selected */
    kINPUTMUX_Lpuart1RdwToCTIMER1CAP = 59U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 received data word input is selected */
    kINPUTMUX_Lpuart1TdwToCTIMER1CAP = 60U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 transmitted data word input is selected */
    kINPUTMUX_Lpuart1RliToCTIMER1CAP = 61U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 receive line idle input is selected */
    kINPUTMUX_Lpuart2RdwToCTIMER1CAP = 62U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart2 received data word input is selected */
    kINPUTMUX_Lpuart2TdwToCTIMER1CAP = 63U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart2 transmitted data word input is selected */
    kINPUTMUX_Lpuart2RliToCTIMER1CAP = 64U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart2 receive line idle input is selected */
    kINPUTMUX_TrigIn0ToCTIMER1CAP = 65U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToCTIMER1CAP = 66U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToCTIMER1CAP = 67U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToCTIMER1CAP = 68U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToCTIMER1CAP = 69U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToCTIMER1CAP = 70U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToCTIMER1CAP = 71U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToCTIMER1CAP = 72U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToCTIMER1CAP = 73U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToCTIMER1CAP = 74U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToCTIMER1CAP = 75U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToCTIMER1CAP = 76U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Lpuart3RdwToCTIMER1CAP = 77U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart3 received data word input is selected */
    kINPUTMUX_Lpuart3TdwToCTIMER1CAP = 78U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart3 transmitted data word input is selected */
    kINPUTMUX_Lpuart3RliToCTIMER1CAP = 79U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart3 receive line idle input is selected */
    kINPUTMUX_Lpuart4RdwToCTIMER1CAP = 80U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart4 received data word input is selected */
    kINPUTMUX_Lpuart4TdwToCTIMER1CAP = 81U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart4 transmitted data word input is selected */
    kINPUTMUX_Lpuart4RliToCTIMER1CAP = 82U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart4 receive line idle input is selected */

    /*!< CTIMER2CAPn: Capture select register for CTIMER2 inputs */
    kINPUTMUX_CtInp0ToCTIMER2CAP = 1U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp0 input is selected */
    kINPUTMUX_CtInp1ToCTIMER2CAP = 2U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp1 input is selected */
    kINPUTMUX_CtInp2ToCTIMER2CAP = 3U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp2 input is selected */
    kINPUTMUX_CtInp3ToCTIMER2CAP = 4U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp3 input is selected */
    kINPUTMUX_CtInp4ToCTIMER2CAP = 5U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp4 input is selected */
    kINPUTMUX_CtInp5ToCTIMER2CAP = 6U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp5 input is selected */
    kINPUTMUX_CtInp6ToCTIMER2CAP = 7U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp6 input is selected */
    kINPUTMUX_CtInp7ToCTIMER2CAP = 8U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp7 input is selected */
    kINPUTMUX_CtInp8ToCTIMER2CAP = 9U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp8 input is selected */
    kINPUTMUX_CtInp9ToCTIMER2CAP = 10U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp9 input is selected */
    kINPUTMUX_CtInp10ToCTIMER2CAP = 11U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp10 input is selected */
    kINPUTMUX_CtInp11ToCTIMER2CAP = 12U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp11 input is selected */
    kINPUTMUX_CtInp12ToCTIMER2CAP = 13U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp12 input is selected */
    kINPUTMUX_CtInp13ToCTIMER2CAP = 14U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp13 input is selected */
    kINPUTMUX_CtInp14ToCTIMER2CAP = 15U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp14 input is selected */
    kINPUTMUX_CtInp15ToCTIMER2CAP = 16U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp15 input is selected */
    kINPUTMUX_CtInp16ToCTIMER2CAP = 17U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp16 input is selected */
    kINPUTMUX_CtInp17ToCTIMER2CAP = 18U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp17 input is selected */
    kINPUTMUX_CtInp18ToCTIMER2CAP = 19U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp18 input is selected */
    kINPUTMUX_CtInp19ToCTIMER2CAP = 20U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp19 input is selected */
    kINPUTMUX_Aoi0Out0ToCTIMER2CAP = 22U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToCTIMER2CAP = 23U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToCTIMER2CAP = 24U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToCTIMER2CAP = 25U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Adc0Tcomp0ToCTIMER2CAP = 26U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[0] input is selected */
    kINPUTMUX_Adc0Tcomp1ToCTIMER2CAP = 27U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[1] input is selected */
    kINPUTMUX_Adc0Tcomp2ToCTIMER2CAP = 28U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[2] input is selected */
    kINPUTMUX_Adc0Tcomp3ToCTIMER2CAP = 29U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[3] input is selected */
    kINPUTMUX_Cmp0OutToCTIMER2CAP = 30U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Lpi2c2MeopToCTIMER2CAP = 31U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpi2c2 master end of packet input is selected */
    kINPUTMUX_Lpi2c2SeopToCTIMER2CAP = 32U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpi2c2 slave end of packet input is selected */
    kINPUTMUX_Ctimer0Mat1ToCTIMER2CAP = 33U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer0Mat2ToCTIMER2CAP = 34U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToCTIMER2CAP = 35U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat1ToCTIMER2CAP = 36U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat2ToCTIMER2CAP = 37U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToCTIMER2CAP = 38U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig0ToCTIMER2CAP = 44U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig0ToCTIMER2CAP = 45U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig0ToCTIMER2CAP = 46U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig0ToCTIMER2CAP = 47U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig0 input is selected */
    kINPUTMUX_Lpi2c0MeopToCTIMER2CAP = 48U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpi2c0 master end of packet input is selected */
    kINPUTMUX_Lpi2c0SeopToCTIMER2CAP = 49U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpi2c0 slave end of packet input is selected */
    kINPUTMUX_Lpi2c1MeopToCTIMER2CAP = 50U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpi2c1 master end of packet input is selected */
    kINPUTMUX_Lpi2c1SeopToCTIMER2CAP = 51U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpi2c1 slave end of packet input is selected */
    kINPUTMUX_Lpspi0EofToCTIMER2CAP = 52U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpspi0 end of frame input is selected */
    kINPUTMUX_Lpspi0RdwToCTIMER2CAP = 53U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpspi0 received data word input is selected */
    kINPUTMUX_Lpspi1EofToCTIMER2CAP = 54U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpspi1 end of frame input is selected */
    kINPUTMUX_Lpspi1RdwToCTIMER2CAP = 55U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpspi1 received data word input is selected */
    kINPUTMUX_Lpuart0RdwToCTIMER2CAP = 56U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 received data word input is selected */
    kINPUTMUX_Lpuart0TdwToCTIMER2CAP = 57U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word input is selected */
    kINPUTMUX_Lpuart0RliToCTIMER2CAP = 58U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle input is selected */
    kINPUTMUX_Lpuart1RdwToCTIMER2CAP = 59U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 received data word input is selected */
    kINPUTMUX_Lpuart1TdwToCTIMER2CAP = 60U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 transmitted data word input is selected */
    kINPUTMUX_Lpuart1RliToCTIMER2CAP = 61U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 receive line idle input is selected */
    kINPUTMUX_Lpuart2RdwToCTIMER2CAP = 62U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart2 received data word input is selected */
    kINPUTMUX_Lpuart2TdwToCTIMER2CAP = 63U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart2 transmitted data word input is selected */
    kINPUTMUX_Lpuart2RliToCTIMER2CAP = 64U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart2 receive line idle input is selected */
    kINPUTMUX_TrigIn0ToCTIMER2CAP = 65U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToCTIMER2CAP = 66U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToCTIMER2CAP = 67U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToCTIMER2CAP = 68U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToCTIMER2CAP = 69U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToCTIMER2CAP = 70U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToCTIMER2CAP = 71U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToCTIMER2CAP = 72U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToCTIMER2CAP = 73U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToCTIMER2CAP = 74U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToCTIMER2CAP = 75U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToCTIMER2CAP = 76U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Lpuart3RdwToCTIMER2CAP = 77U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart3 received data word input is selected */
    kINPUTMUX_Lpuart3TdwToCTIMER2CAP = 78U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart3 transmitted data word input is selected */
    kINPUTMUX_Lpuart3RliToCTIMER2CAP = 79U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart3 receive line idle input is selected */
    kINPUTMUX_Lpuart4RdwToCTIMER2CAP = 80U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart4 received data word input is selected */
    kINPUTMUX_Lpuart4TdwToCTIMER2CAP = 81U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart4 transmitted data word input is selected */
    kINPUTMUX_Lpuart4RliToCTIMER2CAP = 82U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart4 receive line idle input is selected */

    /*!< ADC0_TRIGn: ADC trigger input connections */
    kINPUTMUX_ArmTxevToAdc0Trig = 1U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToAdc0Trig = 2U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToAdc0Trig = 3U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToAdc0Trig = 4U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToAdc0Trig = 5U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToAdc0Trig = 6U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat0ToAdc0Trig = 9U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< ctimer0_mat0 input is selected */
    kINPUTMUX_Ctimer0Mat1ToAdc0Trig = 10U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat0ToAdc0Trig = 11U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< ctimer1_mat0 input is selected */
    kINPUTMUX_Ctimer1Mat1ToAdc0Trig = 12U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat0ToAdc0Trig = 13U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< ctimer2_mat0 input is selected */
    kINPUTMUX_Ctimer2Mat1ToAdc0Trig = 14U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Lptmr0ToAdc0Trig = 15U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< lptmr0 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig0ToAdc0Trig = 18U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig1ToAdc0Trig = 19U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig1 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig0ToAdc0Trig = 20U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig1ToAdc0Trig = 21U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig1 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig0ToAdc0Trig = 22U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig1ToAdc0Trig = 23U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig1 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig0ToAdc0Trig = 24U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig1ToAdc0Trig = 25U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig1 input is selected */
    kINPUTMUX_Gpio0Pet0ToAdc0Trig = 26U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToAdc0Trig = 27U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToAdc0Trig = 28U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToAdc0Trig = 29U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToAdc0Trig = 31U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< EXT_TRIGn: EXT trigger connections 0-7 */
    kINPUTMUX_Aoi0Out0ToExtTrig = 2U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToExtTrig = 3U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToExtTrig = 4U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToExtTrig = 5U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToExtTrig = 6U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Lpuart0IToExtTrig = 9U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< lpuart0 ipp_do_lpuart_txd input is selected */
    kINPUTMUX_Lpuart1IToExtTrig = 10U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< lpuart1 ipp_do_lpuart_txd input is selected */
    kINPUTMUX_Lpuart2IToExtTrig = 11U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< lpuart2 ipp_do_lpuart_txd input is selected */
    kINPUTMUX_Lpuart3IToExtTrig = 12U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< lpuart3 ipp_do_lpuart_txd input is selected */
    kINPUTMUX_Lpuart4IToExtTrig = 13U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< lpuart4 ipp_do_lpuart_txd input is selected */
    kINPUTMUX_Rtc1hzClkToExtTrig = 19U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< rtc_1hz_clk input is selected */

    /*!< AOI0INPUTn: AOI0 trigger input connections */
    kINPUTMUX_Adc0Tcomp0ToAOI0INPUT = 1U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[0] input is selected */
    kINPUTMUX_Adc0Tcomp1ToAOI0INPUT = 2U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[1] input is selected */
    kINPUTMUX_Adc0Tcomp2ToAOI0INPUT = 3U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[2] input is selected */
    kINPUTMUX_Adc0Tcomp3ToAOI0INPUT = 4U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[3] input is selected */
    kINPUTMUX_Cmp0OutToAOI0INPUT = 5U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat0ToAOI0INPUT = 8U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< ctimer0_mat0 input is selected */
    kINPUTMUX_Ctimer0Mat1ToAOI0INPUT = 9U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer0Mat2ToAOI0INPUT = 10U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToAOI0INPUT = 11U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat0ToAOI0INPUT = 12U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< ctimer1_mat0 input is selected */
    kINPUTMUX_Ctimer1Mat1ToAOI0INPUT = 13U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat2ToAOI0INPUT = 14U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToAOI0INPUT = 15U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat0ToAOI0INPUT = 16U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< ctimer2_mat0 input is selected */
    kINPUTMUX_Ctimer2Mat1ToAOI0INPUT = 17U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat2ToAOI0INPUT = 18U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToAOI0INPUT = 19U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_Lptmr0ToAOI0INPUT = 20U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< lptmr0 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig0ToAOI0INPUT = 27U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig1ToAOI0INPUT = 28U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig1 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig0ToAOI0INPUT = 29U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig1ToAOI0INPUT = 30U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig1 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig0ToAOI0INPUT = 31U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig1ToAOI0INPUT = 32U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig1 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig0ToAOI0INPUT = 33U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig1ToAOI0INPUT = 34U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig1 input is selected */
    kINPUTMUX_TrigIn0ToAOI0INPUT = 35U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToAOI0INPUT = 36U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToAOI0INPUT = 37U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToAOI0INPUT = 38U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToAOI0INPUT = 39U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToAOI0INPUT = 40U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToAOI0INPUT = 41U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToAOI0INPUT = 42U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToAOI0INPUT = 43U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToAOI0INPUT = 44U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToAOI0INPUT = 45U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToAOI0INPUT = 46U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToAOI0INPUT = 47U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToAOI0INPUT = 48U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToAOI0INPUT = 49U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToAOI0INPUT = 50U + (AOI0INPUTn_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */

    /*!< CTIMER0TRIG: Trigger register for CTIMER0 */
    kINPUTMUX_CtInp0ToCTIMER0TRIG                  = 1U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp0 input is selected */
    kINPUTMUX_CtInp1ToCTIMER0TRIG                  = 2U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp1 input is selected */
    kINPUTMUX_CtInp2ToCTIMER0TRIG                  = 3U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp2 input is selected */
    kINPUTMUX_CtInp3ToCTIMER0TRIG                  = 4U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp3 input is selected */
    kINPUTMUX_CtInp4ToCTIMER0TRIG                  = 5U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp4 input is selected */
    kINPUTMUX_CtInp5ToCTIMER0TRIG                  = 6U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp5 input is selected */
    kINPUTMUX_CtInp6ToCTIMER0TRIG                  = 7U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp6 input is selected */
    kINPUTMUX_CtInp7ToCTIMER0TRIG                  = 8U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp7 input is selected */
    kINPUTMUX_CtInp8ToCTIMER0TRIG                  = 9U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp8 input is selected */
    kINPUTMUX_CtInp9ToCTIMER0TRIG                  = 10U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp9 input is selected */
    kINPUTMUX_CtInp10ToCTIMER0TRIG                 = 11U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp10 input is selected */
    kINPUTMUX_CtInp11ToCTIMER0TRIG                 = 12U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp11 input is selected */
    kINPUTMUX_CtInp12ToCTIMER0TRIG                 = 13U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp12 input is selected */
    kINPUTMUX_CtInp13ToCTIMER0TRIG                 = 14U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp13 input is selected */
    kINPUTMUX_CtInp14ToCTIMER0TRIG                 = 15U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp14 input is selected */
    kINPUTMUX_CtInp15ToCTIMER0TRIG                 = 16U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp15 input is selected */
    kINPUTMUX_CtInp16ToCTIMER0TRIG                 = 17U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp16 input is selected */
    kINPUTMUX_CtInp17ToCTIMER0TRIG                 = 18U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp17 input is selected */
    kINPUTMUX_CtInp18ToCTIMER0TRIG                 = 19U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp18 input is selected */
    kINPUTMUX_CtInp19ToCTIMER0TRIG                 = 20U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp19 input is selected */
    kINPUTMUX_Aoi0Out0ToCTIMER0TRIG                = 22U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToCTIMER0TRIG                = 23U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToCTIMER0TRIG                = 24U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToCTIMER0TRIG                = 25U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Adc0Tcomp0ToCTIMER0TRIG              = 26U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[0] input is selected */
    kINPUTMUX_Adc0Tcomp1ToCTIMER0TRIG              = 27U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[1] input is selected */
    kINPUTMUX_Adc0Tcomp2ToCTIMER0TRIG              = 28U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[2] input is selected */
    kINPUTMUX_Adc0Tcomp3ToCTIMER0TRIG              = 29U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[3] input is selected */
    kINPUTMUX_Cmp0OutToCTIMER0TRIG                 = 30U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Lpi2c2MeopToCTIMER0TRIG              = 31U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpi2c2 master end of packet input is selected */
    kINPUTMUX_Lpi2c2SeopToCTIMER0TRIG              = 32U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpi2c2 slave end of packet input is selected */
    kINPUTMUX_Ctimer1Mat1ToCTIMER0TRIG             = 33U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat2ToCTIMER0TRIG             = 34U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToCTIMER0TRIG             = 35U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat1ToCTIMER0TRIG             = 36U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat2ToCTIMER0TRIG             = 37U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToCTIMER0TRIG             = 38U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig0ToCTIMER0TRIG         = 44U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig0ToCTIMER0TRIG         = 45U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig0ToCTIMER0TRIG         = 46U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig0ToCTIMER0TRIG         = 47U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig0 input is selected */
    kINPUTMUX_Lpi2c0MeopToCTIMER0TRIG              = 48U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpi2c0 master end of packet input is selected */
    kINPUTMUX_Lpi2c0SeopToCTIMER0TRIG              = 49U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpi2c0 slave end of packet input is selected */
    kINPUTMUX_Lpi2c1MeopToCTIMER0TRIG              = 50U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpi2c1 master end of packet input is selected */
    kINPUTMUX_Lpi2c1SeopToCTIMER0TRIG              = 51U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpi2c1 slave end of packet input is selected */
    kINPUTMUX_Lpspi0EofToCTIMER0TRIG               = 52U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpspi0 end of frame input is selected */
    kINPUTMUX_Lpspi0RdwToCTIMER0TRIG               = 53U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpspi0 received data word input is selected */
    kINPUTMUX_Lpspi1EofToCTIMER0TRIG               = 54U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpspi1 end of frame input is selected */
    kINPUTMUX_Lpspi1RdwToCTIMER0TRIG               = 55U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpspi1 received data word input is selected */
    kINPUTMUX_Lpuart0RdwToCTIMER0TRIG              = 56U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 received data word input is selected */
    kINPUTMUX_Lpuart0TdwToCTIMER0TRIG              = 57U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word input is selected */
    kINPUTMUX_Lpuart0RliToCTIMER0TRIG              = 58U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle input is selected */
    kINPUTMUX_Lpuart1RdwToCTIMER0TRIG              = 59U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 received data word input is selected */
    kINPUTMUX_Lpuart1TdwToCTIMER0TRIG              = 60U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 transmitted data word input is selected */
    kINPUTMUX_Lpuart1RliToCTIMER0TRIG              = 61U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 receive line idle input is selected */
    kINPUTMUX_Lpuart2RdwToCTIMER0TRIG              = 62U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart2 received data word input is selected */
    kINPUTMUX_Lpuart2TdwToCTIMER0TRIG              = 63U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart2 transmitted data word input is selected */
    kINPUTMUX_Lpuart2RliToCTIMER0TRIG              = 64U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart2 receive line idle input is selected */
    kINPUTMUX_TrigIn0ToCTIMER0TRIG                 = 65U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToCTIMER0TRIG                 = 66U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToCTIMER0TRIG                 = 67U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToCTIMER0TRIG                 = 68U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToCTIMER0TRIG                 = 69U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToCTIMER0TRIG                 = 70U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToCTIMER0TRIG                 = 71U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToCTIMER0TRIG                 = 72U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToCTIMER0TRIG                 = 73U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToCTIMER0TRIG                 = 74U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToCTIMER0TRIG                = 75U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToCTIMER0TRIG                = 76U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Lpuart3RdwToCTIMER0TRIG              = 77U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart3 received data word input is selected */
    kINPUTMUX_Lpuart3TdwToCTIMER0TRIG              = 78U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart3 transmitted data word input is selected */
    kINPUTMUX_Lpuart3RliToCTIMER0TRIG              = 79U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart3 receive line idle input is selected */
    kINPUTMUX_Lpuart4RdwToCTIMER0TRIG              = 80U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart4 received data word input is selected */
    kINPUTMUX_Lpuart4TdwToCTIMER0TRIG              = 81U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart4 transmitted data word input is selected */
    kINPUTMUX_Lpuart4RliToCTIMER0TRIG              = 82U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart4 receive line idle input is selected */

    /*!< CTIMER1TRIG: Trigger register for CTIMER1 */
    kINPUTMUX_CtInp0ToCTIMER1TRIG                  = 1U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp0 input is selected */
    kINPUTMUX_CtInp1ToCTIMER1TRIG                  = 2U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp1 input is selected */
    kINPUTMUX_CtInp2ToCTIMER1TRIG                  = 3U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp2 input is selected */
    kINPUTMUX_CtInp3ToCTIMER1TRIG                  = 4U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp3 input is selected */
    kINPUTMUX_CtInp4ToCTIMER1TRIG                  = 5U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp4 input is selected */
    kINPUTMUX_CtInp5ToCTIMER1TRIG                  = 6U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp5 input is selected */
    kINPUTMUX_CtInp6ToCTIMER1TRIG                  = 7U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp6 input is selected */
    kINPUTMUX_CtInp7ToCTIMER1TRIG                  = 8U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp7 input is selected */
    kINPUTMUX_CtInp8ToCTIMER1TRIG                  = 9U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp8 input is selected */
    kINPUTMUX_CtInp9ToCTIMER1TRIG                  = 10U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp9 input is selected */
    kINPUTMUX_CtInp10ToCTIMER1TRIG                 = 11U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp10 input is selected */
    kINPUTMUX_CtInp11ToCTIMER1TRIG                 = 12U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp11 input is selected */
    kINPUTMUX_CtInp12ToCTIMER1TRIG                 = 13U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp12 input is selected */
    kINPUTMUX_CtInp13ToCTIMER1TRIG                 = 14U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp13 input is selected */
    kINPUTMUX_CtInp14ToCTIMER1TRIG                 = 15U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp14 input is selected */
    kINPUTMUX_CtInp15ToCTIMER1TRIG                 = 16U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp15 input is selected */
    kINPUTMUX_CtInp16ToCTIMER1TRIG                 = 17U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp16 input is selected */
    kINPUTMUX_CtInp17ToCTIMER1TRIG                 = 18U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp17 input is selected */
    kINPUTMUX_CtInp18ToCTIMER1TRIG                 = 19U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp18 input is selected */
    kINPUTMUX_CtInp19ToCTIMER1TRIG                 = 20U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp19 input is selected */
    kINPUTMUX_Aoi0Out0ToCTIMER1TRIG                = 22U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToCTIMER1TRIG                = 23U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToCTIMER1TRIG                = 24U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToCTIMER1TRIG                = 25U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Adc0Tcomp0ToCTIMER1TRIG              = 26U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[0] input is selected */
    kINPUTMUX_Adc0Tcomp1ToCTIMER1TRIG              = 27U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[1] input is selected */
    kINPUTMUX_Adc0Tcomp2ToCTIMER1TRIG              = 28U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[2] input is selected */
    kINPUTMUX_Adc0Tcomp3ToCTIMER1TRIG              = 29U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[3] input is selected */
    kINPUTMUX_Cmp0OutToCTIMER1TRIG                 = 30U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Lpi2c2MeopToCTIMER1TRIG              = 31U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpi2c2 master end of packet input is selected */
    kINPUTMUX_Lpi2c2SeopToCTIMER1TRIG              = 32U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpi2c2 slave end of packet input is selected */
    kINPUTMUX_Ctimer0Mat1ToCTIMER1TRIG             = 33U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer0Mat2ToCTIMER1TRIG             = 34U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToCTIMER1TRIG             = 35U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat1ToCTIMER1TRIG             = 36U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat2ToCTIMER1TRIG             = 37U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToCTIMER1TRIG             = 38U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig0ToCTIMER1TRIG         = 44U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig0ToCTIMER1TRIG         = 45U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig0ToCTIMER1TRIG         = 46U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig0ToCTIMER1TRIG         = 47U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig0 input is selected */
    kINPUTMUX_Lpi2c0MeopToCTIMER1TRIG              = 48U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpi2c0 master end of packet input is selected */
    kINPUTMUX_Lpi2c0SeopToCTIMER1TRIG              = 49U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpi2c0 slave end of packet input is selected */
    kINPUTMUX_Lpi2c1MeopToCTIMER1TRIG              = 50U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpi2c1 master end of packet input is selected */
    kINPUTMUX_Lpi2c1SeopToCTIMER1TRIG              = 51U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpi2c1 slave end of packet input is selected */
    kINPUTMUX_Lpspi0EofToCTIMER1TRIG               = 52U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpspi0 end of frame input is selected */
    kINPUTMUX_Lpspi0RdwToCTIMER1TRIG               = 53U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpspi0 received data word input is selected */
    kINPUTMUX_Lpspi1EofToCTIMER1TRIG               = 54U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpspi1 end of frame input is selected */
    kINPUTMUX_Lpspi1RdwToCTIMER1TRIG               = 55U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpspi1 received data word input is selected */
    kINPUTMUX_Lpuart0RdwToCTIMER1TRIG              = 56U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 received data word input is selected */
    kINPUTMUX_Lpuart0TdwToCTIMER1TRIG              = 57U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word input is selected */
    kINPUTMUX_Lpuart0RliToCTIMER1TRIG              = 58U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle input is selected */
    kINPUTMUX_Lpuart1RdwToCTIMER1TRIG              = 59U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 received data word input is selected */
    kINPUTMUX_Lpuart1TdwToCTIMER1TRIG              = 60U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 transmitted data word input is selected */
    kINPUTMUX_Lpuart1RliToCTIMER1TRIG              = 61U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 receive line idle input is selected */
    kINPUTMUX_Lpuart2RdwToCTIMER1TRIG              = 62U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart2 received data word input is selected */
    kINPUTMUX_Lpuart2TdwToCTIMER1TRIG              = 63U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart2 transmitted data word input is selected */
    kINPUTMUX_Lpuart2RliToCTIMER1TRIG              = 64U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart2 receive line idle input is selected */
    kINPUTMUX_TrigIn0ToCTIMER1TRIG                 = 65U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToCTIMER1TRIG                 = 66U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToCTIMER1TRIG                 = 67U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToCTIMER1TRIG                 = 68U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToCTIMER1TRIG                 = 69U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToCTIMER1TRIG                 = 70U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToCTIMER1TRIG                 = 71U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToCTIMER1TRIG                 = 72U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToCTIMER1TRIG                 = 73U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToCTIMER1TRIG                 = 74U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToCTIMER1TRIG                = 75U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToCTIMER1TRIG                = 76U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Lpuart3RdwToCTIMER1TRIG              = 77U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart3 received data word input is selected */
    kINPUTMUX_Lpuart3TdwToCTIMER1TRIG              = 78U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart3 transmitted data word input is selected */
    kINPUTMUX_Lpuart3RliToCTIMER1TRIG              = 79U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart3 receive line idle input is selected */
    kINPUTMUX_Lpuart4RdwToCTIMER1TRIG              = 80U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart4 received data word input is selected */
    kINPUTMUX_Lpuart4TdwToCTIMER1TRIG              = 81U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart4 transmitted data word input is selected */
    kINPUTMUX_Lpuart4RliToCTIMER1TRIG              = 82U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart4 receive line idle input is selected */

    /*!< CTIMER2TRIG: Trigger register for CTIMER2 */
    kINPUTMUX_CtInp0ToCTIMER2TRIG                  = 1U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp0 input is selected */
    kINPUTMUX_CtInp1ToCTIMER2TRIG                  = 2U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp1 input is selected */
    kINPUTMUX_CtInp2ToCTIMER2TRIG                  = 3U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp2 input is selected */
    kINPUTMUX_CtInp3ToCTIMER2TRIG                  = 4U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp3 input is selected */
    kINPUTMUX_CtInp4ToCTIMER2TRIG                  = 5U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp4 input is selected */
    kINPUTMUX_CtInp5ToCTIMER2TRIG                  = 6U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp5 input is selected */
    kINPUTMUX_CtInp6ToCTIMER2TRIG                  = 7U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp6 input is selected */
    kINPUTMUX_CtInp7ToCTIMER2TRIG                  = 8U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp7 input is selected */
    kINPUTMUX_CtInp8ToCTIMER2TRIG                  = 9U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp8 input is selected */
    kINPUTMUX_CtInp9ToCTIMER2TRIG                  = 10U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp9 input is selected */
    kINPUTMUX_CtInp10ToCTIMER2TRIG                 = 11U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp10 input is selected */
    kINPUTMUX_CtInp11ToCTIMER2TRIG                 = 12U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp11 input is selected */
    kINPUTMUX_CtInp12ToCTIMER2TRIG                 = 13U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp12 input is selected */
    kINPUTMUX_CtInp13ToCTIMER2TRIG                 = 14U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp13 input is selected */
    kINPUTMUX_CtInp14ToCTIMER2TRIG                 = 15U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp14 input is selected */
    kINPUTMUX_CtInp15ToCTIMER2TRIG                 = 16U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp15 input is selected */
    kINPUTMUX_CtInp16ToCTIMER2TRIG                 = 17U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp16 input is selected */
    kINPUTMUX_CtInp17ToCTIMER2TRIG                 = 18U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp17 input is selected */
    kINPUTMUX_CtInp18ToCTIMER2TRIG                 = 19U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp18 input is selected */
    kINPUTMUX_CtInp19ToCTIMER2TRIG                 = 20U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp19 input is selected */
    kINPUTMUX_Aoi0Out0ToCTIMER2TRIG                = 22U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToCTIMER2TRIG                = 23U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToCTIMER2TRIG                = 24U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToCTIMER2TRIG                = 25U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Adc0Tcomp0ToCTIMER2TRIG              = 26U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[0] input is selected */
    kINPUTMUX_Adc0Tcomp1ToCTIMER2TRIG              = 27U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[1] input is selected */
    kINPUTMUX_Adc0Tcomp2ToCTIMER2TRIG              = 28U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[2] input is selected */
    kINPUTMUX_Adc0Tcomp3ToCTIMER2TRIG              = 29U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[3] input is selected */
    kINPUTMUX_Cmp0OutToCTIMER2TRIG                 = 30U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Lpi2c2MeopToCTIMER2TRIG              = 31U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpi2c2 master end of packet input is selected */
    kINPUTMUX_Lpi2c2SeopToCTIMER2TRIG              = 32U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpi2c2 slave end of packet input is selected */
    kINPUTMUX_Ctimer0Mat1ToCTIMER2TRIG             = 33U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer0Mat2ToCTIMER2TRIG             = 34U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToCTIMER2TRIG             = 35U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat1ToCTIMER2TRIG             = 36U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat2ToCTIMER2TRIG             = 37U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToCTIMER2TRIG             = 38U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig0ToCTIMER2TRIG         = 44U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig0ToCTIMER2TRIG         = 45U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig0ToCTIMER2TRIG         = 46U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig0ToCTIMER2TRIG         = 47U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig0 input is selected */
    kINPUTMUX_Lpi2c0MeopToCTIMER2TRIG              = 48U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpi2c0 master end of packet input is selected */
    kINPUTMUX_Lpi2c0SeopToCTIMER2TRIG              = 49U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpi2c0 slave end of packet input is selected */
    kINPUTMUX_Lpi2c1MeopToCTIMER2TRIG              = 50U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpi2c1 master end of packet input is selected */
    kINPUTMUX_Lpi2c1SeopToCTIMER2TRIG              = 51U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpi2c1 slave end of packet input is selected */
    kINPUTMUX_Lpspi0EofToCTIMER2TRIG               = 52U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpspi0 end of frame input is selected */
    kINPUTMUX_Lpspi0RdwToCTIMER2TRIG               = 53U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpspi0 received data word input is selected */
    kINPUTMUX_Lpspi1EofToCTIMER2TRIG               = 54U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpspi1 end of frame input is selected */
    kINPUTMUX_Lpspi1RdwToCTIMER2TRIG               = 55U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpspi1 received data word input is selected */
    kINPUTMUX_Lpuart0RdwToCTIMER2TRIG              = 56U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 received data word input is selected */
    kINPUTMUX_Lpuart0TdwToCTIMER2TRIG              = 57U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word input is selected */
    kINPUTMUX_Lpuart0RliToCTIMER2TRIG              = 58U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle input is selected */
    kINPUTMUX_Lpuart1RdwToCTIMER2TRIG              = 59U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 received data word input is selected */
    kINPUTMUX_Lpuart1TdwToCTIMER2TRIG              = 60U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 transmitted data word input is selected */
    kINPUTMUX_Lpuart1RliToCTIMER2TRIG              = 61U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 receive line idle input is selected */
    kINPUTMUX_Lpuart2RdwToCTIMER2TRIG              = 62U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart2 received data word input is selected */
    kINPUTMUX_Lpuart2TdwToCTIMER2TRIG              = 63U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart2 transmitted data word input is selected */
    kINPUTMUX_Lpuart2RliToCTIMER2TRIG              = 64U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart2 receive line idle input is selected */
    kINPUTMUX_TrigIn0ToCTIMER2TRIG                 = 65U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToCTIMER2TRIG                 = 66U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToCTIMER2TRIG                 = 67U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToCTIMER2TRIG                 = 68U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToCTIMER2TRIG                 = 69U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToCTIMER2TRIG                 = 70U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToCTIMER2TRIG                 = 71U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToCTIMER2TRIG                 = 72U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToCTIMER2TRIG                 = 73U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToCTIMER2TRIG                 = 74U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToCTIMER2TRIG                = 75U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToCTIMER2TRIG                = 76U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Lpuart3RdwToCTIMER2TRIG              = 77U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart3 received data word input is selected */
    kINPUTMUX_Lpuart3TdwToCTIMER2TRIG              = 78U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart3 transmitted data word input is selected */
    kINPUTMUX_Lpuart3RliToCTIMER2TRIG              = 79U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart3 receive line idle input is selected */
    kINPUTMUX_Lpuart4RdwToCTIMER2TRIG              = 80U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart4 received data word input is selected */
    kINPUTMUX_Lpuart4TdwToCTIMER2TRIG              = 81U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart4 transmitted data word input is selected */
    kINPUTMUX_Lpuart4RliToCTIMER2TRIG              = 82U + (CTIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart4 receive line idle input is selected */

    /*!< FREQMEAS_REF: Selection for frequency measurement reference clock */
    kINPUTMUX_ClkInToFreqmeasRef                   = 1U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< clk_in input is selected */
    kINPUTMUX_FroOsc12mToFreqmeasRef               = 2U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< fro_osc_12m input is selected */
    kINPUTMUX_FroHfDivToFreqmeasRef                = 3U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< fro_hf_div input is selected */
    kINPUTMUX_Osc32k1ToFreqmeasRef                 = 4U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< osc32k[1] input is selected */
    kINPUTMUX_Clk16k1ToFreqmeasRef                 = 5U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< clk_16k[1] input is selected */
    kINPUTMUX_SlowClkToFreqmeasRef                 = 6U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< slow_clk input is selected */
    kINPUTMUX_FreqmeClkIn0ToFreqmeasRef            = 7U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< freqme_clk_in0 input is selected */
    kINPUTMUX_FreqmeClkIn1ToFreqmeasRef            = 8U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< freqme_clk_in1 input is selected */
    kINPUTMUX_Aoi0Out0ToFreqmeasRef                = 9U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFreqmeasRef                = 10U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig0ToFreqmeasRef         = 11U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig1ToFreqmeasRef         = 12U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig1 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig0ToFreqmeasRef         = 13U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig1ToFreqmeasRef         = 14U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig1 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig0ToFreqmeasRef         = 15U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig1ToFreqmeasRef         = 16U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig1 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig0ToFreqmeasRef         = 17U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig1ToFreqmeasRef         = 18U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig1 input is selected */
    kINPUTMUX_ClkIomuxIppScgIppDoScgClkoutToFreqmeasRef = 19U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< clk__iomux__ipp__scg__ipp_do_scg_clkout input is selected */
    kINPUTMUX_SpcPmcBgRefresh1p8vToFreqmeasRef     = 21U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< spc_pmc_bg_refresh_1p8v input is selected */
    kINPUTMUX_SpcPmcTimerClk1p8vToFreqmeasRef      = 23U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< spc_pmc_timer_clk_1p8v input is selected */
    kINPUTMUX_SpcPmcTstObsBitSfa1p8vToFreqmeasRef  = 24U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< spc_pmc_tst_obs_bit_sfa_1p8v input is selected */
    kINPUTMUX_SpcPmcTstObsBitSfa1p8v1ToFreqmeasRef = 25U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< spc_pmc_tst_obs_bit_sfa_1p8v[1] ^ spc_pmc_coreldo_tstctrl_testdelayin_sf input is selected */
    kINPUTMUX_VbatOttToFreqmeasRef                 = 28U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< vbat osc32k test trigger input is selected */
    kINPUTMUX_VbatOtcToFreqmeasRef                 = 29U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< vbat osc32k test clock input is selected */ 
    kINPUTMUX_TsiclkmainlvToFreqmeastar            = 46U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_TsiclkswlvToFreqmeastar              = 47U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_TsiintgdonelvToFreqmeastar           = 48U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_TsiintgresetlvToFreqmeastar          = 49U + (FREQMEAS_REF_REG << PMUX_SHIFT),

    /*!< FREQMEAS_TAR: Selection for frequency measurement target clock */
    kINPUTMUX_ClkInToFreqmeasTar                   = 1U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< clk_in input is selected */
    kINPUTMUX_FroOsc12mToFreqmeasTar               = 2U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< fro_osc_12m input is selected */
    kINPUTMUX_FroHfDivToFreqmeasTar                = 3U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< fro_hf_div input is selected */
    kINPUTMUX_Osc32k1ToFreqmeasTar                 = 4U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< osc32k[1] input is selected */
    kINPUTMUX_Clk16k1ToFreqmeasTar                 = 5U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< clk_16k[1] input is selected */
    kINPUTMUX_SlowClkToFreqmeasTar                 = 6U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< slow_clk input is selected */
    kINPUTMUX_FreqmeClkIn0ToFreqmeasTar            = 7U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< freqme_clk_in0 input is selected */
    kINPUTMUX_FreqmeClkIn1ToFreqmeasTar            = 8U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< freqme_clk_in1 input is selected */
    kINPUTMUX_Aoi0Out0ToFreqmeasTar                = 9U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFreqmeasTar                = 10U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig0ToFreqmeasTar         = 11U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig1ToFreqmeasTar         = 12U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig1 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig0ToFreqmeasTar         = 13U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig1ToFreqmeasTar         = 14U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig1 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig0ToFreqmeasTar         = 15U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig1ToFreqmeasTar         = 16U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig1 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig0ToFreqmeasTar         = 17U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig1ToFreqmeasTar         = 18U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig1 input is selected */
    kINPUTMUX_ClkIomuxIppScgIppDoScgClkoutToFreqmeasTar = 19U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< clk__iomux__ipp__scg__ipp_do_scg_clkout input is selected */
    kINPUTMUX_SpcPmcBgRefresh1p8vToFreqmeasTar     = 21U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< spc_pmc_bg_refresh_1p8v input is selected */
    kINPUTMUX_SpcPmcTimerClk1p8vToFreqmeasTar      = 23U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< spc_pmc_timer_clk_1p8v input is selected */
    kINPUTMUX_SpcPmcTstObsBitSfa1p8vToFreqmeasTar  = 24U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< spc_pmc_tst_obs_bit_sfa_1p8v input is selected */
    kINPUTMUX_SpcPmcTstObsBitSfa1p8v1ToFreqmeasTar = 25U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< spc_pmc_tst_obs_bit_sfa_1p8v[1] ^ spc_pmc_coreldo_tstctrl_testdelayin_sf input is selected */
    kINPUTMUX_VbatOttToFreqmeasTar                 = 28U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< vbat osc32k test trigger input is selected */
    kINPUTMUX_VbatOtcToFreqmeasTar                 = 29U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< vbat osc32k test clock input is selected */
    kINPUTMUX_TsiclkmainlvToFreqmeasref            = 46U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_TsiclkswlvToFreqmeasref              = 47U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_TsiintgdonelvToFreqmeasref           = 48U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_TsiintgresetlvToFreqmeasref          = 49U + (FREQMEAS_REF_REG << PMUX_SHIFT),

    /*!< LPCMP0_TRIG: LPCMP0 trigger input connections */
    kINPUTMUX_Aoi0Out0ToLpcmp0Trig                 = 2U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLpcmp0Trig                 = 3U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLpcmp0Trig                 = 4U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLpcmp0Trig                 = 5U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Ctimer0Mat0ToLpcmp0Trig              = 8U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat0 input is selected */
    kINPUTMUX_Ctimer0Mat2ToLpcmp0Trig              = 9U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat0ToLpcmp0Trig              = 10U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat0 input is selected */
    kINPUTMUX_Ctimer1Mat2ToLpcmp0Trig              = 11U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat0ToLpcmp0Trig              = 12U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat0 input is selected */
    kINPUTMUX_Ctimer2Mat2ToLpcmp0Trig              = 13U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Lptmr0ToLpcmp0Trig                   = 14U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< lptmr0 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig0ToLpcmp0Trig          = 17U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm0MuxTrig1ToLpcmp0Trig          = 18U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm0_mux_trig1 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig0ToLpcmp0Trig          = 19U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm1MuxTrig1ToLpcmp0Trig          = 20U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm1_mux_trig1 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig0ToLpcmp0Trig          = 21U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm2MuxTrig1ToLpcmp0Trig          = 22U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm2_mux_trig1 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig0ToLpcmp0Trig          = 23U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig0 input is selected */
    kINPUTMUX_Pwm0Sm3MuxTrig1ToLpcmp0Trig          = 24U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< pwm0_sm3_mux_trig1 input is selected */
    kINPUTMUX_Gpio0Pet0ToLpcmp0Trig                = 25U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToLpcmp0Trig                = 26U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLpcmp0Trig                = 27U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLpcmp0Trig                = 28U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToLpcmp0Trig                      = 30U + (LPCMP0_TRIG_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< FlexPWM0_SM0_EXTA0: FlexPWM0_SM0_EXTA0 trigger input connections */
    kINPUTMUX_ArmTxevToFlexpwm0Sm0Exta0            = 1U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToFlexpwm0Sm0Exta0           = 2U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFlexpwm0Sm0Exta0           = 3U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToFlexpwm0Sm0Exta0           = 4U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToFlexpwm0Sm0Exta0           = 5U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToFlexpwm0Sm0Exta0            = 6U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToFlexpwm0Sm0Exta0        = 9U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToFlexpwm0Sm0Exta0        = 10U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToFlexpwm0Sm0Exta0        = 11U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToFlexpwm0Sm0Exta0        = 12U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToFlexpwm0Sm0Exta0        = 13U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToFlexpwm0Sm0Exta0        = 14U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToFlexpwm0Sm0Exta0            = 20U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToFlexpwm0Sm0Exta0            = 21U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToFlexpwm0Sm0Exta0            = 22U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToFlexpwm0Sm0Exta0            = 23U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToFlexpwm0Sm0Exta0            = 24U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToFlexpwm0Sm0Exta0            = 25U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToFlexpwm0Sm0Exta0            = 26U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToFlexpwm0Sm0Exta0            = 27U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToFlexpwm0Sm0Exta0            = 28U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToFlexpwm0Sm0Exta0            = 29U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToFlexpwm0Sm0Exta0           = 30U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToFlexpwm0Sm0Exta0           = 31U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToFlexpwm0Sm0Exta0          = 32U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToFlexpwm0Sm0Exta0          = 33U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToFlexpwm0Sm0Exta0          = 34U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToFlexpwm0Sm0Exta0          = 35U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_EccEiToFlexpwm0Sm0Exta0              = 37U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< ecc error interrupt input is selected */
    kINPUTMUX_WwdtToFlexpwm0Sm0Exta0               = 38U + (FlexPWM0_SM0_EXTA0_REG << PMUX_SHIFT),  /*!< wwdt0/1 interrupt input is selected */

    /*!< FlexPWM0_SM0_EXTSYNC: FlexPWM0_SM0_EXTSYNC trigger input connections */
    kINPUTMUX_ArmTxevToFlexpwm0Sm0Extsync          = 1U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToFlexpwm0Sm0Extsync         = 2U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFlexpwm0Sm0Extsync         = 3U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToFlexpwm0Sm0Extsync         = 4U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToFlexpwm0Sm0Extsync         = 5U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToFlexpwm0Sm0Extsync          = 6U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToFlexpwm0Sm0Extsync      = 9U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToFlexpwm0Sm0Extsync      = 10U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToFlexpwm0Sm0Extsync      = 11U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToFlexpwm0Sm0Extsync      = 12U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToFlexpwm0Sm0Extsync      = 13U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToFlexpwm0Sm0Extsync      = 14U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToFlexpwm0Sm0Extsync          = 20U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToFlexpwm0Sm0Extsync          = 21U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToFlexpwm0Sm0Extsync          = 22U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToFlexpwm0Sm0Extsync          = 23U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToFlexpwm0Sm0Extsync          = 24U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToFlexpwm0Sm0Extsync          = 25U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToFlexpwm0Sm0Extsync          = 26U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToFlexpwm0Sm0Extsync          = 27U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToFlexpwm0Sm0Extsync          = 28U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToFlexpwm0Sm0Extsync          = 29U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToFlexpwm0Sm0Extsync         = 30U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToFlexpwm0Sm0Extsync         = 31U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToFlexpwm0Sm0Extsync        = 32U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToFlexpwm0Sm0Extsync        = 33U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToFlexpwm0Sm0Extsync        = 34U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToFlexpwm0Sm0Extsync        = 35U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_EccEiToFlexpwm0Sm0Extsync            = 37U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< ecc error interrupt input is selected */
    kINPUTMUX_WwdtToFlexpwm0Sm0Extsync             = 38U + (FlexPWM0_SM0_EXTSYNC_REG << PMUX_SHIFT),  /*!< wwdt0/1 interrupt input is selected */

    /*!< FlexPWM0_SM1_EXTA: FlexPWM0_SM1_EXTA trigger input connections */
    kINPUTMUX_ArmTxevToFlexpwm0Sm1Exta             = 1U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToFlexpwm0Sm1Exta            = 2U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFlexpwm0Sm1Exta            = 3U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToFlexpwm0Sm1Exta            = 4U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToFlexpwm0Sm1Exta            = 5U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToFlexpwm0Sm1Exta             = 6U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToFlexpwm0Sm1Exta         = 9U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToFlexpwm0Sm1Exta         = 10U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToFlexpwm0Sm1Exta         = 11U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToFlexpwm0Sm1Exta         = 12U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToFlexpwm0Sm1Exta         = 13U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToFlexpwm0Sm1Exta         = 14U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToFlexpwm0Sm1Exta             = 20U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToFlexpwm0Sm1Exta             = 21U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToFlexpwm0Sm1Exta             = 22U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToFlexpwm0Sm1Exta             = 23U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToFlexpwm0Sm1Exta             = 24U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToFlexpwm0Sm1Exta             = 25U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToFlexpwm0Sm1Exta             = 26U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToFlexpwm0Sm1Exta             = 27U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToFlexpwm0Sm1Exta             = 28U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToFlexpwm0Sm1Exta             = 29U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToFlexpwm0Sm1Exta            = 30U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToFlexpwm0Sm1Exta            = 31U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToFlexpwm0Sm1Exta           = 32U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToFlexpwm0Sm1Exta           = 33U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToFlexpwm0Sm1Exta           = 34U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToFlexpwm0Sm1Exta           = 35U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_EccEiToFlexpwm0Sm1Exta               = 37U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< ecc error interrupt input is selected */
    kINPUTMUX_WwdtToFlexpwm0Sm1Exta                = 38U + (FlexPWM0_SM1_EXTA_REG << PMUX_SHIFT),  /*!< wwdt0/1 interrupt input is selected */

    /*!< FlexPWM0_SM1_EXTSYNC: FlexPWM0_SM1_EXTSYNC trigger input connections */
    kINPUTMUX_ArmTxevToFlexpwm0Sm1Extsync          = 1U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToFlexpwm0Sm1Extsync         = 2U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFlexpwm0Sm1Extsync         = 3U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToFlexpwm0Sm1Extsync         = 4U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToFlexpwm0Sm1Extsync         = 5U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToFlexpwm0Sm1Extsync          = 6U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToFlexpwm0Sm1Extsync      = 9U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToFlexpwm0Sm1Extsync      = 10U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToFlexpwm0Sm1Extsync      = 11U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToFlexpwm0Sm1Extsync      = 12U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToFlexpwm0Sm1Extsync      = 13U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToFlexpwm0Sm1Extsync      = 14U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToFlexpwm0Sm1Extsync          = 20U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToFlexpwm0Sm1Extsync          = 21U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToFlexpwm0Sm1Extsync          = 22U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToFlexpwm0Sm1Extsync          = 23U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToFlexpwm0Sm1Extsync          = 24U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToFlexpwm0Sm1Extsync          = 25U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToFlexpwm0Sm1Extsync          = 26U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToFlexpwm0Sm1Extsync          = 27U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToFlexpwm0Sm1Extsync          = 28U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToFlexpwm0Sm1Extsync          = 29U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToFlexpwm0Sm1Extsync         = 30U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToFlexpwm0Sm1Extsync         = 31U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToFlexpwm0Sm1Extsync        = 32U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToFlexpwm0Sm1Extsync        = 33U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToFlexpwm0Sm1Extsync        = 34U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToFlexpwm0Sm1Extsync        = 35U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_EccEiToFlexpwm0Sm1Extsync            = 37U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< ecc error interrupt input is selected */
    kINPUTMUX_WwdtToFlexpwm0Sm1Extsync             = 38U + (FlexPWM0_SM1_EXTSYNC_REG << PMUX_SHIFT),  /*!< wwdt0/1 interrupt input is selected */

    /*!< FlexPWM0_SM2_EXTA: FlexPWM0_SM2_EXTA trigger input connections */
    kINPUTMUX_ArmTxevToFlexpwm0Sm2Exta             = 1U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToFlexpwm0Sm2Exta            = 2U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFlexpwm0Sm2Exta            = 3U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToFlexpwm0Sm2Exta            = 4U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToFlexpwm0Sm2Exta            = 5U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToFlexpwm0Sm2Exta             = 6U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToFlexpwm0Sm2Exta         = 9U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToFlexpwm0Sm2Exta         = 10U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToFlexpwm0Sm2Exta         = 11U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToFlexpwm0Sm2Exta         = 12U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToFlexpwm0Sm2Exta         = 13U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToFlexpwm0Sm2Exta         = 14U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToFlexpwm0Sm2Exta             = 20U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToFlexpwm0Sm2Exta             = 21U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToFlexpwm0Sm2Exta             = 22U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToFlexpwm0Sm2Exta             = 23U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToFlexpwm0Sm2Exta             = 24U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToFlexpwm0Sm2Exta             = 25U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToFlexpwm0Sm2Exta             = 26U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToFlexpwm0Sm2Exta             = 27U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToFlexpwm0Sm2Exta             = 28U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToFlexpwm0Sm2Exta             = 29U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToFlexpwm0Sm2Exta            = 30U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToFlexpwm0Sm2Exta            = 31U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToFlexpwm0Sm2Exta           = 32U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToFlexpwm0Sm2Exta           = 33U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToFlexpwm0Sm2Exta           = 34U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToFlexpwm0Sm2Exta           = 35U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_EccEiToFlexpwm0Sm2Exta               = 37U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< ecc error interrupt input is selected */
    kINPUTMUX_WwdtToFlexpwm0Sm2Exta                = 38U + (FlexPWM0_SM2_EXTA_REG << PMUX_SHIFT),  /*!< wwdt0/1 interrupt input is selected */

    /*!< FlexPWM0_SM2_EXTSYNC: FlexPWM0_SM2_EXTSYNC trigger input connections */
    kINPUTMUX_ArmTxevToFlexpwm0Sm2Extsync          = 1U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToFlexpwm0Sm2Extsync         = 2U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFlexpwm0Sm2Extsync         = 3U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToFlexpwm0Sm2Extsync         = 4U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToFlexpwm0Sm2Extsync         = 5U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToFlexpwm0Sm2Extsync          = 6U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToFlexpwm0Sm2Extsync      = 9U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToFlexpwm0Sm2Extsync      = 10U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToFlexpwm0Sm2Extsync      = 11U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToFlexpwm0Sm2Extsync      = 12U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToFlexpwm0Sm2Extsync      = 13U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToFlexpwm0Sm2Extsync      = 14U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToFlexpwm0Sm2Extsync          = 20U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToFlexpwm0Sm2Extsync          = 21U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToFlexpwm0Sm2Extsync          = 22U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToFlexpwm0Sm2Extsync          = 23U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToFlexpwm0Sm2Extsync          = 24U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToFlexpwm0Sm2Extsync          = 25U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToFlexpwm0Sm2Extsync          = 26U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToFlexpwm0Sm2Extsync          = 27U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToFlexpwm0Sm2Extsync          = 28U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToFlexpwm0Sm2Extsync          = 29U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToFlexpwm0Sm2Extsync         = 30U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToFlexpwm0Sm2Extsync         = 31U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToFlexpwm0Sm2Extsync        = 32U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToFlexpwm0Sm2Extsync        = 33U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToFlexpwm0Sm2Extsync        = 34U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToFlexpwm0Sm2Extsync        = 35U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_EccEiToFlexpwm0Sm2Extsync            = 37U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< ecc error interrupt input is selected */
    kINPUTMUX_WwdtToFlexpwm0Sm2Extsync             = 38U + (FlexPWM0_SM2_EXTSYNC_REG << PMUX_SHIFT),  /*!< wwdt0/1 interrupt input is selected */

    /*!< FlexPWM0_SM3_EXTA: FlexPWM0_SM3_EXTA trigger input connections */
    kINPUTMUX_ArmTxevToFlexpwm0Sm3Exta             = 1U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToFlexpwm0Sm3Exta            = 2U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFlexpwm0Sm3Exta            = 3U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToFlexpwm0Sm3Exta            = 4U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToFlexpwm0Sm3Exta            = 5U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToFlexpwm0Sm3Exta             = 6U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToFlexpwm0Sm3Exta         = 9U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToFlexpwm0Sm3Exta         = 10U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToFlexpwm0Sm3Exta         = 11U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToFlexpwm0Sm3Exta         = 12U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToFlexpwm0Sm3Exta         = 13U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToFlexpwm0Sm3Exta         = 14U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToFlexpwm0Sm3Exta             = 20U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToFlexpwm0Sm3Exta             = 21U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToFlexpwm0Sm3Exta             = 22U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToFlexpwm0Sm3Exta             = 23U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToFlexpwm0Sm3Exta             = 24U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToFlexpwm0Sm3Exta             = 25U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToFlexpwm0Sm3Exta             = 26U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToFlexpwm0Sm3Exta             = 27U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToFlexpwm0Sm3Exta             = 28U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToFlexpwm0Sm3Exta             = 29U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToFlexpwm0Sm3Exta            = 30U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToFlexpwm0Sm3Exta            = 31U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToFlexpwm0Sm3Exta           = 32U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToFlexpwm0Sm3Exta           = 33U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToFlexpwm0Sm3Exta           = 34U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToFlexpwm0Sm3Exta           = 35U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_EccEiToFlexpwm0Sm3Exta               = 37U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< ecc error interrupt input is selected */
    kINPUTMUX_WwdtToFlexpwm0Sm3Exta                = 38U + (FlexPWM0_SM3_EXTA_REG << PMUX_SHIFT),  /*!< wwdt0/1 interrupt input is selected */

    /*!< FlexPWM0_SM3_EXTSYNC: FlexPWM0_SM3_EXTSYNC trigger input connections */
    kINPUTMUX_ArmTxevToFlexpwm0Sm3Extsync          = 1U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToFlexpwm0Sm3Extsync         = 2U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFlexpwm0Sm3Extsync         = 3U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToFlexpwm0Sm3Extsync         = 4U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToFlexpwm0Sm3Extsync         = 5U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToFlexpwm0Sm3Extsync          = 6U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToFlexpwm0Sm3Extsync      = 9U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToFlexpwm0Sm3Extsync      = 10U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToFlexpwm0Sm3Extsync      = 11U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToFlexpwm0Sm3Extsync      = 12U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToFlexpwm0Sm3Extsync      = 13U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToFlexpwm0Sm3Extsync      = 14U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToFlexpwm0Sm3Extsync          = 20U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToFlexpwm0Sm3Extsync          = 21U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToFlexpwm0Sm3Extsync          = 22U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToFlexpwm0Sm3Extsync          = 23U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToFlexpwm0Sm3Extsync          = 24U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToFlexpwm0Sm3Extsync          = 25U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToFlexpwm0Sm3Extsync          = 26U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToFlexpwm0Sm3Extsync          = 27U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToFlexpwm0Sm3Extsync          = 28U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToFlexpwm0Sm3Extsync          = 29U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToFlexpwm0Sm3Extsync         = 30U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToFlexpwm0Sm3Extsync         = 31U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToFlexpwm0Sm3Extsync        = 32U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToFlexpwm0Sm3Extsync        = 33U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToFlexpwm0Sm3Extsync        = 34U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToFlexpwm0Sm3Extsync        = 35U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_EccEiToFlexpwm0Sm3Extsync            = 37U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< ecc error interrupt input is selected */
    kINPUTMUX_WwdtToFlexpwm0Sm3Extsync             = 38U + (FlexPWM0_SM3_EXTSYNC_REG << PMUX_SHIFT),  /*!< wwdt0/1 interrupt input is selected */

    /*!< FlexPWM0_FAULT0: FlexPWM0_FAULT0 trigger input connections */
    kINPUTMUX_ArmTxevToFlexpwm0Fault0              = 1U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToFlexpwm0Fault0             = 2U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFlexpwm0Fault0             = 3U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToFlexpwm0Fault0             = 4U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToFlexpwm0Fault0             = 5U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToFlexpwm0Fault0              = 6U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToFlexpwm0Fault0          = 9U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToFlexpwm0Fault0          = 10U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToFlexpwm0Fault0          = 11U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToFlexpwm0Fault0          = 12U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToFlexpwm0Fault0          = 13U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToFlexpwm0Fault0          = 14U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToFlexpwm0Fault0              = 20U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToFlexpwm0Fault0              = 21U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToFlexpwm0Fault0              = 22U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToFlexpwm0Fault0              = 23U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToFlexpwm0Fault0              = 24U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToFlexpwm0Fault0              = 25U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToFlexpwm0Fault0              = 26U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToFlexpwm0Fault0              = 27U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToFlexpwm0Fault0              = 28U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToFlexpwm0Fault0              = 29U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToFlexpwm0Fault0             = 30U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToFlexpwm0Fault0             = 31U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToFlexpwm0Fault0            = 32U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToFlexpwm0Fault0            = 33U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToFlexpwm0Fault0            = 34U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToFlexpwm0Fault0            = 35U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_EccEiToFlexpwm0Fault0                = 37U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< ecc error interrupt input is selected */
    kINPUTMUX_WwdtToFlexpwm0Fault0                 = 38U + (FlexPWM0_FAULT0_REG << PMUX_SHIFT),  /*!< wwdt0/1 interrupt input is selected */

    /*!< FlexPWM0_FAULT1: FlexPWM0_FAULT1 trigger input connections */
    kINPUTMUX_ArmTxevToFlexpwm0Fault1              = 1U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToFlexpwm0Fault1             = 2U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFlexpwm0Fault1             = 3U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToFlexpwm0Fault1             = 4U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToFlexpwm0Fault1             = 5U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToFlexpwm0Fault1              = 6U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToFlexpwm0Fault1          = 9U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToFlexpwm0Fault1          = 10U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToFlexpwm0Fault1          = 11U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToFlexpwm0Fault1          = 12U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToFlexpwm0Fault1          = 13U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToFlexpwm0Fault1          = 14U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToFlexpwm0Fault1              = 20U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToFlexpwm0Fault1              = 21U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToFlexpwm0Fault1              = 22U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToFlexpwm0Fault1              = 23U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToFlexpwm0Fault1              = 24U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToFlexpwm0Fault1              = 25U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToFlexpwm0Fault1              = 26U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToFlexpwm0Fault1              = 27U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToFlexpwm0Fault1              = 28U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToFlexpwm0Fault1              = 29U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToFlexpwm0Fault1             = 30U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToFlexpwm0Fault1             = 31U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToFlexpwm0Fault1            = 32U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToFlexpwm0Fault1            = 33U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToFlexpwm0Fault1            = 34U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToFlexpwm0Fault1            = 35U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_EccEiToFlexpwm0Fault1                = 37U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< ecc error interrupt input is selected */
    kINPUTMUX_WwdtToFlexpwm0Fault1                 = 38U + (FlexPWM0_FAULT1_REG << PMUX_SHIFT),  /*!< wwdt0/1 interrupt input is selected */

    /*!< FlexPWM0_FAULT2: FlexPWM0_FAULT2 trigger input connections */
    kINPUTMUX_ArmTxevToFlexpwm0Fault2              = 1U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToFlexpwm0Fault2             = 2U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFlexpwm0Fault2             = 3U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToFlexpwm0Fault2             = 4U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToFlexpwm0Fault2             = 5U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToFlexpwm0Fault2              = 6U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToFlexpwm0Fault2          = 9U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToFlexpwm0Fault2          = 10U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToFlexpwm0Fault2          = 11U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToFlexpwm0Fault2          = 12U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToFlexpwm0Fault2          = 13U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToFlexpwm0Fault2          = 14U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToFlexpwm0Fault2              = 20U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToFlexpwm0Fault2              = 21U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToFlexpwm0Fault2              = 22U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToFlexpwm0Fault2              = 23U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToFlexpwm0Fault2              = 24U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToFlexpwm0Fault2              = 25U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToFlexpwm0Fault2              = 26U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToFlexpwm0Fault2              = 27U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToFlexpwm0Fault2              = 28U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToFlexpwm0Fault2              = 29U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToFlexpwm0Fault2             = 30U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToFlexpwm0Fault2             = 31U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToFlexpwm0Fault2            = 32U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToFlexpwm0Fault2            = 33U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToFlexpwm0Fault2            = 34U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToFlexpwm0Fault2            = 35U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_EccEiToFlexpwm0Fault2                = 37U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< ecc error interrupt input is selected */
    kINPUTMUX_WwdtToFlexpwm0Fault2                 = 38U + (FlexPWM0_FAULT2_REG << PMUX_SHIFT),  /*!< wwdt0/1 interrupt input is selected */

    /*!< FlexPWM0_FAULT3: FlexPWM0_FAULT3 trigger input connections */
    kINPUTMUX_ArmTxevToFlexpwm0Fault3              = 1U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToFlexpwm0Fault3             = 2U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFlexpwm0Fault3             = 3U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToFlexpwm0Fault3             = 4U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToFlexpwm0Fault3             = 5U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToFlexpwm0Fault3              = 6U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToFlexpwm0Fault3          = 9U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToFlexpwm0Fault3          = 10U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToFlexpwm0Fault3          = 11U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToFlexpwm0Fault3          = 12U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToFlexpwm0Fault3          = 13U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToFlexpwm0Fault3          = 14U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToFlexpwm0Fault3              = 20U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToFlexpwm0Fault3              = 21U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToFlexpwm0Fault3              = 22U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToFlexpwm0Fault3              = 23U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToFlexpwm0Fault3              = 24U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToFlexpwm0Fault3              = 25U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToFlexpwm0Fault3              = 26U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToFlexpwm0Fault3              = 27U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToFlexpwm0Fault3              = 28U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToFlexpwm0Fault3              = 29U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToFlexpwm0Fault3             = 30U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToFlexpwm0Fault3             = 31U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToFlexpwm0Fault3            = 32U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToFlexpwm0Fault3            = 33U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToFlexpwm0Fault3            = 34U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToFlexpwm0Fault3            = 35U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_EccEiToFlexpwm0Fault3                = 37U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< ecc error interrupt input is selected */
    kINPUTMUX_WwdtToFlexpwm0Fault3                 = 38U + (FlexPWM0_FAULT3_REG << PMUX_SHIFT),  /*!< wwdt0/1 interrupt input is selected */

    /*!< FlexPWM0_FORCE: FlexPWM0_FORCE trigger input connections */
    kINPUTMUX_ArmTxevToFlexpwm0Force               = 1U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToFlexpwm0Force              = 2U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFlexpwm0Force              = 3U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToFlexpwm0Force              = 4U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToFlexpwm0Force              = 5U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToFlexpwm0Force               = 6U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToFlexpwm0Force           = 9U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToFlexpwm0Force           = 10U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToFlexpwm0Force           = 11U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToFlexpwm0Force           = 12U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToFlexpwm0Force           = 13U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToFlexpwm0Force           = 14U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToFlexpwm0Force               = 20U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToFlexpwm0Force               = 21U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToFlexpwm0Force               = 22U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToFlexpwm0Force               = 23U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToFlexpwm0Force               = 24U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToFlexpwm0Force               = 25U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToFlexpwm0Force               = 26U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToFlexpwm0Force               = 27U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToFlexpwm0Force               = 28U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToFlexpwm0Force               = 29U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToFlexpwm0Force              = 30U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToFlexpwm0Force              = 31U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToFlexpwm0Force             = 32U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToFlexpwm0Force             = 33U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToFlexpwm0Force             = 34U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToFlexpwm0Force             = 35U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_EccEiToFlexpwm0Force                 = 37U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< ecc error interrupt input is selected */
    kINPUTMUX_WwdtToFlexpwm0Force                  = 38U + (FlexPWM0_FORCE_REG << PMUX_SHIFT),  /*!< wwdt0/1 interrupt input is selected */

    /*!< PWM0_EXT_CLK: eFlexPWM0 external clock trigger */
    kINPUTMUX_Clk16k1ToPwm0ExtClk                  = 1U + (PWM0_EXT_CLK_REG << PMUX_SHIFT),  /*!< clk_16k[1] input is selected */
    kINPUTMUX_ClkInToPwm0ExtClk                    = 2U + (PWM0_EXT_CLK_REG << PMUX_SHIFT),  /*!< clk_in input is selected */
    kINPUTMUX_Aoi0Out0ToPwm0ExtClk                 = 3U + (PWM0_EXT_CLK_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToPwm0ExtClk                 = 4U + (PWM0_EXT_CLK_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_TrigIn0ToPwm0ExtClk                  = 5U + (PWM0_EXT_CLK_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn7ToPwm0ExtClk                  = 6U + (PWM0_EXT_CLK_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */

    /*!< LPI2C0_TRIG: LPI2C0 trigger input connections */
    kINPUTMUX_Aoi0Out0ToLpi2c0Trig                 = 2U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLpi2c0Trig                 = 3U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLpi2c0Trig                 = 4U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLpi2c0Trig                 = 5U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLpi2c0Trig                  = 6U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat0ToLpi2c0Trig              = 9U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat0 input is selected */
    kINPUTMUX_Ctimer0Mat1ToLpi2c0Trig              = 10U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat0ToLpi2c0Trig              = 11U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat0 input is selected */
    kINPUTMUX_Ctimer1Mat1ToLpi2c0Trig              = 12U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat0ToLpi2c0Trig              = 13U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat0 input is selected */
    kINPUTMUX_Ctimer2Mat1ToLpi2c0Trig              = 14U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Lptmr0ToLpi2c0Trig                   = 15U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< lptmr0 input is selected */
    kINPUTMUX_TrigIn0ToLpi2c0Trig                  = 17U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLpi2c0Trig                  = 18U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLpi2c0Trig                  = 19U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLpi2c0Trig                  = 20U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLpi2c0Trig                  = 21U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLpi2c0Trig                  = 22U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLpi2c0Trig                  = 23U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLpi2c0Trig                  = 24U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_Gpio0Pet0ToLpi2c0Trig                = 25U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToLpi2c0Trig                = 26U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLpi2c0Trig                = 27U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLpi2c0Trig                = 28U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToLpi2c0Trig                      = 30U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< LPI2C1_TRIG: LPI2C1 trigger input connections */
    kINPUTMUX_Aoi0Out0ToLpi2c1Trig                 = 2U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLpi2c1Trig                 = 3U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLpi2c1Trig                 = 4U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLpi2c1Trig                 = 5U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLpi2c1Trig                  = 6U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat0ToLpi2c1Trig              = 9U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat0 input is selected */
    kINPUTMUX_Ctimer0Mat1ToLpi2c1Trig              = 10U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat0ToLpi2c1Trig              = 11U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat0 input is selected */
    kINPUTMUX_Ctimer1Mat1ToLpi2c1Trig              = 12U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat0ToLpi2c1Trig              = 13U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat0 input is selected */
    kINPUTMUX_Ctimer2Mat1ToLpi2c1Trig              = 14U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Lptmr0ToLpi2c1Trig                   = 15U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< lptmr0 input is selected */
    kINPUTMUX_TrigIn0ToLpi2c1Trig                  = 17U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLpi2c1Trig                  = 18U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLpi2c1Trig                  = 19U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLpi2c1Trig                  = 20U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLpi2c1Trig                  = 21U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLpi2c1Trig                  = 22U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLpi2c1Trig                  = 23U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLpi2c1Trig                  = 24U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_Gpio0Pet0ToLpi2c1Trig                = 25U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToLpi2c1Trig                = 26U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLpi2c1Trig                = 27U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLpi2c1Trig                = 28U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToLpi2c1Trig                      = 30U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< LPI2C2_TRIG: LPI2C2 trigger input connections */
    kINPUTMUX_Aoi0Out0ToLpi2c2Trig                 = 2U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLpi2c2Trig                 = 3U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLpi2c2Trig                 = 4U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLpi2c2Trig                 = 5U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLpi2c2Trig                  = 6U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat0ToLpi2c2Trig              = 9U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat0 input is selected */
    kINPUTMUX_Ctimer0Mat1ToLpi2c2Trig              = 10U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat0ToLpi2c2Trig              = 11U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat0 input is selected */
    kINPUTMUX_Ctimer1Mat1ToLpi2c2Trig              = 12U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat0ToLpi2c2Trig              = 13U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat0 input is selected */
    kINPUTMUX_Ctimer2Mat1ToLpi2c2Trig              = 14U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Lptmr0ToLpi2c2Trig                   = 15U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< lptmr0 input is selected */
    kINPUTMUX_TrigIn0ToLpi2c2Trig                  = 17U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLpi2c2Trig                  = 18U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLpi2c2Trig                  = 19U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLpi2c2Trig                  = 20U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLpi2c2Trig                  = 21U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLpi2c2Trig                  = 22U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLpi2c2Trig                  = 23U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLpi2c2Trig                  = 24U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_Gpio0Pet0ToLpi2c2Trig                = 25U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToLpi2c2Trig                = 26U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLpi2c2Trig                = 27U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLpi2c2Trig                = 28U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToLpi2c2Trig                      = 30U + (LPI2C2_TRIG_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< LPSPI0_TRIG: LPSPI0 trigger input connections */
    kINPUTMUX_Aoi0Out0ToLpspi0Trig                 = 2U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLpspi0Trig                 = 3U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLpspi0Trig                 = 4U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLpspi0Trig                 = 5U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLpspi0Trig                  = 6U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat1ToLpspi0Trig              = 9U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer0Mat2ToLpspi0Trig              = 10U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat1ToLpspi0Trig              = 11U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat2ToLpspi0Trig              = 12U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat1ToLpspi0Trig              = 13U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat2ToLpspi0Trig              = 14U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Lptmr0ToLpspi0Trig                   = 15U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< lptmr0 input is selected */
    kINPUTMUX_TrigIn0ToLpspi0Trig                  = 17U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLpspi0Trig                  = 18U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLpspi0Trig                  = 19U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLpspi0Trig                  = 20U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLpspi0Trig                  = 21U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLpspi0Trig                  = 22U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLpspi0Trig                  = 23U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLpspi0Trig                  = 24U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_Gpio0Pet0ToLpspi0Trig                = 25U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToLpspi0Trig                = 26U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLpspi0Trig                = 27U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLpspi0Trig                = 28U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToLpspi0Trig                      = 30U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< LPSPI1_TRIG: LPSPI1 trigger input connections */
    kINPUTMUX_Aoi0Out0ToLpspi1Trig                 = 2U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLpspi1Trig                 = 3U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLpspi1Trig                 = 4U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLpspi1Trig                 = 5U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLpspi1Trig                  = 6U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat1ToLpspi1Trig              = 9U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer0Mat2ToLpspi1Trig              = 10U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat1ToLpspi1Trig              = 11U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat2ToLpspi1Trig              = 12U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat1ToLpspi1Trig              = 13U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat2ToLpspi1Trig              = 14U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Lptmr0ToLpspi1Trig                   = 15U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< lptmr0 input is selected */
    kINPUTMUX_TrigIn0ToLpspi1Trig                  = 17U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLpspi1Trig                  = 18U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLpspi1Trig                  = 19U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLpspi1Trig                  = 20U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLpspi1Trig                  = 21U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLpspi1Trig                  = 22U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLpspi1Trig                  = 23U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLpspi1Trig                  = 24U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_Gpio0Pet0ToLpspi1Trig                = 25U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToLpspi1Trig                = 26U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLpspi1Trig                = 27U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLpspi1Trig                = 28U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToLpspi1Trig                      = 30U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< LPUART0: LPUART0 trigger input connections */
    kINPUTMUX_Aoi0Out0ToLPUART0                    = 2U + (LPUART0_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLPUART0                    = 3U + (LPUART0_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLPUART0                    = 4U + (LPUART0_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLPUART0                    = 5U + (LPUART0_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLPUART0                     = 6U + (LPUART0_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToLPUART0                 = 9U + (LPUART0_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToLPUART0                 = 10U + (LPUART0_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToLPUART0                 = 11U + (LPUART0_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToLPUART0                 = 12U + (LPUART0_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToLPUART0                 = 13U + (LPUART0_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToLPUART0                 = 14U + (LPUART0_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_Lptmr0ToLPUART0                      = 15U + (LPUART0_REG << PMUX_SHIFT),  /*!< lptmr0 input is selected */
    kINPUTMUX_TrigIn0ToLPUART0                     = 17U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLPUART0                     = 18U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLPUART0                     = 19U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLPUART0                     = 20U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLPUART0                     = 21U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLPUART0                     = 22U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLPUART0                     = 23U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLPUART0                     = 24U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToLPUART0                     = 25U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToLPUART0                     = 26U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToLPUART0                    = 27U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToLPUART0                    = 28U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToLPUART0                   = 29U + (LPUART0_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToLPUART0                   = 30U + (LPUART0_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLPUART0                   = 31U + (LPUART0_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLPUART0                   = 32U + (LPUART0_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToLPUART0                         = 34U + (LPUART0_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< LPUART1: LPUART1 trigger input connections */
    kINPUTMUX_Aoi0Out0ToLPUART1                    = 2U + (LPUART1_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLPUART1                    = 3U + (LPUART1_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLPUART1                    = 4U + (LPUART1_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLPUART1                    = 5U + (LPUART1_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLPUART1                     = 6U + (LPUART1_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToLPUART1                 = 9U + (LPUART1_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToLPUART1                 = 10U + (LPUART1_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToLPUART1                 = 11U + (LPUART1_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToLPUART1                 = 12U + (LPUART1_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToLPUART1                 = 13U + (LPUART1_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToLPUART1                 = 14U + (LPUART1_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_Lptmr0ToLPUART1                      = 15U + (LPUART1_REG << PMUX_SHIFT),  /*!< lptmr0 input is selected */
    kINPUTMUX_TrigIn0ToLPUART1                     = 17U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLPUART1                     = 18U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLPUART1                     = 19U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLPUART1                     = 20U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLPUART1                     = 21U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLPUART1                     = 22U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLPUART1                     = 23U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLPUART1                     = 24U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToLPUART1                     = 25U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToLPUART1                     = 26U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToLPUART1                    = 27U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToLPUART1                    = 28U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToLPUART1                   = 29U + (LPUART1_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToLPUART1                   = 30U + (LPUART1_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLPUART1                   = 31U + (LPUART1_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLPUART1                   = 32U + (LPUART1_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToLPUART1                         = 34U + (LPUART1_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< LPUART2: LPUART2 trigger input connections */
    kINPUTMUX_Aoi0Out0ToLPUART2                    = 2U + (LPUART2_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLPUART2                    = 3U + (LPUART2_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLPUART2                    = 4U + (LPUART2_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLPUART2                    = 5U + (LPUART2_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLPUART2                     = 6U + (LPUART2_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToLPUART2                 = 9U + (LPUART2_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToLPUART2                 = 10U + (LPUART2_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToLPUART2                 = 11U + (LPUART2_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToLPUART2                 = 12U + (LPUART2_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToLPUART2                 = 13U + (LPUART2_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToLPUART2                 = 14U + (LPUART2_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_Lptmr0ToLPUART2                      = 15U + (LPUART2_REG << PMUX_SHIFT),  /*!< lptmr0 input is selected */
    kINPUTMUX_TrigIn0ToLPUART2                     = 17U + (LPUART2_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLPUART2                     = 18U + (LPUART2_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLPUART2                     = 19U + (LPUART2_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLPUART2                     = 20U + (LPUART2_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLPUART2                     = 21U + (LPUART2_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLPUART2                     = 22U + (LPUART2_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLPUART2                     = 23U + (LPUART2_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLPUART2                     = 24U + (LPUART2_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToLPUART2                     = 25U + (LPUART2_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToLPUART2                     = 26U + (LPUART2_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToLPUART2                    = 27U + (LPUART2_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToLPUART2                    = 28U + (LPUART2_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToLPUART2                   = 29U + (LPUART2_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToLPUART2                   = 30U + (LPUART2_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLPUART2                   = 31U + (LPUART2_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLPUART2                   = 32U + (LPUART2_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToLPUART2                         = 34U + (LPUART2_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< LPUART3: LPUART3 trigger input connections */
    kINPUTMUX_Aoi0Out0ToLPUART3                    = 2U + (LPUART3_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLPUART3                    = 3U + (LPUART3_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLPUART3                    = 4U + (LPUART3_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLPUART3                    = 5U + (LPUART3_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLPUART3                     = 6U + (LPUART3_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToLPUART3                 = 9U + (LPUART3_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToLPUART3                 = 10U + (LPUART3_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToLPUART3                 = 11U + (LPUART3_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToLPUART3                 = 12U + (LPUART3_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToLPUART3                 = 13U + (LPUART3_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToLPUART3                 = 14U + (LPUART3_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_Lptmr0ToLPUART3                      = 15U + (LPUART3_REG << PMUX_SHIFT),  /*!< lptmr0 input is selected */
    kINPUTMUX_TrigIn0ToLPUART3                     = 17U + (LPUART3_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLPUART3                     = 18U + (LPUART3_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLPUART3                     = 19U + (LPUART3_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLPUART3                     = 20U + (LPUART3_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLPUART3                     = 21U + (LPUART3_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLPUART3                     = 22U + (LPUART3_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLPUART3                     = 23U + (LPUART3_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLPUART3                     = 24U + (LPUART3_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToLPUART3                     = 25U + (LPUART3_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToLPUART3                     = 26U + (LPUART3_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToLPUART3                    = 27U + (LPUART3_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToLPUART3                    = 28U + (LPUART3_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToLPUART3                   = 29U + (LPUART3_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToLPUART3                   = 30U + (LPUART3_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLPUART3                   = 31U + (LPUART3_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLPUART3                   = 32U + (LPUART3_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToLPUART3                         = 34U + (LPUART3_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< LPUART4: LPUART4 trigger input connections */
    kINPUTMUX_Aoi0Out0ToLPUART4                    = 2U + (LPUART4_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLPUART4                    = 3U + (LPUART4_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLPUART4                    = 4U + (LPUART4_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLPUART4                    = 5U + (LPUART4_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLPUART4                     = 6U + (LPUART4_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToLPUART4                 = 9U + (LPUART4_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToLPUART4                 = 10U + (LPUART4_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToLPUART4                 = 11U + (LPUART4_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToLPUART4                 = 12U + (LPUART4_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToLPUART4                 = 13U + (LPUART4_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToLPUART4                 = 14U + (LPUART4_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_Lptmr0ToLPUART4                      = 15U + (LPUART4_REG << PMUX_SHIFT),  /*!< lptmr0 input is selected */
    kINPUTMUX_TrigIn0ToLPUART4                     = 17U + (LPUART4_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLPUART4                     = 18U + (LPUART4_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLPUART4                     = 19U + (LPUART4_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLPUART4                     = 20U + (LPUART4_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLPUART4                     = 21U + (LPUART4_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLPUART4                     = 22U + (LPUART4_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLPUART4                     = 23U + (LPUART4_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLPUART4                     = 24U + (LPUART4_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToLPUART4                     = 25U + (LPUART4_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToLPUART4                     = 26U + (LPUART4_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToLPUART4                    = 27U + (LPUART4_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToLPUART4                    = 28U + (LPUART4_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio0Pet0ToLPUART4                   = 29U + (LPUART4_REG << PMUX_SHIFT),  /*!< gpio0 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToLPUART4                   = 30U + (LPUART4_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLPUART4                   = 31U + (LPUART4_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLPUART4                   = 32U + (LPUART4_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToLPUART4                         = 34U + (LPUART4_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< TSI0: TSI0 trigger input connections */
    kINPUTMUX_Ctimer0Mat2ToTSI0                    = 1U + (TSI0_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToTSI0                    = 2U + (TSI0_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToTSI0                    = 3U + (TSI0_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToTSI0                    = 4U + (TSI0_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToTSI0                    = 5U + (TSI0_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToTSI0                    = 6U + (TSI0_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_Lptmr0ToTSI0                         = 11U + (TSI0_REG << PMUX_SHIFT),  /*!< lptmr0 input is selected */
    kINPUTMUX_WuuToTSI0                            = 12U + (TSI0_REG << PMUX_SHIFT),  /*!< wuu input is selected */

} inputmux_connection_t;

#define kINPUTMUX_Lptmr0ToTsi0Triginput kINPUTMUX_Lptmr0ToTSI0

/*@}*/

/*@}*/

#endif /* _FSL_INPUTMUX_CONNECTIONS_ */