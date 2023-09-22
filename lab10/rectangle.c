#include "rectangle.h"
#include <stdlib.h>
#include <math.h>

point_t* new_point(double x, double y) {
    point_t* point = (point_t*) malloc(sizeof(point_t));
    point->x = x;
    point->y = y;
    return point;
}
double* get_x(point_t* point) {
    return &point->x;
}
double* get_y(point_t* point) {
    return &point->y;
}

rectangle_t* new_rectangle(point_t* points[4]) {
    rectangle_t* rectangle = (rectangle_t*) malloc(sizeof(rectangle_t));
    rectangle->points = points;
    return rectangle;
}

double get_distance(point_t* a, point_t* b) {
    double* x1 = get_x(a);
    double* x2 = get_x(b);
    double* y1 = get_y(a);
    double* y2 = get_y(b);
    return fabs(sqrt(pow((*x2-*x1),2)+pow((*y2-*y1),2)));
}
double get_height(rectangle_t* rectangle) {
    return get_distance(
        rectangle->points[1],
        rectangle->points[3]
    );
}
double get_width(rectangle_t* rectangle) {
    return get_distance(
        rectangle->points[0],
        rectangle->points[1]
    );
}