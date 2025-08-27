#include <ctype.h>
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

void reverse(char *str) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void swapParenthesis(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        if (str[i] == ')') {
            str[i] = '(';
        } else if (str[i] == '(') {
            str[i] = ')';
        }
    }
}

void convert(const char *expr_inp) {
    top = top2 = -1;
    char expr[100];

    // 1. Copy expression.
    strcpy(expr, expr_inp);

    // 2. Reverse the copied expression
    reverse(expr);

    // 3.Swap brackets
    swapParenthesis(expr);

    int i, len;
    len = strlen(expr);
    for (i = 0; i < len; i++) {
        char token = expr[i];
        if (token == ' ' || token == '\n') continue;

        if (isalnum(token)) {
            push(RESULT, token);

        } else if (token == '(') {
            push(STACK, token);

        } else if (token == ')') {
            while (!isEmpty() && peek() != '(') {
                push(RESULT, pop());
            }

            pop();  // remove '('

        } else if (isOperator(token)) {
            while (!isEmpty() && precedence(peek()) > precedence(token)) {
                push(RESULT, pop());
            }
            push(STACK, token);
        }
    }

    // Push any remaining operator in stack to result
    while (!isEmpty()) {
        push(RESULT, pop());
    }

    // reverse result to get prefix
    reverse(result);
    result[top2 + 1] = '\0';  // Null terminator

    for (int i = 0; i < strlen(result); i++) {
        printf("%c", result[i]);
    }
}

int main() {
    printf("Enter your infix expression: ");

    char expr[100];

    fgets(expr, sizeof(expr), stdin);

    expr[strcspn(expr, "\n")] = '\0';
    convert(expr);

    return 0;
}