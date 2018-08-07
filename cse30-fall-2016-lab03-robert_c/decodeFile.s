.syntax unified

.text

.align 3
.global decodeFile
.func decodeFile, decodeFile
.type decodeFile, %function
 
@ void decodeFile(char *input, char *bin, char * output, int index)
decodeFile:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ write string constants to data segment
    .data
    read: .asciz "r" @ string for open file in read mode
    readWrite: .asciz "w+" @ string for open file in read/write mode
    write: .asciz "w" @ string for open file in write mode

    @ write to text segment
    .text


    @ Open files
    mov r5, r1 @ move pointer to binary file name to r5
    mov r6, r2 @ move pointer to output file name to r6  
    mov r7, r3 @ move index to r3

    ldr r1, =read @ load "r" string to r1
    bl fopen @ call fopen to open input file
    mov r4, r0 @ move input file pointer to r4
 
    mov r0, r5 @ move pointer to binary file name to r0
    ldr r1, =readWrite @ load "w+" to r1
    bl fopen @ call fopen to open binary file
    mov r5, r0 @ move binary file pointer to r5

    mov r0, r6 @ move pointer to output file name to r0
    ldr r1, =write @ load "w" to r1
    bl fopen @ call fopen to open output file
    mov r6, r0 @ move output file pointer to r6

    @ Check for null file pointers
    cmp r4, #0 @ check input file for null pointer
    beq end
    cmp r5, #0 @ check binary file for null pointer
    beq end
    cmp r6, #0 @ check output file for null pointer
    beq end

    bl createReverseMapping @ call create reverse mapping

    mov r0, r4 @ move input file pointer to r0
    mov r1, r5 @ move binary file pointer to r1
    mov r2, r7 @ move index to r2
    bl codeToBinary @ call codeToBinary with input, binary, index as param

    mov r0, r5 @ move binary file pointer to r0
    bl rewind @ reset pointer inside binary file to top of file
    mov r0, r5
    mov r1, r6 @ move output file to r1
    bl binaryToText @ call binary to text with binary, output as param

end:
    

return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
