#include <stdio.h>

long power(long num, long exp) {
    long p = 1, temp = exp;
    while(temp > 0) {
        p *= num;
        temp--;
    }

    return p;
}

void logic_cube() {
    printf("Logic_cube:\n");
    for(int x = 10000; x < 100000; x++) {
        int L = x / 10000, O = x / 1000 % 10, G = x / 100 % 10, I = x / 10 % 10, C = x % 10;
        if(power(L + O + G + I + C, 3) == x) printf("%d\n", x);
    }
}

void logic_cl() {
    printf("Logic_power:\n");
    for(int x = 10000; x < 100000; x++) {
        if(power(x%10, x/10000) == x) printf("%d\n", x);
    }
}

void deed() {
    printf("DEED:\n");
    for(int x = 1000; x < 10000; x++) {
        int D1 = x / 1000 % 10, E1 = x / 100 % 10, E2 = x / 10 % 10, D2 = x % 10;
        if(D1 == D2 && E1 == E2 && power(D1*11, E1) == x) printf("%d\n", x);
    }
}