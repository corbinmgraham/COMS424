#include <stdlib.h>
#include "clothes.h"

clothes* add_layer(const int temp) {
    clothes* new_layer = (clothes*) malloc(sizeof(clothes*));
    new_layer->temp = temp;
    return new_layer;
}