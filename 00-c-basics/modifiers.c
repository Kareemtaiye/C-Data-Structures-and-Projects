#include <stdio.h>

int var_global;

extern int var2;
int main() {
    auto int var;
    register int var3;  

    printf("%d", var2);

    printf("%d\n", var);
    printf("%d\n", var_global);
    return 0;
}
