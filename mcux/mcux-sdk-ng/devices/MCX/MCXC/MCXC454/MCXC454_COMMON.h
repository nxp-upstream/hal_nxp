/*
** ###################################################################
**     Processors:          MCXC454VFM
**                          MCXC454VFT
**                          MCXC454VLF
**                          MCXC454VLH
**                          MCXC454VLK
**                          MCXC454VMP
**
**     Compilers:
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MCXCP064M072F40RM, Rev 1 Draft C
**     Version:             rev. 1.0, 2026-03-13
**     Build:               b260930
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCXC454
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
 * @file MCXC454_COMMON.h
 * @version 1.0
 * @date 2026-03-13
 * @brief CMSIS Peripheral Access Layer for MCXC454
 *
 * CMSIS Peripheral Access Layer for MCXC454
 */

#if !defined(MCXC454_COMMON_H_)
#define MCXC454_COMMON_H_                        /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0000U


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 138                /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M23 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M23 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M23 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M23 System Tick Interrupt */

  /* Device specific interrupts */
  Reserved16_IRQn              = 0,                /**< Reserved interrupt 16 */
  CMC_IRQn                     = 1,                /**< Core Mode Controller interrupt */
  DMA_CH0_IRQn                 = 2,                /**< DMA3_0_CH0 error or transfer complete */
  DMA_CH1_IRQn                 = 3,                /**< DMA3_0_CH1 error or transfer complete */
  DMA_CH2_IRQn                 = 4,                /**< DMA3_0_CH0 error or transfer complete */
  DMA_CH3_IRQn                 = 5,                /**< DMA3_0_CH1 error or transfer complete */
  DMA_CH4_IRQn                 = 6,                /**< DMA3_0_CH0 error or transfer complete */
  DMA_CH5_IRQn                 = 7,                /**< DMA3_0_CH1 error or transfer complete */
  DMA_CH6_IRQn                 = 8,                /**< DMA3_0_CH0 error or transfer complete */
  DMA_CH7_IRQn                 = 9,                /**< DMA3_0_CH1 error or transfer complete */
  ERM0_SINGLE_BIT_IRQn         = 10,               /**< ERM Single Bit error interrupt */
  ERM0_MULTI_BIT_IRQn          = 11,               /**< ERM Multi Bit error interrupt */
  FMU0_IRQn                    = 12,               /**< Flash Management Unit interrupt */
  Reserved29_IRQn              = 13,               /**< Reserved interrupt 29 */
  MBC0_IRQn                    = 14,               /**< MBC secure violation interrupt */
  SCG0_IRQn                    = 15,               /**< System Clock Generator interrupt */
  SPC0_IRQn                    = 16,               /**< System Power Controller interrupt */
  TRNG_IRQn                    = 17,               /**< TRNG  interrupt */
  WUU0_IRQn                    = 18,               /**< Wake Up Unit interrupt */
  Reserved35_IRQn              = 19,               /**< Reserved interrupt 35 */
  Reserved36_IRQn              = 20,               /**< Reserved interrupt 36 */
  Reserved37_IRQn              = 21,               /**< Reserved interrupt 37 */
  Reserved38_IRQn              = 22,               /**< Reserved interrupt 38 */
  Reserved39_IRQn              = 23,               /**< Reserved interrupt 39 */
  I3C_IRQn                     = 24,               /**< I3c Interrupt */
  Reserved41_IRQn              = 25,               /**< Reserved interrupt 41 */
  LPI2C0_IRQn                  = 26,               /**< Low-Power Inter Integrated Circuit 0 interrupt */
  LPI2C1_IRQn                  = 27,               /**< Low-Power Inter Integrated Circuit 0 interrupt */
  LPSPI0_IRQn                  = 28,               /**< Low-Power Serial Peripheral Interface 0 interrupt */
  LPSPI1_IRQn                  = 29,               /**< Low-Power Serial Peripheral Interface 0 interrupt */
  Reserved46_IRQn              = 30,               /**< Reserved interrupt 46 */
  LPUART0_IRQn                 = 31,               /**< Low-Power Universal Asynchronous Receive/Transmit 0 interrupt */
  LPUART1_IRQn                 = 32,               /**< Low-Power Universal Asynchronous Receive/Transmit 1 interrupt */
  LPUART2_IRQn                 = 33,               /**< Low-Power Universal Asynchronous Receive/Transmit 2 interrupt */
  LPUART3_IRQn                 = 34,               /**< Low-Power Universal Asynchronous Receive/Transmit 1 interrupt */
  LPUART4_IRQn                 = 35,               /**< Low-Power Universal Asynchronous Receive/Transmit 2 interrupt */
  Reserved52_IRQn              = 36,               /**< Reserved interrupt 52 */
  Reserved53_IRQn              = 37,               /**< Reserved interrupt 53 */
  Reserved54_IRQn              = 38,               /**< Reserved interrupt 54 */
  CTIMER0_IRQn                 = 39,               /**< Standard counter/timer 0 interrupt */
  CTIMER1_IRQn                 = 40,               /**< Standard counter/timer 0 interrupt */
  CTIMER2_IRQn                 = 41,               /**< Standard counter/timer 0 interrupt */
  Reserved58_IRQn              = 42,               /**< Reserved interrupt 58 */
  Reserved59_IRQn              = 43,               /**< Reserved interrupt 59 */
  FLEXPWM0_RELOAD_ERROR_IRQn   = 44,               /**< FlexPWM0_reload_error interrupt */
  FLEXPWM0_FAULT_IRQn          = 45,               /**< FlexPWM0_fault interrupt */
  FLEXPWM0_SUBMODULE0_IRQn     = 46,               /**< FlexPWM0 Submodule 0 capture/compare/reload interrupt */
  FLEXPWM0_SUBMODULE1_IRQn     = 47,               /**< FlexPWM0 Submodule 1 capture/compare/reload interrupt */
  FLEXPWM0_SUBMODULE2_IRQn     = 48,               /**< FlexPWM0 Submodule 2 capture/compare/reload interrupt */
  FLEXPWM0_SUBMODULE3_IRQn     = 49,               /**< FlexPWM0 Submodule 3 capture/compare/reload interrupt */
  Reserved66_IRQn              = 50,               /**< Reserved interrupt 66 */
  Reserved67_IRQn              = 51,               /**< Reserved interrupt 67 */
  Reserved68_IRQn              = 52,               /**< Reserved interrupt 68 */
  Reserved69_IRQn              = 53,               /**< Reserved interrupt 69 */
  FREQME0_IRQn                 = 54,               /**< Frequency Measurement interrupt */
  LPTMR0_IRQn                  = 55,               /**< Low Power Timer 0 interrupt */
  Reserved72_IRQn              = 56,               /**< Reserved interrupt 72 */
  VBAT0_IRQn                   = 57,               /**< VBAT OSC32K Ready Interrupt */
  RTC_IRQn                     = 58,               /**< RTC alarm interrupt */
  RTC_1HZ_IRQn                 = 59,               /**< RTC 1Hz interrupt */
  WWDT0_IRQn                   = 60,               /**< Windowed Watchdog Timer 0 interrupt */
  WWDT1_IRQn                   = 61,               /**< Windowed Watchdog Timer 0 interrupt */
  ADC0_IRQn                    = 62,               /**< Analog-to-Digital Converter 0 interrupt */
  Reserved79_IRQn              = 63,               /**< Reserved interrupt 79 */
  CMP0_IRQn                    = 64,               /**< Comparator 0 interrupt */
  Reserved81_IRQn              = 65,               /**< Reserved interrupt 81 */
  Reserved82_IRQn              = 66,               /**< Reserved interrupt 82 */
  Reserved83_IRQn              = 67,               /**< Reserved interrupt 83 */
  Reserved84_IRQn              = 68,               /**< Reserved interrupt 84 */
  Reserved85_IRQn              = 69,               /**< Reserved interrupt 85 */
  Reserved86_IRQn              = 70,               /**< Reserved interrupt 86 */
  GPIO0_IRQn                   = 71,               /**< General Purpose Input/Output interrupt 0 */
  GPIO1_IRQn                   = 72,               /**< General Purpose Input/Output interrupt 1 */
  GPIO2_IRQn                   = 73,               /**< General Purpose Input/Output interrupt 2 */
  GPIO3_IRQn                   = 74,               /**< General Purpose Input/Output interrupt 3 */
  Reserved91_IRQn              = 75,               /**< Reserved interrupt 91 */
  Reserved92_IRQn              = 76,               /**< Reserved interrupt 92 */
  LPI2C2_IRQn                  = 77,               /**< Low-Power Inter Integrated Circuit2 interrupt */
  Reserved94_IRQn              = 78,               /**< Reserved interrupt 94 */
  Reserved95_IRQn              = 79,               /**< Reserved interrupt 95 */
  Reserved96_IRQn              = 80,               /**< Reserved interrupt 96 */
  Reserved97_IRQn              = 81,               /**< Reserved interrupt 97 */
  Reserved98_IRQn              = 82,               /**< Reserved interrupt 98 */
  Reserved99_IRQn              = 83,               /**< Reserved interrupt 99 */
  Reserved100_IRQn             = 84,               /**< Reserved interrupt 100 */
  Reserved101_IRQn             = 85,               /**< Reserved interrupt 101 */
  Reserved102_IRQn             = 86,               /**< Reserved interrupt 102 */
  Reserved103_IRQn             = 87,               /**< Reserved interrupt 103 */
  Reserved104_IRQn             = 88,               /**< Reserved interrupt 104 */
  Reserved105_IRQn             = 89,               /**< Reserved interrupt 105 */
  Reserved106_IRQn             = 90,               /**< Reserved interrupt 106 */
  Reserved107_IRQn             = 91,               /**< Reserved interrupt 107 */
  Reserved108_IRQn             = 92,               /**< Reserved interrupt 108 */
  Reserved109_IRQn             = 93,               /**< Reserved interrupt 109 */
  Reserved110_IRQn             = 94,               /**< Reserved interrupt 110 */
  Reserved111_IRQn             = 95,               /**< Reserved interrupt 111 */
  Reserved112_IRQn             = 96,               /**< Reserved interrupt 112 */
  Reserved113_IRQn             = 97,               /**< Reserved interrupt 113 */
  Reserved114_IRQn             = 98,               /**< Reserved interrupt 114 */
  Reserved115_IRQn             = 99,               /**< Reserved interrupt 115 */
  Reserved116_IRQn             = 100,              /**< Reserved interrupt 116 */
  Reserved117_IRQn             = 101,              /**< Reserved interrupt 117 */
  Reserved118_IRQn             = 102,              /**< Reserved interrupt 118 */
  Reserved119_IRQn             = 103,              /**< Reserved interrupt 119 */
  Reserved120_IRQn             = 104,              /**< Reserved interrupt 120 */
  Reserved121_IRQn             = 105,              /**< Reserved interrupt 121 */
  Reserved122_IRQn             = 106,              /**< Reserved interrupt 122 */
  Reserved123_IRQn             = 107,              /**< Reserved interrupt 123 */
  Reserved124_IRQn             = 108,              /**< Reserved interrupt 124 */
  Reserved125_IRQn             = 109,              /**< Reserved interrupt 125 */
  Reserved126_IRQn             = 110,              /**< Reserved interrupt 126 */
  SGI_IRQn                     = 111,              /**< SGI interrupt */
  Reserved128_IRQn             = 112,              /**< Reserved interrupt 128 */
  Reserved129_IRQn             = 113,              /**< Reserved interrupt 129 */
  SECURE_ERR_IRQn              = 114,              /**< Secure IP Error interrupt. SGI, TRNG error together */
  Reserved131_IRQn             = 115,              /**< Reserved interrupt 131 */
  Reserved132_IRQn             = 116,              /**< Reserved interrupt 132 */
  Reserved133_IRQn             = 117,              /**< Reserved interrupt 133 */
  Reserved134_IRQn             = 118,              /**< Reserved interrupt 134 */
  TSI_END_OF_SCAN_IRQn         = 119,              /**< TSI End of Scan interrupt */
  TSI_OUT_OF_SCAN_IRQn         = 120,              /**< TSI Out of Scan interrupt */
  LCD_IRQn                     = 121               /**< SLCD frame start interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M23 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M23 Core Configuration
 * @{
 */

#define __CM23_REV                     0x0200    /**< Core revision r2p0 */
#define __MPU_PRESENT                  0         /**< Defines if an MPU is present or not */
#define __VTOR_PRESENT                 1         /**< Defines if VTOR is present or not */
#define __NVIC_PRIO_BITS               2         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __SAUREGION_PRESENT            0         /**< Defines if an SAU is present or not */

#include "core_cm23.h"                 /* Core Peripheral Access Layer */
#include "system_MCXC454.h"            /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MCXC454_SERIES
#define MCXC454_SERIES
#endif
/* CPU specific feature definitions */
#include "MCXC454_features.h"

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
/*!
 * @addtogroup eim_memory_channel_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the eim_memory_channel
 *
 *
 * Defines the structure for the EIM resource collections.
 */
typedef enum _eim_memory_channel
{
    kEIM_MemoryChannelRAMA0         = 0U,          /**< Memory RAMA0 */
} eim_memory_channel_t;

/* @} */

/*!
 * @addtogroup eim_error_injection_channel_enab_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the eim_error_injection_channel_enable
 *
 *
 * Defines the structure for the EIM error injection resource collections.
 */
typedef enum _eim_error_injection_channel_enab
{
    kEIM_MemoryChannelRAMAEnable    = 0x80000000U, /**< Memory channel 0(RAMA0) error injection enable */
} eim_error_injection_channel_enab_t;

/* @} */

/*!
 * @addtogroup erm_memory_channel_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the erm_memory_channel
 *
 *
 * Defines the structure for the ERM resource collections.
 */
typedef enum _erm_memory_channel
{
    kERM_MemoryChannelRAMA0         = 0U,          /**< Memory RAMA0 */
    kERM_MemoryChannelFLASH         = 1U,          /**< Memory FLASH */
} erm_memory_channel_t;

/* @} */


/*!
 * @}
 */ /* end of group Mapping_Information */


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0x4002F000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((ADC_Type *)ADC0_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC0_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC0 }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn }

/* AOI - Peripheral instance base addresses */
/** Peripheral AOI0 base address */
#define AOI0_BASE                                (0x40018000u)
/** Peripheral AOI0 base pointer */
#define AOI0                                     ((AOI_Type *)AOI0_BASE)
/** Array initializer of AOI peripheral base addresses */
#define AOI_BASE_ADDRS                           { AOI0_BASE }
/** Array initializer of AOI peripheral base pointers */
#define AOI_BASE_PTRS                            { AOI0 }

/* CMC - Peripheral instance base addresses */
/** Peripheral CMC base address */
#define CMC_BASE                                 (0x4000B000u)
/** Peripheral CMC base pointer */
#define CMC                                      ((CMC_Type *)CMC_BASE)
/** Array initializer of CMC peripheral base addresses */
#define CMC_BASE_ADDRS                           { CMC_BASE }
/** Array initializer of CMC peripheral base pointers */
#define CMC_BASE_PTRS                            { CMC }
/** Interrupt vectors for the CMC peripheral type */
#define CMC_IRQS                                 { CMC_IRQn }

/* CRC - Peripheral instance base addresses */
/** Peripheral CRC0 base address */
#define CRC0_BASE                                (0x4000A000u)
/** Peripheral CRC0 base pointer */
#define CRC0                                     ((CRC_Type *)CRC0_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC0_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC0 }

/* CTIMER - Peripheral instance base addresses */
/** Peripheral CTIMER0 base address */
#define CTIMER0_BASE                             (0x4002C000u)
/** Peripheral CTIMER0 base pointer */
#define CTIMER0                                  ((CTIMER_Type *)CTIMER0_BASE)
/** Peripheral CTIMER1 base address */
#define CTIMER1_BASE                             (0x4002D000u)
/** Peripheral CTIMER1 base pointer */
#define CTIMER1                                  ((CTIMER_Type *)CTIMER1_BASE)
/** Peripheral CTIMER2 base address */
#define CTIMER2_BASE                             (0x4002E000u)
/** Peripheral CTIMER2 base pointer */
#define CTIMER2                                  ((CTIMER_Type *)CTIMER2_BASE)
/** Array initializer of CTIMER peripheral base addresses */
#define CTIMER_BASE_ADDRS                        { CTIMER0_BASE, CTIMER1_BASE, CTIMER2_BASE }
/** Array initializer of CTIMER peripheral base pointers */
#define CTIMER_BASE_PTRS                         { CTIMER0, CTIMER1, CTIMER2 }
/** Interrupt vectors for the CTIMER peripheral type */
#define CTIMER_IRQS                              { CTIMER0_IRQn, CTIMER1_IRQn, CTIMER2_IRQn }

/* DEBUGMAILBOX - Peripheral instance base addresses */
/** Peripheral DBGMAILBOX base address */
#define DBGMAILBOX_BASE                          (0x40100000u)
/** Peripheral DBGMAILBOX base pointer */
#define DBGMAILBOX                               ((DEBUGMAILBOX_Type *)DBGMAILBOX_BASE)
/** Array initializer of DEBUGMAILBOX peripheral base addresses */
#define DEBUGMAILBOX_BASE_ADDRS                  { DBGMAILBOX_BASE }
/** Array initializer of DEBUGMAILBOX peripheral base pointers */
#define DEBUGMAILBOX_BASE_PTRS                   { DBGMAILBOX }

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA0 base address */
#define DMA0_BASE                                (0x40000000u)
/** Peripheral DMA0 base pointer */
#define DMA0                                     ((DMA_Type *)DMA0_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA0_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA0 }
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { { DMA_CH0_IRQn, DMA_CH1_IRQn, DMA_CH2_IRQn, DMA_CH3_IRQn, DMA_CH4_IRQn, DMA_CH5_IRQn, DMA_CH6_IRQn, DMA_CH7_IRQn } }
#define DMA_ERROR_IRQS                           { { DMA_CH0_IRQn, DMA_CH1_IRQn, DMA_CH2_IRQn, DMA_CH3_IRQn, DMA_CH4_IRQn, DMA_CH5_IRQn, DMA_CH6_IRQn, DMA_CH7_IRQn } }

/* EIM - Peripheral instance base addresses */
/** Peripheral EIM0 base address */
#define EIM0_BASE                                (0x4000C000u)
/** Peripheral EIM0 base pointer */
#define EIM0                                     ((EIM_Type *)EIM0_BASE)
/** Array initializer of EIM peripheral base addresses */
#define EIM_BASE_ADDRS                           { EIM0_BASE }
/** Array initializer of EIM peripheral base pointers */
#define EIM_BASE_PTRS                            { EIM0 }

/* ERM - Peripheral instance base addresses */
/** Peripheral ERM0 base address */
#define ERM0_BASE                                (0x4000D000u)
/** Peripheral ERM0 base pointer */
#define ERM0                                     ((ERM_Type *)ERM0_BASE)
/** Array initializer of ERM peripheral base addresses */
#define ERM_BASE_ADDRS                           { ERM0_BASE }
/** Array initializer of ERM peripheral base pointers */
#define ERM_BASE_PTRS                            { ERM0 }

/* FMU - Peripheral instance base addresses */
/** Peripheral FMU0 base address */
#define FMU0_BASE                                (0x40015000u)
/** Peripheral FMU0 base pointer */
#define FMU0                                     ((FMU_Type *)FMU0_BASE)
/** Array initializer of FMU peripheral base addresses */
#define FMU_BASE_ADDRS                           { FMU0_BASE }
/** Array initializer of FMU peripheral base pointers */
#define FMU_BASE_PTRS                            { FMU0 }
/** Interrupt vectors for the FMU peripheral type */
#define FMU_IRQS                                 { FMU0_IRQn }

/* FREQME - Peripheral instance base addresses */
/** Peripheral FREQME0 base address */
#define FREQME0_BASE                             (0x40009000u)
/** Peripheral FREQME0 base pointer */
#define FREQME0                                  ((FREQME_Type *)FREQME0_BASE)
/** Array initializer of FREQME peripheral base addresses */
#define FREQME_BASE_ADDRS                        { FREQME0_BASE }
/** Array initializer of FREQME peripheral base pointers */
#define FREQME_BASE_PTRS                         { FREQME0 }
/** Interrupt vectors for the FREQME peripheral type */
#define FREQME_IRQS                              { FREQME0_IRQn }

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIO0 base address */
#define GPIO0_BASE                               (0x40073000u)
/** Peripheral GPIO0 base pointer */
#define GPIO0                                    ((GPIO_Type *)GPIO0_BASE)
/** Peripheral GPIO1 base address */
#define GPIO1_BASE                               (0x40074000u)
/** Peripheral GPIO1 base pointer */
#define GPIO1                                    ((GPIO_Type *)GPIO1_BASE)
/** Peripheral GPIO2 base address */
#define GPIO2_BASE                               (0x40075000u)
/** Peripheral GPIO2 base pointer */
#define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
/** Peripheral GPIO3 base address */
#define GPIO3_BASE                               (0x40076000u)
/** Peripheral GPIO3 base pointer */
#define GPIO3                                    ((GPIO_Type *)GPIO3_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIO0_BASE, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIO0, GPIO1, GPIO2, GPIO3 }
/** Interrupt vectors for the GPIO peripheral type */
#define GPIO_IRQS                                { GPIO0_IRQn, GPIO1_IRQn, GPIO2_IRQn, GPIO3_IRQn }
/* FGPIO Extra definitions */
/* Peripheral FGPIO0 base address */
#define FGPIO0_BASE                               (0xF8001000u)
/* Peripheral FGPIO0 base pointer */
#define FGPIO0                                    ((GPIO_Type *)FGPIO0_BASE)
/* Peripheral FGPIO1 base address */
#define FGPIO1_BASE                               (0xF8002000u)
/* Peripheral FGPIO1 base pointer */
#define FGPIO1                                    ((GPIO_Type *)FGPIO1_BASE)
/* Peripheral FGPIO2 base address */
#define FGPIO2_BASE                               (0xF8003000u)
/* Peripheral FGPIO2 base pointer */
#define FGPIO2                                    ((GPIO_Type *)FGPIO2_BASE)
/* Peripheral FGPIO3 base address */
#define FGPIO3_BASE                               (0xF8004000u)
/* Peripheral FGPIO3 base pointer */
#define FGPIO3                                    ((GPIO_Type *)FGPIO3_BASE)
/* Array initializer of FGPIO peripheral base addresses */
#define FGPIO_BASE_ADDRS                          { FGPIO0_BASE, FGPIO1_BASE, FGPIO2_BASE, FGPIO3_BASE }
/* Array initializer of FGPIO peripheral base pointers */
#define FGPIO_BASE_PTRS                           { FGPIO0, FGPIO1, FGPIO2, FGPIO3 }
/* Interrupt vectors for the FGPIO peripheral type */
#define FGPIO_IRQS                                { GPIO0_IRQn, GPIO1_IRQn, GPIO2_IRQn, GPIO3_IRQn }


/* I3C - Peripheral instance base addresses */
/** Peripheral I3C0 base address */
#define I3C0_BASE                                (0x40057000u)
/** Peripheral I3C0 base pointer */
#define I3C0                                     ((I3C_Type *)I3C0_BASE)
/** Array initializer of I3C peripheral base addresses */
#define I3C_BASE_ADDRS                           { I3C0_BASE }
/** Array initializer of I3C peripheral base pointers */
#define I3C_BASE_PTRS                            { I3C0 }
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { I3C_IRQn }

/* INPUTMUX - Peripheral instance base addresses */
/** Peripheral INPUTMUX0 base address */
#define INPUTMUX0_BASE                           (0x40017000u)
/** Peripheral INPUTMUX0 base pointer */
#define INPUTMUX0                                ((INPUTMUX_Type *)INPUTMUX0_BASE)
/** Array initializer of INPUTMUX peripheral base addresses */
#define INPUTMUX_BASE_ADDRS                      { INPUTMUX0_BASE }
/** Array initializer of INPUTMUX peripheral base pointers */
#define INPUTMUX_BASE_PTRS                       { INPUTMUX0 }

/* LCD - Peripheral instance base addresses */
/** Peripheral SLCD base address */
#define SLCD_BASE                                (0u)
/** Peripheral SLCD base pointer */
#define SLCD                                     ((LCD_Type *)SLCD_BASE)
/** Peripheral SLCD0 base address */
#define SLCD0_BASE                               (0x40042000u)
/** Peripheral SLCD0 base pointer */
#define SLCD0                                    ((LCD_Type *)SLCD0_BASE)
/** Array initializer of LCD peripheral base addresses */
#define LCD_BASE_ADDRS                           { SLCD_BASE, SLCD0_BASE }
/** Array initializer of LCD peripheral base pointers */
#define LCD_BASE_PTRS                            { SLCD, SLCD0 }
/* Backward compatibility */
#define LCD_WFOVERLAY_WFACCESS8BIT_WF8B_COUNT    LCD_WF_ACCESS_WF8BIT_WF8B_COUNT
#define LCD_WFOVERLAY_WFACCESS32BIT_WF_COUNT     LCD_WF_ACCESS_WF32BIT_WF_COUNT


/* LPCMP - Peripheral instance base addresses */
/** Peripheral CMP0 base address */
#define CMP0_BASE                                (0x40031000u)
/** Peripheral CMP0 base pointer */
#define CMP0                                     ((LPCMP_Type *)CMP0_BASE)
/** Array initializer of LPCMP peripheral base addresses */
#define LPCMP_BASE_ADDRS                         { CMP0_BASE }
/** Array initializer of LPCMP peripheral base pointers */
#define LPCMP_BASE_PTRS                          { CMP0 }
/** Interrupt vectors for the LPCMP peripheral type */
#define LPCMP_IRQS                               { CMP0_IRQn }

/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              (0x4001A000u)
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              (0x4001B000u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
/** Peripheral LPI2C2 base address */
#define LPI2C2_BASE                              (0x40054000u)
/** Peripheral LPI2C2 base pointer */
#define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, LPI2C2_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, LPI2C2 }
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LPI2C0_IRQn, LPI2C1_IRQn, LPI2C2_IRQn }

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI0 base address */
#define LPSPI0_BASE                              (0x4001C000u)
/** Peripheral LPSPI0 base pointer */
#define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0x4001D000u)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI0_IRQn, LPSPI1_IRQn }

/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR0 base address */
#define LPTMR0_BASE                              (0x4002B000u)
/** Peripheral LPTMR0 base pointer */
#define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
/** Array initializer of LPTMR peripheral base addresses */
#define LPTMR_BASE_ADDRS                         { LPTMR0_BASE }
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { LPTMR0 }
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { LPTMR0_IRQn }

/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART0 base address */
#define LPUART0_BASE                             (0x4001F000u)
/** Peripheral LPUART0 base pointer */
#define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x40020000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             (0x40021000u)
/** Peripheral LPUART2 base pointer */
#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
/** Peripheral LPUART3 base address */
#define LPUART3_BASE                             (0x40022000u)
/** Peripheral LPUART3 base pointer */
#define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
/** Peripheral LPUART4 base address */
#define LPUART4_BASE                             (0x40023000u)
/** Peripheral LPUART4 base pointer */
#define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2, LPUART3, LPUART4 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn }
#define LPUART_ERR_IRQS                          { LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn }

/* MRCC - Peripheral instance base addresses */
/** Peripheral MRCC0 base address */
#define MRCC0_BASE                               (0x40011800u)
/** Peripheral MRCC0 base pointer */
#define MRCC0                                    ((MRCC_Type *)MRCC0_BASE)
/** Array initializer of MRCC peripheral base addresses */
#define MRCC_BASE_ADDRS                          { MRCC0_BASE }
/** Array initializer of MRCC peripheral base pointers */
#define MRCC_BASE_PTRS                           { MRCC0 }

/* PORT - Peripheral instance base addresses */
/** Peripheral PORT0 base address */
#define PORT0_BASE                               (0x4003C000u)
/** Peripheral PORT0 base pointer */
#define PORT0                                    ((PORT_Type *)PORT0_BASE)
/** Peripheral PORT1 base address */
#define PORT1_BASE                               (0x4003D000u)
/** Peripheral PORT1 base pointer */
#define PORT1                                    ((PORT_Type *)PORT1_BASE)
/** Peripheral PORT2 base address */
#define PORT2_BASE                               (0x4003E000u)
/** Peripheral PORT2 base pointer */
#define PORT2                                    ((PORT_Type *)PORT2_BASE)
/** Peripheral PORT3 base address */
#define PORT3_BASE                               (0x4003F000u)
/** Peripheral PORT3 base pointer */
#define PORT3                                    ((PORT_Type *)PORT3_BASE)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORT0_BASE, PORT1_BASE, PORT2_BASE, PORT3_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORT0, PORT1, PORT2, PORT3 }

/* PWM - Peripheral instance base addresses */
/** Peripheral FLEXPWM0 base address */
#define FLEXPWM0_BASE                            (0x40029000u)
/** Peripheral FLEXPWM0 base pointer */
#define FLEXPWM0                                 ((PWM_Type *)FLEXPWM0_BASE)
/** Array initializer of PWM peripheral base addresses */
#define PWM_BASE_ADDRS                           { FLEXPWM0_BASE }
/** Array initializer of PWM peripheral base pointers */
#define PWM_BASE_PTRS                            { FLEXPWM0 }
/** Interrupt vectors for the PWM peripheral type */
#define PWM_CMP_IRQS                             { { FLEXPWM0_SUBMODULE0_IRQn, FLEXPWM0_SUBMODULE1_IRQn, FLEXPWM0_SUBMODULE2_IRQn, FLEXPWM0_SUBMODULE3_IRQn } }
#define PWM_RELOAD_IRQS                          { { FLEXPWM0_SUBMODULE0_IRQn, FLEXPWM0_SUBMODULE1_IRQn, FLEXPWM0_SUBMODULE2_IRQn, FLEXPWM0_SUBMODULE3_IRQn } }
#define PWM_CAPTURE_IRQS                         { { FLEXPWM0_SUBMODULE0_IRQn, FLEXPWM0_SUBMODULE1_IRQn, FLEXPWM0_SUBMODULE2_IRQn, FLEXPWM0_SUBMODULE3_IRQn } }
#define PWM_FAULT_IRQS                           { FLEXPWM0_FAULT_IRQn }
#define PWM_RELOAD_ERROR_IRQS                    { FLEXPWM0_RELOAD_ERROR_IRQn }

/* RTC - Peripheral instance base addresses */
/** Peripheral RTC0 base address */
#define RTC0_BASE                                (0x4006E000u)
/** Peripheral RTC0 base pointer */
#define RTC0                                     ((RTC_Type *)RTC0_BASE)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC0_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC0 }
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { RTC_IRQn }
#define RTC_SECONDS_IRQS                         { RTC_1HZ_IRQn }

/* SCG - Peripheral instance base addresses */
/** Peripheral SCG0 base address */
#define SCG0_BASE                                (0x4000F000u)
/** Peripheral SCG0 base pointer */
#define SCG0                                     ((SCG_Type *)SCG0_BASE)
/** Array initializer of SCG peripheral base addresses */
#define SCG_BASE_ADDRS                           { SCG0_BASE }
/** Array initializer of SCG peripheral base pointers */
#define SCG_BASE_PTRS                            { SCG0 }
/** Interrupt vectors for the SCG peripheral type */
#define SCG_IRQS                                 { SCG0_IRQn }

/* SECCON - Peripheral instance base addresses */
/** Peripheral SECCON base address */
#define SECCON_BASE                              (0x40068000u)
/** Peripheral SECCON base pointer */
#define SECCON                                   ((SECCON_Type *)SECCON_BASE)
/** Array initializer of SECCON peripheral base addresses */
#define SECCON_BASE_ADDRS                        { SECCON_BASE }
/** Array initializer of SECCON peripheral base pointers */
#define SECCON_BASE_PTRS                         { SECCON }

/* SGI - Peripheral instance base addresses */
/** Peripheral SGI0 base address */
#define SGI0_BASE                                (0x4006B000u)
/** Peripheral SGI0 base pointer */
#define SGI0                                     ((SGI_Type *)SGI0_BASE)
/** Array initializer of SGI peripheral base addresses */
#define SGI_BASE_ADDRS                           { SGI0_BASE }
/** Array initializer of SGI peripheral base pointers */
#define SGI_BASE_PTRS                            { SGI0 }

/* SPC - Peripheral instance base addresses */
/** Peripheral SPC0 base address */
#define SPC0_BASE                                (0x40010000u)
/** Peripheral SPC0 base pointer */
#define SPC0                                     ((SPC_Type *)SPC0_BASE)
/** Array initializer of SPC peripheral base addresses */
#define SPC_BASE_ADDRS                           { SPC0_BASE }
/** Array initializer of SPC peripheral base pointers */
#define SPC_BASE_PTRS                            { SPC0 }

/* SYSCON - Peripheral instance base addresses */
/** Peripheral SYSCON base address */
#define SYSCON_BASE                              (0x40011000u)
/** Peripheral SYSCON base pointer */
#define SYSCON                                   ((SYSCON_Type *)SYSCON_BASE)
/** Array initializer of SYSCON peripheral base addresses */
#define SYSCON_BASE_ADDRS                        { SYSCON_BASE }
/** Array initializer of SYSCON peripheral base pointers */
#define SYSCON_BASE_PTRS                         { SYSCON }

/* TRDC - Peripheral instance base addresses */
/** Peripheral MBC base address */
#define MBC_BASE                                 (0x4000E000u)
/** Peripheral MBC base pointer */
#define MBC                                      ((TRDC_Type *)MBC_BASE)
/** Array initializer of TRDC peripheral base addresses */
#define TRDC_BASE_ADDRS                          { MBC_BASE }
/** Array initializer of TRDC peripheral base pointers */
#define TRDC_BASE_PTRS                           { MBC }

/* TRNG - Peripheral instance base addresses */
/** Peripheral TRNG0 base address */
#define TRNG0_BASE                               (0x4006C000u)
/** Peripheral TRNG0 base pointer */
#define TRNG0                                    ((TRNG_Type *)TRNG0_BASE)
/** Array initializer of TRNG peripheral base addresses */
#define TRNG_BASE_ADDRS                          { TRNG0_BASE }
/** Array initializer of TRNG peripheral base pointers */
#define TRNG_BASE_PTRS                           { TRNG0 }
/** Interrupt vectors for the TRNG peripheral type */
#define TRNG_IRQS                                { TRNG_IRQn }

/* TSI - Peripheral instance base addresses */
/** Peripheral TSI0 base address */
#define TSI0_BASE                                (0x40043000u)
/** Peripheral TSI0 base pointer */
#define TSI0                                     ((TSI_Type *)TSI0_BASE)
/** Array initializer of TSI peripheral base addresses */
#define TSI_BASE_ADDRS                           { TSI0_BASE }
/** Array initializer of TSI peripheral base pointers */
#define TSI_BASE_PTRS                            { TSI0 }

/* VBAT - Peripheral instance base addresses */
/** Peripheral VBAT0 base address */
#define VBAT0_BASE                               (0x40013000u)
/** Peripheral VBAT0 base pointer */
#define VBAT0                                    ((VBAT_Type *)VBAT0_BASE)
/** Array initializer of VBAT peripheral base addresses */
#define VBAT_BASE_ADDRS                          { VBAT0_BASE }
/** Array initializer of VBAT peripheral base pointers */
#define VBAT_BASE_PTRS                           { VBAT0 }

/* WUU - Peripheral instance base addresses */
/** Peripheral WUU0 base address */
#define WUU0_BASE                                (0x40012000u)
/** Peripheral WUU0 base pointer */
#define WUU0                                     ((WUU_Type *)WUU0_BASE)
/** Array initializer of WUU peripheral base addresses */
#define WUU_BASE_ADDRS                           { WUU0_BASE }
/** Array initializer of WUU peripheral base pointers */
#define WUU_BASE_PTRS                            { WUU0 }
/** Interrupt vectors for the WUU peripheral type */
#define WUU_IRQS                                 { WUU0_IRQn }

/* WWDT - Peripheral instance base addresses */
/** Peripheral WWDT0 base address */
#define WWDT0_BASE                               (0x40066000u)
/** Peripheral WWDT0 base pointer */
#define WWDT0                                    ((WWDT_Type *)WWDT0_BASE)
/** Peripheral WWDT1 base address */
#define WWDT1_BASE                               (0x40067000u)
/** Peripheral WWDT1 base pointer */
#define WWDT1                                    ((WWDT_Type *)WWDT1_BASE)
/** Array initializer of WWDT peripheral base addresses */
#define WWDT_BASE_ADDRS                          { WWDT0_BASE, WWDT1_BASE }
/** Array initializer of WWDT peripheral base pointers */
#define WWDT_BASE_PTRS                           { WWDT0, WWDT1 }
/** Interrupt vectors for the WWDT peripheral type */
#define WWDT_IRQS                                { WWDT0_IRQn, WWDT1_IRQn }

/* ----------------------------------------------------------------------------
   -- Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Bit_Field_Generic_Macros Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
 * @{
 */

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang system_header
  #endif
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma system_include
#endif

/**
 * @brief Mask and left-shift a bit field value for use in a register bit range.
 * @param field Name of the register bit field.
 * @param value Value of the bit field.
 * @return Masked and shifted value.
 */
#define NXP_VAL2FLD(field, value)    (((value) << (field ## _SHIFT)) & (field ## _MASK))
/**
 * @brief Mask and right-shift a register value to extract a bit field value.
 * @param field Name of the register bit field.
 * @param value Value of the register.
 * @return Masked and shifted bit field value.
 */
#define NXP_FLD2VAL(field, value)    (((value) & (field ## _MASK)) >> (field ## _SHIFT))

/*!
 * @}
 */ /* end of group Bit_Field_Generic_Macros */


/* ----------------------------------------------------------------------------
   -- SDK Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDK_Compatibility_Symbols SDK Compatibility
 * @{
 */

/* No SDK compatibility issues. */

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* MCXC454_COMMON_H_ */

