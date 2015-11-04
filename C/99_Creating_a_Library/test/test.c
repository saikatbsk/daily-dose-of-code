#include "filereader.h"
#include <stdio.h>

int main(int argc, char * argv[]) {
    if(filereader(argv[1]) == -1) {
        printf("Oops! cannot find %s\n", argv[1]);
    }

    return 0;
}
