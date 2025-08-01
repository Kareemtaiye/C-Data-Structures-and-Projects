#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

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

    if (ptr == *tail && ptr->data < data) {
        new_node->next = ptr->next;
        new_node->prev = ptr;
        ptr->next->prev = new_node;
        ptr->next = new_node;
        *tail = new_node;
        return;
    }

    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;
}

Node *createSortedList(Node *tail) {
    printf("Number of nodes to create: ");

    int n, i = 0, data = 0;
    scanf("%d", &n);

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