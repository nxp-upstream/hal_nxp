//*****************************************************************************
// MCXL253_cm0plus startup code for use with MCUXpresso IDE
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
#include <NXP/crp.h>
__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;

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
WEAK void HardFault_Handler(void);
WEAK void SVC_Handler(void);
WEAK void PendSV_Handler(void);
WEAK void SysTick_Handler(void);
WEAK void IntDefaultHandler(void);

//*****************************************************************************
// Forward declaration of the application IRQ handlers. When the application
// defines a handler (with the same name), this will automatically take
// precedence over weak definitions below
//*****************************************************************************
WEAK void Reserved16_IRQHandler(void);
WEAK void LPI2C0_AON_IRQHandler(void);
WEAK void Reserved18_IRQHandler(void);
WEAK void LPUART0_AON_IRQHandler(void);
WEAK void Reserved20_IRQHandler(void);
WEAK void GPIO00_AON_IRQHandler(void);
WEAK void Reserved22_IRQHandler(void);
WEAK void MU_B_TX_IRQHandler(void);
WEAK void MU_B_RX_IRQHandler(void);
WEAK void MU_B_INT_IRQHandler(void);
WEAK void SMM_IRQHandler(void);
WEAK void SNS_IRQHandler(void);
WEAK void LPCMP_IRQHandler(void);
WEAK void RTC_ALARM0_IRQHandler(void);
WEAK void RTC_ALARM1_IRQHandler(void);
WEAK void RTC_ALARM2_IRQHandler(void);
WEAK void RTC_WDT_IRQHandler(void);
WEAK void RTC_XTAL_IRQHandler(void);
WEAK void SMM_EXT_IRQHandler(void);
WEAK void CGU_IRQHandler(void);
WEAK void PMU_IRQHandler(void);
WEAK void KPP_IRQHandler(void);
WEAK void LPADC_AON_IRQHandler(void);
WEAK void SGLCD_AON_IRQHandler(void);
WEAK void TMR0_AON_IRQHandler(void);
WEAK void TMR1_AON_IRQHandler(void);
WEAK void Reserved42_IRQHandler(void);
WEAK void LCSENSE_IRQHandler(void);
WEAK void LPTMR_AON_IRQHandler(void);
WEAK void Reserved45_IRQHandler(void);
WEAK void CMP0_AON_IRQHandler(void);
WEAK void ADVC_IRQHandler(void);

//*****************************************************************************
// Forward declaration of the driver IRQ handlers. These are aliased
// to the IntDefaultHandler, which is a 'forever' loop. When the driver
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//*****************************************************************************
void Reserved16_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPI2C0_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved18_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPUART0_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved20_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void GPIO00_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved22_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void MU_B_TX_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void MU_B_RX_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void MU_B_INT_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void SMM_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void SNS_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPCMP_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTC_ALARM0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTC_ALARM1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTC_ALARM2_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTC_WDT_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTC_XTAL_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void SMM_EXT_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CGU_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PMU_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void KPP_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPADC_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void SGLCD_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void TMR0_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void TMR1_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved42_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LCSENSE_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPTMR_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved45_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CMP0_AON_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void ADVC_DriverIRQHandler(void) ALIAS(IntDefaultHandler);

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
    // Core Level - CM0P
    &_vStackTop,                       // The initial stack pointer
    ResetISR,                          // The reset handler
    0,                                 // Reserved
    HardFault_Handler,                 // Hard Fault Handler
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    SVC_Handler,                       // SVCall Handler
    0,                                 // Reserved
    0,                                 // Reserved
    PendSV_Handler,                    // PendSV Handler
    SysTick_Handler,                   // SysTick Handler

    // Chip Level - MCXL253_cm0plus
    Reserved16_IRQHandler,   // 16: Reserved interrupt
    LPI2C0_AON_IRQHandler,   // 17: Low-Power Inter Integrated Circuit interrupt
    Reserved18_IRQHandler,   // 18: Reserved interrupt
    LPUART0_AON_IRQHandler,  // 19: Low-Power Universal Asynchronous Receive/Transmit interrupt
    Reserved20_IRQHandler,   // 20: Reserved interrupt
    GPIO00_AON_IRQHandler,   // 21: General Purpose Input/Output interrupt 0
    Reserved22_IRQHandler,   // 22: Reserved interrupt
    MU_B_TX_IRQHandler,      // 23: Ored tx interrupt to MUB
    MU_B_RX_IRQHandler,      // 24: Ored rx interrupt to MUB
    MU_B_INT_IRQHandler,     // 25: ORed general purpose interrupt request to MUB
    SMM_IRQHandler,          // 26: SMM IRQ
    SNS_IRQHandler,          // 27: SNS - first fail test finish
    LPCMP_IRQHandler,        // 28: Comparator
    RTC_ALARM0_IRQHandler,   // 29: RTC alarm 0
    RTC_ALARM1_IRQHandler,   // 30: RTC alarm 1
    RTC_ALARM2_IRQHandler,   // 31: RTC alarm 2
    RTC_WDT_IRQHandler,      // 32: RTC watchdog
    RTC_XTAL_IRQHandler,     // 33: RTC XTAL Fail
    SMM_EXT_IRQHandler,      // 34: External interrupt
    CGU_IRQHandler,          // 35: CGU IRQ
    PMU_IRQHandler,          // 36: PMU IRQ
    KPP_IRQHandler,          // 37: Keypad Interrupt
    LPADC_AON_IRQHandler,    // 38: Analog-to-Digital Converter interrupt
    SGLCD_AON_IRQHandler,    // 39: SLCD frame start interrupt
    TMR0_AON_IRQHandler,     // 40: ORed QTMR Interrupts
    TMR1_AON_IRQHandler,     // 41: ORed QTMR Interrupts
    Reserved42_IRQHandler,   // 42: Reserved interrupt
    LCSENSE_IRQHandler,      // 43: LCSense Fault/Tamper Interrupt
    LPTMR_AON_IRQHandler,    // 44: Low Power Timer 0 interrupt
    Reserved45_IRQHandler,   // 45: Reserved interrupt
    CMP0_AON_IRQHandler,     // 46: Comparator interrupt
    ADVC_IRQHandler,         // 47: ADVC_2.0 Controller Interrupt
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
WEAK_AV void HardFault_Handler(void)
{ while(1) {}
}

WEAK_AV void SVC_Handler(void)
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
WEAK_AV void Reserved16_IRQHandler(void)
{   Reserved16_DriverIRQHandler();
}

WEAK_AV void LPI2C0_AON_IRQHandler(void)
{   LPI2C0_AON_DriverIRQHandler();
}

WEAK_AV void Reserved18_IRQHandler(void)
{   Reserved18_DriverIRQHandler();
}

WEAK_AV void LPUART0_AON_IRQHandler(void)
{   LPUART0_AON_DriverIRQHandler();
}

WEAK_AV void Reserved20_IRQHandler(void)
{   Reserved20_DriverIRQHandler();
}

WEAK_AV void GPIO00_AON_IRQHandler(void)
{   GPIO00_AON_DriverIRQHandler();
}

WEAK_AV void Reserved22_IRQHandler(void)
{   Reserved22_DriverIRQHandler();
}

WEAK_AV void MU_B_TX_IRQHandler(void)
{   MU_B_TX_DriverIRQHandler();
}

WEAK_AV void MU_B_RX_IRQHandler(void)
{   MU_B_RX_DriverIRQHandler();
}

WEAK_AV void MU_B_INT_IRQHandler(void)
{   MU_B_INT_DriverIRQHandler();
}

WEAK_AV void SMM_IRQHandler(void)
{   SMM_DriverIRQHandler();
}

WEAK_AV void SNS_IRQHandler(void)
{   SNS_DriverIRQHandler();
}

WEAK_AV void LPCMP_IRQHandler(void)
{   LPCMP_DriverIRQHandler();
}

WEAK_AV void RTC_ALARM0_IRQHandler(void)
{   RTC_ALARM0_DriverIRQHandler();
}

WEAK_AV void RTC_ALARM1_IRQHandler(void)
{   RTC_ALARM1_DriverIRQHandler();
}

WEAK_AV void RTC_ALARM2_IRQHandler(void)
{   RTC_ALARM2_DriverIRQHandler();
}

WEAK_AV void RTC_WDT_IRQHandler(void)
{   RTC_WDT_DriverIRQHandler();
}

WEAK_AV void RTC_XTAL_IRQHandler(void)
{   RTC_XTAL_DriverIRQHandler();
}

WEAK_AV void SMM_EXT_IRQHandler(void)
{   SMM_EXT_DriverIRQHandler();
}

WEAK_AV void CGU_IRQHandler(void)
{   CGU_DriverIRQHandler();
}

WEAK_AV void PMU_IRQHandler(void)
{   PMU_DriverIRQHandler();
}

WEAK_AV void KPP_IRQHandler(void)
{   KPP_DriverIRQHandler();
}

WEAK_AV void LPADC_AON_IRQHandler(void)
{   LPADC_AON_DriverIRQHandler();
}

WEAK_AV void SGLCD_AON_IRQHandler(void)
{   SGLCD_AON_DriverIRQHandler();
}

WEAK_AV void TMR0_AON_IRQHandler(void)
{   TMR0_AON_DriverIRQHandler();
}

WEAK_AV void TMR1_AON_IRQHandler(void)
{   TMR1_AON_DriverIRQHandler();
}

WEAK_AV void Reserved42_IRQHandler(void)
{   Reserved42_DriverIRQHandler();
}

WEAK_AV void LCSENSE_IRQHandler(void)
{   LCSENSE_DriverIRQHandler();
}

WEAK_AV void LPTMR_AON_IRQHandler(void)
{   LPTMR_AON_DriverIRQHandler();
}

WEAK_AV void Reserved45_IRQHandler(void)
{   Reserved45_DriverIRQHandler();
}

WEAK_AV void CMP0_AON_IRQHandler(void)
{   CMP0_AON_DriverIRQHandler();
}

WEAK_AV void ADVC_IRQHandler(void)
{   ADVC_DriverIRQHandler();
}

//*****************************************************************************

#if defined (DEBUG)
#pragma GCC pop_options
#endif // (DEBUG)
