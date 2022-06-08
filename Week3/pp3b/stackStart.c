/* File: stack.c
 * Author: Cindy
 * Description: contains functions for stack manipulations
 */
#include <stdio.h>
#include "stack.h"
#include "stackItem.h"


/* initStack: initializes stack by setting top index to -1
 * Parameter s pointer to the stack
 * Returns nothing
 */
// ADD CODE HERE

/* push: pushes an item on the stack if it isn't full
 * Parameters:
 *    s pointer to the stack
 *    i the item to push
 * Returns true if push successful, false otherwise 
 */
// ADD CODE HERE

/* pop: pops an item off the stack if it isn't empty
 * Parameters 
 *    s pointer to the stack
 *    i the item to be returned, a pointer
 * Postcondition: i will have the item popped if the stack wasn't empty
 * Returns true if an item was popped 
 */
// ADD CODE HERE

/* isEmpty: returns true if stack is empty
 * Parameter s the stack
 * Returns: true if stack is empty
 */
// ADD CODE HERE

/* printStack: prints the stack
 * Parameter s the stack
 * Returns nothing
 */
void printStack( Stack s ) {
   int i;
   printf("STACK\n------\n");
   for( i = s.top; i >= 0; i-- ) {
      printf ("| %4d |\n", s.array[i] );
      printf("------\n");
   }
   if ( s.top <= EMPTY_INDEX) printf("------\n");
}

