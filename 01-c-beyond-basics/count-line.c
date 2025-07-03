#include <stdio.h>

int countLines() {
    int c, nl;
    nl = 0;
    while((c = getchar()) != EOF) {
        if (c == '\n') 
            ++nl;
    }
    return nl;
}


int main() { 
    
    printf("Word: ");
    int nl = countLines();
    printf("Line number: %d\n", nl);
    
    return 0; 
}