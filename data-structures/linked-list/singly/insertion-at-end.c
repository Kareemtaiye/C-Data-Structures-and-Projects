#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

int countNodes(struct node *head) {
    struct node *ptr = head;
    int sum = 0;

    while (ptr != NULL) {
        sum++;
        ptr = ptr->link;
    }
    return sum;
}

void printNodes(struct node *head) {
    struct node *ptr = head;

    while (ptr != NULL) {
        printf("%d %s ", ptr->data, ptr->link == NULL ? "" : "->");
        ptr = ptr->link;
    }
}

// Runtime: O(n)
void addNodeToEnd(struct node *head, int data) {
    struct node *ptr = head;  // Tail pointer
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    while (ptr->link != NULL) {
        ptr = ptr->link;
    }

    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
}

int main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 20;
    current->link = NULL;

    head->link = current;

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 30;
    current->link = NULL;

    head->link->link = current;

    addNodeToEnd(head, 40);

    printf("The sum of nodes: %d\n", countNodes(head));
    printNodes(head);
}