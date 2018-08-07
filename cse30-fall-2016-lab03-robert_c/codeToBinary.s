.syntax unified

.text

.align 3
.global codeToBinary
.func codeToBinary, codeToBinary
.type codeToBinary, %function

@void codeToBinary(FILE *in, FILE *out, int index);

codeToBinary:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ write string constant to data section
    .data      
    decimal: .asciz "%d" @ store decimal format identifier in data section

    @ write to text section
    .text

    mov r4, r0 @ move file pointer in to r4
    mov r5, r1 @ move file pointer out to r5
    mov r6, r2 @ move index to r6

    while:

        bl fgetc @ call fgetc() with in as param
        mov r7, r0 @ move return value of fgetc to r7
        mov r0, r4 @ more file pointer in to r0, param for feof
        bl feof @ call feof() with file pointer in as param
        cmp r0, #0 @ compare feof return with 0
        bne return @ exit loop if feof return != 0

        mov r0, r7 @ move return value of fgetc to r0
        mov r1, r6 @ move index back to r1
       
        bl extractBit @ call extractBit with read char and index as params
                      @ returns value of encoded bit, 0 or 1

        mov r2, r0 @ move extracted bit to r2
        mov r0, r5 @ move file pointer out to r0
        ldr r1, =decimal @ move format identifier to r1
        
        bl fprintf @ calls fprintf with out, format, bit value as param

        mov r0, r4 @ move input file pointer back to r0
        b while @ branch to start of loop 

        

return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
