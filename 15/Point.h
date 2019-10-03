#ifndef HEADER_FILE_POINT
#define HEADER_FILE_POINT

struct Point {
    int x, y;
};

void point_print_coordinates(struct Point point);

void point_print(struct Point point);

char* point_to_string(struct Point point, char* string);

char* point_to_string_info(struct Point point, char* string);

int point_get_length(struct Point point);

#endif