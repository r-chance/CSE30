.syntax unified

.text

.align 3
.global binaryToText
.func binaryToText, binaryToText
.type binaryToText, %function

@ void binaryToText(FILE *in, FILE *out)
binaryToText:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    mov r4, r0 @ move input file pointer to r4
    mov r5, r1 @ move output file pointer to r5
    mov r6, #6 @ r6 contains array size

    mov r0, r6 @ move array size to r0 as param for malloc
    bl malloc @ allocate memory for char array
    mov r7, r0 @ move array pointer to r7

    while:

        mov r1, #1 @ r1 contains num of bytes of each element read from fread
        mov r2, r6 @ r2 contains num of elements to read from fread
        mov r3, r4 @ move input file pointer to r3
        bl fread @ read 6 bytes in from fread, stores in allocated array

        mov r0, r4 @ move input file pointer to r0
        bl feof @ call feof
        cmp r0, #0 @ compare feof return value to 0
        bne return @ exit loop on eof

        mov r0, r7 @ move pointer to array to r0
        bl decodeChar @ call decode char with array as param,
                      @ returns value of character

        mov r1, r5 @ move output file pointer to r1
        bl fputc @ call fputc with extracted char and output file as param

        mov r0, r7 @ move array pointer to r0 before repeating loop
        b while @ loop to top

return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
