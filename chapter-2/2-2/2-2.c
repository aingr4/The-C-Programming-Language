#include <stdio.h>

int main() {
    
    int i;
    char c;

    int lim = 5;

    char s[lim];

    for (i=0; i<lim; ++i) {
        if ((c=getchar()) != '\n' && c !=EOF) {
            s[i] = c;
        }
    }

    printf("%s\n", s);
}