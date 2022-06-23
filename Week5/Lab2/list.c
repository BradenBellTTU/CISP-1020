#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stock.h"

/* createList: initializes the doubly linked list
 * Parameters:
 *    listPtr - pointer to the list
 * Returns: nothing 
 */
void createList(dbl_linked_list_t* listPtr) {
    if (listPtr != NULL) {
        listPtr -> count = 0;
        listPtr -> headPtr = NULL;
        listPtr -> tailPtr = NULL;
    }
}


/* insertNode: Inserts a new node in the first slot of the doubly linked list
 * Parameters:
 *    listPtr - pointer to the list
 *    nPtr - points to the node
 * Returns: nothing 
 */
void insertNode(dbl_linked_list_t* listPtr, node_t* nPtr) {
    if (listPtr != NULL) {//Make sure the list has been created by createList
        listPtr -> count++;
        if(listPtr -> headPtr == NULL ) { //If listPtr's list is empty
            //printf("headPtr was NULL\n");
            listPtr -> headPtr = nPtr;
            listPtr -> tailPtr = nPtr;
        }

        else { //If listPtr's list is not empty
            //printf("headPtr was not NULL\n");
            nPtr -> nextPtr = listPtr -> headPtr;
            listPtr -> headPtr -> prevPtr = nPtr;
            listPtr -> headPtr = nPtr;
        }
    }
}


/* popNode: pops the first node out of the doubly linked list
 * Parameters:
 *    listPtr - pointer to the list
 * Returns: a pointer to the node that was popped
 */
node_t* popNode(dbl_linked_list_t* listPtr) {
    if(listPtr != NULL && listPtr -> headPtr != NULL) { //If the list is not empty and it was initialized
        listPtr -> count--; //A. Decriment count
        node_t* nodePtr = listPtr -> headPtr; //B. nodePtr = the node at the end of the list
        
        
        listPtr -> headPtr = listPtr -> headPtr -> nextPtr; //C. Set headPtr to point to next in the list
        
        
        if (listPtr -> headPtr != NULL) { //If the list is still not empty
            listPtr -> headPtr -> prevPtr = NULL; //Set headPtr's previous pouinter to NULL
        }

        else { //If the list is empty:
            listPtr -> tailPtr = NULL; //set tailPtr to NULL
        }

        nodePtr -> prevPtr = NULL; //Set nodeptr's prev and next ptrs to NULL since the node's not in the list anymore
        nodePtr -> nextPtr = NULL;

        return nodePtr; //Return nodePtr
    }

    else
        return NULL; //Return NULL
}


/* createList: Prints the data in the doublely linked list as if it were a list
 * Parameters:
 *    listPtr - pointer to the list
 * Returns: nothing 
 */
void traverseStack(const dbl_linked_list_t* listPtr) {
    if (listPtr != NULL) { //If list has been initialized
        node_t* curPtr = listPtr -> headPtr; //curPtr = list's headPtr
        while(curPtr != NULL) { //While curPtr isn't NULL
            printStock (curPtr -> i); //Print curPtr's data
            curPtr = curPtr -> nextPtr; //Update curPtr to point to the next node
        }
    }
}


/* dequeueNode: initializes the list
 * Parameters:
 *    listPtr - pointer to the list
 * Returns: a pointer to the item dequeued
 */
node_t* dequeueNode(dbl_linked_list_t* listPtr) {
    if(listPtr != NULL && listPtr -> headPtr != NULL) { //If the list is not empty and it was initialized
        listPtr -> count--; //A. Decriment count
        node_t* nodePtr = listPtr -> tailPtr; //B. nodePtr = the node at the end of the list
        
        
        listPtr -> tailPtr = listPtr -> tailPtr -> prevPtr; //C. Set headPtr to point to next in the list
        
        
        if (listPtr -> tailPtr != NULL) { //If the list is still not empty
            listPtr -> tailPtr -> nextPtr = NULL; //Set headPtr's previous pouinter to NULL
        }

        else { //If the list is empty:
            listPtr -> headPtr = NULL; //set tailPtr to NULL
        }

        nodePtr -> prevPtr = NULL; //Set nodeptr's prev and next ptrs to NULL since the node's not in the list anymore
        nodePtr -> nextPtr = NULL;

        return nodePtr; //Return nodePtr
    }

    else
        return NULL; //Return NULL
}


/* traverseQueue: prints items in the dynamically linked list as if it were a queue
 * Parameters:
 *    listPtr - pointer to the list
 * Returns: nothing 
 */
void traverseQueue(const dbl_linked_list_t* listPtr) {
    if (listPtr != NULL) { //If list has been initialized
        node_t* curPtr = listPtr -> tailPtr; //curPtr = list's tailPtr
        while(curPtr != NULL) { //While curPtr isn't NULL
            printStock(curPtr -> i);
            //printf("%d ", curPtr -> i); //Print curPtr's data
            curPtr = curPtr -> prevPtr; //Update curPtr to point to the next node
        }
    }
}


/* deleteList: Deletes the doubly linked list
 * Parameters:
 *    listPtr - pointer to the list
 * Returns: nothing 
 */
void deleteList(dbl_linked_list_t* listPtr) {
    if (listPtr != NULL && listPtr -> headPtr != NULL) { //If the list exists and is not empty
        node_t* curPtr = listPtr -> headPtr; //curPtr = the list's headPtr
        
        while(curPtr != NULL) { //While curPtr isn't null:
            listPtr -> headPtr = curPtr -> nextPtr; //headPtr = curPtr's nextPtr
            free(curPtr); //Deallocate curPtr's memory
            curPtr = listPtr -> headPtr; //Update curPtr
        }

        listPtr -> tailPtr = NULL; //Set list's tail pointer to NULL
        listPtr -> count = 0; //Set list's count to 0

    }
}


/* findNode: Searches the list for nodes with a specified key 
 * Parameters:
 *    listPtr - pointer to the list
 *    key - integer to find
 * Returns: a pointer to the node with the key stored in it or NULL if none are found
 */
node_t* findNode(dbl_linked_list_t* listPtr, int key) {
    node_t* curPtr;
    for (curPtr = listPtr -> headPtr; curPtr != NULL; curPtr = curPtr -> nextPtr) {
        if ((curPtr -> i.numShares) == key) {
            return curPtr;
        }
    }
    return NULL;
}


/* removeNode: Removes a node from the list
 * Parameters:
 *    listPtr - pointer to the list
 *    nodePtr - a pointer to the node to be deleted
 * Returns: nothing 
 */
void removeNode(dbl_linked_list_t* listPtr, node_t* nodePtr) {
    //HEAD CASE
    if (nodePtr == listPtr -> headPtr) { //If nodePtr poins to the head of the list
        listPtr -> headPtr = nodePtr -> nextPtr; 
        if(listPtr -> headPtr != NULL) {//Didn't remove last node in the list
            listPtr -> headPtr -> prevPtr = NULL; //Since the head of the node doesn't haev a node before it
        }

        else { //headPtr is NULL so remove the last node in the list which is now empty
            listPtr -> tailPtr = NULL;
        }
    } 

    else if (nodePtr == listPtr -> tailPtr) {
        listPtr -> tailPtr = nodePtr -> prevPtr;
        listPtr -> tailPtr -> nextPtr = NULL;
    }

    else {
        nodePtr -> prevPtr = nodePtr -> nextPtr;
        nodePtr -> nextPtr = nodePtr -> prevPtr;
    }

    listPtr -> count--;
    free(nodePtr);
}