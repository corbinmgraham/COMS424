#ifndef __NODE_H__
#define __NODE_H__

#include "clothes.h"

typedef struct node node;
struct node
{
    int position;
    clothes* value;
    node* next;
};

// Functions associated with stack
clothes* Peek(node* top);
void Pop(node ** top, clothes** output);
void Push(const int tempa, node** top);
void DeleteStack(node** top);
int GetStackSize(node* top);

// Associate Functions
void DisplayStack(node* top);
void PrintNode(node* top);
int QueryOption();
void ExecuteOption(const int option, node ** top);
void DisplayOptions();

void BodyTemp(int curr_temp, node* top);

#endif