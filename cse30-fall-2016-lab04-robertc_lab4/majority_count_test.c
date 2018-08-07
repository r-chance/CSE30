/* ********************************
 * CSE 30 - HW 4
 * ********************************/

#include <stdio.h>
#include "majority_count.h"

int main(int argc, char ** argv) {

    int data1[] = {1,0,1,1};
    int data2[] = {1};
    int data3[] = {1,0};
    int data4[] = {1,1,2,3,5,8,13};
    int data5[100] = {1};
    int data6[] = {0,1,2,3,4,5,6,7,8,9};
    int data7[] = {2,1,1,3};

    // TEST data1
    int c_majority, arm_majority;
    int c_count = majority_count(data1, 4, &c_majority);
    int arm_count = majority_count_ARM(data1, 4, &arm_majority);

    printf("Test 1\n");
    printf("C   Majority Count  : %d\n", c_count);
    printf("C   Majority Element: %d\n", c_majority);
    printf("ARM Majority Count  : %d\n", arm_count);
    printf("ARM Majority Element: %d\n", arm_majority);
    printf("\n");
    
    // TEST data2
    c_count = majority_count(data2, 1, &c_majority);
    arm_count = majority_count_ARM(data2, 1, &arm_majority);

    printf("Test 2\n");
    printf("C   Majority Count  : %d\n", c_count);
    printf("C   Majority Element: %d\n", c_majority);
    printf("ARM Majority Count  : %d\n", arm_count);
    printf("ARM Majority Element: %d\n", arm_majority);
    printf("\n");

    // TEST data3
    c_count = majority_count(data3, 2, &c_majority);
    arm_count = majority_count_ARM(data3, 2, &arm_majority);

    printf("Test 3\n");
    printf("C   Majority Count  : %d\n", c_count);
    printf("C   Majority Element: %d\n", c_majority);
    printf("ARM Majority Count  : %d\n", arm_count);
    printf("ARM Majority Element: %d\n", arm_majority);
    printf("\n");

    // TEST data4
    c_count = majority_count(data4, 7, &c_majority);
    arm_count = majority_count_ARM(data4, 7, &arm_majority);

    printf("Test 4\n");
    printf("C   Majority Count  : %d\n", c_count);
    printf("C   Majority Element: %d\n", c_majority);
    printf("ARM Majority Count  : %d\n", arm_count);
    printf("ARM Majority Element: %d\n", arm_majority);
    printf("\n");

    // TEST data5
    c_count = majority_count(data5, 100, &c_majority);
    arm_count = majority_count_ARM(data5, 100, &arm_majority);

    printf("Test 5\n");
    printf("C   Majority Count  : %d\n", c_count);
    printf("C   Majority Element: %d\n", c_majority);
    printf("ARM Majority Count  : %d\n", arm_count);
    printf("ARM Majority Element: %d\n", arm_majority);
    printf("\n");
 
    // TEST data6
    c_count = majority_count(data6, 10, &c_majority);
    arm_count = majority_count_ARM(data6, 10, &arm_majority);

    printf("Test 6\n");
    printf("C   Majority Count  : %d\n", c_count);
    printf("C   Majority Element: %d\n", c_majority);
    printf("ARM Majority Count  : %d\n", arm_count);
    printf("ARM Majority Element: %d\n", arm_majority);
    printf("\n");
 
    // TEST data7
    c_count = majority_count(data7, 4, NULL);
    arm_count = majority_count_ARM(data7, 4, NULL);

    printf("Test 7\n");
    printf("C   Majority Count  : %d\n", c_count);
    printf("ARM Majority Count  : %d\n", arm_count);
 
    return 0;
}
