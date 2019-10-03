#include <stdio.h>

long long llabs(long long int x) {
    return x < 0 ? -x : x;
}

int sum() {
    long long first, sum = 0, mult = 1;
    int count;
    scanf("%lld %d", &first, &count);
    for(int i = 0; i < count; i++) {
        mult *= first;
        sum += mult;
    }

    printf("%lld", sum);
    return 0;
}