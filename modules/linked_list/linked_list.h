#pragma once

// LIBRARY DEPENDENCIES
// ---------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../obj_types.h"
// ---------------------------------------------

typedef struct node_linked_list {
  Token_t *token_object;
  struct node_linked_list *next;
}Node_linked_list;

typedef struct {
  int number_elements;
  Node_linked_list *linker_node_list;
}Linked_list_t;

Linked_list_t *create_linked_list(void);
int insert_beginning_linked_list(Linked_list_t *list, Token_t *element);
int insert_ending_linked_list(Linked_list_t *list, Token_t *element);
void print_linked_list(Linked_list_t *list);
char *search_linked_list(Linked_list_t *list, char *element);
int remove_linked_list(Linked_list_t *list, Token_t *element);
