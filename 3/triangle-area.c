#include <stdio.h>
#include <math.h>

double maximum(double x, double y, double z) {
    if(x >= y && x >= z) return x;
    if(y >= x && y >= z) return y;
    if(z >= x && z >= y) return z;
}

int calc_area() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    double max = maximum(a,b,c);
    if(max >= a+b+c-max) {
        printf("It's not triangle");
        return -1;
    } else {
        double p = (a+b+c)/2;
        double area = sqrt(p * (p-a) * (p-b) * (p-c));
        printf("%f", area);
    }

    return 0;
}