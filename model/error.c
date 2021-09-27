#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "error.h"



error_t *error_create(
    char *message,
    char *error_type
    ) {
    error_t *error_local_var = malloc(sizeof(error_t));
    if (!error_local_var) {
        return NULL;
    }
    error_local_var->message = message;
    error_local_var->error_type = error_type;

    return error_local_var;
}


void error_free(error_t *error) {
    if(NULL == error){
        return ;
    }
    listEntry_t *listEntry;
    if (error->message) {
        free(error->message);
        error->message = NULL;
    }
    if (error->error_type) {
        free(error->error_type);
        error->error_type = NULL;
    }
    free(error);
}

cJSON *error_convertToJSON(error_t *error) {
    cJSON *item = cJSON_CreateObject();

    // error->message
    if (!error->message) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "message", error->message) == NULL) {
    goto fail; //String
    }


    // error->error_type
    if (!error->error_type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "errorType", error->error_type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

error_t *error_parseFromJSON(cJSON *errorJSON){

    error_t *error_local_var = NULL;

    // error->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(errorJSON, "message");
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }

    // error->error_type
    cJSON *error_type = cJSON_GetObjectItemCaseSensitive(errorJSON, "errorType");
    if (!error_type) {
        goto end;
    }

    
    if(!cJSON_IsString(error_type))
    {
    goto end; //String
    }


    error_local_var = error_create (
        strdup(message->valuestring),
        strdup(error_type->valuestring)
        );

    return error_local_var;
end:
    return NULL;

}
