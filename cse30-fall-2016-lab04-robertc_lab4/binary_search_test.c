/* ********************************
 * CSE 30 - HW 4
 * ********************************/

#include <stdio.h>
#include "binary_search.h"

int main(int argc, char ** argv) {
    int data[] = {1,2,3,4,5,6,7,8,9,10};
    int data2[] = {1};
    int data3[] = {0,0,0,1,1,2,2,3,4,5};
    int data4[] = {1,3,5,7,9};

    printf("C   Binary Search: %d\n", binary_search(data, 4, 0, 9));
    printf("ARM Binary Search: %d\n", binary_search_ARM(data, 4, 0, 9));
 
    printf("C   Binary Search: %d\n", binary_search(data2, 4, 0, 0));
    printf("ARM Binary Search: %d\n", binary_search_ARM(data2, 4, 0, 0));

    printf("C   Binary Search: %d\n", binary_search(data2, 1, 0, 0));
    printf("ARM Binary Search: %d\n", binary_search_ARM(data2, 1, 0, 0));

    printf("C   Binary Search: %d\n", binary_search(data3, 4, 0, 9));
    printf("ARM Binary Search: %d\n", binary_search_ARM(data3, 4, 0, 9));

    printf("C   Binary Search: %d\n", binary_search(data3, 1, 0, 9));
    printf("ARM Binary Search: %d\n", binary_search_ARM(data3, 1, 0, 9));

    printf("C   Binary Search: %d\n", binary_search(data4, 5, 0, 4));
    printf("ARM Binary Search: %d\n", binary_search_ARM(data4, 5, 0, 4));

    printf("C   Binary Search: %d\n", binary_search(data4, 0, 0, 4));
    printf("ARM Binary Search: %d\n", binary_search_ARM(data4, 0, 0, 4));



    return 0;

}
