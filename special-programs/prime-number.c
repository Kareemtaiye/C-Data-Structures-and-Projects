#include <math.h>
#include <stdio.h>

int checkPrime(double value) {
    int val = (int)value;

    int limit = ceil(sqrt(val));
    for (int i = 2; i < limit; i++) {
        if (val % i == 0) return 0;
    }

    return 1;
}

int main() {
    printf("Input a number(positive intergers only)\n");
    int x;
    scanf("%d", &x);

    int is_prime = checkPrime(x);
    printf("%d", is_prime);

    return 0;
}