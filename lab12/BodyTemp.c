#include <stdio.h>
#include "node.h"

void BodyTemp(int curr_temp, node* top) {
    int temp = 96 - curr_temp + GetStackSize(top);
    if(temp < 94) printf("You are too cold. (%i degrees)\n", temp);
    else if(temp > 97) printf("You are too hot. (%i degrees)\n", temp);
    else printf("Your temperature is perfect!");
}