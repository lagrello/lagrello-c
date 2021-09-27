/*
 * token.h
 *
 * Access tokens are used when talking to the API, it will confirm your identity.
 */

#ifndef _token_H_
#define _token_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct token_t token_t;




typedef struct token_t {
    char *token_key; // string
    char *token_name; // string
    char *created_by; // string
    char *created_at; //date time
    list_t *permissions; //primitive container

} token_t;

token_t *token_create(
    char *token_key,
    char *token_name,
    char *created_by,
    char *created_at,
    list_t *permissions
);

void token_free(token_t *token);

token_t *token_parseFromJSON(cJSON *tokenJSON);

cJSON *token_convertToJSON(token_t *token);

#endif /* _token_H_ */

