#include <stdio.h>

float sum(float a, float b) { return a + b; }
float sub(float a, float b) { return a - b; }
float mul(float a, float b) { return a * b; }
float div(float a, float b) {
    if (b == 0.0f) {
        printf("Error: Division by zero\n");
        return 0.0f;
    }
    return a / b;
}

int main() {
    printf(
        "Enter 0 for additon, 1 for subtraction, 2 to multiplication, and 3 to "
        "division: ");

    int choice;
    scanf("%d", &choice);

    float a, b;
    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    float (*ptr2float[])(float, float) = {&sum, &sub, &mul, &div};
    printf("%f\n", ptr2float[choice](a, b));
    return 0;
}