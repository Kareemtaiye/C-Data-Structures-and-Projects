#include <stdio.h>


 /* Count character v-1 */
int main()
{
    int inc;

    while(getchar() != EOF) 
    {
        ++inc;
        printf("%d\n", inc);
    }
}