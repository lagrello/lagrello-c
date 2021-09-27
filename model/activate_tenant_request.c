#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "activate_tenant_request.h"



activate_tenant_request_t *activate_tenant_request_create(
    char *company_name,
    char *company_address,
    char *company_city,
    char *company_postal_code,
    char *company_country,
    char *company_org_number,
    char *company_vat_number
    ) {
    activate_tenant_request_t *activate_tenant_request_local_var = malloc(sizeof(activate_tenant_request_t));
    if (!activate_tenant_request_local_var) {
        return NULL;
    }
    activate_tenant_request_local_var->company_name = company_name;
    activate_tenant_request_local_var->company_address = company_address;
    activate_tenant_request_local_var->company_city = company_city;
    activate_tenant_request_local_var->company_postal_code = company_postal_code;
    activate_tenant_request_local_var->company_country = company_country;
    activate_tenant_request_local_var->company_org_number = company_org_number;
    activate_tenant_request_local_var->company_vat_number = company_vat_number;

    return activate_tenant_request_local_var;
}


void activate_tenant_request_free(activate_tenant_request_t *activate_tenant_request) {
    if(NULL == activate_tenant_request){
        return ;
    }
    listEntry_t *listEntry;
    if (activate_tenant_request->company_name) {
        free(activate_tenant_request->company_name);
        activate_tenant_request->company_name = NULL;
    }
    if (activate_tenant_request->company_address) {
        free(activate_tenant_request->company_address);
        activate_tenant_request->company_address = NULL;
    }
    if (activate_tenant_request->company_city) {
        free(activate_tenant_request->company_city);
        activate_tenant_request->company_city = NULL;
    }
    if (activate_tenant_request->company_postal_code) {
        free(activate_tenant_request->company_postal_code);
        activate_tenant_request->company_postal_code = NULL;
    }
    if (activate_tenant_request->company_country) {
        free(activate_tenant_request->company_country);
        activate_tenant_request->company_country = NULL;
    }
    if (activate_tenant_request->company_org_number) {
        free(activate_tenant_request->company_org_number);
        activate_tenant_request->company_org_number = NULL;
    }
    if (activate_tenant_request->company_vat_number) {
        free(activate_tenant_request->company_vat_number);
        activate_tenant_request->company_vat_number = NULL;
    }
    free(activate_tenant_request);
}

cJSON *activate_tenant_request_convertToJSON(activate_tenant_request_t *activate_tenant_request) {
    cJSON *item = cJSON_CreateObject();

    // activate_tenant_request->company_name
    if (!activate_tenant_request->company_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "companyName", activate_tenant_request->company_name) == NULL) {
    goto fail; //String
    }


    // activate_tenant_request->company_address
    if (!activate_tenant_request->company_address) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "companyAddress", activate_tenant_request->company_address) == NULL) {
    goto fail; //String
    }


    // activate_tenant_request->company_city
    if (!activate_tenant_request->company_city) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "companyCity", activate_tenant_request->company_city) == NULL) {
    goto fail; //String
    }


    // activate_tenant_request->company_postal_code
    if (!activate_tenant_request->company_postal_code) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "companyPostalCode", activate_tenant_request->company_postal_code) == NULL) {
    goto fail; //String
    }


    // activate_tenant_request->company_country
    if (!activate_tenant_request->company_country) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "companyCountry", activate_tenant_request->company_country) == NULL) {
    goto fail; //String
    }


    // activate_tenant_request->company_org_number
    if (!activate_tenant_request->company_org_number) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "companyOrgNumber", activate_tenant_request->company_org_number) == NULL) {
    goto fail; //String
    }


    // activate_tenant_request->company_vat_number
    if (!activate_tenant_request->company_vat_number) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "companyVATNumber", activate_tenant_request->company_vat_number) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

activate_tenant_request_t *activate_tenant_request_parseFromJSON(cJSON *activate_tenant_requestJSON){

    activate_tenant_request_t *activate_tenant_request_local_var = NULL;

    // activate_tenant_request->company_name
    cJSON *company_name = cJSON_GetObjectItemCaseSensitive(activate_tenant_requestJSON, "companyName");
    if (!company_name) {
        goto end;
    }

    
    if(!cJSON_IsString(company_name))
    {
    goto end; //String
    }

    // activate_tenant_request->company_address
    cJSON *company_address = cJSON_GetObjectItemCaseSensitive(activate_tenant_requestJSON, "companyAddress");
    if (!company_address) {
        goto end;
    }

    
    if(!cJSON_IsString(company_address))
    {
    goto end; //String
    }

    // activate_tenant_request->company_city
    cJSON *company_city = cJSON_GetObjectItemCaseSensitive(activate_tenant_requestJSON, "companyCity");
    if (!company_city) {
        goto end;
    }

    
    if(!cJSON_IsString(company_city))
    {
    goto end; //String
    }

    // activate_tenant_request->company_postal_code
    cJSON *company_postal_code = cJSON_GetObjectItemCaseSensitive(activate_tenant_requestJSON, "companyPostalCode");
    if (!company_postal_code) {
        goto end;
    }

    
    if(!cJSON_IsString(company_postal_code))
    {
    goto end; //String
    }

    // activate_tenant_request->company_country
    cJSON *company_country = cJSON_GetObjectItemCaseSensitive(activate_tenant_requestJSON, "companyCountry");
    if (!company_country) {
        goto end;
    }

    
    if(!cJSON_IsString(company_country))
    {
    goto end; //String
    }

    // activate_tenant_request->company_org_number
    cJSON *company_org_number = cJSON_GetObjectItemCaseSensitive(activate_tenant_requestJSON, "companyOrgNumber");
    if (!company_org_number) {
        goto end;
    }

    
    if(!cJSON_IsString(company_org_number))
    {
    goto end; //String
    }

    // activate_tenant_request->company_vat_number
    cJSON *company_vat_number = cJSON_GetObjectItemCaseSensitive(activate_tenant_requestJSON, "companyVATNumber");
    if (!company_vat_number) {
        goto end;
    }

    
    if(!cJSON_IsString(company_vat_number))
    {
    goto end; //String
    }


    activate_tenant_request_local_var = activate_tenant_request_create (
        strdup(company_name->valuestring),
        strdup(company_address->valuestring),
        strdup(company_city->valuestring),
        strdup(company_postal_code->valuestring),
        strdup(company_country->valuestring),
        strdup(company_org_number->valuestring),
        strdup(company_vat_number->valuestring)
        );

    return activate_tenant_request_local_var;
end:
    return NULL;

}
