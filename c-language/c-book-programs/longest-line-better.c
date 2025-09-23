#include <stdio.h>
#define MAXLINE 100

/* Makes the longest line implementation robust and simpler using external
  varibables to avoid argument lists on the functions*/

int max;
char longest[MAXLINE], line[MAXLINE];

int getLine(void);
void copy(void);

int main() {
    extern int max;  // current maximum line length
    max = 0;
    int len;

    while ((len = getLine()) > 0) {
        if (len > max) {
            max = len;  // becomes the current longest line;
            copy();     // update the current line to be longest;
        }
    }

    if (max > 0) {  // if there was a line
        printf("Longest line: %s", longest);
    }
    return 0;
}

int getLine() {
    extern char line[MAXLINE];
    int i = 0, c;

    while ((c = getchar()) != EOF && i < MAXLINE - 1 && c != '\n') {
        line[i] = c;
        i++;
        fflush(stdout);
    }

    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';
    return i;
}

void copy() {
    int i;
    extern char longest[MAXLINE], line[MAXLINE];
    for (i = 0; (longest[i] = line[i]) != '\0'; i++);
}

// #include <stdio.h>

// int main() {
//     int c;
//     printf("Type something (Ctrl+D to send EOF):\n");

//     while ((c = getchar()) != EOF) {
//         printf("You typed: '%c' (ASCII: %d)\n", c, c);
//     }

//     printf("EOF detected. Exiting...\n");
//     return 0;
// }
