#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "paging.h"



paging_t *paging_create(
    char *previous,
    char *next
    ) {
    paging_t *paging_local_var = malloc(sizeof(paging_t));
    if (!paging_local_var) {
        return NULL;
    }
    paging_local_var->previous = previous;
    paging_local_var->next = next;

    return paging_local_var;
}


void paging_free(paging_t *paging) {
    if(NULL == paging){
        return ;
    }
    listEntry_t *listEntry;
    if (paging->previous) {
        free(paging->previous);
        paging->previous = NULL;
    }
    if (paging->next) {
        free(paging->next);
        paging->next = NULL;
    }
    free(paging);
}

cJSON *paging_convertToJSON(paging_t *paging) {
    cJSON *item = cJSON_CreateObject();

    // paging->previous
    if (!paging->previous) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "previous", paging->previous) == NULL) {
    goto fail; //String
    }


    // paging->next
    if (!paging->next) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "next", paging->next) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

paging_t *paging_parseFromJSON(cJSON *pagingJSON){

    paging_t *paging_local_var = NULL;

    // paging->previous
    cJSON *previous = cJSON_GetObjectItemCaseSensitive(pagingJSON, "previous");
    if (!previous) {
        goto end;
    }

    
    if(!cJSON_IsString(previous))
    {
    goto end; //String
    }

    // paging->next
    cJSON *next = cJSON_GetObjectItemCaseSensitive(pagingJSON, "next");
    if (!next) {
        goto end;
    }

    
    if(!cJSON_IsString(next))
    {
    goto end; //String
    }


    paging_local_var = paging_create (
        strdup(previous->valuestring),
        strdup(next->valuestring)
        );

    return paging_local_var;
end:
    return NULL;

}
