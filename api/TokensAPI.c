#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "TokensAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// Creates new token
//
token_t*
TokensAPI_tokensCreate(apiClient_t *apiClient, create_token_request_t * create_token_request )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/tokens")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/tokens");




    // Body Param
    cJSON *localVarSingleItemJSON_create_token_request = NULL;
    if (create_token_request != NULL)
    {
        //string
        localVarSingleItemJSON_create_token_request = create_token_request_convertToJSON(create_token_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_token_request);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","Returns the newly created token");
    }
    //nonprimitive not container
    cJSON *TokensAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    token_t *elementToReturn = token_parseFromJSON(TokensAPIlocalVarJSON);
    cJSON_Delete(TokensAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_create_token_request) {
        cJSON_Delete(localVarSingleItemJSON_create_token_request);
        localVarSingleItemJSON_create_token_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Deletes specifed access token
//
void
TokensAPI_tokensDelete(apiClient_t *apiClient, char * tokenId )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/tokens/{id}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/tokens/{id}");


    // Path Params
    long sizeOfPathParams_tokenId = strlen(tokenId)+3 + strlen("{ tokenId }");
    if(tokenId == NULL) {
        goto end;
    }
    char* localVarToReplace_tokenId = malloc(sizeOfPathParams_tokenId);
    sprintf(localVarToReplace_tokenId, "{%s}", "tokenId");

    localVarPath = strReplace(localVarPath, localVarToReplace_tokenId, tokenId);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "DELETE");

    if (apiClient->response_code == 204) {
        printf("%s\n","Successfully deleted specified token");
    }
    if (apiClient->response_code == 403) {
        printf("%s\n","The access token used to access resource is wrong");
    }
    if (apiClient->response_code == 404) {
        printf("%s\n","token could not be found");
    }
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_tokenId);

}

// Returns a list of all active tokens in tenant
//
token_list_t*
TokensAPI_tokensList(apiClient_t *apiClient, int size , int page )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/tokens")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/tokens");




    // query parameters
    char *keyQuery_size = NULL;
    char * valueQuery_size = NULL;
    keyValuePair_t *keyPairQuery_size = 0;
    if (size)
    {
        keyQuery_size = strdup("size");
        valueQuery_size = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_size, MAX_NUMBER_LENGTH, "%d", size);
        keyPairQuery_size = keyValuePair_create(keyQuery_size, valueQuery_size);
        list_addElement(localVarQueryParameters,keyPairQuery_size);
    }

    // query parameters
    char *keyQuery_page = NULL;
    char * valueQuery_page = NULL;
    keyValuePair_t *keyPairQuery_page = 0;
    if (page)
    {
        keyQuery_page = strdup("page");
        valueQuery_page = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_page, MAX_NUMBER_LENGTH, "%d", page);
        keyPairQuery_page = keyValuePair_create(keyQuery_page, valueQuery_page);
        list_addElement(localVarQueryParameters,keyPairQuery_page);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","Returns a paginated list of tokens");
    }
    //nonprimitive not container
    cJSON *TokensAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    token_list_t *elementToReturn = token_list_parseFromJSON(TokensAPIlocalVarJSON);
    cJSON_Delete(TokensAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_size){
        free(keyQuery_size);
        keyQuery_size = NULL;
    }
    if(valueQuery_size){
        free(valueQuery_size);
        valueQuery_size = NULL;
    }
    if(keyPairQuery_size){
        keyValuePair_free(keyPairQuery_size);
        keyPairQuery_size = NULL;
    }
    if(keyQuery_page){
        free(keyQuery_page);
        keyQuery_page = NULL;
    }
    if(valueQuery_page){
        free(valueQuery_page);
        valueQuery_page = NULL;
    }
    if(keyPairQuery_page){
        keyValuePair_free(keyPairQuery_page);
        keyPairQuery_page = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

