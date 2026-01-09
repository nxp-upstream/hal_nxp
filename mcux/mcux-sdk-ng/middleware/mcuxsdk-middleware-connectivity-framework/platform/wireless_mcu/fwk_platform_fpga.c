/* -------------------------------------------------------------------------- */
/*                             Copyright 2023 NXP                             */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#if defined(HDI_MODE) && (HDI_MODE == 1)
#include "fsl_port.h"
#include "hdi.h"
#endif

#if defined(gUseIpcTransport_d) && (gUseIpcTransport_d == 1)
#include "ipc.h"
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */

#if defined(gUseIpcTransport_d) && (gUseIpcTransport_d == 1)
RPMSG_HANDLE_DEFINE(s_IpcRpmsgHandle);
static const hal_rpmsg_config_t ipcRpmsgConfig = {
    .local_addr  = 60,
    .remote_addr = 50,
};
#endif /* gUseIpcTransport_d */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

#if defined(HDI_MODE) && (HDI_MODE == 1)
static void BOARD_InitPinsSPI0(void);
static void BOARD_InitPinsRF(void);

uint32_t BOARD_GetSpiClock(uint32_t instance)
{
    return 16000000U;
}
void BOARD_InitPinsRFUART(void)
{
    /* RFUART_SIN */
    PORT_SetPinMux(PORTD, 1, kPORT_MuxAlt8);
    /* RFUART_SOUT */
    PORT_SetPinMux(PORTD, 2, kPORT_MuxAlt8);
}

static void BOARD_InitHDI(void)
{
    /* Configure pinmux to output all RF signals on K7 FPGA
       This will override PTD1..3, PTC0..6
       PTDB0..5
       LPUART0/1 and pins are output directly (pinmux is bypassed) */
    BOARD_InitPinsRF();

    /* Init SPI0 clocks */
    CLOCK_SetIpSrc(kCLOCK_Lpspi0, kCLOCK_IpSrcFro192M);
    CLOCK_EnableClock(kCLOCK_Lpspi0);

    /* Init SPI0 pins */
    BOARD_InitPinsSPI0();
}

static void BOARD_InitPinsSPI0(void)
{
    /* Warning: current SPI0 pinmux can interfere with LPUART0 */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* SPI0_PCS0 */
    PORT_SetPinMux(PORTA, 16, kPORT_MuxAlt2);
    /* SPI0 SIN */
    PORT_SetPinMux(PORTA, 17, kPORT_MuxAlt2);
    /* SPI0 SOUT */
    PORT_SetPinMux(PORTA, 18, kPORT_MuxAlt2);
    /* SPI0 SCK */
    PORT_SetPinMux(PORTA, 19, kPORT_MuxAlt2);
}

static void BOARD_InitPinsRF(void)
{
    CLOCK_EnableClock(kCLOCK_PortA);
    CLOCK_EnableClock(kCLOCK_PortB);
    CLOCK_EnableClock(kCLOCK_PortC);

    /* ipp_do_rf_fpga [0..5] */
    // PORT_SetPinMux(PORTA, 16U, kPORT_MuxAlt8); // pinmux bypassed
    // PORT_SetPinMux(PORTA, 18U, kPORT_MuxAlt8);
    // PORT_SetPinMux(PORTA, 19U, kPORT_MuxAlt8);
    // PORT_SetPinMux(PORTD, 1U, kPORT_MuxAlt9);
    // PORT_SetPinMux(PORTD, 2U, kPORT_MuxAlt9);
    // PORT_SetPinMux(PORTD, 3U, kPORT_MuxAlt9);

    /* DTEST [0..12] */
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

    /* PTD3 is used for Phy switch */
    // PORT_SetPinMux(PORTD, 3U, kPORT_MuxAsGpio);
}
#endif

void PLATFORM_InitRadio(void)
{
#if defined(HDI_MODE) && (HDI_MODE == 1)
    /* Init SPI pins and interface to be used for channel switch */
    BOARD_InitHDI();
    /* Init HDI interface */
    HDI_Init();
#endif

#if defined(gUseIpcTransport_d) && (gUseIpcTransport_d == 1)
    Ipc_Init(s_IpcRpmsgHandle, &ipcRpmsgConfig, HDI_IpcInterface);
#endif
    return;
}
