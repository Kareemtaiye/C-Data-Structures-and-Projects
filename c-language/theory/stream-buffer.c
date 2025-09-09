#include <stdio.h>

int main() {
    char input[5];
    printf("Enter characters more than 5: \n");

    fgets(input, sizeof(input), stdin);

    printf("File read so far: %s\n", input);  // reads up to sizeof(input) -1

    fgets(input, sizeof(input), stdin);
    printf("Leftover data in stream buffer: %s\n", input);

    return 0;
}