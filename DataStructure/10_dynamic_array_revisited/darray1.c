#include <stdio.h>
#include <stdlib.h>

int main() {
    int * b;

    b = (int *)malloc(10 * sizeof(int));
    printf("(b)   = %p\n", b);
    printf("(b+1) = %p\n", (b+1));
    printf("(b+3) = %p\n", (b+2));

    b[4] = 5;
    printf("*(b+4) = %d\n", *(b+4));

    return 0;
}
