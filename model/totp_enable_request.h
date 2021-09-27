/*
 * totp_enable_request.h
 *
 * request to enable google authenticator method for user
 */

#ifndef _totp_enable_request_H_
#define _totp_enable_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct totp_enable_request_t totp_enable_request_t;




typedef struct totp_enable_request_t {
    int enable; //boolean

} totp_enable_request_t;

totp_enable_request_t *totp_enable_request_create(
    int enable
);

void totp_enable_request_free(totp_enable_request_t *totp_enable_request);

totp_enable_request_t *totp_enable_request_parseFromJSON(cJSON *totp_enable_requestJSON);

cJSON *totp_enable_request_convertToJSON(totp_enable_request_t *totp_enable_request);

#endif /* _totp_enable_request_H_ */

