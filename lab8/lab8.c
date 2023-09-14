#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node {
    struct node* next;
    double val;
} node_t;

node_t* head = NULL; // Reserving head for linked list
long list_size = 0;

void list_init(double val) {
    head = (node_t*) malloc(sizeof(node_t));
    head->next = NULL;
    head->val = val;
    list_size = 1;
} void list_add(double val) {
    if(head == NULL) {
        list_init(val);
        return;
    }
    node_t* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    node_t* next = (node_t*) malloc(sizeof(node_t));
    next->next = NULL;
    next->val = val;
    temp->next = next;
    list_size++;
} void for_list(char* name, double (*function)(double)) {
    node_t* temp = head;
    if(head == NULL) return;
    printf("Value After %s: %f ", name, (*function)(temp->val));
    while(temp->next != NULL) {
        temp = temp->next;
        printf("%f ", (*function)(temp->val));
    }
    printf("\n");
} char* list_print() {
    char list[10*list_size];
    if(head == NULL) {
        printf("List is empty.\n");
        return "List is empty.";
    }
    node_t* temp = head;
    char temp_str[10];
    sprintf(temp_str, "%f ", temp->val);
    printf("List Values: %s ", temp_str);
    strcpy(list, temp_str);
    while(temp->next != NULL) {
        temp = temp->next;
        sprintf(temp_str, "%f ", temp->val);
        printf("%s ", temp_str);
        strcat(list, temp_str);
    }
    printf("\n");
    return strdup(list);
} void list_clear() {
    node_t* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    list_size = 0;
}


double factorial(int x) {
    if(x <= 1) return 1;
    return x * factorial(x-1);
}
double factorial_helper(double x) { // This function is for linked list
    return factorial(((int) x));
}

double exp(double x) {
    double e = 2.7182818284509451; // Stored value for e
    int x0 = (int) x;
    double z = x-x0;
    double ex0 = pow(e,x0);
    
    double s = 0.0;
    for(int i = 0; i < 20; i++) {
        s = s + pow(z,i) / factorial(i);
    }
        
    return ex0 * s;
}

double ln(double x) {
    double s = x*10;
    for(int i = 0; i < 100; i++) {
        s = s - 1 + x * exp(-s);
    }
    return s;
}
void print_to_file(char* output) {
    FILE* file = fopen("output.txt", "w");
    if(file != NULL) {
        fprintf(file, "%s", output);
    }
}
int main(int argc, char* argv[]) {
    if (argc > 1) {
        char* ptr;
        for(int i = 1; i < argc; i++) {
            list_add(strtod(argv[i], &ptr));
        }
        char* save_list = list_print();
        printf("\nSaved List: %s\n", save_list);
        for_list("EXP", exp);
        for_list("FACTORIAL", factorial_helper);
        print_to_file(save_list);
        list_clear();
        return 0;
    }

    // EXAMPLE
    printf("Example List:\n");
    list_add(0.2);
    list_add(1.2);
    list_add(2.2);
    list_add(3.6);
    list_add(4.6);
    list_print();
    for_list("EXP", exp);
    for_list("FACTORIAL", factorial_helper);
    printf("\n");
    list_clear();

    double input;
    // Scan Input
    while(1) {
        printf("Please enter a floating point number OR -1 to print: ");
        scanf("%lf", &input);
        if(input == -1) break;
        list_add(input);
    }
    char* save_list = list_print();
    printf("\nSaved List: %s\n", save_list);
    for_list("EXP", exp);
    for_list("FACTORIAL", factorial_helper);
    print_to_file(save_list);
    list_clear();

    return 0;
}