#include <stdio.h>
#include "node.h"

node_t* initNode(int data) {
    node_t* nodePtr;
    nodePtr = malloc(sizeof(node_t));
    nodePtr -> i = data;
    nodePtr -> nextPtr = NULL;
    nodePtr -> prevPtr = NULL;
    return nodePtr;
}

