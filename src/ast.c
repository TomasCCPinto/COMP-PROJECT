

#include "ast.h"
#include "y.tab.h"


static int types[] = {
    ID,
    INTLIT,
    REALLIT,
    STRLIT
};


token_t token(char *value, int type) {
    for (int i = 0; i < 4; ++i) {
        if (type == types[i]) {
            return (char *) strdup(value);
        }
    }
    return NULL;
}
