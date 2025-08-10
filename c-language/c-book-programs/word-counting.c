#include <stdio.h>
#define IN 1
#define OUT 2

int* countWordsAndSpaces() {
    int c, nw, nc, nl, state;

    state = OUT;
    nw = nc = nl = 0;

    while ((c = getchar()) != EOF) {
        nc++;
        if (c == '\n') nl++;

        if (c == '\n' || c == '\t' || c == ' ')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            nw++;
        }
    }

    static int result[3];
    result[0] = nc;
    result[1] = nw;
    result[2] = nl;

    return result;
}

int main() {
    printf(
        "Enter your text for test(Press ctrl + d to exit when finished "
        "typing): ");

    int* result = countWordsAndSpaces();
    printf("Characters: %d, words: %d, new lines: %d\n", result[0], result[1],
           result[2]);

    return 0;
}