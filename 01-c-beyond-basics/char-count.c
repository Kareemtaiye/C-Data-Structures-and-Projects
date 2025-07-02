#include <stdio.h>

/* Count character v-1 */
long countInputV1() {
    long nc = 0;
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
        ++nc;
    }

    return nc;
}

/* Count characters v-2*/
long countInputV2() {
    long nc = 0;
    int c;
    for (nc = 0; (c = getchar()) != '\n' && c != EOF; nc++);

    return nc;
}

int main() {
    printf("Type your characters:\n");
    long characters = countInputV2();
    printf("Characters typed %ld\n", characters);

    return 0;
}