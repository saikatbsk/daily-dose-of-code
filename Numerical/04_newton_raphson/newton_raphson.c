/*
 * C program to implement Newton-Raphson Method
 */

#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * log10(x) - 1.2;
}

double df(double x) {
    return log10(x) + 0.43429;
}

int main() {
    int itr    /* Number of iterations */,
        maxItr /* Maximum number of iterations */;

    double h, x0, x1, error;

    printf("Enter x0, allowed error and maximum number of iterations: ");
    scanf("%lf %lf %d", &x0, &error, &maxItr);

    for(itr = 0; itr < maxItr ; itr++) {
        h  = f(x0) / df(x0);
        x1 = x0 - h;
        printf(" At iteration %d, x = %lf\n", itr, x1);

        if(fabs(h) < error) {
            printf("After iteration %d, root = %lf\n", itr, x1);
            return 0;
        }

        x0 = x1;
    }

    printf(">>> The required solution does not converge or iterations are insufficient.\n");

    return 1;
}
