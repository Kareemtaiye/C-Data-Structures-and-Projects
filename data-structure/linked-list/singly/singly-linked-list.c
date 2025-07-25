#include <stdio.h>
#include <stdlib.h>

/* Creating a single linked list */

struct node {
    int data;
    struct node *link;
};

int main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));

    head->data = 43;
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 72;
    current->link = NULL;
    head->link = current;

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 100;
    current->link = NULL;

    head->link->link = current;

    printf("%d\n", head->data);
    printf("%d\n", head->link->data);

    return 0;
}