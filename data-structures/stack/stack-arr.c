#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// ARRAY implementation of stack
int top = -1;
int stack_arr[MAX];  // Instead of being passed into functions

int isEmpty();
int isFull();

void push(int data) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
};

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int val = stack_arr[top];
    top = top - 1;
    return val;
}

int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull() {
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

void printStack() {
    if (isEmpty()) {
        printf("Stack Empty\n");
        return;
    }
    for (int i = 0; i <= top; i++) {
        printf("[%d] ", stack_arr[i]);
    };
    printf("-> top\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    printStack();
    return 0;
}