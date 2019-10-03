#ifndef HEADER_FILE_POLYGON
#define HEADER_FILE_POLYGON
#include "LineString.h"

struct Polygon {
    struct LineString * lineStrings;
    int count, allocatedLength;
};

void polygon_print(struct Polygon polygon);

void polygon_add_line_string(struct Polygon* polygon, struct LineString ls);

struct Polygon createEmptyPolygon();

int polygon_get_length(struct Polygon polygon);

char* polygon_to_string(struct Polygon polygon, char* string);

char* polygon_to_string_info(struct Polygon polygon, char* string);

#endif