/* ********************************
 * CSE 30 - HW 4
 *
 * This file is merely designed to give you an idea how to compile/test your own
 * code. You may modify it as you like.
 *
 * ********************************/

#include <stdio.h>

int str_to_int(char * str, int * dest);

int main(int argc, char ** argv) {
    int x;
    char* s;// null string pointer

    if(str_to_int("-123", &x)) {
        printf("%d\n", x);
    } else {
        printf("Invalid integer string\n");
    }

    if(str_to_int("87654321", &x)) {
        printf("%d\n", x);
    } else {
        printf("Invalid integer string\n");
    }

    if(str_to_int("", &x)) {
        printf("%d\n", x);
    } else {
        printf("Invalid integer string\n");
    }

    if(str_to_int("0", &x)) {
        printf("%d\n", x);
    } else {
        printf("Invalid integer string\n");
    }

    if(str_to_int(s, &x)) {
        printf("%d\n", x);
    } else {
        printf("Invalid integer string\n");
    }

    if(str_to_int("1-234", &x)) {
        printf("%d\n", x);
    } else {
        printf("Invalid integer string\n");
    }

    if(str_to_int("a123", &x)) {
        printf("%d\n", x);
    } else {
        printf("Invalid integer string\n");
    }

    if(str_to_int("123a", &x)) {
        printf("%d\n", x);
    } else {
        printf("Invalid integer string\n");
    }

    if(str_to_int("-123456789", &x)) {
        printf("%d\n", x);
    } else {
        printf("Invalid integer string\n");
    }

    if(str_to_int("-", &x)) {
        printf("%d\n", x);
    } else {
        printf("Invalid integer string\n");
    }

    return 0;
}
