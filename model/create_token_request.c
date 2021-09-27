#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_token_request.h"



create_token_request_t *create_token_request_create(
    char *token_name,
    list_t *permissions
    ) {
    create_token_request_t *create_token_request_local_var = malloc(sizeof(create_token_request_t));
    if (!create_token_request_local_var) {
        return NULL;
    }
    create_token_request_local_var->token_name = token_name;
    create_token_request_local_var->permissions = permissions;

    return create_token_request_local_var;
}


void create_token_request_free(create_token_request_t *create_token_request) {
    if(NULL == create_token_request){
        return ;
    }
    listEntry_t *listEntry;
    if (create_token_request->token_name) {
        free(create_token_request->token_name);
        create_token_request->token_name = NULL;
    }
    if (create_token_request->permissions) {
        list_ForEach(listEntry, create_token_request->permissions) {
            free(listEntry->data);
        }
        list_free(create_token_request->permissions);
        create_token_request->permissions = NULL;
    }
    free(create_token_request);
}

cJSON *create_token_request_convertToJSON(create_token_request_t *create_token_request) {
    cJSON *item = cJSON_CreateObject();

    // create_token_request->token_name
    if (!create_token_request->token_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "tokenName", create_token_request->token_name) == NULL) {
    goto fail; //String
    }


    // create_token_request->permissions
    if(create_token_request->permissions) { 
    cJSON *permissions = cJSON_AddArrayToObject(item, "permissions");
    if(permissions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *permissionsListEntry;
    list_ForEach(permissionsListEntry, create_token_request->permissions) {
    if(cJSON_AddStringToObject(permissions, "", (char*)permissionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_token_request_t *create_token_request_parseFromJSON(cJSON *create_token_requestJSON){

    create_token_request_t *create_token_request_local_var = NULL;

    // create_token_request->token_name
    cJSON *token_name = cJSON_GetObjectItemCaseSensitive(create_token_requestJSON, "tokenName");
    if (!token_name) {
        goto end;
    }

    
    if(!cJSON_IsString(token_name))
    {
    goto end; //String
    }

    // create_token_request->permissions
    cJSON *permissions = cJSON_GetObjectItemCaseSensitive(create_token_requestJSON, "permissions");
    list_t *permissionsList;
    if (permissions) { 
    cJSON *permissions_local;
    if(!cJSON_IsArray(permissions)) {
        goto end;//primitive container
    }
    permissionsList = list_create();

    cJSON_ArrayForEach(permissions_local, permissions)
    {
        if(!cJSON_IsString(permissions_local))
        {
            goto end;
        }
        list_addElement(permissionsList , strdup(permissions_local->valuestring));
    }
    }


    create_token_request_local_var = create_token_request_create (
        strdup(token_name->valuestring),
        permissions ? permissionsList : NULL
        );

    return create_token_request_local_var;
end:
    return NULL;

}
