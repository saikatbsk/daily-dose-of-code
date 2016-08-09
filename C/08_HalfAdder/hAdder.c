#include <stdio.h>

int hAdder(int x, int y) {
    // Implementation of Half Adder logic
    while(y != 0) {
        int c = x & y;
        x = x ^ y;
        y = c << 1;
    }

    return x;
}

int main() {
    int a, b, sum;

    printf("Enter two numbers to perform addition: ");
    scanf("%d %d", &a, &b);

    sum = hAdder(a, b);
    printf("The sum is = %d\n", sum);

    return 0;
}
