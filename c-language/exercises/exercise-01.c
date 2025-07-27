#include <stdio.h>

/* Program to count blanks, tabs, and newlines */
int* countTabs() {
    int b,c,t,nl;
    b = t = nl = 0;

    static int vals[3];

    while((c = getchar()) != EOF) {
        if(c == '\n') 
            ++nl;
        if(c == '\t')
            ++t;
        if(b == ' ')
            ++b;
    }

    vals[0] = nl;
    vals[1] = t;
    vals[2] = b;

    // Returns a pointer to the first element
    return vals;
}

int main() 
{   
    printf("Please start typing\n");
    int* vals = countTabs();
    printf("New lines: %d, Tabs: %d, Blank Spaces: %d \n", vals[0], vals[1], vals[2]);
    return 0;
}