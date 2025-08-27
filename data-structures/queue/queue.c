#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

int isEmpty() {  //clang-format off
    if ((front == -1 && rear == -1))
        return 1;
    else
        return 0;
}

int isFull() {  //clang-format off
    return rear == N - 1;
}

int getPeek() {  //clang-format off
    return queue[rear];
}

int getFront() {  //clang-format off
    return queue[front];
}

void enqueue(int data) {
    if (isFull()) {
        printf("Overflow\n");
    } else if (isEmpty()) {
        front = rear = 1;
        queue[rear] = data;
    } else {
        queue[++rear] = data;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Underflow\n");
        return -1;
    } else if (front == rear) {
        int val = queue[front];
        front = rear = -1;
        return val;
    } else {
        return queue[front++];
    }
}

int main() {
    printf(
        "1. Add data to queue\n"
        "2. Remove data from queue\n"
        "3. Print queue\n"
        "4. Get data at the front of queue\n"
        "5. Get data at the back of queue\n"
        "6. Exit the program\n");

    int n;
    while (n != 6) {
        printf("Enter your option: ");
        scanf("%d", &n);
        int data;
        switch (n) {
            case 1:
                printf("Enter data to add: >> ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                printf("Removed: >> %d \n", dequeue());
                break;
            case 3:
                if (isEmpty()) {
                    printf("Queue is empty");
                } else {
                    printf("Queue: >> ");
                    for (int i = front; i <= rear; i++) {
                        printf("%d ", queue[i]);
                    }
                }
                printf("\n");
                break;
            case 4:
                if (isEmpty())
                    printf("Queue is empty\n");
                else
                    printf("Front: >> %d \n", getFront());

                break;

            case 5:
                if (isEmpty())
                    printf("Queue is empty\n");
                else
                    printf("Rear: >> %d \n", getPeek());
                break;
            case 6:
                printf("Exiting program....\n");
                break;
                ;

            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}