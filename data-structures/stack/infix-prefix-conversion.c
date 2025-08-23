#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef enum Target { STACK, RESULT } Target;

char stack[MAX];
char result[MAX];
int top = -1, top2 = -1;

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

int isOperator(char c) {
    return c == '^' || c == '+' || c == '-' || c == '/' || c == '*';
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

void push(Target where, char data) {  //clang-format off
    if (where == STACK)
        stack[++top] = data;
    else
        result[++top2] = data;
}

void convert(const char expr[]) {
    int i, len;
    len = strlen(expr);
    for (i = len - 1; i >= 0; i--) {
        char token = expr[i];
        if (token == ' ' || token == '\n') continue;

        if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z') ||
            (token >= '0' && token <= '9')) {
            push(RESULT, token);

        } else if ((isOperator(token) && isEmpty()) ||
                   (isOperator(token) && !isEmpty() &&
                    precedence(token) > precedence(peek())) ||
                   token == ')') {
            push(STACK, token);

        } else if (isOperator(token) && !isEmpty() &&
                   precedence(token) <= precedence(peek())) {
            push(RESULT, pop());

        } else if (token == ')') {
            while (!isEmpty() || peek() != '(') {
                push(RESULT, pop());
            }
            pop();
        }
    }

    while (!isEmpty()) {
        push(RESULT, pop());
    }

    int j, res_len;
    res_len = strlen(result);
    for (j = res_len - 1; j >= 0; j--) {
        printf("%c", result[j]);
    }
    printf("\n");
}

int main() {
    printf("Enter your infix expression: ");

    char expr[100];

    fgets(expr, sizeof(expr), stdin);

    convert(expr);
}