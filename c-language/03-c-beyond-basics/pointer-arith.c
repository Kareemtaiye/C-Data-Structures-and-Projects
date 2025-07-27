#include <stdio.h>

int main() {
    /* Assuming integer takes 4 bytes */
    int arr[] = {2, 3, 5, 6, 8, 9, 10};
    int *p = &arr[0];
    int *q = &arr[4];

    printf("Value: %d, Address: %p\n", *p, p);
    printf("Value: %d, Address: %p\n", *(p + 1), p + 1);
    printf("Value: %d, Address: %p\n", *(p + 2), p + 2);

    printf("\nValue: %d, Address: %p\n", *q, q);
    printf("Value: %d, Address: %p\n", *(q - 1), q - 1);
    printf("Value: %d, Address: %p\n", *(q - 2), q - 2);

    printf("\nValue: %d, Address: %ld\n", *p - *q, p - q);
    printf("Value: %d, Address: %ld\n", *q - *p, q - p);
}