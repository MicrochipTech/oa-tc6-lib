/*******************************************************************************
 System Interrupts File

  Company:
    Microchip Technology Inc.

  File Name:
    interrupt.c

  Summary:
    Interrupt vectors mapping

  Description:
    This file maps all the interrupt vectors to their corresponding
    implementations. If a particular module interrupt is used, then its ISR
    definition can be found in corresponding PLIB source file. If a module
    interrupt is not used, then its ISR implementation is mapped to dummy
    handler.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "configuration.h"
#include "device_vectors.h"
#include "interrupts.h"
#include "definitions.h"


// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************

/* MISRA C-2012 Rule 8.6 deviated below. Deviation record ID -  H3_MISRAC_2012_R_8_6_DR_1 */
extern uint32_t _stack;
extern const H3DeviceVectors exception_table;

extern void Dummy_Handler(void);

/* Brief default interrupt handler for unused IRQs.*/
void __attribute__((optimize("-O1"),section(".text.Dummy_Handler"),long_call, noreturn))Dummy_Handler(void)
{
#if defined(__DEBUG) || defined(__DEBUG_D) && defined(__XC32)
    __builtin_software_breakpoint();
#endif
    while (true)
    {
    }
}

/* MISRAC 2012 deviation block start */
/* MISRA C-2012 Rule 8.6 deviated 67 times.  Deviation record ID -  H3_MISRAC_2012_R_8_6_DR_1 */
/* Device vectors list dummy definition*/
extern void SVCall_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PendSV_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SUPC_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void RSTC_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void RTC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void RTT_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void WDT_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PMC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EFC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void UART0_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void UART1_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PIOA_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PIOB_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PIOC_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void USART0_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void USART1_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void USART2_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PIOE_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void HSMCI_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TWIHS1_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SSC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC0_CH0_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC0_CH1_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC0_CH2_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC1_CH0_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC1_CH1_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC1_CH2_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void AFEC0_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DACC_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PWM0_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ICM_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ACC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void USBHS_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void MCAN0_INT0_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void MCAN0_INT1_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void MCAN1_INT0_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void MCAN1_INT1_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void GMAC_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void AFEC1_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TWIHS2_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SPI1_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void QSPI_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void UART2_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void UART3_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void UART4_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC2_CH0_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC2_CH1_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC2_CH2_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC3_CH0_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC3_CH1_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC3_CH2_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void AES_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TRNG_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ISI_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PWM1_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void FPU_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void RSWDT_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void CCW_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void CCF_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void GMAC_Q1_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void GMAC_Q2_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void IXC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void I2SC0_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void I2SC1_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void GMAC_Q3_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void GMAC_Q4_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void GMAC_Q5_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));


/* MISRAC 2012 deviation block end */

/* Multiple handlers for vector */



__attribute__ ((section(".vectors")))
const H3DeviceVectors exception_table=
{
    /* Configure Initial Stack Pointer, using linker-generated symbols */
    .pvStack = &_stack,

    .pfnReset_Handler              = Reset_Handler,
    .pfnNonMaskableInt_Handler     = NonMaskableInt_Handler,
    .pfnHardFault_Handler          = HardFault_Handler,
    .pfnMemoryManagement_Handler   = MemoryManagement_Handler,
    .pfnBusFault_Handler           = BusFault_Handler,
    .pfnUsageFault_Handler         = UsageFault_Handler,
    .pfnSVCall_Handler             = SVCall_Handler,
    .pfnDebugMonitor_Handler       = DebugMonitor_Handler,
    .pfnPendSV_Handler             = PendSV_Handler,
    .pfnSysTick_Handler            = SysTick_Handler,
    .pfnSUPC_Handler               = SUPC_Handler,
    .pfnRSTC_Handler               = RSTC_Handler,
    .pfnRTC_Handler                = RTC_Handler,
    .pfnRTT_Handler                = RTT_Handler,
    .pfnWDT_Handler                = WDT_Handler,
    .pfnPMC_Handler                = PMC_Handler,
    .pfnEFC_Handler                = EFC_Handler,
    .pfnUART0_Handler              = UART0_Handler,
    .pfnUART1_Handler              = UART1_Handler,
    .pfnPIOA_Handler               = PIOA_Handler,
    .pfnPIOB_Handler               = PIOB_Handler,
    .pfnPIOC_Handler               = PIOC_Handler,
    .pfnUSART0_Handler             = USART0_Handler,
    .pfnUSART1_Handler             = USART1_Handler,
    .pfnUSART2_Handler             = USART2_Handler,
    .pfnPIOD_Handler               = PIOD_InterruptHandler,
    .pfnPIOE_Handler               = PIOE_Handler,
    .pfnHSMCI_Handler              = HSMCI_Handler,
    .pfnTWIHS0_Handler             = TWIHS0_InterruptHandler,
    .pfnTWIHS1_Handler             = TWIHS1_Handler,
    .pfnSPI0_Handler               = SPI0_InterruptHandler,
    .pfnSSC_Handler                = SSC_Handler,
    .pfnTC0_CH0_Handler            = TC0_CH0_Handler,
    .pfnTC0_CH1_Handler            = TC0_CH1_Handler,
    .pfnTC0_CH2_Handler            = TC0_CH2_Handler,
    .pfnTC1_CH0_Handler            = TC1_CH0_Handler,
    .pfnTC1_CH1_Handler            = TC1_CH1_Handler,
    .pfnTC1_CH2_Handler            = TC1_CH2_Handler,
    .pfnAFEC0_Handler              = AFEC0_Handler,
    .pfnDACC_Handler               = DACC_Handler,
    .pfnPWM0_Handler               = PWM0_Handler,
    .pfnICM_Handler                = ICM_Handler,
    .pfnACC_Handler                = ACC_Handler,
    .pfnUSBHS_Handler              = USBHS_Handler,
    .pfnMCAN0_INT0_Handler         = MCAN0_INT0_Handler,
    .pfnMCAN0_INT1_Handler         = MCAN0_INT1_Handler,
    .pfnMCAN1_INT0_Handler         = MCAN1_INT0_Handler,
    .pfnMCAN1_INT1_Handler         = MCAN1_INT1_Handler,
    .pfnGMAC_Handler               = GMAC_Handler,
    .pfnAFEC1_Handler              = AFEC1_Handler,
    .pfnTWIHS2_Handler             = TWIHS2_Handler,
    .pfnSPI1_Handler               = SPI1_Handler,
    .pfnQSPI_Handler               = QSPI_Handler,
    .pfnUART2_Handler              = UART2_Handler,
    .pfnUART3_Handler              = UART3_Handler,
    .pfnUART4_Handler              = UART4_Handler,
    .pfnTC2_CH0_Handler            = TC2_CH0_Handler,
    .pfnTC2_CH1_Handler            = TC2_CH1_Handler,
    .pfnTC2_CH2_Handler            = TC2_CH2_Handler,
    .pfnTC3_CH0_Handler            = TC3_CH0_Handler,
    .pfnTC3_CH1_Handler            = TC3_CH1_Handler,
    .pfnTC3_CH2_Handler            = TC3_CH2_Handler,
    .pfnAES_Handler                = AES_Handler,
    .pfnTRNG_Handler               = TRNG_Handler,
    .pfnXDMAC_Handler              = XDMAC_InterruptHandler,
    .pfnISI_Handler                = ISI_Handler,
    .pfnPWM1_Handler               = PWM1_Handler,
    .pfnFPU_Handler                = FPU_Handler,
    .pfnRSWDT_Handler              = RSWDT_Handler,
    .pfnCCW_Handler                = CCW_Handler,
    .pfnCCF_Handler                = CCF_Handler,
    .pfnGMAC_Q1_Handler            = GMAC_Q1_Handler,
    .pfnGMAC_Q2_Handler            = GMAC_Q2_Handler,
    .pfnIXC_Handler                = IXC_Handler,
    .pfnI2SC0_Handler              = I2SC0_Handler,
    .pfnI2SC1_Handler              = I2SC1_Handler,
    .pfnGMAC_Q3_Handler            = GMAC_Q3_Handler,
    .pfnGMAC_Q4_Handler            = GMAC_Q4_Handler,
    .pfnGMAC_Q5_Handler            = GMAC_Q5_Handler,


};

/*******************************************************************************
 End of File
*/
