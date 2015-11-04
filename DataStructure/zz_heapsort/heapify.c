#include "heapify.h"

void buildMaxHeap(int * Arr /* Array of elements */, int n /* Size of the array */) {
    int i;

    /* Call maxHeapify recursively on every non-leaf node */
    for(i = n / 2 ; i >= 0 ; i--)
        maxHeapify(Arr, i, n);

    return;
}

void buildMinHeap(int * Arr /* Array of elements */, int n /* Size of the array */) {
    int i;

    /* Call minHeapify recursively on every non-leaf node */
    for(i = n / 2 ; i >= 0 ; i--)
        minHeapify(Arr, i, n);

    return;
}

void maxHeapify(int * Arr /* Array of elements */,
        int i /* Root index */, int n /* Size of the array */) {
    int leftChild, rightChild, max;

    /* These two variables hold the indexes of the left and the right child */
    leftChild  = 2 * i + 1;
    rightChild = 2 * i + 2;

    /* The max variable holds the index of the parent */
    max = i;

    /* If the left child is greater than the parent set max = leftChild */
    if(leftChild < n && Arr[leftChild] > Arr[max])
        max = leftChild;

    /* If the right child is greater than the parent set max = rightChild */
    if(rightChild < n && Arr[rightChild] > Arr[max])
        max = rightChild;

    /* If max is not the parent swap the parent with the largest value */
    if(max != i) {
        swap(&Arr[i], &Arr[max]);

        /* Call maxHeapify on the child with the new value */
        maxHeapify(Arr, max, n);
    }

    return;
}

void minHeapify(int * Arr /* Array of elements */,
        int i /* Root index */, int n /* Size of the array */) {
    int leftChild, rightChild, min;

    /* These two variables hold the indexes of the left and the right child */
    leftChild  = 2 * i + 1;
    rightChild = 2 * i + 2;

    /* The min variable holds the index of the parent */
    min = i;

    /* If the left child is less than the parent set min = leftChild */
    if(leftChild < n && Arr[leftChild] < Arr[min])
        min = leftChild;

    /* If the right child is less than the parent set min = rightChild */
    if(rightChild < n && Arr[rightChild] < Arr[min])
        min = rightChild;

    /* If min is not the parent swap the parent with the smallest value */
    if(min != i) {
        swap(&Arr[i], &Arr[min]);

        /* Call minHeapify on the child with the new value */
        minHeapify(Arr, min, n);
    }

    return;
}

void swap(int * a, int * b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;

    return;
}
