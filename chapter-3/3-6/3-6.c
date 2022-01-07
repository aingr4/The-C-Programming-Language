#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

void reverse(char s[]);
void itoa(int n, char s[], int p);

int main() {
    
    int n;
    char s[MAX_BUFFER_SIZE];

    n = -1234;

    itoa(n, s, 20);

    printf("Result: %s\n", s);

    return 0;
}


void itoa(int n, char s[], int p) {
    int i, len, sign;

    sign = n;
    i = 0;

    if (n < 0) {
        n = -n;
    }

    do {
        s[i++] = n % 10 + '0';
        n /= 10;
    } while (n > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0'; // Allows the use of strlen
    len = strlen(s);

    while (len < p) {
        s[i++] = ' ';
        p--;
    }

    s[i] = '\0'; // In case the previous null character was overwritten

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