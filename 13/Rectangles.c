#include <stdlib.h>

struct Point {
    double x, y;
};

struct Rectangle {
    struct Point first, second;
};

int is_point_inside_rectangle(struct Rectangle rectangle, struct Point point) {
    return point.x > rectangle.first.x && point.x < rectangle.second.x &&
        point.y > rectangle.first.y && point.y < rectangle.second.y;
}

struct Point** make_canonical_rectangle(struct Rectangle rectangle) {
    struct Point ** points = calloc(2, sizeof(struct Point));
    points[0] = &rectangle.first;
    points[1] = &rectangle.second;
    return points;
}


/*

int main() {
    struct Point firstPoint;
    firstPoint.x = 1;
    firstPoint.y = 3;

    struct Point secondPoint;
    secondPoint.x = 5;
    secondPoint.y = 10;

    struct Point thirdPoint;
    thirdPoint.x = 2;
    thirdPoint.y = 4;

    struct Rectangle figure;
    figure.first = firstPoint;
    figure.second = secondPoint;

    printf("Digits must be '1':\n");
    printf("\tis_point_inside_rectangle: %d ", is_point_inside_rectangle(figure, thirdPoint));
    thirdPoint.x = -1;
    printf("%d\n", is_point_inside_rectangle(figure, thirdPoint) == 0);

    struct Point ** points = make_canonical_rectangle(figure);
    printf("\tmake_canonical_rectangle: %d %d", points[0]->x == firstPoint.x && points[0]->y == firstPoint.y, points[1]->x == secondPoint.x && points[1]->y == secondPoint.y);

    return 0;
}

 */