# C API client for lagrello_api

## Overview
This API client was generated by the [OpenAPI Generator](https://openapi-generator.tech) project. By using the [OpenAPI spec](https://openapis.org) from a remote server, you can easily generate an API client.

- API version: 1.0.0
- Package version: 
- Build package: org.openapitools.codegen.languages.CLibcurlClientCodegen

## Installation
You'll need the `curl 7.58.0` package in order to build the API. To have code formatted nicely, you also need to have uncrustify version 0.67 or later.

# Prerequisites

## Install the `curl 7.58.0` package with the following command on Linux.
```bash
sudo apt remove curl
wget http://curl.haxx.se/download/curl-7.58.0.tar.gz
tar -xvf curl-7.58.0.tar.gz
cd curl-7.58.0/
./configure
make
sudo make install
```
## Install the `uncrustify 0.67` package with the following command on Linux.
```bash
git clone https://github.com/uncrustify/uncrustify.git
cd uncrustify
mkdir build
cd build
cmake ..
make
sudo make install
```

## Compile the sample:
This will compile the generated code and create a library in the build folder which has to be linked to the codes where API will be used.
```bash
mkdir build
cd build
// To install library to specific location, use following commands
cmake -DCMAKE_INSTALL_PREFIX=/pathtolocaiton ..
// for normal install use following command
cmake ..
make
sudo make install
```
## How to use compiled library
Considering the test/source code which uses the API is written in main.c(respective api include is written and all objects necessary are defined and created)

To compile main.c(considering the file is present in build folder) use following command
-L - locaiton of the library(not required if cmake with normal installation is performed)
-l library name
```bash
gcc main.c -L. -llagrello_api -o main
```
Once compiled, you can run it with ``` ./main ```

Note: You don't need to specify includes for models and include folder seperately as they are path linked. You just have to import the api.h file in your code, the include linking will work.

## Documentation for API Endpoints

All URIs are relative to *https://api.lagrello.com*

Category | Method | HTTP request | Description
------------ | ------------- | ------------- | -------------
*AuthAPI* | [**AuthAPI_usersEmailAuth**](docs/AuthAPI.md#AuthAPI_usersEmailAuth) | **GET** /v1/users/email | Gives back user data for the magic link token
*AuthAPI* | [**AuthAPI_usersEmailSend**](docs/AuthAPI.md#AuthAPI_usersEmailSend) | **POST** /v1/users/{userId}/email | This endpoint will be used when you want to send a magic login link to specified user
*AuthAPI* | [**AuthAPI_usersTotpAuth**](docs/AuthAPI.md#AuthAPI_usersTotpAuth) | **GET** /v1/users/{userId}/totp | Verify users TOTP token
*AuthAPI* | [**AuthAPI_usersTotpToggle**](docs/AuthAPI.md#AuthAPI_usersTotpToggle) | **POST** /v1/users/{userId}/totp | Enables or disables Time-based One-Time Password authentication method for specified user
*ImagesAPI* | [**ImagesAPI_imagesTotp**](docs/ImagesAPI.md#ImagesAPI_imagesTotp) | **GET** /v1/images/totp | Returns a generated QR code
*InternalAPI* | [**InternalAPI_tenantsCardtoken**](docs/InternalAPI.md#InternalAPI_tenantsCardtoken) | **GET** /v1/tenant/cardtoken | Returns token that is used by stripe to save card number.
*TenantsAPI* | [**TenantsAPI_tenantUpdate**](docs/TenantsAPI.md#TenantsAPI_tenantUpdate) | **PATCH** /v1/tenant | Updates tenant information
*TenantsAPI* | [**TenantsAPI_tenantsActivate**](docs/TenantsAPI.md#TenantsAPI_tenantsActivate) | **POST** /v1/tenant/activate | Activates the tenant, checks that all necessary information to activate a tenant is included
*TenantsAPI* | [**TenantsAPI_tenantsCreate**](docs/TenantsAPI.md#TenantsAPI_tenantsCreate) | **POST** /v1/tenant | Creates new tenant
*TenantsAPI* | [**TenantsAPI_tenantsCreate_0**](docs/TenantsAPI.md#TenantsAPI_tenantsCreate_0) | **DELETE** /v1/tenant | Deletes tenant caller is part of, will send verification email before deleting tenant
*TenantsAPI* | [**TenantsAPI_tenantsGet**](docs/TenantsAPI.md#TenantsAPI_tenantsGet) | **GET** /v1/tenant | Returns the tenant information the caller is part of
*TokensAPI* | [**TokensAPI_tokensCreate**](docs/TokensAPI.md#TokensAPI_tokensCreate) | **POST** /v1/tokens | Creates new token
*TokensAPI* | [**TokensAPI_tokensDelete**](docs/TokensAPI.md#TokensAPI_tokensDelete) | **DELETE** /v1/tokens/{id} | Deletes specifed access token
*TokensAPI* | [**TokensAPI_tokensList**](docs/TokensAPI.md#TokensAPI_tokensList) | **GET** /v1/tokens | Returns a list of all active tokens in tenant
*UsersAPI* | [**UsersAPI_usersCreate**](docs/UsersAPI.md#UsersAPI_usersCreate) | **POST** /v1/users | Creates a user in tenant, tenant is determined from the token
*UsersAPI* | [**UsersAPI_usersDelete**](docs/UsersAPI.md#UsersAPI_usersDelete) | **DELETE** /v1/users/{userId} | Deletes specified user
*UsersAPI* | [**UsersAPI_usersGet**](docs/UsersAPI.md#UsersAPI_usersGet) | **GET** /v1/users/{userId} | Returns specified user
*UsersAPI* | [**UsersAPI_usersUpdate**](docs/UsersAPI.md#UsersAPI_usersUpdate) | **PATCH** /v1/users/{userId} | Updates specified user


## Documentation for Models

 - [activate_tenant_request_t](docs/activate_tenant_request.md)
 - [create_tenant_request_t](docs/create_tenant_request.md)
 - [create_token_request_t](docs/create_token_request.md)
 - [create_user_request_t](docs/create_user_request.md)
 - [error_t](docs/error.md)
 - [paging_t](docs/paging.md)
 - [tenant_t](docs/tenant.md)
 - [tenant_company_info_t](docs/tenant_company_info.md)
 - [token_t](docs/token.md)
 - [token_list_t](docs/token_list.md)
 - [totp_enable_request_t](docs/totp_enable_request.md)
 - [totp_enable_response_t](docs/totp_enable_response.md)
 - [update_tenant_request_t](docs/update_tenant_request.md)
 - [update_user_request_t](docs/update_user_request.md)
 - [user_t](docs/user.md)


## Documentation for Authorization


### token


- **Type**: HTTP basic authentication


## Author

support@lagrello.com

