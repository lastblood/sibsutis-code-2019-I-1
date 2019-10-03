#include <stdio.h>
#include <math.h>

int calculate() {
    double n,x,temp,epsilon=0.00005;
    scanf("%lf", &n);
    x = 1; //Здесь могла быть ваша... функция предположения

    while(1) {
        temp = (x + n/x) / 2;
        printf("%Lf\t%Lf\n", x, temp);
        if(fabsl(temp - x) < epsilon) break; //Прекращение, если изменения от итерации меньше 10^-4 по модулю
        x = temp;
    }

    printf("%.4lf", x);
    return 0;
}