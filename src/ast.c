

#include "ast.h"
#include "y.tab.h"
#include <stdio.h>

extern int syntax_error ; 

static int types[] = {
    ID,
    INTLIT,
    REALLIT,
    STRLIT,
    BOOLLIT
};


token_t token(char *value, int line, int col, int type) {
    token_t token = {.value = NULL, .line = line, .col = col};
    //printf("%d - %d\n", token.line, token.col);
    //printf("%s\n", value);

    if (type == types[3]) {
        char *aux = (char *) malloc(sizeof(char)*(strlen(value)+1));
        sprintf(aux, "\"%s", value);
        token.value = (char *) strdup(aux);

        free(aux);
        return token;
    }
    token.value = (char *) strdup(value);
    return token;

    /*for (int i = 0; i < 5; ++i) {
        if (type == types[i]) {
            token.value =  (char *) strdup(value);
            return token;
        }
    }

    token.value =  (char *) strdup(value);
    return token;*/
}

ast_node_t *ast_node(char *id, token_t token) {

    //printf("%d - %d - %s\n", token.line, token.col, token.value);
    ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));

    if (node) {
        node->id = id;
        node->brother = NULL;
        node->child = NULL;
        node->value = token.value;
        node->type = NULL;
        node->line = token.line;
        node->col = token.col;
    }

    return node;
}

void add_children(ast_node_t *parent, ast_node_t *child) {
    if (parent) {
        parent->child = child;
    }
}

void add_brother(ast_node_t *older_brother, ast_node_t *brother) {
    if (older_brother && brother) {
        older_brother->brother = brother;
    }
}

static void _print_ast(ast_node_t *node, int level) {
    if (node != NULL) {
        for (int i = 0; i < level; ++i) {
            printf("..");
        }
        if (node->value) {
            if (node->value[0] == '"') {
                int pos = strlen(node->value);
                while(node->value[pos - 1] != '"') {
                    node->value[pos - 1] = '\0';
                    pos--;
                }
            } 
            printf("%s(%s)", node->id, node->value);
        } else {
            printf("%s", node->id);
        }

        if (node->type) {

            if (!strcmp(node->type, "Int")) {
              printf(" - int\n");
            } else if (!strcmp(node->type, "Bool")) {
              printf(" - boolean\n");
            } else if (!strcmp(node->type, "Double")) {
              printf(" - double\n");
            } else if (!strcmp(node->type, "StringArray")) {
              printf(" - String[]\n");
            } else if (!strcmp(node->type, "Void")) {
              printf(" - void\n");
            } else {
                printf(" - %s\n", node->type);
            }



        } else {
            printf("\n");
        }
        _print_ast(node->child, level + 1);
        _print_ast(node->brother, level);
    }
}
void print_ast(ast_node_t *node) {
    if(!syntax_error)
        _print_ast(node, 0);
}

void add_type(ast_node_t *type, ast_node_t *give_me_type) {
    ast_node_t *new_type_node = NULL;
    for (ast_node_t *current = give_me_type; current; current = current->brother) {
        new_type_node = ast_node(type->id, NULL_TOKEN);                
        new_type_node->brother = current->child;       
        current->child = new_type_node;                     
    }
}

int count(ast_node_t *start){
    ast_node_t *list;
    int count = 0;

    list = start;
    while(list){
        list=list->brother;
        count++;
    }

    return count;
}

static void _free_ast(ast_node_t *node) {

    if (node != NULL) {
        _free_ast(node->child);
        _free_ast(node->brother);

        if (node->value)
            free(node->value);

        free(node);
    }
}
void free_ast(ast_node_t *root) {

    if (root != NULL) {
        _free_ast(root);
        root = NULL;
    }
}