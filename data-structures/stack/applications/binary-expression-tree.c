#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Node {
    struct Node *left;
    char int_node;
    struct Node *right;

} Node;

Node *stack[MAX];
int top = -1;

int isEmpty() {  //clang-format off
    return top == -1;
}

void push(Node *data) {  //clang-format off
    stack[++top] = data;
}

Node *pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return NULL;
    }
    return stack[top--];
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void convertToExpTree(char *exp_input) {
    char expr[MAX];
    strcpy(expr, exp_input);
    int len, i;

    for (i = 0; i < (len = strlen(exp_input)); i++) {
        char token = expr[i];

        if (isalnum(token)) {
            Node *new_node = malloc(sizeof(Node));
            new_node->left = 0;
            new_node->right = 0;
            new_node->int_node = token;

            push(new_node);
        } else if (isOperator(token)) {
            Node *a = pop();
            Node *b = pop();

            Node *new_node = malloc(sizeof(Node));
            new_node->left = b;
            new_node->right = a;
            new_node->int_node = token;

            push(new_node);
        }
    }

    Node *root = pop();
    if (!isEmpty()) {
        printf("Invalid expression\n");
        return;
    }

    printf("Root : %c", root->int_node);
}

int main() {
    printf("Enter your Postfix expression: ");
    char expr[MAX];

    fgets(expr, sizeof(expr), stdin);

    expr[strcspn(expr, "\n")] = '\0';

    convertToExpTree(expr);

    return 0;
}