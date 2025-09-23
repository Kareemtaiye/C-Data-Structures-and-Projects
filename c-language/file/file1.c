#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp = NULL;

    fp = fopen("abc.txt", "w");
    char ch = 'T';
    char *string = "This is a sentence";
    fputc(ch, fp);
    fputs(string, fp);

    for (int i = 0; i < strlen(string); i++) {
        fputc(string[i], fp);
    }

    fprintf(fp, "\nFull name: %s, age: %d", "Kareem Taiye", 22);

    FILE *fp2 = NULL;
    char output_char;

    fp2 = fopen("abc2.txt", "r");
    if (fp2 == NULL) {
        printf("Error opening file");
        exit(1);
    }

    while (!feof(fp2)) {
        output_char = fgetc(fp2);
        printf("%c", output_char);
    }

    char string2[20];

    while (!feof(fp2)) {
        fgets(string2, 19, fp2);
        printf("%s", string2);
    }

    fclose(fp);
    fclose(fp2);

    // printf("Writing into file");  // output redirection to the file using >
    // filename(in the terminal).

    return 0;
}
