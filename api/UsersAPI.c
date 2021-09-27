#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "UsersAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// Creates a user in tenant, tenant is determined from the token
//
user_t*
UsersAPI_usersCreate(apiClient_t *apiClient, create_user_request_t * create_user_request )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/users")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/users");




    // Body Param
    cJSON *localVarSingleItemJSON_create_user_request = NULL;
    if (create_user_request != NULL)
    {
        //string
        localVarSingleItemJSON_create_user_request = create_user_request_convertToJSON(create_user_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_user_request);
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

    if (apiClient->response_code == 201) {
        printf("%s\n","Successfully created a new user");
    }
    if (apiClient->response_code == 403) {
        printf("%s\n","The access token used to access resource is wrong");
    }
    if (apiClient->response_code == 409) {
        printf("%s\n","Returned when user already exist");
    }
    //nonprimitive not container
    cJSON *UsersAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    user_t *elementToReturn = user_parseFromJSON(UsersAPIlocalVarJSON);
    cJSON_Delete(UsersAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_create_user_request) {
        cJSON_Delete(localVarSingleItemJSON_create_user_request);
        localVarSingleItemJSON_create_user_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Deletes specified user
//
void
UsersAPI_usersDelete(apiClient_t *apiClient, char * userId )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/users/{userId}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/users/{userId}");


    // Path Params
    long sizeOfPathParams_userId = strlen(userId)+3 + strlen("{ userId }");
    if(userId == NULL) {
        goto end;
    }
    char* localVarToReplace_userId = malloc(sizeOfPathParams_userId);
    sprintf(localVarToReplace_userId, "{%s}", "userId");

    localVarPath = strReplace(localVarPath, localVarToReplace_userId, userId);


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
        printf("%s\n","Successfully deleted specified user");
    }
    if (apiClient->response_code == 403) {
        printf("%s\n","The access token used to access resource is wrong");
    }
    if (apiClient->response_code == 404) {
        printf("%s\n","user could not be found");
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
    free(localVarToReplace_userId);

}

// Returns specified user
//
user_t*
UsersAPI_usersGet(apiClient_t *apiClient, char * userId )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/users/{userId}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/users/{userId}");


    // Path Params
    long sizeOfPathParams_userId = strlen(userId)+3 + strlen("{ userId }");
    if(userId == NULL) {
        goto end;
    }
    char* localVarToReplace_userId = malloc(sizeOfPathParams_userId);
    sprintf(localVarToReplace_userId, "{%s}", "userId");

    localVarPath = strReplace(localVarPath, localVarToReplace_userId, userId);


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
        printf("%s\n","Returns user data for specified user");
    }
    if (apiClient->response_code == 403) {
        printf("%s\n","The access token used to access resource is wrong");
    }
    if (apiClient->response_code == 404) {
        printf("%s\n","user could not be found");
    }
    //nonprimitive not container
    cJSON *UsersAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    user_t *elementToReturn = user_parseFromJSON(UsersAPIlocalVarJSON);
    cJSON_Delete(UsersAPIlocalVarJSON);
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
    
    free(localVarPath);
    free(localVarToReplace_userId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Updates specified user
//
user_t*
UsersAPI_usersUpdate(apiClient_t *apiClient, char * userId , update_user_request_t * update_user_request )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/users/{userId}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/users/{userId}");


    // Path Params
    long sizeOfPathParams_userId = strlen(userId)+3 + strlen("{ userId }");
    if(userId == NULL) {
        goto end;
    }
    char* localVarToReplace_userId = malloc(sizeOfPathParams_userId);
    sprintf(localVarToReplace_userId, "{%s}", "userId");

    localVarPath = strReplace(localVarPath, localVarToReplace_userId, userId);



    // Body Param
    cJSON *localVarSingleItemJSON_update_user_request = NULL;
    if (update_user_request != NULL)
    {
        //string
        localVarSingleItemJSON_update_user_request = update_user_request_convertToJSON(update_user_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_update_user_request);
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
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","Successfully updated specified user");
    }
    if (apiClient->response_code == 403) {
        printf("%s\n","The access token used to access resource is wrong");
    }
    if (apiClient->response_code == 404) {
        printf("%s\n","user could not be found");
    }
    //nonprimitive not container
    cJSON *UsersAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    user_t *elementToReturn = user_parseFromJSON(UsersAPIlocalVarJSON);
    cJSON_Delete(UsersAPIlocalVarJSON);
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
    free(localVarToReplace_userId);
    if (localVarSingleItemJSON_update_user_request) {
        cJSON_Delete(localVarSingleItemJSON_update_user_request);
        localVarSingleItemJSON_update_user_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

