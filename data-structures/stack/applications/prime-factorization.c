#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack_arr[MAX];  // Avoid passing around to functions.
int top = -1;

int isFull() {
    if (top < MAX - 1)
        return 0;
    else
        return 1;
}

void push(int val) {
    if (isFull()) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack_arr[++top] = val;
}

int isprime(int val) {
    int i;
    for (i = 2; i <= (int)sqrt(val); i++) {
        if (val % i == 0) return 0;
    }
    return 1;
}

void printPrimeFactors() {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d ", stack_arr[i]);
    }
}

void primeFactorization(int val) {
    int result, i;

    i = 2, result = val;
    while (result != 1 && i <= val) {
        // Not prime number, increase the number and skip the current iter.
        if (!isprime(i)) {
            i++;
            continue;
        }

        // Prime number here.
        if (result % i == 0) {
            result = result / i;
            push(i);
        } else {
            i++;
        };
    }

    // Print the prime factors in descending order.
    printPrimeFactors();
}

int main() {
    int value = 12;
    primeFactorization(value);
    return 0;
}