#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "token_list.h"



token_list_t *token_list_create(
    list_t *data,
    paging_t *paging
    ) {
    token_list_t *token_list_local_var = malloc(sizeof(token_list_t));
    if (!token_list_local_var) {
        return NULL;
    }
    token_list_local_var->data = data;
    token_list_local_var->paging = paging;

    return token_list_local_var;
}


void token_list_free(token_list_t *token_list) {
    if(NULL == token_list){
        return ;
    }
    listEntry_t *listEntry;
    if (token_list->data) {
        list_ForEach(listEntry, token_list->data) {
            token_free(listEntry->data);
        }
        list_free(token_list->data);
        token_list->data = NULL;
    }
    if (token_list->paging) {
        paging_free(token_list->paging);
        token_list->paging = NULL;
    }
    free(token_list);
}

cJSON *token_list_convertToJSON(token_list_t *token_list) {
    cJSON *item = cJSON_CreateObject();

    // token_list->data
    if (!token_list->data) {
        goto fail;
    }
    
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (token_list->data) {
    list_ForEach(dataListEntry, token_list->data) {
    cJSON *itemLocal = token_convertToJSON(dataListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(data, itemLocal);
    }
    }


    // token_list->paging
    if (!token_list->paging) {
        goto fail;
    }
    
    cJSON *paging_local_JSON = paging_convertToJSON(token_list->paging);
    if(paging_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "paging", paging_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

token_list_t *token_list_parseFromJSON(cJSON *token_listJSON){

    token_list_t *token_list_local_var = NULL;

    // token_list->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(token_listJSON, "data");
    if (!data) {
        goto end;
    }

    list_t *dataList;
    
    cJSON *data_local_nonprimitive;
    if(!cJSON_IsArray(data)){
        goto end; //nonprimitive container
    }

    dataList = list_create();

    cJSON_ArrayForEach(data_local_nonprimitive,data )
    {
        if(!cJSON_IsObject(data_local_nonprimitive)){
            goto end;
        }
        token_t *dataItem = token_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }

    // token_list->paging
    cJSON *paging = cJSON_GetObjectItemCaseSensitive(token_listJSON, "paging");
    if (!paging) {
        goto end;
    }

    paging_t *paging_local_nonprim = NULL;
    
    paging_local_nonprim = paging_parseFromJSON(paging); //nonprimitive


    token_list_local_var = token_list_create (
        dataList,
        paging_local_nonprim
        );

    return token_list_local_var;
end:
    if (paging_local_nonprim) {
        paging_free(paging_local_nonprim);
        paging_local_nonprim = NULL;
    }
    return NULL;

}
