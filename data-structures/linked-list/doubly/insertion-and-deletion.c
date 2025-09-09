#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

// Adds the first element to an empty double linked list
void addToEmpty(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;

    *head = new_node;
}

// Adds to the beginnng of the doubly linked list.
void addToBeg(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = *head;

    // If there are more than one node in the list, i.e the list does not
    // contain only one element
    if ((*head)->next != NULL) {
        (*head)->prev = new_node;
    }

    *head = new_node;
}

// Adds to the end of the doubly linked list.

void addToEnd(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));

    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;

    // If list is empty
    if ((*head) == NULL) {
        *head = new_node;

        // If list contains only one node.
    } else if ((*head)->next == NULL) {
        (*head)->next = new_node;
        new_node->prev = *head;

        // Otherwise.
    } else {
        Node *ptr = *head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->prev = ptr;
    }
}

// Adds to any position of the doubly linked list.
void addToPos(Node **head, int data, int pos) {
    // If 0 or negative value is passed as position.
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;

    // If the list is empty
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Insert at position one
    if (pos == 1) {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
        return;
    }

    Node *ptr = *head;
    Node *prev_ptr = ptr;
    int i = 1;
    while (i < pos) {
        prev_ptr = ptr;
        ptr = ptr->next;
        i++;
    }

    // If position is last, Insert at end
    if (ptr == NULL) {
        prev_ptr->next = new_node;
        new_node->prev = prev_ptr;

    }
    // Insert in the middle
    else {
        new_node->next = ptr;
        new_node->prev = prev_ptr;
        ptr->prev = new_node;
        prev_ptr->next = new_node;
    }
}

// Better, handles position out of bound
void addToPos2(Node **head, int data, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    if (pos == 1) {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
        return;
    }

    Node *ptr = *head;
    Node *next_ptr = ptr->next;
    int i = 1;

    while (i < pos - 1 && ptr != NULL) {
        ptr = ptr->next;
        next_ptr = ptr != NULL ? ptr->next : NULL;
        i++;
    }

    if (ptr == NULL) {
        printf("Position (%d) out of bound\n", pos);
        free(new_node);
        return;
    }

    new_node->next = next_ptr;
    new_node->prev = ptr;
    ptr->next = new_node;
}

void delAtBeg(Node **head) {
    // List is empty.
    if (*head == NULL) {
        printf("Linked list is empty");
        return;
    }

    // List contains one element.
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node *temp = *head;
    Node *next = temp->next;
    (*head) = next;
    next->prev = *head;
    free(temp);
    temp = NULL;
}

void delAtEnd(Node **head) {
    // List is empty.
    if (*head == NULL) {
        printf("Linked list is empty");
        return;
    }

    // List contains one element.
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node *ptr = *head;
    Node *temp = ptr;
    while (ptr->next != NULL) {
        temp = ptr;
        ptr = ptr->next;
    }

    temp->next = NULL;
    free(ptr);
    ptr = NULL;
}

void delAtPos(Node **head, int pos) {
    // List is empty.
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    // Deleting the first node.
    if (pos == 1) {
        // Only one node.
        if ((*head)->next == NULL) {
            free(*head);
            *head = NULL;
            return;
        }

        Node *temp = *head;
        *head = temp->next;
        (*head)->prev = NULL;
        free(temp);
        return;
    }

    Node *prev_ptr = NULL;
    Node *ptr = *head;
    Node *next_ptr = ptr->next;
    int i = 1;

    // Traverse to the position.
    while (i < pos && ptr != NULL) {
        prev_ptr = ptr;
        ptr = ptr->next;
        next_ptr = ptr != NULL ? ptr->next : NULL;
        i++;
    }

    // If position is out of bounds
    if (ptr == NULL) {
        printf("Position (%d) out of bound\n", pos);
        return;
    }

    // Re-link the previous and next nodes
    if (next_ptr != NULL) {
        next_ptr->prev = prev_ptr;
    }

    prev_ptr->next = next_ptr;
    free(ptr);
}

int main() {
    Node *head = NULL;
    addToEmpty(&head, 1);
    addToBeg(&head, 2);
    addToEnd(&head, 3);
    addToPos2(&head, 4, 1);
    delAtBeg(&head);
    delAtEnd(&head);
    delAtPos(&head, 2);

    // Prints the nodes of the linked list.
    Node *ptr = head;
    while (ptr != NULL) {
        printf("%d %s ", ptr->data, ptr->next != NULL ? "->" : "");
        ptr = ptr->next;
    }
    return 0;
}