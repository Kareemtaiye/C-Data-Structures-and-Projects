#include <stdio.h>

int value;
int increment(void);

int main () {
    value = increment();
    value = increment();
    value = increment();

    printf("%d", value);

    return 0;    
}