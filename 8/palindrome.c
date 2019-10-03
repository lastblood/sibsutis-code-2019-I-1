#include <stdio.h>
#include <string.h>
#include <ctype.h>

//In-place realisation
int isPalindrome() {
    char array[1024*1024];
    gets(array);
    int length = strlen(array), i = 0, j = length-1, letters = 0, skipI = 0, skipJ = 0;
    for(int z = 0; z < length; z++) {
//        int temp = array[z];
//        printf("'%c' = %d ? %d\n", temp, temp, isalpha(temp));
        if(array[z] > 0x40 && array[z] < 0x5b) array[z] += 32;
    }

    while(i < length || j >= 0) {
        if(i < length && !isalpha(array[i])) {
            i++;
            skipI++;
            continue;
        }
        if(j >= 0 && !isalpha(array[j])) {
            j--;
            skipJ++;
            continue;
        }

        if(array[i] != array[j]) {
            skipI = -1;
            break;
        } else letters++;

        i++;
        j--;
    }

//    printf("%d %d %d\n", letters, skipI, skipJ);
    puts(!(skipI+1) || letters ? (skipI-skipJ ? "NO" : "YES") : "ERROR");
    return 0;
}