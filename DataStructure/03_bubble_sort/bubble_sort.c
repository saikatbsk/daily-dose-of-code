/* Program to implement Bubble Sort in C */
#include <stdio.h>
#include <stdlib.h>

void swap(int *item1, int *item2) {
    *item1 = *item1+*item2;
    *item2 = *item1-*item2;
    *item1 = *item1-*item2;
}

int main(int argc, char **argv) {
    int i, j;
    int arg[100];
    int nItems, n;

    if(argc < 2) {
        printf("Opps! no data.\n");
        printf("Usage: sort <item 1> <item 2> <item 3> ...\n");
        exit(0);
    }

    nItems = argc-1;

    for(i = 1 ; i < argc ; i++) {
        arg[i-1] = atoi(argv[i]);
    }

    printf("Inserted: ");
    for(i = 0 ; i < nItems ; i++) {
        printf("%d ", arg[i]);
    }

    printf("\n");

    /* bubble sorting */
    n = nItems;
    for(i = 0 ; i < nItems ; i++) {
        for(j = 1 ; j < n ; j++) {
            if(arg[j-1] > arg[j]) {
                swap(&arg[j-1], &arg[j]);
            }
        }
        n = n-1;
    }

    /* Display the sorted array */
    printf("Sorted:   ");
    for(i = 0 ; i < nItems ; i++) {
        printf("%d ", arg[i]);
    }

    printf("\n");

    return 0;
}
