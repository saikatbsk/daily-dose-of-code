#include <stdio.h>

int main() {
    int i, len;

    /* Declaration of char array */
    char str[100];

    /* Get the string from standard input buffer */
    fgets(str, 100, stdin);

    i = 0;
    len = 0;

    /* Run a loop until '\n' is reached */
    while(str[i] != '\n') {
        len++;
        i++;
    }

    /* Print the result */
    printf("Length of the string is: %d\n", len);

    return 0;
}
