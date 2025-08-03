#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *link;
} Node;

Node *reverse(Node *head) {
    if (head == NULL)
        return head;
    else if (head->link == NULL)
        return head;
    else {
        Node *current = head;
        Node *ptr = head;
        head = NULL;

        while (ptr->link != NULL) {
            ptr = ptr->link;
            current->link = head;
            head = current;
            current = ptr;
        }

        current->link = head;
        head = current;
        return head;
    }
}

void reverse2(Node **head) {
    if (*head == NULL)
        printf("Linked list is empty\n");
    else if ((*head)->link == NULL)
        printf("Linked list contains one element\n");
    else {
        Node *current = *head;
        Node *ptr = *head;
        *head = NULL;

        while (ptr->link != NULL) {
            ptr = ptr->link;
            current->link = *head;
            *head = current;
            current = ptr;
        }
        current->link = *head;
        *head = current;
    }
}

Node *addToBeg(Node *head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = head;
    return newNode;
}

int main() {
    Node *head = (Node *)malloc(sizeof(Node));
    head = addToBeg(NULL, 40);
    head = addToBeg(head, 30);
    head = addToBeg(head, 20);
    head = addToBeg(head, 10);

    head = reverse(head);
    reverse2(&head);

    // Prints nodes of the linked List;
    Node *ptr = head;  // Traverses the list
    while (ptr != NULL) {
        printf("%d %s ", ptr->data, ptr->link != NULL ? "->" : "");
        ptr = ptr->link;
    }

    return 0;
}