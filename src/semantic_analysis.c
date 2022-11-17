#include "semantic_analysis.h"
#include "ast.h"
#include "table.h"
#include <stdio.h>



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
	printf("1: %s\n", node->child->id);
	printf("12: %s\n", (*head)->param);
	printf("3:%s\n", node->id);
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





static void append_function_table(ast_node_t *node, symbol_table *symbol_node) {
    if (symbol_node->symbols) {
        append_function_table(node, symbol_node->symbols);
	return;
    }
    symbol_node->symbols = symbol_table_node(node->child->brother->value, node->child->id);
    if (!strcmp(node->child->brother->value, "main")) {
	printf("main\n");
	/* print_ast(node->child->brother); */
    }
    if (node->child->brother->brother && node->child->brother->brother->child && !strcmp(node->child->brother->brother->child->id, "ParamDecl")) {
	add_params(node->child->brother->brother->child, &symbol_node->symbols->params);
	printf("\n\n");
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
