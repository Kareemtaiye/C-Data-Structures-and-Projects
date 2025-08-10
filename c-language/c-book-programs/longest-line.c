#include <stdio.h>
#define MAXLINE 100  // Maximum character per line

/* Program that reads lines and prints the longest line with the number of
 * characters*/

void copy(char*, char*);
int getLine(char*, int);

int main() {
    int len;                // current line length.
    int max;                // the length of the maximum line
    char line[MAXLINE];     // current line;
    char longest[MAXLINE];  // longest character line saved here

    // Gets all line untill it hits an empty line.
    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);  // Copy to the longest line
        }
    }

    if (max > 0)  // There was a line
        printf("Longest line (%d chars): %s", max, longest);

    return 0;
}

/* getline: Read line into a string and returns length*/
int getLine(char s[], int limit) {
    int c, i;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {  // new line counts as a character.
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;  // the length of the line.
}

/* copy: copies "from" into "to", assuming to is big enough*/
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}