#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *create() {
    Node *new_node = malloc(sizeof(Node));
    int x;
    printf("Enter the value for the node(-1 to exit): ");
    scanf("%d", &x);

    if (x == -1) {
        return NULL;
    }

    new_node->data = x;

    printf("Enter the left value of %d: \n", x);
    new_node->left = create();

    printf("Enter the right value of %d: \n", x);
    new_node->right = create();

    return new_node;
}

int main() {
    Node *root = create();

    if (root == NULL) {
        printf("Tree is empty\n");
    } else {
        printf("left: %p data: %d right: %p\n", root->left, root->data,
               root->right);
    }
    return 0;
}