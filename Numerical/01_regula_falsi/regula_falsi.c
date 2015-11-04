#include <stdio.h>
#include <math.h>
#define ESP 0.001
#define f(x) (x * x * x + 2 * x - 5)

int main() {
    float x0 /* lower limit of the initial guess */,
          x1 /* upper limit of the initial guess */,
          x2 /* mid point */;
    double f0, f1, f2;

    printf("Finding root for equation: x^3 + 2x - 5\n");

    printf("Enter the value of the lower limit: ");
    scanf("%f", &x0);

    printf("Enter the value of the lower limit: ");
    scanf("%f", &x1);

    if((f(x0) * f(x1)) > 0) {
        printf(">>> The range does not bracket the desired root!\n");
        return 1;
    }

    int i = 0;

    printf(" Iteration |           x0 |           x1 |           x2 |           f0 |           f1 |           f2 \n");
    printf("-----------+--------------+--------------+--------------+--------------+--------------+--------------\n");

    do {
        f0 = f(x0);
        f1 = f(x1);
        f2 = f(x2);

        x2 = x0 - (f0 * (x1 - x0)) / (f1 - f0);

        printf(" %9d | %-12f | %-12f | %-12f | %-12lf | %-12lf | %-12lf\n", i, x0, x1, x2, f0, f1, f2);

        if(f0 * f2 < 0) {
            x1 = x2;
        }
        else if(f0 * f2 > 0) {
            x0 = x2;
        }
        else {
            break;
        }

        i++;
    } while(fabs(f2) > ESP);

    printf("----------- -------------- -------------- -------------- -------------- -------------- --------------\n");
    printf("Approx Root: %f\n", x2);

    return 0;
}
