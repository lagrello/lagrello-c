#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/error.h"


// Returns token that is used by stripe to save card number.
//
char*
InternalAPI_tenantsCardtoken(apiClient_t *apiClient);


