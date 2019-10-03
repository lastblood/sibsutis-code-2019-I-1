#include <stdio.h>

int printStairs() {
    printf("Steps:");
    int count;
    scanf("%d", &count);

    if(count < 1) {
        printf("Wrong count");
        return -1;
    }

    for(int i = 1; i <= count; i++) {
        for(int j = 0; j < (count - i); j++) printf(" ");
        for(int j = count - i; j < count; j++) printf("#");
        printf("\n");
    }

    return 0;
}