/*******************************************************************************
  PIO PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_pio.h

  Summary:
    PIO PLIB Header File

  Description:
    This library provides an interface to control and interact with Parallel
    Input/Output controller (PIO) module.

*******************************************************************************/

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

#ifndef PLIB_PIO_H
#define PLIB_PIO_H

#include "device.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data types and constants
// *****************************************************************************
// *****************************************************************************


/*** Macros for GPIO_TRACE2 pin ***/
#define GPIO_TRACE2_Set()               (PIOC_REGS->PIO_SODR = (1<<13))
#define GPIO_TRACE2_Clear()             (PIOC_REGS->PIO_CODR = (1<<13))
#define GPIO_TRACE2_Toggle()            (PIOC_REGS->PIO_ODSR ^= (1<<13))
#define GPIO_TRACE2_OutputEnable()      (PIOC_REGS->PIO_OER = (1<<13))
#define GPIO_TRACE2_InputEnable()       (PIOC_REGS->PIO_ODR = (1<<13))
#define GPIO_TRACE2_Get()               ((PIOC_REGS->PIO_PDSR >> 13) & 0x1)
#define GPIO_TRACE2_PIN                  PIO_PIN_PC13

/*** Macros for TC6_RESET_1 pin ***/
#define TC6_RESET_1_Set()               (PIOB_REGS->PIO_SODR = (1<<3))
#define TC6_RESET_1_Clear()             (PIOB_REGS->PIO_CODR = (1<<3))
#define TC6_RESET_1_Toggle()            (PIOB_REGS->PIO_ODSR ^= (1<<3))
#define TC6_RESET_1_OutputEnable()      (PIOB_REGS->PIO_OER = (1<<3))
#define TC6_RESET_1_InputEnable()       (PIOB_REGS->PIO_ODR = (1<<3))
#define TC6_RESET_1_Get()               ((PIOB_REGS->PIO_PDSR >> 3) & 0x1)
#define TC6_RESET_1_PIN                  PIO_PIN_PB3

/*** Macros for USART1_RXD1 pin ***/
#define USART1_RXD1_Get()               ((PIOA_REGS->PIO_PDSR >> 21) & 0x1)
#define USART1_RXD1_PIN                  PIO_PIN_PA21

/*** Macros for GPIO_TRACE4 pin ***/
#define GPIO_TRACE4_Set()               (PIOD_REGS->PIO_SODR = (1<<30))
#define GPIO_TRACE4_Clear()             (PIOD_REGS->PIO_CODR = (1<<30))
#define GPIO_TRACE4_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<30))
#define GPIO_TRACE4_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<30))
#define GPIO_TRACE4_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<30))
#define GPIO_TRACE4_Get()               ((PIOD_REGS->PIO_PDSR >> 30) & 0x1)
#define GPIO_TRACE4_PIN                  PIO_PIN_PD30

/*** Macros for GPIO_PD25 pin ***/
#define GPIO_PD25_Set()               (PIOD_REGS->PIO_SODR = (1<<25))
#define GPIO_PD25_Clear()             (PIOD_REGS->PIO_CODR = (1<<25))
#define GPIO_PD25_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<25))
#define GPIO_PD25_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<25))
#define GPIO_PD25_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<25))
#define GPIO_PD25_Get()               ((PIOD_REGS->PIO_PDSR >> 25) & 0x1)
#define GPIO_PD25_PIN                  PIO_PIN_PD25

/*** Macros for SPI0_SPCK pin ***/
#define SPI0_SPCK_Get()               ((PIOD_REGS->PIO_PDSR >> 22) & 0x1)
#define SPI0_SPCK_PIN                  PIO_PIN_PD22

/*** Macros for SPI0_MOSI pin ***/
#define SPI0_MOSI_Get()               ((PIOD_REGS->PIO_PDSR >> 21) & 0x1)
#define SPI0_MOSI_PIN                  PIO_PIN_PD21

/*** Macros for SPI0_MISO pin ***/
#define SPI0_MISO_Get()               ((PIOD_REGS->PIO_PDSR >> 20) & 0x1)
#define SPI0_MISO_PIN                  PIO_PIN_PD20

/*** Macros for TC6_INT_1 pin ***/
#define TC6_INT_1_Set()               (PIOD_REGS->PIO_SODR = (1<<28))
#define TC6_INT_1_Clear()             (PIOD_REGS->PIO_CODR = (1<<28))
#define TC6_INT_1_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<28))
#define TC6_INT_1_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<28))
#define TC6_INT_1_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<28))
#define TC6_INT_1_Get()               ((PIOD_REGS->PIO_PDSR >> 28) & 0x1)
#define TC6_INT_1_PIN                  PIO_PIN_PD28
#define TC6_INT_1_InterruptEnable()   (PIOD_REGS->PIO_IER = (1<<28))
#define TC6_INT_1_InterruptDisable()  (PIOD_REGS->PIO_IDR = (1<<28))

/*** Macros for LED0 pin ***/
#define LED0_Set()               (PIOA_REGS->PIO_SODR = (1<<9))
#define LED0_Clear()             (PIOA_REGS->PIO_CODR = (1<<9))
#define LED0_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<9))
#define LED0_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<9))
#define LED0_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<9))
#define LED0_Get()               ((PIOA_REGS->PIO_PDSR >> 9) & 0x1)
#define LED0_PIN                  PIO_PIN_PA9

/*** Macros for I2C_SCL pin ***/
#define I2C_SCL_Get()               ((PIOA_REGS->PIO_PDSR >> 4) & 0x1)
#define I2C_SCL_PIN                  PIO_PIN_PA4

/*** Macros for LED1 pin ***/
#define LED1_Set()               (PIOC_REGS->PIO_SODR = (1<<9))
#define LED1_Clear()             (PIOC_REGS->PIO_CODR = (1<<9))
#define LED1_Toggle()            (PIOC_REGS->PIO_ODSR ^= (1<<9))
#define LED1_OutputEnable()      (PIOC_REGS->PIO_OER = (1<<9))
#define LED1_InputEnable()       (PIOC_REGS->PIO_ODR = (1<<9))
#define LED1_Get()               ((PIOC_REGS->PIO_PDSR >> 9) & 0x1)
#define LED1_PIN                  PIO_PIN_PC9

/*** Macros for I2C_SDA pin ***/
#define I2C_SDA_Get()               ((PIOA_REGS->PIO_PDSR >> 3) & 0x1)
#define I2C_SDA_PIN                  PIO_PIN_PA3

/*** Macros for GPIO_TRACE3 pin ***/
#define GPIO_TRACE3_Set()               (PIOD_REGS->PIO_SODR = (1<<11))
#define GPIO_TRACE3_Clear()             (PIOD_REGS->PIO_CODR = (1<<11))
#define GPIO_TRACE3_Toggle()            (PIOD_REGS->PIO_ODSR ^= (1<<11))
#define GPIO_TRACE3_OutputEnable()      (PIOD_REGS->PIO_OER = (1<<11))
#define GPIO_TRACE3_InputEnable()       (PIOD_REGS->PIO_ODR = (1<<11))
#define GPIO_TRACE3_Get()               ((PIOD_REGS->PIO_PDSR >> 11) & 0x1)
#define GPIO_TRACE3_PIN                  PIO_PIN_PD11

/*** Macros for USART1_TXD1 pin ***/
#define USART1_TXD1_Get()               ((PIOB_REGS->PIO_PDSR >> 4) & 0x1)
#define USART1_TXD1_PIN                  PIO_PIN_PB4

/*** Macros for GPIO_TRACE1 pin ***/
#define GPIO_TRACE1_Set()               (PIOA_REGS->PIO_SODR = (1<<6))
#define GPIO_TRACE1_Clear()             (PIOA_REGS->PIO_CODR = (1<<6))
#define GPIO_TRACE1_Toggle()            (PIOA_REGS->PIO_ODSR ^= (1<<6))
#define GPIO_TRACE1_OutputEnable()      (PIOA_REGS->PIO_OER = (1<<6))
#define GPIO_TRACE1_InputEnable()       (PIOA_REGS->PIO_ODR = (1<<6))
#define GPIO_TRACE1_Get()               ((PIOA_REGS->PIO_PDSR >> 6) & 0x1)
#define GPIO_TRACE1_PIN                  PIO_PIN_PA6


// *****************************************************************************
/* PIO Port

  Summary:
    Identifies the available PIO Ports.

  Description:
    This enumeration identifies the available PIO Ports.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all ports are available on all devices.  Refer to the specific
    device data sheet to determine which ports are supported.
*/


#define    PIO_PORT_A       (PIOA_BASE_ADDRESS)
#define    PIO_PORT_B       (PIOB_BASE_ADDRESS)
#define     PIO_PORT_C      (PIOC_BASE_ADDRESS)
#define     PIO_PORT_D      (PIOD_BASE_ADDRESS)
#define     PIO_PORT_E      (PIOE_BASE_ADDRESS)
typedef uint32_t PIO_PORT;

// *****************************************************************************
/* PIO Port Pins

  Summary:
    Identifies the available PIO port pins.

  Description:
    This enumeration identifies the available PIO port pins.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all pins are available on all devices.  Refer to the specific
    device data sheet to determine which pins are supported.
*/

#define    PIO_PIN_PA0     (0U)
#define    PIO_PIN_PA1     (1U)
#define    PIO_PIN_PA2     (2U)
#define    PIO_PIN_PA3     (3U)
#define    PIO_PIN_PA4     (4U)
#define    PIO_PIN_PA5     (5U)
#define    PIO_PIN_PA6     (6U)
#define    PIO_PIN_PA7     (7U)
#define    PIO_PIN_PA8     (8U)
#define    PIO_PIN_PA9     (9U)
#define    PIO_PIN_PA10     (10U)
#define    PIO_PIN_PA11     (11U)
#define    PIO_PIN_PA12     (12U)
#define    PIO_PIN_PA13     (13U)
#define    PIO_PIN_PA14     (14U)
#define    PIO_PIN_PA15     (15U)
#define    PIO_PIN_PA16     (16U)
#define    PIO_PIN_PA17     (17U)
#define    PIO_PIN_PA18     (18U)
#define    PIO_PIN_PA19     (19U)
#define    PIO_PIN_PA20     (20U)
#define    PIO_PIN_PA21     (21U)
#define    PIO_PIN_PA22     (22U)
#define    PIO_PIN_PA23     (23U)
#define    PIO_PIN_PA24     (24U)
#define    PIO_PIN_PA25     (25U)
#define    PIO_PIN_PA26     (26U)
#define    PIO_PIN_PA27     (27U)
#define    PIO_PIN_PA28     (28U)
#define    PIO_PIN_PA29     (29U)
#define    PIO_PIN_PA30     (30U)
#define    PIO_PIN_PA31     (31U)
#define    PIO_PIN_PB0     (32U)
#define    PIO_PIN_PB1     (33U)
#define    PIO_PIN_PB2     (34U)
#define    PIO_PIN_PB3     (35U)
#define    PIO_PIN_PB4     (36U)
#define    PIO_PIN_PB5     (37U)
#define    PIO_PIN_PB6     (38U)
#define    PIO_PIN_PB7     (39U)
#define    PIO_PIN_PB8     (40U)
#define    PIO_PIN_PB9     (41U)
#define    PIO_PIN_PB12     (44U)
#define    PIO_PIN_PB13     (45U)
#define    PIO_PIN_PC0     (64U)
#define    PIO_PIN_PC1     (65U)
#define    PIO_PIN_PC2     (66U)
#define    PIO_PIN_PC3     (67U)
#define    PIO_PIN_PC4     (68U)
#define    PIO_PIN_PC5     (69U)
#define    PIO_PIN_PC6     (70U)
#define    PIO_PIN_PC7     (71U)
#define    PIO_PIN_PC8     (72U)
#define    PIO_PIN_PC9     (73U)
#define    PIO_PIN_PC10     (74U)
#define    PIO_PIN_PC11     (75U)
#define    PIO_PIN_PC12     (76U)
#define    PIO_PIN_PC13     (77U)
#define    PIO_PIN_PC14     (78U)
#define    PIO_PIN_PC15     (79U)
#define    PIO_PIN_PC16     (80U)
#define    PIO_PIN_PC17     (81U)
#define    PIO_PIN_PC18     (82U)
#define    PIO_PIN_PC19     (83U)
#define    PIO_PIN_PC20     (84U)
#define    PIO_PIN_PC21     (85U)
#define    PIO_PIN_PC22     (86U)
#define    PIO_PIN_PC23     (87U)
#define    PIO_PIN_PC24     (88U)
#define    PIO_PIN_PC25     (89U)
#define    PIO_PIN_PC26     (90U)
#define    PIO_PIN_PC27     (91U)
#define    PIO_PIN_PC28     (92U)
#define    PIO_PIN_PC29     (93U)
#define    PIO_PIN_PC30     (94U)
#define    PIO_PIN_PC31     (95U)
#define    PIO_PIN_PD0     (96U)
#define    PIO_PIN_PD1     (97U)
#define    PIO_PIN_PD2     (98U)
#define    PIO_PIN_PD3     (99U)
#define    PIO_PIN_PD4     (100U)
#define    PIO_PIN_PD5     (101U)
#define    PIO_PIN_PD6     (102U)
#define    PIO_PIN_PD7     (103U)
#define    PIO_PIN_PD8     (104U)
#define    PIO_PIN_PD9     (105U)
#define    PIO_PIN_PD10     (106U)
#define    PIO_PIN_PD11     (107U)
#define    PIO_PIN_PD12     (108U)
#define    PIO_PIN_PD13     (109U)
#define    PIO_PIN_PD14     (110U)
#define    PIO_PIN_PD15     (111U)
#define    PIO_PIN_PD16     (112U)
#define    PIO_PIN_PD17     (113U)
#define    PIO_PIN_PD18     (114U)
#define    PIO_PIN_PD19     (115U)
#define    PIO_PIN_PD20     (116U)
#define    PIO_PIN_PD21     (117U)
#define    PIO_PIN_PD22     (118U)
#define    PIO_PIN_PD23     (119U)
#define    PIO_PIN_PD24     (120U)
#define    PIO_PIN_PD25     (121U)
#define    PIO_PIN_PD26     (122U)
#define    PIO_PIN_PD27     (123U)
#define    PIO_PIN_PD28     (124U)
#define    PIO_PIN_PD29     (125U)
#define    PIO_PIN_PD30     (126U)
#define    PIO_PIN_PD31     (127U)
#define    PIO_PIN_PE0     (128U)
#define    PIO_PIN_PE1     (129U)
#define    PIO_PIN_PE2     (130U)
#define    PIO_PIN_PE3     (131U)
#define    PIO_PIN_PE4     (132U)
#define    PIO_PIN_PE5     (133U)

    /* This element should not be used in any of the PIO APIs.
       It will be used by other modules or application to denote that none of the PIO Pin is used */
#define    PIO_PIN_NONE         ( -1)

typedef uint32_t PIO_PIN;

typedef  void (*PIO_PIN_CALLBACK) ( PIO_PIN pin, uintptr_t context);

void PIO_Initialize(void);

// *****************************************************************************
// *****************************************************************************
// Section: PIO Functions which operates on multiple pins of a port
// *****************************************************************************
// *****************************************************************************

uint32_t PIO_PortRead(PIO_PORT port);

void PIO_PortWrite(PIO_PORT port, uint32_t mask, uint32_t value);

uint32_t PIO_PortLatchRead ( PIO_PORT port );

void PIO_PortSet(PIO_PORT port, uint32_t mask);

void PIO_PortClear(PIO_PORT port, uint32_t mask);

void PIO_PortToggle(PIO_PORT port, uint32_t mask);

void PIO_PortInputEnable(PIO_PORT port, uint32_t mask);

void PIO_PortOutputEnable(PIO_PORT port, uint32_t mask);

void PIO_PortInterruptEnable(PIO_PORT port, uint32_t mask);

void PIO_PortInterruptDisable(PIO_PORT port, uint32_t mask);

// *****************************************************************************
// *****************************************************************************
// Section: Local Data types and Prototypes
// *****************************************************************************
// *****************************************************************************

typedef struct {

    /* target pin */
    PIO_PIN                 pin;

    /* Callback for event on target pin*/
    PIO_PIN_CALLBACK        callback;

    /* Callback Context */
    uintptr_t               context;

} PIO_PIN_CALLBACK_OBJ;

// *****************************************************************************
// *****************************************************************************
// Section: PIO Functions which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

static inline void PIO_PinWrite(PIO_PIN pin, bool value)
{
    PIO_PortWrite((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), (uint32_t)(0x1) << (pin & 0x1fU), (uint32_t)(value) << (pin & 0x1fU));
}

static inline bool PIO_PinRead(PIO_PIN pin)
{
    return (bool)((PIO_PortRead((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U)))) >> (pin & 0x1FU)) & 0x1U);
}

static inline bool PIO_PinLatchRead(PIO_PIN pin)
{
    return (bool)((PIO_PortLatchRead((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U)))) >> (pin & 0x1FU)) & 0x1U);
}

static inline void PIO_PinToggle(PIO_PIN pin)
{
    PIO_PortToggle((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), 0x1UL << (pin & 0x1FU));
}

static inline void PIO_PinSet(PIO_PIN pin)
{
    PIO_PortSet((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5))), 0x1UL << (pin & 0x1FU));
}

static inline void PIO_PinClear(PIO_PIN pin)
{
    PIO_PortClear((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), 0x1UL << (pin & 0x1FU));
}

static inline void PIO_PinInputEnable(PIO_PIN pin)
{
    PIO_PortInputEnable((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), 0x1UL << (pin & 0x1FU));
}

static inline void PIO_PinOutputEnable(PIO_PIN pin)
{
    PIO_PortOutputEnable((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), 0x1UL << (pin & 0x1FU));
}

static inline void PIO_PinInterruptEnable(PIO_PIN pin)
{
    PIO_PortInterruptEnable((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), 0x1UL << (pin & 0x1FU));
}

static inline void PIO_PinInterruptDisable(PIO_PIN pin)
{
    PIO_PortInterruptDisable((PIO_PORT)(PIOA_BASE_ADDRESS + (0x200U * (pin>>5U))), 0x1UL << (pin & 0x1FU));
}

bool PIO_PinInterruptCallbackRegister(
    PIO_PIN pin,
    const PIO_PIN_CALLBACK callback,
    uintptr_t context
);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END
#endif // PLIB_PIO_H
