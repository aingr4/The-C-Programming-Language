#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char *s);

int main() {
    
    char *s;

    s = "225.241e+3";

    printf("atof result: %lg\n", atof(s));

    return 0;
}

double atof(char *s) {
    double val, power, epowerval;
    int i, sign, esign;

    while (isspace(*s)) {
        *s++;
    };

    sign = (*s == '-') ? -1: 1;

    if (*s == '+' || *s == '-') {
        *s++;
    }

    val = 0.0;
    while (isdigit(*s)) {
        val = 10.0 * val + (*s - '0');
        *s++;
    }

    if (*s == '.') {
        *s++;
    }

    power = 1.0;
    while (isdigit(*s)) {
        val = 10.0 * val + (*s - '0');
        power *= 10.0;
        *s++;
    }

    if (*s == 'e' || *s == 'E') {
        *s++; 
    }

    esign = (*s == '-') ? -1: 1;

    if (*s == '-' || *s == '+') {
        *s++;
    }

    epowerval = 0.0; // Get the decimal value of the exponent

    while (isdigit(*s)) {
        epowerval = 10.0 * epowerval + (*s - '0');
        *s++;
    }

    return (esign < 0) ? sign * val / (power * pow(10.0, epowerval)) : (sign * val * pow(10.0, epowerval)) / power;
}

