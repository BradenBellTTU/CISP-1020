/* File:  mainStack.c
 * Author: Cindy Arnold
 * Description: main function to test stack code
 */
#include <stdio.h>
#include "stack.h"
#include "stackItem.h"

int main() {
   Stack s;
   int option;
   StackItem num;

   // test initStack and push
   initStack( &s );
   printf( "1 push an integer on the stack\n2 pop an integer off the stack\n3 quit\n" );
   scanf( "%d", &option );
   while( option != 3 ) {
      switch( option ) {
         case 1:
            printf( "Enter integer to push: " );
            scanf( "%d", &num );
            push( &s, num );
            break;
         case 2:
            if ( isEmpty( s ) ) {
               printf( "Error. Stack is empty.\n" );
            }
            else {
               pop( &s, &num );
               printf( "%d popped\n", num );
            }
            break;
         case 3: 
            break;
         default:
            printf( "Invalid option: %d\n", option );
      }
      printStack( s );
      printf( "1 push an integer on the stack\n2 pop an integer off the stack\n3 quit\n" );
      scanf( "%d", &option );
   } 

   return 0;
}
