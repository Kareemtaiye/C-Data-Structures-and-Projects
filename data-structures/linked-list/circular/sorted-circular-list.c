#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

// Free the nodes in the list
void freeList(Node *tail) {
    if (tail == NULL) {
        return;
    }

    Node *ptr = tail->next;
    Node *temp = ptr;

    while (ptr != tail) {
        ptr = ptr->next;
        free(temp);
        temp = ptr;
    }

    free(tail);
}

void print(Node *tail) {
    Node *ptr = tail->next;
    do {
        printf("%d %s ", ptr->data, ptr != tail ? "->" : "");
        ptr = ptr->next;
    } while (ptr != tail->next);
}

void insertNode(Node **tail, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;

    // If list is empty.
    if (*tail == NULL) {
        new_node->prev = new_node;
        new_node->next = new_node;
        *tail = new_node;
        return;
    }

    Node *ptr = (*tail)->next;

    while (ptr != *tail && ptr->data < data) {
        ptr = ptr->next;
    };

    // If data is greater than all node data.
    if (ptr == *tail && ptr->data < data) {
        new_node->next = ptr->next;
        new_node->prev = ptr;
        ptr->next->prev = new_node;
        ptr->next = new_node;
        *tail = new_node;
        return;
    }

    // Insert node before current node.
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;
}

// Creates a sorted circular doubly linked list.
Node *createSortedList(Node *tail) {
    printf("Number of nodes to create: ");

    int n, i = 0, data = 0;
    scanf("%d", &n);

    // If nodes number is 0 or negatice.
    if (n < 1) return NULL;

    while (i < n) {
        printf("Enter the data for node : %d ", i + 1);
        scanf("%d", &data);

        insertNode(&tail, data);
        i++;
    }

    return tail;
}

int main() {
    Node *tail = NULL;
    tail = createSortedList(tail);

    print(tail);
    freeList(tail);
}