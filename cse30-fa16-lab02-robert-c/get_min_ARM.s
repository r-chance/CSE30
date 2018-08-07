.syntax unified

.text

.align 8
.global get_min_ARM
.func get_min_ARM, get_min_ARM
.type get_min_ARM, %function

get_min_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE (list *ls is in r0)
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

