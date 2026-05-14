/*
 * Copyright (C) 2017 - 2019 Xilinx, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 */

/* Connection handle for a UDP Client session */

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "lwip/udp.h"
#include "udp_perf_client.h"
#include "systick.h"
#include "tc6-lwip.h" /* For performance improvement addon */

#define START_DELAY  (10)

#define GET_TICKS SysTick_GetTickMs

static uint32_t startDelay = 0;
static bool running = false;
static struct perf_stats client;
static struct perf_stats server;
static ip_addr_t remoteIP;
static struct udp_pcb *sock[NUM_OF_PARALLEL_CLIENTS];
static uint32_t packet_id[NUM_OF_PARALLEL_CLIENTS] = { 0 };
static uint8_t iPayload[UDP_SEND_BUFSIZE];
static uint16_t iPayloadSize = UDP_SEND_BUFSIZE;

#define FINISH    1
/* Report interval time in ms */
#define REPORT_INTERVAL_TIME (INTERIM_REPORT_INTERVAL * 1000)
/* End time in ms */
#define END_TIME (UDP_TIME_INTERVAL * 1000)

/* labels for formats [KMG] */
const char kLabel[] =
{
    ' ',
    'K',
    'M',
    'G'
};

void iperf_print_app_header(void)
{
    printf("UDP client connecting to %s on port %d\r\n",
            UDP_SERVER_IP_ADDRESS, UDP_CONN_PORT);
    printf("On Host: Run $iperf -s -i %d -u\r\r\n\n",
            INTERIM_REPORT_INTERVAL);
}

static void print_udp_conn_stats(void)
{
    printf("[%3d] connected with ", client.client_id);
    printf("%s port %d\r\n", UDP_SERVER_IP_ADDRESS, UDP_CONN_PORT);
    printf("[ ID] Interval\t\tTransfer   Bandwidth\r\n");
}

static void stats_buffer(char* outString,
        uint32_t data, enum measure_t type)
{
    const uint32_t mega = 1000000;
    sprintf(outString, "%ld.%ld %c", data/mega, data%mega, 'M');
}


/* The report function of a UDP client session */
static void udp_conn_report(uint32_t diff,
        enum report_type report_type)
{
    uint32_t total_len;
    uint32_t duration, bandwidth = 0;
    char data[16], perf[16], time[64];

    if (report_type == INTER_REPORT) {
        total_len = client.i_report.total_bytes;
    } else {
        client.i_report.last_report_time = 0;
        total_len = client.total_bytes;
    }

    /* Converting duration from milliseconds to secs,
     * and bandwidth to bits/sec .
     */
    duration = diff / 1000; /* secs */
    if (duration)
        bandwidth = (total_len / duration) * 8;

    stats_buffer(data, total_len, BYTES);
    stats_buffer(perf, bandwidth, SPEED);

    /* On 32-bit platforms, xil_printf is not able to print
     * uint32_t values, so converting these values in strings and
     * displaying results
     */
    sprintf(time, "%ld-%ld sec",
            client.i_report.last_report_time,
            (client.i_report.last_report_time + duration));
    printf("[%3d] %s  %sBytes  %sbits/sec\r\n", client.client_id,
            time, data, perf);

    if (report_type == INTER_REPORT)
        client.i_report.last_report_time += duration;
    else
        printf("[%3d] sent %lu datagrams\r\n",
                client.client_id, client.cnt_datagrams);
}

static void reset_stats(void)
{
    client.client_id++;

    /* Print connection statistics */
    print_udp_conn_stats();

    /* Save start time for final report */
    client.start_time = GET_TICKS();
    client.total_bytes = 0;
    client.cnt_datagrams = 0;

    /* Initialize Interim report parameters */
    client.i_report.start_time = 0;
    client.i_report.total_bytes = 0;
    client.i_report.last_report_time = 0;
}

static int udp_packet_send(u8_t finished)
{
    int32_t i, *payload;
    for (i = 0; !TC6LwIP_SendWouldBlock(0) && (i < NUM_OF_PARALLEL_CLIENTS); i++) {
        struct pbuf *send_buf;
        int32_t result;
        send_buf = pbuf_alloc(PBUF_TRANSPORT, iPayloadSize, PBUF_POOL);
        if (!send_buf) {
            return 0;
        }
        if (pbuf_take(send_buf, iPayload, iPayloadSize) == ERR_OK) {
            payload = (int32_t*) send_buf->payload;
            if (finished == FINISH) {
                packet_id[i] = -1;
            } else {
                packet_id[i]++;
            }
            *payload = htonl(packet_id[i]);
        } else {
            assert(send_buf->ref != 0);
            pbuf_free(send_buf);
            printf("UDP Iperf: Can not take send buffer\r\n");
            return 0;
        }
        result = udp_sendto(sock[i], send_buf, &remoteIP, UDP_CONN_PORT);
        if (ERR_OK == result) {
            client.total_bytes += iPayloadSize;
            client.cnt_datagrams++;
            client.i_report.total_bytes += iPayloadSize;
            assert(send_buf->ref != 0);
            pbuf_free(send_buf);
            send_buf = NULL;
            return 0;
        } else if ((ERR_WOULDBLOCK == result) || (ERR_ARP == result) || (ERR_MEM == result)) {
            assert(send_buf->ref != 0);
            if (finished != FINISH) {
                packet_id[i]--;
            }
            pbuf_free(send_buf);
            send_buf = NULL;
            return 0;
        } else {
            /* Terminate this app */
            uint32_t now = GET_TICKS();
            uint32_t diff_ms = now - client.start_time;
            printf("Send failed with error code=%ld, ", result);
            printf("Terminating application\r\n");
            udp_conn_report(diff_ms, UDP_DONE_CLIENT);
            printf("UDP test failed\r\n");
            assert(send_buf->ref != 0);
            pbuf_free(send_buf);
            send_buf = NULL;
            running = false;
            return -1;
        }
    }
    return 0;
}

/* Transmit data on a udp session */
static int transfer_data(void)
{
    if (END_TIME || REPORT_INTERVAL_TIME) {
        uint32_t now = GET_TICKS();
        if (REPORT_INTERVAL_TIME) {
            if (client.i_report.start_time) {
                uint32_t diff_ms = now - client.i_report.start_time;
                if (diff_ms >= REPORT_INTERVAL_TIME) {
                    udp_conn_report(diff_ms, INTER_REPORT);
                    client.i_report.start_time = 0;
                    client.i_report.total_bytes = 0;
                }
            } else {
                client.i_report.start_time = now;
            }
        }

        if (END_TIME) {
            /* this session is time-limited */
            uint32_t diff_ms = now - client.start_time;
            if (diff_ms >= END_TIME) {
                /* time specified is over,
                 * close the connection */
                udp_packet_send(FINISH);
                udp_conn_report(diff_ms, UDP_DONE_CLIENT);
                printf("UDP test passed Successfully\r\n");
                running = false;
                return FINISH;
            }
        }
    }

    if (udp_packet_send(!FINISH) < 0)
        return FINISH;

    return 0;
}

static void OnReceive(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, short unsigned int port)
{
    server.cnt_datagrams++;
    server.total_bytes += p->tot_len;
    pbuf_free(p);
}

static void PrintServerStats(void)
{
    uint32_t now;
    if (!server.cnt_datagrams)
        return;
    now = GET_TICKS();
    if (now - server.start_time >= 1000) {
        server.start_time = now;
        printf("IPERF RX bandwidth=%ld kbit/s packets=%ld 1/s\r\n", (server.total_bytes * 8 / 1000), server.cnt_datagrams);
        server.total_bytes = 0;
        server.cnt_datagrams = 0;
    }
}

void iperf_init(void)
{
    uint32_t i;
    memset(&server, 0, sizeof(server));

    if (!ipaddr_aton(UDP_SERVER_IP_ADDRESS, &remoteIP)) {
        printf("UDP client: Remote IP wrong formated\r\n");
    }

    for (i = 0; i < NUM_OF_PARALLEL_CLIENTS; i++) {
        if ((sock[i] = udp_new()) == NULL) {
            printf("UDP client: Error creating Socket\r\n");
            return;
        }
        if (0 == i) {
            if (ERR_OK != udp_bind(sock[i], IP_ADDR_ANY, UDP_CONN_PORT)) {
                printf("UDP client: Error binding Socket\r\n");
                return;
            }
            udp_recv(sock[i], OnReceive, NULL);
        }
    }

    /* initialize data buffer being sent with same as used in iperf */
    for (i = 0; i < UDP_SEND_BUFSIZE; i++) {
        iPayload[i] = (i % 10) + '0';
    }
}

void iperf_start_application(void)
{
    running = false;
    startDelay = GET_TICKS();
    reset_stats();
    transfer_data();
}

void iperf_stop_application(void)
{
    running = false;
}

bool iperf_get_running_state(void)
{
    return running || (0 != startDelay);
}

void iperf_service(void)
{
    if (startDelay && ((GET_TICKS() - startDelay) > START_DELAY)) {
        startDelay = 0;
        running = true;
    }
    if (running) {
        transfer_data();
    }
    PrintServerStats();
}

void iperf_set_packet_size(uint16_t packetLength)
{
    if (packetLength < UDP_SEND_BUFSIZE) {
        iPayloadSize = packetLength;
    } else {
        iPayloadSize = UDP_SEND_BUFSIZE;
    }
    printf("iperf packet size set to %d Bytes\r\n", iPayloadSize);
}