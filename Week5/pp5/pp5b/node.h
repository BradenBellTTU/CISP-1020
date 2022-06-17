#ifndef NODE_H
#define NODE_H

typedef struct node_t {
    int i;
    struct node_t* nextPtr;
    struct node_t* prevPtr;
} node_t;

    

node_t* initNode(int);


#endif