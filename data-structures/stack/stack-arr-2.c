#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int first = -1;
int stack_arr[MAX];  // Making the first element the top;

int isEmpty();
int isFull();

void push(int data) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    for (int i = first; i >= 0; i--) {
        stack_arr[i + 1] = stack_arr[i];
    }
    stack_arr[0] = data;
    first = first + 1;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int value = stack_arr[0];
    for (int i = 1; i <= first; i++) {
        stack_arr[i - 1] = stack_arr[i];
    }
    first = first - 1;
    return value;
};

int isEmpty() {
    if (first == -1)
        return 1;
    else
        return 0;
}

int isFull() {
    if (first == MAX - 1)
        return 1;
    else
        return 0;
}

void printStack() {
    if (isEmpty()) return;

    printf("top -> ");
    for (int i = 0; i <= first; i++) {
        printf("[%d] ", stack_arr[i]);
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    pop();
    printStack();
    return 0;
};