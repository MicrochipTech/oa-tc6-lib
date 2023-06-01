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
#include <assert.h>

#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/spi_host/spi1.h"
#include "mcc_generated_files/dma/dma.h"
#include "mcc_generated_files/timer/sccp1.h"
#include "mcc_generated_files/uart/uart1.h"
#include "mcc_generated_files/uart/uart1.h"
#include "DMASPItransfer.h"/*THW220107 add include file */

#include "tc6-lwip.h"

#include "udp_perf_client.h"
#include "systick.h"

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
#define MAC_TX_CUT_THROUGH          (true)
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
#define RESET()                     {__asm__ volatile ("reset");}
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
    uint32_t lastBeaconCheck;
    uint32_t lastLed;
    int8_t idxLwIp;
    bool button1;
    bool lastBeaconState;
    bool udpIperf;
} MainLocal_t;

static MainLocal_t m;
extern SYSTICK_OBJECT systick; /* Instanced in plib_systick.c */
static const uint8_t m_ip[] = {192, 168, 0, (100 + BOARD_INSTANCE)};

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PRIVATE FUNCTION PROTOTYPES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
static void CheckButton(uint8_t instance, bool newLevel, bool *oldLevel);
static void OnPlcaStatus(int8_t idx, bool success, bool plcaStatus);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PUBLIC FUNCTIONS                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

int main(void)
{

    SYSTEM_Initialize();

    SysTick_Init();
    PROBE_SetLow();

    memset(&m, 0, sizeof(m));

    PRINT(ESC_CLEAR_TERMINAL \
          ESC_CLEAR_TERMINAL \
          ESC_CURSOR_X1Y1    \
          ESC_HIDE_CURSOR    \
          ESC_YELLOW         \
          "dsPIC33 Curiosity 10Base-T1S Demonstrator " \
          FIRMWARE_VERSION   \
          " (" __DATE__ " " __TIME__ ")" \
          ESC_RESETCOLOR     \
          "\r\n");

    m.idxLwIp = TC6LwIP_Init(m_ip, T1S_PLCA_ENABLE, T1S_PLCA_NODE_ID, T1S_PLCA_NODE_COUNT,
        T1S_PLCA_BURST_COUNT, T1S_PLCA_BURST_TIMER, MAC_PROMISCUOUS_MODE,
        MAC_TX_CUT_THROUGH, MAC_RX_CUT_THROUGH);

    if (m.idxLwIp < 0) {
        PRINT(ESC_RED "Failed to initialize TC6 lwIP Driver" ESC_RESETCOLOR "\r\n");
    }

    /* iperf */
    iperf_init();

    PRINT(ESC_YELLOW "Press button S1 to start iperf client \r\n");

    while (true) {
        uint32_t now;
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        iperf_service();
        TC6LwIP_Service();

        now = systick.tickCounter;
       if ((now - m.lastBeaconCheck) >= DELAY_BEACON_CHECK) {
            m.lastBeaconCheck = now;
            if (!TC6LwIP_GetPlcaStatus(m.idxLwIp, OnPlcaStatus)) {
                printf(ESC_RED "GetPlcaStatus failed" ESC_RESETCOLOR "\r\n");
            }
        }
        if ((now - m.lastLed) >= DELAY_LED) {
            m.lastLed = now;
            IO_LED_RED_Toggle();
        }

        CheckButton(0, GPIO_USER_BUTTON_1_GetValue(), &m.button1);
    }
    return -1;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                  PRIVATE  FUNCTION IMPLEMENTATIONS                   */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static void CheckButton(uint8_t instance, bool newLevel, bool *oldLevel)
{
    if (newLevel != *oldLevel) {
        *oldLevel = newLevel;
        if (0 == instance && !newLevel) {
            m.udpIperf = (!m.udpIperf || !iperf_get_running_state());
            if (m.udpIperf) {
                printf("\r\n======================\r\n");
                printf("= iperf client start =\r\n");
                printf("======================\r\n");
                iperf_print_app_header();
                iperf_start_application();
            } else {
                printf("\r\n=====================\r\n");
                printf("= iperf client stop =\r\n");
                printf("=====================\r\n");
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
