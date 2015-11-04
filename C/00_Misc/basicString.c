#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main() {
    char * str;

    //-- allocating memory for str using malloc
    // str = (char *)malloc(sizeof(char) * SIZE);

    //-- allocating memory for str using calloc
    str = (char *)calloc(sizeof(char), SIZE);

    //-- get the string from user
    fgets(str, SIZE, stdin);

    //-- print the first character
    printf("%c\n", str[0]);

    //-- print the next character
    printf("%c\n", str[1]);

    //-- print the entire string
    printf("%s\n", str);

    return 0;
}
