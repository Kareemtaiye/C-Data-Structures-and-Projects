#include <stdio.h>
#include <stdlib.h>

/*Implement dynamic array*/

typedef struct {
    int *data;  // pointer to the first el
    int size;
    int capacity;
} DynamicArray;

void initializeArr(DynamicArray *arr, int initialCapacity) {
    arr->data = (int *)malloc(sizeof(int) * initialCapacity);
    arr->size = 0;
    arr->capacity = initialCapacity;
}

void append(DynamicArray *arr, int data) {
    if (arr->capacity == arr->size) {
        int *temp = realloc(&arr->data, sizeof(arr->capacity) * 2);
        if (temp != NULL) {  // adj memory not avail and new block was allocated
            arr->data = temp;  // assign new addr to arr
        }
    }

    arr->data[arr->size++] = data;
}

void freeArr(DynamicArray *arr) {
    free(arr->data);
    arr->size = 0;
    arr->capacity = 0;
}

void printArr(DynamicArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int getArrLength(DynamicArray *arr) {  //clang-format off
    return arr->size;
}

int main() {
    DynamicArray arr;

    initializeArr(&arr, 4);
    append(&arr, 40);
    append(&arr, 50);

    printArr(&arr);
    printf("Length: %d", getArrLength(&arr));

    freeArr(&arr);

    printf("Length: %d", getArrLength(&arr));

    return 0;
}