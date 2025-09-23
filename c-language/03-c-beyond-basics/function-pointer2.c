#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Example {
    char a;
    int b;
    char c;
};

struct Student {
    char name[100];
    int grade;

} s1, s2, s3;

int sum(int a, int b) { return a + b; }
void display(int (*fptr)(int, int)) { printf("%d\n", fptr(10, 20)); };
void displayStudent(struct Student student) {
    printf("name: %s grade: %d\n", student.name, student.grade);
}

int main() {
    int (*ptr2sum)(int, int) = &sum;
    strcpy(s1.name, "boy");
    s1.grade = 100;

    printf("%p %d", ptr2sum, (*ptr2sum)(10, 20));
    display(sum);
    displayStudent(s1);
    printf("Size: %lu\n", sizeof(struct Example));
    return 0;
}