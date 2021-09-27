#ifndef tenant_company_info_TEST
#define tenant_company_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tenant_company_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tenant_company_info.h"
tenant_company_info_t* instantiate_tenant_company_info(int include_optional);



tenant_company_info_t* instantiate_tenant_company_info(int include_optional) {
  tenant_company_info_t* tenant_company_info = NULL;
  if (include_optional) {
    tenant_company_info = tenant_company_info_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    tenant_company_info = tenant_company_info_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return tenant_company_info;
}


#ifdef tenant_company_info_MAIN

void test_tenant_company_info(int include_optional) {
    tenant_company_info_t* tenant_company_info_1 = instantiate_tenant_company_info(include_optional);

	cJSON* jsontenant_company_info_1 = tenant_company_info_convertToJSON(tenant_company_info_1);
	printf("tenant_company_info :\n%s\n", cJSON_Print(jsontenant_company_info_1));
	tenant_company_info_t* tenant_company_info_2 = tenant_company_info_parseFromJSON(jsontenant_company_info_1);
	cJSON* jsontenant_company_info_2 = tenant_company_info_convertToJSON(tenant_company_info_2);
	printf("repeating tenant_company_info:\n%s\n", cJSON_Print(jsontenant_company_info_2));
}

int main() {
  test_tenant_company_info(1);
  test_tenant_company_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // tenant_company_info_MAIN
#endif // tenant_company_info_TEST
