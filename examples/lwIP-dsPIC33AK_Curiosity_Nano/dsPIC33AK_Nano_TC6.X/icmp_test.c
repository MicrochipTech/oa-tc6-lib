/*
� [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip
    software and any derivatives exclusively with Microchip products.
    You are responsible for complying with 3rd party license terms
    applicable to your use of 3rd party software (including open source
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.?
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR
    THIS SOFTWARE.
*/

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <string.h>                     // memset
#include <assert.h>

#include "icmp_test.h"
#include "test_utils.h"
#include "systick.h"

#include "tc6-lwip.h"
#include "lwip/netif.h"
#include "lwip/icmp.h"
#include "lwip/timeouts.h"
#include "lwip/ip.h"
#include "lwip/ip_addr.h"
#include "lwip/ip4_addr.h"

#include "netif/etharp.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      DEFINES AND LOCAL VARIABLES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define ICMP_TIMER_TIMEOUT_MS   (1000u)     // ICMP timeout in milliseconds
#define ICMP_MAX_PINGS          (100000UL)  // Maximum number of pings to execute

#define ICMP_DEFAULT_DATA_SIZE 128   // Default data size in bytes

/// @brief Defines the control structure for ICMP messages.
struct icmp_msg_data
{
    ip_addr_t addr;         // IP address which waqs pinged
    uint16_t size;          // Size of the data in bytes
    uint32_t iterations;    // Number of pings to send
    uint32_t total;         // Total number of pings sent ever

    uint32_t start;         // Start time in ticks

    uint32_t count;         // Number of pings sent
    uint32_t received;      // Number of resoonses received
    uint32_t seq;           // ICMP sequence number

    uint64_t min;           // Minimum receive time
    uint64_t max;           // Maximum receive time
    uint64_t accum;         // Accumulated time

    bool active;            // Is a ping session active
    bool response;          // Was a response to the last ping recieved
};

/// @brief ICMP message control data.
static struct icmp_msg_data icmp_msg_data = {{0}};

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                   PRIVATE FUNCTIONS AND PROTOTYPES                   */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

void icmp_msg_timeout(void *arg);

/// @brief Stop pings / report statistics.
/// @param arg An input argument.
static void icmp_stop_pings(void *arg)
{
    uint32_t now = SysTick_GetTickMs();

    // Session is no longer active.
    icmp_msg_data.active = false;

    char ip[16] = {0};
    build_ip_string(ip, &icmp_msg_data.addr);

    // Deregister the callbacks.
    icmp_recv(NULL, NULL);
    sys_untimeout(icmp_msg_timeout, NULL);

    PRINT("\r\n--- %s ping statistics ---\r\n", ip);
    PRINT("%lu packets transmitted, %lu received, %.1f%% packet loss, time %ld ms\r\n",
            icmp_msg_data.seq, icmp_msg_data.received,
            (100.0 - ((double)icmp_msg_data.received * 100.0) / icmp_msg_data.seq),
            (now - icmp_msg_data.start));

    if (0 < icmp_msg_data.received)
    {
        // Scale to milliseconds.
        double mintime = (double)(icmp_msg_data.min / 1000.0);
        double maxtime = (double)(icmp_msg_data.max / 1000.0);
        double avgtime = ((double)icmp_msg_data.accum / (double)icmp_msg_data.received) / 1000.0;
        PRINT("rtt min/avg/max = %.2f/%.3f/%.2f ms\r\n", mintime, avgtime, maxtime);
    }
}


/// @brief Timeout for IMCP messages.
/// @param arg Input argument.
/// @note This will trigger a new message if the count has not expired.
void icmp_msg_timeout(void *arg)
{
    bool stop = false;

    if (false == icmp_msg_data.response)
    {
        // CR/LF on the first output.
        if (1UL == icmp_msg_data.seq)
        {
            PRINT("\r\n");
        }

        char ip[16] = {0};
        build_ip_string(ip, &icmp_msg_data.addr);

        PRINT("Request to %s timed out.\r\n", ip);
    }

    // If there's another one to send, send it.
    if ((true == icmp_msg_data.active) && (icmp_msg_data.seq < icmp_msg_data.iterations))
    {
        // Count how many were sent.
        icmp_msg_data.seq++;

        // Send the next request.
        icmp_msg_data.total++;
        icmp_msg_data.response = false;

        err_t err = icmp_send_request(&icmp_msg_data.addr, ICMP_ECHO, 0, icmp_msg_data.total, icmp_msg_data.seq, icmp_msg_data.size);
        if (ERR_OK != err)
        {
            PRINT("Failed to send ping (%d)\r\n", err);
            stop = true;
        }
    }
    else
    {
        stop = true;
    }

    if (true == stop)
    {
        icmp_stop_pings(NULL);
    }
    else
    {
        // Set the next timeout for receipt.
        sys_timeout(ICMP_TIMER_TIMEOUT_MS, icmp_msg_timeout, NULL);
    }
}


/// @brief The callback for received responses.
/// @param arg The input argument.
/// @param iphdr The message, starting with the IP header.
/// @return ERR_CONSUMED if the message was expected, ERR_OK if not.
static err_t icmp_msg_callback(void *arg, uint8_t* payload)
{
    uint64_t now = SysTick_GetTickUs();
    struct ip_hdr *iphdr = (struct ip_hdr *)payload;
    s16_t hlen  = IPH_HL(iphdr) * 4;
    ip_addr_t *dstaddr = (ip_addr_t *)&iphdr->dest;
    ip_addr_t *srcaddr = (ip_addr_t *)&iphdr->src;

    // Get the netif instance.
    struct netif *netif = TC6LwIP_GetNetIf(0);

    // Is this ping for us?
    if (compare_longs(&dstaddr->addr, &netif->ip_addr.addr) && compare_longs(&srcaddr->addr, &icmp_msg_data.addr.addr))
    {
        struct icmp_echo_hdr *iecho;

        // Point to the ICMP header.  All start with the type and code.
        iecho = (struct icmp_echo_hdr *)((uint8_t *)iphdr + hlen);

        switch (iecho->type)
        {
            case ICMP_ECHO:
            {
                // If we get an ICMP_ECHO to us from us, it's us pinging ourselves.
                // Otherwise this is not our ECHO, so let the stack handle it.
                if (!compare_longs(&dstaddr->addr, &srcaddr->addr))
                {
                    return ERR_OK;
                }
            }
            // fallthrough is deliberate

            // We can expect these as replies.
            case ICMP_ER:
            case ICMP_DUR:
            {
                // A response was received!
                icmp_msg_data.response = true;

                char ip[16] = {0};
                build_ip_string(ip, &icmp_msg_data.addr);

                if (1 == icmp_msg_data.seq)
                {
                    PRINT("\r\n");
                }

                if (ICMP_DUR == iecho->type)
                {
                    PRINT("From %s icmp_seq=%ld Destination Host Unreachable\r\n", ip, icmp_msg_data.seq);
                }
                else
                {
                    uint16_t datalen = PP_HTONS(iphdr->_len) - hlen;

                    // Point to where the timestamp is.  this is a 64 bit value expressed in microseconds.
                    uint8_t *data = (uint8_t *)(iecho + 1);
                    uint64_t msgtime = ((uint64_t)*data << 56) | ((uint64_t)*(data + 1) << 48) | ((uint64_t)*(data + 2) << 40) | ((uint64_t)*(data + 2) << 32) |
                                       ((uint64_t)*(data + 4) << 24) | ((uint64_t)*(data + 5) << 16) | ((uint64_t)*(data + 6) << 8) | ((uint64_t)*(data + 7));
                    uint64_t diff = now - msgtime;

                    // Find min/max and count the number of msec for averaging.
                    if ((0ULL == icmp_msg_data.min) || (diff < icmp_msg_data.min))
                    {
                        icmp_msg_data.min = diff;
                    }

                    if (diff > icmp_msg_data.max)
                    {
                        icmp_msg_data.max = diff;
                    }

                    icmp_msg_data.accum += diff;

                    // We received a response.
                    icmp_msg_data.received++;
                    PRINT("%d bytes from %s: icmp_seq=%u ttl=%d time=%.2f ms\r\n", datalen, ip, PP_HTONS(iecho->seqno), iphdr->_ttl, (double)(diff / 1000.0));
                }
            } break;

            // We do not handle these messages.
            default:
            break;
        }
    }

    return ERR_OK;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PUBLIC FUNCTIONS                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

void icmp_test_start(ip4_addr_t addr)
{
    do
    {
        icmp_msg_data.iterations = ICMP_MAX_PINGS;
        icmp_msg_data.addr.addr = addr.addr;
        icmp_msg_data.size = ICMP_DEFAULT_DATA_SIZE;
        icmp_msg_data.response = false;
        icmp_msg_data.seq = 1;
        icmp_msg_data.received = 0;
        icmp_msg_data.min = 0;
        icmp_msg_data.max = 0;
        icmp_msg_data.accum = 0;

        // Register the callbacks.
        icmp_recv(icmp_msg_callback, NULL);

        // Send the first ping.
        icmp_msg_data.total++;
        icmp_msg_data.start = SysTick_GetTickMs();

        char ip[16] = {0};
        build_ip_string(ip, &icmp_msg_data.addr);
        PRINT("PING %s (%s) %u(%u) bytes of data.\r\n", ip, ip, icmp_msg_data.size, (unsigned int)(icmp_msg_data.size + IP_HLEN + sizeof(struct icmp_echo_hdr)));

        // Set the timeout for receipt.
        icmp_msg_data.active = true;
        sys_timeout(ICMP_TIMER_TIMEOUT_MS, icmp_msg_timeout, NULL);

        err_t err = icmp_send_request(&icmp_msg_data.addr, ICMP_ECHO, 0, icmp_msg_data.total, icmp_msg_data.seq, icmp_msg_data.size);
        if (ERR_OK != err)
        {
            PRINT("Failed to send ping (%d)\r\n", err);
            icmp_msg_data.active = false;
            break;
        }

    } while (0);
}

void icmp_test_stop(void)
{
    icmp_stop_pings(NULL);
}