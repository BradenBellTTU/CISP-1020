/* File: mainDblListStart.c
 * Author: Cindy Arnold
 * Description: main function to test the list
 */
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "dbl_linked_list.h"

int main() {
   dbl_linked_list_t list;
   node_t* nPtr;
   int i, num;
   
   // init list to be a valid empty list
   createList( &list );
   
   // test initNode, insertNode, traverseStack
   for( i = 0; i < 4; i++ ) {
     printf( "Enter an int: " );
	  scanf( "%d", &num );
	  // get a node and put the int in it
	  nPtr = initNode( num ); 
	  // put the node in the list
	  insertNode( &list, nPtr );
	  printf( "List as stack: " );
	  traverseStack( &list );
     printf("\n");
   }
   
   // test pop and traverseStack
   for( i = 0; i < 4; i++ ) {
      nPtr = popNode( &list );
	  printf( "%d popped\n" , nPtr->i );
	  // DON'T FORGET TO FREE WHEN DONE WITH A NODE! OTHERWISE A MEMORY LEAK
	  free( nPtr ); 
	  printf( "List after pop: ");
	  traverseStack( &list );
     printf("\n");
   }
   
   // test initNode, insertNode, traverseQueue
   for( i = 0; i < 4; i++ ) {
      printf( "Enter an int: " );
	  scanf( "%d", &num );
	  // get a node and put the int in it
	  nPtr = initNode( num ); 
	  // put the node in the list
	  insertNode( &list, nPtr );
	  printf( "List as queue: " );
	  traverseQueue( &list );
     printf("\n");
   }
   
   // test dequeue and traverseQueue
   for( i = 0; i < 4; i++ ) {
      nPtr = dequeueNode( &list );
	  printf( "%d dequeued\n", nPtr->i );
	  // DON'T FORGET TO FREE WHEN DONE WITH A NODE! OTHERWISE A MEMORY LEAK
	  free( nPtr );
      printf( "List after dequeue: " );	  
	  traverseQueue( &list );
     printf("\n");
   }
   
   // put some numbers in list then test deleteList 
   for( i = 0; i < 4; i++ ) {
      printf( "Enter an int: " );
	  scanf( "%d", &num );
	  // get a node and put the int in it
	  nPtr = initNode( num ); 
	  // put the node in the list
	  insertNode( &list, nPtr );
   }
   // print lis as stack
   printf("List as stack: " );
   traverseStack( &list );
   printf("\n");
   deleteList( &list );
   printf( "After list deleted, list as stack: " );
   traverseStack( &list );
   printf("\n");
   
   
   return 0;
  
}
