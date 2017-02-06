/*
 * 2D array as argument to a function
 */
#include <stdio.h>
#define MAXITEM 100

void display(int a[][MAXITEM], int row, int col); //-- function prototype

/*
 * function definition: definite amount of finite states that are ordered
 */
void display(int a[][MAXITEM], int row, int col) {
    int i, j;

    for(i = 0 ; i < row ; i++) {
        for(j = 0 ; j < col ; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r, c;
    int i, j;
    int a[MAXITEM][MAXITEM];

    printf("Enter row and column for the matrix to be entered: ");
    scanf("%d %d", &r, &c);

    printf("Enter the matrix:\n");
    for(i = 0 ; i < r ; i++) {
        for(j = 0 ; j < c ; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("The matrix is:\n");
    display(a, r, c);

    return 0;
}
