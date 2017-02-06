/*
 * Quick Sort using the method of forward partitioning
 */
#include <stdlib.h>
#include <stdio.h>
#define MAXITEM 100

void swap(int * x, int * y) {
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

void fpartition(int arr[], int start, int end, int * pivot) {
    int l /* end index of the lower part */,
        u /* end index of the upper part */;

    l = start + 1;

    /* partition with respect to pivot arr[start] */
    for(u = start + 1 ; u < end ; u++) {
        if(arr[u] <= arr[start]) {
            swap(&arr[u], &arr[l]);
            l++;
        }
    }

    /* move pivot into place */
    swap(&arr[start], &arr[l - 1]);

    /* set pointer for pivot */
    *pivot = l - 1;
}

void quickSort(int arr[], int start, int end) {
    int pivot;

    if(end - start <= 1) {  //-- base case
        return;
    }
    else {
        /* make the partition */
        fpartition(arr, start, end, &pivot);

        /* quick sort the two partitions */
        quickSort(arr, start, pivot);
        quickSort(arr, pivot + 1, end);
    }
}

int main(int argc, char * argv[]) {
    int length,
        i;
    int primArr[MAXITEM];

    if(argc < 2) {
        printf("Usage: a.out {set of numbers to be sorted}\n");
        printf("Example:\n\t./a.out 1 7 8 3 10 4\n");
        exit(1);
    }

    /* get the set of numbers to be sorted */
    length = argc - 1;
    printf("The set of numbers to be sorted:\n\t");
    for(i = 0 ; i < length ; i++) {
        primArr[i] = atoi(argv[i + 1]);
        printf("%d ", primArr[i]);
    }
    printf("\n");

    /* sort the set of numbers using quick sort */
    quickSort(primArr, 0, length);

    /* display the sorted array */
    printf("The set of numbers after sorting:\n\t");
    for(i = 0 ; i < length ; i++) {
        printf("%d ", primArr[i]);
    }
    printf("\n");

    return 0;
}
