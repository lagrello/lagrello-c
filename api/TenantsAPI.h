#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/activate_tenant_request.h"
#include "../model/create_tenant_request.h"
#include "../model/error.h"
#include "../model/tenant.h"
#include "../model/update_tenant_request.h"


// Updates tenant information
//
// This endpoint is used to update certain information about your tenant. For example if you want to update your tenant's callback URL you will do that here.
//
tenant_t*
TenantsAPI_tenantUpdate(apiClient_t *apiClient, update_tenant_request_t * update_tenant_request );


// Activates the tenant, checks that all necessary information to activate a tenant is included
//
tenant_t*
TenantsAPI_tenantsActivate(apiClient_t *apiClient, activate_tenant_request_t * activate_tenant_request );


// Creates new tenant
//
tenant_t*
TenantsAPI_tenantsCreate(apiClient_t *apiClient, create_tenant_request_t * create_tenant_request );


// Deletes tenant caller is part of, will send verification email before deleting tenant
//
// This endpoint will delete your tenant. Will send an email to the admin email address of the tenant confirming that you want to delete your tenant before deletion.
//
tenant_t*
TenantsAPI_tenantsCreate_0(apiClient_t *apiClient);


// Returns the tenant information the caller is part of
//
tenant_t*
TenantsAPI_tenantsGet(apiClient_t *apiClient);


