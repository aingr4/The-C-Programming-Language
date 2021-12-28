#include <stdio.h>

int main() {

    char c;

    int blanks, newLines, tabs;

    blanks = newLines = tabs = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blanks++;
        } else if (c == '\n') {
            newLines++;
        } else if (c == '\t') {
            tabs++;
        }
    }

    printf("Blanks: %d, New Lines: %d, Tabs: %d\n", blanks, newLines, tabs);


    return 0;
}