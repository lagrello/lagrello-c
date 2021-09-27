#ifndef activate_tenant_request_TEST
#define activate_tenant_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activate_tenant_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activate_tenant_request.h"
activate_tenant_request_t* instantiate_activate_tenant_request(int include_optional);



activate_tenant_request_t* instantiate_activate_tenant_request(int include_optional) {
  activate_tenant_request_t* activate_tenant_request = NULL;
  if (include_optional) {
    activate_tenant_request = activate_tenant_request_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    activate_tenant_request = activate_tenant_request_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return activate_tenant_request;
}


#ifdef activate_tenant_request_MAIN

void test_activate_tenant_request(int include_optional) {
    activate_tenant_request_t* activate_tenant_request_1 = instantiate_activate_tenant_request(include_optional);

	cJSON* jsonactivate_tenant_request_1 = activate_tenant_request_convertToJSON(activate_tenant_request_1);
	printf("activate_tenant_request :\n%s\n", cJSON_Print(jsonactivate_tenant_request_1));
	activate_tenant_request_t* activate_tenant_request_2 = activate_tenant_request_parseFromJSON(jsonactivate_tenant_request_1);
	cJSON* jsonactivate_tenant_request_2 = activate_tenant_request_convertToJSON(activate_tenant_request_2);
	printf("repeating activate_tenant_request:\n%s\n", cJSON_Print(jsonactivate_tenant_request_2));
}

int main() {
  test_activate_tenant_request(1);
  test_activate_tenant_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // activate_tenant_request_MAIN
#endif // activate_tenant_request_TEST
