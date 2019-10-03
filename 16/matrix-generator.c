#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trimStr(char * s) {
    char * p = s;
    int l = strlen(p);

    while(isspace(p[l - 1])) p[--l] = 0;
    while(* p && isspace(* p)) ++p, --l;

    memmove(s, p, l + 1);
}


int randomWriteInFile(FILE* file, int rows, int columns) {
    fprintf(file, "%d %d\n", rows, columns);
    srand(time(NULL));

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            fprintf(file, "%d ", rand() % 20 - 10);
        }
        fprintf(file, "\n");
    }
}


int generate() {
    int rows, columns;
    char fileName[256];

    printf("Enter path to file:");
    char *filePath = gets(fileName);

    printf("Enter rows and columns:");
    scanf("%d %d", &rows, &columns);
    
    if(rows < 1 || columns < 1 || filePath == NULL) {
        printf("Wrong input");
        return -1;
    }

    trimStr(fileName);
    FILE *file = fopen(fileName, "w");
    if(file == NULL) {
        printf("Can't open file");
        exit(-1);
    }

    printf("Generating...");
    randomWriteInFile(file, rows, columns);
    int status = fclose(file);
    printf(status == EOF ? "can't close file" : "Done!");

    return 0;
}
