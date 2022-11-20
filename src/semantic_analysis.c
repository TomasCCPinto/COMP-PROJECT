#include "semantic_analysis.h"
#include "table.h"

// para a ast, o basta imprimir o type ou temos de adicionar ao no?
// para cada tabela de função, ela pode ser eliminada no final ca call?

/* static void _add_params(ast_node_t *node, param_list **head) { */
/*     if (!node) */
/* 	return; */
/*     if((*head)->next) { */
/* 	_add_params(node, &(*head)->next); */
/* 	return; */
/*     } */
/*     (*head)->next = param_list_node(node->child->id); */
/*     _add_params(node->brother, (head)); */
/* } */

/* static void add_params(ast_node_t *node, param_list **head) { */
/*     if (!node) */
/* 	return; */
/*     if (!(*head)) { */
/* 	printf("here\n"); */
/* 	*head = param_list_node(node->child->id); */
/* 	_add_params(node->brother, head); */
/* 	return; */
/*     } */
/*     printf("here1\n"); */
/*     _add_params(node, &(*head)->next); */
/*     printf("here2\n"); */
/* } */

static void add_params(ast_node_t *node, param_list **head) {
    if (!node)
	return;

    if (!(*head)) {
	    *head = param_list_node(node->child->id);
	    /* printf("1: %s\n", node->child->id); */
	    /* printf("12: %s\n", (*head)->param); */
	    /* printf("3:%s\n", node->id); */
	    add_params(node->brother, head);
	    return;
    }
    add_params(node, &(*head)->next);
    /* param_list **current = head; */
    /* while( (*current) && (*current)->next) { */
    /* 	(*current) = (*current)->next; */
    /* } */
    /* for (; (*current)->next; (*current) = (*current)->next); */
    
    /* (*current)->next = param_list_node(node->child->id); */
    /* add_params(node->brother, head); */
    /* printf("2: %s\n", node->child->id); */
    /* printf("21: %s\n", (*current)->next->param); */
}

// append to global table, functions
// TODO: append vardecl
static void append_symbol_table(ast_node_t *node, symbol_table *symbol_node) {
    if (symbol_node->symbols) {
        append_symbol_table(node, symbol_node->symbols);
	    return;
    }
    symbol_node->symbols = symbol_table_node(node->child->brother->value, node->child->id);
    if (node->child->brother->brother && node->child->brother->brother->child && !strcmp(node->child->brother->brother->child->id, "ParamDecl")) {
	    add_params(node->child->brother->brother->child, &symbol_node->symbols->params);
    }
}



static void new_function_table(ast_node_t *node, symbol_table *current_tab) {

    if (!node)
        return;

    if (!current_tab->next) {
        // começar a adicionar
        current_tab->next = symbol_table_node(node->child->brother->value, ""); 
        if (node->child->brother->brother && node->child->brother->brother->child && !strcmp(node->child->brother->brother->child->id, "ParamDecl")) {
	        add_params(node->child->brother->brother->child, &current_tab->next->params);
        }
    }
}

void semantic_analysis(ast_node_t *node) {
    if (!node) 
        return;
    if (!strcmp("Program", node->id)) {
        global_table = symbol_table_node("Class", node->child->value);
    }
    if (!strcmp("MethodDecl", node->id)) {
        append_symbol_table(node->child, global_table);

        symbol_table *current_tab = global_table;
        for (; current_tab->next; current_tab = current_tab->next);
        new_function_table(node->child, current_tab);
        // if (node->child && node->child->child && node->child->child && node->child->child->brother->value && !strcmp(node->child->child->brother->value, "main")) {
        //     printf("AAAAA\n");
        //     print_table(global_table);
        //     printf("AAAAA\n");
        // }
    }
    if (!strcmp("FieldDecl", node->id)) {
        append_symbol_table(node, global_table);
    }

    semantic_analysis(node->brother);
    semantic_analysis(node->child);
}
