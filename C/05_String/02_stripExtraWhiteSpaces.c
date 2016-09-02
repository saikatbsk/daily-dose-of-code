#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXLEN 1024

char * stripExtraWhiteSpaces(char * str) {
    char * finalString;
    char * tmp;
    char ch;
    int i = 0;

    finalString = (char *) malloc(sizeof(char) * MAXLEN);
    tmp = (char *) malloc(sizeof(char) * MAXLEN);

    while((ch = str[i]) != '\0') {
        if(ch == ' ') {
            if(strcmp(tmp, "") != 0) {
                strcat(finalString, tmp);
                strcat(finalString, " ");
            }

            strcpy(tmp, "");
        }
        else {
            char * ptr = (char *) malloc(sizeof(char) * 2);
            ptr[0] = ch;
            ptr[1] = '\0';

            strcat(tmp, ptr);
            free(ptr);
        }

        i++;
    }

    if(strcmp(tmp, " ") != 0)
        strcat(finalString, tmp);

    free(tmp);

    return finalString;
}

int main() {
    char * str;
    str = (char *) malloc(sizeof(char) * MAXLEN);
    strcpy(str, " live long    and  prosper!");

    str = stripExtraWhiteSpaces(str);
    printf("%s\n", str);

    return 0;
}

