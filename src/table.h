
#ifndef __TABLE_H
#define __TABLE_H

#include "ast.h"

typedef struct _symbol_table {
    token_t id;
    token_t value;

    struct _symbol_table *symbols;
    struct _symbol_table *next;
} symbol_table;



extern symbol_table *global_table;

symbol_table* symbol_table_node(char *id, char *value);
void print_table(symbol_table *tabela);

#endif // __TABLE_H
