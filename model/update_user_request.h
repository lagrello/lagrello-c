/*
 * update_user_request.h
 *
 * 
 */

#ifndef _update_user_request_H_
#define _update_user_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_user_request_t update_user_request_t;




typedef struct update_user_request_t {
    char *email; // string

} update_user_request_t;

update_user_request_t *update_user_request_create(
    char *email
);

void update_user_request_free(update_user_request_t *update_user_request);

update_user_request_t *update_user_request_parseFromJSON(cJSON *update_user_requestJSON);

cJSON *update_user_request_convertToJSON(update_user_request_t *update_user_request);

#endif /* _update_user_request_H_ */

