#include <stdio.h>

/* Finding the smallest and largest values in an array */
void minMax(int arr[], int len, int* min, int* max) {
    *min = *max = arr[0];

    for (int i = 1; i < len; i++) {
        if (arr[i] < *min)
            *min = arr[i];
        else if (arr[i] > *max)
            *max = arr[i];
    }
}

/* Finding the middle value in an array */

int* midValue(int arr[], int len) {
    // clang-format off
    return &arr[len / 2];
    // clang-format on
}

int main() {
    int min, max;
    int arr[] = {10, 5, 2, 98, 3, 125, 339, 55, 42};
    int len = sizeof(arr) / sizeof(arr[0]);

    int* mid = midValue(arr, len);

    minMax(arr, len, &min, &max);
    printf(
        "The minimum value is %d and the maximum value is %d and the middle "
        "value is %d \n",
        min, max, *mid);

    return 0;
}