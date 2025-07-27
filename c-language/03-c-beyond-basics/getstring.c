#include <stdio.h>

char* getString(char* prompt) {
    printf("%s", prompt);
    static char str[100];

    scanf("%99s", str);
    return str;
}

int getInt(char* prompt) {
    printf("%s", prompt);
    static int integer;

    scanf("%d", &integer);
    return integer;
}

int main() {
    // char* str = getString("What is your name");
    char* greet = "Hello world";
    // printf("%s", str);
    printf("%c\n", 'A' + 1);
    return 0;
}