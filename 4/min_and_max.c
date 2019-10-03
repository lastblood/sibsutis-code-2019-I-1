#include <stdio.h>

int minmax() {
    char c;
    long value = 0, min = 0, minIndex = 0, maxIndex = 0, max = 0, index = 1;
    int sign = 0, nInRow = 0;
    int mode = 0; //1 - учитывать последовательность -15a как -15, 0 - не учитывать вообще

    while(1) {
        c = fgetc(stdin);
        if(c >= 0x30 && c <= 0x39) {
            nInRow = 0;
            value = value*10 + c - 0x30;
        } else if(c == 0x2d) {
            nInRow = 0;
            if(sign == 1 || value != 0) {
                printf("Wrong sign input");
                return -1;
            } else {
                sign = 1;
            }
        } else if(c == 0x20 || c == '\t' || c == '\n') {
            if(c == '\n') {
                if(nInRow == 1) break;
                else nInRow++;
            }

            int signedValue = value * (sign ? -1 : 1);
            if(min == 0 || min > signedValue) {
                min = signedValue;
                minIndex = index;
            }

            if(max == 0 || max < signedValue) {
                max = signedValue;
                maxIndex = index;
            }

            sign = 0;
            value = 0;
            index++;
        } else {
            if(value != 0 && mode) {
                int smartValue = value * (sign ? -1 : 1);
                if(min == 0 || min > smartValue) {
                    min = smartValue;
                    minIndex = index;
                }

                if(max == 0 || max < smartValue) {
                    max = smartValue;
                    maxIndex = index;
                }
            }

            break;
        }
    }

    printf("min %ld at %ld position\n", min, minIndex);
    printf("max %ld at %ld position", max, maxIndex);

    return 0;
}