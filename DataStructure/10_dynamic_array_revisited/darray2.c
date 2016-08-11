#include <stdio.h>
#include <stdlib.h>

int main() {
    int * b[5];

    for(int i = 0 ; i < 5 ; i++) {
        b[i] = (int *)malloc(10 * sizeof(int));
    }

    printf("(b)   = %u\n", b);
    printf("(b+1) = %u\n", (b+1));
    printf("(b+3) = %u\n", (b+2));

    printf("*(b+2)   = %u\n", *(b+2));
    printf("*(b+2)+3 = %u\n", *(b+2)+3);

    *(*(b+2)+3) = 5;

    printf("*(*(b+2)+3) = %u\n", *(*(b+2)+3));

    return 0;
}
