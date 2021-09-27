/*
 * create_user_request.h
 *
 * 
 */

#ifndef _create_user_request_H_
#define _create_user_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_user_request_t create_user_request_t;




typedef struct create_user_request_t {
    char *email; // string
    char *user_id; // string

} create_user_request_t;

create_user_request_t *create_user_request_create(
    char *email,
    char *user_id
);

void create_user_request_free(create_user_request_t *create_user_request);

create_user_request_t *create_user_request_parseFromJSON(cJSON *create_user_requestJSON);

cJSON *create_user_request_convertToJSON(create_user_request_t *create_user_request);

#endif /* _create_user_request_H_ */

