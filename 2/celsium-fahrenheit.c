#include <stdio.h>

int cf() {
    int celsium;
    scanf("%d", &celsium);
    int fahrenheit = celsium * 9 / 5 + 32;
    printf("%d", fahrenheit);
    return 0;
}