.syntax unified

.text

.align 8
.global substring
.func substring, substring
.type substring, %function

substring:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ char *str1 is in r0, char *str2 is in r1

    cmp r0, #0        @ check str1 for null pointer
    cmpne r1, #0      @ check str2 for null pointer
    beq null_pointer  @ branch to null_pointer if either pointer is null

    mov r4, r0 @ move str1 to saved register
    mov r5, r1 @ move str2 to saved register

    @ determine which string is longer
    bl strlen   @ get length of str1
    mov r6, r0  @ save length to r6
    mov r0, r5  @ move str2 to r0
    bl strlen   @ get length of str2
    mov r7, r0  @ save length to r7
    cmp r6, r7  @ compare both lengths
    
    @ place shorter string in r0, longer in r1
    movle r0, r4   @ move str1 to r0 if shorter than str2
    movle r1, r5   @ move str2 to r1 if longer than str1
    movgt r0, r5   @ move str2 to r0 if shorter than str1
    movgt r1, r4   @ move str1 to r1 if longer than str2
    movgt r4, r5   @ move pointer to shorter string to r4

    compare:

        ldrb r2, [r0]  @ load str1 character to r2
        cmp r2, #0     @ compare with null char
        moveq r0, #1   @ if null, str1 is a substring
        beq end
 
        ldrb r3, [r1]  @ load str2 character to r3
        cmp r3, #0     @ compare str2 with null char
        moveq r0, #0   @ if null, str1 is not a substring
        beq end

        cmp r2, r3       @ compare str1 char with str2 char
        addeq r0, r0, #1 @ increment str1 pointer on equal
        movne r0, r4     @ reset str1 pointer if not equal
        add r1, r1, #1   @ increment str2 pointer 

        b compare  @ branch to top of compare subroutine

    null_pointer:
 
        mov r0, #0  @ move 0 to r0 as return value for null pointer(s)
    
    end:

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end

