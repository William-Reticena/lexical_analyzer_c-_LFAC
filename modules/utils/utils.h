#pragma once

// LIBRARY DEPENDENCIES
// ---------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../linked_list/linked_list.h"
// ---------------------------------------------

// FUNCTIONS
// ---------------------------------------------
char *load_file_memory(char *file_name);
Linked_list_t *separate_tokens(char *tokens_buffer);
int istoken(char ch);
// ---------------------------------------------
