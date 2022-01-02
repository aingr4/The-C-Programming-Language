#include <stdio.h>
#include <stdbool.h>

void expand(char *s1, char *s2);
bool isLetterOrNum(char c);
bool isSameCase(char c1, char c2);

int main() {
    
    char s1[1000] = "This is a-z 0-9 A-Z -a-z a-Z";
    char s2[1000];

    expand(s1, s2);
    printf("%s\n", s2);
}


/* Supports a-z, A-Z, 0-9 but does not support different case (a-Z or A-z) */
void expand(char *s1, char *s2) {
    char leadingChar;
    bool inRange = false;

    while (*s1 != '\0') {
        if (inRange) {
            if (isLetterOrNum(*s1) && isSameCase(*s1, leadingChar)) {
                leadingChar++;

                while (leadingChar <= *s1) {
                    printf("Leading char: %c\n", leadingChar);
                    *s2++ = leadingChar++;
                }

                inRange = false;
            } else {
                *s2++ = '-';
                *s2++ = *s1;
                leadingChar = *s1;
                inRange = false;
            }

            s1++;

        } else if (*s1 == '-' && isLetterOrNum(leadingChar)) {
            inRange = true;
            s1++;

        } else {
            leadingChar = *s1;
            *s2++ = *s1++;
        }
    }

    // Terminate the string with the null character
    *s2 = '\0';
}

bool isLetterOrNum(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

bool isSameCase(char c1, char c2) {
    return ((c1 >= 'a' && c1 <= 'z' && c2 >= 'a' && c2 <= 'z') || (c1 >= 'A' && c1 <= 'Z' && c2 >= 'A' && c2 <= 'Z'));
}