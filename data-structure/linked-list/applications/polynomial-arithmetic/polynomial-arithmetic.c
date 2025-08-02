#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float coeff;
    int exp;
    struct Node *next;
} Node;

void printExpression(Node *head) {
    if (head == NULL) return;
    Node *ptr = head;
    while (ptr->next != NULL) {
        float c = ptr->coeff;
        int e = ptr->exp;
        Node *n = ptr->next;
        printf("%s%.fx^%d ", c > 0 ? "+" : "-", c < 0 ? (c * 2) - c : c, e);
        ptr = n;
    }
    float c = ptr->coeff;
    int e = ptr->exp;
    printf("%s%.fx^%d", c > 0 ? "+" : "-", c < 0 ? (c * 2) - c : c, e);
}

void createPolyTerm(Node **head, int coeff, int exp) {
    if (coeff == 0) return;

    Node *new_node = malloc(sizeof(Node));
    new_node->coeff = coeff;
    new_node->exp = exp;

    // list is empty
    if (*head == NULL) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // // List contains one element
    // if ((*head)->next == NULL && (*head)->exp < exp) {
    //     new_node->next = *head;
    //     *head = new_node;
    //     return;
    // }

    Node *ptr = *head;
    Node *prev_ptr = NULL;

    // Traverse to find correct position or existing exponent
    while (ptr != NULL && ptr->exp > exp) {
        prev_ptr = ptr;
        ptr = ptr->next;
    }

    // If exponent already exists, add coefficients
    if (ptr != NULL && ptr->exp == exp) {
        ptr->coeff += coeff;
        free(new_node);
        return;
    }

    // The list contains one node is the exponent is less than the new node
    if (prev_ptr == NULL) {
        new_node->next = ptr;
        *head = new_node;
        return;
    }

    // Insert new_node between prev_ptr and ptr
    new_node->next = ptr;
    prev_ptr->next = new_node;
}

Node *createPolyExpression(Node *head) {
    printf("Enter the number of terms for the expressions: ");
    int n, exp, coeff, i = 0;

    scanf("%d", &n);
    if (n < 1) return NULL;

    while (i < n) {
        printf("Enter the coefficient of the variable of term %d: ", i + 1);
        scanf("%d", &coeff);

        printf("Enter the exponent of the variable of term %d: ", i + 1);
        scanf("%d", &exp);

        createPolyTerm(&head, coeff, exp);
        i++;
    }

    return head;
}

int main() {
    Node *head = NULL;
    head = createPolyExpression(head);

    printExpression(head);

    return 0;
}