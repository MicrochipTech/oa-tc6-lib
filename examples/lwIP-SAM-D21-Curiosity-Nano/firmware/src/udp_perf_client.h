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
 * Source from: https://github.com/Xilinx/embeddedsw/tree/master/lib/sw_apps/freertos_lwip_udp_perf_client/src
 */

#ifndef __UDP_PERF_CLIENT_H_
#define __UDP_PERF_CLIENT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "lwipopts.h"
#include "lwip/ip_addr.h"
#include "lwip/err.h"
#include "lwip/udp.h"
#include "lwip/inet.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include "errno.h"

/* used as indices into kLabel[] */
enum {
    KCONV_UNIT,
    KCONV_KILO,
    KCONV_MEGA,
    KCONV_GIGA,
};

/* used as type of print */
enum measure_t {
    BYTES,
    SPEED
};

/* Report Type */
enum report_type {
    /* The Intermediate report */
    INTER_REPORT,
    /* The client side test is done */
    UDP_DONE_CLIENT,
    /* Remote side aborted the test */
    UDP_ABORTED_REMOTE
};

struct interim_report {
    uint32_t start_time;
    uint32_t last_report_time;
    uint32_t total_bytes;
};

struct perf_stats {
    uint8_t client_id;
    uint32_t start_time;
    uint32_t total_bytes;
    uint32_t cnt_datagrams;
    struct interim_report i_report;
};

/* seconds between periodic bandwidth reports */
#define INTERIM_REPORT_INTERVAL 5

/* Client port to connect */
#define UDP_CONN_PORT 5001

/* time in seconds to transmit packets */
#define UDP_TIME_INTERVAL 300

/* Server to connect with */
#define UDP_SERVER_IP_ADDRESS "192.168.0.5"

/* UDP buffer length in bytes */
#define UDP_SEND_BUFSIZE 1460

/* Number of parallel UDP clients */
#define NUM_OF_PARALLEL_CLIENTS 1

void iperf_init(void);
void iperf_print_app_header(void);
void iperf_start_application(void);
void iperf_stop_application(void);
bool iperf_get_running_state(void);
void iperf_service(void);
void iperf_set_packet_size(uint16_t packetLength);

#ifdef __cplusplus
}
#endif
#endif /* __UDP_PERF_CLIENT_H_ */
