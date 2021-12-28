#include <stdio.h>
#include <stdbool.h>

int htoi(char *s);
int otoi(char *s);

int main() {
    
    char s[] = "0xA123";
    char s2[] = "123";
    int n;

    n = htoi(s);
    printf("Hex: %s, Int: %d\n", s, n);

    n = otoi(s2);
    printf("Oct: %s, Int: %d\n", s2, n);
}

int htoi(char *s) {

    int i, n;

    n = 0;

    while (*s) {
        char c = *s++;
        if (c == 'x' || c == 'X') {
            n = 0;
        } else if ((c >= '0' && c <= '9')) {
            n = n<<4 | ((c - '0') & 0xF);
        } else if ((c >= 'a' && c <= 'f')) {
            n = n<<4 | ((c - 'a') & 0xF);
        } else if ((c >= 'A' && c <= 'F')) {
            n = n<<4 | ((c - 'A') & 0xF);
        }
    }

    return n;
}

int otoi(char *s) {

    int i, n;

    n = 0;

    while (*s) {
        char c = *s++;
        if ((c >= '0' && c <= '8')) {
            n = n<<3 | ((c - '0') & 07);
        }
    }

    return n;
}