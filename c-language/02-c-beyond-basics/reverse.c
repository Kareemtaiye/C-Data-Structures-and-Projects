#include <stdio.h>
#include <strings.h>
#define ARRAY_LEN(x) sizeof(x) / sizeof((x)[0])

/* Interative approach (arrays)*/

int* reverse(int arr[], int len) {
    static int result[1000];

    for (int i = 0; i < len; i++) {
        result[i] = arr[len - 1 - i];
    }

    return result;
}

/* Recursive approach (strings) */
/* C doest provide a manual way to extract a substring from a string, so we will
 * implement a helper function to make our reverse function clean*/

char* reverseHelper(char* s, int start, int end) {
    int temp = s[start];
    s[start] = s[end];
    s[end] = s[temp];

    return reverseHelper(s, start + 1, end - 1);
};

char* reverseStr(char* word) {
    int string_len = strlen(word);

    return reverseHelper(word, 0, string_len - 1);
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    int arr_len = ARRAY_LEN(arr);
    int* reversed = reverse(arr, arr_len);

    printf("Original: ");
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nReversed: ");
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", reversed[i]);
    }

    printf("\nEnter your string: ");

    char* word = 0;
    scanf("%s", word);

    char* reversed_str = reverseStr(word);
    printf("Original string: %s\n Reversed string: %s", word, reversed_str);

    return 0;
}