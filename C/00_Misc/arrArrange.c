/*
 * Given an input array, arrange the array such that -ve numbers are kept in
 * even positions and +ve ones are in odd positions until one of them exhaust.
 * Then rest of the numbers should appear in the array keeping their initial
 * order of occurence.
 *
 * IMPORTANT:
 *      1. Do not initialize any other array. Do the manipulations in place.
 *      2. Consider 0 as even number.
 *
 * Example,
 *      Input : 4 -13 5 -17 21 -3 -9 6 37 22
 *      output: -13 4 -17 5 -3 21 -9 6 37 22
 */

#include <stdio.h>
#include <stdlib.h>

void display(int * arr, int length);
int check(int arr1[], int arr2[], int length);
int * arrArrange(int * arr, int length);

/* MODIFY THIS FUNCTION. */
int * arrArrange(int * arr, int length) {
    for(int i = 0 ; i < length ; i++) {
        if(((i%2) == 0) && (arr[i] >= 0)) {
            for(int j = i+1 ; j < length ; j++) {
                if(arr[j] < 0) {
                    for(int k = j ; k > i ; k--) {
                        int tmp  = arr[k];
                        arr[k]   = arr[k-1];
                        arr[k-1] = tmp;

                        break;
                    }
                }

                break;
            }
        }
        else if(((i%2) != 0) && (arr[i] < 0)) {
            for(int j = i+1 ; j < length ; j++) {
                if(arr[j] >= 0) {
                    for(int k = j ; k > i ; k--) {
                        int tmp  = arr[k];
                        arr[k]   = arr[k-1];
                        arr[k-1] = tmp;

                        break;
                    }
                }

                break;
            }
        }
    }

    return arr;
}

/* Keep the following section unmodified. */
void display(int * arr, int length) {
    for(int i = 0 ; i < length ; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int check(int arr1[], int arr2[], int length) {
    int count = 0;

    for(int i = 0 ; i < length ; i++) {
        if(arr1[i] == arr2[i])
            count++;
    }

    if(count < length)
        return -1;

    return 0;
}

int main() {
    int inputArray[100] = {4, -13, 5, -17, 21, -3, -9, 6, 9, -22, -1, -4, 8, 7, 8, 34};
    int desiredOut[100] = {-13, 4, -17, 5, -3, 21, -9, 6, -22, 9, -1, 8, -4, 7, 8, 34};
    int lenOfInputArray = 16;

    int * arr = (int *)malloc(sizeof(int) * 100);
    for(int i = 0 ; i < lenOfInputArray ; i++)
        arr[i] = inputArray[i];

    arr = arrArrange(arr, lenOfInputArray);
    if(check(arr, desiredOut, lenOfInputArray) < 0) {
        printf("Result: FAILED!!\n");
    }
    else {
        printf("Result: PASSED.\n");
    }

    printf("\nInput array:\n");
    display(inputArray, lenOfInputArray);

    printf("\nDesired output:\n");
    display(desiredOut, lenOfInputArray);

    printf("\nYour output:\n");
    display(arr, lenOfInputArray);

    return 0;
}
