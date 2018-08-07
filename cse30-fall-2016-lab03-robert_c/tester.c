/**
 * THIS FILE MAY BE USED FOR TEST CODE. IT WILL NOT BE COLLECTED
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "common.h"
#include "encoder.h"
#include "decoder.h"

int main(int argc, char *argv[]){
    char* array; 
   
    

/*
    FILE* this = fopen(argv[1], "r" );
    FILE* that = fopen(argv[2], "r+" );
    FILE* code = fopen(argv[3], "w" );

    createReverseMapping();

    textToBinary(this, that );
    rewind(this);
    rewind(that);
    binaryToCode(that, code, 0 );
    fclose(this);
    fclose(that);
*/

//encodeFile(argv[1], argv[2], argv[3], 3);
decodeFile(argv[1], argv[2], argv[3], 3);
   

   

    return 0;
}
