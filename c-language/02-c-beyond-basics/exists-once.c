#include <stdio.h>

// Checks if any digit occurs more than once in a number.
int moreThanOnce(int n) {
    /*Initialize all element(0 -9) to zero to indicate digit not see at the
     beginning */
    int seen[10] = {0};
    int rvalue = 0, ncopy = n;

    while (ncopy > 0) {
        rvalue = ncopy % 10;
        if (seen[rvalue] == 1) {
            return 1;
        }
        seen[rvalue] = 1;
        ncopy = ncopy / 10;
    }

    return 0;
}

int main() {
    printf("Enter your number: ");
    int n;
    scanf("%d", &n);

    if (moreThanOnce(n))
        printf("Repeated digit(s) found in number: %d", n);
    else
        printf("No repeated digit found");

    return 0;
}