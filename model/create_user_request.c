#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_user_request.h"



create_user_request_t *create_user_request_create(
    char *email,
    char *user_id
    ) {
    create_user_request_t *create_user_request_local_var = malloc(sizeof(create_user_request_t));
    if (!create_user_request_local_var) {
        return NULL;
    }
    create_user_request_local_var->email = email;
    create_user_request_local_var->user_id = user_id;

    return create_user_request_local_var;
}


void create_user_request_free(create_user_request_t *create_user_request) {
    if(NULL == create_user_request){
        return ;
    }
    listEntry_t *listEntry;
    if (create_user_request->email) {
        free(create_user_request->email);
        create_user_request->email = NULL;
    }
    if (create_user_request->user_id) {
        free(create_user_request->user_id);
        create_user_request->user_id = NULL;
    }
    free(create_user_request);
}

cJSON *create_user_request_convertToJSON(create_user_request_t *create_user_request) {
    cJSON *item = cJSON_CreateObject();

    // create_user_request->email
    if(create_user_request->email) { 
    if(cJSON_AddStringToObject(item, "email", create_user_request->email) == NULL) {
    goto fail; //String
    }
     } 


    // create_user_request->user_id
    if (!create_user_request->user_id) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "userId", create_user_request->user_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_user_request_t *create_user_request_parseFromJSON(cJSON *create_user_requestJSON){

    create_user_request_t *create_user_request_local_var = NULL;

    // create_user_request->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(create_user_requestJSON, "email");
    if (email) { 
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }
    }

    // create_user_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(create_user_requestJSON, "userId");
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsString(user_id))
    {
    goto end; //String
    }


    create_user_request_local_var = create_user_request_create (
        email ? strdup(email->valuestring) : NULL,
        strdup(user_id->valuestring)
        );

    return create_user_request_local_var;
end:
    return NULL;

}
