/*
 * Simple program to create a heap
 *
 * compile using gcc as,
 *      gcc main.c heapify.c
 */

#include "heapify.h"

int main() {
    int i;
    int n, Arr[MAXSIZE];

    printf("How many elements do you want to enter? ");
    scanf("%d", &n);

    printf("Insert %d integer(s): ", n);
    for(i = 0 ; i < n ; i++)
        scanf("%d", &Arr[i]);

    buildMaxHeap(Arr, n);

    /* Displaying the array in descending order */
    printf("Displaying the array in descending order: ");
    for(i = 0 ; i < n ; i++) {
        printf("%d ", Arr[0]);

        Arr[0] = Arr[n - i - 1];
        buildMaxHeap(Arr, n - i - 1);
    }
    printf("\n");

    return 0;
}
