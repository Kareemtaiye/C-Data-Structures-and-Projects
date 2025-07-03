#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Palindrome checker for intergers
int isPalindromeInt(int num) {
    // Handle negative numbers
    if (num < 0) return -1;

    int n = num, reversed = 0;
    while (num != 0) {
        int remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num = num / 10;
    }

    return n == reversed;
};

// Palindrome checker for words
int isPalindromeStr(char word[]) {
    int start = 0;
    size_t end = strlen(word) - 1;

    // Force all character to lowercase
    for (int i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);      
    }

    for(; start < end; ) {
        if(word[start] != word[end]) return 0;
         start = start + 1;
         end = end -1;
    }

    return 1;
}

int main() {
    printf("Type 'n' for number or 'w' for word -> ");
    char start_program;
    scanf(" %c", &start_program);

    if (start_program == 'n') {
        printf("Provide your number\n");
        int number;
        scanf("%d", &number);

        if (isPalindromeInt(number)) {
            printf("Number is a palindrome\n");
        } else {
            printf("Number is not a palindrome\n");
        }
    }

    if (start_program == 'w') {
        printf("Provide your word\n");
        char word[100];
        scanf("%s", word);
        if(isPalindromeStr(word)) {
            printf("Word is a palindrome\n");
        } else {
            printf("Word is not a palindrome");
        }
    }

    return 0;
}