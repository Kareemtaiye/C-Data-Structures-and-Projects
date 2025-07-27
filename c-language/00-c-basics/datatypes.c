#include <stdio.h>
#include <limits.h>

int main() 
{
    // Range: The upper and lower bound 
    int var1 = INT_MAX;
    int var2 = INT_MIN;
    unsigned int var3 = UINT_MAX;

    short var4 = SHRT_MAX;
    short var5 = SHRT_MIN;

    unsigned short var6 = USHRT_MAX;

    printf("%zu\n", sizeof(long int));
    printf("The range of signed intergers is from %d to %d\n", var1, var2);
    printf("The range of unsigned intergers is from 0 to %u \n", var3);

    printf("The range of signed SHORTS is from %d to %d\n", var4, var5);
    printf("The range of unsigned shorts is from 0 to %u \n", var6);


    printf("%lu", sizeof(long int));
    printf("%lu", sizeof(long long int));


    return 0;
}