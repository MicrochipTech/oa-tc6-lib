/**
 * TRAPS Generated Driver Source File
 *
 * @file      traps.c
 *
 * @ingroup   trapsdriver
 *
 * @brief     This is the generated driver source file for TRAPS driver
 *
 * @skipline @version   PLIB Version 1.1.0
 *
 * @skipline  Device : dsPIC33AK512MPS512
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

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

#define FIND_TRAP_SOURCE

#ifdef FIND_TRAP_SOURCE
void __attribute__((interrupt(preprologue("rcall _where_was_i ")), no_auto_psv)) _DefaultInterrupt(void);
extern unsigned long trapSrcAddr;

void __attribute__((interrupt(preprologue( "rcall _where_was_i ")), no_auto_psv)) _DefaultInterrupt(void)
{
   /* _trapSrcAddr variable will have the address of the trap source , print the value using UART or use debug watch */
   __builtin_software_breakpoint();
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
    SPLIM = (uint32_t)(((uint8_t *)failsafe_stack) + sizeof(failsafe_stack) - (uint32_t) FAILSAFE_STACK_GUARDSIZE);
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
    INTCON5bits.SOFT = 0;  //Clear the trap flag
    TRAPS_halt_on_error(TRAPS_GEN_ERR);
}

/** Math error trap**/
void ERROR_HANDLER _MathErrorTrap(void)
{
    INTCON4bits.DIV0ERR = 0;  //Clear the trap flag
    TRAPS_halt_on_error(TRAPS_DIV0_ERR);
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
