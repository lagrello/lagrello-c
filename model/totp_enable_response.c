#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "totp_enable_response.h"



totp_enable_response_t *totp_enable_response_create(
    char *secret_key,
    char *qr_image
    ) {
    totp_enable_response_t *totp_enable_response_local_var = malloc(sizeof(totp_enable_response_t));
    if (!totp_enable_response_local_var) {
        return NULL;
    }
    totp_enable_response_local_var->secret_key = secret_key;
    totp_enable_response_local_var->qr_image = qr_image;

    return totp_enable_response_local_var;
}


void totp_enable_response_free(totp_enable_response_t *totp_enable_response) {
    if(NULL == totp_enable_response){
        return ;
    }
    listEntry_t *listEntry;
    if (totp_enable_response->secret_key) {
        free(totp_enable_response->secret_key);
        totp_enable_response->secret_key = NULL;
    }
    if (totp_enable_response->qr_image) {
        free(totp_enable_response->qr_image);
        totp_enable_response->qr_image = NULL;
    }
    free(totp_enable_response);
}

cJSON *totp_enable_response_convertToJSON(totp_enable_response_t *totp_enable_response) {
    cJSON *item = cJSON_CreateObject();

    // totp_enable_response->secret_key
    if (!totp_enable_response->secret_key) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "secretKey", totp_enable_response->secret_key) == NULL) {
    goto fail; //String
    }


    // totp_enable_response->qr_image
    if (!totp_enable_response->qr_image) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "qrImage", totp_enable_response->qr_image) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

totp_enable_response_t *totp_enable_response_parseFromJSON(cJSON *totp_enable_responseJSON){

    totp_enable_response_t *totp_enable_response_local_var = NULL;

    // totp_enable_response->secret_key
    cJSON *secret_key = cJSON_GetObjectItemCaseSensitive(totp_enable_responseJSON, "secretKey");
    if (!secret_key) {
        goto end;
    }

    
    if(!cJSON_IsString(secret_key))
    {
    goto end; //String
    }

    // totp_enable_response->qr_image
    cJSON *qr_image = cJSON_GetObjectItemCaseSensitive(totp_enable_responseJSON, "qrImage");
    if (!qr_image) {
        goto end;
    }

    
    if(!cJSON_IsString(qr_image))
    {
    goto end; //String
    }


    totp_enable_response_local_var = totp_enable_response_create (
        strdup(secret_key->valuestring),
        strdup(qr_image->valuestring)
        );

    return totp_enable_response_local_var;
end:
    return NULL;

}
