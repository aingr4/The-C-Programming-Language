#include <stdio.h>
#include <stdlib.h>
#include "../../extras/charstack.h"


int main() {

    charStack *s = (charStack*)malloc(sizeof(charStack));
    initializeStack(s);

    char a,b,c,d,e,z;

    a = 'a';
    b = 'b';
    c = 'c';
    d = 'd';
    e = 'e';

    push(s, a);
    push(s, b);
    push(s, c);
    push(s, c);
    push(s, c);
    push(s, c);
    push(s, c);

    while (z = pop(s)) {
        printf("%c\n", z);
    }

    return 0;
}