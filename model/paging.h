/*
 * paging.h
 *
 * 
 */

#ifndef _paging_H_
#define _paging_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct paging_t paging_t;




typedef struct paging_t {
    char *previous; // string
    char *next; // string

} paging_t;

paging_t *paging_create(
    char *previous,
    char *next
);

void paging_free(paging_t *paging);

paging_t *paging_parseFromJSON(cJSON *pagingJSON);

cJSON *paging_convertToJSON(paging_t *paging);

#endif /* _paging_H_ */

