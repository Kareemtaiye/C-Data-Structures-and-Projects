#include <stdio.h>
#include <stdlib.h>

/* With circular wrap */
typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

int isEmpty() {  //clang-format off
    return front == NULL && rear == NULL;
}

int getFront() {
    if (isEmpty()) {
        printf("Dequeue is empty");
        return -1;
    }

    return front->data;
}

int getRear() {
    if (isEmpty()) {
        printf("Dequeue is empty");
        return -1;
    }

    return rear->data;
}

void enqueuAtFront(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    if (new_node == NULL) {
        printf("Failed to allocate memory for node");
        return;
    }

    if (isEmpty()) {
        front = rear = new_node;
        front->next = rear;
        rear->prev = front;
    } else {
        new_node->next = front;
        new_node->prev = rear;
        rear->next = new_node;
        front->prev = new_node;
        front = new_node;
    }
}

void enqueueAtRear(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    if (new_node == NULL) {
        printf("Failed to allocate memory for node");
        return;
    }

    if (isEmpty()) {
        front = rear = new_node;
        front->next = rear;
        rear->prev = front;
    } else {
        new_node->next = front;
        new_node->prev = rear;
        rear->next = new_node;
        front->prev = new_node;
        rear = new_node;
    }
}

int dequeueAtFront() {
    int val = getFront();
    Node *temp = front;
    front = front->next;
    rear->next = front;
    front->prev = rear;
    free(temp);
    temp = NULL;
    return val;
}

int dequeueAtRear() {
    int val = getRear();
    Node *temp = rear;
    rear = temp->prev;
    rear->next = front;
    front->prev = rear;
    free(temp);
    temp = NULL;
    return val;
}

void display() {
    Node *ptr = front;

    printf("Front -> ");

    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != front);
    printf("<- Rear\n");
}

void freeMemory() {
    if (isEmpty()) return;

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
    enqueuAtFront(100);
    enqueuAtFront(200);
    enqueuAtFront(50);
    enqueueAtRear(50);
    display();
    printf("Delete: %d\n", dequeueAtFront());
    printf("Delete: %d\n", dequeueAtRear());
    printf("Delete: %d\n", dequeueAtRear());
    display();

    return 0;

    freeMemory();
}