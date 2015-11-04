/*
 * Program to check if a string is a sub-string of another.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100

int checkSubString(char * str1, char * str2);

int main() {
    char * s1;
    char * s2;

    s1 = (char *)malloc(sizeof(char) * MAXSIZE);
    s2 = (char *)malloc(sizeof(char) * MAXSIZE);

    /*
     * Scan the two strings.
     */
    printf("Please enter a string: ");
    fscanf(stdin, "%s", s1);

    printf("Please enter the substring: ");
    fscanf(stdin, "%s", s2);

    /*
     * Check if the 2nd string is a substring of the original string.
     */
    if(checkSubString(s1, s2)) {
        fprintf(stdout, ">>> %s is a substring of %s.\n", s2, s1);
    }
    else {
        fprintf(stdout, ">>> %s is not a substring of %s.\n", s2, s1);
    }

    return 0;
}

int checkSubString(char * str1, char * str2) {
    int i, j;

    /*
     * We look through each symbol of the original string. If any symbol
     * of the 2nd string matches a symbol of the original we check with
     * the next symbol of the 2nd string. If that does not match restart
     * with the first symbol of the 2nd string. We do this until we reach
     * the end of one of the two strings.
     */
    for(i = 0, j = 0 ; i < strlen(str1) && j < strlen(str2); i++) {
        if(str1[i] == str2[j]) {
            j++;
        }
        else {
            j = 0;
        }
    }

    /*
     * Finally if we can check all the values of the 2nd string we can
     * be sure that the 2nd string is a subset of the original string.
     */
    if(j == strlen(str2)) {
        return 1;
    }

    return 0;
}
