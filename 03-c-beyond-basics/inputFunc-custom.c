#include <stdio.h>
#include <stdlib.h>
/* Since gets and scanf are not safe, we want to design our own input function.
 * We want our input funtion to have the following functionalities:

1. It must continue to read the string even after seeing whitespace character.
2. It must stop reading the string after seeing the newline character
3.It must discard extra character
4. It must return the number of characters it stores in the character array.
 */

char* input(char prompt[]) {
    int size = 100;
    char* str = malloc(size);
    if (str == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int c, i = 0;
    printf("%s", prompt);
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i >= size - 1) {  // resize if needed
            size *= 2;
            str = realloc(str, size);
            if (str == NULL) {
                printf("Memory reallocation failed.\n");
                exit(1);
            }
        }
        str[i++] = c;
    }
    str[i] = '\0';
    return str;
}

int main() {
    char* name = input("What is your name? ");
    printf("Hello, %s!\n", name);
    free(name);
    return 0;
}
