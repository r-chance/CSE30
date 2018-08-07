/* Robert Chance
 * A13088857
 */
#include <stdio.h>
#include <stdlib.h>
#include "warmup.h"

int main(int argc, char** argv){
      
    int size = 4; // length of string to read from file
    FILE* input; // input file
    FILE* output;
    int* parsed = malloc(sizeof(int)); // pointer to parsed 4 byte string
     
    

    input = fopen(argv[1],"r");// open input file
    output = fopen(argv[2], "w");// open output file

    while(1) {
        
        // read 4 bytes in; break from loop if value is not 1 element
        if( fread( parsed, size, 1, input ) != 1 ) break;
        
        // reorder bytes
        *parsed = reorder_bytes(*parsed);

        // write to output
        fwrite(parsed, size, 1, output);
    }        
   
    fclose(input);
    fclose(output); 
}
