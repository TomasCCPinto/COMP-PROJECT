
#ifndef __AST_H
#define __AST_H

#include <stdbool.h>
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *token_t;

typedef struct ASTNode ast_node_t;
struct ASTNode {
    char *id;
    token_t value;
    ast_node_t *first_child;
    ast_node_t *next_sibling;
};




token_t token(char *value, int type);

#endif // __AST_H