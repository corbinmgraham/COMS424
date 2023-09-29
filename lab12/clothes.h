#ifndef CLOTHES_H
#define CLOTHES_H

typedef struct {
    int temp;
} clothes;

clothes* add_layer(const int temp);
int temp(clothes* layer);

#endif