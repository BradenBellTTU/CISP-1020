/* File:  mainStack.c
 * Author: Cindy Arnold
 * Description: main function to test stack code
 */
#include <stdio.h>
#include "queue.h"
#include "queueItem.h"

int main() {
   Queue q;
   int option;
   QueueItem num;

   // test initStack and push
   initQueue( &q );
   printQueue( q );
   printf( "1  enqueue an integer on the queue\n2 dequeue an integer off the queue\n3 quit\n" );
   scanf( "%d", &option );
   while( option != 3 ) {
      switch( option ) {
         case 1:
            printf( "Enter integer to enqueue: " );
            scanf( "%d", &num );
            enqueue( &q, num );
            break;
         case 2:
            if ( isEmpty( q ) ) {
               printf( "Error. Queue is empty.\n" );
            }
            else {
               dequeue( &q, &num );
               printf( "%d dequeued\n", num );
            }
            break;
         case 3: 
            break;
         default:
            printf( "Invalid option: %d\n", option );
      }
      printQueue( q );
      printf( "1 enqueue an integer on the queue\n2 dequeue an integer off the queue\n3 quit\n" );
      scanf( "%d", &option );
   } 

   return 0;
}
