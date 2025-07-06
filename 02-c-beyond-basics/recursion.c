#include <stdio.h>

// Factorial using recursion.
long long fact(int n) {
    if (n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

/*1. Direct recursion - It calls itself again. i.e same function*/
/* Structure: */
func() {
    // Some code

    func();

    // Some code
}

/* Indirect function - It calls another function, which in turn calls it
 * directly or indirectly.*/
/* Structure: */

func1() {
    // Some code

    func2();

    // Some cide
}

func2() {
    // Some code

    func1();

    // Some code.
}

/* Tail recursion - The recursion call is the last thing the recursive function
 * is doing. No evaluation and hence, no need to keeo record of the prev
 * state*/

tailFunc(int n) {
    if (n == 0)
        return;
    else
        printf("%d", n);
    return tailFunc(n - 1);
}

/* Non-tail recursion - the recursion call is not the last thing being
   done by the function.
    - After returning there is something left to evaluate .*/

nonTailFunc(int n) {
    if (n == 0) {
        return
    };
    tailFunc(n - 1);
    printf("%d", n);
}

int main() {
    printf("Enter your factorial: ");
    int x;
    scanf("%d", &x);

    long long result = fact(x);
    printf("Factorial: %lld", result);
}
