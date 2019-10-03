#include <stdio.h>

int gimmi_simple_mults() {
    long long number, mult = 2;
    char first = 1;
    scanf("%lld", &number);

    if(number < 2 && number > -2) {
        printf("%lld", mult);
        exit(0);
    }
    if(number < -1) {
        number *= -1;
        printf("-");
    }

    while(number != 1) {
        if(number % mult) {
            mult++;
        } else {
            if(first) {
                printf("%lld", mult);
                first--;
            } else {
                printf("*%lld", mult);
            }
            number /= mult;
        }
    }

    return 0;
}