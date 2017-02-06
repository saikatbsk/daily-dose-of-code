/*
 * ----------------------------------------------
 * Author: Saikat Basak
 * Description: insertion sort, recursive
 * ----------------------------------------------
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXITEMS 100

void err_nodata();
void help();
void swap(int * p, int * q);
void insertionSort(int * array, int start, int nitems);
void insert(int * array, int start);
void display(int array[], int nitems);

int main(int argc, char ** argv) {
    int NITEM;            //-- number of items
    int ITEMS[MAXITEMS];  //-- the items array
    int i;

    if(argc < 2) {
        err_nodata();
        help();
    }
    else {
        NITEM = argc - 1;

        /* put the arguments into the ITEMS array */
        for(i = 0 ; i < NITEM ; i++) {
            ITEMS[i] = atoi(argv[i + 1]);
        }

        /* perform an insertion sort on the array */
        insertionSort(ITEMS, 0, NITEM);

        display(ITEMS, NITEM);
    }
}

void err_nodata() {
    printf("Opps! no data.\n");
}

void help() {
    printf("Usage: sort <item 1> <item 2> <item 3> ...\n");
}

void swap(int * p, int * q) {
    *p = *p + *q;
    *q = *p - *q;
    *p = *p - *q;
}

void insert(int * array, int start) {
    int pos;

    pos = start;

    /*
     * Insert array[start] into array[0 ... (start - 1)]
     */
    while(pos > 0 && array[pos] < array[pos - 1]) {
        swap(&array[pos], &array[pos - 1]);
        pos--;
    }
}

/*
 * Sort array from start to n - 1
 */
void insertionSort(int * array, int start, int nitems) {
    if(start > nitems - 1)
        return;

    insert(array, start);   /* Insert the value at start into
                               the rest of the array */
    insertionSort(array, start + 1, nitems);
}

void display(int array[], int nitems) {
    int i;

    for(i = 0 ; i < nitems ; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}
