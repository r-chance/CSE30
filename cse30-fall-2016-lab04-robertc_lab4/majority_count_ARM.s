.syntax unified

/* You can put constants in the .data section. Look up how to do it on your own,
 * or come ask us if you're curious!*/
.data 


.text

/* int majority_count_ARM(int * arr, int len, int * result)*/
/* Remember to place your return value in r0. */
/* Return the count of the majority element in arr, */
/* or 0 if there is no majority. If "result" is not */
/* NULL, place the value of the majority element at */
/* that memory location before returning. */

.align 8
.global majority_count_ARM
.func majority_count_ARM, majority_count_ARM
.type majority_count_ARM, %function

majority_count_ARM:
    @ We need to save away a bunch of registers
    push    {r4-r11, ip, lr}
    sub sp, sp, #32 @ allocate memory on the stack

 
    @ Base case, if length = 0
    cmp r1, #0    @ compare length to 0
    moveq r0, #0  @ move 0 to r0 on equal
    beq end
 
    @ Base case, if length = 1
    cmp r1, #1
    bne recursion   @ branch to recursion subroutine if length > 1
    cmp r2, #0      @ check validity of result pointer
    ldrne r4, [r0]  @ load array value to r4
    strne r4, [r2]  @ store array value to result
    mov r0, #1      @ move 1 to r0 for return
    b end

    recursion:

        @ arr in sp+28 | len in sp+24 | result in sp+20 | left_majority in sp+16
        @ right_majority in sp+12 | left_majority_count in sp+8
        @ right_majority_count in sp+4 | c in sp+0

        str r0, [sp, #28]   @ store arr pointer to stack
        str r1, [sp, #24]   @ store length to stack
        str r2, [sp, #20]   @ store result pointer to stack
        mov r3, #0
       

        @ left_majority_count
        lsr r1, r1, #1      @ len = len/2
        add r2, sp, #16     @ move address for left_majority to r2
        bl majority_count_ARM  
        str r0, [sp, #8]    @ store left majority return value

        @ right_majority_count
        ldr r1, [sp, #24]      @ load length back to r1
        ldr r0, [sp, #28]      @ load arr pointer back to r0
        mov r3, r1, lsr #1     @ r3 = len/2
        add r0, r0, r3, lsl #2 @ r0 = arr+ 4*(len/2)
        sub r1, r1, r3         @ r1 = len-len/2
        add r2, sp, #12        @ move address for right_majority to r2
        bl majority_count_ARM
        str r0, [sp, #4]       @ store right majority return value

    
        left_majority:    
            ldr r0, [sp, #28]   @ load arr pointer to r0
            ldr r1, [sp, #24]   @ load len to r1        
            ldr r2, [sp, #16]   @ load left_majority to r2
            ldr r3, [sp, #8]    @ load left_majority_count to r3
            cmp r3, #0
            beq right_majority  @ branch to right_majority if no left_majority
            bl count_ARM        @ branch to count
            str r0, [sp]        @ store count to stack
            ldr r1, [sp, #24]   @ load len to r1
            lsr r1, r1, #1      @ r1 = len/2
            cmp r0, r1          @ compare c to len/2
            ldrle r0, [sp, #28] @ restore arr pointer to r0 if no left_majority
            ldrle r1, [sp, #24] @ restore len to r1 if no left_majority
            ble right_majority  @ branch to right_majority if no left_majority
            ldr r4, [sp, #20]   @ load result pointer to r4            
            cmp r4, #0          @ check for null result pointer
            strne r2, [r4]      @ store left_majority to result if valid
            b end               @ branch to end if a left majority

        right_majority:
            ldr r2, [sp, #12]   @ load right_majority to r2
            ldr r3, [sp, #4]    @ load right_majority_count to r3
            cmp r3, #0          @ compare right_majority count to 0
            moveq r0, #0        @ move 0 to r0 for return on no right majority
            beq end
            bl count_ARM
            str r0, [sp]        @ store count to stack
            ldr r1, [sp, #24]   @ load length to r1
            lsr r1, r1, #1      @ r1 = len/2
            cmp r0, r1          @ compare c to len/2
            movle r0, #0        @ move 0 to r0 as return value in no right maj
            ble end             @ branch to end if no right majority
            ldr r4, [sp, #20]   @ load result pointer to r4
            cmp r4, #0          @ check for null result pointer
            strne r2, [r4]      @ store right_majority to result if valid
            b end               @ branch to end

    @ r0 = arr, r1 = len, r2 = target, r5 = i, r6 = ret_count
    count_ARM: 
        
        mov r3, r0   @ store arr pointer to r3
        mov r5, #0   @ set i = 0
        mov r6, #0   @ set ret_count = 0
      
        for:
            cmp r5, r1            @ compare i and len
            beq count_return      @ branch to count_return upon loop complete
            add r0, r3, r5, lsl#2 @ r0 = address of arr[i]
            ldr r4, [r0]          @ load arr[i] to r4
            cmp r4, r2            @ compare arr[i] to target
            addeq r6, r6, #1      @ increment ret_count on equal
            add r5, r5, #1        @ increment i
            b for                 @ branch to top of loop

        count_return:
            mov r0, r6        @ move ret_count to r0 for return
            bx lr             @ branch back to caller


    end: 
      
 
    add sp, sp, #32   @ release allocation on stack
    @ This handles restoring registers and returning
    pop     {r4-r11, ip, lr}

    bx lr

.endfunc

.end


