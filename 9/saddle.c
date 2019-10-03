#include <stdio.h>
#include <math.h>

int saddle() {
    int rows, cols;
    printf("Enter row and cols:");
    scanf("%d %d", &rows, &cols);

    if(rows < 1 || cols < 1) {
        printf("Incorrect");
        return -1;
    }

    int rowMins[rows], colMaxs[cols], data[rows][cols], temp;

    int INT_MAX_VALUE = (int) (powl(2, 8*sizeof(int)) - 1);
    for(int i = 0; i < rows; i++) rowMins[i] = INT_MAX_VALUE;
    for(int i = 0; i < cols; i++) colMaxs[i] = -INT_MAX_VALUE - 1;

    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            scanf("%d", &temp); // Заменить на ввод много-на-строку
            if(temp < rowMins[row]) rowMins[row] = temp;
            if(temp > colMaxs[col]) colMaxs[col] = temp;
            data[row][col] = temp;
        }
    }

    for(int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            temp = data[row][col];
            if(rowMins[row] == temp && colMaxs[col] == temp)
                printf("(%d, %d) = %d\n", row, col, temp);
        }
    }

    return 0;
}