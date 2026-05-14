/**
*   12 bytes pushed to stack after the trap happens including the handler and where_was_i call.
*   substracting 12 from the current stack pointer will give the source of trap.
*
*   current SP                        +12
*   where_was_i   push.l w0           +8
*   rcall in      PC 23->16           +6
*   handler       PC 15->0            +4
*                 PC 23->16           +2
*   TRAP!         PC 15->0            +0
*/
    .section *,bss,near
    .global _trapSrcAddr
 _trapSrcAddr:   .space 4

    .text
    .global _where_was_i
 _where_was_i:
    push.l w0
    sub.l w15,#12,w0
    mov.l [w0], w0
    mov.l w0, _trapSrcAddr
    pop.l w0
    return
