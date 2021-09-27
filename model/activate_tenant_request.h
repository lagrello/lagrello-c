/*
 * activate_tenant_request.h
 *
 * 
 */

#ifndef _activate_tenant_request_H_
#define _activate_tenant_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activate_tenant_request_t activate_tenant_request_t;




typedef struct activate_tenant_request_t {
    char *company_name; // string
    char *company_address; // string
    char *company_city; // string
    char *company_postal_code; // string
    char *company_country; // string
    char *company_org_number; // string
    char *company_vat_number; // string

} activate_tenant_request_t;

activate_tenant_request_t *activate_tenant_request_create(
    char *company_name,
    char *company_address,
    char *company_city,
    char *company_postal_code,
    char *company_country,
    char *company_org_number,
    char *company_vat_number
);

void activate_tenant_request_free(activate_tenant_request_t *activate_tenant_request);

activate_tenant_request_t *activate_tenant_request_parseFromJSON(cJSON *activate_tenant_requestJSON);

cJSON *activate_tenant_request_convertToJSON(activate_tenant_request_t *activate_tenant_request);

#endif /* _activate_tenant_request_H_ */

