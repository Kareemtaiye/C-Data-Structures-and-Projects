#include <stdio.h>
#include <stdlib.h>

int* reverse(int arr[], int len) {
    int* result = malloc(len * sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = len - 1; i >= 0; i--) {
        result[len - 1 - i] = arr[i];
    }

    return result;
}

int main() {
    printf("Enter the length of the array: ");
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the elements %d: ", i + 1);
        scanf("%d ", &arr[i]);
    }
    int* reversed = reverse(arr, n);

    if (reversed == NULL) {
        // Allocation failed; exit early
        return 1;
    }

    printf("Original: ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }

    printf("\nReversed: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", reversed[i]);
    }

    free(reversed);

    return 0;
}