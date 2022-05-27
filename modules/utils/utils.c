#include "utils.h"

char *load_file_memory(char *file_name) {
  int i = 0;
  FILE *file = fopen(file_name, "r");
  char *buffer = (char*) malloc(sizeof(char)*1024);

  memset(buffer, '\0', sizeof(buffer));

  if (file == NULL) {
    printf("Falhou na abertura\n");
    return NULL;
  }

  while (!feof(file)) {
    buffer[i] = getc(file);
    i++;
  }

  buffer[i] = '\0';
  fclose(file);

  return buffer;
}

Linked_list_t *separate_tokens(char *tokens_buffer) {
  Linked_list_t *list_tokens = create_linked_list();
  Token_t *toks;

  char *token = strtok(tokens_buffer, "|");
  while (token) {
    toks = (Token_t*) malloc(sizeof(Token_t));

    toks->value = token;
    token = strtok(NULL, "|");
    toks->token = token;
    token = strtok(NULL, "|");

    insert_ending_linked_list(list_tokens, toks);
  }

  return list_tokens;
}

int istoken(char ch) {
  char toks[] = "(){}[];,+-*/=<>!";

  for (int i=0; i<17 ; i++) {
    if (ch == toks[i])
      return 1;
  }

  return 0;
}
