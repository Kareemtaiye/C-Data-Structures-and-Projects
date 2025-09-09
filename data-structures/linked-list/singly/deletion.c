#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} Node;

// Deletes Node at the end(last node)
// Using two pointers
void delEnd(Node* head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else if (head->link == NULL) {  // Single node
        free(head);  // Wont work here since head is passed here by value
    }

    else {
        Node* temp = head;
        Node* temp2 = head;

        while (temp->link != NULL) {
            temp2 = temp;
            temp = temp->link;
        }

        free(temp);
        temp = NULL;
        temp2->link = NULL;
    }
};

// Using a pointer(better perfomance)
void delEndBetter(Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
    } else if ((*head)->link == NULL) {
        free(*head);
    } else {
        Node* temp = *head;
        while (temp->link->link != NULL) {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
}

// Deletes Node at the beginning(first node)
void delBeg(Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
    } else {
        Node* temp = *head;
        *head = temp->link;
        free(temp);
        temp = NULL;
    }
}

// Deletes a node from a position
void delPos(Node** head, int pos) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
    } else if (pos < 1) {
        printf("Not a valid list position");
    } else if (pos == 1) {
        Node* ptr = *head;
        *head = (*head)->link;
        free(ptr);
    } else {
        Node* current = *head;
        Node* previous = *head;
        int i = 1;
        while (i < pos) {
            previous = current;
            current = current->link;
            i++;
        };

        if (current == NULL) {
            printf("Position (%d) out of bound\n", pos);
        } else {
            previous->link = current->link;
            free(current);
        }
    }
}

// Deletes the linked list
void delList(Node** head) {
    Node* temp = *head;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->link;
        free(temp);
    }
}

// Adds Node at the beginning(first node)
Node* addToBeg(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = head;
    return newNode;
}

// Adds Node at the end(last node)
Node* addToEnd(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* ptr = head;
    newNode->data = data;
    newNode->link = NULL;

    if (head == NULL) {
        return newNode;
    }

    while (ptr->link != NULL) {
        ptr = ptr->link;
    };
    ptr->link = newNode;

    return newNode;
}

int main() {
    Node* head = NULL;
    Node* ptr_t = NULL;
    head = addToBeg(head, 10);

    ptr_t = head;

    head = addToBeg(head, 20);
    ptr_t = addToEnd(ptr_t, 40);
    ptr_t = addToEnd(ptr_t, 50);

    delBeg(&head);
    delEnd(head);
    delEndBetter(&head);
    delPos(&head, 2);

    delList(&head);

    // Prints nodes of the linked List;
    Node* ptr = head;  // Traverses the list
    while (ptr != NULL) {
        printf("%d %s ", ptr->data, ptr->link != NULL ? "->" : "");
        ptr = ptr->link;
    }
}