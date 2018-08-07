.syntax unified

.text

/*int binary_search_ARM(int * data, int toFind, int start, int end)*/

.align 8
.global binary_search_ARM
.func binary_search_ARM, binary_search_ARM
.type binary_search_ARM, %function

binary_search_ARM:
    @ store caller's registers to the stack
    push    {r4-r11, ip, lr}
    
    sub r4, r3, r2             @ r4 = end-start
    add r4, r2, r4, lsr #1     @ r4 = mid = start + (end - start)/2
    sub sp, sp, #8             @ decrement stack pointer
    str r4, [sp, #4]           @ store mid to stack
    lsl r4, r4, #2             @ address offset for data[mid]
    add r4, r4, r0             @ r4 contains address of data[mid]

    @ Base case 1, if element is not in list
    cmp r2, r3      @ compare start and end locations
    mvngt r0, #0    @ move -1 to r0 if start > end
    bgt end

    @ Base case 2, if element is at mid
    ldr r5, [r4]        @ load data[mid] to r5
    cmp r5, r1          @ compare data[mid] to toFind
    ldreq r0, [sp, #4]  @ move index of mid to r0
    beq end

    @ if data[mid] > toFind
    ldrgt r4, [sp, #4]  @ load mid to r4
    subgt r4, r4, #1    @ decrement mid
    movgt r3, r4        @ move mid-1 (new end value) to r3
    blgt binary_search_ARM
    bgt end

    @ if data[mid] < toFind
    ldrlt r4, [sp, #4]  @ load mid to r4
    addlt r4, r4, #1    @ increment mid
    movlt r2, r4        @ move mid+1 (new start value) to r2
    bllt binary_search_ARM
    blt end

    end:

        add sp, sp, #8  @ incrememnt stack point to release local var

    @ This handles restoring registers and returning
    pop     {r4-r11, ip, lr}

    bx lr

.endfunc

.end


