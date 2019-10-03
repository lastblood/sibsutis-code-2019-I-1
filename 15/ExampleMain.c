#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Point.c"
#include "LineString.c"
#include "Polygon.c"

int exampleMain() {
    int countOfLineStrings, countOfPoints;
    printf("count of lines:");
    scanf("%d", &countOfLineStrings);

    printf("count of points:");
    scanf("%d", &countOfPoints);

    if(countOfLineStrings < 1 || countOfPoints < 1) exit(-1);

    srand(time(NULL));
    printf("\n");

    struct Polygon polygon = createEmptyPolygon();

    for(int i = 0; i < countOfLineStrings; i++) {
        struct LineString lineString = createEmptyLineString();

        for (int j = 0; j < countOfPoints; j++) {
            struct Point tempPoint = {
                    .x = rand() % 20,
                    .y = rand() % 20
            };

            point_print(tempPoint);
            line_string_add_point(&lineString, tempPoint);
        }

        line_string_print(lineString);
        printf("\n");
        polygon_add_line_string(&polygon, lineString);
    }

    polygon_print(polygon);

    return 0;
}