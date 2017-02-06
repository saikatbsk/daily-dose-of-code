#include <stdio.h>

int main() {
    int x;
    int * p;    /* p is a pointer type variable
                   that refers to a memory location */

    printf("Enter the value for x: ");
    scanf("%d", &x);

    p = &x; //-- now p refers to the same mem. location as &x

    printf("x  = %d\n", x);
    printf("*p = %d\n", *p);
    printf("p  = %p\n", p);
    printf("&x = %p\n", &x);

    return 0;
}
