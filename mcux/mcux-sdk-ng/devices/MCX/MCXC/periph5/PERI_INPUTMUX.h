/*
** ###################################################################
**     Processors:          MCXC163VFM
**                          MCXC163VFT
**                          MCXC163VLF
**                          MCXC163VLH
**                          MCXC163VLK
**                          MCXC163VMP
**                          MCXC164VFM
**                          MCXC164VFT
**                          MCXC164VLF
**                          MCXC164VLH
**                          MCXC164VLK
**                          MCXC164VMP
**                          MCXC453VFM
**                          MCXC453VFT
**                          MCXC453VLF
**                          MCXC453VLH
**                          MCXC453VLK
**                          MCXC453VMP
**                          MCXC454VFM
**                          MCXC454VFT
**                          MCXC454VLF
**                          MCXC454VLH
**                          MCXC454VLK
**                          MCXC454VMP
**
**     Version:             rev. 1.0, 2026-03-13
**     Build:               b260917
**
**     Abstract:
**         CMSIS Peripheral Access Layer for INPUTMUX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2026-03-13)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_INPUTMUX.h
 * @version 1.0
 * @date 2026-03-13
 * @brief CMSIS Peripheral Access Layer for INPUTMUX
 *
 * CMSIS Peripheral Access Layer for INPUTMUX
 */

#if !defined(PERI_INPUTMUX_H_)
#define PERI_INPUTMUX_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC163VFM) || defined(CPU_MCXC163VFT) || defined(CPU_MCXC163VLF) || defined(CPU_MCXC163VLH) || defined(CPU_MCXC163VLK) || defined(CPU_MCXC163VMP))
#include "MCXC163_COMMON.h"
#elif (defined(CPU_MCXC164VFM) || defined(CPU_MCXC164VFT) || defined(CPU_MCXC164VLF) || defined(CPU_MCXC164VLH) || defined(CPU_MCXC164VLK) || defined(CPU_MCXC164VMP))
#include "MCXC164_COMMON.h"
#elif (defined(CPU_MCXC453VFM) || defined(CPU_MCXC453VFT) || defined(CPU_MCXC453VLF) || defined(CPU_MCXC453VLH) || defined(CPU_MCXC453VLK) || defined(CPU_MCXC453VMP))
#include "MCXC453_COMMON.h"
#elif (defined(CPU_MCXC454VFM) || defined(CPU_MCXC454VFT) || defined(CPU_MCXC454VLF) || defined(CPU_MCXC454VLH) || defined(CPU_MCXC454VLK) || defined(CPU_MCXC454VMP))
#include "MCXC454_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- INPUTMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX_Peripheral_Access_Layer INPUTMUX Peripheral Access Layer
 * @{
 */

/** INPUTMUX - Size of Registers Arrays */
#define INPUTMUX_CTIMERA_COUNT                    4u
#define INPUTMUX_CTIMERB_COUNT                    4u
#define INPUTMUX_CTIMERC_COUNT                    4u
#define INPUTMUX_ADC0_TRIGM_COUNT                 4u
#define INPUTMUX_AOI0_COUNT                       16u
#define INPUTMUX_EXT_TRIGA_COUNT                  8u

/** INPUTMUX - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __IO uint32_t CTIMER0CAP[INPUTMUX_CTIMERA_COUNT]; /**< Capture select register for CTIMER0 inputs, array offset: 0x20, array step: 0x4 */
  __IO uint32_t CTIMER0TRIG;                       /**< Trigger register for CTIMER0, offset: 0x30 */
       uint8_t RESERVED_1[12];
  __IO uint32_t CTIMER1CAP[INPUTMUX_CTIMERB_COUNT]; /**< Capture select register for CTIMER1 inputs, array offset: 0x40, array step: 0x4 */
  __IO uint32_t CTIMER1TRIG;                       /**< Trigger register for CTIMER1, offset: 0x50 */
       uint8_t RESERVED_2[12];
  __IO uint32_t CTIMER2CAP[INPUTMUX_CTIMERC_COUNT]; /**< Capture select register for CTIMER2 inputs, array offset: 0x60, array step: 0x4 */
  __IO uint32_t CTIMER2TRIG;                       /**< Trigger register for CTIMER2, offset: 0x70 */
       uint8_t RESERVED_3[268];
  __IO uint32_t FREQMEAS_REF;                      /**< Selection for frequency measurement reference clock, offset: 0x180 */
  __IO uint32_t FREQMEAS_TAR;                      /**< Selection for frequency measurement target clock, offset: 0x184 */
       uint8_t RESERVED_4[216];
  __IO uint32_t LPCMP0_TRIG;                       /**< LPCMP0 trigger input connections, offset: 0x260 */
       uint8_t RESERVED_5[28];
  __IO uint32_t ADC0_TRIG[INPUTMUX_ADC0_TRIGM_COUNT]; /**< ADC trigger input connections, array offset: 0x280, array step: 0x4 */
       uint8_t RESERVED_6[272];
  __IO uint32_t FLEXPWM0_SM0_EXTA0;                /**< FlexPWM0_SM0_EXTA0 trigger input connections, offset: 0x3A0 */
  __IO uint32_t FLEXPWM0_SM0_EXTSYNC;              /**< FlexPWM0_SM0_EXTSYNC trigger input connections, offset: 0x3A4 */
  __IO uint32_t FLEXPWM0_SM1_EXTA;                 /**< FlexPWM0_SM1_EXTA trigger input connections, offset: 0x3A8 */
  __IO uint32_t FLEXPWM0_SM1_EXTSYNC;              /**< FlexPWM0_SM1_EXTSYNC trigger input connections, offset: 0x3AC */
  __IO uint32_t FLEXPWM0_SM2_EXTA;                 /**< FlexPWM0_SM2_EXTA trigger input connections, offset: 0x3B0 */
  __IO uint32_t FLEXPWM0_SM2_EXTSYNC;              /**< FlexPWM0_SM2_EXTSYNC trigger input connections, offset: 0x3B4 */
  __IO uint32_t FLEXPWM0_SM3_EXTA;                 /**< FlexPWM0_SM3_EXTA trigger input connections, offset: 0x3B8 */
  __IO uint32_t FLEXPWM0_SM3_EXTSYNC;              /**< FlexPWM0_SM3_EXTSYNC trigger input connections, offset: 0x3BC */
  __IO uint32_t FLEXPWM0_FAULT0;                   /**< FlexPWM0_FAULT0 trigger input connections, offset: 0x3C0 */
  __IO uint32_t FLEXPWM0_FAULT1;                   /**< FlexPWM0_FAULT1 trigger input connections, offset: 0x3C4 */
  __IO uint32_t FLEXPWM0_FAULT2;                   /**< FlexPWM0_FAULT2 trigger input connections, offset: 0x3C8 */
  __IO uint32_t FLEXPWM0_FAULT3;                   /**< FlexPWM0_FAULT3 trigger input connections, offset: 0x3CC */
  __IO uint32_t FLEXPWM0_FORCE;                    /**< FlexPWM0_FORCE trigger input connections, offset: 0x3D0 */
       uint8_t RESERVED_7[76];
  __IO uint32_t PWM0_EXT_CLK;                      /**< eFlexPWM0 external clock trigger, offset: 0x420 */
       uint8_t RESERVED_8[28];
  __IO uint32_t AOI0INPUT[INPUTMUX_AOI0_COUNT];    /**< AOI0 trigger input connections, array offset: 0x440, array step: 0x4 */
       uint8_t RESERVED_9[32];
  __IO uint32_t TSI0r;                             /**< TSI0 trigger input connections, offset: 0x4A0, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'TSI0' */
       uint8_t RESERVED_10[28];
  __IO uint32_t EXT_TRIG[INPUTMUX_EXT_TRIGA_COUNT]; /**< EXT trigger connections 0-7, array offset: 0x4C0, array step: 0x4 */
       uint8_t RESERVED_11[96];
  __IO uint32_t LPI2C2_TRIG;                       /**< LPI2C2 trigger input connections, offset: 0x540 */
       uint8_t RESERVED_12[92];
  __IO uint32_t LPI2C0_TRIG;                       /**< LPI2C0 trigger input connections, offset: 0x5A0 */
       uint8_t RESERVED_13[28];
  __IO uint32_t LPI2C1_TRIG;                       /**< LPI2C1 trigger input connections, offset: 0x5C0 */
       uint8_t RESERVED_14[28];
  __IO uint32_t LPSPI0_TRIG;                       /**< LPSPI0 trigger input connections, offset: 0x5E0 */
       uint8_t RESERVED_15[28];
  __IO uint32_t LPSPI1_TRIG;                       /**< LPSPI1 trigger input connections, offset: 0x600 */
       uint8_t RESERVED_16[28];
  __IO uint32_t LPUART0r;                          /**< LPUART0 trigger input connections, offset: 0x620, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART0' */
       uint8_t RESERVED_17[28];
  __IO uint32_t LPUART1r;                          /**< LPUART1 trigger input connections, offset: 0x640, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART1' */
       uint8_t RESERVED_18[28];
  __IO uint32_t LPUART2r;                          /**< LPUART2 trigger input connections, offset: 0x660, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART2' */
       uint8_t RESERVED_19[28];
  __IO uint32_t LPUART3r;                          /**< LPUART3 trigger input connections, offset: 0x680, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART3' */
       uint8_t RESERVED_20[28];
  __IO uint32_t LPUART4r;                          /**< LPUART4 trigger input connections, offset: 0x6A0, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LPUART4' */
} INPUTMUX_Type;

/* ----------------------------------------------------------------------------
   -- INPUTMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INPUTMUX_Register_Masks INPUTMUX Register Masks
 * @{
 */

/*! @name CTIMER0CAP - Capture select register for CTIMER0 inputs */
/*! @{ */

#define INPUTMUX_CTIMER0CAP_INP_MASK             (0x7FU)
#define INPUTMUX_CTIMER0CAP_INP_SHIFT            (0U)
/*! INP - Capture Inputs for CTIMER0
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..CT_INP4 input is selected
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..CT_INP7 input is selected
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..CT_INP10 input is selected
 *  0b0001100..CT_INP11 input is selected
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..CT_INP14 input is selected
 *  0b0010000..CT_INP15 input is selected
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0] input is selected
 *  0b0011011..ADC0_tcomp[1] input is selected
 *  0b0011100..ADC0_tcomp[2] input is selected
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT input is selected
 *  0b0011111..LPI2C2 Master End of Packet input is selected
 *  0b0100000..LPI2C2 Slave End of Packet input is selected
 *  0b0100001..CTimer1_MAT1 input is selected
 *  0b0100010..CTimer1_MAT2 input is selected
 *  0b0100011..CTimer1_MAT3 input is selected
 *  0b0100100..CTimer2_MAT1 input is selected
 *  0b0100101..CTimer2_MAT2 input is selected
 *  0b0100110..CTimer2_MAT3 input is selected
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..LPSPI1 End of Frame input is selected
 *  0b0110111..LPSPI1 Received Data Word input is selected
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..TRIG_IN0 input is selected
 *  0b1000010..TRIG_IN1 input is selected
 *  0b1000011..TRIG_IN2 input is selected
 *  0b1000100..TRIG_IN3 input is selected
 *  0b1000101..TRIG_IN4 input is selected
 *  0b1000110..TRIG_IN5 input is selected
 *  0b1000111..TRIG_IN6 input is selected
 *  0b1001000..TRIG_IN7 input is selected
 *  0b1001001..TRIG_IN8 input is selected
 *  0b1001010..TRIG_IN9 input is selected
 *  0b1001011..TRIG_IN10 input is selected
 *  0b1001100..TRIG_IN11 input is selected
 *  0b1001101..LPUART3 Received Data Word input is selected
 *  0b1001110..LPUART3 Transmitted Data Word input is selected
 *  0b1001111..LPUART3 Receive Line Idle input is selected
 *  0b1010000..LPUART4 Received Data Word input is selected
 *  0b1010001..LPUART4 Transmitted Data Word input is selected
 *  0b1010010..LPUART4 Receive Line Idle input is selected
 *  0b1010011..Reserved
 *  0b1010100..Reserved
 *  0b1010101..Reserved
 *  0b1010110..Reserved
 *  0b1010111..Reserved
 *  0b1011000..Reserved
 *  0b1011001..Reserved
 *  0b1011010..Reserved
 *  0b1011011..Reserved
 *  0b1011100..Reserved
 *  0b1011101..Reserved
 *  0b1011110..Reserved
 *  0b1011111..Reserved
 *  0b1100000..Reserved
 *  0b1100001..Reserved
 *  0b1100010..Reserved
 *  0b1100011..Reserved
 *  0b1100100..Reserved
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..Reserved
 *  0b1101010..Reserved
 *  0b1101011..Reserved
 *  0b1101100..Reserved
 *  0b1101101..Reserved
 *  0b1101110..Reserved
 *  0b1101111..Reserved
 *  0b1110000..Reserved
 */
#define INPUTMUX_CTIMER0CAP_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER0CAP_INP_SHIFT)) & INPUTMUX_CTIMER0CAP_INP_MASK)
/*! @} */

/* The count of INPUTMUX_CTIMER0CAP */
#define INPUTMUX_CTIMER0CAP_COUNT                (4U)

/*! @name CTIMER0TRIG - Trigger register for CTIMER0 */
/*! @{ */

#define INPUTMUX_CTIMER0TRIG_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER0TRIG_INP_SHIFT           (0U)
/*! INP - Trigger Inputs for CTIMER0
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..CT_INP4 input is selected
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..CT_INP7 input is selected
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..CT_INP10 input is selected
 *  0b0001100..CT_INP11 input is selected
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..CT_INP14 input is selected
 *  0b0010000..CT_INP15 input is selected
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0] input is selected
 *  0b0011011..ADC0_tcomp[1] input is selected
 *  0b0011100..ADC0_tcomp[2] input is selected
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT input is selected
 *  0b0011111..LPI2C2 Master End of Packet input is selected
 *  0b0100000..LPI2C2 Slave End of Packet input is selected
 *  0b0100001..CTimer1_MAT1 input is selected
 *  0b0100010..CTimer1_MAT2 input is selected
 *  0b0100011..CTimer1_MAT3 input is selected
 *  0b0100100..CTimer2_MAT1 input is selected
 *  0b0100101..CTimer2_MAT2 input is selected
 *  0b0100110..CTimer2_MAT3 input is selected
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..LPSPI1 End of Frame input is selected
 *  0b0110111..LPSPI1 Received Data Word input is selected
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..TRIG_IN0 input is selected
 *  0b1000010..TRIG_IN1 input is selected
 *  0b1000011..TRIG_IN2 input is selected
 *  0b1000100..TRIG_IN3 input is selected
 *  0b1000101..TRIG_IN4 input is selected
 *  0b1000110..TRIG_IN5 input is selected
 *  0b1000111..TRIG_IN6 input is selected
 *  0b1001000..TRIG_IN7 input is selected
 *  0b1001001..TRIG_IN8 input is selected
 *  0b1001010..TRIG_IN9 input is selected
 *  0b1001011..TRIG_IN10 input is selected
 *  0b1001100..TRIG_IN11 input is selected
 *  0b1001101..LPUART3 Received Data Word input is selected
 *  0b1001110..LPUART3 Transmitted Data Word input is selected
 *  0b1001111..LPUART3 Receive Line Idle input is selected
 *  0b1010000..LPUART4 Received Data Word input is selected
 *  0b1010001..LPUART4 Transmitted Data Word input is selected
 *  0b1010010..LPUART4 Receive Line Idle input is selected
 *  0b1010011..Reserved
 *  0b1010100..Reserved
 *  0b1010101..Reserved
 *  0b1010110..Reserved
 *  0b1010111..Reserved
 *  0b1011000..Reserved
 *  0b1011001..Reserved
 *  0b1011010..Reserved
 *  0b1011011..Reserved
 *  0b1011100..Reserved
 *  0b1011101..Reserved
 *  0b1011110..Reserved
 *  0b1011111..Reserved
 *  0b1100000..Reserved
 *  0b1100001..Reserved
 *  0b1100010..Reserved
 *  0b1100011..Reserved
 *  0b1100100..Reserved
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..Reserved
 *  0b1101010..Reserved
 *  0b1101011..Reserved
 *  0b1101100..Reserved
 *  0b1101101..Reserved
 *  0b1101110..Reserved
 *  0b1101111..Reserved
 *  0b1110000..Reserved
 */
#define INPUTMUX_CTIMER0TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER0TRIG_INP_SHIFT)) & INPUTMUX_CTIMER0TRIG_INP_MASK)
/*! @} */

/*! @name CTIMER1CAP - Capture select register for CTIMER1 inputs */
/*! @{ */

#define INPUTMUX_CTIMER1CAP_INP_MASK             (0x7FU)
#define INPUTMUX_CTIMER1CAP_INP_SHIFT            (0U)
/*! INP - Capture Inputs for CTIMER1
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..CT_INP4 input is selected
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..CT_INP7 input is selected
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..CT_INP10 input is selected
 *  0b0001100..CT_INP11 input is selected
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..CT_INP14 input is selected
 *  0b0010000..CT_INP15 input is selected
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0] input is selected
 *  0b0011011..ADC0_tcomp[1] input is selected
 *  0b0011100..ADC0_tcomp[2] input is selected
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT input is selected
 *  0b0011111..LPI2C2 Master End of Packet input is selected
 *  0b0100000..LPI2C2 Slave End of Packet input is selected
 *  0b0100001..CTimer0_MAT1 input is selected
 *  0b0100010..CTimer0_MAT2 input is selected
 *  0b0100011..CTimer0_MAT3 input is selected
 *  0b0100100..CTimer2_MAT1 input is selected
 *  0b0100101..CTimer2_MAT2 input is selected
 *  0b0100110..CTimer2_MAT3 input is selected
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..LPSPI1 End of Frame input is selected
 *  0b0110111..LPSPI1 Received Data Word input is selected
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..TRIG_IN0 input is selected
 *  0b1000010..TRIG_IN1 input is selected
 *  0b1000011..TRIG_IN2 input is selected
 *  0b1000100..TRIG_IN3 input is selected
 *  0b1000101..TRIG_IN4 input is selected
 *  0b1000110..TRIG_IN5 input is selected
 *  0b1000111..TRIG_IN6 input is selected
 *  0b1001000..TRIG_IN7 input is selected
 *  0b1001001..TRIG_IN8 input is selected
 *  0b1001010..TRIG_IN9 input is selected
 *  0b1001011..TRIG_IN10 input is selected
 *  0b1001100..TRIG_IN11 input is selected
 *  0b1001101..LPUART3 Received Data Word input is selected
 *  0b1001110..LPUART3 Transmitted Data Word input is selected
 *  0b1001111..LPUART3 Receive Line Idle input is selected
 *  0b1010000..LPUART4 Received Data Word input is selected
 *  0b1010001..LPUART4 Transmitted Data Word input is selected
 *  0b1010010..LPUART4 Receive Line Idle input is selected
 *  0b1010011..Reserved
 *  0b1010100..Reserved
 *  0b1010101..Reserved
 *  0b1010110..Reserved
 *  0b1010111..Reserved
 *  0b1011000..Reserved
 *  0b1011001..Reserved
 *  0b1011010..Reserved
 *  0b1011011..Reserved
 *  0b1011100..Reserved
 *  0b1011101..Reserved
 *  0b1011110..Reserved
 *  0b1011111..Reserved
 *  0b1100000..Reserved
 *  0b1100001..Reserved
 *  0b1100010..Reserved
 *  0b1100011..Reserved
 *  0b1100100..Reserved
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..Reserved
 *  0b1101010..Reserved
 *  0b1101011..Reserved
 *  0b1101100..Reserved
 *  0b1101101..Reserved
 *  0b1101110..Reserved
 *  0b1101111..Reserved
 *  0b1110000..Reserved
 */
#define INPUTMUX_CTIMER1CAP_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER1CAP_INP_SHIFT)) & INPUTMUX_CTIMER1CAP_INP_MASK)
/*! @} */

/* The count of INPUTMUX_CTIMER1CAP */
#define INPUTMUX_CTIMER1CAP_COUNT                (4U)

/*! @name CTIMER1TRIG - Trigger register for CTIMER1 */
/*! @{ */

#define INPUTMUX_CTIMER1TRIG_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER1TRIG_INP_SHIFT           (0U)
/*! INP - Trigger Inputs for CTIMER1
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..CT_INP4 input is selected
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..CT_INP7 input is selected
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..CT_INP10 input is selected
 *  0b0001100..CT_INP11 input is selected
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..CT_INP14 input is selected
 *  0b0010000..CT_INP15 input is selected
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0] input is selected
 *  0b0011011..ADC0_tcomp[1] input is selected
 *  0b0011100..ADC0_tcomp[2] input is selected
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT input is selected
 *  0b0011111..LPI2C2 Master End of Packet input is selected
 *  0b0100000..LPI2C2 Slave End of Packet input is selected
 *  0b0100001..CTimer0_MAT1 input is selected
 *  0b0100010..CTimer0_MAT2 input is selected
 *  0b0100011..CTimer0_MAT3 input is selected
 *  0b0100100..CTimer2_MAT1 input is selected
 *  0b0100101..CTimer2_MAT2 input is selected
 *  0b0100110..CTimer2_MAT3 input is selected
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..LPSPI1 End of Frame input is selected
 *  0b0110111..LPSPI1 Received Data Word input is selected
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..TRIG_IN0 input is selected
 *  0b1000010..TRIG_IN1 input is selected
 *  0b1000011..TRIG_IN2 input is selected
 *  0b1000100..TRIG_IN3 input is selected
 *  0b1000101..TRIG_IN4 input is selected
 *  0b1000110..TRIG_IN5 input is selected
 *  0b1000111..TRIG_IN6 input is selected
 *  0b1001000..TRIG_IN7 input is selected
 *  0b1001001..TRIG_IN8 input is selected
 *  0b1001010..TRIG_IN9 input is selected
 *  0b1001011..TRIG_IN10 input is selected
 *  0b1001100..TRIG_IN11 input is selected
 *  0b1001101..LPUART3 Received Data Word input is selected
 *  0b1001110..LPUART3 Transmitted Data Word input is selected
 *  0b1001111..LPUART3 Receive Line Idle input is selected
 *  0b1010000..LPUART4 Received Data Word input is selected
 *  0b1010001..LPUART4 Transmitted Data Word input is selected
 *  0b1010010..LPUART4 Receive Line Idle input is selected
 *  0b1010011..Reserved
 *  0b1010100..Reserved
 *  0b1010101..Reserved
 *  0b1010110..Reserved
 *  0b1010111..Reserved
 *  0b1011000..Reserved
 *  0b1011001..Reserved
 *  0b1011010..Reserved
 *  0b1011011..Reserved
 *  0b1011100..Reserved
 *  0b1011101..Reserved
 *  0b1011110..Reserved
 *  0b1011111..Reserved
 *  0b1100000..Reserved
 *  0b1100001..Reserved
 *  0b1100010..Reserved
 *  0b1100011..Reserved
 *  0b1100100..Reserved
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..Reserved
 *  0b1101010..Reserved
 *  0b1101011..Reserved
 *  0b1101100..Reserved
 *  0b1101101..Reserved
 *  0b1101110..Reserved
 *  0b1101111..Reserved
 *  0b1110000..Reserved
 */
#define INPUTMUX_CTIMER1TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER1TRIG_INP_SHIFT)) & INPUTMUX_CTIMER1TRIG_INP_MASK)
/*! @} */

/*! @name CTIMER2CAP - Capture select register for CTIMER2 inputs */
/*! @{ */

#define INPUTMUX_CTIMER2CAP_INP_MASK             (0x7FU)
#define INPUTMUX_CTIMER2CAP_INP_SHIFT            (0U)
/*! INP - Capture Inputs for CTIMER2
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..CT_INP4 input is selected
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..CT_INP7 input is selected
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..CT_INP10 input is selected
 *  0b0001100..CT_INP11 input is selected
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..CT_INP14 input is selected
 *  0b0010000..CT_INP15 input is selected
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0] input is selected
 *  0b0011011..ADC0_tcomp[1] input is selected
 *  0b0011100..ADC0_tcomp[2] input is selected
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT input is selected
 *  0b0011111..LPI2C2 Master End of Packet input is selected
 *  0b0100000..LPI2C2 Slave End of Packet input is selected
 *  0b0100001..CTimer0_MAT1 input is selected
 *  0b0100010..CTimer0_MAT2 input is selected
 *  0b0100011..CTimer0_MAT3 input is selected
 *  0b0100100..CTimer1_MAT1 input is selected
 *  0b0100101..CTimer1_MAT2 input is selected
 *  0b0100110..CTimer1_MAT3 input is selected
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..LPSPI1 End of Frame input is selected
 *  0b0110111..LPSPI1 Received Data Word input is selected
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..TRIG_IN0 input is selected
 *  0b1000010..TRIG_IN1 input is selected
 *  0b1000011..TRIG_IN2 input is selected
 *  0b1000100..TRIG_IN3 input is selected
 *  0b1000101..TRIG_IN4 input is selected
 *  0b1000110..TRIG_IN5 input is selected
 *  0b1000111..TRIG_IN6 input is selected
 *  0b1001000..TRIG_IN7 input is selected
 *  0b1001001..TRIG_IN8 input is selected
 *  0b1001010..TRIG_IN9 input is selected
 *  0b1001011..TRIG_IN10 input is selected
 *  0b1001100..TRIG_IN11 input is selected
 *  0b1001101..LPUART3 Received Data Word input is selected
 *  0b1001110..LPUART3 Transmitted Data Word input is selected
 *  0b1001111..LPUART3 Receive Line Idle input is selected
 *  0b1010000..LPUART4 Received Data Word input is selected
 *  0b1010001..LPUART4 Transmitted Data Word input is selected
 *  0b1010010..LPUART4 Receive Line Idle input is selected
 *  0b1010011..Reserved
 *  0b1010100..Reserved
 *  0b1010101..Reserved
 *  0b1010110..Reserved
 *  0b1010111..Reserved
 *  0b1011000..Reserved
 *  0b1011001..Reserved
 *  0b1011010..Reserved
 *  0b1011011..Reserved
 *  0b1011100..Reserved
 *  0b1011101..Reserved
 *  0b1011110..Reserved
 *  0b1011111..Reserved
 *  0b1100000..Reserved
 *  0b1100001..Reserved
 *  0b1100010..Reserved
 *  0b1100011..Reserved
 *  0b1100100..Reserved
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..Reserved
 *  0b1101010..Reserved
 *  0b1101011..Reserved
 *  0b1101100..Reserved
 *  0b1101101..Reserved
 *  0b1101110..Reserved
 *  0b1101111..Reserved
 *  0b1110000..Reserved
 */
#define INPUTMUX_CTIMER2CAP_INP(x)               (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER2CAP_INP_SHIFT)) & INPUTMUX_CTIMER2CAP_INP_MASK)
/*! @} */

/* The count of INPUTMUX_CTIMER2CAP */
#define INPUTMUX_CTIMER2CAP_COUNT                (4U)

/*! @name CTIMER2TRIG - Trigger register for CTIMER2 */
/*! @{ */

#define INPUTMUX_CTIMER2TRIG_INP_MASK            (0x7FU)
#define INPUTMUX_CTIMER2TRIG_INP_SHIFT           (0U)
/*! INP - Trigger Inputs for CTIMER2
 *  0b0000000..Reserved
 *  0b0000001..CT_INP0 input is selected
 *  0b0000010..CT_INP1 input is selected
 *  0b0000011..CT_INP2 input is selected
 *  0b0000100..CT_INP3 input is selected
 *  0b0000101..CT_INP4 input is selected
 *  0b0000110..CT_INP5 input is selected
 *  0b0000111..CT_INP6 input is selected
 *  0b0001000..CT_INP7 input is selected
 *  0b0001001..CT_INP8 input is selected
 *  0b0001010..CT_INP9 input is selected
 *  0b0001011..CT_INP10 input is selected
 *  0b0001100..CT_INP11 input is selected
 *  0b0001101..CT_INP12 input is selected
 *  0b0001110..CT_INP13 input is selected
 *  0b0001111..CT_INP14 input is selected
 *  0b0010000..CT_INP15 input is selected
 *  0b0010001..CT_INP16 input is selected
 *  0b0010010..CT_INP17 input is selected
 *  0b0010011..CT_INP18 input is selected
 *  0b0010100..CT_INP19 input is selected
 *  0b0010101..Reserved
 *  0b0010110..AOI0_OUT0 input is selected
 *  0b0010111..AOI0_OUT1 input is selected
 *  0b0011000..AOI0_OUT2 input is selected
 *  0b0011001..AOI0_OUT3 input is selected
 *  0b0011010..ADC0_tcomp[0] input is selected
 *  0b0011011..ADC0_tcomp[1] input is selected
 *  0b0011100..ADC0_tcomp[2] input is selected
 *  0b0011101..ADC0_tcomp[3] input is selected
 *  0b0011110..CMP0_OUT input is selected
 *  0b0011111..LPI2C2 Master End of Packet input is selected
 *  0b0100000..LPI2C2 Slave End of Packet input is selected
 *  0b0100001..CTimer0_MAT1 input is selected
 *  0b0100010..CTimer0_MAT2 input is selected
 *  0b0100011..CTimer0_MAT3 input is selected
 *  0b0100100..CTimer1_MAT1 input is selected
 *  0b0100101..CTimer1_MAT2 input is selected
 *  0b0100110..CTimer1_MAT3 input is selected
 *  0b0100111..Reserved
 *  0b0101000..Reserved
 *  0b0101001..Reserved
 *  0b0101010..Reserved
 *  0b0101011..Reserved
 *  0b0101100..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b0101101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b0101110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b0101111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b0110000..LPI2C0 Master End of Packet input is selected
 *  0b0110001..LPI2C0 Slave End of Packet input is selected
 *  0b0110010..LPI2C1 Master End of Packet input is selected
 *  0b0110011..LPI2C1 Slave End of Packet input is selected
 *  0b0110100..LPSPI0 End of Frame input is selected
 *  0b0110101..LPSPI0 Received Data Word input is selected
 *  0b0110110..LPSPI1 End of Frame input is selected
 *  0b0110111..LPSPI1 Received Data Word input is selected
 *  0b0111000..LPUART0 Received Data Word input is selected
 *  0b0111001..LPUART0 Transmitted Data Word input is selected
 *  0b0111010..LPUART0 Receive Line Idle input is selected
 *  0b0111011..LPUART1 Received Data Word input is selected
 *  0b0111100..LPUART1 Transmitted Data Word input is selected
 *  0b0111101..LPUART1 Receive Line Idle input is selected
 *  0b0111110..LPUART2 Received Data Word input is selected
 *  0b0111111..LPUART2 Transmitted Data Word input is selected
 *  0b1000000..LPUART2 Receive Line Idle input is selected
 *  0b1000001..TRIG_IN0 input is selected
 *  0b1000010..TRIG_IN1 input is selected
 *  0b1000011..TRIG_IN2 input is selected
 *  0b1000100..TRIG_IN3 input is selected
 *  0b1000101..TRIG_IN4 input is selected
 *  0b1000110..TRIG_IN5 input is selected
 *  0b1000111..TRIG_IN6 input is selected
 *  0b1001000..TRIG_IN7 input is selected
 *  0b1001001..TRIG_IN8 input is selected
 *  0b1001010..TRIG_IN9 input is selected
 *  0b1001011..TRIG_IN10 input is selected
 *  0b1001100..TRIG_IN11 input is selected
 *  0b1001101..LPUART3 Received Data Word input is selected
 *  0b1001110..LPUART3 Transmitted Data Word input is selected
 *  0b1001111..LPUART3 Receive Line Idle input is selected
 *  0b1010000..LPUART4 Received Data Word input is selected
 *  0b1010001..LPUART4 Transmitted Data Word input is selected
 *  0b1010010..LPUART4 Receive Line Idle input is selected
 *  0b1010011..Reserved
 *  0b1010100..Reserved
 *  0b1010101..Reserved
 *  0b1010110..Reserved
 *  0b1010111..Reserved
 *  0b1011000..Reserved
 *  0b1011001..Reserved
 *  0b1011010..Reserved
 *  0b1011011..Reserved
 *  0b1011100..Reserved
 *  0b1011101..Reserved
 *  0b1011110..Reserved
 *  0b1011111..Reserved
 *  0b1100000..Reserved
 *  0b1100001..Reserved
 *  0b1100010..Reserved
 *  0b1100011..Reserved
 *  0b1100100..Reserved
 *  0b1100101..Reserved
 *  0b1100110..Reserved
 *  0b1100111..Reserved
 *  0b1101000..Reserved
 *  0b1101001..Reserved
 *  0b1101010..Reserved
 *  0b1101011..Reserved
 *  0b1101100..Reserved
 *  0b1101101..Reserved
 *  0b1101110..Reserved
 *  0b1101111..Reserved
 *  0b1110000..Reserved
 */
#define INPUTMUX_CTIMER2TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_CTIMER2TRIG_INP_SHIFT)) & INPUTMUX_CTIMER2TRIG_INP_MASK)
/*! @} */

/*! @name FREQMEAS_REF - Selection for frequency measurement reference clock */
/*! @{ */

#define INPUTMUX_FREQMEAS_REF_INP_MASK           (0x3FU)
#define INPUTMUX_FREQMEAS_REF_INP_SHIFT          (0U)
/*! INP - Clock source number (binary value) for frequency measure function target clock.
 *  0b000000..Reserved
 *  0b000001..clk_in input is selected
 *  0b000010..FRO_OSC_12M input is selected
 *  0b000011..fro_hf_div input is selected
 *  0b000100..Osc32k[1] input is selected
 *  0b000101..clk_16k[1] input is selected
 *  0b000110..SLOW_CLK input is selected
 *  0b000111..FREQME_CLK_IN0 input is selected
 *  0b001000..FREQME_CLK_IN1 input is selected
 *  0b001001..AOI0_OUT0 input is selected
 *  0b001010..AOI0_OUT1 input is selected
 *  0b001011..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b001100..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b001101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b001110..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b001111..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b010000..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b010001..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b010010..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b010011..CLK__iomux__IPP__scg__ipp_do_scg_clkout input is selected
 *  0b010100..Reserved
 *  0b010101..spc_pmc_bg_refresh_1p8v input is selected
 *  0b010110..Reserved
 *  0b010111..spc_pmc_timer_clk_1p8v input is selected
 *  0b011000..spc_pmc_tst_obs_bit_sfa_1p8v input is selected
 *  0b011001..spc_pmc_tst_obs_bit_sfa_1p8v[1] ^ spc_pmc_coreldo_tstctrl_testdelayin_sf input is selected
 *  0b011010..Reserved
 *  0b011011..Reserved
 *  0b011100..VBAT OSC32K test trigger input is selected
 *  0b011101..VBAT OSC32K test clock input is selected
 *  0b011110..Reserved
 *  0b011111..Reserved
 *  0b100000..Reserved
 *  0b100001..Reserved
 *  0b100010..Reserved
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..TSI: clkmain_lv input is selected
 *  0b101111..TSI: clksw_lv input is selected
 *  0b110000..TSI: intg_done_lv input is selected
 *  0b110001..TSI: intg_reset_lv input is selected
 */
#define INPUTMUX_FREQMEAS_REF_INP(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FREQMEAS_REF_INP_SHIFT)) & INPUTMUX_FREQMEAS_REF_INP_MASK)
/*! @} */

/*! @name FREQMEAS_TAR - Selection for frequency measurement target clock */
/*! @{ */

#define INPUTMUX_FREQMEAS_TAR_INP_MASK           (0x3FU)
#define INPUTMUX_FREQMEAS_TAR_INP_SHIFT          (0U)
/*! INP - Clock source number (binary value) for frequency measure function target clock.
 *  0b000000..Reserved
 *  0b000001..clk_in input is selected
 *  0b000010..FRO_OSC_12M input is selected
 *  0b000011..fro_hf_div input is selected
 *  0b000100..Osc32k[1] input is selected
 *  0b000101..clk_16k[1] input is selected
 *  0b000110..SLOW_CLK input is selected
 *  0b000111..FREQME_CLK_IN0 input is selected
 *  0b001000..FREQME_CLK_IN1 input is selected
 *  0b001001..AOI0_OUT0 input is selected
 *  0b001010..AOI0_OUT1 input is selected
 *  0b001011..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b001100..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b001101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b001110..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b001111..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b010000..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b010001..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b010010..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b010011..CLK__iomux__IPP__scg__ipp_do_scg_clkout input is selected
 *  0b010100..Reserved
 *  0b010101..spc_pmc_bg_refresh_1p8v input is selected
 *  0b010110..Reserved
 *  0b010111..spc_pmc_timer_clk_1p8v input is selected
 *  0b011000..spc_pmc_tst_obs_bit_sfa_1p8v input is selected
 *  0b011001..spc_pmc_tst_obs_bit_sfa_1p8v[1] ^ spc_pmc_coreldo_tstctrl_testdelayin_sf input is selected
 *  0b011010..Reserved
 *  0b011011..Reserved
 *  0b011100..VBAT OSC32K test trigger input is selected
 *  0b011101..VBAT OSC32K test clock input is selected
 *  0b011110..Reserved
 *  0b011111..Reserved
 *  0b100000..Reserved
 *  0b100001..Reserved
 *  0b100010..Reserved
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..TSI: clkmain_lv input is selected
 *  0b101111..TSI: clksw_lv input is selected
 *  0b110000..TSI: intg_done_lv input is selected
 *  0b110001..TSI: intg_reset_lv input is selected
 */
#define INPUTMUX_FREQMEAS_TAR_INP(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FREQMEAS_TAR_INP_SHIFT)) & INPUTMUX_FREQMEAS_TAR_INP_MASK)
/*! @} */

/*! @name LPCMP0_TRIG - LPCMP0 trigger input connections */
/*! @{ */

#define INPUTMUX_LPCMP0_TRIG_TRIGIN_MASK         (0x1FU)
#define INPUTMUX_LPCMP0_TRIG_TRIGIN_SHIFT        (0U)
/*! TRIGIN - LPCMP0 trigger inputs
 *  0b00000..Reserved
 *  0b00001..Reserved
 *  0b00010..AOI0_OUT0 input is selected
 *  0b00011..AOI0_OUT1 input is selected
 *  0b00100..AOI0_OUT2 input is selected
 *  0b00101..AOI0_OUT3 input is selected
 *  0b00110..Reserved
 *  0b00111..Reserved
 *  0b01000..CTimer0_MAT0 input is selected
 *  0b01001..CTimer0_MAT2 input is selected
 *  0b01010..CTimer1_MAT0 input is selected
 *  0b01011..CTimer1_MAT2 input is selected
 *  0b01100..CTimer2_MAT0 input is selected
 *  0b01101..CTimer2_MAT2 input is selected
 *  0b01110..LPTMR0 input is selected
 *  0b01111..Reserved
 *  0b10000..Reserved
 *  0b10001..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b10010..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b10011..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b10100..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b10101..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b10110..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b10111..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b11000..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b11001..GPIO0 Pin Event Trig 0 input is selected
 *  0b11010..GPIO1 Pin Event Trig 0 input is selected
 *  0b11011..GPIO2 Pin Event Trig 0 input is selected
 *  0b11100..GPIO3 Pin Event Trig 0 input is selected
 *  0b11101..Reserved
 *  0b11110..WUU input is selected
 */
#define INPUTMUX_LPCMP0_TRIG_TRIGIN(x)           (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPCMP0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_LPCMP0_TRIG_TRIGIN_MASK)
/*! @} */

/*! @name ADC0_TRIG - ADC trigger input connections */
/*! @{ */

#define INPUTMUX_ADC0_TRIG_TRIGIN_MASK           (0x1FU)
#define INPUTMUX_ADC0_TRIG_TRIGIN_SHIFT          (0U)
/*! TRIGIN - ADC0 trigger inputs
 *  0b00000..Reserved
 *  0b00001..ARM_TXEV input is selected
 *  0b00010..AOI0_OUT0 input is selected
 *  0b00011..AOI0_OUT1 input is selected
 *  0b00100..AOI0_OUT2 input is selected
 *  0b00101..AOI0_OUT3 input is selected
 *  0b00110..CMP0_OUT input is selected
 *  0b00111..Reserved
 *  0b01000..Reserved
 *  0b01001..CTimer0_MAT0 input is selected
 *  0b01010..CTimer0_MAT1 input is selected
 *  0b01011..CTimer1_MAT0 input is selected
 *  0b01100..CTimer1_MAT1 input is selected
 *  0b01101..CTimer2_MAT0 input is selected
 *  0b01110..CTimer2_MAT1 input is selected
 *  0b01111..LPTMR0 input is selected
 *  0b10000..Reserved
 *  0b10001..Reserved
 *  0b10010..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b10011..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b10100..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b10101..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b10110..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b10111..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b11000..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b11001..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b11010..GPIO0 Pin Event Trig 0 input is selected
 *  0b11011..GPIO1 Pin Event Trig 0 input is selected
 *  0b11100..GPIO2 Pin Event Trig 0 input is selected
 *  0b11101..GPIO3 Pin Event Trig 0 input is selected
 *  0b11110..Reserved
 *  0b11111..WUU input is selected
 */
#define INPUTMUX_ADC0_TRIG_TRIGIN(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_ADC0_TRIG_TRIGIN_SHIFT)) & INPUTMUX_ADC0_TRIG_TRIGIN_MASK)
/*! @} */

/* The count of INPUTMUX_ADC0_TRIG */
#define INPUTMUX_ADC0_TRIG_COUNT                 (4U)

/*! @name FLEXPWM0_SM0_EXTA0 - FlexPWM0_SM0_EXTA0 trigger input connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM0_EXTA0_TRIGIN_MASK  (0x3FU)
#define INPUTMUX_FLEXPWM0_SM0_EXTA0_TRIGIN_SHIFT (0U)
/*! TRIGIN - Trigger input connections for FlexPWM0_SM0_EXTA0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 */
#define INPUTMUX_FLEXPWM0_SM0_EXTA0_TRIGIN(x)    (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM0_EXTA0_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM0_EXTA0_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM0_EXTSYNC - FlexPWM0_SM0_EXTSYNC trigger input connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM0_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM0_SM0_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - Trigger input connections for FlexPWM0_SM0_EXTSYNC
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 */
#define INPUTMUX_FLEXPWM0_SM0_EXTSYNC_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM0_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM0_EXTSYNC_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM1_EXTA - FlexPWM0_SM1_EXTA trigger input connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM1_EXTA_TRIGIN_MASK   (0x3FU)
#define INPUTMUX_FLEXPWM0_SM1_EXTA_TRIGIN_SHIFT  (0U)
/*! TRIGIN - Trigger input connections for FlexPWM0_SM1_EXTA
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 */
#define INPUTMUX_FLEXPWM0_SM1_EXTA_TRIGIN(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM1_EXTA_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM1_EXTA_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM1_EXTSYNC - FlexPWM0_SM1_EXTSYNC trigger input connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM1_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM0_SM1_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - Trigger input connections for FlexPWM0_SM1_EXTSYNC
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 */
#define INPUTMUX_FLEXPWM0_SM1_EXTSYNC_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM1_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM1_EXTSYNC_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM2_EXTA - FlexPWM0_SM2_EXTA trigger input connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM2_EXTA_TRIGIN_MASK   (0x3FU)
#define INPUTMUX_FLEXPWM0_SM2_EXTA_TRIGIN_SHIFT  (0U)
/*! TRIGIN - Trigger input connections for FlexPWM0_SM2_EXTA
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 */
#define INPUTMUX_FLEXPWM0_SM2_EXTA_TRIGIN(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM2_EXTA_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM2_EXTA_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM2_EXTSYNC - FlexPWM0_SM2_EXTSYNC trigger input connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM2_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM0_SM2_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - Trigger input connections for FlexPWM0_SM2_EXTSYNC
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 */
#define INPUTMUX_FLEXPWM0_SM2_EXTSYNC_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM2_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM2_EXTSYNC_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM3_EXTA - FlexPWM0_SM3_EXTA trigger input connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM3_EXTA_TRIGIN_MASK   (0x3FU)
#define INPUTMUX_FLEXPWM0_SM3_EXTA_TRIGIN_SHIFT  (0U)
/*! TRIGIN - Trigger input connections for FlexPWM0_SM3_EXTA
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 */
#define INPUTMUX_FLEXPWM0_SM3_EXTA_TRIGIN(x)     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM3_EXTA_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM3_EXTA_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_SM3_EXTSYNC - FlexPWM0_SM3_EXTSYNC trigger input connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_SM3_EXTSYNC_TRIGIN_MASK (0x3FU)
#define INPUTMUX_FLEXPWM0_SM3_EXTSYNC_TRIGIN_SHIFT (0U)
/*! TRIGIN - Trigger input connections for FlexPWM0_SM3_EXTSYNC
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 */
#define INPUTMUX_FLEXPWM0_SM3_EXTSYNC_TRIGIN(x)  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_SM3_EXTSYNC_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_SM3_EXTSYNC_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_FAULT0 - FlexPWM0_FAULT0 trigger input connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_FAULT0_TRIGIN_MASK     (0x3FU)
#define INPUTMUX_FLEXPWM0_FAULT0_TRIGIN_SHIFT    (0U)
/*! TRIGIN - Trigger input connections for FlexPWM0_FAULT0
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 */
#define INPUTMUX_FLEXPWM0_FAULT0_TRIGIN(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_FAULT0_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_FAULT0_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_FAULT1 - FlexPWM0_FAULT1 trigger input connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_FAULT1_TRIGIN_MASK     (0x3FU)
#define INPUTMUX_FLEXPWM0_FAULT1_TRIGIN_SHIFT    (0U)
/*! TRIGIN - Trigger input connections for FlexPWM0_FAULT1
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 */
#define INPUTMUX_FLEXPWM0_FAULT1_TRIGIN(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_FAULT1_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_FAULT1_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_FAULT2 - FlexPWM0_FAULT2 trigger input connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_FAULT2_TRIGIN_MASK     (0x3FU)
#define INPUTMUX_FLEXPWM0_FAULT2_TRIGIN_SHIFT    (0U)
/*! TRIGIN - Trigger input connections for FlexPWM0_FAULT2
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 */
#define INPUTMUX_FLEXPWM0_FAULT2_TRIGIN(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_FAULT2_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_FAULT2_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_FAULT3 - FlexPWM0_FAULT3 trigger input connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_FAULT3_TRIGIN_MASK     (0x3FU)
#define INPUTMUX_FLEXPWM0_FAULT3_TRIGIN_SHIFT    (0U)
/*! TRIGIN - Trigger input connections for FlexPWM0_FAULT3
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 */
#define INPUTMUX_FLEXPWM0_FAULT3_TRIGIN(x)       (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_FAULT3_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_FAULT3_TRIGIN_MASK)
/*! @} */

/*! @name FLEXPWM0_FORCE - FlexPWM0_FORCE trigger input connections */
/*! @{ */

#define INPUTMUX_FLEXPWM0_FORCE_TRIGIN_MASK      (0x3FU)
#define INPUTMUX_FLEXPWM0_FORCE_TRIGIN_SHIFT     (0U)
/*! TRIGIN - Trigger input connections for FlexPWM0_FORCE
 *  0b000000..Reserved
 *  0b000001..ARM_TXEV input is selected
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..Reserved
 *  0b010000..Reserved
 *  0b010001..Reserved
 *  0b010010..Reserved
 *  0b010011..Reserved
 *  0b010100..TRIG_IN0 input is selected
 *  0b010101..TRIG_IN1 input is selected
 *  0b010110..TRIG_IN2 input is selected
 *  0b010111..TRIG_IN3 input is selected
 *  0b011000..TRIG_IN4 input is selected
 *  0b011001..TRIG_IN5 input is selected
 *  0b011010..TRIG_IN6 input is selected
 *  0b011011..TRIG_IN7 input is selected
 *  0b011100..TRIG_IN8 input is selected
 *  0b011101..TRIG_IN9 input is selected
 *  0b011110..TRIG_IN10 input is selected
 *  0b011111..TRIG_IN11 input is selected
 *  0b100000..GPIO0 Pin Event Trig 0 input is selected
 *  0b100001..GPIO1 Pin Event Trig 0 input is selected
 *  0b100010..GPIO2 Pin Event Trig 0 input is selected
 *  0b100011..GPIO3 Pin Event Trig 0 input is selected
 *  0b100100..Reserved
 *  0b100101..ECC Error Interrupt input is selected
 *  0b100110..WWDT0/1 Interrupt input is selected
 */
#define INPUTMUX_FLEXPWM0_FORCE_TRIGIN(x)        (((uint32_t)(((uint32_t)(x)) << INPUTMUX_FLEXPWM0_FORCE_TRIGIN_SHIFT)) & INPUTMUX_FLEXPWM0_FORCE_TRIGIN_MASK)
/*! @} */

/*! @name PWM0_EXT_CLK - eFlexPWM0 external clock trigger */
/*! @{ */

#define INPUTMUX_PWM0_EXT_CLK_INP_MASK           (0xFU)
#define INPUTMUX_PWM0_EXT_CLK_INP_SHIFT          (0U)
/*! INP - Input Trigger Connection for eFlexPWM0 EXT_CLK
 *  0b0000..Reserved
 *  0b0001..clk_16k[1] input is selected
 *  0b0010..clk_in input is selected
 *  0b0011..AOI0_OUT0 input is selected
 *  0b0100..AOI0_OUT1 input is selected
 *  0b0101..TRIG_IN0 input is selected
 *  0b0110..TRIG_IN7 input is selected
 *  0b0111..Reserved
 *  0b1000..Reserved
 */
#define INPUTMUX_PWM0_EXT_CLK_INP(x)             (((uint32_t)(((uint32_t)(x)) << INPUTMUX_PWM0_EXT_CLK_INP_SHIFT)) & INPUTMUX_PWM0_EXT_CLK_INP_MASK)
/*! @} */

/*! @name AOI0INPUT - AOI0 trigger input connections */
/*! @{ */

#define INPUTMUX_AOI0INPUT_INP_MASK              (0x3FU)
#define INPUTMUX_AOI0INPUT_INP_SHIFT             (0U)
/*! INP - AOI0 trigger input connections
 *  0b000000..Reserved
 *  0b000001..ADC0_tcomp[0] input is selected
 *  0b000010..ADC0_tcomp[1] input is selected
 *  0b000011..ADC0_tcomp[2] input is selected
 *  0b000100..ADC0_tcomp[3] input is selected
 *  0b000101..CMP0_OUT input is selected
 *  0b000110..Reserved
 *  0b000111..Reserved
 *  0b001000..CTimer0_MAT0 input is selected
 *  0b001001..CTimer0_MAT1 input is selected
 *  0b001010..CTimer0_MAT2 input is selected
 *  0b001011..CTimer0_MAT3 input is selected
 *  0b001100..CTimer1_MAT0 input is selected
 *  0b001101..CTimer1_MAT1 input is selected
 *  0b001110..CTimer1_MAT2 input is selected
 *  0b001111..CTimer1_MAT3 input is selected
 *  0b010000..CTimer2_MAT0 input is selected
 *  0b010001..CTimer2_MAT1 input is selected
 *  0b010010..CTimer2_MAT2 input is selected
 *  0b010011..CTimer2_MAT3 input is selected
 *  0b010100..LPTMR0 input is selected
 *  0b010101..Reserved
 *  0b010110..Reserved
 *  0b010111..Reserved
 *  0b011000..Reserved
 *  0b011001..Reserved
 *  0b011010..Reserved
 *  0b011011..PWM0_SM0_MUX_TRIG0 input is selected
 *  0b011100..PWM0_SM0_MUX_TRIG1 input is selected
 *  0b011101..PWM0_SM1_MUX_TRIG0 input is selected
 *  0b011110..PWM0_SM1_MUX_TRIG1 input is selected
 *  0b011111..PWM0_SM2_MUX_TRIG0 input is selected
 *  0b100000..PWM0_SM2_MUX_TRIG1 input is selected
 *  0b100001..PWM0_SM3_MUX_TRIG0 input is selected
 *  0b100010..PWM0_SM3_MUX_TRIG1 input is selected
 *  0b100011..TRIG_IN0 input is selected
 *  0b100100..TRIG_IN1 input is selected
 *  0b100101..TRIG_IN2 input is selected
 *  0b100110..TRIG_IN3 input is selected
 *  0b100111..TRIG_IN4 input is selected
 *  0b101000..TRIG_IN5 input is selected
 *  0b101001..TRIG_IN6 input is selected
 *  0b101010..TRIG_IN7 input is selected
 *  0b101011..TRIG_IN8 input is selected
 *  0b101100..TRIG_IN9 input is selected
 *  0b101101..TRIG_IN10 input is selected
 *  0b101110..TRIG_IN11 input is selected
 *  0b101111..GPIO0 Pin Event Trig 0 input is selected
 *  0b110000..GPIO1 Pin Event Trig 0 input is selected
 *  0b110001..GPIO2 Pin Event Trig 0 input is selected
 *  0b110010..GPIO3 Pin Event Trig 0 input is selected
 */
#define INPUTMUX_AOI0INPUT_INP(x)                (((uint32_t)(((uint32_t)(x)) << INPUTMUX_AOI0INPUT_INP_SHIFT)) & INPUTMUX_AOI0INPUT_INP_MASK)
/*! @} */

/* The count of INPUTMUX_AOI0INPUT */
#define INPUTMUX_AOI0INPUT_COUNT                 (16U)

/*! @name TSI0 - TSI0 trigger input connections */
/*! @{ */

#define INPUTMUX_TSI0_INP_MASK                   (0xFU)
#define INPUTMUX_TSI0_INP_SHIFT                  (0U)
/*! INP - TSI0 trigger input connections
 *  0b0000..Reserved
 *  0b0001..CTimer0_MAT2 input is selected
 *  0b0010..CTimer0_MAT3 input is selected
 *  0b0011..CTimer1_MAT2 input is selected
 *  0b0100..CTimer1_MAT3 input is selected
 *  0b0101..CTimer2_MAT2 input is selected
 *  0b0110..CTimer2_MAT3 input is selected
 *  0b0111..Reserved
 *  0b1000..Reserved
 *  0b1001..Reserved
 *  0b1010..Reserved
 *  0b1011..LPTMR0 input is selected
 *  0b1100..WUU input is selected
 */
#define INPUTMUX_TSI0_INP(x)                     (((uint32_t)(((uint32_t)(x)) << INPUTMUX_TSI0_INP_SHIFT)) & INPUTMUX_TSI0_INP_MASK)
/*! @} */

/*! @name EXT_TRIG - EXT trigger connections 0-7 */
/*! @{ */

#define INPUTMUX_EXT_TRIG_INP_MASK               (0x1FU)
#define INPUTMUX_EXT_TRIG_INP_SHIFT              (0U)
/*! INP - EXT trigger input connections
 *  0b00000..Reserved
 *  0b00001..Reserved
 *  0b00010..AOI0_OUT0 input is selected
 *  0b00011..AOI0_OUT1 input is selected
 *  0b00100..AOI0_OUT2 input is selected
 *  0b00101..AOI0_OUT3 input is selected
 *  0b00110..CMP0_OUT input is selected
 *  0b00111..Reserved
 *  0b01000..Reserved
 *  0b01001..LPUART0 ipp_do_lpuart_txd input is selected
 *  0b01010..LPUART1 ipp_do_lpuart_txd input is selected
 *  0b01011..LPUART2 ipp_do_lpuart_txd input is selected
 *  0b01100..LPUART3 ipp_do_lpuart_txd input is selected
 *  0b01101..LPUART4 ipp_do_lpuart_txd input is selected
 *  0b01110..Reserved
 *  0b01111..Reserved
 *  0b10000..Reserved
 *  0b10001..Reserved
 *  0b10010..Reserved
 *  0b10011..RTC_1Hz_CLK input is selected
 *  0b10100..Reserved
 */
#define INPUTMUX_EXT_TRIG_INP(x)                 (((uint32_t)(((uint32_t)(x)) << INPUTMUX_EXT_TRIG_INP_SHIFT)) & INPUTMUX_EXT_TRIG_INP_MASK)
/*! @} */

/* The count of INPUTMUX_EXT_TRIG */
#define INPUTMUX_EXT_TRIG_COUNT                  (8U)

/*! @name LPI2C2_TRIG - LPI2C2 trigger input connections */
/*! @{ */

#define INPUTMUX_LPI2C2_TRIG_INP_MASK            (0x1FU)
#define INPUTMUX_LPI2C2_TRIG_INP_SHIFT           (0U)
/*! INP - LPI2C2 trigger input connections
 *  0b00000..Reserved
 *  0b00001..Reserved
 *  0b00010..AOI0_OUT0 input is selected
 *  0b00011..AOI0_OUT1 input is selected
 *  0b00100..AOI0_OUT2 input is selected
 *  0b00101..AOI0_OUT3 input is selected
 *  0b00110..CMP0_OUT input is selected
 *  0b00111..Reserved
 *  0b01000..Reserved
 *  0b01001..CTimer0_MAT0 input is selected
 *  0b01010..CTimer0_MAT1 input is selected
 *  0b01011..CTimer1_MAT0 input is selected
 *  0b01100..CTimer1_MAT1 input is selected
 *  0b01101..CTimer2_MAT0 input is selected
 *  0b01110..CTimer2_MAT1 input is selected
 *  0b01111..LPTMR0 input is selected
 *  0b10000..Reserved
 *  0b10001..TRIG_IN0 input is selected
 *  0b10010..TRIG_IN1 input is selected
 *  0b10011..TRIG_IN2 input is selected
 *  0b10100..TRIG_IN3 input is selected
 *  0b10101..TRIG_IN4 input is selected
 *  0b10110..TRIG_IN5 input is selected
 *  0b10111..TRIG_IN6 input is selected
 *  0b11000..TRIG_IN7 input is selected
 *  0b11001..GPIO0 Pin Event Trig 0 input is selected
 *  0b11010..GPIO1 Pin Event Trig 0 input is selected
 *  0b11011..GPIO2 Pin Event Trig 0 input is selected
 *  0b11100..GPIO3 Pin Event Trig 0 input is selected
 *  0b11101..Reserved
 *  0b11110..WUU input is selected
 */
#define INPUTMUX_LPI2C2_TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPI2C2_TRIG_INP_SHIFT)) & INPUTMUX_LPI2C2_TRIG_INP_MASK)
/*! @} */

/*! @name LPI2C0_TRIG - LPI2C0 trigger input connections */
/*! @{ */

#define INPUTMUX_LPI2C0_TRIG_INP_MASK            (0x1FU)
#define INPUTMUX_LPI2C0_TRIG_INP_SHIFT           (0U)
/*! INP - LPI2C0 trigger input connections
 *  0b00000..Reserved
 *  0b00001..Reserved
 *  0b00010..AOI0_OUT0 input is selected
 *  0b00011..AOI0_OUT1 input is selected
 *  0b00100..AOI0_OUT2 input is selected
 *  0b00101..AOI0_OUT3 input is selected
 *  0b00110..CMP0_OUT input is selected
 *  0b00111..Reserved
 *  0b01000..Reserved
 *  0b01001..CTimer0_MAT0 input is selected
 *  0b01010..CTimer0_MAT1 input is selected
 *  0b01011..CTimer1_MAT0 input is selected
 *  0b01100..CTimer1_MAT1 input is selected
 *  0b01101..CTimer2_MAT0 input is selected
 *  0b01110..CTimer2_MAT1 input is selected
 *  0b01111..LPTMR0 input is selected
 *  0b10000..Reserved
 *  0b10001..TRIG_IN0 input is selected
 *  0b10010..TRIG_IN1 input is selected
 *  0b10011..TRIG_IN2 input is selected
 *  0b10100..TRIG_IN3 input is selected
 *  0b10101..TRIG_IN4 input is selected
 *  0b10110..TRIG_IN5 input is selected
 *  0b10111..TRIG_IN6 input is selected
 *  0b11000..TRIG_IN7 input is selected
 *  0b11001..GPIO0 Pin Event Trig 0 input is selected
 *  0b11010..GPIO1 Pin Event Trig 0 input is selected
 *  0b11011..GPIO2 Pin Event Trig 0 input is selected
 *  0b11100..GPIO3 Pin Event Trig 0 input is selected
 *  0b11101..Reserved
 *  0b11110..WUU input is selected
 */
#define INPUTMUX_LPI2C0_TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPI2C0_TRIG_INP_SHIFT)) & INPUTMUX_LPI2C0_TRIG_INP_MASK)
/*! @} */

/*! @name LPI2C1_TRIG - LPI2C1 trigger input connections */
/*! @{ */

#define INPUTMUX_LPI2C1_TRIG_INP_MASK            (0x1FU)
#define INPUTMUX_LPI2C1_TRIG_INP_SHIFT           (0U)
/*! INP - LPI2C1 trigger input connections
 *  0b00000..Reserved
 *  0b00001..Reserved
 *  0b00010..AOI0_OUT0 input is selected
 *  0b00011..AOI0_OUT1 input is selected
 *  0b00100..AOI0_OUT2 input is selected
 *  0b00101..AOI0_OUT3 input is selected
 *  0b00110..CMP0_OUT input is selected
 *  0b00111..Reserved
 *  0b01000..Reserved
 *  0b01001..CTimer0_MAT0 input is selected
 *  0b01010..CTimer0_MAT1 input is selected
 *  0b01011..CTimer1_MAT0 input is selected
 *  0b01100..CTimer1_MAT1 input is selected
 *  0b01101..CTimer2_MAT0 input is selected
 *  0b01110..CTimer2_MAT1 input is selected
 *  0b01111..LPTMR0 input is selected
 *  0b10000..Reserved
 *  0b10001..TRIG_IN0 input is selected
 *  0b10010..TRIG_IN1 input is selected
 *  0b10011..TRIG_IN2 input is selected
 *  0b10100..TRIG_IN3 input is selected
 *  0b10101..TRIG_IN4 input is selected
 *  0b10110..TRIG_IN5 input is selected
 *  0b10111..TRIG_IN6 input is selected
 *  0b11000..TRIG_IN7 input is selected
 *  0b11001..GPIO0 Pin Event Trig 0 input is selected
 *  0b11010..GPIO1 Pin Event Trig 0 input is selected
 *  0b11011..GPIO2 Pin Event Trig 0 input is selected
 *  0b11100..GPIO3 Pin Event Trig 0 input is selected
 *  0b11101..Reserved
 *  0b11110..WUU input is selected
 */
#define INPUTMUX_LPI2C1_TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPI2C1_TRIG_INP_SHIFT)) & INPUTMUX_LPI2C1_TRIG_INP_MASK)
/*! @} */

/*! @name LPSPI0_TRIG - LPSPI0 trigger input connections */
/*! @{ */

#define INPUTMUX_LPSPI0_TRIG_INP_MASK            (0x1FU)
#define INPUTMUX_LPSPI0_TRIG_INP_SHIFT           (0U)
/*! INP - LPSPI0 trigger input connections
 *  0b00000..Reserved
 *  0b00001..Reserved
 *  0b00010..AOI0_OUT0 input is selected
 *  0b00011..AOI0_OUT1 input is selected
 *  0b00100..AOI0_OUT2 input is selected
 *  0b00101..AOI0_OUT3 input is selected
 *  0b00110..CMP0_OUT input is selected
 *  0b00111..Reserved
 *  0b01000..Reserved
 *  0b01001..CTimer0_MAT1 input is selected
 *  0b01010..CTimer0_MAT2 input is selected
 *  0b01011..CTimer1_MAT1 input is selected
 *  0b01100..CTimer1_MAT2 input is selected
 *  0b01101..CTimer2_MAT1 input is selected
 *  0b01110..CTimer2_MAT2 input is selected
 *  0b01111..LPTMR0 input is selected
 *  0b10000..Reserved
 *  0b10001..TRIG_IN0 input is selected
 *  0b10010..TRIG_IN1 input is selected
 *  0b10011..TRIG_IN2 input is selected
 *  0b10100..TRIG_IN3 input is selected
 *  0b10101..TRIG_IN4 input is selected
 *  0b10110..TRIG_IN5 input is selected
 *  0b10111..TRIG_IN6 input is selected
 *  0b11000..TRIG_IN7 input is selected
 *  0b11001..GPIO0 Pin Event Trig 0 input is selected
 *  0b11010..GPIO1 Pin Event Trig 0 input is selected
 *  0b11011..GPIO2 Pin Event Trig 0 input is selected
 *  0b11100..GPIO3 Pin Event Trig 0 input is selected
 *  0b11101..Reserved
 *  0b11110..WUU input is selected
 */
#define INPUTMUX_LPSPI0_TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPSPI0_TRIG_INP_SHIFT)) & INPUTMUX_LPSPI0_TRIG_INP_MASK)
/*! @} */

/*! @name LPSPI1_TRIG - LPSPI1 trigger input connections */
/*! @{ */

#define INPUTMUX_LPSPI1_TRIG_INP_MASK            (0x1FU)
#define INPUTMUX_LPSPI1_TRIG_INP_SHIFT           (0U)
/*! INP - LPSPI1 trigger input connections
 *  0b00000..Reserved
 *  0b00001..Reserved
 *  0b00010..AOI0_OUT0 input is selected
 *  0b00011..AOI0_OUT1 input is selected
 *  0b00100..AOI0_OUT2 input is selected
 *  0b00101..AOI0_OUT3 input is selected
 *  0b00110..CMP0_OUT input is selected
 *  0b00111..Reserved
 *  0b01000..Reserved
 *  0b01001..CTimer0_MAT1 input is selected
 *  0b01010..CTimer0_MAT2 input is selected
 *  0b01011..CTimer1_MAT1 input is selected
 *  0b01100..CTimer1_MAT2 input is selected
 *  0b01101..CTimer2_MAT1 input is selected
 *  0b01110..CTimer2_MAT2 input is selected
 *  0b01111..LPTMR0 input is selected
 *  0b10000..Reserved
 *  0b10001..TRIG_IN0 input is selected
 *  0b10010..TRIG_IN1 input is selected
 *  0b10011..TRIG_IN2 input is selected
 *  0b10100..TRIG_IN3 input is selected
 *  0b10101..TRIG_IN4 input is selected
 *  0b10110..TRIG_IN5 input is selected
 *  0b10111..TRIG_IN6 input is selected
 *  0b11000..TRIG_IN7 input is selected
 *  0b11001..GPIO0 Pin Event Trig 0 input is selected
 *  0b11010..GPIO1 Pin Event Trig 0 input is selected
 *  0b11011..GPIO2 Pin Event Trig 0 input is selected
 *  0b11100..GPIO3 Pin Event Trig 0 input is selected
 *  0b11101..Reserved
 *  0b11110..WUU input is selected
 */
#define INPUTMUX_LPSPI1_TRIG_INP(x)              (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPSPI1_TRIG_INP_SHIFT)) & INPUTMUX_LPSPI1_TRIG_INP_MASK)
/*! @} */

/*! @name LPUART0 - LPUART0 trigger input connections */
/*! @{ */

#define INPUTMUX_LPUART0_INP_MASK                (0x3FU)
#define INPUTMUX_LPUART0_INP_SHIFT               (0U)
/*! INP - LPUART0 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..LPTMR0 input is selected
 *  0b010000..Reserved
 *  0b010001..TRIG_IN0 input is selected
 *  0b010010..TRIG_IN1 input is selected
 *  0b010011..TRIG_IN2 input is selected
 *  0b010100..TRIG_IN3 input is selected
 *  0b010101..TRIG_IN4 input is selected
 *  0b010110..TRIG_IN5 input is selected
 *  0b010111..TRIG_IN6 input is selected
 *  0b011000..TRIG_IN7 input is selected
 *  0b011001..TRIG_IN8 input is selected
 *  0b011010..TRIG_IN9 input is selected
 *  0b011011..TRIG_IN10 input is selected
 *  0b011100..TRIG_IN11 input is selected
 *  0b011101..GPIO0 Pin Event Trig 0 input is selected
 *  0b011110..GPIO1 Pin Event Trig 0 input is selected
 *  0b011111..GPIO2 Pin Event Trig 0 input is selected
 *  0b100000..GPIO3 Pin Event Trig 0 input is selected
 *  0b100001..Reserved
 *  0b100010..WUU input is selected
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 */
#define INPUTMUX_LPUART0_INP(x)                  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPUART0_INP_SHIFT)) & INPUTMUX_LPUART0_INP_MASK)
/*! @} */

/*! @name LPUART1 - LPUART1 trigger input connections */
/*! @{ */

#define INPUTMUX_LPUART1_INP_MASK                (0x3FU)
#define INPUTMUX_LPUART1_INP_SHIFT               (0U)
/*! INP - LPUART1 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..LPTMR0 input is selected
 *  0b010000..Reserved
 *  0b010001..TRIG_IN0 input is selected
 *  0b010010..TRIG_IN1 input is selected
 *  0b010011..TRIG_IN2 input is selected
 *  0b010100..TRIG_IN3 input is selected
 *  0b010101..TRIG_IN4 input is selected
 *  0b010110..TRIG_IN5 input is selected
 *  0b010111..TRIG_IN6 input is selected
 *  0b011000..TRIG_IN7 input is selected
 *  0b011001..TRIG_IN8 input is selected
 *  0b011010..TRIG_IN9 input is selected
 *  0b011011..TRIG_IN10 input is selected
 *  0b011100..TRIG_IN11 input is selected
 *  0b011101..GPIO0 Pin Event Trig 0 input is selected
 *  0b011110..GPIO1 Pin Event Trig 0 input is selected
 *  0b011111..GPIO2 Pin Event Trig 0 input is selected
 *  0b100000..GPIO3 Pin Event Trig 0 input is selected
 *  0b100001..Reserved
 *  0b100010..WUU input is selected
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 */
#define INPUTMUX_LPUART1_INP(x)                  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPUART1_INP_SHIFT)) & INPUTMUX_LPUART1_INP_MASK)
/*! @} */

/*! @name LPUART2 - LPUART2 trigger input connections */
/*! @{ */

#define INPUTMUX_LPUART2_INP_MASK                (0x3FU)
#define INPUTMUX_LPUART2_INP_SHIFT               (0U)
/*! INP - LPUART2 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..LPTMR0 input is selected
 *  0b010000..Reserved
 *  0b010001..TRIG_IN0 input is selected
 *  0b010010..TRIG_IN1 input is selected
 *  0b010011..TRIG_IN2 input is selected
 *  0b010100..TRIG_IN3 input is selected
 *  0b010101..TRIG_IN4 input is selected
 *  0b010110..TRIG_IN5 input is selected
 *  0b010111..TRIG_IN6 input is selected
 *  0b011000..TRIG_IN7 input is selected
 *  0b011001..TRIG_IN8 input is selected
 *  0b011010..TRIG_IN9 input is selected
 *  0b011011..TRIG_IN10 input is selected
 *  0b011100..TRIG_IN11 input is selected
 *  0b011101..GPIO0 Pin Event Trig 0 input is selected
 *  0b011110..GPIO1 Pin Event Trig 0 input is selected
 *  0b011111..GPIO2 Pin Event Trig 0 input is selected
 *  0b100000..GPIO3 Pin Event Trig 0 input is selected
 *  0b100001..Reserved
 *  0b100010..WUU input is selected
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 */
#define INPUTMUX_LPUART2_INP(x)                  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPUART2_INP_SHIFT)) & INPUTMUX_LPUART2_INP_MASK)
/*! @} */

/*! @name LPUART3 - LPUART3 trigger input connections */
/*! @{ */

#define INPUTMUX_LPUART3_INP_MASK                (0x3FU)
#define INPUTMUX_LPUART3_INP_SHIFT               (0U)
/*! INP - LPUART3 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..LPTMR0 input is selected
 *  0b010000..Reserved
 *  0b010001..TRIG_IN0 input is selected
 *  0b010010..TRIG_IN1 input is selected
 *  0b010011..TRIG_IN2 input is selected
 *  0b010100..TRIG_IN3 input is selected
 *  0b010101..TRIG_IN4 input is selected
 *  0b010110..TRIG_IN5 input is selected
 *  0b010111..TRIG_IN6 input is selected
 *  0b011000..TRIG_IN7 input is selected
 *  0b011001..TRIG_IN8 input is selected
 *  0b011010..TRIG_IN9 input is selected
 *  0b011011..TRIG_IN10 input is selected
 *  0b011100..TRIG_IN11 input is selected
 *  0b011101..GPIO0 Pin Event Trig 0 input is selected
 *  0b011110..GPIO1 Pin Event Trig 0 input is selected
 *  0b011111..GPIO2 Pin Event Trig 0 input is selected
 *  0b100000..GPIO3 Pin Event Trig 0 input is selected
 *  0b100001..Reserved
 *  0b100010..WUU input is selected
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 */
#define INPUTMUX_LPUART3_INP(x)                  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPUART3_INP_SHIFT)) & INPUTMUX_LPUART3_INP_MASK)
/*! @} */

/*! @name LPUART4 - LPUART4 trigger input connections */
/*! @{ */

#define INPUTMUX_LPUART4_INP_MASK                (0x3FU)
#define INPUTMUX_LPUART4_INP_SHIFT               (0U)
/*! INP - LPUART4 trigger input connections
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..AOI0_OUT0 input is selected
 *  0b000011..AOI0_OUT1 input is selected
 *  0b000100..AOI0_OUT2 input is selected
 *  0b000101..AOI0_OUT3 input is selected
 *  0b000110..CMP0_OUT input is selected
 *  0b000111..Reserved
 *  0b001000..Reserved
 *  0b001001..CTimer0_MAT2 input is selected
 *  0b001010..CTimer0_MAT3 input is selected
 *  0b001011..CTimer1_MAT2 input is selected
 *  0b001100..CTimer1_MAT3 input is selected
 *  0b001101..CTimer2_MAT2 input is selected
 *  0b001110..CTimer2_MAT3 input is selected
 *  0b001111..LPTMR0 input is selected
 *  0b010000..Reserved
 *  0b010001..TRIG_IN0 input is selected
 *  0b010010..TRIG_IN1 input is selected
 *  0b010011..TRIG_IN2 input is selected
 *  0b010100..TRIG_IN3 input is selected
 *  0b010101..TRIG_IN4 input is selected
 *  0b010110..TRIG_IN5 input is selected
 *  0b010111..TRIG_IN6 input is selected
 *  0b011000..TRIG_IN7 input is selected
 *  0b011001..TRIG_IN8 input is selected
 *  0b011010..TRIG_IN9 input is selected
 *  0b011011..TRIG_IN10 input is selected
 *  0b011100..TRIG_IN11 input is selected
 *  0b011101..GPIO0 Pin Event Trig 0 input is selected
 *  0b011110..GPIO1 Pin Event Trig 0 input is selected
 *  0b011111..GPIO2 Pin Event Trig 0 input is selected
 *  0b100000..GPIO3 Pin Event Trig 0 input is selected
 *  0b100001..Reserved
 *  0b100010..WUU input is selected
 *  0b100011..Reserved
 *  0b100100..Reserved
 *  0b100101..Reserved
 *  0b100110..Reserved
 *  0b100111..Reserved
 *  0b101000..Reserved
 *  0b101001..Reserved
 *  0b101010..Reserved
 *  0b101011..Reserved
 *  0b101100..Reserved
 *  0b101101..Reserved
 *  0b101110..Reserved
 *  0b101111..Reserved
 */
#define INPUTMUX_LPUART4_INP(x)                  (((uint32_t)(((uint32_t)(x)) << INPUTMUX_LPUART4_INP_SHIFT)) & INPUTMUX_LPUART4_INP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group INPUTMUX_Register_Masks */


/*!
 * @}
 */ /* end of group INPUTMUX_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_INPUTMUX_H_ */

