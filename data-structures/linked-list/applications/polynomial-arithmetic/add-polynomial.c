#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float coeff;
    int exp;
    struct Node *next;
} Node;

void freeList(Node *head) {
    Node *ptr;
    while (head != NULL) {
        ptr = head;
        head = head->next;
        free(ptr);
    }
}

void printExpression(Node *head) {
    if (head == NULL) return;
    Node *ptr = head;
    int first = 1;
    while (ptr != NULL) {
        printf("%s%.fx^%d",
               ptr->coeff >= 0 && !first  ? " + "
               : first && ptr->coeff >= 0 ? " "
                                          : " - ",
               fabs(ptr->coeff), ptr->exp);

        ptr = ptr->next;
        if (first == 1) first = 0;
    }
}

// Inserts new polynomail Node at the end of a polynomial expression list.
void insert(Node **head, float coeff, int exp) {
    Node *new_node = malloc(sizeof(Node));

    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;
    // List is empty.
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *ptr = *head;
    while (ptr->next != NULL) ptr = ptr->next;

    ptr->next = new_node;
}

Node *add(Node *head1, Node *head2) {
    // iF One list is empty, return the other;
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node *result = NULL;
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->exp == ptr2->exp) {
            insert(&result, ptr1->coeff + ptr2->coeff, ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->exp > ptr2->exp) {
            insert(&result, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        } else if (ptr1->exp < ptr2->exp) {
            insert(&result, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }

    if (ptr1 == NULL) {
        while (ptr2 != NULL) {
            insert(&result, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }

    if (ptr2 == NULL) {
        while (ptr1 != NULL) {
            insert(&result, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        }
    }

    return result;
}

void createPolyTerm(Node **head, int coeff, int exp) {
    if (coeff == 0) return;

    Node *new_node = malloc(sizeof(Node));
    new_node->coeff = coeff;
    new_node->exp = exp;

    if (*head == NULL) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *ptr = *head;
    Node *prev_ptr = NULL;

    while (ptr != NULL && ptr->exp > exp) {
        prev_ptr = ptr;
        ptr = ptr->next;
    }

    if (ptr != NULL && ptr->exp == exp) {
        ptr->coeff += coeff;
        free(new_node);
        return;
    }

    if (prev_ptr == NULL) {
        new_node->next = ptr;
        *head = new_node;
        return;
    }

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
    Node *head1 = NULL;
    Node *head2 = NULL;
    head1 = createPolyExpression(head1);
    head2 = createPolyExpression(head2);

    Node *result = add(head1, head2);

    printf("Expression 1: ");
    printExpression(head1);

    printf("\nExpression 2: ");
    printExpression(head2);

    printf("\nResult: ");
    printExpression(result);

    // Return memory to OS.
    freeList(head1);
    freeList(head2);
    freeList(result);
    return 0;
}