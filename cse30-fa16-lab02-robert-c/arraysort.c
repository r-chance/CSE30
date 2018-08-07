/*
 * Robert Chance
 * A13088857
 */


#include <stdio.h>
#include <stdlib.h>

#include "arraysort.h"
/**
 * This function creates an empty list, with space allocated for an array of
 * maxElements ints (pointed to by int *sortedList) and returns a pointer to 
 * the list.
 */
list* createlist(int maxElements)
{
    int* firstElement;// pointer to newly allocated array location
    list* newList = malloc(sizeof(list));// pointer to new list struct

    // Return null pointer to list for invalid length of list 
    if( maxElements < 0 ) {
        
        free(newList);// Deallocate memory from newList
        return NULL;
    }
    

    // Return list with null pointer to first element for 0 element list
    if( maxElements == 0 ) {
        newList -> size = 0;
        newList -> maxSize = 0;
        newList -> sortedList = NULL;
        return newList;
    }

    // Return list with pointer to first element and max size of list
    newList -> maxSize = maxElements;
    newList -> size = 0;
    newList -> sortedList = malloc(maxElements*sizeof(int));
    
    return newList;
}

/**
 * This function takes a pointer to the list and an integer value as input. It
 * should insert the value 'val' into sortedList, update the number of elements
 * in the list and return the index where the element was inserted. If the list
 * is full before inserting the element, it should increase the size of the
 * list to double its previous size and then insert the element. If the result
 * of the insert was not successful it should return -1. Note that the 
 * resulting list should be sorted and there should be no information loss.
 * The function should return -1 if no valid list was passed to it..
 */
int insert(list *ls, int val)
{
    list* ls2;// Pointer to list of double the length of ls
    int i;
    int swap;// for relocating array elements
    int index = 0;// index where val was inserted
    int indexCounter = 0;// a counter to determine where val is inserted

    // Negative values are invalid; Null pointer to list is invalid. Return -1
    if( val < 0 || ls == NULL ) {
      
        return -1;
    }

    // If adding val to list causes size > maxSize, double size of list
    // and copy values to new list.
    if( (ls -> size)+1 > ls -> maxSize ) {
       
        // If capacity of list is 0, create new list with single element,
        // set list member pointer to new array, add element and return index
        if( (ls -> maxSize) == 0 ) {

            ls2 = createlist(1);
            *(ls2 -> sortedList) = val;// insert val at element 0
            // No need to free blocks, null pointer
            ls -> sortedList = ls2 -> sortedList;
            ls -> size = 1;
            ls -> maxSize = ls2 -> maxSize;
            free(ls2);
            return 0;// index will be at 0 for only 1 element in list
        }    

        // If values already exist in list, double list size, copy elements to
        // new list, and add new value in correct location
        ls2 = createlist( 2*(ls -> maxSize ) );
        ls2 -> size = (ls -> size) + 1;
         
        // Copy old values to new list
        for(i = 0; i < (ls -> maxSize); i++ ) {

	    int* temp = ls->sortedList;
	    temp = temp + i;
            *(( ls2 -> sortedList)+i) = *temp;

        }
    
        // Add new value to proper location
        for(i = 0; i < (ls -> size); i++ ) {
            // Iterate through list and sort
            if( val <= *((ls2 -> sortedList) + i) ) {
   
                 
                // Update index only for first insertion of val, i.e. so
                // index isn't overwritten when array is shifted
                if( indexCounter == 0 ) {
                    index = i;
                    indexCounter++;
                 }
            
                // swap value of ith element with val
                swap = *((ls2 -> sortedList) + i);
                *((ls2 -> sortedList) + i) = val;
                val = swap;
            }
        }

        // val contains the largest value at this point, place at end
        *((ls2 -> sortedList) + (ls -> size)) = val;
        ls -> sortedList = ls2 -> sortedList;
        ls -> size = ls2 -> size;
        ls -> maxSize = ls2 -> maxSize;
        free(ls2);
 
        // return last array index if val wasn't inserted in middle of list
        if( indexCounter == 0 ) {

            return ls -> size-1;
        }
        // return index of val was inserted in middle of list
        else return index;
    }

    // If adding an element doesn't cause size > maxSize, add element to 
    // appropriate location.
    for( i = 0; i < (ls -> size); i++ ) {
  
        // Iterate through list and sort
        if( val <= *(ls -> sortedList + i) ) {
    
            // Update index only for first iteration...
            if( indexCounter == 0 ) {
                index = i;
                indexCounter++; 
            }
    
            // Swap value of ith element with val
            swap = *((ls -> sortedList) + i);
            *((ls -> sortedList) + i) = val;
            val = swap;
        }
    }

    // val contains largest value by this point, insert at end and update
    // size of list.
    *((ls -> sortedList) + (ls -> size++)) = val;
 
    // return last array index if val wasn't inserted in middle of list
    if( indexCounter == 0 ) {

        return ls -> size -1;
    }
    // return index if val was inserted in middle of list
    else return index;
       
}

/**
 * This function takes a pointer to the list and an integer value as input. It
 * should delete all instances of elements in the sortedList with value 'val',
 * update the number of elements remaining in the list and return the number of
 * elements that were deleted. Once again the resulting list should be sorted.
 */
int remove_val(list *ls, int val)
{
    int numDeleted = 0;
    int i, j;

    for( i = 0; i < ls -> size; i++ ) {

        // if element at index i equals val, delete, increment numDeleted,
        // shift array left by 1 element, update size of list, decrement i
        // so loop will check value moved into that location again
        if( *((ls -> sortedList)+i) == val ) {
        
            numDeleted++;
            
            // Iterate through list to shift elements left       
            for( j = i; j < ls -> size; j++ ) {

                *((ls -> sortedList) + j) = *((ls -> sortedList)+j+1);
            }
        ls -> size--;
        i--;
        }
    
    }
    return numDeleted;
}

/**
 * This function takes a pointer to the the list as input and returns the
 * maximum value in the list OR -1 if the list is empty.
 */
int get_max_value(list *ls)
{
    // Return -1 for empty list
    if( (ls -> size) == 0 ) {

        return -1;
    }

    // Return last element
    return *((ls -> sortedList) + (ls -> size-1));
}

/**
 * This function takes a pointer to the list and returns the minimum value in
 * the list OR -1 if the list is empty.
 */
int get_min_value(list *ls){

    // Return -1 for empty list
    if( (ls -> size) == 0 ) {
  
        return -1;
    }

    // Return 0th element
    return *(ls -> sortedList);
}

/**
 * This function returns the index of the first occurrence of 'val' in the
 * list. It returns -1 if the value 'val' is not present in the list.
 */
int search(list *ls, int val){

    int i;

    // return -1 if list is empty
    if( ls -> size == 0 ) {

        return -1;
    }

    for( i = 0; i < ls -> size ; i++ ) {

        // Search list and return index of first instance of val
        if( val == *((ls -> sortedList) + i) ) {

            return i;
        }
    }
    return -1; 
}

/**
 * This function returns the minimum value from the list and removes it from
 * the list. It returns -1 if the list is empty.
 */
int pop_min(list *ls){

    int minValue;

    // return -1 for empty list
    if( ls -> size == 0 ) { 
  
        return -1;
    }

    // set minValue to 0th list element and move pointer to 1st element
    minValue = *(ls -> sortedList);
    ls -> sortedList = ls -> sortedList + 1;
    ls -> size--;
  
    return minValue;
    
}

/**
 * This function print the contents of the sorted list on a single line as
 * follows:
 * 1 4 6 7 8
 */
void print(list *ls){

    int i;
    // Iterate through list and print elements in sequential order.
    for( i = 0; i < ls -> size ; i++ ) {

        printf("%d ", *((ls -> sortedList) + i) );
        
    }
    printf("\n");
}

/**
 * Identical to get_min_value(), but implemented in ARM assembly
 * (use given file get_min_ARM.s)
 */
int get_min_ARM(list *ls);

/**
 * Identical to get_max_value(), but implemented in ARM assembly
 * (use given file get_max_ARM.s)
 */
int get_max_ARM(list *ls);
