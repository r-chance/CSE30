.syntax unified

.text

.align 3
.global extractBit
.func extractBit, extractBit
.type extractBit, %function

@ int extractBit(char c, int index)
extractBit:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    mov r2, #1 @ move a 1 to r2 as a bit mask
    lsr r0, r0, r1 @ shift the bits in r0 right by value of index (r1)
    and r0, r2 @ perform bit and with ro and mask; contains bit at index

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
