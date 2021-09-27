/*
 * user.h
 *
 * Information about a user.
 */

#ifndef _user_H_
#define _user_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_t user_t;




typedef struct user_t {
    char *email; // string
    char *user_id; // string

} user_t;

user_t *user_create(
    char *email,
    char *user_id
);

void user_free(user_t *user);

user_t *user_parseFromJSON(cJSON *userJSON);

cJSON *user_convertToJSON(user_t *user);

#endif /* _user_H_ */

