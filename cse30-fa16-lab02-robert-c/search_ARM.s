.syntax unified

.text

.align 8
.global search_ARM
.func search_ARM, search_ARM
.type search_ARM, %function

search_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0, int val is in r1)
    @-----------------------

    @ (your code)

    @ put your return value in r0 here:

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

