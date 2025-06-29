#include <stdio.h>
#define PI 3.14159
#define add(x, y) x+y
#define greater(x, y) if(x > y) \
                            printf("%d is greater than %d \n",x, y );\
                        else \
                            printf("%d is greater than %d \n", y, x);
int main()
{

    printf("%.5f", PI);
    printf("Addtion of two numbers is %d \n", add(4, 5));
    greater(6, 5);

    printf("The result of the expression a + b * c is %d\n", 5 * add(2, 5));

    printf("Date is %s\n", __DATE__);
    printf("Time is %s\n", __TIME__);
    return 0;
}