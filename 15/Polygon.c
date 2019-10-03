#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Polygon.h"

struct Polygon;

void polygon_print(struct Polygon polygon) {
    char buffer[polygon_get_length(polygon)];
    buffer[0] = '\0';
    printf("%s\n", polygon_to_string(polygon, buffer));
}

void polygon_add_line_string(struct Polygon* polygon, struct LineString ls) {
    struct Polygon pol = *polygon;

    //Если выделенная память и используемая равна (до добавления)
    if(pol.allocatedLength <= pol.count) {
        struct LineString *temp = calloc(polygon->allocatedLength * 2, sizeof(struct LineString));

        memmove(temp, pol.lineStrings, sizeof(struct LineString) * pol.allocatedLength);
        free(pol.lineStrings);

        polygon->allocatedLength *= 2;
        polygon->lineStrings = temp;
    }

    polygon->lineStrings[pol.count] = ls;
    polygon->count += 1;
}

struct Polygon createEmptyPolygon() {
    struct Polygon result;

    result.count = 0;
    result.allocatedLength = 3;
    result.lineStrings = calloc(result.allocatedLength, sizeof(struct LineString));

    return result;
}

int polygon_get_length(struct Polygon polygon) {
    int sum = 0;
    for(int i = 0; i < polygon.count; i++)
        sum += line_string_get_length(polygon.lineStrings[i]) + 4;
    return sum + 12;
}

char* polygon_to_string(struct Polygon polygon, char* string) {
    char buffer[polygon_get_length(polygon)];
    buffer[0] = '\0';
    polygon_to_string_info(polygon, buffer);

    strcat(string, "POLYGON (");
    strcat(string, buffer);
    strcat(string, ")");

    return string;
}

char* polygon_to_string_info(struct Polygon polygon, char* string) {
    char buffer[polygon_get_length(polygon)];
    buffer[0] = '\0';

    for(int i = 0; i < polygon.count; i++) {
        if(i) strcat(string, ", ");
        strcat(string, "(");
        strcat(string, line_string_to_string_info(polygon.lineStrings[i], buffer));
        strcat(string, ")");
        buffer[0] = '\0';
    }

    return string;
}