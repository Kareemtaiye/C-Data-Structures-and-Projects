#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

char stack[MAX];
int top = -1;

void push(char bracket) {
    top = top + 1;
    stack[top] = bracket;
}

char pop() {
    char val = stack[top];
    top = top - 1;
    return val;
}

int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

int match(char bracket) {
    int poped_bracket = pop();
    if (poped_bracket == '(' && bracket == ')') return 1;
    if (poped_bracket == '{' && bracket == '}') return 1;
    if (poped_bracket == '[' && bracket == ']') return 1;
    if (poped_bracket == '<' && bracket == '>') return 1;

    return 0;
}

int main() {
    char expr[100];
    printf("Enter your expression: ");

    fgets(expr, sizeof(expr), stdin);
    int i;
    int len = strlen(expr);
    int bracket;
    for (i = 0; i < len - 1; i++) {
        switch (expr[i]) {
            case '(':
            case '{':
            case '[':
            case '<':
                printf("Pushing: %c\n", expr[i]);  // Debugging case
                push(expr[i]);  // push opening bracket to stack
                break;
            case ')':
            case '}':
            case ']':
            case '>':
                if (isEmpty()) {
                    printf(
                        "Invalid expression: Right Brackets are more than "
                        "left\n");
                    return 1;
                }
                if (!match(expr[i])) {
                    printf("Invalid expression: Brackets '%c' mismatch\n",
                           expr[i]);
                    printf("stack, %d\n", top + 1);

                    return 1;
                }
                break;
        }
    }

    if (isEmpty())
        printf("Valid expression, brackets are well balanced\n");
    else  // Remaining  pushed left bracket(s)
        printf("Invalid expression: Left Brackets are more than right\n");

    printf("stack, %d\n", top + 1);
    return 0;
}