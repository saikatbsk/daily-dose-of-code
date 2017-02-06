/*
 * Matrix Addition of Two Matrices
 */
#include <stdio.h>
#define MAXSIZE 100

int main() {
    int i, j;
    int m, n; //-- Degree of the matrices
    int M1[MAXSIZE][MAXSIZE];
    int M2[MAXSIZE][MAXSIZE];
    int SUM[MAXSIZE][MAXSIZE];

    printf("Degree of matrix? (m x n) ");
    scanf("%d %d", &m, &n);

    printf("Enter the 1st matrix:\n");
    for(i = 0 ; i < m ; i++) {
        for(j = 0 ; j < n ; j++) {
            scanf("%d", &M1[i][j]);
        }
    }

    printf("Enter the 2nd matrix:\n");
    for(i = 0 ; i < m ; i++) {
        for(j = 0 ; j < n ; j++) {
            scanf("%d", &M2[i][j]);
            SUM[i][j] = M1[i][j] + M2[i][j];
        }
    }

    printf("The sum of the two matrices:\n");
    for(i = 0 ; i < m ; i++) {
        for(j = 0 ; j < n ; j++) {
            printf("%4d", SUM[i][j]);
        }
        printf("\n");
    }

    return 0;
}
