#include <stdio.h>
struct Point {
    int x, y;
};

struct rectangle {
    struct Point upper_left;
    struct Point lower_right;
};

int area(struct rectangle r) {
    int length = r.lower_right.x - r.upper_left.x;
    int breadth = r.upper_left.y - r.lower_right.y;

    return length * breadth;
};
int main() {
    struct rectangle r;
    printf("Enter the upper left coordinate if the rectangle: ");
    scanf("%d %d", &r.upper_left.x, &r.upper_left.y);

    printf("Enter the lower right coordinate if the rectangle: ");
    scanf("%d %d", &r.lower_right.x, &r.lower_right.y);

    printf("Area: %d", area(r));
}