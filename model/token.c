#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "token.h"



token_t *token_create(
    char *token_key,
    char *token_name,
    char *created_by,
    char *created_at,
    list_t *permissions
    ) {
    token_t *token_local_var = malloc(sizeof(token_t));
    if (!token_local_var) {
        return NULL;
    }
    token_local_var->token_key = token_key;
    token_local_var->token_name = token_name;
    token_local_var->created_by = created_by;
    token_local_var->created_at = created_at;
    token_local_var->permissions = permissions;

    return token_local_var;
}


void token_free(token_t *token) {
    if(NULL == token){
        return ;
    }
    listEntry_t *listEntry;
    if (token->token_key) {
        free(token->token_key);
        token->token_key = NULL;
    }
    if (token->token_name) {
        free(token->token_name);
        token->token_name = NULL;
    }
    if (token->created_by) {
        free(token->created_by);
        token->created_by = NULL;
    }
    if (token->created_at) {
        free(token->created_at);
        token->created_at = NULL;
    }
    if (token->permissions) {
        list_ForEach(listEntry, token->permissions) {
            free(listEntry->data);
        }
        list_free(token->permissions);
        token->permissions = NULL;
    }
    free(token);
}

cJSON *token_convertToJSON(token_t *token) {
    cJSON *item = cJSON_CreateObject();

    // token->token_key
    if (!token->token_key) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "tokenKey", token->token_key) == NULL) {
    goto fail; //String
    }


    // token->token_name
    if (!token->token_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "tokenName", token->token_name) == NULL) {
    goto fail; //String
    }


    // token->created_by
    if (!token->created_by) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "createdBy", token->created_by) == NULL) {
    goto fail; //String
    }


    // token->created_at
    if (!token->created_at) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "createdAt", token->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // token->permissions
    if (!token->permissions) {
        goto fail;
    }
    
    cJSON *permissions = cJSON_AddArrayToObject(item, "permissions");
    if(permissions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *permissionsListEntry;
    list_ForEach(permissionsListEntry, token->permissions) {
    if(cJSON_AddStringToObject(permissions, "", (char*)permissionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

token_t *token_parseFromJSON(cJSON *tokenJSON){

    token_t *token_local_var = NULL;

    // token->token_key
    cJSON *token_key = cJSON_GetObjectItemCaseSensitive(tokenJSON, "tokenKey");
    if (!token_key) {
        goto end;
    }

    
    if(!cJSON_IsString(token_key))
    {
    goto end; //String
    }

    // token->token_name
    cJSON *token_name = cJSON_GetObjectItemCaseSensitive(tokenJSON, "tokenName");
    if (!token_name) {
        goto end;
    }

    
    if(!cJSON_IsString(token_name))
    {
    goto end; //String
    }

    // token->created_by
    cJSON *created_by = cJSON_GetObjectItemCaseSensitive(tokenJSON, "createdBy");
    if (!created_by) {
        goto end;
    }

    
    if(!cJSON_IsString(created_by))
    {
    goto end; //String
    }

    // token->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(tokenJSON, "createdAt");
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at))
    {
    goto end; //DateTime
    }

    // token->permissions
    cJSON *permissions = cJSON_GetObjectItemCaseSensitive(tokenJSON, "permissions");
    if (!permissions) {
        goto end;
    }

    list_t *permissionsList;
    
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


    token_local_var = token_create (
        strdup(token_key->valuestring),
        strdup(token_name->valuestring),
        strdup(created_by->valuestring),
        strdup(created_at->valuestring),
        permissionsList
        );

    return token_local_var;
end:
    return NULL;

}
