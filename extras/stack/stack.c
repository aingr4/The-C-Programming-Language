#include "stack.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
* Name: initializeStack
*
* Description: Allocates memory for the stack initializes
*              member variables
*
*/
Stack* initializeStack(int elemSize) {
    byte *storage;
    Stack *stack;

    stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "Insufficient memory to initialize stack.\n");
        goto exit;
    }

    storage = (byte *)malloc(elemSize * MAX_STACK_SIZE);
    if (storage == NULL) {
        fprintf(stderr, "Insufficient memory to initialize stack storage.\n");
        free(stack);
        stack = NULL;
        goto exit;
    }

    /* Initialize empty stack*/
    stack->storage = storage;
    stack->top = 0;
    stack->elemSize = elemSize;

exit:
    return stack;
}

bool isEmpty(const Stack *st) {
    return (st->top == 0);
}

int size(const Stack *st) {
    return st->top;
}

void *pop(Stack *st) {
    byte *elem;

    if (isEmpty(st)) {
        printf("Stack is empty!");
    } else {
        int start, i;

        start = (--st->top) * st->elemSize;
        elem = (byte *)malloc(st->elemSize);
        
        /* Copy from the top of the stack to elem */
        memcpy(elem, st->storage + start, st->elemSize);
    }

    return (void *)elem;
}

bool isFull(const Stack *st) {
    return st->top >= MAX_STACK_SIZE;
}

void push(Stack *st, const void *elem) {
    if (isFull(st)) {
        fprintf(stderr, "Stack is full.\n");
        exit(1); // Don't like this either
    } else {
        int start, i;
        start = st->top++ * st->elemSize;

        /* Copy elem to the top of the stack*/
        memcpy(st->storage + start, elem, st->elemSize);
    }
}

void emptyStack(Stack *st) {
    if (!isEmpty(st)) {
        st->top = 0;
    }
}

void *peek(Stack *st) {
    void *elem;
    push(st, elem = pop(st));

    return elem;
}

void destroy(Stack *st) {
    free(st->storage);
    free(st);
}