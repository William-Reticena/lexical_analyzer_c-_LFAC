// #include "./modules/lexical_analyzer.h"
#include <ctype.h>
#include "./modules/utils/utils.h"

int main() {
  char *file_input = load_file_memory("./examples/example3.cm");
  int length_file_input = strlen(file_input),
      state = 0,
      error = 0;

  printf("%s\n", file_input);

  // lexical_analyzer(file_input, length_file_input);

  for (int ctrl=0; ctrl<length_file_input-1; ctrl++) {
    if (state == 0) {
      if (isalpha(file_input[ctrl])) {
        printf("q0 alpha: %c\n", file_input[ctrl]);
        state = 1;

      } else if (isblank(file_input[ctrl]) || file_input[ctrl] == '\n') {
        printf("q0 blank:\n");
        continue;

      } else {
        error = 1;
        break;
      }
    } else if (state == 1) {
      if (isalpha(file_input[ctrl]) || isdigit(file_input[ctrl]) || file_input[ctrl] == '\n') {
        printf("q1 alpha: %c\n", file_input[ctrl]);
        continue;

      } else if (isblank(file_input[ctrl])) {
        printf("q1 blank:\n");
        state = 2;
        // continue;

      } else if (istoken(file_input[ctrl])) {
        printf("q1 token: %c\n", file_input[ctrl]);
        state = 3;
        // continue;

      } else {
        error = 1;
        break;
      }
    } else if (state == 2) {
      if (isalpha(file_input[ctrl])) {
        printf("q2 alpha: %c\n", file_input[ctrl]);
        state = 1;

      } else if (isblank(file_input[ctrl]) || file_input[ctrl] == '\n') {
        printf("q2 blank:\n");
        continue;

      } else if (istoken(file_input[ctrl])) {
        printf("q2 token: %c\n", file_input[ctrl]);
        state = 3;
        // continue;

      } else {
        error = 1;
        break;
      }
    } else if (state == 3) {
      if (isalpha(file_input[ctrl])) {
        printf("q3 alpha: %c\n", file_input[ctrl]);
        state = 1;

      } else if (isblank(file_input[ctrl]) || file_input[ctrl] == '\n') {
        printf("q3 blank:\n");
        continue;

      } else if (istoken(file_input[ctrl])) {
        printf("q3 token: %c\n", file_input[ctrl]);
        state = 6;
        // continue;

      } else if (isdigit(file_input[ctrl])) {
        printf("q3 digit: %c\n", file_input[ctrl]);
        state = 4;
        // continue;

      } else {
        error = 1;
        break;
      }
    } else if (state == 4) {
      if (isdigit(file_input[ctrl])) {
        printf("q4 digit: %c\n", file_input[ctrl]);
        continue;

      } else if (isblank(file_input[ctrl]) || istoken(file_input[ctrl])) {
        printf("q4 token: %c\n", file_input[ctrl]);
        state = 3;

      } else if (file_input[ctrl] == '.') {
        printf("q4 dot: %c", file_input[ctrl]);
        state = 5;
        // continue;

      } else {
        error = 1;
        break;
      }
    } else if (state == 5) {
      if (isdigit(file_input[ctrl])) {
        printf("q5 digit: %c\n", file_input[ctrl]);
        continue;

      } else if (isblank(file_input[ctrl]) || istoken(file_input[ctrl])) {
        printf("q5 token: %c\n", file_input[ctrl]);
        state = 3;

      } else {
        error = 1;
        break;
      }
    } else if (state == 6) {
      if (isalpha(file_input[ctrl])) {
        printf("q6 alpha: %c\n", file_input[ctrl]);
        state = 1;

      } else if (isdigit(file_input[ctrl])) {
        printf("q6 digit: %c\n", file_input[ctrl]);
        state = 4;

      } else if (istoken(file_input[ctrl]) || isblank(file_input[ctrl]) || file_input[ctrl] == '\n') {
        printf("q5 token: %c\n", file_input[ctrl]);
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