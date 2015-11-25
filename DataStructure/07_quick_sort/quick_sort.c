/*
 * Quick Sort: Partition using temporary array
 */
#include <stdlib.h>
#include <stdio.h>
#define MAXITEM 100

void partition(int arr[], int start, int end, int * l) {
    int p,
        i, j, m, n,
        count;
    int tmpArr[MAXITEM];

    p = arr[start]; //-- the chosen one

    /* create the two arrays */
    m = start + 1;
    n = end;
    count = 0;

    for(i = start + 1 ; i <= end ; i++) {
        if(arr[i] < p) {
            tmpArr[m++] = arr[i];
            count++;
        }
        else {
            tmpArr[n--] = arr[i];
        }
    }

    tmpArr[start] = tmpArr[start + count];
    tmpArr[start + count] = p;
    *l = start + count;

    /* put the contents back on the primary array */
    for(j = start ; j <= end ; j++) {
        arr[j] = tmpArr[j];
    }
}

void quickSort(int arr[], int start, int end) {
    int l;

    if(start >= end) {
        return;
    }
    else {
        /* make the partition */
        partition(arr, start, end, &l);

        /* quick sort the two partitions */
        quickSort(arr, start, l);
        quickSort(arr, l + 1, end);
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
    quickSort(primArr, 0, length - 1);

    /* display the sorted array */
    printf("The set of numbers after sorting:\n\t");
    for(i = 0 ; i < length ; i++) {
        printf("%d ", primArr[i]);
    }
    printf("\n");

    return 0;
}
