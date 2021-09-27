/*
 * update_tenant_request.h
 *
 * 
 */

#ifndef _update_tenant_request_H_
#define _update_tenant_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_tenant_request_t update_tenant_request_t;




typedef struct update_tenant_request_t {
    char *callback_url; // string

} update_tenant_request_t;

update_tenant_request_t *update_tenant_request_create(
    char *callback_url
);

void update_tenant_request_free(update_tenant_request_t *update_tenant_request);

update_tenant_request_t *update_tenant_request_parseFromJSON(cJSON *update_tenant_requestJSON);

cJSON *update_tenant_request_convertToJSON(update_tenant_request_t *update_tenant_request);

#endif /* _update_tenant_request_H_ */

