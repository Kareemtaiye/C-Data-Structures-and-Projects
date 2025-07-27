#include <stdio.h>

int addWithoutOperator(int a, int b) {
    while (b != 0) {
        a++;
        b--;
    }

    return a;
}

int main() {
    int x, y;
    printf("Enter the first value: ");
    scanf("%d", &x);

    printf("Enter the second value: ");
    scanf("%d", &y);

    printf("Result -> %d\n", addWithoutOperator(x, y));

    return 0;
}