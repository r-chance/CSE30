/* Robert Chance
 * A13088857
 */

/* This is a tester file for the arraySort program.  It performs several tests
 * on each function and provides a tool for debugging.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "arraysort.h"


/* This will test the functionality of createlist(). */
list* test_createList(int elements) {

    // Create new list struct
    list* newList; 

    // Allocate memory for list of 'elements'
    newList = createlist(elements);

    return newList;
}


/* This will test the function insert() and ensure that elements are properly
 * inserted to the linked list.
 */
int test_insert(list* ls, int val) {

    // Add value to empty list
    return insert( ls, val );
}


int main(void)
{
    
    // Test cases for createlist()
    {
    // Create references to deallocate memory later
    list* testListNeg = test_createList(-1);
    list* testListZero = test_createList(0);
    list* testListOne = test_createList(1);
    list* testListBig = test_createList(10000);
    // Test functionality
    assert( testListZero -> sortedList == NULL && 
            testListZero -> maxSize == 0 );
    assert( testListOne -> sortedList != NULL &&
            testListOne -> maxSize == 1 );   
    assert( testListNeg == NULL ); 
    assert( testListBig -> sortedList != NULL &&
            testListBig -> maxSize == 10000 );
    // Deallocate memory 
    free(testListOne -> sortedList);
    free(testListBig -> sortedList);
    free(testListZero);
    free(testListOne);
    free(testListBig);
    }// end of createlist test cases



    // Test cases for insert()
    list* empty = createlist(0);// test with list of 0 max elements
    list* nonempty = createlist(10);// test with list of 10 max elements
    // Test on empty list
    assert( insert(empty, 2) == 0 );
    assert( insert(empty, 4) == 1 );
    assert( insert(empty, 3) == 1 );
    // Test on non-empty list
    assert( insert(nonempty, 2) == 0 );
    assert( insert(nonempty, 4) == 1 );
    assert( insert(nonempty, 3) == 1 );
    // Deallocate memory
    free(empty);
    free(nonempty);
    
   

    // Test cases for remove_val()
    list* ls1 = createlist(10);    
    insert(ls1, 0);
    insert(ls1, 2);
    insert(ls1, 4);
    insert(ls1, 4);
    // Test functionality
    assert( remove_val(ls1, 0) == 1);
    assert( remove_val(ls1, 5) == 0);
    assert( remove_val(ls1, 4) == 2);
    // Deallocate
    free(ls1);


    // Test cases for get_max_value()
    ls1 = createlist(0);// empty list
    list* ls2 = createlist(10);
    insert(ls2, 1);
    insert(ls2, 4);
    insert(ls2, 139);
    insert(ls2, 1500);
    insert(ls2, 12);
    // Test functionality
    assert( get_max_value(ls1) == -1 );
    assert( get_max_value(ls2) == 1500 );
    // Deallocate
    free(ls1);
    free(ls2);



    // Test cases for get_min_value()
    ls1 = createlist(0);// empty list
    ls2 = createlist(10);
    insert(ls2, 1500);
    insert(ls2, 1600);
    insert(ls2, 1700);
    insert(ls2, 1800);
    // Test functionality
    assert( get_min_value(ls2) == 1500 );
    assert( get_min_value(ls1) == -1 );
    // Deallocate
    free(ls1);
    free(ls2);



    // Test cases for search()
    ls1 = createlist(0);// empty list
    ls2 = createlist(10);
    insert(ls2, 1);
    insert(ls2, 2);
    insert(ls2, 3);
    insert(ls2, 1);
    // Test functionalit
    assert( search(ls1, 1) == -1 );
    assert( search(ls2, 4) == -1 );
    assert( search(ls2, 1) == 0 );
    assert( search(ls2, 2) == 2 );
    // Deallocate
    free(ls1);
    free(ls2);



    // Test cases for pop_min()
    list* list1 = createlist(10);
    list* list2 = createlist(0);
    insert(list1, 2);
    insert(list1, 3);
    insert(list1, 1);
    insert(list1, 4);
    insert(list1, 3);

    // Test functionality
    assert( pop_min(list1) == 1 );
    assert( pop_min(list1) == 2 ); 
    assert( pop_min(list2) == -1 );

    // Deallocate memory
    free(list1);
    free(list2);



    // Test cases for print()
    ls1 = createlist(10);
    insert(ls1, 0);
    insert(ls1, 5);
    insert(ls1, 10);
    insert(ls1, 15);
    insert(ls1, 20);
    // Test by visual inspection
    print(ls1);
    // Deallocate
    free(ls1);
 
 
    return 0;
}
