#ifndef HEADER_FILE
#define HEADER_FILE

struct Fraction {
    int numerator;
    int denominator;
};

struct Fraction build(int numerator, int denominator);

struct Fraction buildl(long int numerator, long int denominator);

struct Fraction fraction_sum(struct Fraction a, struct Fraction b);

struct Fraction fraction_multiplication(struct Fraction a, struct Fraction b);

struct Fraction fract_reduction(long int numerator, long int denominator);

#endif