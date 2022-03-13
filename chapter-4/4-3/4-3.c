#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include "../../extras/stack/stack.h"

double polishCalc(char *c);

int main() {

    char * s;
    s = "10 6 % 5.5 2 * *";

    printf("Expected: 16, Actual: %f\n", polishCalc(s));

    return 0;
}

/* Calculator that can process polish notation equations */
double polishCalc(char *c) {

    Stack *st;
    initializeStack(st, sizeof(double));

    bool isLastCharOp, inDecimal;
    double val, power;
    val = 0.0;
    power = 1.0;

    while (*c) {
        if (isdigit(*c)) {
            val = val*10.0 + *c - '0';
            isLastCharOp = false;

            if (inDecimal) {
                power *= 10.0;
            }

        } else if (*c == '.'){
            inDecimal = true;

        } else if (isspace(*c) && !isLastCharOp) {
            val = val/power;
            push(st, (void*)&val);
            val = 0.0;
            power = 1.0;
            inDecimal = false;
        } else if (*c == '+'){
            double sum = *(double *)pop(st) + *(double *)pop(st); 
            push(st, (void *)&sum);
            isLastCharOp = true;
        } else if (*c == '-'){
            double op1 = *(double*)pop(st); 
            double sum = *(double*)pop(st) - op1;
            push(st, (void *)&sum);
            isLastCharOp = true;
        } else if (*c == '/'){
            double op1 = *(double*)pop(st);
            double op2 = *(double*)pop(st);
            if (op1 != 0.0) {
                double sum = op2 / op1;
                push(st, (void *)&sum);
            } else {
                printf("Error");
            }
            isLastCharOp = true;

        } else if (*c == '*'){
            double sum = *(double *)pop(st) * *(double *)pop(st);
            push(st, (void *)&sum);
            isLastCharOp = true;
        } else if (*c == '%') {
            double op1 = *(double*)pop(st);
            double op2 = *(double*)pop(st);
            double sum = fmod(op2, op1);

            push(st, (void *)&sum); // Using fmod since the modulo operator (%) only works on integers
            isLastCharOp = true;
        }
        *c++;
    }

    if (!isEmpty(st)) {
        return pop(st);
    } else {
        printf("Error");
        return 0.0;
    }
}