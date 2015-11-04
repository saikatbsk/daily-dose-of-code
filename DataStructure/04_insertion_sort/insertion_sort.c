/*
 * ----------------------------------------------
 * Author: Saikat Basak
 * Description: insertion sort the usual way
 * Compile: gcc -o sort 01_insertion_sort.c
 * ----------------------------------------------
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXITEMS 100

void err_nodata();
void help();
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

void sort(int * array, int nitems) {
    int i, j;
    int tmp;

    /* move the key pointer from 1 till the last item */
    for(i = 1 ; i < nitems ; i++) {
        tmp = array[i];

        /* shift elements to the right to find proper position for tmp */
        for(j = i - 1 ; j >= 0 ; j--) {
            if(array[j] > tmp) {
                array[j + 1] = array[j];
            }
            else
                break;
        }

        /* put tmp in the proper array location */
        array[j + 1] = tmp;
    }
}

void display(int array[], int items) {
    int i;

    for(i = 0 ; i < items ; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}
