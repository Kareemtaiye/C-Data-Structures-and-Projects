#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} Node;

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

void addAtPos(Node* head, int pos, int data) {
    Node* ptr = head;
    Node* temp = (Node*)malloc(sizeof(Node));

    int n = 1;
    while (n < pos - 1) {
        ptr = ptr->link;
        n++;
    }
    temp->data = data;
    temp->link = ptr->link;
    ptr->link = temp;
};

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    Node* ptr = (Node*)malloc(sizeof(Node));

    head = addAtBeg(NULL, 10);

    ptr = head;
    head = addAtBeg(head, 20);
    ptr = addAtEnd(ptr, 30);
    addAtPos(head, 3, 50);
    printNodes(head);
}