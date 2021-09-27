#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_user_request.h"



update_user_request_t *update_user_request_create(
    char *email
    ) {
    update_user_request_t *update_user_request_local_var = malloc(sizeof(update_user_request_t));
    if (!update_user_request_local_var) {
        return NULL;
    }
    update_user_request_local_var->email = email;

    return update_user_request_local_var;
}


void update_user_request_free(update_user_request_t *update_user_request) {
    if(NULL == update_user_request){
        return ;
    }
    listEntry_t *listEntry;
    if (update_user_request->email) {
        free(update_user_request->email);
        update_user_request->email = NULL;
    }
    free(update_user_request);
}

cJSON *update_user_request_convertToJSON(update_user_request_t *update_user_request) {
    cJSON *item = cJSON_CreateObject();

    // update_user_request->email
    if(update_user_request->email) { 
    if(cJSON_AddStringToObject(item, "email", update_user_request->email) == NULL) {
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

update_user_request_t *update_user_request_parseFromJSON(cJSON *update_user_requestJSON){

    update_user_request_t *update_user_request_local_var = NULL;

    // update_user_request->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(update_user_requestJSON, "email");
    if (email) { 
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }
    }


    update_user_request_local_var = update_user_request_create (
        email ? strdup(email->valuestring) : NULL
        );

    return update_user_request_local_var;
end:
    return NULL;

}
