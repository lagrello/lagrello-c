# InternalAPI

All URIs are relative to *https://api.lagrello.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**InternalAPI_tenantsCardtoken**](InternalAPI.md#InternalAPI_tenantsCardtoken) | **GET** /v1/tenant/cardtoken | Returns token that is used by stripe to save card number.


# **InternalAPI_tenantsCardtoken**
```c
// Returns token that is used by stripe to save card number.
//
char* InternalAPI_tenantsCardtoken(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 

### Return type

char*



### Authorization

[token](../README.md#token)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

