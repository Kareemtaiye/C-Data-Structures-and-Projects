#include <stdio.h>

int main() {
    char* fruits[] = {"Oranges", "Banana", "Apple", "Grape"};
    for (int i = 0; i < sizeof(fruits) / sizeof(fruits[0]); i++) {
        printf("%s\n", fruits[i]);
    }
}