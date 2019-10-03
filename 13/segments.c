#include <math.h>
#include <stdio.h>

struct Point {
    double x, y;
};

struct Segment {
    struct Point * a;
    struct Point * b;
};

double distance(struct Point a, struct Point b) {
    return pow(fabs(a.x - b.x) + fabs(a.y - b.y), 0.5);
}

struct Segment find_max_segment(struct Point a[], int length) {
    double maxDistance = distance(a[0], a[1]);
    int indeces[2] = {0,1};

    for(int i = 0; i < length - 1; i++) {
        for(int j = i + 1; j < length; j++) {
            double temp = distance(a[i], a[j]);
            if(temp > maxDistance) {
                indeces[0] = i; indeces[1] = j;
                maxDistance = temp;
            }
        }
    }

    struct Segment result;
    result.a = &a[indeces[0]];
    result.b = &a[indeces[1]];
    return result;
}


int demonstrate() {
    printf("Input count of points:");
    int count;
    scanf("%d", &count);

    struct Point points[count];

    for(int i = 0; i < count; i++)
        scanf("%lf %lf", &points[i].x, &points[i].y);

    struct Segment segment = find_max_segment(points, count);

    printf("a { %lf %lf }\n", segment.a->x, segment.a->y);
    printf("b { %lf %lf }", segment.b->x, segment.b->y);

    return 0;
}
