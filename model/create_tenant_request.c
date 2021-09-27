#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_tenant_request.h"



create_tenant_request_t *create_tenant_request_create(
    char *tenant_name,
    char *admin_email
    ) {
    create_tenant_request_t *create_tenant_request_local_var = malloc(sizeof(create_tenant_request_t));
    if (!create_tenant_request_local_var) {
        return NULL;
    }
    create_tenant_request_local_var->tenant_name = tenant_name;
    create_tenant_request_local_var->admin_email = admin_email;

    return create_tenant_request_local_var;
}


void create_tenant_request_free(create_tenant_request_t *create_tenant_request) {
    if(NULL == create_tenant_request){
        return ;
    }
    listEntry_t *listEntry;
    if (create_tenant_request->tenant_name) {
        free(create_tenant_request->tenant_name);
        create_tenant_request->tenant_name = NULL;
    }
    if (create_tenant_request->admin_email) {
        free(create_tenant_request->admin_email);
        create_tenant_request->admin_email = NULL;
    }
    free(create_tenant_request);
}

cJSON *create_tenant_request_convertToJSON(create_tenant_request_t *create_tenant_request) {
    cJSON *item = cJSON_CreateObject();

    // create_tenant_request->tenant_name
    if (!create_tenant_request->tenant_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "tenantName", create_tenant_request->tenant_name) == NULL) {
    goto fail; //String
    }


    // create_tenant_request->admin_email
    if (!create_tenant_request->admin_email) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "adminEmail", create_tenant_request->admin_email) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_tenant_request_t *create_tenant_request_parseFromJSON(cJSON *create_tenant_requestJSON){

    create_tenant_request_t *create_tenant_request_local_var = NULL;

    // create_tenant_request->tenant_name
    cJSON *tenant_name = cJSON_GetObjectItemCaseSensitive(create_tenant_requestJSON, "tenantName");
    if (!tenant_name) {
        goto end;
    }

    
    if(!cJSON_IsString(tenant_name))
    {
    goto end; //String
    }

    // create_tenant_request->admin_email
    cJSON *admin_email = cJSON_GetObjectItemCaseSensitive(create_tenant_requestJSON, "adminEmail");
    if (!admin_email) {
        goto end;
    }

    
    if(!cJSON_IsString(admin_email))
    {
    goto end; //String
    }


    create_tenant_request_local_var = create_tenant_request_create (
        strdup(tenant_name->valuestring),
        strdup(admin_email->valuestring)
        );

    return create_tenant_request_local_var;
end:
    return NULL;

}
