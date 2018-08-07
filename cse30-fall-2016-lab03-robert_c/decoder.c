/**
 * ALL IMPLEMENTATIONS AND HELPER FUNCTIONS FOR DECODER WILL BE IN THIS FILE.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "decoder.h"
 
/**
 * Takes a char c and int index as input. 
 * Extracts the bit at the input index from the char c. The 0 index
 * refers to the LSB, so for example, index 2 should extract the 3rd
 * least significant bit.
 *
 * @param c the char to extract a bit from
 * @param index the index of the bit to extract
 * @returns the value of the bit at index in c
 */
/*int extractBit(char c, int index){
    int mask = 1;
    
    // shift bits left by index and extract bit
    return (c >> index) & mask;

} */

/**
 * Takes a 6 character array b as input and returns the corresponding
 * char from MAPPING that is indexed by the binary ASCII string b.
 * For example, if b = "010101", then the char that is mapped to it is 
 * in MAPPING, index 1*16 + 1*4 + 1*1 = 21.
 *
 * @param b a pointer to a 6 character array, with ASCII '1's and '0's
 * @returns the corresponding character from MAPPING
 */
/*char decodeChar(char *b){
    
    const int shift = 48;
    int index = 0;
    const int arraySize = 6;
    int i = 1;
    int ascii = 0;

    for( int j = 0 ; j < arraySize; j++ ) {

        index = b[arraySize - 1 - j] - shift;
        ascii += i * index;
        i = i<<1;

    }
    return MAPPING[ascii];
}*/

/**
 * Takes a FILE handle in as input (corresponding to
 * an encoded file) and reads the file, char by char. The
 * bit at the input index of each char is extracted (by calling
 * extractBit). The least significant bit is in index 0.
 *
 * For each character, if the extracted bit is 0, output ASCII '0' to
 * the output file. If the extracted bit is 1, output ASCII
 * '1' to the output file.
 *
 * @param in the input file handle to read from
 * @param out the output file to write the extracted ASCII binary into
 * @param index the index of the bit to extract from each char
*/
/*void codeToBinary(FILE *in, FILE *out, int index){
    
    char extracted;
    int bitValue;

    while(1) {

        extracted = fgetc(in);
        if( feof(in) ) break;

        bitValue = extractBit( extracted, index );

        fprintf(out,"%d", bitValue );
    }
   
}
*/
/**
 * Takes a FILE handle in as input (corresponding to a
 * "binary" decoded file) and reads the file, 6 chars at a
 * time. Each 6 chars (all ASCII 0's and 1's) should be read into a
 * char array and decoded into its corresponding char (by calling
 * decodeChar). The resulting chars would be output to the FILE handle
 * pointed to by out.
 *
 * @param in the input file, encoded as ASCII '1's and '0's
 * @Param out the decoded output file (ASCII)
*/
/*void binaryToText(FILE *in, FILE *out){
 
    int arraySize = 6;
    char* array = malloc(arraySize*sizeof(char));
    char extracted;
 
    // loop until EOF
    while(1) {

        fread(array, 1, arraySize, in);

        if( feof(in) ) break;// break from loop if EOF
        
        
        // decode array into char
        extracted = decodeChar( array );

        // write to file
        fputc( extracted, out );
    }

            
}*/

/**
 * Reads in a file from the specified input path and outputs a a binary decoding to
 * specified bin path and a fully decoded version to specified output path.
 * This should simply open the necessary files, call the above helper functions
 * in the correct sequence, and close the necessary files.
 *
 * @param input the path to the input file
 * @param bin the path to the decoded ASCII binary output file
 * @param output the path to the decoded output file
 * @param index The index of the bit from which binary values should be extracted
 */
/*void decodeFile(char* input, char* bin, char* output, int index){
    

    FILE *in, *binary, *out;

    in = fopen(input, "r");
    binary = fopen(bin, "w+");
    out = fopen(output, "w");

    // return if any file fails to open
    if( in == NULL || binary == NULL || out == NULL ) return;

    createReverseMapping();

    codeToBinary( in, binary, index );
    rewind( binary );// place file pointer at top of file
    binaryToText( binary, out );
    
  
}*/
