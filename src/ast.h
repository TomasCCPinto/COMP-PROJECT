
#ifndef __AST_H
#define __AST_H

#include <stdbool.h>
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char *token_t;

typedef struct _ASTNode {
    char *id;

    struct _ASTNode *child;
    struct _ASTNode *brother;
} ast_node_t;




token_t token(char *value, int type);

ast_node_t *ast_node(char *id);
void add_children(ast_node_t *parent, ast_node_t *child);
void add_brother(ast_node_t *older_bother, ast_node_t *brother);


#endif // __AST_H
