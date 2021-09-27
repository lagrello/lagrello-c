/*
 * create_tenant_request.h
 *
 * 
 */

#ifndef _create_tenant_request_H_
#define _create_tenant_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_tenant_request_t create_tenant_request_t;




typedef struct create_tenant_request_t {
    char *tenant_name; // string
    char *admin_email; // string

} create_tenant_request_t;

create_tenant_request_t *create_tenant_request_create(
    char *tenant_name,
    char *admin_email
);

void create_tenant_request_free(create_tenant_request_t *create_tenant_request);

create_tenant_request_t *create_tenant_request_parseFromJSON(cJSON *create_tenant_requestJSON);

cJSON *create_tenant_request_convertToJSON(create_tenant_request_t *create_tenant_request);

#endif /* _create_tenant_request_H_ */

