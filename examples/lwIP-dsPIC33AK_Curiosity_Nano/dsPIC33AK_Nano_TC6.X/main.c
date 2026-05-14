//DOM-IGNORE-BEGIN
/*
Copyright (C) 2026, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/uart/uart1.h"

#include "tc6.h"
#include "tc6-lwip.h"

#include "test_utils.h"
#include "udp_perf_client.h"
#include "icmp_test.h"
#include "systick.h"


/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define FIRMWARE_VERSION            TC6_LIB_VER_STRING

#ifndef BOARD_INSTANCE
#define BOARD_INSTANCE              (0)
#endif
#define T1S_PLCA_ENABLE             (true)
#define T1S_PLCA_NODE_ID            (BOARD_INSTANCE)
#define T1S_PLCA_NODE_COUNT         (8)
#define T1S_PLCA_BURST_COUNT        (0)
#define T1S_PLCA_BURST_TIMER        (0x80)
#define MAC_PROMISCUOUS_MODE        (false)
#define MAC_TX_CUT_THROUGH          (true)
#define MAC_RX_CUT_THROUGH          (false)
#define DELAY_BEACON_CHECK          (1000)
#define DELAY_LED                   (333)

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
    char command;
    bool lastBeaconState;
    bool firstStateChecked;
    bool udpIperf;
    bool pingTest;
} MainLocal_t;

static MainLocal_t m;
static const uint8_t m_ip[] = {192, 168, 0, (100 + BOARD_INSTANCE)};

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PRIVATE FUNCTION PROTOTYPES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static void printMenu(void);
static void printHeader(void);
static void OnPlcaStatus(int8_t idx, bool success, bool plcaStatus);
static void checkPlcaStatus(void);
static void checkSystemStatus(void);
static void uartRxHandler(void);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PUBLIC FUNCTIONS                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/


/**
 * @brief Main application.
 */
int main(void)
{
    SYSTEM_Initialize();
    SysTick_Initialize();

    (void)memset(&m, 0, sizeof(m));

   // Register the callback handler for received UART data.
    UART1_RxCompleteCallbackRegister(uartRxHandler);

    // Flush the UART.
    while (true == UART1_IsRxReady())
    {
        UART1_Read();
    }

    printHeader();

    /* Initialize the stack */
    m.idxLwIp = TC6LwIP_Init(m_ip, T1S_PLCA_ENABLE, T1S_PLCA_NODE_ID, T1S_PLCA_NODE_COUNT,
                            T1S_PLCA_BURST_COUNT, T1S_PLCA_BURST_TIMER, MAC_PROMISCUOUS_MODE,
                            MAC_TX_CUT_THROUGH, MAC_RX_CUT_THROUGH);
    if (m.idxLwIp < 0)
    {
        PRINT(ESC_RED "Failed to initialize TC6 lwIP Driver" ESC_RESETCOLOR "\r\n");
        while(1) {}
    }

    PRINT(ESC_GREEN "TC6 lwIP Driver initialized\r\n" ESC_RESETCOLOR);

    /* Execute initial PLCA check before starting */
    PRINT(ESC_GREEN "Checking PLCA status\r\n" ESC_RESETCOLOR);
    while (false == m.firstStateChecked)
    {
        checkPlcaStatus();
        TC6LwIP_Service();
    }

    /* iperf */
    iperf_init();

    /* main menu */
    printMenu();

    /* Main loop */
    while (true)
    {
        /* Update PLCA status */
        checkPlcaStatus();

        /* Service iperf */
        iperf_service();

        /* Service the TC6 engine */
        TC6LwIP_Service();

        /* Service status updates */
        checkSystemStatus();
    }
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                  PRIVATE  FUNCTION IMPLEMENTATIONS                   */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/**
 * @brief Print the application header.
 */
static void printHeader(void)
{
    PRINT(ESC_CLEAR_TERMINAL \
          ESC_CLEAR_TERMINAL \
          ESC_CURSOR_X1Y1    \
          ESC_YELLOW         \
          "dsPIC33AK Curiosity Nano 10BASE-T1S Demonstrator " \
          FIRMWARE_VERSION   \
          " (" __DATE__ " " __TIME__ ")" \
          ESC_RESETCOLOR     \
          "\r\n");
}

/**
 * @brief Print the menu.
 */
static void printMenu(void)
{
    PRINT(ESC_YELLOW "\r\n====== Available Keys ======\r\n" ESC_RESETCOLOR);
    PRINT(" m - print this menu\r\n");
    PRINT(" r - soft reset\r\n");
    PRINT(" c - clear screen\r\n");
    PRINT(" i - toggle iperf tx test\r\n");
    PRINT(" p - toggle icmp (ping) test\r\n");
    PRINT(ESC_YELLOW "============================\r\n" ESC_RESETCOLOR);
}

/**
 * @brief PLCA status check callback function.
 * @param idx The lwIP instance index.
 * @param success The success of the status check.
 * @param plcaStatus The result of the status check.
 */
static void OnPlcaStatus(int8_t idx, bool success, bool plcaStatus)
{
    (void)idx;

    if (true == success)
    {
        if ((false == m.firstStateChecked) || (plcaStatus != m.lastBeaconState))
        {
            m.lastBeaconState = plcaStatus;

            if (true == plcaStatus)
            {
                PRINT(ESC_GREEN "PLCA Mode active\r\n" ESC_RESETCOLOR);
            }
            else
            {
                PRINT(ESC_RED "CSMA/CD fallback\r\n" ESC_RESETCOLOR);
            }
        }

        m.lastBeaconState = plcaStatus;
    }
    else
    {
        PRINT(ESC_RED "PLCA status register read failed\r\n" ESC_RESETCOLOR);
    }

    m.firstStateChecked = true;
}

/**
 * @brief PLCA status check service routine.
 */
static void checkPlcaStatus(void)
{
    uint32_t now = SysTick_GetTickMs();

    if ((now - m.lastBeaconCheck) >= DELAY_BEACON_CHECK)
    {
        m.lastBeaconCheck = now;

        if (false == TC6LwIP_GetPlcaStatus(m.idxLwIp, OnPlcaStatus))
        {
            PRINT(ESC_RED "GetPlcaStatus failed\r\n" ESC_RESETCOLOR);
        }
    }
}

/**
 * @brief System status check service routine.
 */
static void checkSystemStatus(void)
{
    uint32_t now = SysTick_GetTickMs();

    if ((now - m.lastLed) >= DELAY_LED)
    {
        m.lastLed = now;
        LED0_Toggle();
    }

    // Check the button for reset.
    if (0 == SW0_GetValue())
    {
        RESET();
    }

    // Check for UART input and set states accordingly.
    if (m.command != 0)
    {
        switch (tolower(m.command))
        {
            // m: menu
            case 'm':
            {
                printMenu();
            }
            break;

            // r: reset
            case 'r':
            {
                RESET();
            };

            // c: clear screen
            case 'c':
            {
                printHeader();
            }
            break;

            // i: iperf test
            case 'i':
            {
                m.udpIperf = (!m.udpIperf || !iperf_get_running_state());
                if (true == m.udpIperf)
                {
                    printf("\r\n======================\r\n");
                    printf("= iperf client start =\r\n");
                    printf("======================\r\n");
                    iperf_print_app_header();
                    iperf_start_application();
                }
                else
                {
                    printf("\r\n=====================\r\n");
                    printf("= iperf client stop =\r\n");
                    printf("=====================\r\n");
                    iperf_stop_application();
                }
            }
            break;

            // p: ping test
            case 'p':
            {
                m.pingTest = !m.pingTest;
                if (true == m.pingTest)
                {
                    ip_addr_t addr;

                    // Get the netif instance.
                    struct netif *netif = TC6LwIP_GetNetIf(0);

                    // If the interface address is the first unicast address, send to
                    // the second one and vice versa.
                    addr.addr = (PP_NTOHL(TEST_UNICAST_ADDRESS_1) == netif->ip_addr.addr)
                                ? PP_NTOHL(TEST_UNICAST_ADDRESS_2)
                                : PP_NTOHL(TEST_UNICAST_ADDRESS_1);

                    // Start the test with indicative output to console.
                    printf("\r\n===================\r\n");
                    printf("= ping test start =\r\n");
                    printf("===================\r\n");
                    icmp_test_start(addr);
                }
                else
                {
                    icmp_test_stop();
                    printf("\r\n==================\r\n");
                    printf("= ping test stop =\r\n");
                    printf("==================\r\n");
                }
            }
            break;

            default:
            break;
        }

        // Command was processed.
        m.command = 0;
    }
}

/**
 * @brief UART receive handler.
 */
static void uartRxHandler(void)
{
    // Read the UART for a command.
    if (true == UART1_IsRxReady())
    {
        m.command = UART1_Read();
    }
}
