/* ********************************
 * CSE 30 - HW 3
 * ********************************/

#include <stdio.h>
#include <assert.h>
#include "substring.h"

int main() {
    
    char* str1 = "abc";
    char* str2 = "abcd";
    char* str3 = "abdc";
    char* str4 = "";
    char* str5 = "bandana";
    char* str6 = "banana";
    char* str7 = "nana";   
    char* str8 = "and";
    char* str9;

    // Test cases
    assert( substring(str1, str2) == 1 );
    assert( substring(str1, str3) == 0 );
    assert( substring(str1, str4) == 1 );
    assert( substring(str4, str4) == 1 );
    assert( substring(str5, str6) == 0 );
    assert( substring(str6, str7) == 1 );
    assert( substring(str5, str8) == 1 );
    assert( substring(str8, str9) == 0 );    

    // Test cases with args switched
    assert( substring(str2, str1) == 1 );
    assert( substring(str3, str1) == 0 );
    assert( substring(str4, str1) == 1 );
    assert( substring(str4, str4) == 1 );
    assert( substring(str6, str5) == 0 );
    assert( substring(str7, str6) == 1 );
    assert( substring(str8, str5) == 1 );
    assert( substring(str9, str8) == 0 );

    return 0;
}
