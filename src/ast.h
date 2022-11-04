
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
    char *value;

    struct _ASTNode *child;
    struct _ASTNode *brother;
} ast_node_t;




token_t token(char *value, int type);

ast_node_t *ast_node(char *id, char *);
void add_children(ast_node_t *parent, ast_node_t *child);
void add_brother(ast_node_t *older_bother, ast_node_t *brother);
void print_ast(ast_node_t *);


void print_node(ast_node_t *node);
void add_type(ast_node_t *type, ast_node_t *give_me_type);

#endif // __AST_H
