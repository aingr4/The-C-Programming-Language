#include <stdio.h>
#include <stdbool.h>

void escape(char *s, char *t);
void unescape(char *s, char *t);

int main() {
    
    
    char s[100] = "This is \n a test \t \t \n";
    char u[100] = "This is \\n a test \\t \\t \\n";
    char t[100];
    char v[100];

    escape(s, t);
    printf("%s\n", t);

    unescape(u, v);
    printf("%s\n", v);
}

/* Only supports escape characters \\, \t, \n */
void escape(char *s, char *t) {

    while (*s != '\0') {
        switch (*s) {
            case '\t':
                *t++ = '\\';
                *t++ = 't';
                s++;
                break;
            case '\n':
                *t++ = '\\';
                *t++ = 'n';
                s++;
                break;
            case '\\':
                *t++ = '\\';
                *t++ = '\\';
                s++;
                break;
            default: 
                *t++ = *s++;
                break;
        }
    }

    // Terminate the string with the null character
    *t = '\0';
}

/* Only suppots escape characters \\, \t, \n */
void unescape(char *s, char *t) {

    bool inEscape = false;

    while (*s != '\0') {

        if (inEscape) {
            switch (*s) {
                case 't':
                    *t++ = '\t';
                    break;
                case 'n':
                    *t++ = '\n';
                    break;
                case '\\':
                    *t++ = '\\';
                    break;
                default:
                    // Illegal, backslash should be followed by one of the supported characters
                    break;
                    
            }

            inEscape = false;
            s++;

        } else if (*s == '\\') {
            inEscape = true;
            s++;

        } else {
            *t++ = *s++;
        }
    }

    // Terminate the string with the null character
    *t = '\0';
}