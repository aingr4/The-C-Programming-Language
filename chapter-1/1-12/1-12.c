#include <stdio.h>
#include <stdbool.h>

int main() {

    char c;

    bool inWord = false;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            inWord = false;
            putchar('\n');
        } else {
            inWord = true;
        }

        if (inWord) {
            putchar(c);
        }

    }

    return 0;
}