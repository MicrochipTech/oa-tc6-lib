//DOM-IGNORE-BEGIN
/*
Copyright (C) 2023, Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/
//DOM-IGNORE-END
/*******************************************************************************
  main-loop for OpenAlliance TC6 10BASE-T1S MACPHY via SPI protocol

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    The main file

  Description:
    This files contains the main-loop driving the initialization and the cyclic
    tasks
*******************************************************************************/

/**************************************************************************************************/
/******                    SET YOUR SERIAL TERMINAL BAUDRATE TO 115200                    *********/
/**************************************************************************************************/

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>                     // memset
#include "definitions.h"                // SYS function prototypes

#include "lwip/apps/lwiperf.h"

#include "tc6-lwip.h"
#include "udp_perf_client.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define FIRMWARE_VERSION            "V3.0.1"

#define BOARD_INSTANCE              (0)
#define T1S_PLCA_ENABLE             (true)
#define T1S_PLCA_NODE_ID            (BOARD_INSTANCE + 1)
#define T1S_PLCA_NODE_COUNT         (8)
#define T1S_PLCA_BURST_COUNT        (0)
#define T1S_PLCA_BURST_TIMER        (0x80)
#define MAC_PROMISCUOUS_MODE        (false)
#define MAC_TX_CUT_THROUGH          (false)
#define MAC_RX_CUT_THROUGH          (false)
#define DELAY_BEACON_CHECK          (1000)
#define DELAY_LED                   (333)

#define ESC_CLEAR_TERMINAL          "\033[2J"
#define ESC_CURSOR_X1Y1             "\033[1;1H"
#define ESC_HIDE_CURSOR             "\033[?25l"
#define ESC_CLEAR_LINE              "\033[2K"
#define ESC_RESETCOLOR              "\033[0m"
#define ESC_GREEN                   "\033[0;32m"
#define ESC_RED                     "\033[0;31m"
#define ESC_YELLOW                  "\033[1;33m"
#define ESC_BLUE                    "\033[0;36m"

#define PRINT(...)                  printf(__VA_ARGS__)

#ifdef DEBUG
#define ASSERT(x)                  __conditional_software_breakpoint(x)
#else
#define ASSERT(x)
#endif

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      DEFINES AND LOCAL VARIABLES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

typedef struct
{
    uint32_t nextCycle;
    uint32_t nextBeaconCheck;
    uint32_t nextLed;
    int8_t idxLwIp;
    bool button1;
    bool button2;
    bool lastBeaconState;
    bool udpIperf;
} MainLocal_t;

static MainLocal_t m;
extern SYSTICK_OBJECT systick; /* Instanced in plib_systick.c */
static const uint8_t m_ip[] = {192, 168, 0, (100 + BOARD_INSTANCE)};

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PRIVATE FUNCTION PROTOTYPES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static void PrintMenu();
static void CheckUartInput(void);
static void CheckButton(uint8_t instance, bool newLevel, bool *oldLevel);
static void OnPlcaStatus(int8_t idx, bool success, bool plcaStatus);
static void OnIperfResult(void *arg, enum lwiperf_report_type report_type,
                          const ip_addr_t *local_addr, u16_t local_port,
                          const ip_addr_t *remote_addr, u16_t remote_port,
                          u32_t bytes_transferred, u32_t ms_duration,
                          u32_t bandwidth_kbitpsec);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PUBLIC FUNCTIONS                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

int main(void)
{
    /* Initialize all modules */
    SYS_Initialize(NULL);
    memset(&m, 0, sizeof(m));
    SYSTICK_TimerStart();
    PRINT(ESC_CLEAR_TERMINAL \
          ESC_CURSOR_X1Y1    \
          ESC_HIDE_CURSOR    \
          ESC_YELLOW         \
          "=== SAM E54 10Base-T1S Demo " FIRMWARE_VERSION " (" \
          __DATE__ " " __TIME__ ") ===" ESC_RESETCOLOR "\r\n");

    m.idxLwIp = TC6LwIP_Init(m_ip, T1S_PLCA_ENABLE, T1S_PLCA_NODE_ID, T1S_PLCA_NODE_COUNT,
        T1S_PLCA_BURST_COUNT, T1S_PLCA_BURST_TIMER, MAC_PROMISCUOUS_MODE,
        MAC_TX_CUT_THROUGH, MAC_RX_CUT_THROUGH);

    if (m.idxLwIp < 0) {
        PRINT(ESC_RED "Failed to initialize TC6 lwIP Driver" ESC_RESETCOLOR "\r\n");
        goto ERROR;
    }

    /* iperf */
    lwiperf_start_tcp_server_default(OnIperfResult, NULL);
    iperf_init();
    m.nextBeaconCheck = DELAY_BEACON_CHECK;

    PrintMenu();

    while (true) {
        uint32_t now;
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
        iperf_service();
        TC6LwIP_Service();

        now = systick.tickCounter;
        if (now > m.nextBeaconCheck) {
            m.nextBeaconCheck = now + DELAY_BEACON_CHECK;
            if (!TC6LwIP_GetPlcaStatus(m.idxLwIp, OnPlcaStatus)) {
                PRINT(ESC_RED "GetPlcaStatus failed" ESC_RESETCOLOR "\r\n");
            }
        }
        if (now > m.nextLed) {
            m.nextLed = now + DELAY_LED;
            GPIO_USER_LED_1_Toggle();
        }
        CheckUartInput();
        CheckButton(0, GPIO_USER_BUTTON_1_Get(), &m.button1);
        CheckButton(1, GPIO_USER_BUTTON_2_Get(), &m.button2);
    }
ERROR:
    while (true) {
        uint32_t now = systick.tickCounter;
        if (now > m.nextLed) {
            m.nextLed = now + 100;
            GPIO_USER_LED_1_Toggle();
        }
        SYS_Tasks();
    }
    return (EXIT_FAILURE);
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                  PRIVATE  FUNCTION IMPLEMENTATIONS                   */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static void PrintMenu()
{
    PRINT("\r\n=== Available Keys ===\r\n");
    PRINT(" m - print this menu\r\n");
    PRINT(" r - soft reset\r\n");
    PRINT(" c - clear screen\r\n");
    PRINT(" i - toggle iperf tx test\r\n");
    PRINT("======================\r\n");
}

static void CheckUartInput(void)
{
    static uint8_t m_rx = 0;

    if (m_rx && SERCOM1_USART_ReadCountGet()) {
        switch(m_rx) {
            case 'M':
            case 'm':
                PrintMenu();
                break;
            case 'R':
            case 'r':
                __NVIC_SystemReset();
                while(true);
                break;
            case 'C':
            case 'c':
                PRINT(ESC_CLEAR_TERMINAL ESC_CURSOR_X1Y1 ESC_HIDE_CURSOR);
                break;
            case 'I':
            case 'i':
                m.udpIperf = (!m.udpIperf || !iperf_get_running_state());
                if (m.udpIperf) {
                    iperf_print_app_header();
                    iperf_start_application();
                } else {
                    PRINT("iperf client stop\r\n");
                    iperf_stop_application();
                }
                break;
            default:
                PRINT("Unknown key='%c'(0x%X)\r\n", m_rx, m_rx);
                break;
        }
    }
    if (!SERCOM1_USART_ReadIsBusy()) {
        SERCOM1_USART_Read(&m_rx, 1);
    }
}

static void CheckButton(uint8_t instance, bool newLevel, bool *oldLevel)
{
    if (newLevel != *oldLevel) {
        *oldLevel = newLevel;
        if (0 == instance && !newLevel) {
            m.udpIperf = (!m.udpIperf || !iperf_get_running_state());
            if (m.udpIperf) {
                PRINT("\r\n======================\r\n");
                PRINT("= iperf client start =\r\n");
                PRINT("======================\r\n");
                iperf_print_app_header();
                iperf_start_application();
            } else {
                PRINT("\r\n=====================\r\n");
                PRINT("= iperf client stop =\r\n");
                PRINT("=====================\r\n");
                iperf_stop_application();
            }
        }
    }
}

static void OnPlcaStatus(int8_t idx, bool success, bool plcaStatus)
{
    if (success) {
        if (plcaStatus != m.lastBeaconState) {
            m.lastBeaconState = plcaStatus;
            if (plcaStatus) {
                PRINT(ESC_GREEN "PLCA Mode active" ESC_RESETCOLOR "\r\n");
            } else {
                PRINT(ESC_RED "CSMA/CD fallback" ESC_RESETCOLOR "\r\n");
            }
        }
        m.lastBeaconState = plcaStatus;
    } else {
        PRINT(ESC_RED "PLCA status register read failed" ESC_RESETCOLOR "\r\n");
    }
}


/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                  CALLBACK FUNCTION FROM LWIP iperf                   */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

void OnIperfResult(void *arg, enum lwiperf_report_type report_type,
                   const ip_addr_t *local_addr, u16_t local_port,
                   const ip_addr_t *remote_addr, u16_t remote_port,
                   u32_t bytes_transferred, u32_t ms_duration,
                   u32_t bandwidth_kbitpsec)
{
    PRINT("iperf result [Bytes=%ld Duration=%ld ms Bandwidth=%ld kbit/s]\r\n", bytes_transferred, ms_duration, bandwidth_kbitpsec);
}

