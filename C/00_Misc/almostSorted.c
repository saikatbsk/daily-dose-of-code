/* Solution to problem: https://www.hackerrank.com/challenges/almost-sorted */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(int * x, int * y) {
    int tmp;

    tmp = *x;
    *x  = *y;
    *y  = tmp;
}

void reverseSubArray(int arr[], int start, int end) {
    int n = end-start+1;
    int h = n/2;

    for(int i = 0 ; i < h ; i++) {
        swap(&arr[start+i], &arr[end-i]);
    }
}

int checkIfSorted(int arr[], int length) {
    for(int i = 0 ; i < length-1 ; i++) {
        if(arr[i+1] < arr[i])
            return 0;
    }

    return 1;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;  //-- number of digits in the input array

    // Read inputs
    fscanf(stdin, "%d", &n);

    int arr[n];
    for(int i = 0 ; i < n ; i++)
        fscanf(stdin, "%d", &arr[i]);

    // Check for subarray where modifications might be necessary
    int start, end;
    start = end = -1;

    for(int i = 0 ; i < n-1 ; i++) {
        if(arr[i+1] < arr[i]) {
            start = i;
            break;
        }
    }

    if(start == -1) {   //-- no modifications needed; array already sorted
        printf("yes");
        return 0;
    }
    else {
        for(int i = n-1 ; i > 0 ; i--) {
            if(arr[i] < arr[i-1]) {
                end = i;
                break;
            }
        }
    }

    // Check by swapping start and end
    int _arr[n];
    for(int i = 0 ; i < n ; i++) {
        _arr[i] = arr[i];
    }

    swap(&_arr[start], &_arr[end]);
    if(checkIfSorted(_arr, n)) {
        printf("yes\n");
        printf("swap %d %d", start+1, end+1);
        return 0;
    }

    // Check by reversing the subarray arr[start ... end]
    reverseSubArray(arr, start, end);
    if(checkIfSorted(arr, n)) {
        printf("yes\n");
        printf("reverse %d %d", start+1, end+1);
        return 0;
    }

    // Declare not possible
    printf("no");

    return 0;
}
