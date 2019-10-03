#include <stdio.h>

void printHoriz(int newLine) {
    const int width = 66;
    for(int i = 0; i < width; i++) { printf("_"); }
    if(newLine > 0) printf("\n");
}

int ascii() {
    printHoriz(1);
    printf("||\tOct\t|\tDec\t|\tHex\t|\tChar\t||\n");
    printHoriz(1);

    int start = 0x20, end = 0x7f;

    for(int i = start; i < end; i++)
        printf("||\t%o\t|\t%d\t|\t%x\t|\t'%c'\t||\n", i,i,i,i);

    printHoriz(0);
    return 0;
}