/* File:  mainStack.c
 * Author: Cindy Arnold
 * Description: header file for a circular queue
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "queueItem.h"

#define QUEUE_SIZE 10

typedef struct {
    QueueItem array[QUEUE_SIZE];
    int count;
    int front;
    int rear;
} Queue;

void initQueue(Queue*);
int enqueue(Queue*, QueueItem);
int dequeue(Queue*, QueueItem*);
int isEmpty(Queue q);
void printQueue(Queue);

#endif