
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "y.tab.h"


int alloc_types[] = {
    ID,
    INTLIT,
    REALLIT,
    STRLIT
};


token_t token(char *value, int type) {
    for (int i = 0; i < (sizeof(alloc_types) / sizeof(alloc_types[0])); ++i) {
        if (type == alloc_types[i]) {
            return (char *)strdup(value);
        }
    }
    return NULL;
}