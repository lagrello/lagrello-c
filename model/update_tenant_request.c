#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_tenant_request.h"



update_tenant_request_t *update_tenant_request_create(
    char *callback_url
    ) {
    update_tenant_request_t *update_tenant_request_local_var = malloc(sizeof(update_tenant_request_t));
    if (!update_tenant_request_local_var) {
        return NULL;
    }
    update_tenant_request_local_var->callback_url = callback_url;

    return update_tenant_request_local_var;
}


void update_tenant_request_free(update_tenant_request_t *update_tenant_request) {
    if(NULL == update_tenant_request){
        return ;
    }
    listEntry_t *listEntry;
    if (update_tenant_request->callback_url) {
        free(update_tenant_request->callback_url);
        update_tenant_request->callback_url = NULL;
    }
    free(update_tenant_request);
}

cJSON *update_tenant_request_convertToJSON(update_tenant_request_t *update_tenant_request) {
    cJSON *item = cJSON_CreateObject();

    // update_tenant_request->callback_url
    if(update_tenant_request->callback_url) { 
    if(cJSON_AddStringToObject(item, "callbackUrl", update_tenant_request->callback_url) == NULL) {
    goto fail; //String
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

update_tenant_request_t *update_tenant_request_parseFromJSON(cJSON *update_tenant_requestJSON){

    update_tenant_request_t *update_tenant_request_local_var = NULL;

    // update_tenant_request->callback_url
    cJSON *callback_url = cJSON_GetObjectItemCaseSensitive(update_tenant_requestJSON, "callbackUrl");
    if (callback_url) { 
    if(!cJSON_IsString(callback_url))
    {
    goto end; //String
    }
    }


    update_tenant_request_local_var = update_tenant_request_create (
        callback_url ? strdup(callback_url->valuestring) : NULL
        );

    return update_tenant_request_local_var;
end:
    return NULL;

}
