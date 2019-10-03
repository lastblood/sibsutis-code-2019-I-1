#include <stdio.h>
#include <string.h>

char * string_suffix(char * string, int suffix_length) {
    return string + (strlen(string) - suffix_length);
}


/*
int main() {
    char input[1000];

    printf("Enter string: ");
    if(gets(input) == NULL) {
        printf("Wrong input");
        exit(-1);
    }

    printf("Enter suffix length: ");
    int suffixLength;
    scanf("%d", &suffixLength);

    printf("Suffix: %s", string_suffix(input, suffixLength));
}
 */