#include <stdio.h>
#include <stdlib.h>
#include "dbl_linked_list.h"


void createList(dbl_linked_list_t* listPtr) {
    if (listPtr != NULL) {
        listPtr -> count = 0;
        listPtr -> headPtr = NULL;
        listPtr -> tailPtr = NULL;
    }
}

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

void traverseStack(const dbl_linked_list_t* listPtr) {
    if (listPtr != NULL) { //If list has been initialized
        node_t* curPtr = listPtr -> headPtr; //curPtr = list's headPtr
        while(curPtr != NULL) { //While curPtr isn't NULL
            printf("%d ", curPtr -> i); //Print curPtr's data
            curPtr = curPtr -> nextPtr; //Update curPtr to point to the next node
        }
    }
}

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

void traverseQueue(const dbl_linked_list_t* listPtr) {
    if (listPtr != NULL) { //If list has been initialized
        node_t* curPtr = listPtr -> tailPtr; //curPtr = list's tailPtr
        while(curPtr != NULL) { //While curPtr isn't NULL
            printf("%d ", curPtr -> i); //Print curPtr's data
            curPtr = curPtr -> prevPtr; //Update curPtr to point to the next node
        }
    }

    else
        printf("Error: traverseQueue function was passed a NULL value"); //error message for debugging
}

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