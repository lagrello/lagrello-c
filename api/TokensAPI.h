#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/create_token_request.h"
#include "../model/error.h"
#include "../model/token.h"
#include "../model/token_list.h"


// Creates new token
//
token_t*
TokensAPI_tokensCreate(apiClient_t *apiClient, create_token_request_t * create_token_request );


// Deletes specifed access token
//
void
TokensAPI_tokensDelete(apiClient_t *apiClient, char * tokenId );


// Returns a list of all active tokens in tenant
//
token_list_t*
TokensAPI_tokensList(apiClient_t *apiClient, int size , int page );


