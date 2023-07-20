//DOM-IGNORE-BEGIN
/*
Copyright (C) 2023, Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/
//DOM-IGNORE-END

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef DMASPITRANSFER_H
#define	DMASPITRANSFER_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations
#define SIZEOFBUF           (1208u)

#define DMA_CHANNEL_1       (0u)
#define DMA_CHANNEL_2       (1u)

/* DMA1 transfer modes */
#define INC_GPR_FIX_SFR     (0x03u) /* sptr = TrmtBuf */
#define FIX_GPR_FIX_SFR     (0x01u) /* sptr = dummy {0xFF } */

/* DMA2 transfer modes */
#define FIX_SFR_INC_GPR     (0x40u) /* dptr = RcvBuffer */
#define FIX_SFR_FIX_GPR     (0x00u) /* dptr = dummy */

#define DMA_PATTERN_DUMMY   (0xFFu)

#define DMA_TRANSFER_PROGRESS  ( 0x55u)
#define DMA_TRANSFER_DONE       (0x00u)

extern void     vidInitDmaSpiTransfer(void);
extern uint8_t  u8SpiStartTransaction( uint8_t *pu8Tx, uint8_t *pu8Rx, uint16_t u16length);
extern uint8_t  u8GetProcessStatus(void);
extern void     vidDma2DestCountISR(void);
extern void     vidTransactionDone(void);

/* these both functions are defined outside of this file */
extern void vidChipSelectLow(void);
extern void vidChipSelectHigh(void);


// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C"
{
#endif /* __cplusplus */

// TODO If C++ is being used, regular C code needs function names to have C 
// linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* DMASPITRANSFER_H */

