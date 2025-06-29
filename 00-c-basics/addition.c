#include <stdio.h>


int main()
{
    int a, b;

    printf("Enter the value for the first number\n");
    scanf("%d", &a);
    printf("Enter the value for the second number\n");
    scanf("%d", &b);

    printf("%d + %d = %d\n", a, b, a + b);

    // int user_input = scanf("%d");
    // printf("%d", user_input);

    return 0;
}