// Test code for pointer exercise

#include<stdio.h>

int main(void) {

    long x = 0x0000;
    long y = 0x0005;
    long z = 0xFFFF;

    long *p = &x;
    printf("%ld\n", *p);
   
    p++;
    x = (long) p;

    printf("%ld\n", p);

    printf("%ld\n", x);
    printf("%ld\n", *p);
    printf("%ld\n", *(&(*p)));
    printf("%ld\n", *(p-1) +1);

    return 0;
}
