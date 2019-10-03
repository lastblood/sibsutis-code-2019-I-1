#ifndef HEADER_FILE_LINESTRING
#define HEADER_FILE_LINESTRING
#include "Point.h"

struct LineString {
    struct Point * points;
    int count, allocatedLength;
};

void line_string_print(struct LineString lineString);

void line_string_print_coordinates(struct LineString lineString);

void line_string_add_point(struct LineString * lineString, struct Point p);

struct LineString createEmptyLineString();

int line_string_get_length(struct LineString lineString);

char* line_string_to_string(struct LineString lineString, char* string);

char* line_string_to_string_info(struct LineString lineString, char* string);

#endif