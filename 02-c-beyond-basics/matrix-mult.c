#include <stdio.h>
#define MAX 50

/* Create a function for the matrix for reuse later */
int* multMatrix(int matA[], int matB[]) {}

int main() {
    /* Specify dimension for matrix A */
    int a_row;
    int a_col;

    printf(
        "Enter the number of rows and column for matrix A in format 'a b': ");
    scanf("%d %d", &a_row, &a_col);

    int matrixA[MAX][MAX];

    printf("Enter matrix A values\n");

    for (int i = 0; i < a_row; i++) {
        for (int j = 0; j < a_col; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    /* Specify dimension for matrix B*/
    int b_row;
    int b_col;

    printf(
        "\nEnter the number of rows and column for matrix A in format 'a b': ");
    scanf("%d %d", &b_row, &b_col);

    if (a_col != b_row) {
        printf(
            "Matrix multiplication cannot be performed A=(%d x %d) x B=(%d x "
            "%d)",
            a_row, a_col, b_row, b_col);
        return 1;
    }

    int matrixB[MAX][MAX];

    printf("Enter matrix B values\n");

    for (int i = 0; i < b_row; i++) {
        for (int j = 0; j < b_col; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    /* Resultant matriz */
    int resultant[MAX][MAX];
    int sum = 0;

    for (int i = 0; i < a_row; i++) {
        for (int j = 0; j < b_col; j++) {
            for (int k = 0; k < b_row; k++) {
                sum = sum + matrixA[i][k] * matrixB[k][j];
            }
            resultant[i][j] = sum;
            sum = 0;
        }
    }

    printf("Resultant matrix: \n");
    for (int i = 0; i < a_row; i++) {
        for (int j = 0; j < b_col; j++) {
            printf("%d ", resultant[i][j]);
        }
        printf(" \n");
    }
    return 0;
}