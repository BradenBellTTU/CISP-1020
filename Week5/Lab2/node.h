#ifndef NODE_H
#define NODE_H

#include "stock.h"

typedef struct node_t {
    stock_t i;
    struct node_t* nextPtr;
    struct node_t* prevPtr;
} node_t;

    

node_t* initNode(stock_t);


#endif
