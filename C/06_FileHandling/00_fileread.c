#include <stdio.h>

int main() {
    char ch;
    FILE * fp;

    if(!(fp = fopen("sample.txt", "r"))) {
        printf(">>> Error! file does not exist.\n");
        return -1;
    }

    while((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);

    return 0;
}
