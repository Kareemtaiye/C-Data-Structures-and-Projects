#include <stdio.h>

void printFloyTriangle(int n) {
    int init = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            printf("%d ", init);
            init++;
        }
        printf("\n");
    }
}

int main() {
    printf("Enter traingle row number: ");
    int n;
    scanf("%d", &n);

    printFloyTriangle(n);
    return 0;
}