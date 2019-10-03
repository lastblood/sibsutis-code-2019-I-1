#include <stdio.h>

int sort() {
    long long size;
    scanf("%lld", &size);
    if(size <= 0) {
        printf("Wrong array size");
        return -1;
    }

    long long array[size];
    long long max = 0, min = 0;
    for(long long i = 0; i < size; i++) {
        scanf("%lld", &array[i]);

        if(!i) {
            max = array[i];
            min = array[i];
        } else {
            max = max < array[i] ? array[i] : max;
            min = min > array[i] ? array[i] : min;
        }
    }

    unsigned long long difference = max - min + 1;
    long long count[difference];
    for(unsigned long long i = 0; i < difference; i++) count[i] = 0;
    for(long long i = 0; i < size; i++) count[array[i] - min]++;

    for(unsigned long long i = 0; i < difference; i++)
        for(long long j = 0; j < count[i]; j++)
            printf("%lld ", i+min);
}