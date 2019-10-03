#include "LineString.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LineString;

void line_string_add_point(struct LineString * lineString, struct Point p) {
    struct LineString ls = *lineString;

    //Если выделенная память и используемая равна (до добавления)
    if(ls.allocatedLength <= ls.count) {
        struct Point *temp = calloc(lineString->allocatedLength * 2, sizeof(struct Point));

        memmove(temp, ls.points, sizeof(struct Point) * ls.allocatedLength);
        free(ls.points);

        lineString->allocatedLength *= 2;
        lineString->points = temp;
    }
    lineString->points[ls.count] = p;
    lineString->count += + 1;
}


void line_string_print(struct LineString lineString) {
    char buffer[line_string_get_length(lineString)];
    buffer[0] = '\0';
    printf("%s\n", line_string_to_string(lineString, buffer));
}


void line_string_print_coordinates(struct LineString lineString) {
    char buffer[line_string_get_length(lineString)];
    buffer[0] = '\0';
    printf("%s", line_string_to_string_info(lineString, buffer));
}


int line_string_get_length(struct LineString lineString) {
    return 14 + 30*lineString.count;
}

char* line_string_to_string(struct LineString lineString, char* string) {
    char buffer[line_string_get_length(lineString)];
    buffer[0] = '\0';
    line_string_to_string_info(lineString, buffer);

    strcat(string, "LINESTRING (");
    strcat(string, buffer);
    strcat(string, ")");

    return string;
}

char* line_string_to_string_info(struct LineString lineString, char* string) {
    char buffer[line_string_get_length(lineString)];
    buffer[0] = '\0';

    for(int i = 0; i < lineString.count; i++) {
        if(i) strcat(string, ", ");
        strcat(string, point_to_string_info(lineString.points[i], buffer));
        buffer[0] = '\0';
    }
    return string;
}


//struct should be created by this function
struct LineString createEmptyLineString() {
    struct LineString result;

    result.count = 0;
    result.allocatedLength = 3;
    result.points = calloc(result.allocatedLength, sizeof(struct Point));

    return result;
}