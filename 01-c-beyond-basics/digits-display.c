#include <stdio.h>

int main() {
    printf(
        "Enter your text for test(Press ctrl + d to exit when finished "
        "typing): ");

    /* Counts the number of occurence of each digits from 1 to 10 */
    int c, i, nwhite, nother;
    int ndigit[10] = {0};

    nwhite = nother = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == '\n' || c == '\t' || c == ' ')
            ++nwhite;
        else
            ++nother;
    }

    char mult;
    printf("\ndigit:\n");

    for (i = 0; i < 10; i++) {
        mult = ndigit[i] > 1 ? 's' : ' ';
        printf("%d occurs %d time%c\n", i, ndigit[i], mult);
    };

    printf("\nwhitespaces = %d, others = %d\n", nwhite, nother);

    return 0;
}