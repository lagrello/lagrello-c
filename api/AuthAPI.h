#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/error.h"
#include "../model/totp_enable_request.h"
#include "../model/totp_enable_response.h"
#include "../model/user.h"


// Gives back user data for the magic link token
//
user_t*
AuthAPI_usersEmailAuth(apiClient_t *apiClient, char * payload );


// This endpoint will be used when you want to send a magic login link to specified user
//
void
AuthAPI_usersEmailSend(apiClient_t *apiClient, char * userId );


// Verify users TOTP token
//
user_t*
AuthAPI_usersTotpAuth(apiClient_t *apiClient, char * userId , char * payload );


// Enables or disables Time-based One-Time Password authentication method for specified user
//
// When you want your users to be able to use TOTP authentication you need to send enable set to true as payload to this endpoint. To turn off TOTP set enable to false. When enabling you will recieve the secret key and a QR code link. The QR code you need to show your user for them to scan.
//
totp_enable_response_t*
AuthAPI_usersTotpToggle(apiClient_t *apiClient, char * userId , totp_enable_request_t * totp_enable_request );


