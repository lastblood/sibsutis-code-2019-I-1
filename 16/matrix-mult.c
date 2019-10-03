#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Matrix {
    int x;
    int y;
    int * matrix;
};

void trim(char * s) {
    char * p = s;
    int l = strlen(p);

    while(isspace(p[l - 1])) p[--l] = 0;
    while(* p && isspace(* p)) ++p, --l;

    memmove(s, p, l + 1);
}

//Валидация данных не производится
struct Matrix read_matrix(char fileName[], struct Matrix m) {
    FILE * fp;
    if((fp = fopen(fileName, "r")) == NULL) {
        printf("Wrong filename");
        exit(-1);
    }

    char str[512];

    int x = 0, y = 0;
    fscanf(fp, "%d %d", &y, &x);

    int * matrix = calloc(x * y, sizeof(int));

    for(int i = 0; i < x*y; i++)
        fscanf(fp, "%d", &matrix[i]);

    m.x = x;
    m.y = y;
    m.matrix = matrix;

    fclose(fp);

    return m;
}


void printMatrix(struct Matrix m) {
    printf("%d %d\n", m.x, m.y);
    for(int i = 0; i < m.y; i++) {
        for(int j = 0; j < m.x; j++) {
            printf("%d ", m.matrix[i * m.x + j]);
        }

        printf("\n");
    }
    printf("\n\n");
}


int mult() {
    char fileName[255];

    fgets(fileName, 255, stdin);
    trim(fileName);
    struct Matrix firstMatrix = read_matrix(fileName, firstMatrix);

    fgets(fileName, 255, stdin);
    trim(fileName);
    struct Matrix secondMatrix = read_matrix(fileName, secondMatrix);


    if(firstMatrix.x != secondMatrix.y) {
        printf("Wrong matrix size");
        exit(-1);
    }

//    printf("\nfirstMatrix.x = %d, firstMatrix.y = %d\n", firstMatrix.x, firstMatrix.y);
//    printf("secondMatrix.x = %d, secondMatrix.y = %d\n\n", secondMatrix.x, secondMatrix.y);

    int x, y;

    struct Matrix resultMatrix;
    resultMatrix.x = secondMatrix.x;
    resultMatrix.y = firstMatrix.y;
    resultMatrix.matrix = calloc(firstMatrix.y * secondMatrix.x, sizeof(int));

    for(int i = 0; i < firstMatrix.y * secondMatrix.x; i++) {
        int sum = 0;
        x = i % secondMatrix.x;
        y = i / secondMatrix.x;

        for(int j = 0; j < firstMatrix.x; j++) {
            int acoord = j + y * firstMatrix.x;
            int bcoord = x + j * secondMatrix.x;
//            printf("%d %d\n", acoord, bcoord);
            sum += firstMatrix.matrix[acoord] * secondMatrix.matrix[bcoord];
        }

        resultMatrix.matrix[i] = sum;
    }

    printMatrix(resultMatrix);

    return 0;
}