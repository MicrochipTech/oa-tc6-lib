/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F57Q43
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_AN2 aliases
#define IO_AN2_TRIS                 TRISAbits.TRISA1
#define IO_AN2_LAT                  LATAbits.LATA1
#define IO_AN2_PORT                 PORTAbits.RA1
#define IO_AN2_WPU                  WPUAbits.WPUA1
#define IO_AN2_OD                   ODCONAbits.ODCA1
#define IO_AN2_ANS                  ANSELAbits.ANSELA1
#define IO_AN2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IO_AN2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IO_AN2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IO_AN2_GetValue()           PORTAbits.RA1
#define IO_AN2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IO_AN2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IO_AN2_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define IO_AN2_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define IO_AN2_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define IO_AN2_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define IO_AN2_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define IO_AN2_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set IO_AN3 aliases
#define IO_AN3_TRIS                 TRISAbits.TRISA2
#define IO_AN3_LAT                  LATAbits.LATA2
#define IO_AN3_PORT                 PORTAbits.RA2
#define IO_AN3_WPU                  WPUAbits.WPUA2
#define IO_AN3_OD                   ODCONAbits.ODCA2
#define IO_AN3_ANS                  ANSELAbits.ANSELA2
#define IO_AN3_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_AN3_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_AN3_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_AN3_GetValue()           PORTAbits.RA2
#define IO_AN3_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_AN3_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_AN3_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_AN3_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_AN3_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define IO_AN3_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define IO_AN3_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define IO_AN3_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA6 procedures
#define RA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define RA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define RA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define RA6_GetValue()              PORTAbits.RA6
#define RA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define RA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define RA6_SetPullup()             do { WPUAbits.WPUA6 = 1; } while(0)
#define RA6_ResetPullup()           do { WPUAbits.WPUA6 = 0; } while(0)
#define RA6_SetAnalogMode()         do { ANSELAbits.ANSELA6 = 1; } while(0)
#define RA6_SetDigitalMode()        do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set IO_RST1 aliases
#define IO_RST1_TRIS                 TRISAbits.TRISA7
#define IO_RST1_LAT                  LATAbits.LATA7
#define IO_RST1_PORT                 PORTAbits.RA7
#define IO_RST1_WPU                  WPUAbits.WPUA7
#define IO_RST1_OD                   ODCONAbits.ODCA7
#define IO_RST1_ANS                  ANSELAbits.ANSELA7
#define IO_RST1_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define IO_RST1_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define IO_RST1_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define IO_RST1_GetValue()           PORTAbits.RA7
#define IO_RST1_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define IO_RST1_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define IO_RST1_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define IO_RST1_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define IO_RST1_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define IO_RST1_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define IO_RST1_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define IO_RST1_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set IO_SW0 aliases
#define IO_SW0_TRIS                 TRISBbits.TRISB4
#define IO_SW0_LAT                  LATBbits.LATB4
#define IO_SW0_PORT                 PORTBbits.RB4
#define IO_SW0_WPU                  WPUBbits.WPUB4
#define IO_SW0_OD                   ODCONBbits.ODCB4
#define IO_SW0_ANS                  ANSELBbits.ANSELB4
#define IO_SW0_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_SW0_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_SW0_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_SW0_GetValue()           PORTBbits.RB4
#define IO_SW0_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_SW0_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_SW0_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_SW0_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_SW0_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_SW0_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_SW0_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_SW0_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set IO_CS1 aliases
#define IO_CS1_TRIS                 TRISDbits.TRISD4
#define IO_CS1_LAT                  LATDbits.LATD4
#define IO_CS1_PORT                 PORTDbits.RD4
#define IO_CS1_WPU                  WPUDbits.WPUD4
#define IO_CS1_OD                   ODCONDbits.ODCD4
#define IO_CS1_ANS                  ANSELDbits.ANSELD4
#define IO_CS1_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define IO_CS1_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define IO_CS1_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define IO_CS1_GetValue()           PORTDbits.RD4
#define IO_CS1_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define IO_CS1_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define IO_CS1_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define IO_CS1_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define IO_CS1_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define IO_CS1_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define IO_CS1_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define IO_CS1_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set RF0 procedures
#define RF0_SetHigh()            do { LATFbits.LATF0 = 1; } while(0)
#define RF0_SetLow()             do { LATFbits.LATF0 = 0; } while(0)
#define RF0_Toggle()             do { LATFbits.LATF0 = ~LATFbits.LATF0; } while(0)
#define RF0_GetValue()              PORTFbits.RF0
#define RF0_SetDigitalInput()    do { TRISFbits.TRISF0 = 1; } while(0)
#define RF0_SetDigitalOutput()   do { TRISFbits.TRISF0 = 0; } while(0)
#define RF0_SetPullup()             do { WPUFbits.WPUF0 = 1; } while(0)
#define RF0_ResetPullup()           do { WPUFbits.WPUF0 = 0; } while(0)
#define RF0_SetAnalogMode()         do { ANSELFbits.ANSELF0 = 1; } while(0)
#define RF0_SetDigitalMode()        do { ANSELFbits.ANSELF0 = 0; } while(0)

// get/set RF1 procedures
#define RF1_SetHigh()            do { LATFbits.LATF1 = 1; } while(0)
#define RF1_SetLow()             do { LATFbits.LATF1 = 0; } while(0)
#define RF1_Toggle()             do { LATFbits.LATF1 = ~LATFbits.LATF1; } while(0)
#define RF1_GetValue()              PORTFbits.RF1
#define RF1_SetDigitalInput()    do { TRISFbits.TRISF1 = 1; } while(0)
#define RF1_SetDigitalOutput()   do { TRISFbits.TRISF1 = 0; } while(0)
#define RF1_SetPullup()             do { WPUFbits.WPUF1 = 1; } while(0)
#define RF1_ResetPullup()           do { WPUFbits.WPUF1 = 0; } while(0)
#define RF1_SetAnalogMode()         do { ANSELFbits.ANSELF1 = 1; } while(0)
#define RF1_SetDigitalMode()        do { ANSELFbits.ANSELF1 = 0; } while(0)

// get/set IO_LED0 aliases
#define IO_LED0_TRIS                 TRISFbits.TRISF3
#define IO_LED0_LAT                  LATFbits.LATF3
#define IO_LED0_PORT                 PORTFbits.RF3
#define IO_LED0_WPU                  WPUFbits.WPUF3
#define IO_LED0_OD                   ODCONFbits.ODCF3
#define IO_LED0_ANS                  ANSELFbits.ANSELF3
#define IO_LED0_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define IO_LED0_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define IO_LED0_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define IO_LED0_GetValue()           PORTFbits.RF3
#define IO_LED0_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define IO_LED0_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define IO_LED0_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define IO_LED0_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define IO_LED0_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define IO_LED0_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define IO_LED0_SetAnalogMode()      do { ANSELFbits.ANSELF3 = 1; } while(0)
#define IO_LED0_SetDigitalMode()     do { ANSELFbits.ANSELF3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF6 pin functionality
 * @Example
    IOCAF6_ISR();
 */
void IOCAF6_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF6 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF6 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF6_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF6_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF6 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF6_SetInterruptHandler() method.
    This handler is called every time the IOCAF6 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF6_SetInterruptHandler(IOCAF6_InterruptHandler);

*/
extern void (*IOCAF6_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF6 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF6_SetInterruptHandler() method.
    This handler is called every time the IOCAF6 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF6_SetInterruptHandler(IOCAF6_DefaultInterruptHandler);

*/
void IOCAF6_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/