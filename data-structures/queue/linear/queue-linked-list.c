#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

int isEmpty() { return front == NULL && rear == NULL; }

void enqueue(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;

    if (isEmpty()) {
        new_node->next = NULL;
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

int dequeue() {
    if (isEmpty()) {
        return -1;
    }

    Node *temp = front;
    int val = temp->data;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    free(temp);
    return val;
}

Node *peek() {
    if (isEmpty()) return NULL;
    return rear;
}

void printQueue() {
    int i;
    Node *ptr = front;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void freeQueue() {
    Node *temp = front;
    Node *ptr;
    while (temp != NULL) {
        ptr = temp->next;
        free(temp);
        temp = ptr;
    }
}

int main() {
    enqueue(100);
    enqueue(200);
    dequeue();
    printQueue();

    freeQueue();
    return 0;
}