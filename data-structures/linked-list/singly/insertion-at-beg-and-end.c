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

    if (tail != NULL) {
        tail->link = new_node;
    }

    return new_node;
}

Node* addAtBeg(Node* head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->link = head;

    return new_node;
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    Node* ptr = (Node*)malloc(sizeof(Node));

    head = addAtEnd(NULL, 10);
    ptr = head;

    ptr = addAtEnd(ptr, 20);
    ptr = addAtEnd(ptr, 30);
    head = addAtBeg(head, 5);
    head = addAtBeg(head, 1);
    printNodes(head);

    return 0;
}