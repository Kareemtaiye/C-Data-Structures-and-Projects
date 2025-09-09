#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/* Recursive creation of nodes */
Node *create() {
    int x;
    printf("Enter the value for the node(-1 to exit): ");
    scanf("%d", &x);

    if (x == -1) {
        return NULL;
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->data = x;

    printf("Enter the left value of %d: \n", x);
    new_node->left = create();

    printf("Enter the right value of %d: \n", x);
    new_node->right = create();

    return new_node;
}

// Pre-order traversal.
void preOrderTraversal(Node *root) {
    if (root == 0) {
        return;
    }

    printf("data: %d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    printf("\n");
};

// Post-order traversal.
void postOrderTraversal(Node *root) {
    if (root == 0) {
        return;
    }

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    printf("data: %d ", root->data);
    printf("\n");
};
// In-order traversal.
void inOrderTraversal(Node *root) {
    if (root == 0) {
        return;
    }

    preOrderTraversal(root->left);
    printf("data: %d ", root->data);
    preOrderTraversal(root->right);
    printf("\n");
};

int main() {
    Node *root = create();

    if (root == NULL) {
        printf("Tree is empty\n");
    } else {
        printf("left: %p data: %d right: %p\n", root->left, root->data,
               root->right);
    }

    printf("\n");

    preOrderTraversal(root);
    postOrderTraversal(root);
    inOrderTraversal(root);

    return 0;
}