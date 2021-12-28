#include <stdio.h>

int main() {

    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 150;
    step = 10;

    celsius = upper;

    printf("Celsius Farenheit\n");

    while (celsius >= lower) {
        fahr = (celsius * (9.0/5.0)) + 32.0;
        printf("%7.0f %9.0f\n", celsius, fahr);
        celsius = celsius - step;
    }

    return 0;
}