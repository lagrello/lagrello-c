#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ImagesAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// Returns a generated QR code
//
// This endpoint does not do any lookups of any sort. It will just generate a QR code from the parameters supplied to it.
//
binary_t**
ImagesAPI_imagesTotp(apiClient_t *apiClient, char * tenantName , char * userId , char * userSecret )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/images/totp")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/images/totp");




    // query parameters
    char *keyQuery_tenantName = NULL;
    char * valueQuery_tenantName = NULL;
    keyValuePair_t *keyPairQuery_tenantName = 0;
    if (tenantName)
    {
        keyQuery_tenantName = strdup("tenantName");
        valueQuery_tenantName = strdup((tenantName));
        keyPairQuery_tenantName = keyValuePair_create(keyQuery_tenantName, valueQuery_tenantName);
        list_addElement(localVarQueryParameters,keyPairQuery_tenantName);
    }

    // query parameters
    char *keyQuery_userId = NULL;
    char * valueQuery_userId = NULL;
    keyValuePair_t *keyPairQuery_userId = 0;
    if (userId)
    {
        keyQuery_userId = strdup("userId");
        valueQuery_userId = strdup((userId));
        keyPairQuery_userId = keyValuePair_create(keyQuery_userId, valueQuery_userId);
        list_addElement(localVarQueryParameters,keyPairQuery_userId);
    }

    // query parameters
    char *keyQuery_userSecret = NULL;
    char * valueQuery_userSecret = NULL;
    keyValuePair_t *keyPairQuery_userSecret = 0;
    if (userSecret)
    {
        keyQuery_userSecret = strdup("userSecret");
        valueQuery_userSecret = strdup((userSecret));
        keyPairQuery_userSecret = keyValuePair_create(keyQuery_userSecret, valueQuery_userSecret);
        list_addElement(localVarQueryParameters,keyPairQuery_userSecret);
    }
    list_addElement(localVarHeaderType,"image/png"); //produces
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
        printf("%s\n","Gives back the QR code as an image");
    }
    if (apiClient->response_code == 400) {
        printf("%s\n","The payload of the request is not valid");
    }
    //primitive reutrn type simple
    binary_t** elementToReturn =  strdup((binary_t**)apiClient->dataReceived);

    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_tenantName){
        free(keyQuery_tenantName);
        keyQuery_tenantName = NULL;
    }
    if(valueQuery_tenantName){
        free(valueQuery_tenantName);
        valueQuery_tenantName = NULL;
    }
    if(keyPairQuery_tenantName){
        keyValuePair_free(keyPairQuery_tenantName);
        keyPairQuery_tenantName = NULL;
    }
    if(keyQuery_userId){
        free(keyQuery_userId);
        keyQuery_userId = NULL;
    }
    if(valueQuery_userId){
        free(valueQuery_userId);
        valueQuery_userId = NULL;
    }
    if(keyPairQuery_userId){
        keyValuePair_free(keyPairQuery_userId);
        keyPairQuery_userId = NULL;
    }
    if(keyQuery_userSecret){
        free(keyQuery_userSecret);
        keyQuery_userSecret = NULL;
    }
    if(valueQuery_userSecret){
        free(valueQuery_userSecret);
        valueQuery_userSecret = NULL;
    }
    if(keyPairQuery_userSecret){
        keyValuePair_free(keyPairQuery_userSecret);
        keyPairQuery_userSecret = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

