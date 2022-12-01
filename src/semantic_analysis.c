#include "semantic_analysis.h"
#include "table.h"
#include <stdio.h>


static bool in_table(const symbol_table *head, const char *value) {
  if (!head)
    return true;
  if (head->symbols) {
    if (!strcmp(head->id, value) ) {
      return false;
    }
    return in_table(head->symbols, value);
  }
  return true;
}

static void add_params(ast_node_t *node, param_list **global_head, param_list **func_head, symbol_table **symbol_head, const symbol_table *head) {
    if (!node)
	return;

    if (!(*global_head) && !(*func_head) && !(*symbol_head)) {

	*global_head = param_list_node(node->child->id);
	*func_head = param_list_node(node->child->id);
	if (in_table(head, node->child->brother->value)) {
	    *symbol_head = symbol_table_node(node->child->brother->value, node->child->id, true, false);
	    add_params(node->brother, global_head, func_head, &(*symbol_head)->symbols, head);
	    return;
	}
	add_params(node->brother, global_head, func_head, symbol_head, head);
	// add_params(node->brother, &(*global_head)->next, &(*func_head)->next, symbol_head);
	return;
    } 
    if (global_head && func_head && symbol_head) {
      add_params(node, &(*global_head)->next, &(*func_head)->next, symbol_head, head);
    } else if (global_head) {
      add_params(node, &(*global_head)->next, func_head, symbol_head, head);
    } else if (func_head) {
      add_params(node, global_head, &(*func_head)->next, symbol_head, head);
    }
}

static char* return_type_ast(ast_node_t *node, symbol_table *head) {
    if (!node->value) 
        return NULL;

    symbol_table *current = head;
    for (; current; current = current->symbols) {
        if (!strcmp(node->value, current->id) && strcmp(current->value, "")) {
            //printf("%s - %s - %s\n", current->id, node->value, current->value);
            return current->value;
        } else if (!strcmp(node->id, "DecLit")) {
            return "Int";
        } else if (!strcmp(node->id, "RealLit")) {
            return "Double";
        } else if (!strcmp(node->id, "BoolLit")) {
            return "Bool";
        }
    }

    current = global_table;
    for (; current; current = current->symbols) {
        if (!strcmp(node->value, current->id)) {
            //printf("%s - %s - %s\n", current->id, node->value, current->value);
            return current->value;
        } else if (!strcmp(node->id, "DecLit")) {
            return "Int";
        } else if (!strcmp(node->id, "RealLit")) {
            return "Double";
        } else if (!strcmp(node->id, "BoolLit")) {
            return "Bool";
        }
    }

    return NULL;
}

static void add_type_ast(ast_node_t *node, symbol_table *head) {
    if (node) {
        node->type = return_type_ast(node, head);
        add_type_ast(node->child, head);
        add_type_ast(node->brother, head);

        if (!strcmp(node->id, "Assign")) {
            add_type_ast(node->child, head);
            node->type = node->child->type;
        } else if (!strcmp(node->id, "Call")) {
            add_type_ast(node->child, head);
            node->type = return_type_ast(node->child, head);
            //printf("type: %s\n", return_type_ast(node->child, head));
        }


        if (!strcmp(node->id, "ParseArgs")) {
            // NOT SURE IT'S ALWAYS: INT
            node->type = "Int";
        } else if (!strcmp(node->id, "Eq") || !strcmp(node->id, "Le") || !strcmp(node->id, "Ne") || !strcmp(node->id, "Ge") || !strcmp(node->id, "Gt") || !strcmp(node->id, "Lt") ) {
            node->type = "Bool";
        } else if (!strcmp(node->id, "And") || !strcmp(node->id, "Or") || !strcmp(node->id, "Xor") || !strcmp(node->id, "Not") ) {
            node->type = "Bool";
        }

        if (!node->child || !node->child->type)
            return;

        if (!strcmp(node->id, "Add")) {
            if (!strcmp(node->child->type, "Int") && !strcmp(node->child->type, "Int"))
                node->type = "Int";
            else if (!strcmp(node->child->type, "Double") || !strcmp(node->child->type, "Double"))
                node->type = "Double";
        } else if (!strcmp(node->id, "Sub")) {
            if (!strcmp(node->child->type, "Int") && !strcmp(node->child->type, "Int"))
                node->type = "Int";
            else if (!strcmp(node->child->type, "Double") || !strcmp(node->child->type, "Double"))
                node->type = "Double";
        } else if (!strcmp(node->id, "Div")) {
            if (!strcmp(node->child->type, "Int") && !strcmp(node->child->type, "Int"))
                node->type = "Int";
            else if (!strcmp(node->child->type, "Double") || !strcmp(node->child->type, "Double"))
                node->type = "Double";
        } else if (!strcmp(node->id, "Mul")) {
            if (!strcmp(node->child->type, "Int") && !strcmp(node->child->type, "Int"))
                node->type = "Int";
            else if (!strcmp(node->child->type, "Double") || !strcmp(node->child->type, "Double"))
                node->type = "Double";
        } else if (!strcmp(node->id, "Mod")) {
            if (!strcmp(node->child->type, "Int") && !strcmp(node->child->type, "Int"))
                node->type = "Int";
            else if (!strcmp(node->child->type, "Double") || !strcmp(node->child->type, "Double"))
                node->type = "Double";
        }
    }
}

static void add_body_params(ast_node_t *node, symbol_table **symbol_node, symbol_table *head) {
    if (!node)
        return;

    if (!(*symbol_node)) {
        if (!strcmp(node->id, "VarDecl")) {
	        if (in_table(head, node->child->brother->value)) {
	            *symbol_node = symbol_table_node(node->child->brother->value, node->child->id, false, false);
	        }
        } else if (!strcmp(node->id, "Assign")) {
            //add_type_ast(node->child, head);
            //node->type = node->child->type;
            add_type_ast(node, head);

            //add_type_ast(node, head);
        } else if (!strcmp(node->id, "Return")) {
            add_type_ast(node->child, head);
        } else if (!strcmp(node->id, "Call")) {
            //add_type_ast(node->child, head);
            //node->type = head->symbols->value;
            add_type_ast(node, head);

            // printf("type: %s\n", node->type);
        } else if (!strcmp(node->id, "If")) {
            add_type_ast(node->child, head);
        } else if (!strcmp(node->id, "While")) {
            add_type_ast(node->child, head);
        }
        add_body_params(node->brother, symbol_node, head);
        return;
    }
    if (*symbol_node)
        add_body_params(node, &(*symbol_node)->symbols, head);
}

static void append_symbol_table(ast_node_t *node, symbol_table *symbol_node) {
    if (symbol_node->symbols) {
        append_symbol_table(node, symbol_node->symbols);
	return;
    }
    symbol_node->symbols = symbol_table_node(node->child->brother->value, node->child->id, false, true);
    symbol_node->next = symbol_table_node(node->child->brother->value, "", false, true); 
    symbol_node->next->symbols = symbol_table_node("return", node->child->id, false, false); 
    if (node->child->brother->brother && node->child->brother->brother->child && !strcmp(node->child->brother->brother->child->id, "ParamDecl")) {
      add_params(node->child->brother->brother->child, &symbol_node->symbols->params, &symbol_node->next->params, &symbol_node->next->symbols->symbols, symbol_node->next->symbols->symbols);
    }
    if (node->brother && !strcmp(node->brother->id, "MethodBody")) {
        add_body_params(node->brother->child, &symbol_node->next, symbol_node->next);
    }
}

static void append_var_table(ast_node_t *node, symbol_table *symbol_node) {
    if (!symbol_node->symbols) {
        symbol_node->symbols = symbol_table_node(node->child->brother->value, node->child->id, false, false);
        return;
    }
    append_var_table(node, symbol_node->symbols);
}

void semantic_analysis(ast_node_t *node) {
    if (!node) 
        return;
    if (!strcmp("Program", node->id)) {
        global_table = symbol_table_node("Class", node->child->value, false, false);
    } else if (!strcmp("MethodDecl", node->id)) {
        append_symbol_table(node->child, global_table);

        semantic_analysis(node->brother);

        return; 
    } else if (!strcmp("FieldDecl", node->id)) {
        append_var_table(node, global_table);
        semantic_analysis(node->brother);

        return; 
    }

    semantic_analysis(node->brother);
    semantic_analysis(node->child);
}
