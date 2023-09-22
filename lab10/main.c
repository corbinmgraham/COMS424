#include "rectangle.h"
#include "quad_area.h"
#include "quad_perimeter.h"
#include <stdio.h>

int main() {
    // point_t* point1 = new_point(-2.0, 2.0);
    // point_t* point2 = new_point(2.0, 2.0);
    // point_t* point3 = new_point(-2.0, 0.0);
    // point_t* point4 = new_point(2.0, 0.0);
    // point_t* points[4] = {
    //     point1,
    //     point2,
    //     point3,
    //     point4
    // };
    double x,y;
    point_t* points[4];
    for(int i = 0; i < 4; i++) {
        printf("Enter a set of points: ");
        scanf("%lf %lf", &x, &y);
        points[i] = new_point(x, y);
    }
    rectangle_t* rectangle = new_rectangle(points);
    printf("Area: %f\nPerimeter: %f",
        get_area(rectangle), get_perimeter(rectangle));
    return 0;
}