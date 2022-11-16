#include "ast.h"
#include "table.h"


extern symbol_table *global_table;

symbol_table* symbol_table_node(char *id, char *value) {
    symbol_table *node = (symbol_table *) malloc(sizeof(symbol_table));

    if (node) {
        node->id = id;
        node->value = value;

        node->next = NULL;
        node->symbols = NULL;
    }
    return node;
}




void print_table(symbol_table *tabela){
    if(tabela){
        printf("%s - %s\n", tabela->id, tabela->value);
        print_table(tabela->symbols);
    }
}

