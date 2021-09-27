# TokensAPI

All URIs are relative to *https://api.lagrello.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**TokensAPI_tokensCreate**](TokensAPI.md#TokensAPI_tokensCreate) | **POST** /v1/tokens | Creates new token
[**TokensAPI_tokensDelete**](TokensAPI.md#TokensAPI_tokensDelete) | **DELETE** /v1/tokens/{id} | Deletes specifed access token
[**TokensAPI_tokensList**](TokensAPI.md#TokensAPI_tokensList) | **GET** /v1/tokens | Returns a list of all active tokens in tenant


# **TokensAPI_tokensCreate**
```c
// Creates new token
//
token_t* TokensAPI_tokensCreate(apiClient_t *apiClient, create_token_request_t * create_token_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 
**create_token_request** | **[create_token_request_t](create_token_request.md) \*** |  | [optional] 

### Return type

[token_t](token.md) *


### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TokensAPI_tokensDelete**
```c
// Deletes specifed access token
//
void TokensAPI_tokensDelete(apiClient_t *apiClient, char * tokenId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 
**tokenId** | **char \*** | Id of the token you want to delete | 

### Return type

void

### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TokensAPI_tokensList**
```c
// Returns a list of all active tokens in tenant
//
token_list_t* TokensAPI_tokensList(apiClient_t *apiClient, int size, int page);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 
**size** | **int** | Maximum of results per page | [optional] 
**page** | **int** | The page you want to see | [optional] 

### Return type

[token_list_t](token_list.md) *


### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

