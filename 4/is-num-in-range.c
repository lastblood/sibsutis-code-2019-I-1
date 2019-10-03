#include <stdio.h>

void format(char string[], int x) {
    printf("%s : %s\n", string, "false\0true" + (6*x));
}

int check() {
    double num;
    scanf("%lf", &num);

    format("[0;)",num >= 0);
    format("[5;15)",num >= 5 && num < 15);
    format("(-1;1)", num > -1 && num < 1);
    format("(-1;1) \\/ [5;15)", (num > -1 && num < 1) || (num >= 5 && num < 15));
    format("(-1;1) \\/ [5;15) \\/ {20,100,1000}", (num > -1 && num < 1) || (num >= 5 && num < 15) || num == 20 || num == 100 || num == 1000);

    return 0;
}