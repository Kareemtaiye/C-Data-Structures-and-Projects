#include <stdio.h>

/* Implementation v-1 */
int checkStrongNumber(int number) {
    int original = number;
    int q, rem, result;
    result = 0;
    q = number;
    int mul;

    while (q != 0) {
        rem = q % 10;
        mul = 1;

        for (int i = 0; i < rem; i++) {
            mul = mul * (rem - i);
        }
        result = result + mul;
        q = q / 10;
    }
    return result == original;
}

/* Implementation v-2 */
int checkStrongNNumberV2(int number) {
    int original, q;
    original = q = number;
    int result, fact, rem;
    result = 0;

    while (q != 0) {
        rem = q % 10;
        fact = 1;

        for (int i = 1; i <= rem; i++) {
            fact = fact * i;
        }
        result = result + fact;
        q = q / 10;
    }

    return result == original;
}

int main() {
    printf("Enter your strong number \n");
    int value;

    scanf("%d", &value);
    int is_str = checkStrongNNumberV2(value);

    printf("%d", is_str);

    return 0;
}