#include <stdio.h>
#define N 5
int dequeue[N];
int front = -1;
int rear = -1;

int isFull() {  // clang-format off
    return (front == 0 && rear == N -1) || front == rear + 1;
}
int isEmpty() {
    return front == -1 && rear == -1;
}

int getFront() {
    return dequeue[front];
}

int getRear() {
    return dequeue[rear];
}

// clang-format on
void enqueueFront(int data) {
    if (isFull()) {
        printf("Dequeue is full");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = N - 1;
    } else {
        front--;
    }
    dequeue[front] = data;
}

void enqueueRear(int data) {
    if (isFull()) {
        printf("Dequeue is full");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == N - 1) {
        rear = 0;
    } else {
        rear++;
    }
    dequeue[rear] = data;
}

int dequeueFront() {
    if (isEmpty()) {
        printf("Dequeue is empty");
        return -1;
    }

    int val = getFront();
    if (front == rear) {
        front = rear = -1;
    } else if (front == N - 1) {
        front = 0;
    } else {
        front++;
    }
    return val;
}

int dequeueRear() {
    if (isEmpty()) {
        printf("Dequeue is empty");
        return -1;
    }

    int val = getRear();

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = N - 1;
    } else {
        rear--;
    }

    return val;
}

void display() {
    if (isEmpty()) {
        printf("Dequeue is empty");
        return;
    }

    printf("Front ->");

    int i;
    for (i = front; i != rear; i = (i + 1) % N) {
        printf("%d ", dequeue[i]);
    }
    printf("%d ", dequeue[i]);
    printf("<- Rear");
}

int main() {
    enqueueRear(100);
    enqueueRear(200);

    display();

    return 0;
}