/**
 * @file linkedlist.h
 * @author Corbin Graham
 * @brief Linked List Prototype for use across labs
 * 
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct pair {
    double x;
    double y;
} pair_t;

typedef struct node {
	void* data;
	struct node* next;
} Node;

typedef struct list {
	int size;
	Node* head;
} List;

List* create_list() {
	List* new_list = (List*)malloc(sizeof(List));
	new_list->size = 0;
	new_list->head = NULL;
	return new_list;
}

void add_to_list(List* list, void* data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = list->head;
	list->head = new_node;
	list->size++;
}

void* remove_from_list(List* list) {
	if (list->size == 0) {
		return NULL;
	}
	Node* node_to_remove = list->head;
	void* data = node_to_remove->data;
	list->head = node_to_remove->next;
	free(node_to_remove);
	list->size--;
	return data;
}

void free_list(List* list) {
	Node* current_node = list->head;
	while (current_node != NULL) {
		Node* next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	free(list);
}

// Standard print to file function prints a single string to a file
// Not related to linked list
void print_to_file(char* output, char* fname) {
    FILE* file = fopen(fname, "w");
    if(file != NULL) {
        fprintf(file, "%s", output);
    }
}

#endif