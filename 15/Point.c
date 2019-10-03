#include "Point.h"
#include "stdio.h"

struct Point;

void point_print_coordinates(struct Point point) {
    char buffer[point_get_length(point)];
    buffer[0] = '\0';
    printf("%s", point_to_string_info(point, buffer));
}

void point_print(struct Point point) {
    char buffer[point_get_length(point)];
    buffer[0] = '\0';
    printf("%s\n", point_to_string(point, buffer));
}


int point_get_length(struct Point point) {
    return 32;
}

char* point_to_string(struct Point point, char* string) {
    char buffer[point_get_length(point)];
    buffer[0] = '\0';
    memset(buffer, 0, sizeof(buffer));

    point_to_string_info(point, buffer);
    sprintf(string, "POINT (");
    strcat(string, buffer);
    strcat(string, ")");

    return string;
}

char* point_to_string_info(struct Point point, char* string) {
    char buffer[point_get_length(point)];
    buffer[0] = '\0';
    memset(buffer, 0, sizeof(buffer));

    sprintf(buffer, "%d %d", point.x, point.y);
    strcat(string, buffer);
    return string;
}