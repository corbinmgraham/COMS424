#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "clothes.h"

void Push(const int tempa, node** top)
{
    if (*top == NULL) {
        *top = (node*) malloc(sizeof(struct node));
        (*top)->next = NULL;
        (*top)->value = add_layer(tempa);
        (*top)->position = 1;
    } else {
        node* temp;
        temp = (node *) malloc(sizeof(struct node));
        temp->next = *top;
        temp->value = add_layer(tempa);
        temp->position = 1;
        *top = temp;

        node* ptr = (*top)->next;
        while (ptr != NULL) {
            ptr->position = ptr->position+1;
            ptr = ptr ->next;
        }
    }
}