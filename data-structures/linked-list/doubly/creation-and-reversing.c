#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

// Creates a doubly linked list.
Node *createList(Node *head) {
    int n, i, data;
    printf("Enter the number of elemnents for the list: ");
    scanf("%d", &n);

    Node *temp = NULL;
    i = 0;
    while (i < n) {
        printf("Enter the data for Node: %d ", i + 1);
        scanf("%d", &data);

        Node *new_node = malloc(sizeof(Node));

        if (i == 0) {
            new_node->prev = NULL;
            head = new_node;
            temp = head;
        } else {
            temp->next = new_node;
            new_node->prev = temp;
            temp = new_node;
        }
        new_node->next = NULL;
        new_node->data = data;
        i++;
    }

    return head;
}

void reverse(Node **head) {
    Node *prev_ptr = NULL;
    Node *ptr = *head;
    Node *next_ptr = ptr->next;

    while (ptr->next != NULL) {
        ptr->prev = ptr->next;
        ptr->next = prev_ptr;
        prev_ptr = ptr;
        ptr = next_ptr;
        next_ptr = ptr->next;
    }

    (*head) = ptr;
    (*head)->next = prev_ptr;
    (*head)->prev = NULL;
}

int main() {
    Node *head = NULL;
    head = createList(head);

    printf("Original list \n");

    // Prints the list
    Node *ptr = head;
    // printf("Pointer address: \n");
    // while (ptr != NULL) {
    //     printf("%p %s ", &ptr, ptr->next != NULL ? "->" : "");
    //     ptr = ptr->next;
    // }

    // ptr = head;
    printf("Node addresses: \n");
    while (ptr != NULL) {
        printf("%p: %d %s ", ptr, ptr->data, ptr->next != NULL ? "->" : "");
        ptr = ptr->next;
    }

    reverse(&head);
    printf("\nReversed list \n");

    // Prints the list
    ptr = head;
    printf("Node addresses: \n");
    while (ptr != NULL) {
        printf("%p: %d %s ", ptr, ptr->data, ptr->next != NULL ? "->" : "");
        ptr = ptr->next;
    }
}