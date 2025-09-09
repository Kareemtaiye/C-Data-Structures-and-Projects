#include <stdio.h>

// Not safe and questionable in the real world use.(violating the use of argc
// and argv[]) Just a clever trick.
int main(int argc, char **argv) {  //clang-format off
    return argc <= 127 ? printf("%c ", argc), main(argc + 1, &argv[1]) : 0;
}