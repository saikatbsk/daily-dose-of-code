/*
 * Program to produce the factorial of n numbers.
 */
#include <stdio.h>

int main() {
    long int fact;
    int n, i;

    printf("Enter the number of terms to produce factorial: ");
    scanf("%d", &n);

    fact = 1;

    for(i = 0 ; i < n ; i++) {
        if(i > 0)
            fact = fact * i;

        printf("%2d! = %ld\n", i, fact);
    }

    return 0;
}
