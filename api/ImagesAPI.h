#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/error.h"


// Returns a generated QR code
//
// This endpoint does not do any lookups of any sort. It will just generate a QR code from the parameters supplied to it.
//
binary_t**
ImagesAPI_imagesTotp(apiClient_t *apiClient, char * tenantName , char * userId , char * userSecret );


