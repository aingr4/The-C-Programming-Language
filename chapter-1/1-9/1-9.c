#include <stdio.h>
#include <stdbool.h>

int main() {

    char c;

    bool foundSpace = false;

    while ((c = getchar()) != EOF) {
        if (foundSpace && !(c == ' ')) {
                foundSpace = false;
                putchar(' ');
                putchar(c);
        } else if (c == ' '){
            foundSpace = true;
        } else {
            putchar(c);
        }
    }

    return 0;
}