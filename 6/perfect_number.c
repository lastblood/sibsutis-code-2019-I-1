#include <stdio.h>
#include <math.h>
#include <time.h>

//Ищет в диапазоне long long, а не только в пределах 10k. Потому что может.
int find_perfect_numbers() {
    clock_t start = clock();

    int size = sizeof(long long)*8 - 1;

    long long cache[size];
    cache[0] = 1;

    for(int i = 1; i < size; i++)
        cache[i] = 2 * cache[i-1];

    int lastj = 0;
    for (int i = 3; i < size; i+=2) {
        for(int j = lastj; j < i; j++) {
            long long candidate = cache[i] - cache[j], sum = 1, k = 2, *mults = calloc(i, sizeof(long long)), mi = 0;
            int flag = 1;

            while(k < candidate) {
                if(candidate % k == 0) {
                    mults[mi++] = k;
                    sum += k;
                    k *= 2;
                } else if(flag) {
                    flag = 0;
                    k-=1;
                } else break;
            }

            if(candidate == sum) {
                flag = 1;
                for(int n = 0; n < /*mi/2*/ lastj && flag; n++) {
                    for(long long m = mults[n] + 1; m < mults[n+1]; m+=2) {
                        if(candidate % m == 0) {
                            flag = 0;
                            break;
                        }
                    }
                }
                if(flag) {
                    printf("SUCCESS %lld\n", candidate);
                    lastj = j;
                }
                free(mults);
                break;
            } else {
                free(mults);
            }
        }
    }

    printf("%ld/%d sec for 2^%d", clock() - start, CLOCKS_PER_SEC, size-1);

    return 0;
}


//NAIVE VERSION
int find_perfect_numbers_naive() {
    long long cache[63] = {1};

    for(int i = 1; i < 63; i++)
        cache[i] = 2 * cache[i-1];

    for (int i = 2; i < 63; i++) {
        for(int j = i-1; j > 0; j--) {
            long long candidate = cache[i] - cache[j], sum = 1;
            for(int k = 2; k <= powl(candidate, 0.5); k++) {
                if (candidate % k == 0)
                    sum += k + candidate / k;
                if(sum > candidate) break;
            }

            if(candidate == sum)
                printf("%lld\n", sum);
        }
    }

    return 0;
}