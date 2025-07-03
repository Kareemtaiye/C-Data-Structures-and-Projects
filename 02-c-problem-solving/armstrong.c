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

    /* Convert the number to number */
    char str[20];
    sprintf(str, "%d", original);
    int result = 0;

    /* Convert each digits back to string and perform logic */
    for (int i = 0; i < count; i++) {
        int base_val = str[i] - '0';
        int exponent = count;
        base_val = (int)pow(base_val, exponent);
        result = result + base_val;
    }

    return result == original;
}

/* Implementation v-2 */
int checkArmstrongV2(int digit) {
    int count = 0;
    int original = digit;

    while (digit != 0) {
        digit = digit / 10;
        ++count;
    }

    int result = 0;
    int digit_copy = original;

    /* Extract the last values from the right until there is no more value*/
    int rem = digit_copy % 10;
    while (digit_copy != 0) {
        int base_value = rem;
        int exponent = count;
        result = result + (int)pow(base_value, exponent);
        digit_copy = digit_copy / 10;
        rem = digit_copy % 10;
    }

    return original == result;
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

    // printf("%d", checkArmstrongV2(153));
    return 0;
}