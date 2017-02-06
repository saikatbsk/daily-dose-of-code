/*
 * SIMPSON'S 1/3 RULE
 */

#include <stdio.h>
#include <stdlib.h>
#define f(x) x*x*x

int main() {
    float a;  //-- lower limit
    float b;  //-- upper limit
    float h;  //-- segmentation width
    int n;    //-- number of intervals
    int i;

    printf("+========================+\n");
    printf("+   SIMPSON'S 1/3 RULE   +\n");
    printf("+========================+\n");

    printf("Enter the lower limit: ");
    scanf("%f", &a);

    printf("Enter the upper limit: ");
    scanf("%f", &b);

    printf("Enter number of interval: ");
    scanf("%d", &n);

    //-- calculating the segmentation width
    h = (b-a) / n;

    //-- check if solution is possible
    if((a+h) > b) {
        printf(">>> A solution is NOT possible with these inputs!!\n");
        exit(0);
    }

    float arg1, arg2, sum;
    float part1, part2, part3, total;

    part1 = f(a) + f(b);

    sum = 0;
    for (i = 1 ; i < n ; i = i+2) {
        arg1 = a + (i*h);
        arg2 = f(arg1);
        sum = sum + arg2;
    }
    part2 = 4*sum;

    sum = 0;
    for (i = 2 ; i < n-1 ; i = i+2) {
        arg1 = a + (i*h);
        arg2 = f(arg1);
        sum = sum + arg2;
    }
    part3 = 2*sum;

    total = (h/3) * (part1+part2+part3);
    printf("The final result is: %f\n", total);

    return 0;
}
