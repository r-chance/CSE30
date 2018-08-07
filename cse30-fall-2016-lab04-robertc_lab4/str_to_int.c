/* This file contains the c code for the same implementation as the file
 * str_to_int.s, which converts a string representation of an integer value
 * to a decimal representation.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* This function takes as parameters a string representing an integer value,
 * and an integer pointer for where the value will be stored.  It converts the
 * string to a 32-bit signed representation of the integer, stores the value
 * and returns 1 on success, 0 otherwise.
 */
int str_to_int(char* s, int* dest) {

    char parsed; // character extracted from string
    char negative = 0; // stores 1 if num is negative, 0 if positive
    char length; // stores length of string    
    char base = 10; // used for placing each number at correct digit (base10)
    int index = 1;
    char asciiShift = 48; // ascii value of '0'    

    // return 0 if either pointer is null
    if( s == 0 || dest == 0 ) return 0;

    // clear value of dest, if any
    *dest = 0;

    length = strlen(s);// stores length of string

    parsed = *s;  // move first byte of s to parsed
    
    // set negative flag if first byte is negative char
    if( parsed == 45 ) {

        negative = 1;  
        length--; // decrease length of string by 1  
        parsed = *(++s);// get next byte
    }

    // return 0 if string is empty
    if( parsed == 0 ) return 0;

    // convert string to integer value
    while( parsed != 0 ) {

        // return 0 if parsed char is not a number
        if( parsed > 57 || parsed < 48 ) return 0;

        int i;
        for( i = 0; i < length-1; i++ ) {

            index = base*index; // multiple of the parsed digit
        }

        *dest += (parsed-asciiShift)*index;
        index = 1;
        length--;
        parsed = *(++s);
    }

    if( negative ) {

        *dest = ~(*(dest)) + 1; // take 2's comp if negative
    }

    return 1;
}





