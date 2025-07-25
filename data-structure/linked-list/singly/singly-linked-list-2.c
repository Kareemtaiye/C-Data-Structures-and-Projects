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

int main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 55;
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 100;
    current->link = NULL;
    head->link = current;

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 150;
    current->link = NULL;

    head->link->link = current;

    int node_count = countNodes(head);

    printNodes(head);

    printf("\nNumber of nodes: %d", node_count);
}