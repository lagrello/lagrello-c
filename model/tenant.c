#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tenant.h"



tenant_t *tenant_create(
    char *tenant_id,
    char *tenant_name,
    char *callback_url,
    tenant_company_info_t *company_info,
    int activated
    ) {
    tenant_t *tenant_local_var = malloc(sizeof(tenant_t));
    if (!tenant_local_var) {
        return NULL;
    }
    tenant_local_var->tenant_id = tenant_id;
    tenant_local_var->tenant_name = tenant_name;
    tenant_local_var->callback_url = callback_url;
    tenant_local_var->company_info = company_info;
    tenant_local_var->activated = activated;

    return tenant_local_var;
}


void tenant_free(tenant_t *tenant) {
    if(NULL == tenant){
        return ;
    }
    listEntry_t *listEntry;
    if (tenant->tenant_id) {
        free(tenant->tenant_id);
        tenant->tenant_id = NULL;
    }
    if (tenant->tenant_name) {
        free(tenant->tenant_name);
        tenant->tenant_name = NULL;
    }
    if (tenant->callback_url) {
        free(tenant->callback_url);
        tenant->callback_url = NULL;
    }
    if (tenant->company_info) {
        tenant_company_info_free(tenant->company_info);
        tenant->company_info = NULL;
    }
    free(tenant);
}

cJSON *tenant_convertToJSON(tenant_t *tenant) {
    cJSON *item = cJSON_CreateObject();

    // tenant->tenant_id
    if (!tenant->tenant_id) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "tenantId", tenant->tenant_id) == NULL) {
    goto fail; //String
    }


    // tenant->tenant_name
    if (!tenant->tenant_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "tenantName", tenant->tenant_name) == NULL) {
    goto fail; //String
    }


    // tenant->callback_url
    if (!tenant->callback_url) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "callbackUrl", tenant->callback_url) == NULL) {
    goto fail; //String
    }


    // tenant->company_info
    if (!tenant->company_info) {
        goto fail;
    }
    
    cJSON *company_info_local_JSON = tenant_company_info_convertToJSON(tenant->company_info);
    if(company_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "companyInfo", company_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // tenant->activated
    if (!tenant->activated) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "activated", tenant->activated) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

tenant_t *tenant_parseFromJSON(cJSON *tenantJSON){

    tenant_t *tenant_local_var = NULL;

    // tenant->tenant_id
    cJSON *tenant_id = cJSON_GetObjectItemCaseSensitive(tenantJSON, "tenantId");
    if (!tenant_id) {
        goto end;
    }

    
    if(!cJSON_IsString(tenant_id))
    {
    goto end; //String
    }

    // tenant->tenant_name
    cJSON *tenant_name = cJSON_GetObjectItemCaseSensitive(tenantJSON, "tenantName");
    if (!tenant_name) {
        goto end;
    }

    
    if(!cJSON_IsString(tenant_name))
    {
    goto end; //String
    }

    // tenant->callback_url
    cJSON *callback_url = cJSON_GetObjectItemCaseSensitive(tenantJSON, "callbackUrl");
    if (!callback_url) {
        goto end;
    }

    
    if(!cJSON_IsString(callback_url))
    {
    goto end; //String
    }

    // tenant->company_info
    cJSON *company_info = cJSON_GetObjectItemCaseSensitive(tenantJSON, "companyInfo");
    if (!company_info) {
        goto end;
    }

    tenant_company_info_t *company_info_local_nonprim = NULL;
    
    company_info_local_nonprim = tenant_company_info_parseFromJSON(company_info); //nonprimitive

    // tenant->activated
    cJSON *activated = cJSON_GetObjectItemCaseSensitive(tenantJSON, "activated");
    if (!activated) {
        goto end;
    }

    
    if(!cJSON_IsBool(activated))
    {
    goto end; //Bool
    }


    tenant_local_var = tenant_create (
        strdup(tenant_id->valuestring),
        strdup(tenant_name->valuestring),
        strdup(callback_url->valuestring),
        company_info_local_nonprim,
        activated->valueint
        );

    return tenant_local_var;
end:
    if (company_info_local_nonprim) {
        tenant_company_info_free(company_info_local_nonprim);
        company_info_local_nonprim = NULL;
    }
    return NULL;

}
