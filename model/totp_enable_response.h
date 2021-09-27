/*
 * totp_enable_response.h
 *
 * payload with the secret key and url to QR code image
 */

#ifndef _totp_enable_response_H_
#define _totp_enable_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct totp_enable_response_t totp_enable_response_t;




typedef struct totp_enable_response_t {
    char *secret_key; // string
    char *qr_image; // string

} totp_enable_response_t;

totp_enable_response_t *totp_enable_response_create(
    char *secret_key,
    char *qr_image
);

void totp_enable_response_free(totp_enable_response_t *totp_enable_response);

totp_enable_response_t *totp_enable_response_parseFromJSON(cJSON *totp_enable_responseJSON);

cJSON *totp_enable_response_convertToJSON(totp_enable_response_t *totp_enable_response);

#endif /* _totp_enable_response_H_ */

