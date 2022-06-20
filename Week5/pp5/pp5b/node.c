#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* initNode: initializes a node set up for a doubly linked list
 * Parameters:
 *    i = the data to be stored in the node
 * Returns: a pointer to the node
 */
node_t* initNode(int data) {
    node_t* nodePtr;
    nodePtr = malloc(sizeof(node_t));
    nodePtr -> i = data;
    nodePtr -> nextPtr = NULL;
    nodePtr -> prevPtr = NULL;
    return nodePtr;
}

