
#ifndef __AST_H
#define __AST_H

#include <stdbool.h>
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Token {
    char *value;
    int line;
    int col;
} token_t;

typedef struct _ASTNode {
    char *id;
    char *value;
    char *type;
    int line;
    int col;

    struct _ASTNode *child;
    struct _ASTNode *brother;
} ast_node_t;

#define NULL_TOKEN (token_t) { .value = NULL, .line = -1, .col = -1 }

extern bool syntax_error; 


token_t token(char *value, int line, int col, int type);

ast_node_t *ast_node(char *, token_t );
void add_children(ast_node_t *, ast_node_t *);
void add_brother(ast_node_t *, ast_node_t *);

void free_ast(ast_node_t *);
void print_ast(ast_node_t *);

void add_type(ast_node_t *, ast_node_t *);
int count(ast_node_t *);

#endif // __AST_H
