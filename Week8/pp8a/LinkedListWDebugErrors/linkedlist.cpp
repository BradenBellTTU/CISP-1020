/* File: linkedList.cpp
 * Author: Cindy
 * Description: implements a linked list
 */
#include <cstdlib>
#include "book.h"
#include "node.h"
#include "linkedlist.h"



LinkedList::LinkedList() {
	headPtr = NULL;
	tailPtr = NULL;
	count = 0;
}

//Write a deep copy constructor
LinkedList::LinkedList(LinkedList const& l) {
	// thisPtr goes through this' list, curPtr goes thru l's
   Node* thisPtr = NULL, *curPtr = l.headPtr; 
   headPtr = NULL;
   if ( l.headPtr != NULL ) { //  if there's list to copy
      curPtr = l.headPtr;
      headPtr = new Node( *(l.headPtr) );
      thisPtr = headPtr;
      curPtr = curPtr->nextPtr;
      while ( curPtr != NULL ) {
         thisPtr->nextPtr = new Node( *curPtr );
         thisPtr->nextPtr->prevPtr = thisPtr;
         thisPtr = thisPtr->nextPtr;
         curPtr = curPtr->nextPtr;
      }
   }
   tailPtr = thisPtr;
   count = l.count;

   //return *this;
}



/* insertNode inserts a node at the beginning of the list
 * Parameter a pointer to the node to insert
 * Precondition: parameter nodePtr has been allocated
 * Returns: nothing
 */
void LinkedList::insertNode( Node* nodePtr ) {
   if (headPtr != NULL) {
	   nodePtr->nextPtr = headPtr;
	   headPtr->prevPtr = nodePtr;
	   headPtr = nodePtr;
	}
	
	else {
		headPtr = tailPtr = nodePtr;
	}
   count++;
}

/* traverseStack traverses entire list from head to tail and prints every node's book
 */
void LinkedList::traverseStack() const {
   Node* curPtr = headPtr;
   while (curPtr != NULL ) {
      cout << curPtr->book << endl;
      curPtr = curPtr->nextPtr;
   }
}

/* traverseQueue traverses entire list from tail to head and prints every node's book
 */
void LinkedList::traverseQueue() const {
   Node* curPtr = tailPtr;
   while (curPtr != NULL ) {
      cout << curPtr->book << endl;
      curPtr = curPtr->prevPtr;
   }
}

/* finds a node in the list that has data in it and return
 *    pointer or NULL if not found
 * Parameters:
 *    b  book to be found
 * Returns: pointer to node where book is found or NULL
 */
Node* LinkedList::findNode( const Book& b ) const {
   Node* curPtr = headPtr;

   while( curPtr != NULL ) {
      if ( curPtr->book == b )// USES OVERLOADED == BOOK OPERATOR!
         return curPtr;
      curPtr = curPtr->nextPtr;
   }
   return NULL;
}

/* deleteNode deletes node from list pointed to by parameter and deallocates it
 * Parameter pointer to node to delete
 * Precondition nodePtr points to a node in the list
 * Postcondition list altered by node removal
 */
void LinkedList::deleteNode( Node* nodePtr ) {

   if ( headPtr != NULL ) { // do nothing if list empty
      // node at beginning of list?
      if ( headPtr == nodePtr ) {
         headPtr = headPtr->prevPtr;
         headPtr->prevPtr =  NULL;
         delete nodePtr;
         count--;
         if ( count == 0 ) tailPtr = NULL; // removed last node?
      }
      // node at end of list and list has more than one node
      else if ( tailPtr  == nodePtr ) {
         tailPtr = tailPtr->prevPtr;
         tailPtr->nextPtr =  NULL;
         delete nodePtr;
         count--;
      }
      else { // node in middle of list
        nodePtr->prevPtr->nextPtr = nodePtr->nextPtr;
        nodePtr->nextPtr->prevPtr = nodePtr->prevPtr;
        count--;
        delete nodePtr;
      }
   }
}

/* popNode deletes node at front of list
 * Postcondition list altered by node removal
 */
Node* LinkedList::popNode() {
   Node* oldPtr = headPtr;
   if ( oldPtr != NULL ) {
      headPtr = headPtr->nextPtr;
      if ( headPtr != NULL ) headPtr->prevPtr = NULL;
      count--;
      return oldPtr;
   } 
   return NULL;
}

/* dequeueNode deletes node at tail of list
 * Postcondition list altered by node removal
 */
Node* LinkedList::dequeueNode() {
   Node* oldPtr = tailPtr;
   if ( tailPtr != NULL ) {//If the list is not empty
      tailPtr = tailPtr->prevPtr;
      if ( tailPtr != NULL ) tailPtr->nextPtr = NULL;
      else headPtr = NULL;
	  count--;
      return oldPtr;
   } 
   
   return NULL;
}

/* deleteList deletes entire list deallocating all
 *    nodes' memory
 * Postcondition list has no nodes, head/tail pointers are NULL
 */
void LinkedList::deleteList() {
   Node* nodePtr = headPtr;
   while( nodePtr != NULL ) {
      headPtr = headPtr->nextPtr;
      delete nodePtr;
      nodePtr = headPtr;
   }
   tailPtr = NULL;
   count = 0;
}

/* operator= does a deep copy
 * Parameter
 *  l list to copy
 * Returns reference to new list
 * Postcondition invoking list has all nodes deallocated then new nodes
 *    allocated to copy from parameter list l
 */
LinkedList& LinkedList::operator=( const LinkedList& l ) {
   // thisPtr goes through this' list, curPtr goes thru l's
   Node* thisPtr = NULL, *curPtr = l.headPtr; 
   headPtr = NULL;
   // first, delete original list so no memory  leak
   deleteList();
   if ( l.headPtr != NULL ) { //  if there's list to copy
      curPtr = l.headPtr;
      headPtr = new Node( *(l.headPtr) );
      thisPtr = headPtr;
      curPtr = curPtr->nextPtr;
      while ( curPtr != NULL ) {
         thisPtr->nextPtr = new Node( *curPtr );
         thisPtr->nextPtr->prevPtr = thisPtr;
         thisPtr = thisPtr->nextPtr;
         curPtr = curPtr->nextPtr;
      }
   }
   tailPtr = thisPtr;
   count = l.count;

   return *this;
}

