# AuthAPI

All URIs are relative to *https://api.lagrello.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AuthAPI_usersEmailAuth**](AuthAPI.md#AuthAPI_usersEmailAuth) | **GET** /v1/users/email | Gives back user data for the magic link token
[**AuthAPI_usersEmailSend**](AuthAPI.md#AuthAPI_usersEmailSend) | **POST** /v1/users/{userId}/email | This endpoint will be used when you want to send a magic login link to specified user
[**AuthAPI_usersTotpAuth**](AuthAPI.md#AuthAPI_usersTotpAuth) | **GET** /v1/users/{userId}/totp | Verify users TOTP token
[**AuthAPI_usersTotpToggle**](AuthAPI.md#AuthAPI_usersTotpToggle) | **POST** /v1/users/{userId}/totp | Enables or disables Time-based One-Time Password authentication method for specified user


# **AuthAPI_usersEmailAuth**
```c
// Gives back user data for the magic link token
//
user_t* AuthAPI_usersEmailAuth(apiClient_t *apiClient, char * payload);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 
**payload** | **char \*** | The magic link token the user sent | 

### Return type

[user_t](user.md) *


### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthAPI_usersEmailSend**
```c
// This endpoint will be used when you want to send a magic login link to specified user
//
void AuthAPI_usersEmailSend(apiClient_t *apiClient, char * userId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 
**userId** | **char \*** | Id of the user you want to send magic link to | 

### Return type

void

### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthAPI_usersTotpAuth**
```c
// Verify users TOTP token
//
user_t* AuthAPI_usersTotpAuth(apiClient_t *apiClient, char * userId, char * payload);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 
**userId** | **char \*** | Id of the user you want to verify TOTP code for | 
**payload** | **char \*** | The totp token the user sent | 

### Return type

[user_t](user.md) *


### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthAPI_usersTotpToggle**
```c
// Enables or disables Time-based One-Time Password authentication method for specified user
//
// When you want your users to be able to use TOTP authentication you need to send enable set to true as payload to this endpoint. To turn off TOTP set enable to false. When enabling you will recieve the secret key and a QR code link. The QR code you need to show your user for them to scan.
//
totp_enable_response_t* AuthAPI_usersTotpToggle(apiClient_t *apiClient, char * userId, totp_enable_request_t * totp_enable_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 
**userId** | **char \*** | Id of the user you want to enable TOTP for | 
**totp_enable_request** | **[totp_enable_request_t](totp_enable_request.md) \*** |  | [optional] 

### Return type

[totp_enable_response_t](totp_enable_response.md) *


### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

