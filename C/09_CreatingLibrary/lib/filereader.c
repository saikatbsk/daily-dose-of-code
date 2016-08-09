#include <stdio.h>

int filereader(const char * file_name) {
    FILE * f;
    char ch;

    f = fopen(file_name, "r");
    if(f == NULL) {
        return -1;
    }

    while(1) {
        ch = fgetc(f);
        if(ch == EOF)
            break;

        printf("%c", ch);
    }

    fclose(f);

    return 0;
}
