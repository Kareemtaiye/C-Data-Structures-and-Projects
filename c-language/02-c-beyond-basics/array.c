#include <stdio.h>

// int* reverse(int list[]) {
//     int length = sizeof(list) / sizeof(list[0]);
//     for (int i = length; i != 0; i--) {
//         list[i] = list[length];
//     }
// }

int main() {
    int arr[10] = {2, 10, 5, [6] = 1, [8] = 3};

    int i = 0, j = 0;

    for (i = 0; i < 10; i++) {
        printf("Enter the number for position %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    while (j < 10) {
        printf("Number at position %d is %d \n", j, arr[j]);
        j++;
    }
}