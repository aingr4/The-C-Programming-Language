#include <stdio.h>
#include <stdlib.h>
#include "../../extras/stack/stack.h"

int main() {
    
    Stack *stack;

    // Declaring stack of type int
    initializeStack(stack, sizeof(int));

    int a, b, c, d;
    a = 1;
    b = 2;
    c = 3;
    d = 4;

    push(stack, (void *)&a);
    push(stack, (void *)&b);
    push(stack, (void *)&c);
    push(stack, (void *)&d);
    push(stack, (void *)&a);

    printf("Peeking: %d\n", *(int *)peek(stack));

    while (!isEmpty(stack)) {
        printf("Emptying stack: %d\n", *(int *)pop(stack));
    }

    destroy(stack);

    return 0;
}