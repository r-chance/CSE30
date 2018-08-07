/* Robert Chance
 * A13088857
 */

#include <stdio.h>
#include <stdlib.h>
#include "warmup.h"

/* This function take a file stream as input, parses each character and adds
 * to the array index specified by the ascii value of the character for each
 * character read.
 */
unsigned int *char_freqs(FILE *fp){
   
    unsigned int* freqCount;// 0 initialized array
    const int sizeOfArray = 256; 
    unsigned int ascii;

    if(fp == NULL) return NULL; // return NULL if file pointer is null

    freqCount = calloc(sizeOfArray,sizeof(int));

    // Loop until EOF
    while(1)   {
    
        ascii = fgetc(fp); // set ascii equal to int representation on char     
        
        if(feof(fp)) break; // exit loop if eof 
        freqCount[ascii]++; // increment appropriate array element  
 
    }

    return freqCount;

}
  

int reorder_bytes(int num){

    unsigned int mask_byte0 = 0xff;
    unsigned int mask_byte1 = 0xff00;
    unsigned int mask_byte2 = 0xff0000;
    unsigned int mask_byte3 = 0xff000000;

    unsigned int reversed0 = 0, reversed1 = 0, reversed2 = 0, reversed3 = 0;
    int reordered = 0;
    // reorder bytes
    reversed0 = num & mask_byte0;
    reversed0 = reversed0<<24;
    reversed1 = num & mask_byte1;
    reversed1 = reversed1<<8;
    reversed2 = num & mask_byte2;
    reversed2 = reversed2>>8;
    reversed3 = num & mask_byte3;
    reversed3 = reversed3>>24;
    reordered = reversed0 | reversed1 | reversed2 | reversed3;
    
    return reordered;
}
