/*
 * create_token_request.h
 *
 * 
 */

#ifndef _create_token_request_H_
#define _create_token_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_token_request_t create_token_request_t;




typedef struct create_token_request_t {
    char *token_name; // string
    list_t *permissions; //primitive container

} create_token_request_t;

create_token_request_t *create_token_request_create(
    char *token_name,
    list_t *permissions
);

void create_token_request_free(create_token_request_t *create_token_request);

create_token_request_t *create_token_request_parseFromJSON(cJSON *create_token_requestJSON);

cJSON *create_token_request_convertToJSON(create_token_request_t *create_token_request);

#endif /* _create_token_request_H_ */

