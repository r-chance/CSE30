.syntax unified

.text

.align 3
.global decodeChar
.func decodeChar, decodeChar
.type decodeChar, %function

@ char decodeChar(char *b)
decodeChar:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    mov r9, #48 @ used to shift ascii chars of 0 and 1 to their value
    mov r8, #6 @ length of char array
    mov r7, #1 @ stores 2^n; n=0 at this point
    mov r6, #0 @ counter of loop   
    mov r4, #0 @ index for mapping array

    for:

        cmp r6, r8 @ compare counter with array size
        beq end @ branch to end if loop finished
        sub r5, r8, #1 @ r5 contains size of array -1
        sub r5, r5, r6 @ subtract counter from r5
        
        add r1, r0, r5 @ r1 contains mem address of b[size-i-1]
        ldrb r2, [r1] @ r2 contains value of b[size-i-1] in ASCII
        sub r2, r9 @ r2 contains either a 0 or 1
        mul r3, r2, r7 @ multiply r2 by 2^n
        add r4, r4, r3 @ index += r3

        lsl r7, r7, #1 @ increase exponent of 2^n
        add r6, r6, #1 @ increment counter
     
        b for @ branch to top of loop
        
    end:

        ldr r0, =MAPPING @ move mapping array address to r0
        add r0, r0, r4 @ offset mapping address by r4
        ldrb r0, [r0] @ load value of MAPPING[index] to r0

return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
