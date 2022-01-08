#include <stdio.h>

int strrindex(char *s, char t);

int main() {

    char *s;
    char t;

    t = 'z';
    s = "Hello World!";

    printf("First occurence of '%c' in '%s' is at position %d\n", t, s, strrindex(s, t));
    
    return 0;
}


int strrindex(char *s, char t) {
    int i;

    i = 0;
    
    while(*s) {
        if (*s == t) {
            break;
        }
        *s++;
        i++;
    }

    return (*s == t) ? i : -1;
}