/*  
 * Implementation based on Anshu Avinash's generic stack
 * https://github.com/igniting/generic-stack
*/
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/* Constants */
#define MAX_STACK_SIZE 100

/* Type definitions */
typedef unsigned char byte;

typedef struct Stack {
  int top;
  byte *storage;
  int elemSize;
} Stack;

/* Function declarations */
void initializeStack(Stack *st, int elemSize);
bool isEmpty(const Stack *st);
int size(const Stack *st);
void *pop(Stack *st);
bool isFull(const Stack *st);
void push(Stack *st, const void *elem);
void destroy(Stack *st);
void *peek(Stack *st);

#endif /* STACK_H */