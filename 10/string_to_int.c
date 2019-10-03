#include <stdio.h>

int string_to_int() {
    char array[11];
    gets(array);

    int sign = 1, value = 0;
    int signWasUsed = 0;

    for(int i = 0; 1; i++) {
        char temp = array[i];
        printf("array[%d] = %d\n", i, temp);
        if(temp == 0) break;
        else if(temp == 45 && !signWasUsed) {
            sign = -1;
            signWasUsed = 1;
        }
        else if(temp >= 48 && temp <= 57) {
            if(temp == 48 && !value) {
                printf("First digit can't be zero");
                return -1;
            } else {
                signWasUsed = 1;
                value *= 10;
                value += temp - 48;
            }
        } else if(temp == 43 && !signWasUsed) {
            signWasUsed = 1;
        } else {
            printf("ERROR");
            return -1;
        }
    }

    printf("%d", sign * value);

    return 0;
}