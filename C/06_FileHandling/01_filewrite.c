#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

int main() {
    char * st;
    FILE * fp;

    st = (char *)malloc(sizeof(char) * MAXSIZE);
    fgets(st, MAXSIZE, stdin);

    if(!(fp = fopen("sample1.txt", "w"))) {
        printf(">>> Error! file could not be written.\n");
        return -1;
    }

    fputs(st, fp);

    fclose(fp);

    return 0;
}
