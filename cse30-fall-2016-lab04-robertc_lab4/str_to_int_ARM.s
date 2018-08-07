.syntax unified

/* You can put constants in the .data section. Look up how to do it on your own,
 * or come ask us if you're curious!*/
.data 


.text

/* int str_to_int(char * str, int * dest);*/
/* Return 1 for success and 0 for failure. */
/* If successful, store the result at the */
/* location pointed to by "dest" */

.align 8
.global str_to_int
.func str_to_int, str_to_int
.type str_to_int, %function

str_to_int:
    @ We need to save away a bunch of registers
    push    {r4-r11, ip, lr}

    mov r4, r0  @ move string pointer to r4
    mov r5, r1  @ move int pointer to r5
    mov r6, #1  @ r6 is digit index of each base 10 digit
    mov r7, #0  @ used to clear existing value in dest, also as negative flag
    mov r8, #10 @ base for decimal numbering

    @ check for null pointers, return 0 if either are null
    cmp r0, #0
    cmpne r1, #0
    moveq r0, #0
    beq end

    str r7, [r1] @ clear any existing value in dest

    bl strlen  @ get length of string
    mov r2, r0 @ move length to r2

    @ check for and handle negative preceeding string of numbers    
    ldrb r0, [r4]      @ load first char value of string to r0
    cmp r0, #45        @ compare parsed value to ascii '-' 
    moveq r7, #1       @ move 1 to r7 to indicate negative value
    subeq r2, r2, #1   @ decrement length of string
    addeq r4, r4, #1   @ increment string pointer
    ldrbeq r0, [r4]    @ load next char to r0
        
    @ check for empty string, return 0 if empty
    cmp r0, #0    
    moveq r0, #0  
    beq end

    sub r2, r2, #1  @ subtract 1 from string length, used for base10 indexing

    while:

        cmp r0, #0     @ compare parsed value to null terminator
        beq handle_negative

        @ check that parsed value is not a non-number
        cmp r0, #57    @ compare with ascii '9'
        movgt r0, #0   @ move 0 for return value if not a number
        bgt end
        cmp r0, #48    @ compare with ascii '0'
        movlt r0, #0   @ move 0 for return value if not a number
        blt end

        @ loop will provide index of base 10 number, i.e. 10^x
        mov r3, #0       @ set r3 to 0 for loop counter
       
        for:

            cmp r3, r2   @ loop header comparison
            beq construct_number

            mul r9, r6, r8 @ multiply index by powers of 10
            mov r6, r9     @ move result back to r6

            add r3, r3, #1  @ increment counter
            b for           @ return to top of for loop

        construct_number:

            sub r0, r0, #48 @ subtract ascii value of '0' from parsed value
            mul r9, r0, r6  @ multiply number by base 10 index
            mov r0, r9      @ move multiplied value back to r0
            ldr r3, [r5]    @ load dest value to r3
            add r0, r0, r3  @ add dest value with parsed value
            str r0, [r5]    @ store resulting value back at r5 address
 
            mov r6, #1      @ reset index to 1
            sub r2, r2, #1  @ subtract 1 from length

            add r4, r4, #1  @ increment string pointer
            ldrb r0, [r4]   @ load next char value to r0

            b while         @ branch to top of while loop

    handle_negative:

        cmp r7, #1        @ check negative flag
        ldreq r0, [r5]    @ load dest value to r0
        mvneq r0, r0      @ flip bits if negative
        addeq r0, r0, #1  @ add 1 for 2's compliment
        streq r0, [r5]    @ store value back at r5 address
        
        mov r0, #1        @ move 1 to r0 for successful return value

    end:

    @ This handles restoring registers and returning
    pop     {r4-r11, ip, pc}

.endfunc

.end


