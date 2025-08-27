#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

int isEmpty() {  // clang-format off
   return front == -1 && rear == -1;
}

int isFull() {
    return (rear + 1) % N == front;
}


void enqueue(int data) {
    if(isEmpty()) {
        front = rear = 0;
        queue[rear] = data;
    } else if(isFull()) {
        printf("Overflow\n");
    } else {
        rear = (rear + 1) % N;
        queue[rear] = data;
    }
}


int dequeue() {
    if(isEmpty()) return -1;
    int val = queue[front];
    front = (front +1 ) % N;
    return val;
}


int peek() {
    return queue[rear];
}

void display() {
    int i;
    printf("Front -> ");
    for(i = front; i != rear; i = (i + 1) % N) {
        printf("%d ", queue[i]);
    }
    printf("%d <- Rear", queue[i]);
}


int main() {
    enqueue(100);
    enqueue(200);
    enqueue(300);
    enqueue(400);
    enqueue(500);
    dequeue();
    dequeue();
    enqueue(900);
    enqueue(900);

    display();
}