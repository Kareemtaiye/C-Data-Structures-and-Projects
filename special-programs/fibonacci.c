#include <stdio.h>

void finobacci(int n) {
    int a, b, result;
    a = 0;
    b = 1;

    for (int i = 0; i < n; i++) {
        printf("%d\n", a);
        result = a + b;
        a = b;
        b = result;
    }
}

int main() {
    printf("Enter the number of fin term: ");
    int x;
    scanf("%d", &x);
    finobacci(x);
    return 0;
}