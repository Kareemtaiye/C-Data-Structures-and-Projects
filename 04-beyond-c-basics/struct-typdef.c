#include <stdio.h>

struct Student {
    char name[100];
    int age;
    char* school;
    char* skills[10];
    char* bestTopic;
    char* languages[10];
    char* bio;
};

typedef struct {
    char name[100];
    int projects;
    char* companies[10];
    int year;

} programmer;

int main() {
    struct Student kt = {
        .name = "Kareem Taiye",
        .age = 22,
        .school = "UNILORIN",
        .skills = {"CS Fun", "AI/ML", "SE", "Sys-Des", "DevOps", "CP"},
        .languages = {"C", "Python", "C++", "Javascript/TS", "Java"},
        .bestTopic = "Discrete Math"
        // clang format off
    };
    // clang format on

    kt.bio =
        "A passionate and knowlege driven cs student who dream of building "
        "legacies and loves exploring cs concepts";

    programmer kh = {
        .name = "Kareem Taiye",
        .projects = 100,
        .companies = {"Google", "OpenAI", "Meta", "Netflix", "Amazon", "Inv"},
        .year = 2027
        // clang format off
    };
    // clang format on
    printf("%s\n", kt.name);
    for (int i = 0; i < sizeof(kh.companies) / sizeof(kh.companies[0]); i++) {
        printf("%d. %s\n", i, kh.companies[i]);
    }

    return 0;
}