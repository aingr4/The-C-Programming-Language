#include <stdio.h>

int main() {

    int c;

    while ((c = getchar()) != EOF) {
        printf("%d", c != EOF);
        putchar(c);
    }

    return 0;
}