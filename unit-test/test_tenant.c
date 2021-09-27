#ifndef tenant_TEST
#define tenant_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tenant_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tenant.h"
tenant_t* instantiate_tenant(int include_optional);

#include "test_tenant_company_info.c"


tenant_t* instantiate_tenant(int include_optional) {
  tenant_t* tenant = NULL;
  if (include_optional) {
    tenant = tenant_create(
      "0",
      "0",
      "https://example.com/users/{}",
       // false, not to have infinite recursion
      instantiate_tenant_company_info(0),
      1
    );
  } else {
    tenant = tenant_create(
      "0",
      "0",
      "https://example.com/users/{}",
      NULL,
      1
    );
  }

  return tenant;
}


#ifdef tenant_MAIN

void test_tenant(int include_optional) {
    tenant_t* tenant_1 = instantiate_tenant(include_optional);

	cJSON* jsontenant_1 = tenant_convertToJSON(tenant_1);
	printf("tenant :\n%s\n", cJSON_Print(jsontenant_1));
	tenant_t* tenant_2 = tenant_parseFromJSON(jsontenant_1);
	cJSON* jsontenant_2 = tenant_convertToJSON(tenant_2);
	printf("repeating tenant:\n%s\n", cJSON_Print(jsontenant_2));
}

int main() {
  test_tenant(1);
  test_tenant(0);

  printf("Hello world \n");
  return 0;
}

#endif // tenant_MAIN
#endif // tenant_TEST
