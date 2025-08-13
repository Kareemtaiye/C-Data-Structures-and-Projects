#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *link;
} Node;

Node *top = NULL;

void push(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;

    new_node->link = top;
    top = new_node;
}

int isEmpty() {
    if (top == NULL)
        return 1;
    else
        return 0;
}

int pop(int data) {
    if (isEmpty()) {
        printf("Stack underflow\n");
    }

    int value = top->data;
    Node *temp = top;
    top = top->link;
    free(temp);

    return value;
}

void printStack() {
    if (top == NULL) {
        return;
    }
    printf("top -> ");
    Node *ptr = top;
    while (ptr != NULL) {
        printf("[%d] ", ptr->data);
        ptr = ptr->link;
    }
}

int main() {
    push(20);
    push(40);
    printStack();

    return 0;
}