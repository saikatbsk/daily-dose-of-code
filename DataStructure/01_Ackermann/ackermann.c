#include <stdio.h>

int ackermann(int x, int y) {
    int result;

    if(x == 0)
        result = y+1;
    else if(y == 0)
        result = ackermann(x-1, 1);
    else
        result = ackermann(x-1, ackermann(x, y-1));

    return result;
}

int main() {
    int i, j;

    for(i = 0 ; i < 6 ; i++)
        for(j = 0 ; j < 6 ; j++)
            printf("ackermann (%d, %d) is: %d\n", i, j, ackermann(i, j));

    return 0;
}
