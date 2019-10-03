#include <stdio.h>

void pCh(int x) {
    printf("%c", x);
}

int pyramide() {
    char letter;
    printf("Lower letter:");
    scanf("%c", &letter);
    int maxValue = (int) letter;

    if(maxValue < 65 || maxValue > 90) {
        printf("It's not capital letter");
        return -1;
    }

    for(int i = 65; i <= maxValue; i++) {
        for(int j = i; j < maxValue; j++) printf(" ");
        for(int j = 65; j < i; j++) pCh(j);
        pCh(i);
        for(int j = i-1; j >= 65; j--) pCh(j);
        if(i != maxValue) printf("\n");
    }

    return 0;
}