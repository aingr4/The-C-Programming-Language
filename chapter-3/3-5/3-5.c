#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itob(int n, char s[], int b);

int main() {
    
    int n;
    char s[100];

    n = 1234;

    itob(n, s, 16);

    printf("Result: %s\n", s);

    return 0;
}

void itob(int n, char s[], int b) {

    int i, sign;
    char comp[] = "0123456789ABCDEF";

    sign = n;
    i = 0;

    if (n < 0) {
        n = -n;
    }

    do {
        s[i++] = comp[n % b];
        n /= b;
    } while (n > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);

}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}