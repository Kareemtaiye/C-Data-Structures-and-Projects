#include <stdio.h>

int checkLeapYear(int year) {
    if (year % 400 == 0) return 1;
    if (year % 400 != 0 && year % 100 != 0 && year % 4 == 0) {
        return 1;
    }

    return 0;
}

int main() {
    printf("Enter year for leap check: ");
    int year;
    scanf("%d", &year);

    int isLeapYear = checkLeapYear(year);
    if (isLeapYear)
        printf("Year (%d) is a leap year", year);
    else
        printf("Year (%d) is not a leap year", year);
}