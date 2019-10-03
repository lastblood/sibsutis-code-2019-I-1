#include <stdio.h>

int convert() {
    int seconds;

    printf("Input seconds: ");
    scanf("%d", &seconds);

    int days = seconds / (24 * 60 * 60);
    seconds = seconds % (24 * 60 * 60);

    int hours = seconds / (60 * 60);
    seconds %= 60 * 60;

    int minutes = seconds / 60;
    seconds %= 60;

    printf("%dd %dh %dm %ds", days, hours, minutes, seconds);

    return 0;
}