#include <stdio.h>

int factorial(int n);

int factorial(int n) {
    if(n != 1)
        return n * factorial(n - 1);
}

int main() {
    int n;

    printf("Enter a value to produce factorial: ");
    scanf("%d", &n);

    printf("The factorial is: %d\n", factorial(n));

    return 0;
}
