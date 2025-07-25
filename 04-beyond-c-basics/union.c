#include <stdio.h>

union person {
    char* name;
    char* nationality;
    int age;
};

struct store {
    double price;
    union {
        struct {
            char* title;
            char* author;
            int num_pages;
        } book;

        struct {
            int size;
            int color;
            char* design;
        } shirt;
    } item;
};

int main() {
    union person kh;
    kh.name = "Kareem Taiye";
    kh.age = 500;  // Overwrites name

    struct store s;
    s.item.book.author = "John Doe";
    s.item.book.title = "Javascript Mastery";
    s.item.book.num_pages = 598;

    printf("%ld %d\n", sizeof(kh), kh.age);
    printf("%ld %s", sizeof(s.item), s.item.book.author);
    return 0;
}