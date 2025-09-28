#include <stdio.h>

int writeAndCountLines(char* file_name) {
    FILE* fp = NULL;
    fp = fopen(file_name, "a");

    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    int c, i, line_count, last_char;
    line_count = last_char = i = 0;

    while ((c = getchar()) != EOF && i < 500) {
        fputc(c, fp);
        if (c == '\n') line_count++;
    }

    last_char = c;

    // if last line didnt end with a newline but has content, count it
    if (last_char != '\n' && i < 0) {
        line_count++;
    }

    fclose(fp);

    return line_count;
}

int countLines(char* file_name) {
    FILE* fp = NULL;
    fp = fopen(file_name, "r");

    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    int c, lines = 0, last_char = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            lines++;
        }
        last_char = c;
    }

    // if last line didnt end with a newline but has content, count it
    if (last_char != '\n' && last_char != 0) {
        lines++;
    }

    fclose(fp);
    return lines;
}

int main() {
    int line_count = writeAndCountLines("abc4.txt");

    printf("Line just written: %d", line_count);
    printf("Total line in file: %d", countLines("abc4.txt"));
    return 0;
}