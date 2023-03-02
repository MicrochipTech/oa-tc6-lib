/*
 * Instance header file for ATSAMD21J17D
 *
 * Copyright (c) 2022 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* file generated from device description version 2020-11-19T13:00:05Z */
#ifndef _SAMD21_TCC0_INSTANCE_
#define _SAMD21_TCC0_INSTANCE_


/* ========== Instance Parameter definitions for TCC0 peripheral ========== */
#define TCC0_CC_NUM                              (4)        /* Number of Compare/Capture units */
#define TCC0_DITHERING                           (1)        /* Dithering feature implemented */
#define TCC0_DMAC_ID_OVF                         (13)       /* DMA overflow/underflow/retrigger trigger */
#define TCC0_DMAC_ID_MC0                         (14)       /* DMA Match/Compare 0 trigger */
#define TCC0_DMAC_ID_MC1                         (15)       /* DMA Match/Compare 1 trigger */
#define TCC0_DMAC_ID_MC2                         (16)       /* DMA Match/Compare 2 trigger */
#define TCC0_DMAC_ID_MC3                         (17)       /* DMA Match/Compare 3 trigger */
#define TCC0_DTI                                 (1)        /* Dead-Time-Insertion feature implemented */
#define TCC0_EXT                                 (31)       /* (@_DITHERING*16+@_PG*8+@_SWAP*4+@_DTI*2+@_OTMX*1) */
#define TCC0_GCLK_ID                             (26)       /* Index of Generic Clock */
#define TCC0_MASTER                              (0)        
#define TCC0_OTMX                                (1)        /* Output Matrix feature implemented */
#define TCC0_OW_NUM                              (8)        /* Number of Output Waveforms */
#define TCC0_PG                                  (1)        /* Pattern Generation feature implemented */
#define TCC0_SIZE                                (24)       
#define TCC0_SWAP                                (1)        /* DTI outputs swap feature implemented */
#define TCC0_TYPE                                (1)        /* TCC type 0 : NA, 1 : Master, 2 : Slave */
#define TCC0_INSTANCE_ID                         (72)       

#endif /* _SAMD21_TCC0_INSTANCE_ */
