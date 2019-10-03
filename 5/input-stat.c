#include <stdio.h>
#include <ctype.h>

int getStat() {
    int vowels = 0, symbols = 0, letters = 0, digits = 0, puncs = 0;

    while(1) {
        char c = getchar();
        if(c == EOF) break;
//        if(c == '\n') break;

        symbols += 1;
        puncs += ispunct(c) != 0;
        letters += isalpha(c) != 0;
        digits += isdigit(c) != 0;
        vowels += c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }

    printf("vowels: %d\n", vowels);
    printf("digits: %d\n", digits);
    printf("punctuation marks: %d\n", puncs);
    printf("%% of letters: %.2lf%%", !symbols ? 0 : letters * 100.0 / symbols);

    return 0;
}