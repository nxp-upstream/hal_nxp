//*****************************************************************************
// MCXL253_cm33 startup code for use with MCUXpresso IDE
//
// Version : 270325
//*****************************************************************************
//
// Copyright 2016-2025 NXP
// All rights reserved.
//
// SPDX-License-Identifier: BSD-3-Clause
//*****************************************************************************

#if defined (DEBUG)
#pragma GCC push_options
#pragma GCC optimize ("Og")
#endif // (DEBUG)

#if defined (__cplusplus)
#ifdef __REDLIB__
#error Redlib does not support C++
#else
//*****************************************************************************
//
// The entry point for the C++ library startup
//
//*****************************************************************************
extern "C" {
    extern void __libc_init_array(void);
}
#endif
#endif

#define WEAK __attribute__ ((weak))
#define WEAK_AV __attribute__ ((weak, section(".after_vectors")))
#define ALIAS(f) __attribute__ ((weak, alias (#f)))

//*****************************************************************************
#if defined (__cplusplus)
extern "C" {
#endif

//*****************************************************************************
// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
//*****************************************************************************
//*****************************************************************************
// Declaration of external SystemInit function
//*****************************************************************************
#if defined (__USE_CMSIS)
extern void SystemInit(void);
#endif // (__USE_CMSIS)

//*****************************************************************************
// Forward declaration of the core exception handlers.
// When the application defines a handler (with the same name), this will
// automatically take precedence over these weak definitions.
// If your application is a C++ one, then any interrupt handlers defined
// in C++ files within in your main application will need to have C linkage
// rather than C++ linkage. To do this, make sure that you are using extern "C"
// { .... } around the interrupt handler within your main application code.
//*****************************************************************************
     void ResetISR(void);
WEAK void NMI_Handler(void);
WEAK void HardFault_Handler(void);
WEAK void BusFault_Handler(void);
WEAK void UsageFault_Handler(void);
WEAK void SVC_Handler(void);
WEAK void DebugMon_Handler(void);
WEAK void PendSV_Handler(void);
WEAK void SysTick_Handler(void);
WEAK void IntDefaultHandler(void);

//*****************************************************************************
// Forward declaration of the application IRQ handlers. When the application
// defines a handler (with the same name), this will automatically take
// precedence over weak definitions below
//*****************************************************************************
WEAK void Reserved16_IRQHandler(void);
WEAK void CMC_IRQHandler(void);
WEAK void DMA0_CH0_IRQHandler(void);
WEAK void DMA0_CH1_IRQHandler(void);
WEAK void DMA0_CH2_IRQHandler(void);
WEAK void DMA0_CH3_IRQHandler(void);
WEAK void Reserved22_IRQHandler(void);
WEAK void Reserved23_IRQHandler(void);
WEAK void Reserved24_IRQHandler(void);
WEAK void Reserved25_IRQHandler(void);
WEAK void ERM0_IRQHandler(void);
WEAK void Reserved27_IRQHandler(void);
WEAK void FMU0_IRQHandler(void);
WEAK void GLIKEY0_IRQHandler(void);
WEAK void MBC0_IRQHandler(void);
WEAK void SCG0_IRQHandler(void);
WEAK void Reserved32_IRQHandler(void);
WEAK void Reserved33_IRQHandler(void);
WEAK void WUU0_IRQHandler(void);
WEAK void Reserved35_IRQHandler(void);
WEAK void Reserved36_IRQHandler(void);
WEAK void Reserved37_IRQHandler(void);
WEAK void Reserved38_IRQHandler(void);
WEAK void Reserved39_IRQHandler(void);
WEAK void Reserved40_IRQHandler(void);
WEAK void Reserved41_IRQHandler(void);
WEAK void LPI2C0_IRQHandler(void);
WEAK void LPI2C1_IRQHandler(void);
WEAK void LPSPI0_IRQHandler(void);
WEAK void LPSPI1_IRQHandler(void);
WEAK void Reserved46_IRQHandler(void);
WEAK void LPUART0_IRQHandler(void);
WEAK void LPUART1_IRQHandler(void);
WEAK void Reserved49_IRQHandler(void);
WEAK void Reserved50_IRQHandler(void);
WEAK void Reserved51_IRQHandler(void);
WEAK void Reserved52_IRQHandler(void);
WEAK void Reserved53_IRQHandler(void);
WEAK void CDOG0_IRQHandler(void);
WEAK void CTIMER0_IRQHandler(void);
WEAK void CTIMER1_IRQHandler(void);
WEAK void CTIMER2_IRQHandler(void);
WEAK void Reserved58_IRQHandler(void);
WEAK void Reserved59_IRQHandler(void);
WEAK void Reserved60_IRQHandler(void);
WEAK void Reserved61_IRQHandler(void);
WEAK void Reserved62_IRQHandler(void);
WEAK void Reserved63_IRQHandler(void);
WEAK void Reserved64_IRQHandler(void);
WEAK void Reserved65_IRQHandler(void);
WEAK void Reserved66_IRQHandler(void);
WEAK void Reserved67_IRQHandler(void);
WEAK void Reserved68_IRQHandler(void);
WEAK void Reserved69_IRQHandler(void);
WEAK void FREQME0_IRQHandler(void);
WEAK void Reserved71_IRQHandler(void);
WEAK void Reserved72_IRQHandler(void);
WEAK void OS_EVENT_IRQHandler(void);
WEAK void Reserved74_IRQHandler(void);
WEAK void UTICK0_IRQHandler(void);
WEAK void WWDT0_IRQHandler(void);
WEAK void Reserved77_IRQHandler(void);
WEAK void ADC0_IRQHandler(void);
WEAK void Reserved79_IRQHandler(void);
WEAK void CMP0_IRQHandler(void);
WEAK void Reserved81_IRQHandler(void);
WEAK void Reserved82_IRQHandler(void);
WEAK void Reserved83_IRQHandler(void);
WEAK void Reserved84_IRQHandler(void);
WEAK void Reserved85_IRQHandler(void);
WEAK void Reserved86_IRQHandler(void);
WEAK void GPIO10_IRQHandler(void);
WEAK void GPIO11_IRQHandler(void);
WEAK void GPIO20_IRQHandler(void);
WEAK void GPIO21_IRQHandler(void);
WEAK void GPIO30_IRQHandler(void);
WEAK void GPIO31_IRQHandler(void);
WEAK void Reserved93_IRQHandler(void);
WEAK void Reserved94_IRQHandler(void);
WEAK void Reserved95_IRQHandler(void);
WEAK void MU_A_TX_IRQHandler(void);
WEAK void MU_A_RX_IRQHandler(void);
WEAK void MU_A_INT_IRQHandler(void);
WEAK void CDOG1_IRQHandler(void);
WEAK void Reserved100_IRQHandler(void);
WEAK void Reserved101_IRQHandler(void);
WEAK void Reserved102_IRQHandler(void);
WEAK void Reserved103_IRQHandler(void);
WEAK void Reserved104_IRQHandler(void);
WEAK void Reserved105_IRQHandler(void);
WEAK void Reserved106_IRQHandler(void);
WEAK void Reserved107_IRQHandler(void);
WEAK void Reserved108_IRQHandler(void);
WEAK void Reserved109_IRQHandler(void);
WEAK void Reserved110_IRQHandler(void);
WEAK void Reserved111_IRQHandler(void);
WEAK void DMA1_CH0_IRQHandler(void);
WEAK void DMA1_CH1_IRQHandler(void);
WEAK void DMA1_CH2_IRQHandler(void);
WEAK void DMA1_CH3_IRQHandler(void);
WEAK void Reserved116_IRQHandler(void);
WEAK void Reserved117_IRQHandler(void);
WEAK void Reserved118_IRQHandler(void);
WEAK void Reserved119_IRQHandler(void);
WEAK void Reserved120_IRQHandler(void);
WEAK void Reserved121_IRQHandler(void);
WEAK void Reserved122_IRQHandler(void);
WEAK void Reserved123_IRQHandler(void);
WEAK void Reserved124_IRQHandler(void);
WEAK void Reserved125_IRQHandler(void);
WEAK void PKC_IRQHandler(void);
WEAK void SGI_IRQHandler(void);
WEAK void TRNG_IRQHandler(void);
WEAK void ERR_SGI_UDF_TRNG_PKC_IRQHandler(void);
WEAK void HYPERVISOR_IRQHandler(void);
WEAK void Reserved131_IRQHandler(void);
WEAK void Reserved132_IRQHandler(void);
WEAK void Reserved133_IRQHandler(void);
WEAK void Reserved134_IRQHandler(void);
WEAK void Reserved135_IRQHandler(void);
WEAK void Reserved136_IRQHandler(void);
WEAK void Reserved137_IRQHandler(void);
WEAK void Reserved138_IRQHandler(void);
WEAK void Reserved139_IRQHandler(void);
WEAK void Reserved140_IRQHandler(void);
WEAK void Reserved141_IRQHandler(void);
WEAK void Reserved142_IRQHandler(void);
WEAK void Reserved143_IRQHandler(void);
WEAK void LPI2C0_AON_IRQHandler(void);
WEAK void Reserved145_IRQHandler(void);
WEAK void LPUART0_AON_IRQHandler(void);
WEAK void Reserved147_IRQHandler(void);
WEAK void GPIO00_AON_IRQHandler(void);
WEAK void GPIO01_AON_IRQHandler(void);
WEAK void Reserved150_IRQHandler(void);
WEAK void Reserved151_IRQHandler(void);
WEAK void Reserved152_IRQHandler(void);
WEAK void Reserved153_IRQHandler(void);
WEAK void Reserved154_IRQHandler(void);
WEAK void LPCMP_IRQHandler(void);
WEAK void RTC_ALARM0_IRQHandler(void);
WEAK void RTC_ALARM1_IRQHandler(void);
WEAK void RTC_ALARM2_IRQHandler(void);
WEAK void RTC_WDT_IRQHandler(void);
WEAK void RTC_XTAL_IRQHandler(void);
WEAK void Reserved161_IRQHandler(void);
WEAK void Reserved162_IRQHandler(void);
WEAK void Reserved163_IRQHandler(void);
WEAK void KPP_IRQHandler(void);
WEAK void LPADC_AON_IRQHandler(void);
WEAK void Reserved166_IRQHandler(void);
WEAK void TMR0_AON_IRQHandler(void);
WEAK void TMR1_AON_IRQHandler(void);
WEAK void Reserved169_IRQHandler(void);
WEAK void LCSENSE_IRQHandler(void);
WEAK void LPTMR_AON_IRQHandler(void);
WEAK void Reserved172_IRQHandler(void);
WEAK void CMP0_AON_IRQHandler(void);
WEAK void ADVC_IRQHandler(void);
WEAK void Reserved175_IRQHandler(void);
WEAK void SGLCD_FRAME_AON_IRQHandler(void);
WEAK void SGLCD_FFAULT_AON_IRQHandler(void);

//*****************************************************************************
// Forward declaration of the driver IRQ handlers. These are aliased
// to the IntDefaultHandler, which is a 'forever' loop. When the driver
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//*****************************************************************************
void Reserved16_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CMC_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA0_CH0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA0_CH1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA0_CH2_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA0_CH3_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved22_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved23_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved24_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved25_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void ERM0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved27_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void FMU0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void GLIKEY0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void MBC0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void SCG0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved32_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved33_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void WUU0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved35_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved36_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved37_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved38_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved39_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved40_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved41_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPI2C0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPI2C1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPSPI0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPSPI1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved46_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPUART0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPUART1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved49_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved50_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved51_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved52_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved53_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CDOG0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CTIMER0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CTIMER1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CTIMER2_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved58_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved59_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved60_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved61_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved62_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved63_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved64_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved65_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved66_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved67_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved68_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved69_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void FREQME0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved71_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved72_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void OS_EVENT_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved74_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void UTICK0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void WWDT0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved77_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void ADC0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved79_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CMP0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved81_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved82_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved83_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved84_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved85_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved86_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void GPIO10_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void GPIO11_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void GPIO20_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void GPIO21_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void GPIO30_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void GPIO31_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved93_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved94_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved95_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void MU_A_TX_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void MU_A_RX_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void MU_A_INT_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CDOG1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved100_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved101_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved102_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved103_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved104_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved105_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved106_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved107_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved108_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved109_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved110_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved111_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA1_CH0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA1_CH1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA1_CH2_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA1_CH3_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved116_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved117_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved118_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved119_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved120_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved121_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved122_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved123_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved124_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved125_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PKC_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void SGI_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void TRNG_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void ERR_SGI_UDF_TRNG_PKC_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void HYPERVISOR_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved131_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved132_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved133_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved134_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved135_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved136_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved137_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved138_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved139_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved140_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved141_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved142_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved143_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPI2C0_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved145_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPUART0_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved147_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void GPIO00_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void GPIO01_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved150_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved151_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved152_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved153_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved154_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPCMP_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTC_ALARM0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTC_ALARM1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTC_ALARM2_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTC_WDT_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTC_XTAL_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved161_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved162_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved163_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void KPP_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPADC_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved166_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void TMR0_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void TMR1_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved169_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LCSENSE_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPTMR_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved172_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CMP0_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void ADVC_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved175_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void SGLCD_FRAME_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void SGLCD_FFAULT_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);

//*****************************************************************************
// The entry point for the application.
// __main() is the entry point for Redlib based applications
// main() is the entry point for Newlib based applications
//*****************************************************************************
#if defined (__REDLIB__)
extern void __main(void);
#endif
extern int main(void);

//*****************************************************************************
// External declaration for the pointer to the stack top from the Linker Script
//*****************************************************************************
extern void _vStackTop(void);
extern void _vStackBase(void);
//*****************************************************************************
#if defined (__cplusplus)
} // extern "C"
#endif
//*****************************************************************************
// The vector table.
// This relies on the linker script to place at correct location in memory.
//*****************************************************************************

extern void (* const g_pfnVectors[])(void);
extern void * __Vectors __attribute__ ((alias ("g_pfnVectors")));

__attribute__ ((used, section(".isr_vector")))
void (* const g_pfnVectors[])(void) = {
    // Core Level - CM33
    &_vStackTop,                       // The initial stack pointer
    ResetISR,                          // The reset handler
    NMI_Handler,                       // NMI Handler
    HardFault_Handler,                 // Hard Fault Handler
    0,                                 // Reserved
    BusFault_Handler,                  // Bus Fault Handler
    UsageFault_Handler,                // Usage Fault Handler
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    SVC_Handler,                       // SVCall Handler
    DebugMon_Handler,                  // Debug Monitor Handler
    0,                                 // Reserved
    PendSV_Handler,                    // PendSV Handler
    SysTick_Handler,                   // SysTick Handler

    // Chip Level - MCXL253_cm33
    Reserved16_IRQHandler,            // 16 : Reserved interrupt
    CMC_IRQHandler,                   // 17 : Core Mode Controller interrupt
    DMA0_CH0_IRQHandler,              // 18 : DMA3_0_CH0 error or transfer complete
    DMA0_CH1_IRQHandler,              // 19 : DMA3_0_CH1 error or transfer complete
    DMA0_CH2_IRQHandler,              // 20 : DMA3_0_CH2 error or transfer complete
    DMA0_CH3_IRQHandler,              // 21 : DMA3_0_CH3 error or transfer complete
    Reserved22_IRQHandler,            // 22 : Reserved interrupt
    Reserved23_IRQHandler,            // 23 : Reserved interrupt
    Reserved24_IRQHandler,            // 24 : Reserved interrupt
    Reserved25_IRQHandler,            // 25 : Reserved interrupt
    ERM0_IRQHandler,                  // 26 : ERM Single Bit error interrupt
    Reserved27_IRQHandler,            // 27 : Reserved interrupt
    FMU0_IRQHandler,                  // 28 : Flash Management Unit interrupt
    GLIKEY0_IRQHandler,               // 29 : GLIKEY Interrupt
    MBC0_IRQHandler,                  // 30 : MBC secure violation interrupt
    SCG0_IRQHandler,                  // 31 : System Clock Generator interrupt
    Reserved32_IRQHandler,            // 32 : Reserved interrupt
    Reserved33_IRQHandler,            // 33 : Reserved interrupt
    WUU0_IRQHandler,                  // 34 : Wake Up Unit interrupt
    Reserved35_IRQHandler,            // 35 : Reserved interrupt
    Reserved36_IRQHandler,            // 36 : Reserved interrupt
    Reserved37_IRQHandler,            // 37 : Reserved interrupt
    Reserved38_IRQHandler,            // 38 : Reserved interrupt
    Reserved39_IRQHandler,            // 39 : Reserved interrupt
    Reserved40_IRQHandler,            // 40 : Reserved interrupt
    Reserved41_IRQHandler,            // 41 : Reserved interrupt
    LPI2C0_IRQHandler,                // 42 : Low-Power Inter Integrated Circuit interrupt
    LPI2C1_IRQHandler,                // 43 : Low-Power Inter Integrated Circuit interrupt
    LPSPI0_IRQHandler,                // 44 : Low-Power Serial Peripheral Interface interrupt
    LPSPI1_IRQHandler,                // 45 : Low-Power Serial Peripheral Interface interrupt
    Reserved46_IRQHandler,            // 46 : Reserved interrupt
    LPUART0_IRQHandler,               // 47 : Low-Power Universal Asynchronous Receive/Transmit interrupt
    LPUART1_IRQHandler,               // 48 : Low-Power Universal Asynchronous Receive/Transmit interrupt
    Reserved49_IRQHandler,            // 49 : Reserved interrupt
    Reserved50_IRQHandler,            // 50 : Reserved interrupt
    Reserved51_IRQHandler,            // 51 : Reserved interrupt
    Reserved52_IRQHandler,            // 52 : Reserved interrupt
    Reserved53_IRQHandler,            // 53 : Reserved interrupt
    CDOG0_IRQHandler,                 // 54 : Code Watchdog Timer 0 interrupt
    CTIMER0_IRQHandler,               // 55 : Standard counter/timer 0 interrupt
    CTIMER1_IRQHandler,               // 56 : Standard counter/timer 1 interrupt
    CTIMER2_IRQHandler,               // 57 : Standard counter/timer 2 interrupt
    Reserved58_IRQHandler,            // 58 : Reserved interrupt
    Reserved59_IRQHandler,            // 59 : Reserved interrupt
    Reserved60_IRQHandler,            // 60 : Reserved interrupt
    Reserved61_IRQHandler,            // 61 : Reserved interrupt
    Reserved62_IRQHandler,            // 62 : Reserved interrupt
    Reserved63_IRQHandler,            // 63 : Reserved interrupt
    Reserved64_IRQHandler,            // 64 : Reserved interrupt
    Reserved65_IRQHandler,            // 65 : Reserved interrupt
    Reserved66_IRQHandler,            // 66 : Reserved interrupt
    Reserved67_IRQHandler,            // 67 : Reserved interrupt
    Reserved68_IRQHandler,            // 68 : Reserved interrupt
    Reserved69_IRQHandler,            // 69 : Reserved interrupt
    FREQME0_IRQHandler,               // 70 : Frequency Measurement interrupt
    Reserved71_IRQHandler,            // 71 : Reserved interrupt
    Reserved72_IRQHandler,            // 72 : Reserved interrupt
    OS_EVENT_IRQHandler,              // 73 : OS event timer interrupt
    Reserved74_IRQHandler,            // 74 : Reserved interrupt
    UTICK0_IRQHandler,                // 75 : Micro-Tick Timer interrupt
    WWDT0_IRQHandler,                 // 76 : Windowed Watchdog Timer 0 interrupt
    Reserved77_IRQHandler,            // 77 : Reserved interrupt
    ADC0_IRQHandler,                  // 78 : Analog-to-Digital Converter interrupt
    Reserved79_IRQHandler,            // 79 : Reserved interrupt
    CMP0_IRQHandler,                  // 80 : Comparator interrupt
    Reserved81_IRQHandler,            // 81 : Reserved interrupt
    Reserved82_IRQHandler,            // 82 : Reserved interrupt
    Reserved83_IRQHandler,            // 83 : Reserved interrupt
    Reserved84_IRQHandler,            // 84 : Reserved interrupt
    Reserved85_IRQHandler,            // 85 : Reserved interrupt
    Reserved86_IRQHandler,            // 86 : Reserved interrupt
    GPIO10_IRQHandler,                // 87 : General Purpose Input/Output 1 interrupt 0
    GPIO11_IRQHandler,                // 88 : General Purpose Input/Output 1 interrupt 1
    GPIO20_IRQHandler,                // 89 : General Purpose Input/Output 2 interrupt 0
    GPIO21_IRQHandler,                // 90 : General Purpose Input/Output 2 interrupt 1
    GPIO30_IRQHandler,                // 91 : General Purpose Input/Output 3 interrupt 0
    GPIO31_IRQHandler,                // 92 : General Purpose Input/Output 3 interrupt 1
    Reserved93_IRQHandler,            // 93 : Reserved interrupt
    Reserved94_IRQHandler,            // 94 : Reserved interrupt
    Reserved95_IRQHandler,            // 95 : Reserved interrupt
    MU_A_TX_IRQHandler,               // 96 : Ored tx interrupt to MUA
    MU_A_RX_IRQHandler,               // 97 : Ored rx interrupt to MUA
    MU_A_INT_IRQHandler,              // 98 : ORed general purpose interrupt request to MUA
    CDOG1_IRQHandler,                 // 99 : Code Watchdog Timer 1 interrupt
    Reserved100_IRQHandler,           // 100: Reserved interrupt
    Reserved101_IRQHandler,           // 101: Reserved interrupt
    Reserved102_IRQHandler,           // 102: Reserved interrupt
    Reserved103_IRQHandler,           // 103: Reserved interrupt
    Reserved104_IRQHandler,           // 104: Reserved interrupt
    Reserved105_IRQHandler,           // 105: Reserved interrupt
    Reserved106_IRQHandler,           // 106: Reserved interrupt
    Reserved107_IRQHandler,           // 107: Reserved interrupt
    Reserved108_IRQHandler,           // 108: Reserved interrupt
    Reserved109_IRQHandler,           // 109: Reserved interrupt
    Reserved110_IRQHandler,           // 110: Reserved interrupt
    Reserved111_IRQHandler,           // 111: Reserved interrupt
    DMA1_CH0_IRQHandler,              // 112: DMA3_1_CH0 error or transfer complete
    DMA1_CH1_IRQHandler,              // 113: DMA3_1_CH1 error or transfer complete
    DMA1_CH2_IRQHandler,              // 114: DMA3_1_CH2 error or transfer complete
    DMA1_CH3_IRQHandler,              // 115: DMA3_1_CH3 error or transfer complete
    Reserved116_IRQHandler,           // 116: Reserved interrupt
    Reserved117_IRQHandler,           // 117: Reserved interrupt
    Reserved118_IRQHandler,           // 118: Reserved interrupt
    Reserved119_IRQHandler,           // 119: Reserved interrupt
    Reserved120_IRQHandler,           // 120: Reserved interrupt
    Reserved121_IRQHandler,           // 121: Reserved interrupt
    Reserved122_IRQHandler,           // 122: Reserved interrupt
    Reserved123_IRQHandler,           // 123: Reserved interrupt
    Reserved124_IRQHandler,           // 124: Reserved interrupt
    Reserved125_IRQHandler,           // 125: Reserved interrupt
    PKC_IRQHandler,                   // 126: PKC interrupt
    SGI_IRQHandler,                   // 127: SGI interrupt
    TRNG_IRQHandler,                  // 128: TRNG interrupt
    ERR_SGI_UDF_TRNG_PKC_IRQHandler,  // 129: ORed Error Interrupt from SGI, UDF,TRNG and PKC
    HYPERVISOR_IRQHandler,            // 130: Hypervisor interrupt
    Reserved131_IRQHandler,           // 131: Reserved interrupt
    Reserved132_IRQHandler,           // 132: Reserved interrupt
    Reserved133_IRQHandler,           // 133: Reserved interrupt
    Reserved134_IRQHandler,           // 134: Reserved interrupt
    Reserved135_IRQHandler,           // 135: Reserved interrupt
    Reserved136_IRQHandler,           // 136: Reserved interrupt
    Reserved137_IRQHandler,           // 137: Reserved interrupt
    Reserved138_IRQHandler,           // 138: Reserved interrupt
    Reserved139_IRQHandler,           // 139: Reserved interrupt
    Reserved140_IRQHandler,           // 140: Reserved interrupt
    Reserved141_IRQHandler,           // 141: Reserved interrupt
    Reserved142_IRQHandler,           // 142: Reserved interrupt
    Reserved143_IRQHandler,           // 143: Reserved interrupt
    LPI2C0_AON_IRQHandler,            // 144: Low-Power Inter Integrated Circuit interrupt
    Reserved145_IRQHandler,           // 145: Reserved interrupt
    LPUART0_AON_IRQHandler,           // 146: Low-Power Universal Asynchronous Receive/Transmit interrupt
    Reserved147_IRQHandler,           // 147: Reserved interrupt
    GPIO00_AON_IRQHandler,            // 148: General Purpose Input/Output interrupt 0
    GPIO01_AON_IRQHandler,            // 149: General Purpose Input/Output interrupt 1
    Reserved150_IRQHandler,           // 150: Reserved interrupt
    Reserved151_IRQHandler,           // 151: Reserved interrupt
    Reserved152_IRQHandler,           // 152: Reserved interrupt
    Reserved153_IRQHandler,           // 153: Reserved interrupt
    Reserved154_IRQHandler,           // 154: Reserved interrupt
    LPCMP_IRQHandler,                 // 155: Comparator
    RTC_ALARM0_IRQHandler,            // 156: RTC alarm 0
    RTC_ALARM1_IRQHandler,            // 157: RTC alarm 1
    RTC_ALARM2_IRQHandler,            // 158: RTC alarm 2
    RTC_WDT_IRQHandler,               // 159: RTC watchdog
    RTC_XTAL_IRQHandler,              // 160: RTC XTAL Fail
    Reserved161_IRQHandler,           // 161: Reserved interrupt
    Reserved162_IRQHandler,           // 162: Reserved interrupt
    Reserved163_IRQHandler,           // 163: Reserved interrupt
    KPP_IRQHandler,                   // 164: Keypad Interrupt
    LPADC_AON_IRQHandler,             // 165: ADC Summary Interrupt
    Reserved166_IRQHandler,           // 166: Reserved interrupt
    TMR0_AON_IRQHandler,              // 167: ORed QTMR Interrupts
    TMR1_AON_IRQHandler,              // 168: ORed QTMR Interrupts
    Reserved169_IRQHandler,           // 169: Reserved interrupt
    LCSENSE_IRQHandler,               // 170: LCSense Fault/Tamper Interrupt
    LPTMR_AON_IRQHandler,             // 171: Low Power Timer 0 interrupt
    Reserved172_IRQHandler,           // 172: Reserved interrupt
    CMP0_AON_IRQHandler,              // 173: Comparator interrupt
    ADVC_IRQHandler,                  // 174: ADVC_2.0 Controller Interrupt
    Reserved175_IRQHandler,           // 175: Reserved interrupt
    SGLCD_FRAME_AON_IRQHandler,       // 176: Frame Update Interrupt
    SGLCD_FFAULT_AON_IRQHandler,      // 177: Fault Detect Interrupt
}; /* End of g_pfnVectors */

//*****************************************************************************
// Functions to carry out the initialization of RW and BSS data sections. These
// are written as separate functions rather than being inlined within the
// ResetISR() function in order to cope with MCUs with multiple banks of
// memory.
//*****************************************************************************
__attribute__ ((section(".after_vectors.init_data")))
void data_init(unsigned int romstart, unsigned int start, unsigned int len) {
    unsigned int *pulDest = (unsigned int*) start;
    unsigned int *pulSrc = (unsigned int*) romstart;
    unsigned int loop;
    for (loop = 0; loop < len; loop = loop + 4)
        *pulDest++ = *pulSrc++;
}

__attribute__ ((section(".after_vectors.init_bss")))
void bss_init(unsigned int start, unsigned int len) {
    unsigned int *pulDest = (unsigned int*) start;
    unsigned int loop;
    for (loop = 0; loop < len; loop = loop + 4)
        *pulDest++ = 0;
}

//*****************************************************************************
// The following symbols are constructs generated by the linker, indicating
// the location of various points in the "Global Section Table". This table is
// created by the linker via the Code Red managed linker script mechanism. It
// contains the load address, execution address and length of each RW data
// section and the execution and length of each BSS (zero initialized) section.
//*****************************************************************************
extern unsigned int __data_section_table;
extern unsigned int __data_section_table_end;
extern unsigned int __bss_section_table;
extern unsigned int __bss_section_table_end;

//*****************************************************************************
// Reset entry point for your code.
// Sets up a simple runtime environment and initializes the C/C++
// library.
//*****************************************************************************
__attribute__ ((naked, section(".after_vectors.reset")))
void ResetISR(void) {
    // Disable interrupts
    __asm volatile ("cpsid i");
    // Config VTOR & MSPLIM register
    __asm volatile ("LDR R0, =0xE000ED08  \n"
                    "STR %0, [R0]         \n"
                    "LDR R1, [%0]         \n"
                    "MSR MSP, R1          \n"
                    "MSR MSPLIM, %1       \n"
                    :
                    : "r"(g_pfnVectors), "r"(_vStackBase)
                    : "r0", "r1");

#if defined (__USE_CMSIS)
// If __USE_CMSIS defined, then call CMSIS SystemInit code
    SystemInit();

#endif // (__USE_CMSIS)

    //
    // Copy the data sections from flash to SRAM.
    //
    unsigned int LoadAddr, ExeAddr, SectionLen;
    unsigned int *SectionTableAddr;

    // Load base address of Global Section Table
    SectionTableAddr = &__data_section_table;

    // Copy the data sections from flash to SRAM.
    while (SectionTableAddr < &__data_section_table_end) {
        LoadAddr = *SectionTableAddr++;
        ExeAddr = *SectionTableAddr++;
        SectionLen = *SectionTableAddr++;
        data_init(LoadAddr, ExeAddr, SectionLen);
    }

    // At this point, SectionTableAddr = &__bss_section_table;
    // Zero fill the bss segment
    while (SectionTableAddr < &__bss_section_table_end) {
        ExeAddr = *SectionTableAddr++;
        SectionLen = *SectionTableAddr++;
        bss_init(ExeAddr, SectionLen);
    }

#if !defined (__USE_CMSIS)
// Assume that if __USE_CMSIS defined, then CMSIS SystemInit code
// will setup the VTOR register

    // Check to see if we are running the code from a non-zero
    // address (eg RAM, external flash), in which case we need
    // to modify the VTOR register to tell the CPU that the
    // vector table is located at a non-0x0 address.
    unsigned int * pSCB_VTOR = (unsigned int *) 0xE000ED08;
    if ((unsigned int *)g_pfnVectors!=(unsigned int *) 0x00000000) {
        *pSCB_VTOR = (unsigned int)g_pfnVectors;
    }
#endif // (__USE_CMSIS)
#if defined (__cplusplus)
    //
    // Call C++ library initialisation
    //
    __libc_init_array();
#endif

    // Reenable interrupts
    __asm volatile ("cpsie i");

#if defined (__REDLIB__)
    // Call the Redlib library, which in turn calls main()
    __main();
#else
    main();
#endif

    //
    // main() shouldn't return, but if it does, we'll just enter an infinite loop
    //
    while (1) {
        ;
    }
}

//*****************************************************************************
// Default core exception handlers. Override the ones here by defining your own
// handler routines in your application code.
//*****************************************************************************
WEAK_AV void NMI_Handler(void)
{ while(1) {}
}

WEAK_AV void HardFault_Handler(void)
{ while(1) {}
}

WEAK_AV void BusFault_Handler(void)
{ while(1) {}
}

WEAK_AV void UsageFault_Handler(void)
{ while(1) {}
}

WEAK_AV void SVC_Handler(void)
{ while(1) {}
}

WEAK_AV void DebugMon_Handler(void)
{ while(1) {}
}

WEAK_AV void PendSV_Handler(void)
{ while(1) {}
}

WEAK_AV void SysTick_Handler(void)
{ while(1) {}
}

//*****************************************************************************
// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.
//*****************************************************************************
WEAK_AV void IntDefaultHandler(void)
{ while(1) {}
}

//*****************************************************************************
// Default application exception handlers. Override the ones here by defining
// your own handler routines in your application code. These routines call
// driver exception handlers or IntDefaultHandler() if no driver exception
// handler is included.
//*****************************************************************************
WEAK void Reserved16_IRQHandler(void)
{   Reserved16_DriverIRQHandler();
}

WEAK void CMC_IRQHandler(void)
{   CMC_DriverIRQHandler();
}

WEAK void DMA0_CH0_IRQHandler(void)
{   DMA0_CH0_DriverIRQHandler();
}

WEAK void DMA0_CH1_IRQHandler(void)
{   DMA0_CH1_DriverIRQHandler();
}

WEAK void DMA0_CH2_IRQHandler(void)
{   DMA0_CH2_DriverIRQHandler();
}

WEAK void DMA0_CH3_IRQHandler(void)
{   DMA0_CH3_DriverIRQHandler();
}

WEAK void Reserved22_IRQHandler(void)
{   Reserved22_DriverIRQHandler();
}

WEAK void Reserved23_IRQHandler(void)
{   Reserved23_DriverIRQHandler();
}

WEAK void Reserved24_IRQHandler(void)
{   Reserved24_DriverIRQHandler();
}

WEAK void Reserved25_IRQHandler(void)
{   Reserved25_DriverIRQHandler();
}

WEAK void ERM0_IRQHandler(void)
{   ERM0_DriverIRQHandler();
}

WEAK void Reserved27_IRQHandler(void)
{   Reserved27_DriverIRQHandler();
}

WEAK void FMU0_IRQHandler(void)
{   FMU0_DriverIRQHandler();
}

WEAK void GLIKEY0_IRQHandler(void)
{   GLIKEY0_DriverIRQHandler();
}

WEAK void MBC0_IRQHandler(void)
{   MBC0_DriverIRQHandler();
}

WEAK void SCG0_IRQHandler(void)
{   SCG0_DriverIRQHandler();
}

WEAK void Reserved32_IRQHandler(void)
{   Reserved32_DriverIRQHandler();
}

WEAK void Reserved33_IRQHandler(void)
{   Reserved33_DriverIRQHandler();
}

WEAK void WUU0_IRQHandler(void)
{   WUU0_DriverIRQHandler();
}

WEAK void Reserved35_IRQHandler(void)
{   Reserved35_DriverIRQHandler();
}

WEAK void Reserved36_IRQHandler(void)
{   Reserved36_DriverIRQHandler();
}

WEAK void Reserved37_IRQHandler(void)
{   Reserved37_DriverIRQHandler();
}

WEAK void Reserved38_IRQHandler(void)
{   Reserved38_DriverIRQHandler();
}

WEAK void Reserved39_IRQHandler(void)
{   Reserved39_DriverIRQHandler();
}

WEAK void Reserved40_IRQHandler(void)
{   Reserved40_DriverIRQHandler();
}

WEAK void Reserved41_IRQHandler(void)
{   Reserved41_DriverIRQHandler();
}

WEAK void LPI2C0_IRQHandler(void)
{   LPI2C0_DriverIRQHandler();
}

WEAK void LPI2C1_IRQHandler(void)
{   LPI2C1_DriverIRQHandler();
}

WEAK void LPSPI0_IRQHandler(void)
{   LPSPI0_DriverIRQHandler();
}

WEAK void LPSPI1_IRQHandler(void)
{   LPSPI1_DriverIRQHandler();
}

WEAK void Reserved46_IRQHandler(void)
{   Reserved46_DriverIRQHandler();
}

WEAK void LPUART0_IRQHandler(void)
{   LPUART0_DriverIRQHandler();
}

WEAK void LPUART1_IRQHandler(void)
{   LPUART1_DriverIRQHandler();
}

WEAK void Reserved49_IRQHandler(void)
{   Reserved49_DriverIRQHandler();
}

WEAK void Reserved50_IRQHandler(void)
{   Reserved50_DriverIRQHandler();
}

WEAK void Reserved51_IRQHandler(void)
{   Reserved51_DriverIRQHandler();
}

WEAK void Reserved52_IRQHandler(void)
{   Reserved52_DriverIRQHandler();
}

WEAK void Reserved53_IRQHandler(void)
{   Reserved53_DriverIRQHandler();
}

WEAK void CDOG0_IRQHandler(void)
{   CDOG0_DriverIRQHandler();
}

WEAK void CTIMER0_IRQHandler(void)
{   CTIMER0_DriverIRQHandler();
}

WEAK void CTIMER1_IRQHandler(void)
{   CTIMER1_DriverIRQHandler();
}

WEAK void CTIMER2_IRQHandler(void)
{   CTIMER2_DriverIRQHandler();
}

WEAK void Reserved58_IRQHandler(void)
{   Reserved58_DriverIRQHandler();
}

WEAK void Reserved59_IRQHandler(void)
{   Reserved59_DriverIRQHandler();
}

WEAK void Reserved60_IRQHandler(void)
{   Reserved60_DriverIRQHandler();
}

WEAK void Reserved61_IRQHandler(void)
{   Reserved61_DriverIRQHandler();
}

WEAK void Reserved62_IRQHandler(void)
{   Reserved62_DriverIRQHandler();
}

WEAK void Reserved63_IRQHandler(void)
{   Reserved63_DriverIRQHandler();
}

WEAK void Reserved64_IRQHandler(void)
{   Reserved64_DriverIRQHandler();
}

WEAK void Reserved65_IRQHandler(void)
{   Reserved65_DriverIRQHandler();
}

WEAK void Reserved66_IRQHandler(void)
{   Reserved66_DriverIRQHandler();
}

WEAK void Reserved67_IRQHandler(void)
{   Reserved67_DriverIRQHandler();
}

WEAK void Reserved68_IRQHandler(void)
{   Reserved68_DriverIRQHandler();
}

WEAK void Reserved69_IRQHandler(void)
{   Reserved69_DriverIRQHandler();
}

WEAK void FREQME0_IRQHandler(void)
{   FREQME0_DriverIRQHandler();
}

WEAK void Reserved71_IRQHandler(void)
{   Reserved71_DriverIRQHandler();
}

WEAK void Reserved72_IRQHandler(void)
{   Reserved72_DriverIRQHandler();
}

WEAK void OS_EVENT_IRQHandler(void)
{   OS_EVENT_DriverIRQHandler();
}

WEAK void Reserved74_IRQHandler(void)
{   Reserved74_DriverIRQHandler();
}

WEAK void UTICK0_IRQHandler(void)
{   UTICK0_DriverIRQHandler();
}

WEAK void WWDT0_IRQHandler(void)
{   WWDT0_DriverIRQHandler();
}

WEAK void Reserved77_IRQHandler(void)
{   Reserved77_DriverIRQHandler();
}

WEAK void ADC0_IRQHandler(void)
{   ADC0_DriverIRQHandler();
}

WEAK void Reserved79_IRQHandler(void)
{   Reserved79_DriverIRQHandler();
}

WEAK void CMP0_IRQHandler(void)
{   CMP0_DriverIRQHandler();
}

WEAK void Reserved81_IRQHandler(void)
{   Reserved81_DriverIRQHandler();
}

WEAK void Reserved82_IRQHandler(void)
{   Reserved82_DriverIRQHandler();
}

WEAK void Reserved83_IRQHandler(void)
{   Reserved83_DriverIRQHandler();
}

WEAK void Reserved84_IRQHandler(void)
{   Reserved84_DriverIRQHandler();
}

WEAK void Reserved85_IRQHandler(void)
{   Reserved85_DriverIRQHandler();
}

WEAK void Reserved86_IRQHandler(void)
{   Reserved86_DriverIRQHandler();
}

WEAK void GPIO10_IRQHandler(void)
{   GPIO10_DriverIRQHandler();
}

WEAK void GPIO11_IRQHandler(void)
{   GPIO11_DriverIRQHandler();
}

WEAK void GPIO20_IRQHandler(void)
{   GPIO20_DriverIRQHandler();
}

WEAK void GPIO21_IRQHandler(void)
{   GPIO21_DriverIRQHandler();
}

WEAK void GPIO30_IRQHandler(void)
{   GPIO30_DriverIRQHandler();
}

WEAK void GPIO31_IRQHandler(void)
{   GPIO31_DriverIRQHandler();
}

WEAK void Reserved93_IRQHandler(void)
{   Reserved93_DriverIRQHandler();
}

WEAK void Reserved94_IRQHandler(void)
{   Reserved94_DriverIRQHandler();
}

WEAK void Reserved95_IRQHandler(void)
{   Reserved95_DriverIRQHandler();
}

WEAK void MU_A_TX_IRQHandler(void)
{   MU_A_TX_DriverIRQHandler();
}

WEAK void MU_A_RX_IRQHandler(void)
{   MU_A_RX_DriverIRQHandler();
}

WEAK void MU_A_INT_IRQHandler(void)
{   MU_A_INT_DriverIRQHandler();
}

WEAK void CDOG1_IRQHandler(void)
{   CDOG1_DriverIRQHandler();
}

WEAK void Reserved100_IRQHandler(void)
{   Reserved100_DriverIRQHandler();
}

WEAK void Reserved101_IRQHandler(void)
{   Reserved101_DriverIRQHandler();
}

WEAK void Reserved102_IRQHandler(void)
{   Reserved102_DriverIRQHandler();
}

WEAK void Reserved103_IRQHandler(void)
{   Reserved103_DriverIRQHandler();
}

WEAK void Reserved104_IRQHandler(void)
{   Reserved104_DriverIRQHandler();
}

WEAK void Reserved105_IRQHandler(void)
{   Reserved105_DriverIRQHandler();
}

WEAK void Reserved106_IRQHandler(void)
{   Reserved106_DriverIRQHandler();
}

WEAK void Reserved107_IRQHandler(void)
{   Reserved107_DriverIRQHandler();
}

WEAK void Reserved108_IRQHandler(void)
{   Reserved108_DriverIRQHandler();
}

WEAK void Reserved109_IRQHandler(void)
{   Reserved109_DriverIRQHandler();
}

WEAK void Reserved110_IRQHandler(void)
{   Reserved110_DriverIRQHandler();
}

WEAK void Reserved111_IRQHandler(void)
{   Reserved111_DriverIRQHandler();
}

WEAK void DMA1_CH0_IRQHandler(void)
{   DMA1_CH0_DriverIRQHandler();
}

WEAK void DMA1_CH1_IRQHandler(void)
{   DMA1_CH1_DriverIRQHandler();
}

WEAK void DMA1_CH2_IRQHandler(void)
{   DMA1_CH2_DriverIRQHandler();
}

WEAK void DMA1_CH3_IRQHandler(void)
{   DMA1_CH3_DriverIRQHandler();
}

WEAK void Reserved116_IRQHandler(void)
{   Reserved116_DriverIRQHandler();
}

WEAK void Reserved117_IRQHandler(void)
{   Reserved117_DriverIRQHandler();
}

WEAK void Reserved118_IRQHandler(void)
{   Reserved118_DriverIRQHandler();
}

WEAK void Reserved119_IRQHandler(void)
{   Reserved119_DriverIRQHandler();
}

WEAK void Reserved120_IRQHandler(void)
{   Reserved120_DriverIRQHandler();
}

WEAK void Reserved121_IRQHandler(void)
{   Reserved121_DriverIRQHandler();
}

WEAK void Reserved122_IRQHandler(void)
{   Reserved122_DriverIRQHandler();
}

WEAK void Reserved123_IRQHandler(void)
{   Reserved123_DriverIRQHandler();
}

WEAK void Reserved124_IRQHandler(void)
{   Reserved124_DriverIRQHandler();
}

WEAK void Reserved125_IRQHandler(void)
{   Reserved125_DriverIRQHandler();
}

WEAK void PKC_IRQHandler(void)
{   PKC_DriverIRQHandler();
}

WEAK void SGI_IRQHandler(void)
{   SGI_DriverIRQHandler();
}

WEAK void TRNG_IRQHandler(void)
{   TRNG_DriverIRQHandler();
}

WEAK void ERR_SGI_UDF_TRNG_PKC_IRQHandler(void)
{   ERR_SGI_UDF_TRNG_PKC_DriverIRQHandler();
}

WEAK void HYPERVISOR_IRQHandler(void)
{   HYPERVISOR_DriverIRQHandler();
}

WEAK void Reserved131_IRQHandler(void)
{   Reserved131_DriverIRQHandler();
}

WEAK void Reserved132_IRQHandler(void)
{   Reserved132_DriverIRQHandler();
}

WEAK void Reserved133_IRQHandler(void)
{   Reserved133_DriverIRQHandler();
}

WEAK void Reserved134_IRQHandler(void)
{   Reserved134_DriverIRQHandler();
}

WEAK void Reserved135_IRQHandler(void)
{   Reserved135_DriverIRQHandler();
}

WEAK void Reserved136_IRQHandler(void)
{   Reserved136_DriverIRQHandler();
}

WEAK void Reserved137_IRQHandler(void)
{   Reserved137_DriverIRQHandler();
}

WEAK void Reserved138_IRQHandler(void)
{   Reserved138_DriverIRQHandler();
}

WEAK void Reserved139_IRQHandler(void)
{   Reserved139_DriverIRQHandler();
}

WEAK void Reserved140_IRQHandler(void)
{   Reserved140_DriverIRQHandler();
}

WEAK void Reserved141_IRQHandler(void)
{   Reserved141_DriverIRQHandler();
}

WEAK void Reserved142_IRQHandler(void)
{   Reserved142_DriverIRQHandler();
}

WEAK void Reserved143_IRQHandler(void)
{   Reserved143_DriverIRQHandler();
}

WEAK void LPI2C0_AON_IRQHandler(void)
{   LPI2C0_AON_DriverIRQHandler();
}

WEAK void Reserved145_IRQHandler(void)
{   Reserved145_DriverIRQHandler();
}

WEAK void LPUART0_AON_IRQHandler(void)
{   LPUART0_AON_DriverIRQHandler();
}

WEAK void Reserved147_IRQHandler(void)
{   Reserved147_DriverIRQHandler();
}

WEAK void GPIO00_AON_IRQHandler(void)
{   GPIO00_AON_DriverIRQHandler();
}

WEAK void GPIO01_AON_IRQHandler(void)
{   GPIO01_AON_DriverIRQHandler();
}

WEAK void Reserved150_IRQHandler(void)
{   Reserved150_DriverIRQHandler();
}

WEAK void Reserved151_IRQHandler(void)
{   Reserved151_DriverIRQHandler();
}

WEAK void Reserved152_IRQHandler(void)
{   Reserved152_DriverIRQHandler();
}

WEAK void Reserved153_IRQHandler(void)
{   Reserved153_DriverIRQHandler();
}

WEAK void Reserved154_IRQHandler(void)
{   Reserved154_DriverIRQHandler();
}

WEAK void LPCMP_IRQHandler(void)
{   LPCMP_DriverIRQHandler();
}

WEAK void RTC_ALARM0_IRQHandler(void)
{   RTC_ALARM0_DriverIRQHandler();
}

WEAK void RTC_ALARM1_IRQHandler(void)
{   RTC_ALARM1_DriverIRQHandler();
}

WEAK void RTC_ALARM2_IRQHandler(void)
{   RTC_ALARM2_DriverIRQHandler();
}

WEAK void RTC_WDT_IRQHandler(void)
{   RTC_WDT_DriverIRQHandler();
}

WEAK void RTC_XTAL_IRQHandler(void)
{   RTC_XTAL_DriverIRQHandler();
}

WEAK void Reserved161_IRQHandler(void)
{   Reserved161_DriverIRQHandler();
}

WEAK void Reserved162_IRQHandler(void)
{   Reserved162_DriverIRQHandler();
}

WEAK void Reserved163_IRQHandler(void)
{   Reserved163_DriverIRQHandler();
}

WEAK void KPP_IRQHandler(void)
{   KPP_DriverIRQHandler();
}

WEAK void LPADC_AON_IRQHandler(void)
{   LPADC_AON_DriverIRQHandler();
}

WEAK void Reserved166_IRQHandler(void)
{   Reserved166_DriverIRQHandler();
}

WEAK void TMR0_AON_IRQHandler(void)
{   TMR0_AON_DriverIRQHandler();
}

WEAK void TMR1_AON_IRQHandler(void)
{   TMR1_AON_DriverIRQHandler();
}

WEAK void Reserved169_IRQHandler(void)
{   Reserved169_DriverIRQHandler();
}

WEAK void LCSENSE_IRQHandler(void)
{   LCSENSE_DriverIRQHandler();
}

WEAK void LPTMR_AON_IRQHandler(void)
{   LPTMR_AON_DriverIRQHandler();
}

WEAK void Reserved172_IRQHandler(void)
{   Reserved172_DriverIRQHandler();
}

WEAK void CMP0_AON_IRQHandler(void)
{   CMP0_AON_DriverIRQHandler();
}

WEAK void ADVC_IRQHandler(void)
{   ADVC_DriverIRQHandler();
}

WEAK void Reserved175_IRQHandler(void)
{   Reserved175_DriverIRQHandler();
}

WEAK void SGLCD_FRAME_AON_IRQHandler(void)
{   SGLCD_FRAME_AON_DriverIRQHandler();
}

WEAK void SGLCD_FFAULT_AON_IRQHandler(void)
{   SGLCD_FFAULT_AON_DriverIRQHandler();
}

//*****************************************************************************

#if defined (DEBUG)
#pragma GCC pop_options
#endif // (DEBUG)
