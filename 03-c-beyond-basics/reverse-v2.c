#include <stdio.h>
#define N 5

int main() {
    int arr[N], *p;

    printf("Enter the elements for your array ");

    for (p = arr; p < arr + N; p++) {
        printf("Next: ");
        scanf("%d", p);
    }

    printf("Reversed: ");

    // Print the elements in reversed order
    for (p = arr + (N - 1); p > arr; p--) {
        printf("%d ", *p);
    }
    return 0;
}
