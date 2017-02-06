#include <stdio.h>
#include "functions.h"

void pop(int* stack, int* top) {
    int t = *top;

    printf("%d", stack[t]);
    t--;
    *top = t;

    return;
}

void popl(int* stack, int* top) {
    int t = *top;

    printf("%d\n", stack[t]);
    t--;
    *top = t;

    return;
}

void endline() {
    printf("\n");

    return;
}

void addition(int* stack, int* top) {
    int t = *top;
    int num1;
    int num2;
    int sum;

    num1 = stack[t];
    t--;
    num2 = stack[t];
    sum = num2+num1;
    stack[t] = sum;

    *top = t;

    return;
}

void subtraction(int* stack, int* top) {
    int t = *top;
    int num1;
    int num2;
    int sub;

    num1 = stack[t];
    t--;
    num2 = stack[t];
    sub = num2-num1;
    stack[t] = sub;

    *top = t;

    return;
}

void multiplication(int* stack, int* top) {
    int t = *top;
    int num1;
    int num2;
    int mul;

    num1 = stack[t];
    t--;
    num2 = stack[t];
    mul = num2*num1;
    stack[t] = mul;

    *top = t;

    return;
}

void division(int* stack, int* top) {
    int t = *top;
    int num1;
    int num2;
    int div;

    num1 = stack[t];
    t--;
    num2 = stack[t];
    div = num2/num1;
    stack[t] = div;

    *top = t;

    return;
}
