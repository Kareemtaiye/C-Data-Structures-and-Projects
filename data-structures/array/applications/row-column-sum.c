#include <stdio.h>

int main() {
    // clang-format off
    int arr[5][5] = { 
        {8, 3, 9, 0, 10},
        {3, 5, 17, 1, 1},
        {2, 8, 6, 23, 1},
        {15, 7, 3, 2, 9},
        {6, 14, 2, 6, 0},
    };
    // clang-format on

    // Row sum
    printf("Row sum: ");
    int sum = 0;
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            sum = sum + arr[i][j];
        }
        printf("%d ", sum);
        sum = 0;
    }

    // Column sum
    printf("\nColumn sum: ");
    i = j = sum = 0;
    while (j < 5) {
        while (i < 5) {
            sum = sum + arr[i][j];
            i++;
        }
        j++;
        i = 0;
        printf("%d ", sum);
        sum = 0;
    }
    // for (i = 0; i < 5; j++) {
    //     for (j = 0; j < 5; i++) {

    //     }
    // }
}