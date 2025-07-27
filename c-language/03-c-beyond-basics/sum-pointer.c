#include <stdio.h>

int sumInt(int *b, int len) {
    int sum = 0, i;
    for (i = 0; i < len; i++) {
        sum = sum + b[i];
    }
    return sum;
}

int main() {
    int arr[] = {2, 3, 4, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    int sum = sumInt(arr, len);

    // for (p = &arr[0]; p < &arr[len]; p++) {
    //     sum += *p;
    // }

    // New program
    // for (sum = arr; sum < arr + len; sum++) {
    //     sum += sum;
    // }

    printf("Sum: %d\n", sum);

    return 0;
}