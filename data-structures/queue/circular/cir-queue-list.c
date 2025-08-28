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
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    rear->next = front;
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
        rear->next = front;
    }

    free(temp);
    return val;
}

void display() {
    Node *ptr = front;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != front);
}

void freeQueue() {
    if (isEmpty()) return;

    // Breaks the circle.
    rear->next = NULL;

    Node *temp = front;
    Node *ptr;
    while (temp != NULL) {
        ptr = temp->next;
        free(temp);
        temp = ptr;
    }

    front = rear = NULL;
}
int main() {
    enqueue(100);
    enqueue(200);

    display();
    freeQueue();
    return 0;
}