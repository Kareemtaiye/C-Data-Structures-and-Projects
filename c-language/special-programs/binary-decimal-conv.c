#include <stdio.h>

int binDecConversion(int binary) {
    int weight, result, rem;
    weight = 1;
    result = 0;
    while (binary != 0) {
        rem = binary % 10;
        result = result + rem * weight;
        binary = binary / 10;
        weight = weight * 2;
    }

    return result;
}

int main() {
    printf("Provide your binary number: ");
    int bin;
    scanf("%d", &bin);

    int converted = binDecConversion(bin);
    printf("%d\n", converted);

    return 0;
}