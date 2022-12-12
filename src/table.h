
#ifndef __TABLE_H
#define __TABLE_H


#include "ast.h"


typedef struct _param_list {
  char *param;

  struct _param_list *next;
} param_list;

typedef struct _symbol_table {
    char *id;
    char *value;
    bool is_param;
    bool is_func;
    param_list *params;

    struct _symbol_table *symbols;
    struct _symbol_table *next;
} symbol_table;



extern symbol_table *global_table;

symbol_table* symbol_table_node(char *id, char *value, bool is_param, bool is_func);
param_list *param_list_node(char *param);

void print_table(symbol_table *tabela);
void free_table(symbol_table *head);

#endif // __TABLE_H
