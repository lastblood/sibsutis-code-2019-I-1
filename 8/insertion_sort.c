#include <stdio.h>

int sort() {
    long long size;
    scanf("%lld", &size);
    if(size <= 0) {
        printf("Wrong array size");
        return -1;
    }

    long long array[size];
    long long iter = 0;
    for(long long i = 0; i < size; i++) {
        scanf("%lld", &array[i]);

        for(long long j = i; j > 0; j--) {
            iter++;
            if(array[j] < array[j-1]) {
                array[j] += array[j-1];
                array[j-1] = array[j] - array[j-1];
                array[j] = array[j] - array[j-1];
            } else {
                break;
            }
        }
    }

    printf("Iterations: %lld\n", iter );
    for(long long i = 0; i < size; i++) {
        printf("%lld ", array[i]);
    }
    return 0;
}