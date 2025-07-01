#include <stdio.h>

int main() 
{
    int c;

    /* Copy input to output v-1 */
    c = getchar();
    while(c != EOF) {
        c = getchar();
        printf("%d", c);
        putchar(c);
    }


    /* Copy input to output v-2*/
    while((c = getchar()) != EOF) 
    {
        putchar(c);
    }

    // printf("%c", p);
    return 0;

}