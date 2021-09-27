#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user.h"



user_t *user_create(
    char *email,
    char *user_id
    ) {
    user_t *user_local_var = malloc(sizeof(user_t));
    if (!user_local_var) {
        return NULL;
    }
    user_local_var->email = email;
    user_local_var->user_id = user_id;

    return user_local_var;
}


void user_free(user_t *user) {
    if(NULL == user){
        return ;
    }
    listEntry_t *listEntry;
    if (user->email) {
        free(user->email);
        user->email = NULL;
    }
    if (user->user_id) {
        free(user->user_id);
        user->user_id = NULL;
    }
    free(user);
}

cJSON *user_convertToJSON(user_t *user) {
    cJSON *item = cJSON_CreateObject();

    // user->email
    if(user->email) { 
    if(cJSON_AddStringToObject(item, "email", user->email) == NULL) {
    goto fail; //String
    }
     } 


    // user->user_id
    if (!user->user_id) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "userId", user->user_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

user_t *user_parseFromJSON(cJSON *userJSON){

    user_t *user_local_var = NULL;

    // user->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(userJSON, "email");
    if (email) { 
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }
    }

    // user->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(userJSON, "userId");
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsString(user_id))
    {
    goto end; //String
    }


    user_local_var = user_create (
        email ? strdup(email->valuestring) : NULL,
        strdup(user_id->valuestring)
        );

    return user_local_var;
end:
    return NULL;

}
