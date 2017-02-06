/*
 * Basic macro definitions in C.
 */
#include <stdio.h>
#define NUM 100
#define STR "100"
#define CHR '2'
#define f(x) 2 * x
#define div /

int main() {
    printf("%d\n", NUM);
    printf("%s\n", STR);
    printf("%c\n", CHR);
    printf("%d\n", f(NUM));
    printf("%f\n", (float)22 div (float)7);

    return 0;
}