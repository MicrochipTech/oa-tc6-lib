/**
 * TRAPS Generated Driver Source File
 *
 * @file      traps.c
 *
 * @ingroup   trapsdriver
 *
 * @brief     This is the generated driver source file for TRAPS driver
 *
 * @skipline @version   PLIB Version 1.1.2
 *
 * @skipline  Device : dsPIC33AK512MPS512
*/

/*
© [2026] Microchip Technology Inc. and its subsidiaries.

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

// Section: Included Files
#include <xc.h>
#include "../traps.h"


/* To identify the source of the trap, or the address of the source code causing the trap, please uncomment the
  following line. When the code is executed by uncommenting the below line, the trapSrcAddr variable will contain
  the address of the source code that, in the event that a trap occurs, is causing.*/

/* #define FIND_TRAP_SOURCE */

#ifdef FIND_TRAP_SOURCE
void __attribute__((interrupt(preprologue("rcall _where_was_i ")), no_auto_psv)) _DefaultInterrupt(void);
extern unsigned long trapSrcAddr;

void __attribute__((interrupt(preprologue( "rcall _where_was_i ")), no_auto_psv)) _DefaultInterrupt(void)
{
   /* _trapSrcAddr variable will have the address of the trap source , print the value using UART or use debug watch */
   while(1)
   {

   }
}
#else
#define ERROR_HANDLER __attribute__((weak,interrupt,no_auto_psv))
#define FAILSAFE_STACK_GUARDSIZE 8
#define FAILSAFE_STACK_SIZE 32

// A private place to store the error code if we run into a severe error

static uint16_t TRAPS_error_code = -1;

// Section: Driver Interface Function Definitions

//@brief Halts
void __attribute__((weak)) TRAPS_halt_on_error(uint16_t code)
{
    TRAPS_error_code = code;
#ifdef __DEBUG
    /* If we are in debug mode, cause a software breakpoint in the debugger */
    __builtin_software_breakpoint();
    while(1)
    {

    }
#else
    // Trigger software reset
    __asm__ volatile ("reset");
#endif
}

// @brief Sets the stack pointer to a backup area of memory, in case we run into
//   a stack error (in which case we can't really trust the stack pointer)

inline static void use_failsafe_stack(void)
{
    static uint8_t failsafe_stack[FAILSAFE_STACK_SIZE];
    asm volatile (
        "   mov    %[pstack], W15\n"
        :
        : [pstack]"r"(failsafe_stack)
    );

    /* Controls where the stack pointer limit is, relative to the end of the
     * failsafe stack
     */
    /* cppcheck-suppress misra-c2012-11.4
    * Assigning stack pointer address location
    */
    /* cppcheck-suppress misra-c2012-18.4
    * Assigning stack pointer address location
    */
    SPLIM = (uint32_t)(((uint8_t *)failsafe_stack) + sizeof(failsafe_stack) - (uint32_t) FAILSAFE_STACK_GUARDSIZE);
}

/** Bus error trap**/
void ERROR_HANDLER _BusErrorTrap(void)
{
    if(INTCON3bits.CPUBET == 1)
    {
      INTCON3bits.CPUBET = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_CPU_BUS_ERR);
    }

    if(INTCON3bits.XRAMBET == 1)
    {
      INTCON3bits.XRAMBET = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_XRAM_BUS_ERR);
    }

    if(INTCON3bits.DMABET == 1)
    {
      INTCON3bits.DMABET = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_DMA_BUS_ERR);
    }

    if(INTCON3bits.YRAMBET == 1)
    {
      INTCON3bits.YRAMBET = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_YRAM_BUS_ERR);
    }

    while(1)
    {
    }
}

/** Math error trap**/
void ERROR_HANDLER _MathErrorTrap(void)
{
    if(INTCON4bits.OVATE == 1)
    {
      INTCON4bits.OVATE = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_OVAT_ERR);
    }

    if(INTCON4bits.SFTACERR == 1)
    {
      INTCON4bits.SFTACERR = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_SFTAC_ERR);
    }

    if(INTCON4bits.OVBERR == 1)
    {
      INTCON4bits.OVBERR = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_OVB_ERR);
    }

    if(INTCON4bits.DIV0ERR == 1)
    {
      INTCON4bits.DIV0ERR = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_DIV0_ERR);
    }

    if(INTCON4bits.COVBERR == 1)
    {
      INTCON4bits.COVBERR = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_COVB_ERR);
    }

    if(INTCON4bits.COVTE == 1)
    {
      INTCON4bits.COVTE = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_COVT_ERR);
    }

    if(INTCON4bits.OVBTE == 1)
    {
      INTCON4bits.OVBTE = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_OVBT_ERR);
    }

    if(INTCON4bits.OVAERR == 1)
    {
      INTCON4bits.OVAERR = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_OVA_ERR);
    }

    if(INTCON4bits.COVAERR == 1)
    {
      INTCON4bits.COVAERR = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_COVA_ERR);
    }

    while(1)
    {
    }
}

/** Address error trap**/
void ERROR_HANDLER _AddressErrorTrap(void)
{
    INTCON1bits.ADDRERR = 0;  //Clear the trap flag
    TRAPS_halt_on_error(TRAPS_ADDRESS_ERR);
}

/** General error trap**/
void ERROR_HANDLER _GeneralTrap(void)
{
    if(INTCON5bits.XPWBDED == 1)
    {
      INTCON5bits.XPWBDED = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_XPWBDED_ERR);
    }

    if(INTCON5bits.DMTE == 1)
    {
      INTCON5bits.DMTE = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_DMT_ERR);
    }

    if(INTCON5bits.SOFT == 1)
    {
      INTCON5bits.SOFT = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_GEN_ERR);
    }

    if(INTCON5bits.YPWBDED == 1)
    {
      INTCON5bits.YPWBDED = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_YPWBDED_ERR);
    }

    if(INTCON5bits.WDTE == 1)
    {
      INTCON5bits.WDTE = 0;  //Clear the trap flag
      TRAPS_halt_on_error(TRAPS_WDT_ERR);
    }

    while(1)
    {
    }
}

/** Stack error trap**/
void ERROR_HANDLER _StackErrorTrap(void)
{
    /* We use a failsafe stack: the presence of a stack-pointer error
     * means that we cannot trust the stack to operate correctly unless
     * we set the stack pointer to a safe place.
     */
    use_failsafe_stack();

    INTCON1bits.STKERR = 0;  //Clear the trap flag
    TRAPS_halt_on_error(TRAPS_STACK_ERR);
}

/** Illegal instruction trap**/
void ERROR_HANDLER _IllegalInstructionTrap(void)
{
    INTCON1bits.BADOPERR = 0;  //Clear the trap flag
    TRAPS_halt_on_error(TRAPS_ILLEGALINSTRUCTION);
}

#endif
