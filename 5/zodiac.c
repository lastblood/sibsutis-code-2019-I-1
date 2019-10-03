#include <stdio.h>
#include <math.h>

char *strings[] = {"Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius"};
double magic[] = {0, -.1583, 2.833, -19.04, 59.167, -82.8, 41, -.0714, 1.13, -.4};

int what_is_your_zodiac() {
    int day, month;
    scanf("%d.%d", &day, &month);
    for(int i = 0, j = month/7, g = 5-3*j; i <= g; i++) magic[0] += magic[(int) pow(7, j) + i] * pow(month, g - i);
    switch(1) case 1: printf("%s", strings[(month-1 + day / (int) (19 + round(magic[0]))) % 12]);
    return 0;
}