#include <stdio.h>
#include <stdlib.h>

//int array[] = {1,2,3,2,1,2};
//int length = sizeof(array) / sizeof(array[0]);

int array[];
int length;

int findMax(int first, int last, int fromEnd) {
    if(first > last) {
        int temp = first;
        first = last;
        last = temp;
    }

    int max = array[first], pos = first;
    for(int i = first; i <= last; i++) {
        if(array[i] > max || (fromEnd && array[i] == max)) {
            max = array[i];
            pos = i;
        }
    }

    printf("first %d last %d max[%d]=%d\n", first, last, pos, max);
    return pos;
}


int checkOnSide(int start, int step) {
    if(start + step >= length || start + step < 0) return 0;
    int maxpos = findMax(start + step, step == 1 ? length - 1 : 0, 1), sum = 0;

    //Движемся в сторону найденного максимума
    for(int i = start+step, minMax = __min(array[start], array[maxpos]); i != maxpos; i+=step)
        sum += minMax - array[i];

    printf("array[%d]=%d array[%d]=%d step %d sum %d\n", start, array[start], maxpos, array[maxpos], step, sum);
    return sum + checkOnSide(maxpos, step);
}

int letsrain() {
    scanf("%d", &length);
    for (int i = 0; i < length; i++) scanf("%d", &array[i]);

    int maxpos = findMax(0, length - 1, 0);
    printf("%d", checkOnSide(maxpos, 1) + checkOnSide(maxpos, -1));
    return 0;
}
