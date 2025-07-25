#include <stdio.h>
#include <stdlib.h>

// Here and on, we are defining our structure type as Node.
typedef struct Node {
    int data;
    struct Node* link;
} Node;

int countNodes(Node* head) {
    Node* ptr = head;
    int sum = 0;

    while (ptr != NULL) {
        sum++;
        ptr = ptr->link;
    }
    return sum;
}

void printNodes(Node* head) {
    Node* ptr = head;

    while (ptr != NULL) {
        printf("%d %s ", ptr->data, ptr->link == NULL ? "" : "->");
        ptr = ptr->link;
    }
}

// Runtime O(1). Building the linked list from scratch
Node* addAtEnd(Node* tail, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->link = NULL;
    new_node->data = data;

    tail->link = new_node;
    return new_node;
}

Node* addAtBeg(Node* head, int data) {
    Node* tail = (Node*)malloc(sizeof(Node));
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    Node* tail = (Node*)malloc(sizeof(Node));

    Node* first = (Node*)malloc(sizeof(Node));
    first->data = 10;
    first->link = NULL;

    head->link = first;
    tail = head;

    tail = addAtEnd(tail, 10);
    printNodes(head);

    return 0;
}