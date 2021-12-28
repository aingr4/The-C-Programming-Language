#include <stdio.h>
#include <string.h>

int main() {

    char s[2] = "";

    strcpy(s, "\\");
    s[1] = EOF;

    printf("%s\n", s);

    return 0;
}