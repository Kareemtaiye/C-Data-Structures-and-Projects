#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    int val = 30;
    int *v = &val;

    // &*val = &val

    int *p = arr;  // The address of arr[1];

    int (*p)[5] = &arr;  // Pointer to the whole array of 5 integer elements;

    //
    // &*p = p

    return 0;
}