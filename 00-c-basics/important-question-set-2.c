#include <stdio.h>
//declared here(which automatically gets set to 0) and is stored on bss in memory
//Also, explicit assignment to to zero(0) means it is a definition and the value of the var is n0t stored in bss but datac
static int i;

//i is defined here and the compiler stores the value to data in memory
static int i = 27;

i=40; //Not allowes, assignment are allowed only in function block(it is considered to be redefinition)

//Value remains unchange.
static int i;

int main() 
{
    //i is zero here (local variable gets higher preference) because of scope
    static int i;

    printf("%d", i);
    return 0;
}