/*
 * C program to find the value of a determinant of 2nd and 3rd order.
 */
#include <stdio.h>
#include <math.h>
#define MAXITEM 3

int getCofactor(int dA[][MAXITEM], int i, int j);

/*
 * Produces the cofactor of an element.
 */
int getCofactor(int dA[][MAXITEM], int i, int j) {
    int mA[MAXITEM][MAXITEM]; //-- Matrix that holds the minor.
    int cofactor;
    int r, c;
    int k, l;

    k = l = 0;

    for(r = 0 ; r < 3 ; r++) {
        for(c = 0 ; c < 3 ; c++) {
            if(r != i && c != j) {
                mA[k][l] = dA[r][c];
                l++;
            }
        }
        if(r != i) {
            l = 0;
            k++;
        }
    }

    //-- Calculate the cofactor.
    cofactor = pow(-1, i + j) * (mA[0][0] * mA[1][1] - mA[0][1] * mA[1][0]);

    return cofactor;
}

int main() {
    int detOrder; //-- The order of the determinant.
    int dA[MAXITEM][MAXITEM]; //-- Array to hold the elements.
    int row, col;
    int d;

    printf("C program to find out the value of a determinant.\n");
    printf("-------------------------------------------------\n");

    printf("\n");

    printf("Order of the determinant? (2/3) ");
    scanf("%d", &detOrder);

    switch(detOrder) {
        case 2:
            /*
             * Take the elements of the determinant as input from the user.
             * Fill up dA one row at a time.
             */
            printf("Enter the elements one row at a time:\n");

            for(row = 0 ; row < 2 ; row++)
                for(col = 0 ; col < 2 ; col++)
                    scanf("%d", &dA[row][col]);

            /*
             * calculate the value of the determinant.
             */
            d = getCofactor(dA, -1, -1);

            printf("Value of the determinant is: %d\n", d);

            break;
        case 3:
            /*
             * Take the elements of the determinant as input from the user.
             */
            printf("Enter the elements one row at a time:\n");

            for(row = 0 ; row < 3 ; row++)
                for(col = 0 ; col < 3 ; col++)
                    scanf("%d", &dA[row][col]);

            /*
             * calculate the value of the determinant.
             */
            int k;
            d = 0;

            for(k = 0 ; k < 3 ; k++) {
                d += dA[0][k] * getCofactor(dA, 0, k);
            }

            printf("Value of the determinant is: %d\n", d);

            break;
        default:
            printf("The program is limited to determinants of order 2 and 3!\n");

            break;
    }

    return 0;
}
