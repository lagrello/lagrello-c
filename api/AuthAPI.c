#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "AuthAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// Gives back user data for the magic link token
//
user_t*
AuthAPI_usersEmailAuth(apiClient_t *apiClient, char * payload )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/users/email")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/users/email");




    // query parameters
    char *keyQuery_payload = NULL;
    char * valueQuery_payload = NULL;
    keyValuePair_t *keyPairQuery_payload = 0;
    if (payload)
    {
        keyQuery_payload = strdup("payload");
        valueQuery_payload = strdup((payload));
        keyPairQuery_payload = keyValuePair_create(keyQuery_payload, valueQuery_payload);
        list_addElement(localVarQueryParameters,keyPairQuery_payload);
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
        printf("%s\n","Returns user data for authenticated user");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","End users token is wrong, DO NOT authenticate user");
    }
    if (apiClient->response_code == 403) {
        printf("%s\n","The access token used to access resource is wrong");
    }
    if (apiClient->response_code == 404) {
        printf("%s\n","user could not be found");
    }
    //nonprimitive not container
    cJSON *AuthAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    user_t *elementToReturn = user_parseFromJSON(AuthAPIlocalVarJSON);
    cJSON_Delete(AuthAPIlocalVarJSON);
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
    if(keyQuery_payload){
        free(keyQuery_payload);
        keyQuery_payload = NULL;
    }
    if(valueQuery_payload){
        free(valueQuery_payload);
        valueQuery_payload = NULL;
    }
    if(keyPairQuery_payload){
        keyValuePair_free(keyPairQuery_payload);
        keyPairQuery_payload = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// This endpoint will be used when you want to send a magic login link to specified user
//
void
AuthAPI_usersEmailSend(apiClient_t *apiClient, char * userId )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/users/{userId}/email")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/users/{userId}/email");


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
                    "POST");

    if (apiClient->response_code == 204) {
        printf("%s\n","Email to user has been sent successfully.");
    }
    if (apiClient->response_code == 400) {
        printf("%s\n","The payload of the request is not valid");
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

// Verify users TOTP token
//
user_t*
AuthAPI_usersTotpAuth(apiClient_t *apiClient, char * userId , char * payload )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/users/{userId}/totp")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/users/{userId}/totp");


    // Path Params
    long sizeOfPathParams_userId = strlen(userId)+3 + strlen("{ userId }");
    if(userId == NULL) {
        goto end;
    }
    char* localVarToReplace_userId = malloc(sizeOfPathParams_userId);
    sprintf(localVarToReplace_userId, "{%s}", "userId");

    localVarPath = strReplace(localVarPath, localVarToReplace_userId, userId);



    // query parameters
    char *keyQuery_payload = NULL;
    char * valueQuery_payload = NULL;
    keyValuePair_t *keyPairQuery_payload = 0;
    if (payload)
    {
        keyQuery_payload = strdup("payload");
        valueQuery_payload = strdup((payload));
        keyPairQuery_payload = keyValuePair_create(keyQuery_payload, valueQuery_payload);
        list_addElement(localVarQueryParameters,keyPairQuery_payload);
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
        printf("%s\n","Success - Returns the user information if the totp token is correct");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","End users token is wrong, DO NOT authenticate user");
    }
    if (apiClient->response_code == 403) {
        printf("%s\n","The access token used to access resource is wrong");
    }
    if (apiClient->response_code == 404) {
        printf("%s\n","user could not be found");
    }
    //nonprimitive not container
    cJSON *AuthAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    user_t *elementToReturn = user_parseFromJSON(AuthAPIlocalVarJSON);
    cJSON_Delete(AuthAPIlocalVarJSON);
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
    free(localVarToReplace_userId);
    if(keyQuery_payload){
        free(keyQuery_payload);
        keyQuery_payload = NULL;
    }
    if(valueQuery_payload){
        free(valueQuery_payload);
        valueQuery_payload = NULL;
    }
    if(keyPairQuery_payload){
        keyValuePair_free(keyPairQuery_payload);
        keyPairQuery_payload = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Enables or disables Time-based One-Time Password authentication method for specified user
//
// When you want your users to be able to use TOTP authentication you need to send enable set to true as payload to this endpoint. To turn off TOTP set enable to false. When enabling you will recieve the secret key and a QR code link. The QR code you need to show your user for them to scan.
//
totp_enable_response_t*
AuthAPI_usersTotpToggle(apiClient_t *apiClient, char * userId , totp_enable_request_t * totp_enable_request )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/users/{userId}/totp")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/users/{userId}/totp");


    // Path Params
    long sizeOfPathParams_userId = strlen(userId)+3 + strlen("{ userId }");
    if(userId == NULL) {
        goto end;
    }
    char* localVarToReplace_userId = malloc(sizeOfPathParams_userId);
    sprintf(localVarToReplace_userId, "{%s}", "userId");

    localVarPath = strReplace(localVarPath, localVarToReplace_userId, userId);



    // Body Param
    cJSON *localVarSingleItemJSON_totp_enable_request = NULL;
    if (totp_enable_request != NULL)
    {
        //string
        localVarSingleItemJSON_totp_enable_request = totp_enable_request_convertToJSON(totp_enable_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_totp_enable_request);
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
        printf("%s\n","Will return user&#39;s secret key and a url where QR-code image can be found");
    }
    if (apiClient->response_code == 204) {
        printf("%s\n","Success when disabling TOTP for user");
    }
    if (apiClient->response_code == 403) {
        printf("%s\n","The access token used to access resource is wrong");
    }
    if (apiClient->response_code == 404) {
        printf("%s\n","user could not be found");
    }
    //nonprimitive not container
    cJSON *AuthAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    totp_enable_response_t *elementToReturn = totp_enable_response_parseFromJSON(AuthAPIlocalVarJSON);
    cJSON_Delete(AuthAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_totp_enable_request) {
        cJSON_Delete(localVarSingleItemJSON_totp_enable_request);
        localVarSingleItemJSON_totp_enable_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

