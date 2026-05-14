//DOM-IGNORE-BEGIN
/*
Copyright (C) 2025, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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
  Potentiometer test source file.

  Company:
    Microchip Technology Inc.

  File Name:
    pot_test.c

  Summary:
    Potentiometer test header file

  Description:
    The potentiometer test that sends UDP messages to devices capable of
    interpreting them, and those devices control their 3-color LED based on the
    values received from the sender.
*******************************************************************************/

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <string.h>                     // memset
#include <assert.h>

#include "pot_test.h"
#include "test_utils.h"
#include "tc6-lwip.h"

#include "lwip/netif.h"
#include "lwip/timeouts.h"
#include "lwip/ip.h"
#include "lwip/ip_addr.h"
#include "lwip/ip4_addr.h"
#include "lwip/udp.h"

#include "netif/etharp.h"

#include "bsp/pot.h"
#include "bsp/led_blue.h"
#include "bsp/led_green.h"
#include "bsp/led_red.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      DEFINES AND LOCAL VARIABLES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/// @brief Get the absolute value.
#define abs(value) (((int32_t)(value) < 0) ? (~(value) + 1) : (value))

#define POT_TIMEOUT_MS      (50)
#define POT_MSG_ID          (0x4224U)
#define POT_DEBOUNCE_VALUE  (64)


/// @brief Defines a potentiometer control message.
struct pot_msg {
    uint16_t id;        // Message ID
    uint16_t value;     // Potentiometer value
    uint32_t count;     // Message number
} __attribute__((packed));


/// @brief Defines potentiometer message control data.
struct pot_msg_data {
    ip4_addr_t addr;        // IP Address to which messages are being sent
    uint16_t port;          // UDP port to which messages are being sent
    uint16_t period;        // Period between messages in milliseconds

    uint32_t count;         // Number of messages sent
    uint32_t sent;          // Number of messages sent successfully
    uint32_t failed;        // NUmber of send failures

    struct udp_pcb *sock;   // UDP socket to use

    uint32_t received;      // Number of messages received

    uint16_t last;          // Last value of the potentiometer

    bool active;            // Is the operation active
    bool quiet;             // Are debug messages being output
};

/// @brief Potentiometer control data.
static struct pot_msg_data pot_msg_data;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                   PRIVATE FUNCTIONS AND PROTOTYPES                   */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static void pot_timer(void *arg);

/// @brief End a potentiometer data stream.
static void pot_stop_stream(void *arg)
{
    (void)arg;

    if (true == pot_msg_data.active)
    {
        pot_msg_data.active = false;

        // Unregister the timer.
        sys_untimeout(pot_timer, NULL);

        // Disconnect the socket.
        udp_disconnect(pot_msg_data.sock);
        udp_remove(pot_msg_data.sock);

        // Print that we're done.
        char ip[16] = {0};
        build_ip_string(ip, &pot_msg_data.addr);

        if (pot_msg_data.addr.addr == TEST_BROADCAST_ADDRESS)
        {
            PRINT("\r\nSent %lu messages\r\n", pot_msg_data.sent);
        }
        else
        {
            PRINT("\r\nSent %lu messages to %s:%u\r\n", pot_msg_data.sent, ip, pot_msg_data.port);
        }

        PRINT("Received %lu messages\r\n", pot_msg_data.received);

        if (0 < pot_msg_data.failed)
        {
            PRINT("Failed to send %lu packets\r\n", pot_msg_data.failed);
        }
    }

    LED_BLUE_SetIntensity(0);
    LED_RED_SetIntensity(0);
    LED_BLUE_Off();
    LED_RED_Off();
}


/// @brief Send a generated UDP message with the potentiometer's data.
/// @param sock The UDP socket to use.
/// @param addr The target IP address.
/// @param port The target port.
/// @param value The potentiometer value to send.
/// @param count The current message count.
/// @return TRUE if sent, FALSE if not.
static err_t pot_send_message(struct udp_pcb *sock, ip4_addr_t *addr, uint16_t port,
                              uint16_t value, uint32_t count)
{
    err_t result = ERR_WOULDBLOCK;

    if (!TC6LwIP_SendWouldBlock(0))
    {
        // Get a packet buffer and fill it with data.
        struct pbuf *send_buf;
        ip4_addr_t src;
        uint16_t size = 8;

        src.addr = get_long(&addr->addr);

        send_buf = pbuf_alloc(PBUF_TRANSPORT, size, PBUF_RAM);
        if (NULL == send_buf)
        {
            result = ERR_MEM;
        }
        else
        {
            // Insert the message data into the buffer.
            // Format a simple message that contains a message code (2 bytes),
            // a value (2 bytes), and a count (4 bytes).
            struct pot_msg *p = (struct pot_msg *)send_buf->payload;
            p->id = POT_MSG_ID;
            p->value = value;
            p->count = count;

            // Send the packet.
            result = udp_sendto(sock, send_buf, &src, port);
            assert(send_buf->ref != 0);
            pbuf_free(send_buf);
        }
    }

    return result;
}


/// @brief Handle a UDP message when the potentiometer test is enabled.
/// @param arg The input argument.
/// @param pcb The UDP control block.
/// @param p The message buffer that was received.
/// @param addr The interface IP address.
/// @param port The source/destination port.
static void pot_recv(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
{
    (void)arg;
    (void)pcb;
    (void)addr;
    (void)port;

    uint8_t *data = (uint8_t *)p->payload;

    struct pot_msg *msg = (struct pot_msg *)data;
    if (msg->id == POT_MSG_ID)
    {
        // Successful receipt.
        pot_msg_data.received++;
        if (0 == (pot_msg_data.received % 10))
        {
            if (false == pot_msg_data.quiet)
            {
                PRINT(":");
            }
        }

        // Set the LED to the received value.
        uint16_t value = get_short(&msg->value);

        // Low values increase RED and decrease BLUE.
        // High values increase BLUE and decrease RED.
        uint16_t blueval = value;
        uint16_t redval = 0x7FFFU - value;
        LED_BLUE_SetIntensity(blueval);
        LED_RED_SetIntensity(redval);
    }

    // Free the buffer, as it was a copy and we no longer need it.
    pbuf_free(p);
}


/// @brief The timer for generating UDP messages by reading the potentiometer.
/// @param arg The input argument.
static void pot_timer(void *arg)
{
    (void)arg;

    // Read the potentiometer, and send an updated value
    // if the value has changed enough to register.
    uint16_t value = POT_Read();

    if (abs(value - pot_msg_data.last) > POT_DEBOUNCE_VALUE)
    {
        // Send a new packet.
        err_t result;

        pot_msg_data.last = value;
        pot_msg_data.count++;

        result = pot_send_message(pot_msg_data.sock, &pot_msg_data.addr, pot_msg_data.port,
                                  pot_msg_data.last, pot_msg_data.count);
        if (ERR_OK == result)
        {
            // Successful send.
            pot_msg_data.sent++;
            if (0 == (pot_msg_data.sent % 10UL))
            {
                if (false == pot_msg_data.quiet)
                {
                    PRINT(".");
                }
            }
        }
        else
        {
            // Failed to send for reasons.
            pot_msg_data.failed++;

            if (ERR_OK != result)
            {
                switch (result)
                {
                    case ERR_WOULDBLOCK:
                        PRINT("Send of packet %lu failed (would block)\r\n", pot_msg_data.count);
                        break;

                    case ERR_ARP:
                        PRINT("Send of packet %lu failed (ARP request sent)\r\n", pot_msg_data.count);
                        break;

                    default:
                        PRINT("Send of packet %lu failed with error code %d\r\n", pot_msg_data.count, result);
                        break;
                }
            }
        }
    }

    // See if any packets came in that we want to process.

    // Restart the timer.
    sys_timeout(pot_msg_data.period, pot_timer, NULL);
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PUBLIC FUNCTIONS                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

void pot_test_start(ip4_addr_t addr, uint16_t port, bool quiet)
{
    do
    {
        // If the stream is active, remind to stop first.
        if (true == pot_msg_data.active)
        {
            PRINT("Potentiometer test is already active\r\n");
            break;
        }

        // Get the netif instance.
        struct netif *netif = TC6LwIP_GetNetIf(0);

        // If broadcast, it's to everyone.
        pot_msg_data.addr.addr = addr.addr;
        pot_msg_data.port = port;
        pot_msg_data.quiet = quiet;

        // Start the stream.
        pot_msg_data.count = 1;
        pot_msg_data.sent = 0;
        pot_msg_data.received = 0;
        pot_msg_data.failed = 0;
        pot_msg_data.period = POT_TIMEOUT_MS;

        // Create a socket.
        pot_msg_data.sock = udp_new();
        if (NULL == pot_msg_data.sock)
        {
            PRINT("Failed to open socket\r\n");
            break;
        }

        // Bind to the UDP port on our local address.
        if (ERR_OK != udp_bind(pot_msg_data.sock, &netif->ip_addr, pot_msg_data.port))
        {
            char ip[16] = {0};
            build_ip_string(ip, &netif->ip_addr);

            udp_remove(pot_msg_data.sock);
            PRINT("Failed to bind to socket on %s:%d\r\n", ip, pot_msg_data.port);
            break;
        }

        // Connect to the remote address on the same port.
        if (ERR_OK != udp_connect(pot_msg_data.sock, &pot_msg_data.addr, pot_msg_data.port))
        {
            char ip[16] = {0};
            build_ip_string(ip, &pot_msg_data.addr);

            udp_remove(pot_msg_data.sock);
            PRINT("Failed to connect to socket on %s:%d\r\n", ip, pot_msg_data.port);
            break;
        }

        if (TEST_BROADCAST_ADDRESS == pot_msg_data.addr.addr)
        {
            PRINT("Broadcasting UDP messages for potentiometer control on port %u\r\n", pot_msg_data.port);
        }
        else
        {
            char ip[16] = {0};
            build_ip_string(ip, &pot_msg_data.addr);

            PRINT("Opened connection to %s:%u\r\n", ip, pot_msg_data.port);
            PRINT("Sending UDP messages for potentiometer control to %s:%u\r\n", ip, pot_msg_data.port);
        }

        // Register the callback.
        udp_recv(pot_msg_data.sock, pot_recv, netif);

        LED_BLUE_SetIntensity(0);
        LED_RED_SetIntensity(0);
        LED_BLUE_On();
        LED_RED_On();

        // Start the stream timer.  (The send might fail because of an ARP request.)
        pot_msg_data.active = true;
        sys_timeout(pot_msg_data.period, pot_timer, NULL);

    } while (0);
}

void pot_test_stop(void)
{
    if (false == pot_msg_data.active)
    {
        PRINT("\r\nPotentiometer test was not active\r\n");
    }
    else
    {
        PRINT("\r\nPotentiometer test stopped\r\n");
        pot_stop_stream(NULL);
    }
}
