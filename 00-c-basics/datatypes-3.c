#include <stdio.h>

int main() 
{
    // characters
    int var1 = 65;

    float var2 = 3.14567891234;
    double var3 = 3.14567891234579;
    long double var4 = 3.1456789123457982;


    int var5 =  4/9;
    float var6 = 4/9;
    float var7 = 4.0/9.0;

    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(double));
    printf("%lu\n", sizeof(long double));

    printf("%.16f\n", var2);
    printf("%.16f\n", var3);
    printf("%.21Lf\n", var4);


    printf("%d\n", var5);
    printf("%.2f\n", var6);
    printf("%.2f\n", var7 );




    // Float, double, double float
    printf("%c", var1);
    return 0;
}