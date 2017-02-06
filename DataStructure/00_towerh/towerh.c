#include <stdio.h>
#include <stdlib.h>

long int step = 0;

void tower(
        nrDisk  /* no. of disks */,
        from    /* from this peg */,
        to      /* to this peg */,
        via     /* via this peg/transit peg */)

    /* type decleration of parameters */
    int nrDisk;
    char from, to, via;
{
    if(nrDisk == 1) {
        //printf("STEP %ld: Move from %c to %c via %c\n", step, from, to, via);
        step++;
    }
    else {
        tower(nrDisk-1, from, via, to);
        tower(1, from, to, via);
        tower(nrDisk-1, via, to, from);
    }

    return;
}

int main(int argc, char ** argv) {
    int n;

    if(argc >= 2) {
        n = atoi(argv[1]);
    }
    else {
        printf("Enter the number of disks: ");
        scanf("%d", &n);
    }

    /* fromulate tower of Hanoi and generate list of possible ways */
    tower(n, 'A', 'B', 'C');

    printf("Done! Total number of steps performed: %ld\n", step);

    return 0;
}
