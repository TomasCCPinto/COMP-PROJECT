

#include "ast.h"
#include "y.tab.h"


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

ast_node_t *ast_node(char *id) {
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
    }

    return node;
}

void add_children(ast_node_t *parent, ast_node_t *child) {
    if (parent) {
        parent->child = child;
    }
}

void add_brother(ast_node_t *older_brother, ast_node_t *brother) {
    if (older_brother) {
        older_brother->brother = brother;
    }
}