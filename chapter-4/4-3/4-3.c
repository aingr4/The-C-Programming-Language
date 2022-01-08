#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include "../../extras/doublestack.h"

double polishCalc(char *c);

int main() {

    char * s;
    s = "10 6 % 5.5 2 * *";

    printf("%f\n", polishCalc(s));

    return 0;
}

/* Calculator that can process polish notation equations */
double polishCalc(char *c) {

    doubleStack *st = (doubleStack*)malloc(sizeof(doubleStack));
    initializeStack(st);

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
            printf("%f\n", val);
            push(st, val);
            val = 0.0;
            power = 1.0;
            inDecimal = false;

        } else if (*c == '+'){
            // Was having weird interactions with my implementation of stack when popping..
            // will have to investigate later
            double op1 = pop(st); 
            double op2 = pop(st);
            push(st, op1 + op2);
            isLastCharOp = true;

        } else if (*c == '-'){
            double temp = pop(st); 
            push(st, pop(st) - temp);
            isLastCharOp = true;

        } else if (*c == '/'){
            double op1 = pop(st);
            double op2 = pop(st);
            if (op1 != 0.0) {
                push(st, op2 / op1);
            } else {
                printf("Error");
            }
            isLastCharOp = true;

        } else if (*c == '*'){
            double op1 = pop(st);
            double op2 = pop(st);
            push(st, op1 * op2);
            isLastCharOp = true;
        } else if (*c == '%') {
            double op1 = pop(st);
            double op2 = pop(st);

            push(st, fmod(op2, op1)); // Using fmod since the modulo operator (%) only works on integers
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