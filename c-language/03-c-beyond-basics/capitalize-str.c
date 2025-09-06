#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

// Copy a string to another.
char *copyStr(char *to, char *from) {
    char *base_str = to;
    while (*from != '\0') {
        *to = *from;
        from++;
        to++;
    }

    *to = '\0';
    return base_str;
}

char *toUppCase(char *word) {
    char *word_cpy = malloc(strlen(word) + 1);
    word_cpy = copyStr(word_cpy, word);

    for (char *p = word_cpy; *p; p++) {
        // Only convert lowercase letter to Uppercase, ignore the rest
        if (*p >= 'a' && *p <= 'z') {
            *p = *p - 32;
        }
    }

    return word_cpy;
}

char *toLwrCase(char *word) {
    char *word_cpy = malloc(strlen(word) + 1);
    word_cpy = copyStr(word_cpy, word);

    for (char *p = word_cpy; *p; p++) {
        // Only convert uppercase letter to lowercase, ignore the rest
        if (*p >= 'A' && *p <= 'Z') {
            *p = *p + 32;
        }
    }

    return word_cpy;
}

int main() {
    char word[N] = "Kareem Taiye100#";

    char *capitalized_word = toUppCase(word);
    char *lowercased_word = toLwrCase(word);
    printf("%s - > %s\n", word, capitalized_word);
    printf("%s - > %s\n", word, lowercased_word);

    return 0;
}