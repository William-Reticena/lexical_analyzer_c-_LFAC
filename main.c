#include <ctype.h>
#include "./modules/utils/utils.h"

int main(int argc, char *argv[]) {
  char *token_file = load_file_memory("./modules/utils/token_list.txt");
  Linked_list_t *token_list = separate_tokens(token_file);
  char *file_input = load_file_memory(argv[1]);
  // char *file_input = load_file_memory("./examples/example1.cm");
  char buffer[50];
  int length_file_input = strlen(file_input),
      state = 0,
      error = 0,
      i = 0;

  for (int ctrl=0; ctrl<length_file_input-1; ctrl++) {
    if (state == 0) {
      if (isalpha(file_input[ctrl])) {
        buffer[i++] = file_input[ctrl];
        state = 1;

      } else if (isblank(file_input[ctrl]) || file_input[ctrl] == '\n') {
        continue;

      } else {
        error = 1;
        break;
      }
    } else if (state == 1) {
      if (isalpha(file_input[ctrl]) || isdigit(file_input[ctrl]) || file_input[ctrl] == '\n') {
        buffer[i++] = file_input[ctrl];

        if ((!isalpha(file_input[ctrl+1])) || (isdigit(file_input[ctrl+1])) || (file_input[ctrl+1] == '\n')) {
          buffer[i] = '\0';
          search_linked_list(token_list, buffer);
          i = 0;
        }
        continue;

      } else if (isblank(file_input[ctrl])) {
        buffer[i] = '\0';

        if (buffer[0] != '\0') {
          search_linked_list(token_list, buffer);
          i = 0;
        }

        state = 2;

      } else if (istoken(file_input[ctrl])) {
        buffer[i++] = file_input[ctrl];
        buffer[i] = '\0';
        search_linked_list(token_list, buffer);
        i = 0;
        state = 3;

      } else {
        error = 1;
        break;
      }
    } else if (state == 2) {
      if (isalpha(file_input[ctrl])) {
        buffer[i++] = file_input[ctrl];
        if (istoken(file_input[ctrl+1])) {
          buffer[i] = '\0';
          search_linked_list(token_list, buffer);
          i = 0;
        }
        state = 1;

      } else if (isblank(file_input[ctrl]) || file_input[ctrl] == '\n') {
        continue;

      } else if (istoken(file_input[ctrl])) {
        buffer[i++] = file_input[ctrl];
        if (file_input[ctrl+1] == '=') {
          buffer[i++] = file_input[++ctrl];
        }

        buffer[i] = '\0';
        search_linked_list(token_list, buffer);
        i = 0;
        state = 3;

      } else {
        error = 1;
        break;
      }
    } else if (state == 3) {
      if (isalpha(file_input[ctrl])) {
        buffer[i++] = file_input[ctrl];
        if (istoken(file_input[ctrl+1])) {
          buffer[i] = '\0';
          search_linked_list(token_list, buffer);
          i = 0;
        }
        state = 1;

      } else if (isblank(file_input[ctrl]) || file_input[ctrl] == '\n') {
        continue;

      } else if (istoken(file_input[ctrl])) {
        buffer[i++] = file_input[ctrl];
        buffer[i] = '\0';
        search_linked_list(token_list, buffer);
        i = 0;
        state = 6;

      } else if (isdigit(file_input[ctrl])) {
        buffer[i++] = file_input[ctrl];

        if (file_input[ctrl+1] != '.' && !isdigit(file_input[ctrl+1])) {
          printf("NUMBER\n");
          i = 0;
        }
        state = 4;

      } else {
        error = 1;
        break;
      }
    } else if (state == 4) {
      if (isdigit(file_input[ctrl])) {
        buffer[i++] = file_input[ctrl];
        if (!isdigit(file_input[ctrl+1])) {
          printf("NUMBER\n");
          i = 0;
        }
        continue;

      } else if (isblank(file_input[ctrl]) || istoken(file_input[ctrl])) {
        buffer[i++] = file_input[ctrl];
        buffer[i] = '\0';
        search_linked_list(token_list, buffer);
        i = 0;
        state = 3;

      } else if (file_input[ctrl] == '.') {
        buffer[i++] = file_input[ctrl];
        state = 5;

      } else {
        error = 1;
        break;
      }
    } else if (state == 5) {
      if (isdigit(file_input[ctrl])) {
        buffer[i++] = file_input[ctrl];
        if (!isdigit(file_input[ctrl+1])) {
          printf("NUMBER\n");
          i = 0;
        }
        continue;

      } else if (isblank(file_input[ctrl]) || istoken(file_input[ctrl])) {
        buffer[i++] = file_input[ctrl];
        buffer[i] = '\0';
        search_linked_list(token_list, buffer);
        i = 0;
        state = 3;

      } else {
        error = 1;
        break;
      }
    } else if (state == 6) {
      if (isalpha(file_input[ctrl])) {
        buffer[i++] = file_input[ctrl];
        state = 1;

      } else if (isdigit(file_input[ctrl])) {
        state = 4;

      } else if (istoken(file_input[ctrl]) || isblank(file_input[ctrl]) || file_input[ctrl] == '\n') {
        buffer[i++] = file_input[ctrl];
        if (buffer[0] != '\n' && !isblank(buffer[0])){
          buffer[i] = '\0';
          search_linked_list(token_list, buffer);
        }
        i = 0;
        continue;

      } else {
        error = 1;
        break;
      }
    }
  }

  if (error) {
    printf("Erro de sintaxe\n");
    return 1;
  }

  return 0;
}
