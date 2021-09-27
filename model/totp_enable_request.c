#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "totp_enable_request.h"



totp_enable_request_t *totp_enable_request_create(
    int enable
    ) {
    totp_enable_request_t *totp_enable_request_local_var = malloc(sizeof(totp_enable_request_t));
    if (!totp_enable_request_local_var) {
        return NULL;
    }
    totp_enable_request_local_var->enable = enable;

    return totp_enable_request_local_var;
}


void totp_enable_request_free(totp_enable_request_t *totp_enable_request) {
    if(NULL == totp_enable_request){
        return ;
    }
    listEntry_t *listEntry;
    free(totp_enable_request);
}

cJSON *totp_enable_request_convertToJSON(totp_enable_request_t *totp_enable_request) {
    cJSON *item = cJSON_CreateObject();

    // totp_enable_request->enable
    if (!totp_enable_request->enable) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "enable", totp_enable_request->enable) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

totp_enable_request_t *totp_enable_request_parseFromJSON(cJSON *totp_enable_requestJSON){

    totp_enable_request_t *totp_enable_request_local_var = NULL;

    // totp_enable_request->enable
    cJSON *enable = cJSON_GetObjectItemCaseSensitive(totp_enable_requestJSON, "enable");
    if (!enable) {
        goto end;
    }

    
    if(!cJSON_IsBool(enable))
    {
    goto end; //Bool
    }


    totp_enable_request_local_var = totp_enable_request_create (
        enable->valueint
        );

    return totp_enable_request_local_var;
end:
    return NULL;

}
