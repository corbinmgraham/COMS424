#include <stdio.h>

char GetKey(){
    char throwaway;
    char key;
    scanf("%c", &throwaway);
    printf("Enter key to search: ");
    scanf("%c", &key);
    // printf("What is going on here: '%c'", key);
    return key;
}