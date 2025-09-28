#include <stdio.h>

int main() {
    FILE* fp = NULL;

    fp = fopen("abc3.txt", "w+");

    char* string = "Hello my name is KH\n";
    fputs(string, fp);

    int last_pos = ftell(fp);
    rewind(fp);
    int first_pos = ftell(fp);
    fseek(fp, 6, SEEK_CUR);
    printf("Pos: %d", last_pos);
    printf("Pos: %d", first_pos);

    fp = fopen("abc3.txt", "a");
    fputs("C programming\n", fp);

    return 0;
}