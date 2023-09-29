#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int QueryOption()
{
    int option;
    printf("ENTER CHOICE: ");
    scanf("%i", &option);
    return option;
}

void ExecuteOption(const int option , node ** top)
{
    // Always display options
    int curr_temp = 50;
    system("clear");
    printf("Current temparature is %i degrees.\n", curr_temp);
    BodyTemp(curr_temp, *top);
    DisplayOptions();

    clothes* value;
    int size;
    switch(option) {
        case 1: // Enter a new value then push new node to stack
            printf("Adding a layer\n");
            Push(1, top);
            break;
        case 2: // Pop top value off of stack
            if (* top != NULL) {
                Pop(top, &value);
                printf ("Popped temp value = %i\n", temp(value));
            } else { printf ("Stack is empty .\n"); }
            break;
        case 3: // Peek at top value on stack
            if ((* top)!= NULL) {
                value = Peek(*top);
                printf("Peeked temp value is %i\n", temp(value));
            } else { printf ("Stack is empty .\n"); }
            break;

        case 4: // Display the entire stack
            DisplayStack(*top);
            break;
        case 5: // Print stack size
            size = GetStackSize(*top);
            printf("Stack size is %i\n", size);
            break;
        case 6: // Do nothing here , but this causes code to end
            break;
        default :
            printf ("Error : incorrect option . Try again .\n");
            break;
    }
}