#include <stdio.h>
#include <string.h>

// Palindrome checker for intergers
int isPalindromeInt(int num) {
    // Handle negative numbers
    if (num < 0) return;

    int n = num, reversed = 0;
    while (num != 0) {
        int remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num = num / 10;
    }

    return n == reversed;
};

int isPalindromeStr(char word[]) {
    int start = 0;
    size_t end = strlen(word);

    return 0;
}

int main() {
    printf("Provide your number\n");
    int number;
    scanf("%d", &number);

    if (isPalindromeInt(number)) {
        printf("Number is a palindrome\n");
    } else {
        printf("Number is not a palindrome\n");
    }

    return 0;
}