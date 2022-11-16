#include "semantic_analysis.h"
#include "table.h"



void append_function_table(ast_node_t *node, symbol_table *symbol_node) {
    if (symbol_node->symbols) {
        append_function_table(node, symbol_node->symbols);
    } else {
        symbol_node->symbols = symbol_table_node(node->child->brother->value, node->child->id);
    }
}


void semantic_analysis(ast_node_t *node) {
    if (!node) 
        return;
    if (!strcmp("Program", node->id)) {
        global_table = symbol_table_node("Class", node->child->value);
    }
    if (!strcmp("MethodHeader", node->id)) {
        append_function_table(node, global_table);
    }
    if (!strcmp("FieldDecl", node->id)) {
        append_function_table(node, global_table);
    }

    semantic_analysis(node->brother);
    semantic_analysis(node->child);
}
