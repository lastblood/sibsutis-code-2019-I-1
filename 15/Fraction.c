#include "Fraction.h"
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

struct Fraction;


long int gcd(long int a, long int b) {
    long temp;
    while(b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}


struct Fraction build(int numerator, int denominator) {
    if(numerator < 0 || denominator < 1) {
        printf("Fraction build exception. Numerator < 0 or denominator < 1");
        exit(-1);
    }
    
    struct Fraction result = {numerator, denominator};
    return result;
}

struct Fraction buildl(long int numerator, long int denominator) {
    if(labs(numerator) > INT_MAX || labs(denominator) > INT_MAX) {
        printf("Integer overflow");
        exit(-1);
    }

    return build((int) numerator, (int) denominator);
}


struct Fraction fract_reduction(long int numerator, long int denominator) {
    long int gcdResult = gcd(numerator, denominator);
    numerator /= gcdResult;
    denominator /= gcdResult;

    return buildl(numerator, denominator);
}


struct Fraction fraction_sum(struct Fraction a, struct Fraction b) {
    long int tempNumerator = (long int) b.numerator * a.denominator + (long int) a.numerator * b.denominator;
    long int tempDenominator = (long int) b.denominator * a.denominator;

    printf("sum %ld / %ld\n", tempNumerator, tempDenominator);

    return fract_reduction(tempNumerator, tempDenominator);
}

struct Fraction fraction_multiplication(struct Fraction a, struct Fraction b) {
    long int tempNumerator = (long int) a.numerator * b.numerator;
    long int tempDenominator = (long int) a.denominator * b.denominator;

    printf("mult %ld / %ld\n", tempNumerator, tempDenominator);

    return fract_reduction(tempNumerator, tempDenominator);
}


//Only positive or zero-equals fractions
int exampleMain() {
    int numerator, denominator;
    scanf("%d %d", &numerator, &denominator);
    struct Fraction f1 = build(numerator, denominator);
    
    scanf("%d %d", &numerator, &denominator);
    struct Fraction f2 = build(numerator, denominator);

    struct Fraction f3 = fraction_sum(f1, f2);
    struct Fraction f4 = fraction_multiplication(f1, f2);

    printf("%d / %d\n", f3.numerator, f3.denominator);
    printf("%d / %d\n", f4.numerator, f4.denominator);

    return 0;
}