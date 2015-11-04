/*
 * Program to find the transpose of a given matrix.
 */
#include <stdio.h>

int main() {
    int M[100][100]; //-- Used to store the matrix.
    int m, n; //-- Used to determine the order of the matrix.
    int i, j;

    printf("Enter the order of the matrix: (i.e. m, n) ");
    scanf("%d %d", &m, &n);

    printf("Enter the matrix:\n");

    for(i = 0 ; i < m ; i++) {
        for(j = 0 ; j < n ; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    printf("The transpose of the given matrix is:\n");

    for(i = 0 ; i < m ; i++) {
        for(j = 0 ; j < n ; j++) {
            printf("%d ", M[j][i]);
        }

        printf("\n");
    }

    return 0;
}
