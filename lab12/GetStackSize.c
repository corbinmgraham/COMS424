#include <stdlib.h>
#include "node.h"

int GetStackSize(node* top)
{
    if (top == NULL) {
        return 0; 
    }
    return 1 + GetStackSize(top->next);
}