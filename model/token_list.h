/*
 * token_list.h
 *
 * 
 */

#ifndef _token_list_H_
#define _token_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct token_list_t token_list_t;

#include "paging.h"
#include "token.h"



typedef struct token_list_t {
    list_t *data; //nonprimitive container
    struct paging_t *paging; //model

} token_list_t;

token_list_t *token_list_create(
    list_t *data,
    paging_t *paging
);

void token_list_free(token_list_t *token_list);

token_list_t *token_list_parseFromJSON(cJSON *token_listJSON);

cJSON *token_list_convertToJSON(token_list_t *token_list);

#endif /* _token_list_H_ */

