#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

void freeList(Node *tail) {
    if (tail == NULL) return;

    Node *ptr = tail->next;
    Node *temp = ptr;

    while (ptr != tail) {
        free(temp);
        ptr = ptr->next;
        temp = ptr;
    }

    free(tail);
}

void print(Node *tail) {
    if (tail == NULL) return;

    Node *ptr = tail->next;
    do {
        printf("%d %s ", ptr->data, ptr != tail ? "->" : "");
        ptr = ptr->next;
    } while (ptr != tail->next);
}

// Creates a circular doubly linked list.
Node *createCircularList(Node *tail) {
    printf("Number of nodes to create: ");

    int n, i = 0, data = 0;
    scanf("%d", &n);

    if (n < 1) return NULL;

    while (i < n) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);

        Node *new_node = malloc(sizeof(Node));
        new_node->data = data;

        if (i == 0) {
            new_node->next = new_node;
            new_node->prev = new_node;
            tail = new_node;
        } else {
            new_node->next = tail->next;
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }

        i++;
    }

    return tail;
}

void insertAtBeg(Node **tail, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;

    // If list is empty.
    if (*tail == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        *tail = new_node;
        return;
    }

    new_node->next = (*tail)->next;
    new_node->prev = *tail;
    (*tail)->next = new_node;
};

void insertAtEnd(Node **tail, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    // If list is empty.
    if (*tail == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        *tail = new_node;
        return;
    }

    new_node->next = (*tail)->next;
    new_node->prev = *tail;
    (*tail)->next = new_node;
    (*tail) = new_node;
}

void insertAtPos(Node **tail, int data, int pos) {
    // List is empty and position is not the first.
    if (pos > 1 && (*tail) == NULL) {
        printf("List is empty. Cannot insert at position (%d)\n", pos);
        return;
    }

    if (pos == 1) {
        insertAtBeg(tail, data);
        return;
    }

    Node *ptr = (*tail)->next;
    int i = 1;

    while (i < pos - 1 && ptr->next != (*tail)->next) {
        ptr = ptr->next;
        i++;
    };

    // Position greater than last + 1 node.
    if (i < pos - 1) {
        printf("Position (%d) out of bound\n", pos);
        return;
    }

    // If position is last + 1.
    if (ptr == *tail) {
        insertAtEnd(tail, data);
        return;
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = ptr->next;
    new_node->prev = ptr;
    ptr->next = new_node;
}

void delAtBeg(Node **tail) {
    if (*tail == NULL) return;  // list is empty.

    if ((*tail)->next == *tail) {  // Contains one node;
        free(*tail);
        *tail = NULL;
        return;
    };

    Node *temp = (*tail)->next;
    (*tail)->next = temp->next;
    temp->next->prev = (*tail);
    free(temp);
    temp = NULL;
}

void delAtEnd(Node **tail) {
    if (*tail == NULL) return;  // list is empty.

    if ((*tail)->next == *tail) {  // Contains one node;
        free(*tail);
        *tail = NULL;
        return;
    };

    Node *temp = *tail;
    (*tail)->prev->next = temp->next;
    temp->next->prev = (*tail)->prev;
    *tail = temp->prev;
    free(temp);
    temp = NULL;
}

void delAtPos(Node **tail, int pos) {
    if (*tail == NULL) return;  // list is empty.

    if (pos == 1) {
        delAtBeg(tail);
        return;
    }

    Node *ptr = (*tail)->next;
    int i = 1;
    while (i < pos - 1 && ptr->next != (*tail)) {
        ptr = ptr->next;
        i++;
    }

    // If position is out of bound.
    if (i < pos - 1) {
        printf("Position (%d) out of bound\n", pos);
        return;
    }

    // If position is last
    if (ptr->next == *tail) {
        delAtEnd(tail);
        return;
    }

    // Ptr is just before the position of the node to be deleted.
    Node *temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
    temp = NULL;
}

int main() {
    Node *tail = NULL;

    tail = createCircularList(tail);
    insertAtBeg(&tail, 1);
    insertAtEnd(&tail, 4);
    insertAtPos(&tail, 5, 5);
    delAtBeg(&tail);
    delAtEnd(&tail);
    delAtEnd(&tail);
    delAtPos(&tail, 4);
    print(tail);

    // Returns memory back to OS.
    freeList(tail);
}