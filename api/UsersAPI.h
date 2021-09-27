#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/create_user_request.h"
#include "../model/error.h"
#include "../model/update_user_request.h"
#include "../model/user.h"


// Creates a user in tenant, tenant is determined from the token
//
user_t*
UsersAPI_usersCreate(apiClient_t *apiClient, create_user_request_t * create_user_request );


// Deletes specified user
//
void
UsersAPI_usersDelete(apiClient_t *apiClient, char * userId );


// Returns specified user
//
user_t*
UsersAPI_usersGet(apiClient_t *apiClient, char * userId );


// Updates specified user
//
user_t*
UsersAPI_usersUpdate(apiClient_t *apiClient, char * userId , update_user_request_t * update_user_request );


