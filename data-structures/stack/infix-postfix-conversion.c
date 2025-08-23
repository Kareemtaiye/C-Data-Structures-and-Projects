#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

int precedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int isOperator(char val) {
    return val == '^' || val == '+' || val == '-' || val == '/' || val == '*';
}
int isEmpty() {  //clang-format off
    return top == -1;
}

char pop() {  //clang-format off
    if (!isEmpty()) return stack[top--];
    return '\0';
}

char peek() {  //clang-format off
    if (!isEmpty()) return stack[top];
    return '\0';
}

void push(char data) {  //clang-format off
    stack[++top] = data;
}

void convert(const char expr[]) {
    int i, len;
    len = strlen(expr);
    for (i = 0; i < len; i++) {
        char token = expr[i];

        if (token == ' ' || token == '\n') continue;

        if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z') ||
            (token >= '0' && token <= '9')) {
            printf("%c", token);
        } else if (isOperator(token)) {
            while (!isEmpty() && precedence(token) <= precedence(peek())) {
                printf("%c", pop());
            }
            push(token);
        } else if (token == '(') {
            push(token);
        } else if (token == ')') {
            while (!isEmpty() && peek() != '(') {
                printf("%c", pop());
            }
            pop();
        }
    }
    while (!isEmpty()) {
        printf("%c", pop());
    }

    printf("\n");
}

int main() {
    printf("Enter your infix expression: ");
    char expr[100];

    fgets(expr, sizeof(expr), stdin);
    convert(expr);
    return 0;
}