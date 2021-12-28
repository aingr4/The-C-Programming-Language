#include <stdio.h>

int main() {
    printf("Size of char: %ld bits\n", sizeof(char)*8);
    printf("Size of short: %ld bits\n", sizeof(short)*8);
    printf("Size of int: %ld bits\n", sizeof(int)*8);
    printf("Size of long: %ld bits\n", sizeof(long)*8);

    printf("\n\n\n");

    printf("Size of signed char: %ld bits\n", sizeof(signed char)*8);
    printf("Size of signed short: %ld bits\n", sizeof(signed short)*8);
    printf("Size of signed int: %ld bits\n", sizeof(signed int)*8);
    printf("Size of signed long: %ld bits\n", sizeof(signed long)*8);

    printf("\n\n\n");

    printf("Size of signed double: %ld bits\n", sizeof(double)*8);
    printf("Size of signed float: %ld bits\n", sizeof(float)*8);
    printf("Size of signed long double: %ld bits\n", sizeof(long double)*8);
}