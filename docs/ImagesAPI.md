# ImagesAPI

All URIs are relative to *https://api.lagrello.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ImagesAPI_imagesTotp**](ImagesAPI.md#ImagesAPI_imagesTotp) | **GET** /v1/images/totp | Returns a generated QR code


# **ImagesAPI_imagesTotp**
```c
// Returns a generated QR code
//
// This endpoint does not do any lookups of any sort. It will just generate a QR code from the parameters supplied to it.
//
binary_t** ImagesAPI_imagesTotp(apiClient_t *apiClient, char * tenantName, char * userId, char * userSecret);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration | 
**tenantName** | **char \*** | The company name you your users to see in their TOTP application | [optional] 
**userId** | **char \*** | The userId of the user you want to create the TOTP QR image for | [optional] 
**userSecret** | **char \*** | The TOTP secret for the specified user | [optional] 

### Return type

binary_t**



### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: image/png, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

