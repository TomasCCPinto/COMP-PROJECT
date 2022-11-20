#include "table.h"
#include <stdio.h>
#include <stdlib.h>


extern symbol_table *global_table;

param_list* param_list_node(char *param) {
  param_list *node = (param_list *) malloc(sizeof(param_list));

  if (node) {
    node->param = param;

    node->next = NULL;
  }
  return node;
}

symbol_table* symbol_table_node(char *id, char *value) {
    symbol_table *node = (symbol_table *) malloc(sizeof(symbol_table));

    if (node) {
        node->id = id;
        node->value = value;
      	node->params = NULL;

        node->next = NULL;
        node->symbols = NULL;
    }
    return node;
}



void _print_params(param_list *head) {
  if(head) {
    printf("(");
    param_list *current = head;
    for (; current->next; current = current->next) {
      printf("%s,", current->param);
    }
    printf("%s) ", current->param);


  }
}


void print_table(symbol_table *tabela){
    if(tabela){
      printf("%s ", tabela->id);

	    _print_params(tabela->params);

	    printf("%s\n", tabela->value);
      print_table(tabela->symbols);
      if (tabela->next) {
        printf("\n\nNova tabela: ");
        print_table(tabela->next);
      }
    }
}

