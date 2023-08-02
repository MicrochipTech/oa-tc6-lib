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

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
#include "systick.h"
#include "tc6-noip.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/


#ifndef BOARD_INSTANCE
#define BOARD_INSTANCE              (0)
#endif
#define T1S_PLCA_ENABLE             (true)
#define T1S_PLCA_NODE_ID            (BOARD_INSTANCE)
#define T1S_PLCA_NODE_COUNT         (8)
#define T1S_PLCA_BURST_COUNT        (0)
#define T1S_PLCA_BURST_TIMER        (0x80)
#define MAC_PROMISCUOUS_MODE        (false)
#define MAC_TX_CUT_THROUGH          (false)
#define MAC_RX_CUT_THROUGH          (false)

#define DELAY_LED                   (256)
#define UDP_PAYLOAD_OFFSET          (42)
#define UDP_TARGET_PORT             (34505)

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          MCP9800 CONFIG                            */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define CONVERSION_FACTOR           256
#define MCP9800_SLAVE_ADDR          0x48
#define MCP9800_TEMP_REG_ADDR       0x00
#define MCP9800_CONFIG_REG_ADDR     0x01
#define MCP9800_THYST_REG_ADDR      0x02
#define MCP9800_TSET_REG_ADDR       0x03
#define MCP9800_RESOLUTION          0x20   // 10 bit 0.25C
#define MCP9800_MAX_NEG_VALUE       -55
#define MCP9800_MAX_POS_VALUE       125

#define PRINT(...)                  printf(__VA_ARGS__)
#ifdef DEBUG
#define ASSERT(x)                   __conditional_software_breakpoint(x)
#else
#define ASSERT(x)
#endif

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      DEFINES AND LOCAL VARIABLES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

typedef struct
{
    uint32_t lastLed;
    int8_t idxNoIp;
} MainLocal_t;

static MainLocal_t m;
static const uint8_t m_mac[] = { 0x00, 0x80, 0xC2, 0x00, 0x01, T1S_PLCA_NODE_ID }; // MAC = 00:80:C2:00:01: ID

static uint8_t m_udpPacket[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x70, 0xb3, /* ......p. */
    0xd5, 0x77, 0xf0, BOARD_INSTANCE, 0x08, 0x00, 0x45, 0x00, /* .w.*..E. */
    0x00, 0x22, 0x37, 0x57, 0x00, 0x00, 0x80, 0x11, /* ."7W.... */
    0x00, 0x00, 0xc0, 0xa8, 0x00, 0xde, 0xc0, 0xa8, /* .F...... */
    0x00, 0xff, 0x86, 0xc9, 0x86, 0xc9, 0x00, 0x0e, /* ........ */
    0x00, 0x00, 0x01, 0xCD, 0xCD, 0xCD, 0xCD, 0xCD  /* f....... */
};

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PUBLIC FUNCTIONS                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

void MCP9800_Initialize(void)
{
    I2C1_Write1ByteRegister(MCP9800_SLAVE_ADDR, MCP9800_CONFIG_REG_ADDR, MCP9800_RESOLUTION);
}

static void send_thermo7_temp(void)
{
    uint8_t addr = 0x00;
    uint16_t val = UINT16_MAX;
    val = i2c_read2ByteRegister(MCP9800_SLAVE_ADDR, addr);
    m_udpPacket[UDP_PAYLOAD_OFFSET + 0] = (uint8_t)(val >>8);
    m_udpPacket[UDP_PAYLOAD_OFFSET + 1] = (uint8_t)val;
}

void main(void)
{
    SYSTEM_Initialize();
    MCP9800_Initialize();
    TMR2_SetInterruptHandler(TMR2_DefaultInterruptHandler);
    INTERRUPT_GlobalInterruptEnable();
    SysTick_Init();

    memcpy(&m_udpPacket[6], m_mac, 6);
    m_udpPacket[0x1D] = 100 + T1S_PLCA_NODE_ID; /* Last Byte of IP address */
    m_udpPacket[0x24] = (UDP_TARGET_PORT >> 8) & 0xFF;
    m_udpPacket[0x25] = UDP_TARGET_PORT & 0xFF;

    while (!IO_SW0_GetValue()) {
        /* Wait until button gets released */
    }

    SPI1_Open(SPI1_DEFAULT); /* open SPI instance */

    PRINT("\033[2J");      /* Clear Terminal */
    PRINT("\033[1;1H");    /* Set Cursor to x=1 y=1 */
    PRINT("\033[?25l");    /* Hide Cursor */
    PRINT("\r==============================================\r\n");
    PRINT("  PIC18 10BASE-T1S Temperature Demo V1.0.0\r\n");
    PRINT("==============================================\r\n");

    m.idxNoIp = TC6NoIP_Init(T1S_PLCA_ENABLE, T1S_PLCA_NODE_ID, T1S_PLCA_NODE_COUNT,
        T1S_PLCA_BURST_COUNT, T1S_PLCA_BURST_TIMER, MAC_PROMISCUOUS_MODE,
        MAC_TX_CUT_THROUGH, MAC_RX_CUT_THROUGH);

    if (m.idxNoIp < 0) {
        PRINT("Failed to initialize TC6 noIP Driver\r\n");
        goto error;
    }
    while (true)
    {
        uint32_t now = SysTick_GetMillis();
        TC6NoIP_Service();

        if(time_to_read_temp) {  // read the temperature every second

           send_thermo7_temp();  //read temperature and store the data into UDP buffer
           TC6NoIP_SendEthernetPacket(0, m_udpPacket, sizeof(m_udpPacket));

           time_to_read_temp = false; // reset flag
        }

        if ((now - m.lastLed) >= DELAY_LED) {
            m.lastLed = now;
            IO_LED0_Toggle();
        }
        if (!IO_SW0_GetValue()) {
            RESET();
        }
        while(UART1_is_rx_ready()) {
            char key = UART1_Read();
            PRINT("key=%c\r\n", key);
        }
    }
error:
    while(true) {
        IO_LED0_Toggle();
        SysTick_DelayMS(100);
        if (!IO_SW0_GetValue()) {
            RESET();
        }
    }
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                CALLBACK FUNCTION FROM NoIP component                 */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

void TC6NoIP_CB_OnEthernetReceive(int8_t idx, const uint8_t *pRx, uint16_t len)
{
    if ((0x11 /* UDP Protocol */ == pRx[0x17]) && (len >= (UDP_PAYLOAD_OFFSET + 2))) {
        bool error = false;
        uint16_t targetPort = ((uint16_t)pRx[0x24] << 8) | (uint16_t)pRx[0x25];
        if (UDP_TARGET_PORT == targetPort) {

            uint32_t now = SysTick_GetMillis();
            uint8_t remoteNode = pRx[0xB];
            uint8_t dataH = pRx[UDP_PAYLOAD_OFFSET + 0];
            uint8_t dataL = pRx[UDP_PAYLOAD_OFFSET + 1];
            uint16_t data = ((uint16_t)dataH << 8) | (dataL);
            if ((0 == data) || (UINT16_MAX == data)) {
                error = true;
            } else {
                float temp = (float)data;
                temp /= CONVERSION_FACTOR;

                if((temp < MCP9800_MAX_NEG_VALUE) || (temp > MCP9800_MAX_POS_VALUE)) {
                    error = true;
                } else {
                    printf("[%ld]Temperature from Node %d: %.3f C \r\n", now, remoteNode, temp);
                }
            }
            if (error) {
                printf("[%ld]Temperature from Node %d invalid. Is Thermo7 click missing?\r\n", now, remoteNode);
            }
        }
    }
}
