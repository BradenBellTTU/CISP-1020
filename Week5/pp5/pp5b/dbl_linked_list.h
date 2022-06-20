#ifndef DBL_LINKED_LIST_H
#define DBL_LINKED_LIST_H

#include "node.h"

typedef struct {
    node_t* headPtr;
    node_t* tailPtr;
    int count;
} dbl_linked_list_t;

void createList(dbl_linked_list_t*);
void insertNode(dbl_linked_list_t*, node_t*);
node_t* popNode(dbl_linked_list_t*);
node_t* dequeueNode(dbl_linked_list_t*);
void deleteList(dbl_linked_list_t*);
void traverseStack(const dbl_linked_list_t*);
void traverseQueue(const dbl_linked_list_t*);

#endif