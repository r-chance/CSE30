/**
 * ALL FUNCTION IMPLEMENTATIONS AND HELPER FUNCTIONS FOR ENCODER WILL BE IN THIS FILE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "common.h"
#include "encoder.h"
/**
 *
 * This function takes a char c as input and returns a (6 character) array
 * that represents the 6 digit code for that character. This code is simply
 * the index of the char in the MAPPING array (represented in binary). 
 * You should use the REVERSE\_MAPPING array in this function to get 
 * the binary code for the character. REVERSE\_MAPPING array MUST be 
 * initialized with createReverseMapping(), prior to calling this function.
 *
 * @param c The input character to encode
 * @returns a six character array which encodes the index into ASCII binary
 */
char* encodeChar(char c){
    
    // char array to store encoding in
    int arraySize = 6;
    char* binaryCode = malloc(arraySize*sizeof(char));
    unsigned char mappedChar;
    int mask = 1; // mask to remove individual bits from char representation
    

    // get mapped representation of char
    mappedChar = REVERSE_MAPPING[c];

    for(int i = 0; i < arraySize; i++ ) {

        // save each bit of the char to binaryCode
        *(binaryCode+i) = (mappedChar >> (arraySize-i-1)) & mask;

    }

    return binaryCode; 
}

/**
 * Takes a char c and int bit (should be either 0 or 1) and int index as input. 
 * Sets the bit at input index of c to be the input bit and returns the result.
 * The 0 index refers to the LSB, so for example, index 2 should 
 * set the 3rd least significant bit.
 * 
 * @param c the char to implant a bit into
 * @param bit the bit value to implant (0 or 1)
 * @param index the index to implant the bit into (0 is LSB)
 * @returns the char with bit b implanted into the input index
 */
char implantBit(char c, int bit, int index){
    
    char mask = 1;
    char flipBitMask = 0xFF;
    char newChar;

    // shift the 1 bit to the appropriate location
    mask = mask << index; 

    // use bit OR comparison with mask to insert if bit is a 1
    if( bit == 1 ) {
    
        // bit OR to implant bit
        newChar = c | mask;

        return newChar;
    }

    // if bit = 0, flip all bits in c, implant a 1 at index and flip back
    c = c ^ flipBitMask;
    c = c | mask;
    newChar = c ^ flipBitMask;
    return newChar;

}

/**
 * Takes a FILE handle in as input (corresponding to a regular ASCII
 * text file) and reads the file, char by char. Encodes each char into
 * a 6 character "binary" char array (by calling encodeChar).  The
 * resulting character arrays should be written to the output file
 * handle out
 *
 * @param in The input text file to read
 * @param out The output file, in ASCII encoded "binary"
 */
void textToBinary(FILE *in, FILE *out){

    char* charIn = malloc(1); // the char that is read from input file    
    char charRead; // to save char from charIn array
    char* charOut;// char array that will be written to output file
    int length = 6; // length of ASCII rep

    // exit out if either the input or output file pointers are null
    if( in == NULL || out == NULL ) return;

    // Loop until fread fails to read another input
    while( fread( charIn, 1, 1, in ) == 1 )  {
    
        charRead = *charIn;// set charRead to 0th element of array
        charOut = encodeChar( charRead );// encode the char
  
        for( int i = 0; i < length; i++ ) { 
        
            fprintf(out,"%d",charOut[i] );

        } 
        free(charOut);  
    }

    free(charIn);
    
}

/**
 * Takes a FILE handle in as input (corresponding to a
 * "binary" encoded file) and reads the file 1 char at a time. Each
 * char read will be an ASCII '0' or ASCII '1', and either 0 or 1 
 * will be implanted into randomized chars generated by rand()%256.
 *
 * If ASCII '0', then implant 0 into the bit at the input index 
 * of a randomized char . If ASCII '1', then implant 1 into the bit at 
 * the input index of the randomized char (by calling implantBit). 
 * Write the result into the output file handle out 
 * (Note: The least significant bit is in index 0)
 *
 * @param in The input file handle to read (ASCII encoded binary)
 * @param out The output file to write to
 * @param index the index of the bit where binary values should be implanted (0 is LSB)
 */
void binaryToCode(FILE *in, FILE *out, int index){
    srand(1); //DO NOT REMOVE OR EDIT THIS LINE OF CODE
    char random;// generates a random number between 0 and 255
    int charFromFile;// stores char as int
    char implanted; // stored char with implanted bit

    if( in == NULL || out == NULL ) return;
    
    while(1)  {
   
        charFromFile = fgetc(in);
        random = rand()%256;
        if( charFromFile == EOF ) break ;
        
        if( charFromFile == '0' ) {

            implanted = implantBit( random, 0,  index );
        }
        
        if( charFromFile == '1' ) {

           implanted = implantBit( random, 1,  index );
        }
        
        fputc( implanted, out );       
    }    
   
}

/**
 * Reads in a file from the specified input path and outputs a a binary encoding to
 * specified bin path and a fully encoded version to specified output path. 
 * This should simply open the necessary files and call the above helper 
 * functions in the correct sequence, and close the necessary files.
 *
 * @param input the path to the input file
 * @param bin the path to the encoded ASCII binary output file
 * @param output the path to the encoded output file 
 * @param index The index of the bit where binary values should be implanted (0 is LSB)
*/
void encodeFile(char* input, char* bin, char* output, int index){
  
 
     FILE* in = fopen(input, "r");
     FILE* binary = fopen(bin, "w+");
     FILE* out = fopen(output, "w");
     
     // return if any file fails to open
     if( input == NULL || bin == NULL || output == NULL ) return;

     createReverseMapping();

     textToBinary(in, binary);    
     rewind(binary);
     binaryToCode(binary, out, index);

     fclose(in);
     fclose(out);
     fclose(binary);  

     
 
     return;
     
}