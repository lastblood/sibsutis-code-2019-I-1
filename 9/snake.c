#include <stdio.h>
#include <math.h>

int numberLength(int number) {
    if(number < 1) return 1;
    int length = ceil(log10(number + 1));
    return length;
}

int snake() {
    int rows, cols, flag = 1;
    printf("Enter rows and cols number:");
    scanf("%d %d", &rows, &cols);

    int cellLength = numberLength(rows * cols - 1) + 2;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int n = i*cols + (flag ? j : cols-1-j);
            printf("%d", n);
            for(int x = numberLength(n); x < cellLength; x++) {
                printf(" ");
            }
        }
        printf("\n");
        flag = flag ? 0 : 1;
    }
    return 0;
}