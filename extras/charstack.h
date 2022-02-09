#ifndef CHARSTACK_H
#define CHARSTACK_H

#define MAXVAL 100

#define isEmpty(st) (st->top < 0) // Check if stack is empty
#define isFull(st) (st->top == MAXVAL) // Check if stack is full
#define push(st, n) (!isFull(st)) && (st->items[st->top++] = n) // Push value onto the stack if array is not full
#define pop(st) (!isEmpty(st)) ? (st->items[--st->top]) : '\0' // Return top element of the stack, return null if stack is empty
#define initializeStack(st) (st->top = -1) // Initialize an empty stack

struct charStack {
    char items[MAXVAL];
    int top;
};
typedef struct charStack charStack;

#endif /* CHARSTACK_H */