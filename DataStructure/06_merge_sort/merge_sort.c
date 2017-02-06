#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 100

void merge(int arr[], int start, int end) {
    int mid,
        l, i, j;
    int tempArr[MAX_SIZE];

    mid = (start + end) / 2;
    l = start;
    i = start;
    j = mid + 1;

    /* form a temporary array */
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            tempArr[l++] = arr[i++];
        }
        else {
            tempArr[l++] = arr[j++];
        }
    }

    if(i > mid) {
        for(; j <= end ;) {
            tempArr[l++] = arr[j++];
        }
    }
    else if(j > end) {
        for(; i <= mid ;) {
            tempArr[l++] = arr[i++];
        }
    }

    /* copy to primary array */
    for(l = start ; l <= end ; l++) {
        arr[l] = tempArr[l];
    }
}

void mergeSort(int arr[], int start, int end) {
    int mid;

    if(start >= end) {
        return;
    }
    else {
        mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, end);
    }
}

int main(int argc, char* argv[]) {
    int i,
        length;
    int primArr[MAX_SIZE];

    if(argc < 2) {
        printf("Usage: a.out {set of elements to be sorted}\n");
        printf("Example:\n\t./a.out 2 8 1 5 9 24 3\n");
        exit(1);
    }

    /* get the set of numbers to be sorted */
    length = argc - 1;
    printf("Set of numbers to be sorted:\n\t");
    for(i = 0 ; i < length ; i++) {
        primArr[i] = atoi(argv[i + 1]);
        printf("%d ", primArr[i]);
    }
    printf("\n");

    /* apply the mergeSort routine */
    mergeSort(primArr, 0, length - 1);

    /* print the sorteed array */
    printf("The sorted array is:\n\t");
    for(i = 0 ; i < length ; i++) {
        printf("%d ", primArr[i]);
    }
    printf("\n");

    return 0;
}
