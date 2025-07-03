#include <math.h>
#include <stdio.h>

/* Implementation v-1 */
int checkArmstrong(int digit) {
    /* Count the number of digits*/
    int count = 0;
    int original = digit;

    while (digit != 0) {
        digit = digit / 10;
        count++;
    }

    char str[20];
    sprintf(str, "%d", original);
    int result = 0;

    for (int i = 0; i < count; i++) {
        int base_val = str[i] - '0';
        int exponent = count;
        base_val = (int)pow(base_val, exponent);
        result = result + base_val;
    }

    return result == original;
}

int main() {
    printf("Enter your number -> ");
    int value;

    scanf("%d", &value);
    int is_armstrong = checkArmstrong(value);

    if (is_armstrong) {
        printf("value: %d is an armstrong number", value);
    } else {
        printf("value: %d is not an armstrong number", value);
    }
    return 0;
}