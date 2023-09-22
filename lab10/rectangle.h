#ifndef RECTANGLE_H
#define RECTANGLE_H

typedef struct {
    double x;
    double y;
} point_t;
typedef struct {
    point_t** points;
} rectangle_t;

point_t* new_point(double x, double y);
double* get_x(point_t* point);
double* get_y(point_t* point);

rectangle_t* new_rectangle(point_t* points[4]);

double get_distance(point_t* a, point_t* b);
double get_height(rectangle_t* rectangle);
double get_width(rectangle_t* rectangle);

#endif