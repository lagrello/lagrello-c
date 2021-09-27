#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "TenantsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// Updates tenant information
//
// This endpoint is used to update certain information about your tenant. For example if you want to update your tenant's callback URL you will do that here.
//
tenant_t*
TenantsAPI_tenantUpdate(apiClient_t *apiClient, update_tenant_request_t * update_tenant_request )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/tenant")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/tenant");




    // Body Param
    cJSON *localVarSingleItemJSON_update_tenant_request = NULL;
    if (update_tenant_request != NULL)
    {
        //string
        localVarSingleItemJSON_update_tenant_request = update_tenant_request_convertToJSON(update_tenant_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_update_tenant_request);
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
        printf("%s\n","Successfully updated tenant");
    }
    if (apiClient->response_code == 403) {
        printf("%s\n","The access token used to access resource is wrong");
    }
    //nonprimitive not container
    cJSON *TenantsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    tenant_t *elementToReturn = tenant_parseFromJSON(TenantsAPIlocalVarJSON);
    cJSON_Delete(TenantsAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_update_tenant_request) {
        cJSON_Delete(localVarSingleItemJSON_update_tenant_request);
        localVarSingleItemJSON_update_tenant_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Activates the tenant, checks that all necessary information to activate a tenant is included
//
tenant_t*
TenantsAPI_tenantsActivate(apiClient_t *apiClient, activate_tenant_request_t * activate_tenant_request )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/tenant/activate")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/tenant/activate");




    // Body Param
    cJSON *localVarSingleItemJSON_activate_tenant_request = NULL;
    if (activate_tenant_request != NULL)
    {
        //string
        localVarSingleItemJSON_activate_tenant_request = activate_tenant_request_convertToJSON(activate_tenant_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_activate_tenant_request);
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
        printf("%s\n","Returns tenant information about the newly activated tenant.");
    }
    if (apiClient->response_code == 400) {
        printf("%s\n","The payload of the request is not valid");
    }
    if (apiClient->response_code == 403) {
        printf("%s\n","The access token used to access resource is wrong");
    }
    //nonprimitive not container
    cJSON *TenantsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    tenant_t *elementToReturn = tenant_parseFromJSON(TenantsAPIlocalVarJSON);
    cJSON_Delete(TenantsAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_activate_tenant_request) {
        cJSON_Delete(localVarSingleItemJSON_activate_tenant_request);
        localVarSingleItemJSON_activate_tenant_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Creates new tenant
//
tenant_t*
TenantsAPI_tenantsCreate(apiClient_t *apiClient, create_tenant_request_t * create_tenant_request )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/tenant")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/tenant");




    // Body Param
    cJSON *localVarSingleItemJSON_create_tenant_request = NULL;
    if (create_tenant_request != NULL)
    {
        //string
        localVarSingleItemJSON_create_tenant_request = create_tenant_request_convertToJSON(create_tenant_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_create_tenant_request);
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
        printf("%s\n","Returns information about the newly created tenant");
    }
    //nonprimitive not container
    cJSON *TenantsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    tenant_t *elementToReturn = tenant_parseFromJSON(TenantsAPIlocalVarJSON);
    cJSON_Delete(TenantsAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_create_tenant_request) {
        cJSON_Delete(localVarSingleItemJSON_create_tenant_request);
        localVarSingleItemJSON_create_tenant_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Deletes tenant caller is part of, will send verification email before deleting tenant
//
// This endpoint will delete your tenant. Will send an email to the admin email address of the tenant confirming that you want to delete your tenant before deletion.
//
tenant_t*
TenantsAPI_tenantsCreate_0(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/tenant")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/tenant");



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
        printf("%s\n","Sucess, will send verification email before deleting");
    }
    if (apiClient->response_code == 403) {
        printf("%s\n","The access token used to access resource is wrong");
    }
    //nonprimitive not container
    cJSON *TenantsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    tenant_t *elementToReturn = tenant_parseFromJSON(TenantsAPIlocalVarJSON);
    cJSON_Delete(TenantsAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Returns the tenant information the caller is part of
//
tenant_t*
TenantsAPI_tenantsGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/v1/tenant")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/v1/tenant");



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
        printf("%s\n","Gives back the tenant call is part of");
    }
    if (apiClient->response_code == 403) {
        printf("%s\n","The access token used to access resource is wrong");
    }
    //nonprimitive not container
    cJSON *TenantsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    tenant_t *elementToReturn = tenant_parseFromJSON(TenantsAPIlocalVarJSON);
    cJSON_Delete(TenantsAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

