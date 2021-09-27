# UsersAPI

All URIs are relative to *https://api.lagrello.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**UsersAPI_usersCreate**](UsersAPI.md#UsersAPI_usersCreate) | **POST** /v1/users | Creates a user in tenant, tenant is determined from the token
[**UsersAPI_usersDelete**](UsersAPI.md#UsersAPI_usersDelete) | **DELETE** /v1/users/{userId} | Deletes specified user
[**UsersAPI_usersGet**](UsersAPI.md#UsersAPI_usersGet) | **GET** /v1/users/{userId} | Returns specified user
[**UsersAPI_usersUpdate**](UsersAPI.md#UsersAPI_usersUpdate) | **PATCH** /v1/users/{userId} | Updates specified user


# **UsersAPI_usersCreate**
```c
// Creates a user in tenant, tenant is determined from the token
//
user_t* UsersAPI_usersCreate(apiClient_t *apiClient, create_user_request_t * create_user_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 
**create_user_request** | **[create_user_request_t](create_user_request.md) \*** |  | [optional] 

### Return type

[user_t](user.md) *


### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersAPI_usersDelete**
```c
// Deletes specified user
//
void UsersAPI_usersDelete(apiClient_t *apiClient, char * userId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 
**userId** | **char \*** | Id of the user you want to delete | 

### Return type

void

### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersAPI_usersGet**
```c
// Returns specified user
//
user_t* UsersAPI_usersGet(apiClient_t *apiClient, char * userId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 
**userId** | **char \*** | userId of user you want to fetch information about | 

### Return type

[user_t](user.md) *


### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersAPI_usersUpdate**
```c
// Updates specified user
//
user_t* UsersAPI_usersUpdate(apiClient_t *apiClient, char * userId, update_user_request_t * update_user_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 
**userId** | **char \*** | Id of the user you want to update | 
**update_user_request** | **[update_user_request_t](update_user_request.md) \*** |  | [optional] 

### Return type

[user_t](user.md) *


### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

