/*
 * Merge Sort using additional arrays
 */
#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 100

/*
 * Merge arrA[0 ... m-1], arrB[0 ... n-1] to arrC[0 ... m+n]
 */
void merge(int arrA[], int m, int arrB[], int n, int arrC[]) {
    int i, j, k;

    i = j = k = 0;

    while(k < m + n) {
        //-- Case 1: Move head of arrA into arrC
        if(j == n || arrA[i] <= arrB[j]) {
            arrC[k] = arrA[i];
            i++; k++;
        }

        //-- Case 2: Move head of arrB into arrC
        if(i == m || arrA[i] > arrB[j]) {
            arrC[k] = arrB[j];
            j++; k++;
        }
    }
}

/*
 * Sort the segment arrA[left ... right-1] into arrB
 */
void mergeSort(int arrA[], int left, int right, int arrB[]) {
    int mid;
    int arrL[MAX_SIZE];
    int arrR[MAX_SIZE];

    if(right - left == 1) { //-- Base case
        arrB[0] = arrA[left];
    }

    if(right - left > 1) {  //-- Recursive call
        mid = (left + right) / 2;
        mergeSort(arrA, left, mid, arrL);
        mergeSort(arrA, mid, right, arrR);
        merge(arrL, mid - left, arrR, right - mid, arrB);
    }
}

int main(int argc, char* argv[]) {
    int i, length;

    int primArr[MAX_SIZE];
    int finlArr[MAX_SIZE];

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
    mergeSort(primArr, 0, length, finlArr);

    /* print the sorted array */
    printf("The sorted array is:\n\t");
    for(i = 0 ; i < length ; i++) {
        printf("%d ", finlArr[i]);
    }
    printf("\n");

    return 0;
}
