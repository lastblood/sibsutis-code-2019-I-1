#include <stdio.h>

int to_upper_case() {
    int ch, length = 128, all = 0, processed = 0, *array;
    array = calloc(length, sizeof(int));
    
    while((ch = getchar()) != EOF) {
        if(ch >= 0x61 && ch <= 0x7a) {
            ch -= 0x20;
            processed++;
        }

        array[all++] = ch;
        if(length == all) {
            length *= 2;
            int *temp = calloc(length, sizeof(int));
            for(int i = 0; i < all; i++)
                temp[i] = array[i];
            free(array);
            array = temp;
        }
    }
    
    for(int i = 0; i < all; i++)
        putchar(array[i]);
    printf("\nall = %d; processed = %d", all, processed);

    return 0;
}