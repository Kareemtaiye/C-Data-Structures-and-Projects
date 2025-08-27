#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int stack[100];
int top = -1;

int isEmpty() {  //clang-format off
    return top == -1;
}

int pop() {
    if (!isEmpty()) return stack[top--];
    printf("Error: Stack underflow\n");
    return -1;
}

void push(int data) {  //clang-format off
    stack[++top] = data;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int compute(int a, int b, char op) {
    switch (op) {
        case '+':
            return b + a;
        case '-':
            return b - a;
        case '*':
            return b * a;
        case '/':
            return b / a;
        case '^':
            return (int)pow(b, a);
        default:
            return -1;
    }
}

char evaluate(const char* expr_inp) {
    char expr[100];
    int i, result;
    char a, b;
    strcpy(expr, expr_inp);

    for (i = 0; i < strlen(expr); i++) {
        char token = expr[i];

        if (isdigit(token)) {
            push(token - '0');
        } else if (isOperator(token)) {
            if (top < 1) {
                printf("Error: Not enough operands\n");
                return -1;
            }
            int a = pop();
            int b = pop();
            result = compute(a, b, token);
            push(result);
        }
    }
    result = pop();

    if (!isEmpty()) {
        printf("Error: Invalid expression (too many operands)\n");
        return -1;
    }

    return result;
}

int main() {
    printf("Enter your postfix expression: ");

    char expr[100];
    fgets(expr, sizeof(expr), stdin);

    expr[strcspn(expr, "\n")] = '\0';

    int result = evaluate(expr);
    if (result != -1) {
        printf("Result: %d\n", result);
    }

    return 0;
}