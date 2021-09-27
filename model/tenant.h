/*
 * tenant.h
 *
 * Tenant is what you can call your account with lagrello. In your tenant you will store all the information about your account and all your users accounts.
 */

#ifndef _tenant_H_
#define _tenant_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct tenant_t tenant_t;

#include "tenant_company_info.h"



typedef struct tenant_t {
    char *tenant_id; // string
    char *tenant_name; // string
    char *callback_url; // string
    struct tenant_company_info_t *company_info; //model
    int activated; //boolean

} tenant_t;

tenant_t *tenant_create(
    char *tenant_id,
    char *tenant_name,
    char *callback_url,
    tenant_company_info_t *company_info,
    int activated
);

void tenant_free(tenant_t *tenant);

tenant_t *tenant_parseFromJSON(cJSON *tenantJSON);

cJSON *tenant_convertToJSON(tenant_t *tenant);

#endif /* _tenant_H_ */

