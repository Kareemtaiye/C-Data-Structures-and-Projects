#include <stdio.h>
#define ARRAY_LEN(x) sizeof(x) / sizeof((x)[0])

int* reverse(int arr[], int len) {
    static int result[1000];

    for (int i = 0; i < len; i++) {
        result[i] = arr[len - 1 - i];
    }

    return result;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    int arr_len = ARRAY_LEN(arr);
    int* reversed = reverse(arr, arr_len);

    printf("Original: ");
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nReversed: ");
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", reversed[i]);
    }

    return 0;
}