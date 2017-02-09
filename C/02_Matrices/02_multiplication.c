/*
 * Program to implement matrix multiplication
 */
#include <stdio.h>
#define MAX 200

int main() {
    int M1[MAX][MAX], M2[MAX][MAX], //-- Input matrices
        R[MAX][MAX],                //-- Resultant matrix
        i, j, k,                    //-- Used in loops
        m, n, p, q;                 //-- Order of matrices

    /*  Scanning the order of the two matrices */
    printf("Enter the rows and columns for 1st matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter the rows and columns for 2nd matrix: ");
    scanf("%d %d", &p, &q);

    /*  Check if multiplication can be done */
    if(n != p) {
        printf(">>> Error! Cannot multiply!\n");

        return -1;
    }

    /*  Scan the elements */
    printf("Enter the elements for the 1st matrix:\n");
    for(i = 0 ; i < m ; i++) {
        for(j = 0 ; j < n ; j++) {
            scanf("%d", &M1[i][j]);
        }
    }

    printf("Enter the elements for the 2nd matrix:\n");
    for(i = 0 ; i < p ; i++) {
        for(j = 0 ; j < q ; j++) {
            scanf("%d", &M2[i][j]);
        }
    }

    /*  Multiply the two matrices */
    for(i = 0 ; i < m ; i++) {
        for(j = 0 ; j < q ; j++) {
            for(k = 0 ; k < n ; k++)
            {
                R[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }

    /*  Display the resultant matrix */
    printf("The resultant matrix is:\n");
    for(i = 0 ; i < m ; i++) {
        for(j = 0 ; j < q ; j++) {
            printf("%6d ", R[i][j]);
        }
        printf("\n");
    }

    return 0;
}
