/*
* Basic implementation of a stack. Some bugs occur when trying to include pop() in a function call
*
* ex. fmod(pop(st) + pop(st))
*
* I will explore this issue at a later date
*/
#ifndef DOUBLESTACK_H
#define DOUBLESTACK_H

#define MAXVAL 100

#define isEmpty(st) (st->top < 0) // Check if stack is empty
#define isFull(st) (st->top >= MAXVAL) // Check if stack is full
#define push(st, n) (isFull(st) && printf("Stack is full, error!\n")) || (!isFull(st)) && (st->items[st->top++] = n) // Push value onto the stack if array is not full
#define pop(st) (isEmpty(st) && printf("Stack is empty, error!\n")) ? 0.0 : (st->items[--st->top])  // Return top element of the stack, return 0.0 if stack is empty
#define initializeStack(st) (st->top = -1) // Initialize an empty stack
#define peek(st) (!isEmpty(st) && printf("%lf\n", st->items[st->top-1])) || (isEmpty(st) && printf("Stack is empty\n"))

struct doubleStack {
    double items[MAXVAL];
    int top;
};
typedef struct doubleStack doubleStack;

#endif /* DOUBLESTACK_H */