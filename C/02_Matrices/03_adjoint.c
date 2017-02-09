/*
 * Produce the adjoint of a given 3x3 matrix
 */
#include <stdio.h>
#include <math.h>
#define MAXITEM 3

int getCofactor(int M[][MAXITEM], int i, int j);

/* Produces the cofactor of an element */
int getCofactor(int M[][MAXITEM], int i, int j) {
    int m[MAXITEM][MAXITEM]; //-- Matrix that holds the minor
    int cofactor;
    int r, c;
    int k, l;

    k = l = 0;

    for(r = 0 ; r < 3 ; r++) {
        for(c = 0 ; c < 3 ; c++) {
            if(r != i && c != j) {
                m[k][l] = M[r][c];
                l++;
            }
        }
        if(r != i) {
            l = 0;
            k++;
        }
    }

    //-- Calculate the cofactor
    cofactor = pow(-1, i + j) * (m[0][0] * m[1][1] - m[0][1] * m[1][0]);

    return cofactor;
}

int main() {
    int M[MAXITEM][MAXITEM],
        C[MAXITEM][MAXITEM],
        T[MAXITEM][MAXITEM];
    int i, j;

    printf("Enter a 3x3 matrix and the program will produce the adjoint:\n");
    for(i = 0 ; i < 3 ; i++) {
        for(j = 0 ; j < 3 ; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    //-- Producing the cofactor matrix
    for(i = 0 ; i < 3 ; i++) {
        for(j = 0 ; j < 3 ; j++) {
            C[i][j] = getCofactor(M, i, j);
        }
    }

    //-- Generate the transpose of the cofactor matrix
    for(i = 0 ; i < 3 ; i++) {
        for(j = 0 ; j < 3 ; j++) {
            T[i][j] = C[j][i];
        }
    }

    //-- Display the final matrix
    printf("The adjoint is:\n");
    for(i = 0 ; i < 3 ; i++) {
        for(j = 0 ; j < 3 ; j++) {
            printf("%4d ", T[i][j]);
        }
        printf("\n");
    }

    return 0;
}
