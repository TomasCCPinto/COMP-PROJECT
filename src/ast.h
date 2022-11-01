
#ifndef __AST_H
#define __AST_H

#include <stdbool.h>
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char *token_t;

typedef struct ASTNode {
    char *id;
}ast_node_t;




token_t token(char *value, int type);

#endif // __AST_H
