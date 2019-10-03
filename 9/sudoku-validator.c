#include <stdio.h>

//Симуляция ограничений памяти 16-битного компьютера
int validate() {
    int rank, temp, flag = 1;
    printf("Enter sudoku rank:");
    scanf("%d", &rank);
    if(rank < 1 || rank > 8) flag = 0;
    int square = rank * rank, cube = rank * rank * rank;
    int sudoku[square][square];

    if(flag) {
        for (int i = 0; i < square * square; i++) {
            scanf("%d", &temp);
            if(temp < 1 || temp > square) flag = 0;
            sudoku[i / (square)][i % (square)] = temp;
        }
    }

    for(int i = 0; i < square && flag; i++) {
        long long int row = 0, col = 0, quad = 0;
        for(int j = 0; j < square && flag; j++) {
            row += 1 << sudoku[i][j] - 1;
            col += 1 << sudoku[j][i] - 1;
            temp = i*square+j % cube; //Обход квадрантов
            temp = //Используются 4 составляющие:
                    temp%rank //Переход на следующую клетку
                    + temp%square/rank*square // Переход на следующую строку внутри квадранта
                    + temp%cube/square*rank  // Переход на следующий квадрант в строке квадрантов
                    + temp/cube*cube; //Переход на следующую строку квадрантов
            quad += 1 << sudoku[temp/square][temp%square] - 1;
//            printf("%d ", temp);
        }
//        printf("\n%lld %lld %lld %d\n", row, col, quad, (1 << square) - 1);
        if(row + 1 != 1 << square) flag = 0;
        if(col + 1 != 1 << square) flag = 0;
        if(quad + 1 != 1 << square) flag = 0;
    }

    printf(flag ? "Correct" : "Incorrect");
    return 0;
}

/*
1 3 2 5 4 6 9 8 7
4 6 5 8 7 9 3 2 1
7 9 8 2 1 3 6 5 4
9 2 1 4 3 5 8 7 6
3 5 4 7 6 8 2 1 9
6 8 7 1 9 2 5 4 3
5 7 6 9 8 1 4 3 2
2 4 3 6 5 7 1 9 8
8 1 9 3 2 4 7 6 5

1 2 3 4
4 3 2 1
2 1 4 3
3 4 1 2

 */