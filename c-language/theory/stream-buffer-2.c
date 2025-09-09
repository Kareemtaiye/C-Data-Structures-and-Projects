#include <stdio.h>
#include <string.h>

int main() {
    printf("Enter characters more than 5: ");

    char input[5];
    fgets(input, sizeof(input), stdin);

    printf("Characters read: %s\n", input);

    // if input didnt include newline flush the remaining data in the stream
    // buffer.

    if (strchr(input, '\n') == NULL) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);  // up to the 1st nl or EOF
    }

    fgets(input, sizeof(input), stdin);
    printf("Leftover data in input buffer: %s", input);
}
