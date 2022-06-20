#include <stdio.h>
#include "dbl_linked_list.h"


void createList(dbl_linked_list_t* listPtr) {
    listPtr -> count = 0;
    listPtr -> headPtr = NULL;
    listPtr -> tailPtr = NULL;
}

void insertNode(dbl_linked_list_t* listPtr, node_t* nPtr) {
    if(listPtr -> headPtr == NULL ) { //If listPtr's list is empty
        listPtr -> headPtr = nPtr;
        listPtr -> tailPtr = nPtr;
    }

    else {
        nPtr -> nextPtr = listPtr -> headPtr;
        //Start here, follow algo in lecture notes
    }
    

}