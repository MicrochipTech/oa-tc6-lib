/*******************************************************************************
 Cortex-M device vectors file

  Company:
    Microchip Technology Inc.

  File Name:
    device_vectors.h

  Summary:
    Harmony3 device handler structure for cortex-M devices

  Description:
    This file contains Harmony3 device handler structure for cortex-M devices
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END

#ifndef DEVICE_VECTORS_H
#define DEVICE_VECTORS_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/* Function pointer type for vector handlers */
typedef void (*pfn_handler_t)(void);

/* Structure defining device vector types */
typedef struct H3DeviceVectorsTag
{
  /* Stack pointer */
  uint32_t* pvStack;

  /* CORTEX-M7 handlers */ 
  pfn_handler_t pfnReset_Handler;                   /* -15 Reset Vector, invoked on Power up and warm reset */
  pfn_handler_t pfnNonMaskableInt_Handler;          /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  pfn_handler_t pfnHardFault_Handler;               /* -13 Hard Fault, all classes of Fault */
  pfn_handler_t pfnMemoryManagement_Handler;        /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  pfn_handler_t pfnBusFault_Handler;                /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  pfn_handler_t pfnUsageFault_Handler;              /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  pfn_handler_t pfnReservedC9;
  pfn_handler_t pfnReservedC8;
  pfn_handler_t pfnReservedC7;
  pfn_handler_t pfnReservedC6;
  pfn_handler_t pfnSVCall_Handler;                  /* -5 System Service Call via SVC instruction */
  pfn_handler_t pfnDebugMonitor_Handler;            /* -4 Debug Monitor */
  pfn_handler_t pfnReservedC3;
  pfn_handler_t pfnPendSV_Handler;                  /* -2 Pendable request for system service */
  pfn_handler_t pfnSysTick_Handler;                 /* -1 System Tick Timer */

  /* Peripheral handlers */
  pfn_handler_t pfnSUPC_Handler;                    /* 0 Supply Controller */
  pfn_handler_t pfnRSTC_Handler;                    /* 1 Reset Controller */
  pfn_handler_t pfnRTC_Handler;                     /* 2 Real Time Clock */
  pfn_handler_t pfnRTT_Handler;                     /* 3 Real Time Timer */
  pfn_handler_t pfnWDT_Handler;                     /* 4 Watchdog Timer */
  pfn_handler_t pfnPMC_Handler;                     /* 5 Power Management Controller */
  pfn_handler_t pfnEFC_Handler;                     /* 6 Enhanced Embedded Flash Controller */
  pfn_handler_t pfnUART0_Handler;                   /* 7 UART 0 */
  pfn_handler_t pfnUART1_Handler;                   /* 8 UART 1 */
  pfn_handler_t pfnReserved9;
  pfn_handler_t pfnPIOA_Handler;                    /* 10 Parallel I/O Controller A */
  pfn_handler_t pfnPIOB_Handler;                    /* 11 Parallel I/O Controller B */
  pfn_handler_t pfnPIOC_Handler;                    /* 12 Parallel I/O Controller C */
  pfn_handler_t pfnUSART0_Handler;                  /* 13 USART 0 */
  pfn_handler_t pfnUSART1_Handler;                  /* 14 USART 1 */
  pfn_handler_t pfnUSART2_Handler;                  /* 15 USART 2 */
  pfn_handler_t pfnPIOD_Handler;                    /* 16 Parallel I/O Controller D */
  pfn_handler_t pfnPIOE_Handler;                    /* 17 Parallel I/O Controller E */
  pfn_handler_t pfnHSMCI_Handler;                   /* 18 Multimedia Card Interface */
  pfn_handler_t pfnTWIHS0_Handler;                  /* 19 Two Wire Interface 0 HS */
  pfn_handler_t pfnTWIHS1_Handler;                  /* 20 Two Wire Interface 1 HS */
  pfn_handler_t pfnSPI0_Handler;                    /* 21 Serial Peripheral Interface 0 */
  pfn_handler_t pfnSSC_Handler;                     /* 22 Synchronous Serial Controller */
  pfn_handler_t pfnTC0_CH0_Handler;                 /* 23 Timer/Counter 0 Channel 0 */
  pfn_handler_t pfnTC0_CH1_Handler;                 /* 24 Timer/Counter 0 Channel 1 */
  pfn_handler_t pfnTC0_CH2_Handler;                 /* 25 Timer/Counter 0 Channel 2 */
  pfn_handler_t pfnTC1_CH0_Handler;                 /* 26 Timer/Counter 1 Channel 0 */
  pfn_handler_t pfnTC1_CH1_Handler;                 /* 27 Timer/Counter 1 Channel 1 */
  pfn_handler_t pfnTC1_CH2_Handler;                 /* 28 Timer/Counter 1 Channel 2 */
  pfn_handler_t pfnAFEC0_Handler;                   /* 29 Analog Front End 0 */
  pfn_handler_t pfnDACC_Handler;                    /* 30 Digital To Analog Converter */
  pfn_handler_t pfnPWM0_Handler;                    /* 31 Pulse Width Modulation 0 */
  pfn_handler_t pfnICM_Handler;                     /* 32 Integrity Check Monitor */
  pfn_handler_t pfnACC_Handler;                     /* 33 Analog Comparator */
  pfn_handler_t pfnUSBHS_Handler;                   /* 34 USB Host / Device Controller */
  pfn_handler_t pfnMCAN0_INT0_Handler;              /* 35 MCAN Controller 0 Interrupt 0 */
  pfn_handler_t pfnMCAN0_INT1_Handler;              /* 36 MCAN Controller 0 Interrupt 1 */
  pfn_handler_t pfnMCAN1_INT0_Handler;              /* 37 MCAN Controller 1 Interrupt 0 */
  pfn_handler_t pfnMCAN1_INT1_Handler;              /* 38 MCAN Controller 1 Interrupt 1 */
  pfn_handler_t pfnGMAC_Handler;                    /* 39 Ethernet MAC */
  pfn_handler_t pfnAFEC1_Handler;                   /* 40 Analog Front End 1 */
  pfn_handler_t pfnTWIHS2_Handler;                  /* 41 Two Wire Interface 2 HS */
  pfn_handler_t pfnSPI1_Handler;                    /* 42 Serial Peripheral Interface 1 */
  pfn_handler_t pfnQSPI_Handler;                    /* 43 Quad I/O Serial Peripheral Interface */
  pfn_handler_t pfnUART2_Handler;                   /* 44 UART 2 */
  pfn_handler_t pfnUART3_Handler;                   /* 45 UART 3 */
  pfn_handler_t pfnUART4_Handler;                   /* 46 UART 4 */
  pfn_handler_t pfnTC2_CH0_Handler;                 /* 47 Timer/Counter 2 Channel 0 */
  pfn_handler_t pfnTC2_CH1_Handler;                 /* 48 Timer/Counter 2 Channel 1 */
  pfn_handler_t pfnTC2_CH2_Handler;                 /* 49 Timer/Counter 2 Channel 2 */
  pfn_handler_t pfnTC3_CH0_Handler;                 /* 50 Timer/Counter 3 Channel 0 */
  pfn_handler_t pfnTC3_CH1_Handler;                 /* 51 Timer/Counter 3 Channel 1 */
  pfn_handler_t pfnTC3_CH2_Handler;                 /* 52 Timer/Counter 3 Channel 2 */
  pfn_handler_t pfnMLB_Handler;                     /* 53 MediaLB */
  pfn_handler_t pfnReserved54;
  pfn_handler_t pfnReserved55;
  pfn_handler_t pfnAES_Handler;                     /* 56 AES */
  pfn_handler_t pfnTRNG_Handler;                    /* 57 True Random Generator */
  pfn_handler_t pfnXDMAC_Handler;                   /* 58 DMA */
  pfn_handler_t pfnISI_Handler;                     /* 59 Camera Interface */
  pfn_handler_t pfnPWM1_Handler;                    /* 60 Pulse Width Modulation 1 */
  pfn_handler_t pfnFPU_Handler;                     /* 61 Floating Point Unit */
  pfn_handler_t pfnReserved62;
  pfn_handler_t pfnRSWDT_Handler;                   /* 63 Reinforced Secure Watchdog Timer */
  pfn_handler_t pfnCCW_Handler;                     /* 64 Cache ECC Warning */
  pfn_handler_t pfnCCF_Handler;                     /* 65 Cache ECC Fault */
  pfn_handler_t pfnGMAC_Q1_Handler;                 /* 66 GMAC Queue 1 */
  pfn_handler_t pfnGMAC_Q2_Handler;                 /* 67 GMAC Queue 2 */
  pfn_handler_t pfnIXC_Handler;                     /* 68 Floating Point Unit IXC */
  pfn_handler_t pfnI2SC0_Handler;                   /* 69 Inter-IC Sound controller 0 */
  pfn_handler_t pfnI2SC1_Handler;                   /* 70 Inter-IC Sound controller 1 */
  pfn_handler_t pfnGMAC_Q3_Handler;                 /* 71 GMAC Queue 3 */
  pfn_handler_t pfnGMAC_Q4_Handler;                 /* 72 GMAC Queue 4 */
  pfn_handler_t pfnGMAC_Q5_Handler;                 /* 73 GMAC Queue 5 */
}H3DeviceVectors;

#endif //DEVICE_VECTORS_H
