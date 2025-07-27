#include <stdio.h>

long powCustom(int base, int exponent) {
    /* Handle base and exponent edge cases*/
    if (base == 0) return 0;
    if (exponent == 0) return 1;

    int result = 1;

    while (exponent != 0) {
        result = result * base;
        exponent--;
    }

    return result;
}

int main() {
    printf("Provide your base value: ");
    int base;
    scanf("%d", &base);

    printf("Provide your exponent value: ");
    int exp;
    scanf("%d", &exp);

    long result = powCustom(base, exp);
    printf("Result: %ld", result);

    return 0;
}