/* Swap using Call By Reference method */
#include <stdio.h>

void swap(int * x, int * y);

int main() {
    int p, q;

    p = 9;
    q = 6;

    printf("Before swap: %d %d\n", p, q);

    swap(&p, &q);

    printf("After swap [in main]: %d %d\n", p, q);
}

void swap(int * x, int * y) {
    int t;

    t = *x;
    *x = *y;
    *y = t;

    printf("After swap [in swap]: %d %d\n", *x, *y);
}
