/*
 * error.h
 *
 * 
 */

#ifndef _error_H_
#define _error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct error_t error_t;




typedef struct error_t {
    char *message; // string
    char *error_type; // string

} error_t;

error_t *error_create(
    char *message,
    char *error_type
);

void error_free(error_t *error);

error_t *error_parseFromJSON(cJSON *errorJSON);

cJSON *error_convertToJSON(error_t *error);

#endif /* _error_H_ */

