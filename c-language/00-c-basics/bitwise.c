#include <stdio.h>

int main() 
{
    int a = 10;//(00001010)
    int b = 3; //(00000011)
    //Bitwise and(&)
    printf("%d\n", a & b);

    //Bitwise or(|)
    printf("%d\n", a | b); 

    //Bitwise left shift (for a << b, result = a * 2^b)
    printf("%d\n", a << b); //(10100000)

    //Bitwise right shift (for a << b, result = a / 2^b)
    printf("%d\n", a >> b); //(00000001)

    //Bitwise XOR
    printf("%d", a ^ b);

    return 0;
}