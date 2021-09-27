# TenantsAPI

All URIs are relative to *https://api.lagrello.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**TenantsAPI_tenantUpdate**](TenantsAPI.md#TenantsAPI_tenantUpdate) | **PATCH** /v1/tenant | Updates tenant information
[**TenantsAPI_tenantsActivate**](TenantsAPI.md#TenantsAPI_tenantsActivate) | **POST** /v1/tenant/activate | Activates the tenant, checks that all necessary information to activate a tenant is included
[**TenantsAPI_tenantsCreate**](TenantsAPI.md#TenantsAPI_tenantsCreate) | **POST** /v1/tenant | Creates new tenant
[**TenantsAPI_tenantsCreate_0**](TenantsAPI.md#TenantsAPI_tenantsCreate_0) | **DELETE** /v1/tenant | Deletes tenant caller is part of, will send verification email before deleting tenant
[**TenantsAPI_tenantsGet**](TenantsAPI.md#TenantsAPI_tenantsGet) | **GET** /v1/tenant | Returns the tenant information the caller is part of


# **TenantsAPI_tenantUpdate**
```c
// Updates tenant information
//
// This endpoint is used to update certain information about your tenant. For example if you want to update your tenant's callback URL you will do that here.
//
tenant_t* TenantsAPI_tenantUpdate(apiClient_t *apiClient, update_tenant_request_t * update_tenant_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 
**update_tenant_request** | **[update_tenant_request_t](update_tenant_request.md) \*** |  | [optional] 

### Return type

[tenant_t](tenant.md) *


### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TenantsAPI_tenantsActivate**
```c
// Activates the tenant, checks that all necessary information to activate a tenant is included
//
tenant_t* TenantsAPI_tenantsActivate(apiClient_t *apiClient, activate_tenant_request_t * activate_tenant_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 
**activate_tenant_request** | **[activate_tenant_request_t](activate_tenant_request.md) \*** |  | [optional] 

### Return type

[tenant_t](tenant.md) *


### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TenantsAPI_tenantsCreate**
```c
// Creates new tenant
//
tenant_t* TenantsAPI_tenantsCreate(apiClient_t *apiClient, create_tenant_request_t * create_tenant_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 
**create_tenant_request** | **[create_tenant_request_t](create_tenant_request.md) \*** |  | [optional] 

### Return type

[tenant_t](tenant.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TenantsAPI_tenantsCreate_0**
```c
// Deletes tenant caller is part of, will send verification email before deleting tenant
//
// This endpoint will delete your tenant. Will send an email to the admin email address of the tenant confirming that you want to delete your tenant before deletion.
//
tenant_t* TenantsAPI_tenantsCreate_0(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 

### Return type

[tenant_t](tenant.md) *


### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TenantsAPI_tenantsGet**
```c
// Returns the tenant information the caller is part of
//
tenant_t* TenantsAPI_tenantsGet(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 

### Return type

[tenant_t](tenant.md) *


### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

