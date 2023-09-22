#include "quad_perimeter.h"

double get_perimeter(rectangle_t* rectangle) {
    double perimeter = 0;
    perimeter += get_width(rectangle);
    perimeter += get_height(rectangle);
    return perimeter*2;
}