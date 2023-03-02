/*
 * Header file for ATSAMV71Q21B
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

/* File generated from device description version 2022-04-21T07:58:40Z */
#ifndef _SAMV71Q21B_H_
#define _SAMV71Q21B_H_

/* Header version uses Semantic Versioning 2.0.0 (https://semver.org/) */
#define HEADER_FORMAT_VERSION "2.1.0"

#define HEADER_FORMAT_VERSION_MAJOR (2)
#define HEADER_FORMAT_VERSION_MINOR (1)
#define HEADER_FORMAT_VERSION_PATCH (0)

/* SAMV71Q21B definitions
  This file defines all structures and symbols for SAMV71Q21B:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
*/

#ifdef __cplusplus
 extern "C" {
#endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  include <stdint.h>
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !defined(SKIP_INTEGER_LITERALS)
#  if defined(_UINT8_) || defined(_UINT16_) || defined(_UINT32_)
#    error "Integer constant value macros already defined elsewhere"
#  endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Macros that deal with sizes of integer constants for C/C++ */
#  define _UINT8_(x)   ((uint8_t)(x))    /* C code: 8-bits unsigned integer constant value */
#  define _UINT16_(x)  ((uint16_t)(x))   /* C code: 16-bits unsigned integer constant value */
#  define _UINT32_(x)  ((uint32_t)(x))   /* C code: 32-bits unsigned integer constant value */

#else /* Assembler */

#  define _UINT8_(x) x    /* Assembler: 8-bits unsigned integer constant value */
#  define _UINT16_(x) x   /* Assembler: 16-bits unsigned integer constant value */
#  define _UINT32_(x) x   /* Assembler: 32-bits unsigned integer constant value */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* SKIP_INTEGER_LITERALS */

/* ************************************************************************** */
/* CMSIS DEFINITIONS FOR SAMV71Q21B                                         */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Interrupt Number Definition */
typedef enum IRQn
{
/******  CORTEX-M7 Processor Exceptions Numbers ******************************/
  Reset_IRQn                = -15, /* -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn       = -14, /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn            = -13, /* -13 Hard Fault, all classes of Fault    */
  MemoryManagement_IRQn     = -12, /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn             = -11, /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  UsageFault_IRQn           = -10, /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  SVCall_IRQn               =  -5, /* -5  System Service Call via SVC instruction */
  DebugMonitor_IRQn         =  -4, /* -4  Debug Monitor                       */
  PendSV_IRQn               =  -2, /* -2  Pendable request for system service */
  SysTick_IRQn              =  -1, /* -1  System Tick Timer                   */

/******  SAMV71Q21B specific Interrupt Numbers ***********************************/
  SUPC_IRQn                 =   0, /* 0   Supply Controller (SUPC)            */
  RSTC_IRQn                 =   1, /* 1   Reset Controller (RSTC)             */
  RTC_IRQn                  =   2, /* 2   Real-time Clock (RTC)               */
  RTT_IRQn                  =   3, /* 3   Real-time Timer (RTT)               */
  WDT_IRQn                  =   4, /* 4   Watchdog Timer (WDT)                */
  PMC_IRQn                  =   5, /* 5   Power Management Controller (PMC)   */
  EFC_IRQn                  =   6, /* 6   Embedded Flash Controller (EFC)     */
  UART0_IRQn                =   7, /* 7   Universal Asynchronous Receiver Transmitter (UART0) */
  UART1_IRQn                =   8, /* 8   Universal Asynchronous Receiver Transmitter (UART1) */
  PIOA_IRQn                 =  10, /* 10  Parallel Input/Output Controller (PIOA) */
  PIOB_IRQn                 =  11, /* 11  Parallel Input/Output Controller (PIOB) */
  PIOC_IRQn                 =  12, /* 12  Parallel Input/Output Controller (PIOC) */
  USART0_IRQn               =  13, /* 13  Universal Synchronous Asynchronous Receiver Transmitter (USART0) */
  USART1_IRQn               =  14, /* 14  Universal Synchronous Asynchronous Receiver Transmitter (USART1) */
  USART2_IRQn               =  15, /* 15  Universal Synchronous Asynchronous Receiver Transmitter (USART2) */
  PIOD_IRQn                 =  16, /* 16  Parallel Input/Output Controller (PIOD) */
  PIOE_IRQn                 =  17, /* 17  Parallel Input/Output Controller (PIOE) */
  HSMCI_IRQn                =  18, /* 18  High Speed MultiMedia Card Interface (HSMCI) */
  TWIHS0_IRQn               =  19, /* 19  Two-wire Interface High Speed (TWIHS0) */
  TWIHS1_IRQn               =  20, /* 20  Two-wire Interface High Speed (TWIHS1) */
  SPI0_IRQn                 =  21, /* 21  Serial Peripheral Interface (SPI0)  */
  SSC_IRQn                  =  22, /* 22  Synchronous Serial Controller (SSC) */
  TC0_CH0_IRQn              =  23, /* 23  Timer/Counter 0 Channel 0 (TC0)     */
  TC0_CH1_IRQn              =  24, /* 24  Timer/Counter 0 Channel 1 (TC0)     */
  TC0_CH2_IRQn              =  25, /* 25  Timer/Counter 0 Channel 2 (TC0)     */
  TC1_CH0_IRQn              =  26, /* 26  Timer/Counter 1 Channel 0 (TC1)     */
  TC1_CH1_IRQn              =  27, /* 27  Timer/Counter 1 Channel 1 (TC1)     */
  TC1_CH2_IRQn              =  28, /* 28  Timer/Counter 1 Channel 2 (TC1)     */
  AFEC0_IRQn                =  29, /* 29  Analog Front-End Controller (AFEC0) */
  DACC_IRQn                 =  30, /* 30  Digital-to-Analog Converter Controller (DACC) */
  PWM0_IRQn                 =  31, /* 31  Pulse Width Modulation Controller (PWM0) */
  ICM_IRQn                  =  32, /* 32  Integrity Check Monitor (ICM)       */
  ACC_IRQn                  =  33, /* 33  Analog Comparator Controller (ACC)  */
  USBHS_IRQn                =  34, /* 34  USB High-Speed Interface (USBHS)    */
  MCAN0_INT0_IRQn           =  35, /* 35  Controller Area Network (MCAN0)     */
  MCAN0_INT1_IRQn           =  36, /* 36  Controller Area Network (MCAN0)     */
  MCAN1_INT0_IRQn           =  37, /* 37  Controller Area Network (MCAN1)     */
  MCAN1_INT1_IRQn           =  38, /* 38  Controller Area Network (MCAN1)     */
  GMAC_IRQn                 =  39, /* 39  Gigabit Ethernet MAC (GMAC)         */
  AFEC1_IRQn                =  40, /* 40  Analog Front-End Controller (AFEC1) */
  TWIHS2_IRQn               =  41, /* 41  Two-wire Interface High Speed (TWIHS2) */
  SPI1_IRQn                 =  42, /* 42  Serial Peripheral Interface (SPI1)  */
  QSPI_IRQn                 =  43, /* 43  Quad Serial Peripheral Interface (QSPI) */
  UART2_IRQn                =  44, /* 44  Universal Asynchronous Receiver Transmitter (UART2) */
  UART3_IRQn                =  45, /* 45  Universal Asynchronous Receiver Transmitter (UART3) */
  UART4_IRQn                =  46, /* 46  Universal Asynchronous Receiver Transmitter (UART4) */
  TC2_CH0_IRQn              =  47, /* 47  Timer/Counter 2 Channel 0 (TC2)     */
  TC2_CH1_IRQn              =  48, /* 48  Timer/Counter 2 Channel 1 (TC2)     */
  TC2_CH2_IRQn              =  49, /* 49  Timer/Counter 2 Channel 2 (TC2)     */
  TC3_CH0_IRQn              =  50, /* 50  Timer/Counter 3 Channel 0 (TC3)     */
  TC3_CH1_IRQn              =  51, /* 51  Timer/Counter 3 Channel 1 (TC3)     */
  TC3_CH2_IRQn              =  52, /* 52  Timer/Counter 3 Channel 2 (TC3)     */
  MLB_IRQn                  =  53, /* 53  MediaLB (MLB)                       */
  AES_IRQn                  =  56, /* 56  Advanced Encryption Standard (AES)  */
  TRNG_IRQn                 =  57, /* 57  True Random Number Generator (TRNG) */
  XDMAC_IRQn                =  58, /* 58  Extensible DMA Controller (XDMAC)   */
  ISI_IRQn                  =  59, /* 59  Image Sensor Interface (ISI)        */
  PWM1_IRQn                 =  60, /* 60  Pulse Width Modulation Controller (PWM1) */
  FPU_IRQn                  =  61, /* 61  Floating Point Unit (FPU)           */
  RSWDT_IRQn                =  63, /* 63  Reinforced Safety Watchdog Timer (RSWDT) */
  CCW_IRQn                  =  64, /* 64  System Control Block (SCB)          */
  CCF_IRQn                  =  65, /* 65  System Control Block (SCB)          */
  GMAC_Q1_IRQn              =  66, /* 66  Gigabit Ethernet MAC (GMAC)         */
  GMAC_Q2_IRQn              =  67, /* 67  Gigabit Ethernet MAC (GMAC)         */
  IXC_IRQn                  =  68, /* 68  Floating Point Unit (FPU)           */
  I2SC0_IRQn                =  69, /* 69  Inter-IC Sound Controller (I2SC0)   */
  I2SC1_IRQn                =  70, /* 70  Inter-IC Sound Controller (I2SC1)   */
  GMAC_Q3_IRQn              =  71, /* 71  Gigabit Ethernet MAC (GMAC)         */
  GMAC_Q4_IRQn              =  72, /* 72  Gigabit Ethernet MAC (GMAC)         */
  GMAC_Q5_IRQn              =  73, /* 73  Gigabit Ethernet MAC (GMAC)         */

  PERIPH_MAX_IRQn           =  73  /* Max peripheral ID */
} IRQn_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct _DeviceVectors
{
  /* Stack pointer */
  void* pvStack;
  /* CORTEX-M7 handlers */
  void* pfnReset_Handler;                        /* -15 Reset Vector, invoked on Power up and warm reset */
  void* pfnNonMaskableInt_Handler;               /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  void* pfnHardFault_Handler;                    /* -13 Hard Fault, all classes of Fault */
  void* pfnMemoryManagement_Handler;             /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  void* pfnBusFault_Handler;                     /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  void* pfnUsageFault_Handler;                   /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  void* pvReservedC9;
  void* pvReservedC8;
  void* pvReservedC7;
  void* pvReservedC6;
  void* pfnSVCall_Handler;                       /*  -5 System Service Call via SVC instruction */
  void* pfnDebugMonitor_Handler;                 /*  -4 Debug Monitor */
  void* pvReservedC3;
  void* pfnPendSV_Handler;                       /*  -2 Pendable request for system service */
  void* pfnSysTick_Handler;                      /*  -1 System Tick Timer */

  /* Peripheral handlers */
  void* pfnSUPC_Handler;                         /*   0 Supply Controller (SUPC) */
  void* pfnRSTC_Handler;                         /*   1 Reset Controller (RSTC) */
  void* pfnRTC_Handler;                          /*   2 Real-time Clock (RTC) */
  void* pfnRTT_Handler;                          /*   3 Real-time Timer (RTT) */
  void* pfnWDT_Handler;                          /*   4 Watchdog Timer (WDT) */
  void* pfnPMC_Handler;                          /*   5 Power Management Controller (PMC) */
  void* pfnEFC_Handler;                          /*   6 Embedded Flash Controller (EFC) */
  void* pfnUART0_Handler;                        /*   7 Universal Asynchronous Receiver Transmitter (UART0) */
  void* pfnUART1_Handler;                        /*   8 Universal Asynchronous Receiver Transmitter (UART1) */
  void* pvReserved9;
  void* pfnPIOA_Handler;                         /*  10 Parallel Input/Output Controller (PIOA) */
  void* pfnPIOB_Handler;                         /*  11 Parallel Input/Output Controller (PIOB) */
  void* pfnPIOC_Handler;                         /*  12 Parallel Input/Output Controller (PIOC) */
  void* pfnUSART0_Handler;                       /*  13 Universal Synchronous Asynchronous Receiver Transmitter (USART0) */
  void* pfnUSART1_Handler;                       /*  14 Universal Synchronous Asynchronous Receiver Transmitter (USART1) */
  void* pfnUSART2_Handler;                       /*  15 Universal Synchronous Asynchronous Receiver Transmitter (USART2) */
  void* pfnPIOD_Handler;                         /*  16 Parallel Input/Output Controller (PIOD) */
  void* pfnPIOE_Handler;                         /*  17 Parallel Input/Output Controller (PIOE) */
  void* pfnHSMCI_Handler;                        /*  18 High Speed MultiMedia Card Interface (HSMCI) */
  void* pfnTWIHS0_Handler;                       /*  19 Two-wire Interface High Speed (TWIHS0) */
  void* pfnTWIHS1_Handler;                       /*  20 Two-wire Interface High Speed (TWIHS1) */
  void* pfnSPI0_Handler;                         /*  21 Serial Peripheral Interface (SPI0) */
  void* pfnSSC_Handler;                          /*  22 Synchronous Serial Controller (SSC) */
  void* pfnTC0_CH0_Handler;                      /*  23 Timer/Counter 0 Channel 0 (TC0) */
  void* pfnTC0_CH1_Handler;                      /*  24 Timer/Counter 0 Channel 1 (TC0) */
  void* pfnTC0_CH2_Handler;                      /*  25 Timer/Counter 0 Channel 2 (TC0) */
  void* pfnTC1_CH0_Handler;                      /*  26 Timer/Counter 1 Channel 0 (TC1) */
  void* pfnTC1_CH1_Handler;                      /*  27 Timer/Counter 1 Channel 1 (TC1) */
  void* pfnTC1_CH2_Handler;                      /*  28 Timer/Counter 1 Channel 2 (TC1) */
  void* pfnAFEC0_Handler;                        /*  29 Analog Front-End Controller (AFEC0) */
  void* pfnDACC_Handler;                         /*  30 Digital-to-Analog Converter Controller (DACC) */
  void* pfnPWM0_Handler;                         /*  31 Pulse Width Modulation Controller (PWM0) */
  void* pfnICM_Handler;                          /*  32 Integrity Check Monitor (ICM) */
  void* pfnACC_Handler;                          /*  33 Analog Comparator Controller (ACC) */
  void* pfnUSBHS_Handler;                        /*  34 USB High-Speed Interface (USBHS) */
  void* pfnMCAN0_INT0_Handler;                   /*  35 Controller Area Network (MCAN0) */
  void* pfnMCAN0_INT1_Handler;                   /*  36 Controller Area Network (MCAN0) */
  void* pfnMCAN1_INT0_Handler;                   /*  37 Controller Area Network (MCAN1) */
  void* pfnMCAN1_INT1_Handler;                   /*  38 Controller Area Network (MCAN1) */
  void* pfnGMAC_Handler;                         /*  39 Gigabit Ethernet MAC (GMAC) */
  void* pfnAFEC1_Handler;                        /*  40 Analog Front-End Controller (AFEC1) */
  void* pfnTWIHS2_Handler;                       /*  41 Two-wire Interface High Speed (TWIHS2) */
  void* pfnSPI1_Handler;                         /*  42 Serial Peripheral Interface (SPI1) */
  void* pfnQSPI_Handler;                         /*  43 Quad Serial Peripheral Interface (QSPI) */
  void* pfnUART2_Handler;                        /*  44 Universal Asynchronous Receiver Transmitter (UART2) */
  void* pfnUART3_Handler;                        /*  45 Universal Asynchronous Receiver Transmitter (UART3) */
  void* pfnUART4_Handler;                        /*  46 Universal Asynchronous Receiver Transmitter (UART4) */
  void* pfnTC2_CH0_Handler;                      /*  47 Timer/Counter 2 Channel 0 (TC2) */
  void* pfnTC2_CH1_Handler;                      /*  48 Timer/Counter 2 Channel 1 (TC2) */
  void* pfnTC2_CH2_Handler;                      /*  49 Timer/Counter 2 Channel 2 (TC2) */
  void* pfnTC3_CH0_Handler;                      /*  50 Timer/Counter 3 Channel 0 (TC3) */
  void* pfnTC3_CH1_Handler;                      /*  51 Timer/Counter 3 Channel 1 (TC3) */
  void* pfnTC3_CH2_Handler;                      /*  52 Timer/Counter 3 Channel 2 (TC3) */
  void* pfnMLB_Handler;                          /*  53 MediaLB (MLB) */
  void* pvReserved54;
  void* pvReserved55;
  void* pfnAES_Handler;                          /*  56 Advanced Encryption Standard (AES) */
  void* pfnTRNG_Handler;                         /*  57 True Random Number Generator (TRNG) */
  void* pfnXDMAC_Handler;                        /*  58 Extensible DMA Controller (XDMAC) */
  void* pfnISI_Handler;                          /*  59 Image Sensor Interface (ISI) */
  void* pfnPWM1_Handler;                         /*  60 Pulse Width Modulation Controller (PWM1) */
  void* pfnFPU_Handler;                          /*  61 Floating Point Unit (FPU) */
  void* pvReserved62;
  void* pfnRSWDT_Handler;                        /*  63 Reinforced Safety Watchdog Timer (RSWDT) */
  void* pfnCCW_Handler;                          /*  64 System Control Block (SCB) */
  void* pfnCCF_Handler;                          /*  65 System Control Block (SCB) */
  void* pfnGMAC_Q1_Handler;                      /*  66 Gigabit Ethernet MAC (GMAC) */
  void* pfnGMAC_Q2_Handler;                      /*  67 Gigabit Ethernet MAC (GMAC) */
  void* pfnIXC_Handler;                          /*  68 Floating Point Unit (FPU) */
  void* pfnI2SC0_Handler;                        /*  69 Inter-IC Sound Controller (I2SC0) */
  void* pfnI2SC1_Handler;                        /*  70 Inter-IC Sound Controller (I2SC1) */
  void* pfnGMAC_Q3_Handler;                      /*  71 Gigabit Ethernet MAC (GMAC) */
  void* pfnGMAC_Q4_Handler;                      /*  72 Gigabit Ethernet MAC (GMAC) */
  void* pfnGMAC_Q5_Handler;                      /*  73 Gigabit Ethernet MAC (GMAC) */
} DeviceVectors;

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if !defined DONT_USE_PREDEFINED_CORE_HANDLERS
/* CORTEX-M7 exception handlers */
void Reset_Handler                 ( void );
void NonMaskableInt_Handler        ( void );
void HardFault_Handler             ( void );
void MemoryManagement_Handler      ( void );
void BusFault_Handler              ( void );
void UsageFault_Handler            ( void );
void SVCall_Handler                ( void );
void DebugMonitor_Handler          ( void );
void PendSV_Handler                ( void );
void SysTick_Handler               ( void );
#endif /* DONT_USE_PREDEFINED_CORE_HANDLERS */

#if !defined DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS
/* Peripherals interrupt handlers */
void SUPC_Handler                  ( void );
void RSTC_Handler                  ( void );
void RTC_Handler                   ( void );
void RTT_Handler                   ( void );
void WDT_Handler                   ( void );
void PMC_Handler                   ( void );
void EFC_Handler                   ( void );
void UART0_Handler                 ( void );
void UART1_Handler                 ( void );
void PIOA_Handler                  ( void );
void PIOB_Handler                  ( void );
void PIOC_Handler                  ( void );
void USART0_Handler                ( void );
void USART1_Handler                ( void );
void USART2_Handler                ( void );
void PIOD_Handler                  ( void );
void PIOE_Handler                  ( void );
void HSMCI_Handler                 ( void );
void TWIHS0_Handler                ( void );
void TWIHS1_Handler                ( void );
void SPI0_Handler                  ( void );
void SSC_Handler                   ( void );
void TC0_CH0_Handler               ( void );
void TC0_CH1_Handler               ( void );
void TC0_CH2_Handler               ( void );
void TC1_CH0_Handler               ( void );
void TC1_CH1_Handler               ( void );
void TC1_CH2_Handler               ( void );
void AFEC0_Handler                 ( void );
void DACC_Handler                  ( void );
void PWM0_Handler                  ( void );
void ICM_Handler                   ( void );
void ACC_Handler                   ( void );
void USBHS_Handler                 ( void );
void MCAN0_INT0_Handler            ( void );
void MCAN0_INT1_Handler            ( void );
void MCAN1_INT0_Handler            ( void );
void MCAN1_INT1_Handler            ( void );
void GMAC_Handler                  ( void );
void AFEC1_Handler                 ( void );
void TWIHS2_Handler                ( void );
void SPI1_Handler                  ( void );
void QSPI_Handler                  ( void );
void UART2_Handler                 ( void );
void UART3_Handler                 ( void );
void UART4_Handler                 ( void );
void TC2_CH0_Handler               ( void );
void TC2_CH1_Handler               ( void );
void TC2_CH2_Handler               ( void );
void TC3_CH0_Handler               ( void );
void TC3_CH1_Handler               ( void );
void TC3_CH2_Handler               ( void );
void MLB_Handler                   ( void );
void AES_Handler                   ( void );
void TRNG_Handler                  ( void );
void XDMAC_Handler                 ( void );
void ISI_Handler                   ( void );
void PWM1_Handler                  ( void );
void FPU_Handler                   ( void );
void RSWDT_Handler                 ( void );
void CCW_Handler                   ( void );
void CCF_Handler                   ( void );
void GMAC_Q1_Handler               ( void );
void GMAC_Q2_Handler               ( void );
void IXC_Handler                   ( void );
void I2SC0_Handler                 ( void );
void I2SC1_Handler                 ( void );
void GMAC_Q3_Handler               ( void );
void GMAC_Q4_Handler               ( void );
void GMAC_Q5_Handler               ( void );
#endif /* DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* Configuration of the CORTEX-M7 Processor and Core Peripherals */
#define __CM7_REV                     0x0101 /* CM7 Core Revision                                                         */
#define __NVIC_PRIO_BITS                   3 /* Number of Bits used for Priority Levels                                   */
#define __Vendor_SysTickConfig             0 /* Set to 1 if different SysTick Config is used                              */
#define __MPU_PRESENT                      1 /* MPU present or not                                                        */
#define __VTOR_PRESENT                     1 /* Vector Table Offset Register present or not                               */
#define __FPU_PRESENT                      1 /* FPU present or not                                                        */
#define __FPU_DP                           1 /* Double Precision FPU                                                      */
#define __ICACHE_PRESENT                   1 /* Instruction Cache present                                                 */
#define __DCACHE_PRESENT                   1 /* Data Cache present                                                        */
#define __ITCM_PRESENT                     1 /* Instruction TCM present                                                   */
#define __DTCM_PRESENT                     1 /* Data TCM present                                                          */
#define __DEBUG_LVL                        1
#define __TRACE_LVL                        1
#define __ARCH_ARM                         1
#define __ARCH_ARM_CORTEX_M                1

/* CMSIS includes */
#include "core_cm7.h"
#if defined USE_CMSIS_INIT
#include "system_samv71.h"
#endif /* USE_CMSIS_INIT */

/* ************************************************************************** */
/*   SOFTWARE PERIPHERAL API DEFINITION FOR SAMV71Q21B                        */
/* ************************************************************************** */
#include "component/acc.h"
#include "component/aes.h"
#include "component/afec.h"
#include "component/chipid.h"
#include "component/dacc.h"
#include "component/efc.h"
#include "component/fuses.h"
#include "component/gmac.h"
#include "component/gpbr.h"
#include "component/hsmci.h"
#include "component/i2sc.h"
#include "component/icm.h"
#include "component/isi.h"
#include "component/matrix.h"
#include "component/mcan.h"
#include "component/mlb.h"
#include "component/pio.h"
#include "component/pmc.h"
#include "component/pwm.h"
#include "component/qspi.h"
#include "component/rstc.h"
#include "component/rswdt.h"
#include "component/rtc.h"
#include "component/rtt.h"
#include "component/smc.h"
#include "component/spi.h"
#include "component/ssc.h"
#include "component/supc.h"
#include "component/tc.h"
#include "component/trng.h"
#include "component/twihs.h"
#include "component/uart.h"
#include "component/usart.h"
#include "component/usbhs.h"
#include "component/utmi.h"
#include "component/wdt.h"
#include "component/xdmac.h"

/* ************************************************************************** */
/*   INSTANCE DEFINITIONS FOR SAMV71Q21B */
/* ************************************************************************** */
#include "instance/acc.h"
#include "instance/aes.h"
#include "instance/afec0.h"
#include "instance/afec1.h"
#include "instance/chipid.h"
#include "instance/dacc.h"
#include "instance/efc.h"
#include "instance/fuses.h"
#include "instance/gmac.h"
#include "instance/gpbr.h"
#include "instance/hsmci.h"
#include "instance/i2sc0.h"
#include "instance/i2sc1.h"
#include "instance/icm.h"
#include "instance/isi.h"
#include "instance/matrix.h"
#include "instance/mcan0.h"
#include "instance/mcan1.h"
#include "instance/mlb.h"
#include "instance/pioa.h"
#include "instance/piob.h"
#include "instance/pioc.h"
#include "instance/piod.h"
#include "instance/pioe.h"
#include "instance/pmc.h"
#include "instance/pwm0.h"
#include "instance/pwm1.h"
#include "instance/qspi.h"
#include "instance/rstc.h"
#include "instance/rswdt.h"
#include "instance/rtc.h"
#include "instance/rtt.h"
#include "instance/smc.h"
#include "instance/spi0.h"
#include "instance/spi1.h"
#include "instance/ssc.h"
#include "instance/supc.h"
#include "instance/tc0.h"
#include "instance/tc1.h"
#include "instance/tc2.h"
#include "instance/tc3.h"
#include "instance/trng.h"
#include "instance/twihs0.h"
#include "instance/twihs1.h"
#include "instance/twihs2.h"
#include "instance/uart0.h"
#include "instance/uart1.h"
#include "instance/uart2.h"
#include "instance/uart3.h"
#include "instance/uart4.h"
#include "instance/usart0.h"
#include "instance/usart1.h"
#include "instance/usart2.h"
#include "instance/usbhs.h"
#include "instance/utmi.h"
#include "instance/wdt.h"
#include "instance/xdmac.h"

/* ************************************************************************** */
/*  PERIPHERAL ID DEFINITIONS FOR SAMV71Q21B                                  */
/* ************************************************************************** */
#define ID_SUPC          (  0) /* Supply Controller (SUPC) */
#define ID_RSTC          (  1) /* Reset Controller (RSTC) */
#define ID_RTC           (  2) /* Real-time Clock (RTC) */
#define ID_RTT           (  3) /* Real-time Timer (RTT) */
#define ID_WDT           (  4) /* Watchdog Timer (WDT) */
#define ID_PMC           (  5) /* Power Management Controller (PMC) */
#define ID_EFC           (  6) /* Embedded Flash Controller (EFC) */
#define ID_UART0         (  7) /* Universal Asynchronous Receiver Transmitter (UART0) */
#define ID_UART1         (  8) /* Universal Asynchronous Receiver Transmitter (UART1) */
#define ID_SMC           (  9) /* Static Memory Controller (SMC) */
#define ID_PIOA          ( 10) /* Parallel Input/Output Controller (PIOA) */
#define ID_PIOB          ( 11) /* Parallel Input/Output Controller (PIOB) */
#define ID_PIOC          ( 12) /* Parallel Input/Output Controller (PIOC) */
#define ID_USART0        ( 13) /* Universal Synchronous Asynchronous Receiver Transmitter (USART0) */
#define ID_USART1        ( 14) /* Universal Synchronous Asynchronous Receiver Transmitter (USART1) */
#define ID_USART2        ( 15) /* Universal Synchronous Asynchronous Receiver Transmitter (USART2) */
#define ID_PIOD          ( 16) /* Parallel Input/Output Controller (PIOD) */
#define ID_PIOE          ( 17) /* Parallel Input/Output Controller (PIOE) */
#define ID_HSMCI         ( 18) /* High Speed MultiMedia Card Interface (HSMCI) */
#define ID_TWIHS0        ( 19) /* Two-wire Interface High Speed (TWIHS0) */
#define ID_TWIHS1        ( 20) /* Two-wire Interface High Speed (TWIHS1) */
#define ID_SPI0          ( 21) /* Serial Peripheral Interface (SPI0) */
#define ID_SSC           ( 22) /* Synchronous Serial Controller (SSC) */
#define ID_TC0_CHANNEL0  ( 23) /* Timer Counter (TC0_CHANNEL0) */
#define ID_TC0_CHANNEL1  ( 24) /* Timer Counter (TC0_CHANNEL1) */
#define ID_TC0_CHANNEL2  ( 25) /* Timer Counter (TC0_CHANNEL2) */
#define ID_TC1_CHANNEL0  ( 26) /* Timer Counter (TC1_CHANNEL0) */
#define ID_TC1_CHANNEL1  ( 27) /* Timer Counter (TC1_CHANNEL1) */
#define ID_TC1_CHANNEL2  ( 28) /* Timer Counter (TC1_CHANNEL2) */
#define ID_AFEC0         ( 29) /* Analog Front-End Controller (AFEC0) */
#define ID_DACC          ( 30) /* Digital-to-Analog Converter Controller (DACC) */
#define ID_PWM0          ( 31) /* Pulse Width Modulation Controller (PWM0) */
#define ID_ICM           ( 32) /* Integrity Check Monitor (ICM) */
#define ID_ACC           ( 33) /* Analog Comparator Controller (ACC) */
#define ID_USBHS         ( 34) /* USB High-Speed Interface (USBHS) */
#define ID_MCAN0         ( 35) /* Controller Area Network (MCAN0) */
#define ID_MCAN1         ( 37) /* Controller Area Network (MCAN1) */
#define ID_GMAC          ( 39) /* Gigabit Ethernet MAC (GMAC) */
#define ID_AFEC1         ( 40) /* Analog Front-End Controller (AFEC1) */
#define ID_TWIHS2        ( 41) /* Two-wire Interface High Speed (TWIHS2) */
#define ID_SPI1          ( 42) /* Serial Peripheral Interface (SPI1) */
#define ID_QSPI          ( 43) /* Quad Serial Peripheral Interface (QSPI) */
#define ID_UART2         ( 44) /* Universal Asynchronous Receiver Transmitter (UART2) */
#define ID_UART3         ( 45) /* Universal Asynchronous Receiver Transmitter (UART3) */
#define ID_UART4         ( 46) /* Universal Asynchronous Receiver Transmitter (UART4) */
#define ID_TC2_CHANNEL0  ( 47) /* Timer Counter (TC2_CHANNEL0) */
#define ID_TC2_CHANNEL1  ( 48) /* Timer Counter (TC2_CHANNEL1) */
#define ID_TC2_CHANNEL2  ( 49) /* Timer Counter (TC2_CHANNEL2) */
#define ID_TC3_CHANNEL0  ( 50) /* Timer Counter (TC3_CHANNEL0) */
#define ID_TC3_CHANNEL1  ( 51) /* Timer Counter (TC3_CHANNEL1) */
#define ID_TC3_CHANNEL2  ( 52) /* Timer Counter (TC3_CHANNEL2) */
#define ID_MLB           ( 53) /* MediaLB (MLB) */
#define ID_AES           ( 56) /* Advanced Encryption Standard (AES) */
#define ID_TRNG          ( 57) /* True Random Number Generator (TRNG) */
#define ID_XDMAC         ( 58) /* Extensible DMA Controller (XDMAC) */
#define ID_ISI           ( 59) /* Image Sensor Interface (ISI) */
#define ID_PWM1          ( 60) /* Pulse Width Modulation Controller (PWM1) */
#define ID_RSWDT         ( 63) /* Reinforced Safety Watchdog Timer (RSWDT) */
#define ID_I2SC0         ( 69) /* Inter-IC Sound Controller (I2SC0) */
#define ID_I2SC1         ( 70) /* Inter-IC Sound Controller (I2SC1) */

#define ID_PERIPH_MAX    ( 70) /* Number of peripheral IDs */

/* ************************************************************************** */
/*   REGISTER STRUCTURE ADDRESS DEFINITIONS FOR SAMV71Q21B                    */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#define ACC_REGS                         ((acc_registers_t*)0x40044000)                /* ACC Registers Address        */
#define AES_REGS                         ((aes_registers_t*)0x4006c000)                /* AES Registers Address        */
#define AFEC0_REGS                       ((afec_registers_t*)0x4003c000)               /* AFEC0 Registers Address      */
#define AFEC1_REGS                       ((afec_registers_t*)0x40064000)               /* AFEC1 Registers Address      */
#define CHIPID_REGS                      ((chipid_registers_t*)0x400e0940)             /* CHIPID Registers Address     */
#define DACC_REGS                        ((dacc_registers_t*)0x40040000)               /* DACC Registers Address       */
#define EFC_REGS                         ((efc_registers_t*)0x400e0c00)                /* EFC Registers Address        */
#define GMAC_REGS                        ((gmac_registers_t*)0x40050000)               /* GMAC Registers Address       */
#define GPBR_REGS                        ((gpbr_registers_t*)0x400e1890)               /* GPBR Registers Address       */
#define HSMCI_REGS                       ((hsmci_registers_t*)0x40000000)              /* HSMCI Registers Address      */
#define I2SC0_REGS                       ((i2sc_registers_t*)0x4008c000)               /* I2SC0 Registers Address      */
#define I2SC1_REGS                       ((i2sc_registers_t*)0x40090000)               /* I2SC1 Registers Address      */
#define ICM_REGS                         ((icm_registers_t*)0x40048000)                /* ICM Registers Address        */
#define ISI_REGS                         ((isi_registers_t*)0x4004c000)                /* ISI Registers Address        */
#define MATRIX_REGS                      ((matrix_registers_t*)0x40088000)             /* MATRIX Registers Address     */
#define MCAN0_REGS                       ((mcan_registers_t*)0x40030000)               /* MCAN0 Registers Address      */
#define MCAN1_REGS                       ((mcan_registers_t*)0x40034000)               /* MCAN1 Registers Address      */
#define MLB_REGS                         ((mlb_registers_t*)0x40068000)                /* MLB Registers Address        */
#define PIOA_REGS                        ((pio_registers_t*)0x400e0e00)                /* PIOA Registers Address       */
#define PIOB_REGS                        ((pio_registers_t*)0x400e1000)                /* PIOB Registers Address       */
#define PIOC_REGS                        ((pio_registers_t*)0x400e1200)                /* PIOC Registers Address       */
#define PIOD_REGS                        ((pio_registers_t*)0x400e1400)                /* PIOD Registers Address       */
#define PIOE_REGS                        ((pio_registers_t*)0x400e1600)                /* PIOE Registers Address       */
#define PMC_REGS                         ((pmc_registers_t*)0x400e0600)                /* PMC Registers Address        */
#define PWM0_REGS                        ((pwm_registers_t*)0x40020000)                /* PWM0 Registers Address       */
#define PWM1_REGS                        ((pwm_registers_t*)0x4005c000)                /* PWM1 Registers Address       */
#define QSPI_REGS                        ((qspi_registers_t*)0x4007c000)               /* QSPI Registers Address       */
#define RSTC_REGS                        ((rstc_registers_t*)0x400e1800)               /* RSTC Registers Address       */
#define RSWDT_REGS                       ((rswdt_registers_t*)0x400e1900)              /* RSWDT Registers Address      */
#define RTC_REGS                         ((rtc_registers_t*)0x400e1860)                /* RTC Registers Address        */
#define RTT_REGS                         ((rtt_registers_t*)0x400e1830)                /* RTT Registers Address        */
#define SMC_REGS                         ((smc_registers_t*)0x40080000)                /* SMC Registers Address        */
#define SPI0_REGS                        ((spi_registers_t*)0x40008000)                /* SPI0 Registers Address       */
#define SPI1_REGS                        ((spi_registers_t*)0x40058000)                /* SPI1 Registers Address       */
#define SSC_REGS                         ((ssc_registers_t*)0x40004000)                /* SSC Registers Address        */
#define SUPC_REGS                        ((supc_registers_t*)0x400e1810)               /* SUPC Registers Address       */
#define TC0_REGS                         ((tc_registers_t*)0x4000c000)                 /* TC0 Registers Address        */
#define TC1_REGS                         ((tc_registers_t*)0x40010000)                 /* TC1 Registers Address        */
#define TC2_REGS                         ((tc_registers_t*)0x40014000)                 /* TC2 Registers Address        */
#define TC3_REGS                         ((tc_registers_t*)0x40054000)                 /* TC3 Registers Address        */
#define TRNG_REGS                        ((trng_registers_t*)0x40070000)               /* TRNG Registers Address       */
#define TWIHS0_REGS                      ((twihs_registers_t*)0x40018000)              /* TWIHS0 Registers Address     */
#define TWIHS1_REGS                      ((twihs_registers_t*)0x4001c000)              /* TWIHS1 Registers Address     */
#define TWIHS2_REGS                      ((twihs_registers_t*)0x40060000)              /* TWIHS2 Registers Address     */
#define UART0_REGS                       ((uart_registers_t*)0x400e0800)               /* UART0 Registers Address      */
#define UART1_REGS                       ((uart_registers_t*)0x400e0a00)               /* UART1 Registers Address      */
#define UART2_REGS                       ((uart_registers_t*)0x400e1a00)               /* UART2 Registers Address      */
#define UART3_REGS                       ((uart_registers_t*)0x400e1c00)               /* UART3 Registers Address      */
#define UART4_REGS                       ((uart_registers_t*)0x400e1e00)               /* UART4 Registers Address      */
#define USART0_REGS                      ((usart_registers_t*)0x40024000)              /* USART0 Registers Address     */
#define USART1_REGS                      ((usart_registers_t*)0x40028000)              /* USART1 Registers Address     */
#define USART2_REGS                      ((usart_registers_t*)0x4002c000)              /* USART2 Registers Address     */
#define USBHS_REGS                       ((usbhs_registers_t*)0x40038000)              /* USBHS Registers Address      */
#define UTMI_REGS                        ((utmi_registers_t*)0x400e0400)               /* UTMI Registers Address       */
#define WDT_REGS                         ((wdt_registers_t*)0x400e1850)                /* WDT Registers Address        */
#define XDMAC_REGS                       ((xdmac_registers_t*)0x40078000)              /* XDMAC Registers Address      */
#define GPNVMBITS_REGS                   ((fuses_gpnvmbits_registers_t*)0x00000000)    /* FUSES Registers Address      */
#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR SAMV71Q21B                                  */
/* ************************************************************************** */
#define ACC_BASE_ADDRESS                 _UINT32_(0x40044000)                          /* ACC Base Address */
#define AES_BASE_ADDRESS                 _UINT32_(0x4006c000)                          /* AES Base Address */
#define AFEC0_BASE_ADDRESS               _UINT32_(0x4003c000)                          /* AFEC0 Base Address */
#define AFEC1_BASE_ADDRESS               _UINT32_(0x40064000)                          /* AFEC1 Base Address */
#define CHIPID_BASE_ADDRESS              _UINT32_(0x400e0940)                          /* CHIPID Base Address */
#define DACC_BASE_ADDRESS                _UINT32_(0x40040000)                          /* DACC Base Address */
#define EFC_BASE_ADDRESS                 _UINT32_(0x400e0c00)                          /* EFC Base Address */
#define GMAC_BASE_ADDRESS                _UINT32_(0x40050000)                          /* GMAC Base Address */
#define GPBR_BASE_ADDRESS                _UINT32_(0x400e1890)                          /* GPBR Base Address */
#define HSMCI_BASE_ADDRESS               _UINT32_(0x40000000)                          /* HSMCI Base Address */
#define I2SC0_BASE_ADDRESS               _UINT32_(0x4008c000)                          /* I2SC0 Base Address */
#define I2SC1_BASE_ADDRESS               _UINT32_(0x40090000)                          /* I2SC1 Base Address */
#define ICM_BASE_ADDRESS                 _UINT32_(0x40048000)                          /* ICM Base Address */
#define ISI_BASE_ADDRESS                 _UINT32_(0x4004c000)                          /* ISI Base Address */
#define MATRIX_BASE_ADDRESS              _UINT32_(0x40088000)                          /* MATRIX Base Address */
#define MCAN0_BASE_ADDRESS               _UINT32_(0x40030000)                          /* MCAN0 Base Address */
#define MCAN1_BASE_ADDRESS               _UINT32_(0x40034000)                          /* MCAN1 Base Address */
#define MLB_BASE_ADDRESS                 _UINT32_(0x40068000)                          /* MLB Base Address */
#define PIOA_BASE_ADDRESS                _UINT32_(0x400e0e00)                          /* PIOA Base Address */
#define PIOB_BASE_ADDRESS                _UINT32_(0x400e1000)                          /* PIOB Base Address */
#define PIOC_BASE_ADDRESS                _UINT32_(0x400e1200)                          /* PIOC Base Address */
#define PIOD_BASE_ADDRESS                _UINT32_(0x400e1400)                          /* PIOD Base Address */
#define PIOE_BASE_ADDRESS                _UINT32_(0x400e1600)                          /* PIOE Base Address */
#define PMC_BASE_ADDRESS                 _UINT32_(0x400e0600)                          /* PMC Base Address */
#define PWM0_BASE_ADDRESS                _UINT32_(0x40020000)                          /* PWM0 Base Address */
#define PWM1_BASE_ADDRESS                _UINT32_(0x4005c000)                          /* PWM1 Base Address */
#define QSPI_BASE_ADDRESS                _UINT32_(0x4007c000)                          /* QSPI Base Address */
#define RSTC_BASE_ADDRESS                _UINT32_(0x400e1800)                          /* RSTC Base Address */
#define RSWDT_BASE_ADDRESS               _UINT32_(0x400e1900)                          /* RSWDT Base Address */
#define RTC_BASE_ADDRESS                 _UINT32_(0x400e1860)                          /* RTC Base Address */
#define RTT_BASE_ADDRESS                 _UINT32_(0x400e1830)                          /* RTT Base Address */
#define SMC_BASE_ADDRESS                 _UINT32_(0x40080000)                          /* SMC Base Address */
#define SPI0_BASE_ADDRESS                _UINT32_(0x40008000)                          /* SPI0 Base Address */
#define SPI1_BASE_ADDRESS                _UINT32_(0x40058000)                          /* SPI1 Base Address */
#define SSC_BASE_ADDRESS                 _UINT32_(0x40004000)                          /* SSC Base Address */
#define SUPC_BASE_ADDRESS                _UINT32_(0x400e1810)                          /* SUPC Base Address */
#define TC0_BASE_ADDRESS                 _UINT32_(0x4000c000)                          /* TC0 Base Address */
#define TC1_BASE_ADDRESS                 _UINT32_(0x40010000)                          /* TC1 Base Address */
#define TC2_BASE_ADDRESS                 _UINT32_(0x40014000)                          /* TC2 Base Address */
#define TC3_BASE_ADDRESS                 _UINT32_(0x40054000)                          /* TC3 Base Address */
#define TRNG_BASE_ADDRESS                _UINT32_(0x40070000)                          /* TRNG Base Address */
#define TWIHS0_BASE_ADDRESS              _UINT32_(0x40018000)                          /* TWIHS0 Base Address */
#define TWIHS1_BASE_ADDRESS              _UINT32_(0x4001c000)                          /* TWIHS1 Base Address */
#define TWIHS2_BASE_ADDRESS              _UINT32_(0x40060000)                          /* TWIHS2 Base Address */
#define UART0_BASE_ADDRESS               _UINT32_(0x400e0800)                          /* UART0 Base Address */
#define UART1_BASE_ADDRESS               _UINT32_(0x400e0a00)                          /* UART1 Base Address */
#define UART2_BASE_ADDRESS               _UINT32_(0x400e1a00)                          /* UART2 Base Address */
#define UART3_BASE_ADDRESS               _UINT32_(0x400e1c00)                          /* UART3 Base Address */
#define UART4_BASE_ADDRESS               _UINT32_(0x400e1e00)                          /* UART4 Base Address */
#define USART0_BASE_ADDRESS              _UINT32_(0x40024000)                          /* USART0 Base Address */
#define USART1_BASE_ADDRESS              _UINT32_(0x40028000)                          /* USART1 Base Address */
#define USART2_BASE_ADDRESS              _UINT32_(0x4002c000)                          /* USART2 Base Address */
#define USBHS_BASE_ADDRESS               _UINT32_(0x40038000)                          /* USBHS Base Address */
#define UTMI_BASE_ADDRESS                _UINT32_(0x400e0400)                          /* UTMI Base Address */
#define WDT_BASE_ADDRESS                 _UINT32_(0x400e1850)                          /* WDT Base Address */
#define XDMAC_BASE_ADDRESS               _UINT32_(0x40078000)                          /* XDMAC Base Address */
#define GPNVMBITS_BASE_ADDRESS           _UINT32_(0x00000000)                          /* FUSES Base Address */

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR SAMV71Q21B                                           */
/* ************************************************************************** */
#include "pio/samv71q21b.h"

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR SAMV71Q21B                                */
/* ************************************************************************** */
#define PERIPHERALS_SIZE               _UINT32_(0x20000000)    /* 524288kB Memory segment type: io */
#define SYSTEM_SIZE                    _UINT32_(0x10000000)    /* 262144kB Memory segment type: io */
#define QSPIMEM_SIZE                   _UINT32_(0x20000000)    /* 524288kB Memory segment type: other */
#define AXIMX_SIZE                     _UINT32_(0x00100000)    /* 1024kB Memory segment type: other */
#define ITCM_SIZE                      _UINT32_(0x00200000)    /* 2048kB Memory segment type: other */
#define IFLASH_SIZE                    _UINT32_(0x00200000)    /* 2048kB Memory segment type: flash */
#define IFLASH_PAGE_SIZE               _UINT32_(       512)
#define IFLASH_NB_OF_PAGES             _UINT32_(      4096)

#define IROM_SIZE                      _UINT32_(0x00004000)    /*   16kB Memory segment type: rom */
#define DTCM_SIZE                      _UINT32_(0x00020000)    /*  128kB Memory segment type: other */
#define IRAM_SIZE                      _UINT32_(0x00060000)    /*  384kB Memory segment type: ram */
#define EBI_CS0_SIZE                   _UINT32_(0x01000000)    /* 16384kB Memory segment type: other */
#define EBI_CS1_SIZE                   _UINT32_(0x01000000)    /* 16384kB Memory segment type: other */
#define EBI_CS2_SIZE                   _UINT32_(0x01000000)    /* 16384kB Memory segment type: other */
#define EBI_CS3_SIZE                   _UINT32_(0x01000000)    /* 16384kB Memory segment type: other */

#define PERIPHERALS_ADDR               _UINT32_(0x40000000)    /* PERIPHERALS base address (type: io)*/
#define SYSTEM_ADDR                    _UINT32_(0xe0000000)    /* SYSTEM base address (type: io)*/
#define QSPIMEM_ADDR                   _UINT32_(0x80000000)    /* QSPIMEM base address (type: other)*/
#define AXIMX_ADDR                     _UINT32_(0xa0000000)    /* AXIMX base address (type: other)*/
#define ITCM_ADDR                      _UINT32_(0x00000000)    /* ITCM base address (type: other)*/
#define IFLASH_ADDR                    _UINT32_(0x00400000)    /* IFLASH base address (type: flash)*/
#define IROM_ADDR                      _UINT32_(0x00800000)    /* IROM base address (type: rom)*/
#define DTCM_ADDR                      _UINT32_(0x20000000)    /* DTCM base address (type: other)*/
#define IRAM_ADDR                      _UINT32_(0x20400000)    /* IRAM base address (type: ram)*/
#define EBI_CS0_ADDR                   _UINT32_(0x60000000)    /* EBI_CS0 base address (type: other)*/
#define EBI_CS1_ADDR                   _UINT32_(0x61000000)    /* EBI_CS1 base address (type: other)*/
#define EBI_CS2_ADDR                   _UINT32_(0x62000000)    /* EBI_CS2 base address (type: other)*/
#define EBI_CS3_ADDR                   _UINT32_(0x63000000)    /* EBI_CS3 base address (type: other)*/

/* ************************************************************************** */
/*   DEVICE SIGNATURES FOR SAMV71Q21B                                         */
/* ************************************************************************** */
#define CHIP_JTAGID                    _UINT32_(0X05B3D03F)
#define CHIP_CIDR                      _UINT32_(0XA1220E01)
#define CHIP_EXID                      _UINT32_(0X00000002)

/* ************************************************************************** */
/*   ELECTRICAL DEFINITIONS FOR SAMV71Q21B                                    */
/* ************************************************************************** */
#define CHIP_FREQ_SLCK_RC_MIN          _UINT32_(20000)     
#define CHIP_FREQ_SLCK_RC              _UINT32_(32000)     /* Typical Slow Clock Internal RC frequency */
#define CHIP_FREQ_SLCK_RC_MAX          _UINT32_(44000)     
#define CHIP_FREQ_MAINCK_RC_4MHZ       _UINT32_(4000000)   
#define CHIP_FREQ_MAINCK_RC_8MHZ       _UINT32_(8000000)   
#define CHIP_FREQ_MAINCK_RC_12MHZ      _UINT32_(12000000)  
#define CHIP_FREQ_CPU_MAX              _UINT32_(300000000) 
#define CHIP_FREQ_XTAL_32K             _UINT32_(32768)     
#define CHIP_FREQ_XTAL_12M             _UINT32_(12000000)  
#define CHIP_FREQ_FWS_0                _UINT32_(23000000)  /* Maximum operating frequency when FWS is 0 */
#define CHIP_FREQ_FWS_1                _UINT32_(46000000)  /* Maximum operating frequency when FWS is 1 */
#define CHIP_FREQ_FWS_2                _UINT32_(69000000)  /* Maximum operating frequency when FWS is 2 */
#define CHIP_FREQ_FWS_3                _UINT32_(92000000)  /* Maximum operating frequency when FWS is 3 */
#define CHIP_FREQ_FWS_4                _UINT32_(115000000) /* Maximum operating frequency when FWS is 4 */
#define CHIP_FREQ_FWS_5                _UINT32_(138000000) /* Maximum operating frequency when FWS is 5 */
#define CHIP_FREQ_FWS_6                _UINT32_(150000000) /* Maximum operating frequency when FWS is 6 */
#define CHIP_FREQ_FWS_NUMBER           _UINT32_(7)         /* Number of FWS ranges */



#ifdef __cplusplus
}
#endif

#endif /* _SAMV71Q21B_H_ */

