/*
 * ----------------------------------------------
 * Author: Saikat Basak
 * Description: insertion sort
 * ----------------------------------------------
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXITEMS 100

void err_nodata();
void help();
void swap(int * p, int * q);
void sort(int * array, int nitems);
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
        sort(ITEMS, NITEM);

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

void sort(int * array, int nitems) {
    int pos;
    int nextpos;

    /*
     * Build longer and longer sorted segments. In each
     * iteration array[0] ... array[pos - 1] is already sorted.
     */
    for(pos = 1 ; pos < nitems ; pos++) {
        /*
         * Move first element after sorted segment left
         * till it is in the correct place.
         */
        nextpos = pos;
        while(nextpos > 0 &&
                array[nextpos] < array[nextpos - 1]) {
            swap(&array[nextpos], &array[nextpos - 1]);
            nextpos--;
        }
    }
}

void display(int array[], int items) {
    int i;

    for(i = 0 ; i < items ; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}
