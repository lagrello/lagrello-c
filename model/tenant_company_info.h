/*
 * tenant_company_info.h
 *
 * 
 */

#ifndef _tenant_company_info_H_
#define _tenant_company_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct tenant_company_info_t tenant_company_info_t;




typedef struct tenant_company_info_t {
    char *name; // string
    char *address; // string
    char *city; // string
    char *postal_code; // string
    char *country; // string
    char *org_number; // string
    char *vat_number; // string

} tenant_company_info_t;

tenant_company_info_t *tenant_company_info_create(
    char *name,
    char *address,
    char *city,
    char *postal_code,
    char *country,
    char *org_number,
    char *vat_number
);

void tenant_company_info_free(tenant_company_info_t *tenant_company_info);

tenant_company_info_t *tenant_company_info_parseFromJSON(cJSON *tenant_company_infoJSON);

cJSON *tenant_company_info_convertToJSON(tenant_company_info_t *tenant_company_info);

#endif /* _tenant_company_info_H_ */

