#include <stdio.h>

int checkPerfectNo(int n) {
    int sum = 0;

    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum = sum + i;
        }
    }

    return sum == n;
}

int main() {
    printf("Enter your number for test: ");
    int n;
    scanf("%d", &n);

    int is_perfect = checkPerfectNo(n);

    if (is_perfect)
        printf("Number (%d) is a perfect number", n);
    else
        printf("Number (%d) is not a perfect number", n);
}