#include <stdio.h>

enum Bool {
    False,
    True
};  // Automatic initialization, starting from 0, in contrast to #define;

int main() {
    enum LocalBool {
        False,
        True
    };  // (Can be declared locally) In contrast to #define

    enum Point {
        x = 10,
        y,
        z = 35
    };  // All uninitialzed value will get the previous value + 1;

    enum PointNotAllowed {
        a = 5,
        b = 2.5
    };  // Only integer values are
        // allowed;

    enum PointNotAllowed2 {
        a = 5,
        b = 2
    };  // Enum constants must be unique in their scope, a and b were already

    enum Bool var;
    var = True;

    printf("%d", var);
    return 0;
}