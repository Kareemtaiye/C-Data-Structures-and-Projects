#include <stdio.h>
#include <stdlib.h>

int main() {
    /* Change the stdin and stdout to text files */
    int c;
    while (
        (c = getchar()) != '\n' &&
        c != EOF)  // stdin are line-buffered in c. (keyboard is the def stdin)
        printf("%c", c);

    printf(" -> %d", c);  // The new line character in buffer.

    return 0;
}
