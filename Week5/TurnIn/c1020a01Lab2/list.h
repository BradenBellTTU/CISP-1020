#ifndef LIST_H
#define LIST_H
#include <stdio.h>
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
node_t* findNode(dbl_linked_list_t*, int);
void removeNode(dbl_linked_list_t*, node_t*);
void traverseQueueAndSell(dbl_linked_list_t*, node_t*, int, char*);
void writeListToFile(dbl_linked_list_t*, char*);

#endif