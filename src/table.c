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

symbol_table* symbol_table_node(char *id, char *value, bool is_param, bool is_func) {
    symbol_table *node = (symbol_table *) malloc(sizeof(symbol_table));

    if (node) {
        node->id = id;
        node->value = value;
        node->is_param = is_param;
        node->is_func = is_func;
      	node->params = NULL;

        node->next = NULL;
        node->symbols = NULL;
    }
    return node;
}



static void _print_params(param_list *head) {
  printf("(");
  if(head) {
    param_list *current = head;
    for (; current->next; current = current->next) {

      if (!strcmp(current->param, "Int")) {
        printf("int,");
      } else if (!strcmp(current->param, "Bool")) {
        printf("boolean,");
      } else if (!strcmp(current->param, "Double")) {
        printf("double,");
      } else if (!strcmp(current->param, "StringArray")) {
        printf("String[],");
      } else if (!strcmp(current->param, "Void")) {
        printf("void,");
      } else {
        printf("%s,", current->param);
      }
    }
    if (!strcmp(current->param, "Int")) {
      printf("int");
    } else if (!strcmp(current->param, "Bool")) {
        printf("boolean");
    } else if (!strcmp(current->param, "Double")) {
        printf("double");
    } else if (!strcmp(current->param, "StringArray")) {
        printf("String[]");
    } else if (!strcmp(current->param, "Void")) {
        printf("void");
    } else {
      printf("%s", current->param);
    }
  }
  printf(")");
}

static void _print_function_table(symbol_table *tabela) {

  if(tabela){

    if (tabela->is_func) {
      printf("===== Method %s", tabela->id);
	    _print_params(tabela->params);
      printf(" Symbol Table =====");
    } else {

      printf("%s\t", tabela->id);

      if (!strcmp(tabela->value, "Int")) {
        printf("\tint");
      } else if (!strcmp(tabela->value, "Bool")) {
        printf("\tboolean");
      } else if (!strcmp(tabela->value, "Double")) {
        printf("\tdouble");
      } else if (!strcmp(tabela->value, "StringArray")) {
        printf("\tString[]");
      } else if (!strcmp(tabela->value, "Void")) {
        printf("\tvoid");
      } else {
	      printf("\t%s", tabela->value);
      }
    }

    if (tabela->is_param)
      printf("\tparam");
    printf("\n");

    if (tabela->symbols)
      _print_function_table(tabela->symbols);
    /* else  */
    /*   printf("\n"); */
    } 
  }

void _print_table(symbol_table *tabela) {
  if(tabela){
    printf("%s\t", tabela->id);

    if (tabela->is_func) {
	    _print_params(tabela->params);
    }
      printf("\t");

    if (!strcmp(tabela->value, "Int")) {
      printf("int\n");
    } else if (!strcmp(tabela->value, "Bool")) {
        printf("boolean\n");
    } else if (!strcmp(tabela->value, "Double")) {
        printf("double\n");
    } else if (!strcmp(tabela->value, "StringArray")) {
        printf("String[]\n");
    } else if (!strcmp(tabela->value, "Void")) {
        printf("void\n");
    } else {
	    printf("%s\n", tabela->value);
    }

    if (tabela->symbols)
      _print_table(tabela->symbols);

    //_print_function_table(tabela->next);
  }
}

static void print_function(symbol_table *tabela) {
    if (tabela) {
	      if (tabela->next) {
	          printf("\n");
	          _print_function_table(tabela->next);
	      }
  	    print_function(tabela->symbols);
    }
}

void print_table(symbol_table *tabela){
  if(tabela){
      printf("===== %s %s Symbol Table =====\n", tabela->id, tabela->value);
    _print_table(tabela->symbols);
    // printf("\n");
    print_function(tabela);
  }
}
