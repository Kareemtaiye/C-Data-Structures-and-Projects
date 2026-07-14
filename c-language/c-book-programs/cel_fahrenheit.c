#include <stdio.h>

int main() {
    int celcius, fahr;
    int upper, lower, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    for (; fahr <= upper; fahr += step) {
        celcius = 5 * (fahr - 32) / 9;
        printf("Fahrenheit: %d\t Celcius: %d\n", fahr, celcius);
    }

    return 0;
}