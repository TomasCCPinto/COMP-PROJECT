

#include "ast.h"
#include "y.tab.h"
#include <stdio.h>


static int types[] = {
    ID,
    INTLIT,
    REALLIT,
    STRLIT
};


token_t token(char *value, int type) {
    for (int i = 0; i < 4; ++i) {
        if (type == types[i]) {
            return (char *) strdup(value);
        }
    }
    return NULL;
}

ast_node_t *ast_node(char *id, char *value) {
    /**
     * Create a AST node
     * 
     * id : type of non-terminal node
    */
    ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));

    if (node) {
        node->id = id;
        node->brother = NULL;
        node->child = NULL;
        node->value = value;
    }

    return node;
}

void _print_ast(ast_node_t *node, int level) {
    if (node != NULL) {
        for (int i = 0; i < level; ++i) {
            printf("..");
        }
        if (node->value) {
            printf("%s(%s)\n", node->id, node->value);
        } else {
            printf("%s\n", node->id);
        }
        _print_ast(node->child, level + 1);
        _print_ast(node->brother, level);
    }
}
void print_ast(ast_node_t *node) {
    _print_ast(node, 0);
}

void add_children(ast_node_t *parent, ast_node_t *child) {
    if (parent) {
        parent->child = child;
    }
}

void print_node(ast_node_t *node) {
    if (node) {
        if (node->child)
            printf("filho%s\n", node->child->id);

    }
}

void add_brother(ast_node_t *older_brother, ast_node_t *brother) {
    if (older_brother) {
        older_brother->brother = brother;
    }
}
