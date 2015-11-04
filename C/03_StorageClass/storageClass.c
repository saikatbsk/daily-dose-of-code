/*
 * An example illustrating storage classes in C.
 */
#include <stdio.h>
#include "storageClass.h"

static int g_count; /* Global Variable */
void func(void);

int main() {
    /*
     * The `auto` Storage Class
     * ======================================================================
     * An automatic variable is a local variable which is allocated and
     * deallocated automatically when a program enters and leaves the
     * variable's scope. All variables within a block of code are automatic
     * by default, but this can be made explicit with the `auto` keyword.
     */
    auto int x;

    x = 7;  //-- Now we assign a value to x.

    printf("Part 1 : Auto Storage Class\n");
    printf("The value of x is %d\n", x);
    printf("\n");

    /*
     * The `register` Storage Class
     * ======================================================================
     * Using the storage class `register` is a hint to the compiler to cache
     * the variable in a processor register. Other than not allowing the
     * referencing operator (&) to be used on the variable or any of its
     * subcomponents, the compiler is free to ignore the hint. This also means
     * that the variable has a maximum size equal to the register size
     * (usually one word).
     *
     * It should also be noted that defining `register` does not mean that
     * the variable will be stored in a register. It means that it MIGHT be
     * stored in a register depending on hardware and implementation
     * restrictions.
     */
    register int counter;

    counter = 0;

    while(x > 0) {
        counter++;
        x--;
    }

    printf("Part 2 : Register Storage Class\n");
    printf("x has the value equal to %d\n", counter);
    printf("\n");

    /*
     * The `static` Storage Class
     * ======================================================================
     * Static is the default storage class for global variables. Static
     * variables can be 'seen' within all functions in this source file.
     * At link time, the static variables defined here will not be seen by
     * the object modules that are brought in.
     *
     * Static can also be defined within a function. If this is done the
     * variable is initialized at run time but is not reinitialized when the
     * function is called. This inside-a-function static variable retains its
     * value during various calls.
     */
    g_count = 10;

    printf("Part 3 : Static Storage Class\n");

    while(g_count /* Global Variable */ > 0) {
        func();
        g_count--;
    }

    printf("\n");

    /*
     * The `extern` Storage Class
     * ======================================================================
     * Extern is used to give a reference of a global variable that is
     * visible to ALL the program files. When one uses 'extern' the variable
     * cannot be initialized as all it does is to point the variable name at
     * a storage location that has been previously defined.
     */
    extern int e;

    e = 100;

    printf("Part 4 : Extern Storage Class\n");
    printf("e is %d\n", e);

    return 0;
}

void func(void) {
    static int x;
    x = 9;

    printf("x is %d, and g_count is %d\n", x, g_count);

    return;
}
