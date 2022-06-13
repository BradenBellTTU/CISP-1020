/* File: queue.c
 * Author: Braden Bell
 * Description: contains functions for queue manipulations
 */
#include <stdio.h>
#include "queue.h"
#include "queueItem.h"


/* initQueue: initializes the queue
 * Parameters:
 *    q - pointer to the queue
 * Returns: nothing 
 */
void initQueue(Queue* q) {
    q -> count = 0;
    q -> front = 0;
    q -> rear = QUEUE_SIZE - 1;
}


/* enqueue: enqueues an item in the queue if the queue is not full
 * Parameters:
 *    q - pointer to the stack
 *    item - the item to push
 * Returns true if enqueue successful, false otherwise 
 */
int enqueue(Queue* q, QueueItem item) {
    if (q -> count < QUEUE_SIZE) {
        q -> count++;
       //printf("Count: %d, Rear: %d\n", q -> count, q -> rear);
        q -> rear = (q -> rear + 1) % QUEUE_SIZE;
        //printf("Rear: %d\n", q -> rear);
        q -> array[ q -> rear] = item;
        return 1;
    }
    return 0;
}


/* dequeue: dequeues an item in the queue if the queue is not empty
 * Parameters:
 *    q - pointer to the queue
 *    item - the item to be returned, a pointer
 * Returns: true if dequeue was successful, false otherwise 
 */
int dequeue(Queue* q, QueueItem* item) {
    if (q -> count > 0) {
        q -> count--;
        *item = q -> array[q -> front];
        q -> front = (q -> front + 1) % QUEUE_SIZE;
        return 1;
    }
    else
        return 0;
}


/* isEmpty: Returns true if queue is empty
 * Parameters:
 *    q - the stack
 * Returns: true if stack is empty, false otherwise 
 */
int isEmpty(Queue q) {
    if (q.count == 0)
        return 1;
    
    else
        return 0;
}


/* printStack: Prints all content in the queue
 * Parameter q, the stack
 * Returns nothing
 */
void printQueue(Queue q) {
    int i;
    printf("QUEUE\n");
    //printf("Count: %d, Rear: %d, Front: %d\n", q.count, q.rear, q.front);
    if (q.count > 0) {
        for (i = q.front; i != q.rear; i = (i + 1) % QUEUE_SIZE) {
            printf("| %4d |\n", q.array[i]);
        }
    }
    if (q.count > 0) {
        printf("| %4d |\n", q.array[q.rear]);
    }

    else 
        printf("| |\n");
}


