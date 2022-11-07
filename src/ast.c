

#include "ast.h"
#include "y.tab.h"
#include <stdio.h>

bool syntax_error = false; 

static int types[] = {
    ID,
    INTLIT,
    REALLIT,
    STRLIT,
    BOOLLIT
};


token_t token(char *value, int type) {
    for (int i = 0; i < 5; ++i) {
        if (type == types[3]) {
            //char aux[200];
            char *aux = (char *) malloc(sizeof(char)*(strlen(value)+1));
            sprintf(aux, "\"%s", value);
            return (char *) strdup(aux);
        }
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
    if(!syntax_error)
        _print_ast(node, 0);
}

void add_children(ast_node_t *parent, ast_node_t *child) {
    if (parent) {
        parent->child = child;
    }
}

void print_node(ast_node_t *node) {
    if (node) {
        printf("%s\n", node->id);
        if (node->child)
            printf("filho%s\n", node->child->value);

    }
}

void add_brother(ast_node_t *older_brother, ast_node_t *brother) {
    if (older_brother && brother) {
        older_brother->brother = brother;
    }
}

 void add(ast_node_t *parent, int argc, ...) {
    va_list args;
    ast_node_t *child = NULL;
    va_start(args, argc);

    assert(parent != NULL);
    child = va_arg(args, ast_node_t *);

    parent->child = child;
    ast_node_t *current = parent->child;

    for (int i = 0; i < argc - 1; ++i) {
        child = va_arg(args, ast_node_t *);
        for (ast_node_t *c = child; c; c = c->brother) {
            current->brother = c;
            current = current->brother;
        }
    }
    va_end(args);
}



void add_step_brother(ast_node_t *older_brother, ast_node_t *brother) {
    printf("here\n");
    if (older_brother != NULL) {
        ast_node_t *current = older_brother;

        while(current->brother) {
            current = current->brother;
            printf("\n\n");
            print_node(current);
            printf("\n\n");
            printf("here333\n");
        }
        add_brother(current, brother);
    }
}

void add_type(ast_node_t *type, ast_node_t *give_me_type) {
    ast_node_t *new_type_node = NULL;
    for (ast_node_t *current = give_me_type; current; current = current->brother) {
        new_type_node = ast_node(type->id, NULL);                
        new_type_node->brother = current->child;       
        current->child = new_type_node;                     
    }
}

static void _free_ast(ast_node_t *node) {

    if (node != NULL) {
        _free_ast(node->child);
        _free_ast(node->brother);
        free(node);
    }
}
void free_ast(ast_node_t *root) {

    if (root != NULL) {
        _free_ast(root);
        root = NULL;
    }
}



ast_node_t *split_vardecl(ast_node_t *node, token_t vardecl_tok) {
    if (node == NULL)
        return NULL;

    int n_vars = 0;
    ast_node_t *current = node, *first = NULL, *type, *vars = node, *new_id;

    while (current->brother != NULL)
    {
        n_vars++;
        current = current->brother;
    }

    for (int i = 0; i < n_vars; i++)
    {
        vars = vars->brother;
        if (first == NULL)
        {
            first = ast_node("VarDecl", vardecl_tok);
            current = first;
        }
        else
        {
            current->brother = ast_node("VarDecl", vardecl_tok);
            current = current->brother;
        }
        /*type = create_node(node->type, node->token);
        current->fChild = type;*/
        new_id = ast_node("Id", vars->value);
        add_brother(current->child, new_id);
    }

    return first;
}
ast_node_t *statement_list(ast_node_t *stat_list) {
    ast_node_t *list = stat_list;
    if (list && strcmp(list->id, "Block") == 0) {
        return list;
    }
    if (list && list->brother) {
        list = ast_node("Block", NULL);
        list->child = stat_list;
    }
    return list;
}