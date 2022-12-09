#include "semantic_analysis.h"
#include "table.h"
#include <stdio.h>

extern int line;
extern int col;
char *search_type_var_in_table(symbol_table *table, char *var_name);
char * get_types(char * type );

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

static void add_params(ast_node_t *node, param_list **global_head, param_list **func_head, symbol_table **symbol_head, const symbol_table *head, symbol_table *tabela) {
    if (!node)
	return;

    if (!(*global_head) && !(*func_head) && !(*symbol_head)) {

	*global_head = param_list_node(node->child->id);
	*func_head = param_list_node(node->child->id);

    
    

    //tinha aqui in_table
    if (search_type_var_in_table(tabela,  node->child->brother->value) != NULL) {
        printf("Line %d, col %d: Symbol %s already defined\n", node->child->brother->line, node->child->brother->col, node->child->brother->value);
    }
    *symbol_head = symbol_table_node(node->child->brother->value, node->child->id, true, false);
	add_params(node->brother, global_head, func_head, &(*symbol_head)->symbols, head,tabela);
	return;
    

    print_table(*symbol_head);
	add_params(node->brother, global_head, func_head, symbol_head, head,tabela);
	return;
    } 
    if (global_head && func_head && symbol_head) {
      add_params(node, &(*global_head)->next, &(*func_head)->next, symbol_head, head,tabela);
    } else if (global_head) {
      add_params(node, &(*global_head)->next, func_head, symbol_head, head,tabela);
    } else if (func_head) {
      add_params(node, global_head, &(*func_head)->next, symbol_head, head,tabela);
    }
}


static bool is_declit(const char *number) {
    char string[strlen(number) + 2];
    strcpy(string, number);

    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == '_') {
            int j = i;
            for (; string[j+1] != '\0'; ++j) {
                string[j] = string[j+1];
            }
            string[j] = '\0';
            i--;
        }
    }
    long long convertion = atoll(string);
        
    return convertion < 2147483648;
}


static char* return_type_ast(ast_node_t *node, symbol_table *head) {
    if (!node->value) 
        return NULL;

    symbol_table *current = head;
    for (; current; current = current->symbols) {
        //printf("---%d\n",current->is_func);
        if(!current->is_func){
        if (!strcmp(node->value, current->id)) {
            //printf("%s - %s - %s\n", current->id, node->value, current->value);
            return current->value;
        } else if (!strcmp(node->id, "DecLit")) {
            // -2147483648
            if (is_declit(node->value)) {
                return "Int";
            } else {
                printf("Line %d, col %d: Number %s out of bounds\n", node->line, node->col, node->value);
                return "Int";
            }
            return "Int";
        } else if (!strcmp(node->id, "RealLit")) {
            return "Double";
        } else if (!strcmp(node->id, "BoolLit")) {
            return "Bool";
        } else if (!strcmp(node->id, "StrLit")) {
            return "String";
        }
     }
    }

    current = global_table;
    for (; current; current = current->symbols) {
        //printf("-%d\n",current->is_func);
        if(!current->is_func){
        if (!strcmp(node->value, current->id)) {
            //printf("%s - %s - %s\n", current->id, node->value, current->value);
            return current->value;
        } else if (!strcmp(node->id, "DecLit")) {
            return "Int";
        } else if (!strcmp(node->id, "RealLit")) {
            return "Double";
        } else if (!strcmp(node->id, "BoolLit")) {
            return "Bool";
        } else if (!strcmp(node->id, "StrLit")) {
            return "String";
        }
    }
    }
    return NULL;
}

static bool match_method(ast_node_t *node, symbol_table *head, bool flag) {
    //if(flag==1){
    //    printf("here\n");
    //}
    if (!node || !head)
        return false;
        
    
    if (node->brother && head->params) {
        
        ast_node_t *cur_node = node->brother;
        param_list *cur_param = head->params;

        for (; cur_param && cur_node; cur_param = cur_param->next, cur_node = cur_node->brother) {
            //printf("lmao-> %d\n",flag);
            if (flag && cur_node->type && !strcmp(cur_node->type, "Int") && !strcmp(cur_param->param, "Double")){
                
                continue;
            }
            if (cur_node->type && strcmp(cur_param->param, cur_node->type)) {
                return false;
            }
        }
        if (cur_param || cur_node)
            return false;

        return true;
    } else if (!node->brother && !head->params) {
        return true;
    }
    return false;
}

static char* copy_args(ast_node_t *node, symbol_table *head) {
    if (!node)
        return "()";
    if (!head || !head->params) {
        return "()";
    }

    param_list *curr_param = head->params;
    char *string = (char *) malloc(sizeof(char *) * (strlen(curr_param->param) + 1));

    if (!strcmp(curr_param->param, "Int")) {
        sprintf(string, "(int");
    } else if (!strcmp(curr_param->param, "Bool")) {
        sprintf(string, "(boolean");
    } else if (!strcmp(curr_param->param, "Double")) {
        sprintf(string, "(double");
    } else if (!strcmp(curr_param->param, "StringArray")) {
        sprintf(string, "(String[]");
    } else if (!strcmp(curr_param->param, "Void")) {
        sprintf(string, "(void");
    } else {
	    sprintf(string, "(%s", curr_param->param);
    }

    curr_param = curr_param->next;
    for (; curr_param; curr_param = curr_param->next) {
        string = (char *) realloc(string, sizeof(char *) * strlen(string) + strlen(curr_param->param) + 1);

        if (!strcmp(curr_param->param, "Int")) {
            strcat(string, ",");
            strcat(string, "int");
        } else if (!strcmp(curr_param->param, "Bool")) {
            strcat(string, ",");
            strcat(string, "boolean");
        } else if (!strcmp(curr_param->param, "Double")) {
            strcat(string, ",");
            strcat(string, "double");
        } else if (!strcmp(curr_param->param, "StringArray")) {
            strcat(string, ",");
            strcat(string, "String[]");
        } else if (!strcmp(curr_param->param, "Void")) {
            strcat(string, ",");
            strcat(string, "void");
        } else {
	        sprintf(string, "(%s", curr_param->param);
        }
    }
    string = (char *) realloc(string, sizeof(char *) * strlen(string) + 1);
    strcat(string, ")");
    return string;
}

static bool return_type_call(ast_node_t *node, symbol_table *head) {
    if (!node || ! head)
        return false;
    
    //verificar se da match direto correto
    //printf("lol-> %s\n",head->id);
    if (!strcmp(node->child->value, head->id) && match_method(node->child, head, false)) {
        //printf("-> %s \n",head->value);
        node->type = head->value;
        node->child->type = copy_args(node, head);
        return true;
    }

    bool flag = return_type_call(node, head->symbols);
    if (flag)
        return flag;

    
    if (!strcmp(node->child->value, head->id) && match_method(node->child, head, true)) {
        //printf("aqui\n");
        node->type = head->value;
        node->child->type = copy_args(node, head);
        return true;
    }
    return false;
}

static void add_type_ast(ast_node_t *node, symbol_table *head) {
    if (node) {
        
        //printf("%d\n",head->is_func);
        
        if(!node->type){
            node->type = return_type_ast(node, head);
        }

        add_type_ast(node->child, head);
        add_type_ast(node->brother, head);

        

        if (!strcmp(node->id, "Assign")) {
            node->type = node->child->type;
        } else if (!strcmp(node->id, "Call")) {
            //("-- %s\n",node->child->type);
            if(strcmp(node->child->id,"Id")==0){
                node->child->type=NULL;
            }
            return_type_call(node, global_table);
            if (!node->type) {
                node->type = "undef";
                node->child->type = "undef";
                printf("Line %d, col %d: Cannot find symbol %s\n", node->child->line, node->child->col, node->child->value);
            }
            //printf("-- %s\n",node->child->type);
        } else if (!strcmp(node->id, "Length")) {
            node->type = "Int";
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

        /*if (!strcmp(node->id, "Add")) {
            if (!strcmp(node->child->type, "Int"))
                node->type = "Int";
            else if (!strcmp(node->child->type, "Double"))
                node->type = "Double";
        } else if (!strcmp(node->id, "Sub")) {
            if (!strcmp(node->child->type, "Int"))
                node->type = "Int";
            else if (!strcmp(node->child->type, "Double"))
                node->type = "Double";
        }*/
        
        if (!node->child->brother || !node->child->brother->type)
            return;

        if (!strcmp(node->id, "Add")) {
            if (!strcmp(node->child->type, "Int") && !strcmp(node->child->brother->type, "Int"))
                node->type = "Int";
            else if (!strcmp(node->child->type, "Double") || !strcmp(node->child->brother->type, "Double"))
                node->type = "Double";
        } else if (!strcmp(node->id, "Sub")) {
            if (!strcmp(node->child->type, "Int") && !strcmp(node->child->brother->type, "Int"))
                node->type = "Int";
            else if (!strcmp(node->child->type, "Double") || !strcmp(node->child->brother->type, "Double"))
                node->type = "Double";
        } else if (!strcmp(node->id, "Div")) {
            if (!strcmp(node->child->type, "Int") && !strcmp(node->child->brother->type, "Int"))
                node->type = "Int";
            else if (!strcmp(node->child->type, "Double") || !strcmp(node->child->brother->type, "Double"))
                node->type = "Double";
        } else if (!strcmp(node->id, "Mul")) {
            if (!strcmp(node->child->type, "Int") && !strcmp(node->child->brother->type, "Int"))
                node->type = "Int";
            else if (!strcmp(node->child->type, "Double") || !strcmp(node->child->brother->type, "Double"))
                node->type = "Double";
        } else if (!strcmp(node->id, "Mod")) {
            if (!strcmp(node->child->type, "Int") && !strcmp(node->child->brother->type, "Int"))
                node->type = "Int";
            else if (!strcmp(node->child->type, "Double") || !strcmp(node->child->brother->type, "Double"))
                node->type = "Double";
        } else if (!strcmp(node->id, "Lshift")) {
            if (!strcmp(node->child->type, "Int") && !strcmp(node->child->brother->type, "Int"))
                node->type = "Int";
            else if (!strcmp(node->child->type, "Double") || !strcmp(node->child->brother->type, "Double"))
                node->type = "Double";
        } else if (!strcmp(node->id, "Rshift")) {
            if (!strcmp(node->child->type, "Int") && !strcmp(node->child->brother->type, "Int"))
                node->type = "Int";
            else if (!strcmp(node->child->type, "Double") || !strcmp(node->child->brother->type, "Double"))
                node->type = "Double";
        }
    }
}

static void add_body_params(ast_node_t *node, symbol_table **symbol_node, symbol_table *head) {
    if (!node)
        return;

    if (!(*symbol_node)) {
        if (!strcmp(node->id, "VarDecl")) {
            //printf("lol-> %d\n",search_type_var_in_table(head,  node->child->brother->value) );
	        if (search_type_var_in_table(head,  node->child->brother->value) != NULL) {
                printf("Line %d, col %d: Symbol %s already defined\n", node->child->brother->line, node->child->brother->col, node->child->brother->value);
	        }
            else{
                *symbol_node = symbol_table_node(node->child->brother->value, node->child->id, false, false);
            }
        } else if (!strcmp(node->id, "Assign")) {
            add_type_ast(node, head);
        } else if (!strcmp(node->id, "Return")) {
            add_type_ast(node->child, head);
        } else if (!strcmp(node->id, "Call")) {
            add_type_ast(node, head);
        } else if (!strcmp(node->id, "If")) {
            add_type_ast(node->child, head);

            //printf("lol->%s\n",node->child->type);
            
            if (!node->child->value || strcmp(node->child->type, "Bool")) {
                if (node->child->line != -1)
                    printf("Line %d, col %d: Incompatible type %s in if statement\n", node->child->line, node->child->col, get_types(node->child->type));
                //else
                //printf("Line %d, col %d: Incompatible type %s in if statement\n", node->child->child->line, node->child->child->col, get_types(node->child->type));

                //printf("%s - %s\n", node->child->id, node->child->value);
            }
            

        } else if (!strcmp(node->id, "While")) {
            add_type_ast(node->child, head);

            /*
            if (!node->child->value || strcmp(node->child->type, "Bool")) {
                if (node->child->line != -1)
                    printf("Line %d, col %d: Incompatible type %s in while statement\n", node->child->line, node->child->col, get_types(node->child->type));
                   
                //else
                //printf("Line %d, col %d: Incompatible type %s in if statement\n", node->child->child->line, node->child->child->col, get_types(node->child->type));

                //printf("%s - %s\n", node->child->id, node->child->value);
            }
            */
            
        } else if (!strcmp(node->id, "Print")) {
            add_type_ast(node->child, head);
            if (!strcmp(node->child->type, "undef"))
                printf("Line %d, col %d: Incompatible type undef in System.out.print\n", node->child->line, node->col);
        }

        add_body_params(node->brother, symbol_node, head);
        return;
    }
    if (*symbol_node)
        add_body_params(node, &(*symbol_node)->symbols, head);
}

static symbol_table* append_symbol_table(ast_node_t *node, symbol_table *symbol_node) {
    if (symbol_node->symbols) {
        return append_symbol_table(node, symbol_node->symbols);
    }
    symbol_node->symbols = symbol_table_node(node->child->brother->value, node->child->id, false, true);
    symbol_node->next = symbol_table_node(node->child->brother->value, "", false, true); 
    symbol_node->next->symbols = symbol_table_node("return", node->child->id, false, false); 
    if (node->child->brother->brother && node->child->brother->brother->child && !strcmp(node->child->brother->brother->child->id, "ParamDecl")) {
        //printf("lalala\n");
        //print_table(symbol_node->next);
        //printf("lelelele\n");
        add_params(node->child->brother->brother->child, &symbol_node->symbols->params, &symbol_node->next->params, &symbol_node->next->symbols->symbols, symbol_node->next->symbols->symbols, symbol_node->next);
        
    }
    return symbol_node;
}

static void append_var_table(ast_node_t *node, symbol_table *symbol_node) {
    if (!symbol_node->symbols) {
        symbol_node->symbols = symbol_table_node(node->child->brother->value, node->child->id, false, false);
        return;
    }
    append_var_table(node, symbol_node->symbols);
}

/*
char *search_type_var(symbol_table *table_global, symbol_table *table_local, char *var_name) {
  char *aux = search_type_var_in_table(table_local, var_name);
  if (aux != NULL) {
    return aux;
  }
  aux = search_type_var_in_table(table_global, var_name);
  if (aux != NULL) {
    return aux;
  }
  return NULL;
}
*/

char *search_type_var_in_table(symbol_table *table, char *var_name) {
  if (table == NULL) {
    return NULL;
  }


  
  symbol_table *current = table;

  while (current != NULL) {
    if (strcmp(current->id, var_name) == 0  && !current->is_func) {
      return current->value;
    }
    current = current->symbols;
  }

  return NULL;
}

void semantic_analysis(ast_node_t *node) {
    if (!node) 
        return;
    //printf("%d - %d\n", node->line, node->col);
    if (!strcmp("Program", node->id)) {
        global_table = symbol_table_node("Class", node->child->value, false, false);
    } else if (!strcmp("MethodDecl", node->id)) {
        symbol_table *symbol_node = append_symbol_table(node->child, global_table);

        
        semantic_analysis(node->brother);
        add_body_params(node->child->brother->child, &symbol_node->next, symbol_node->next);


        return; 
    } else if (!strcmp("FieldDecl", node->id)) {

        if (search_type_var_in_table(global_table,  node->child->brother->value) != NULL) {
          //printf("Line %d, col %d: Symbol %s already defined\n", node->child->line, node->child->col, node->id);
          printf("Line %d, col %d: Symbol %s already defined\n", node->child->brother->line, node->child->brother->col, node->child->brother->value);
        } else {
        append_var_table(node, global_table);
        semantic_analysis(node->brother);
        
        return;
        } 
    }

    semantic_analysis(node->brother);
    semantic_analysis(node->child);
}


char * get_types(char * type ){
    if(strcmp(type,"Bool")==0){
      return "boolean";  
    }
    else if(strcmp(type,"Int")==0){
      return "int";  
    }
    else if(strcmp(type,"Double")==0){
      return "double";  
    }
    else if(strcmp(type,"StringArray")==0){
      return "String[]";  
    }
    else if(strcmp(type,"Void")==0){
      return "void";  
    }
    else{
        return "";
    }
}