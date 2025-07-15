#include <stdio.h>

int main() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // Without pointers
    printf("Without pointers: ");
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
    }

    // With pointers
    int *p;
    printf("\nWith pointers: ");
    for (p = &arr[0][0]; p <= &arr[1][2]; p++) {
        printf("%d ", *p);
    }

    // With pointers(using dimentions)
    int rows = 2, cols = 3;
    printf("\nWith pointers: ");
    for (p = &arr[0][0]; p < &arr[0][0] + rows * cols; p++) {
        printf("%d ", *p);
    }

    return 0;
}