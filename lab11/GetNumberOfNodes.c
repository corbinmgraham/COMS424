#include <stdio.h>
#include "node.h"

int GetNumberOfNodes() {
    int num_nodes;
    printf("Enter Number of Nodes: ");
    scanf("%d", &num_nodes);
    return num_nodes;
}