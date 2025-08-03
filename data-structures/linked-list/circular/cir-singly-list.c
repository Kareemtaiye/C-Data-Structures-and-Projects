#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    // struct Node *prev;
    int data;
    struct Node *next;
} Node;

// Free up memory.
void freeList(Node *tail) {
    if (tail == NULL) return;

    Node *curr = tail->next;
    Node *next;
    while (curr != tail) {
        next = curr->next;
        free(curr);
        curr = next;
    }

    free(tail);
}

// Prints the nodes from any point in the list.
void print(Node *tail) {
    if (tail == NULL) {
        printf("NULL");
        return;
    }
    Node *ptr = tail->next;

    while (ptr != tail) {
        printf("%p: %d %s ", ptr, ptr->data, ptr->next != tail ? "->" : "");
        ptr = ptr->next;
    };
    printf("%p: %d ", ptr, ptr->data);
}

Node *createCircularList(Node *tail) {
    printf("Number of nodes you want to create: ");
    int n, i = 0, data = 0;
    scanf("%d", &n);

    if (n < 1) {
        return NULL;
    }

    Node *temp = NULL;
    while (i < n) {
        printf("Enter the value for node %d: ", i + 1);
        scanf("%d", &data);

        Node *new_node = malloc(sizeof(Node));
        temp = tail;

        if (i == 0) {
            tail = new_node;
            tail->next = new_node;
        } else {
            new_node->next = temp->next;
            temp->next = new_node;
            tail = new_node;
        }
        new_node->data = data;
        i++;
    }

    return tail;
}

// Inserts a node at the beginning of the curcular linked list.
void insertAtBeg(Node **tail, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = (*tail)->next;
    (*tail)->next = new_node;
}

// Inserts a node at the end of the curcular linked list.
void insertAtEnd(Node **tail, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = (*tail)->next;
    (*tail)->next = new_node;
    (*tail) = new_node;
}

// Inserts a node at a position of the curcular linked list.

void insertAtPos(Node **tail, int data, int pos) {
    // If position is first.
    if (pos == 1) {
        insertAtBeg(tail, data);
        return;
    }

    if (*tail == NULL) {
        printf("List is empty. Cannot insert at position (%d)\n", pos);
        return;
    }

    Node *ptr = (*tail)->next;
    int i = 1;

    while (i < pos - 1 && ptr != (*tail)) {
        ptr = ptr->next;
        i++;
    }

    // If position is out of bound
    if (i < pos - 1) {
        printf("Position (%d) out of bound\n", pos);
        return;
    }

    // If position is last
    if (ptr == *tail) {
        insertAtEnd(tail, data);
        return;
    }

    Node *new_node = malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = data;
    new_node->next = ptr->next;
    ptr->next = new_node;
}

// Counts the nodes in the list
int count(Node *tail) {
    Node *ptr = tail;
    if (tail == NULL) return 0;

    int count = 0;

    do {
        ptr = ptr->next;
        count++;
    } while (ptr != tail);

    return count;
}

// Searches for a node by data and returns the position.
int findNode(Node *tail, int data) {
    Node *ptr = tail->next;
    int pos = 1;
    if (tail == NULL) return 0;  // empty list.

    while (ptr != tail) {
        if (ptr->data == data) {
            return pos;
        }
        ptr = ptr->next;
        pos++;
    };

    // if its the last element;
    if (ptr->data == data) {
        return pos;
    }

    return -1;  // if node is not found
}

int main() {
    Node *tail = NULL;
    tail = createCircularList(tail);
    insertAtEnd(&tail, 5);
    insertAtBeg(&tail, 0);
    insertAtPos(&tail, 100, 6);
    int num_nodes = count(tail);
    int node_pos = findNode(tail, 1010);

    // prints from the node specified.
    // print(tail->next->next);

    // prints circular linked list.
    printf("Number of nodes: %d\n", num_nodes);
    printf("Position of node: %d\n", node_pos);
    print(tail);

    // Return the memory back to OS
    freeList(tail);
}