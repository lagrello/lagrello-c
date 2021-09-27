#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tenant_company_info.h"



tenant_company_info_t *tenant_company_info_create(
    char *name,
    char *address,
    char *city,
    char *postal_code,
    char *country,
    char *org_number,
    char *vat_number
    ) {
    tenant_company_info_t *tenant_company_info_local_var = malloc(sizeof(tenant_company_info_t));
    if (!tenant_company_info_local_var) {
        return NULL;
    }
    tenant_company_info_local_var->name = name;
    tenant_company_info_local_var->address = address;
    tenant_company_info_local_var->city = city;
    tenant_company_info_local_var->postal_code = postal_code;
    tenant_company_info_local_var->country = country;
    tenant_company_info_local_var->org_number = org_number;
    tenant_company_info_local_var->vat_number = vat_number;

    return tenant_company_info_local_var;
}


void tenant_company_info_free(tenant_company_info_t *tenant_company_info) {
    if(NULL == tenant_company_info){
        return ;
    }
    listEntry_t *listEntry;
    if (tenant_company_info->name) {
        free(tenant_company_info->name);
        tenant_company_info->name = NULL;
    }
    if (tenant_company_info->address) {
        free(tenant_company_info->address);
        tenant_company_info->address = NULL;
    }
    if (tenant_company_info->city) {
        free(tenant_company_info->city);
        tenant_company_info->city = NULL;
    }
    if (tenant_company_info->postal_code) {
        free(tenant_company_info->postal_code);
        tenant_company_info->postal_code = NULL;
    }
    if (tenant_company_info->country) {
        free(tenant_company_info->country);
        tenant_company_info->country = NULL;
    }
    if (tenant_company_info->org_number) {
        free(tenant_company_info->org_number);
        tenant_company_info->org_number = NULL;
    }
    if (tenant_company_info->vat_number) {
        free(tenant_company_info->vat_number);
        tenant_company_info->vat_number = NULL;
    }
    free(tenant_company_info);
}

cJSON *tenant_company_info_convertToJSON(tenant_company_info_t *tenant_company_info) {
    cJSON *item = cJSON_CreateObject();

    // tenant_company_info->name
    if (!tenant_company_info->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "Name", tenant_company_info->name) == NULL) {
    goto fail; //String
    }


    // tenant_company_info->address
    if (!tenant_company_info->address) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "Address", tenant_company_info->address) == NULL) {
    goto fail; //String
    }


    // tenant_company_info->city
    if (!tenant_company_info->city) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "City", tenant_company_info->city) == NULL) {
    goto fail; //String
    }


    // tenant_company_info->postal_code
    if (!tenant_company_info->postal_code) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "PostalCode", tenant_company_info->postal_code) == NULL) {
    goto fail; //String
    }


    // tenant_company_info->country
    if (!tenant_company_info->country) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "Country", tenant_company_info->country) == NULL) {
    goto fail; //String
    }


    // tenant_company_info->org_number
    if (!tenant_company_info->org_number) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "OrgNumber", tenant_company_info->org_number) == NULL) {
    goto fail; //String
    }


    // tenant_company_info->vat_number
    if (!tenant_company_info->vat_number) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "VATNumber", tenant_company_info->vat_number) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

tenant_company_info_t *tenant_company_info_parseFromJSON(cJSON *tenant_company_infoJSON){

    tenant_company_info_t *tenant_company_info_local_var = NULL;

    // tenant_company_info->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(tenant_company_infoJSON, "Name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // tenant_company_info->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(tenant_company_infoJSON, "Address");
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // tenant_company_info->city
    cJSON *city = cJSON_GetObjectItemCaseSensitive(tenant_company_infoJSON, "City");
    if (!city) {
        goto end;
    }

    
    if(!cJSON_IsString(city))
    {
    goto end; //String
    }

    // tenant_company_info->postal_code
    cJSON *postal_code = cJSON_GetObjectItemCaseSensitive(tenant_company_infoJSON, "PostalCode");
    if (!postal_code) {
        goto end;
    }

    
    if(!cJSON_IsString(postal_code))
    {
    goto end; //String
    }

    // tenant_company_info->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(tenant_company_infoJSON, "Country");
    if (!country) {
        goto end;
    }

    
    if(!cJSON_IsString(country))
    {
    goto end; //String
    }

    // tenant_company_info->org_number
    cJSON *org_number = cJSON_GetObjectItemCaseSensitive(tenant_company_infoJSON, "OrgNumber");
    if (!org_number) {
        goto end;
    }

    
    if(!cJSON_IsString(org_number))
    {
    goto end; //String
    }

    // tenant_company_info->vat_number
    cJSON *vat_number = cJSON_GetObjectItemCaseSensitive(tenant_company_infoJSON, "VATNumber");
    if (!vat_number) {
        goto end;
    }

    
    if(!cJSON_IsString(vat_number))
    {
    goto end; //String
    }


    tenant_company_info_local_var = tenant_company_info_create (
        strdup(name->valuestring),
        strdup(address->valuestring),
        strdup(city->valuestring),
        strdup(postal_code->valuestring),
        strdup(country->valuestring),
        strdup(org_number->valuestring),
        strdup(vat_number->valuestring)
        );

    return tenant_company_info_local_var;
end:
    return NULL;

}
