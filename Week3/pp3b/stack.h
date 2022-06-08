/* File: stack.h
 * Author: Cindy Arnold
 * Description: header file for a stack
 */
#ifndef STACK_H
#define STACK_H

#include "stackItem.h"

#define MAX_STACK_SIZE 10
#define EMPTY_INDEX -1

typedef struct {
           StackItem array[MAX_STACK_SIZE];
              int top; // index of top item on stack
} Stack;


void initStack( Stack* );
int push( Stack*, StackItem );
int pop( Stack*, StackItem* );
int isEmpty( Stack );
void printStack( Stack );

#endif
