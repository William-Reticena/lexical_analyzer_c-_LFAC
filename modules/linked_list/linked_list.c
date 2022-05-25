#include "linked_list.h"

Linked_list_t *create_linked_list(void) {
  Linked_list_t *list = (Linked_list_t*) malloc(sizeof(Linked_list_t));

  list->linker_node_list = NULL;
  list->number_elements = 0;

  return list;
}

int insert_beginning_linked_list(Linked_list_t *list, Token_t *element) {
  if (list == NULL) return 1;

  Node_linked_list *node = (Node_linked_list*) malloc(sizeof(Node_linked_list));

  node->token_object = element;
  node->next = list->linker_node_list;

  list->linker_node_list = node;
  list->number_elements++;

  return 0;
}

int insert_ending_linked_list(Linked_list_t *list, Token_t *element) {
  if (list == NULL) return 1;

  Node_linked_list *n, *node = (Node_linked_list*) malloc(sizeof(Node_linked_list));

  node->token_object = element;
  node->next = NULL;

  if (list->linker_node_list == NULL) {
    list->linker_node_list = node;
  } else {
    n = list->linker_node_list;

    while (n->next != NULL)
      n = n->next;

    n->next = node;
  }
    list->number_elements++;

    return 0;
}

void print_linked_list(Linked_list_t *list) {
  if (list == NULL) return;

  Node_linked_list *node = list->linker_node_list;

  int i = 1;
  while (node != NULL) {
    printf("%d - value: %s\n", i++, node->token_object->value);
    printf("token: %s\n", node->token_object->token);

    node = node->next;
  }
}

char *search_linked_list(Linked_list_t *list, char *element) {
  if (list == NULL) return NULL;

  Node_linked_list *node = list->linker_node_list;

  while (node != NULL) {
    if (strcmp(node->token_object->value, element) == 0) {
      printf("%s\n", node->token_object->token);
      return node->token_object->value;
    }

    node = node->next;
  }

  if (node == NULL) printf("ID\n");

  return NULL;
}

int remove_linked_list(Linked_list_t *list, Token_t *element) {
  if (list == NULL) return 1;

  Node_linked_list *node = list->linker_node_list;
  Node_linked_list *node_remove = NULL;

  if (node != NULL && list->linker_node_list->token_object == element) {
    node_remove = list->linker_node_list;
    list->linker_node_list = node_remove->next;
  } else {
    while (node != NULL && node->next != NULL && node->next->token_object == element) {
      node_remove = node->next;
      node->next = node_remove->next;
    }
  }
  if (node_remove != NULL) {
    free(node_remove);
    list->number_elements--;
  }

}
