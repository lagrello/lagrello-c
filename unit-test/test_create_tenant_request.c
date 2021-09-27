#ifndef create_tenant_request_TEST
#define create_tenant_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_tenant_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_tenant_request.h"
create_tenant_request_t* instantiate_create_tenant_request(int include_optional);



create_tenant_request_t* instantiate_create_tenant_request(int include_optional) {
  create_tenant_request_t* create_tenant_request = NULL;
  if (include_optional) {
    create_tenant_request = create_tenant_request_create(
      "Example Company",
      "admin@example.com"
    );
  } else {
    create_tenant_request = create_tenant_request_create(
      "Example Company",
      "admin@example.com"
    );
  }

  return create_tenant_request;
}


#ifdef create_tenant_request_MAIN

void test_create_tenant_request(int include_optional) {
    create_tenant_request_t* create_tenant_request_1 = instantiate_create_tenant_request(include_optional);

	cJSON* jsoncreate_tenant_request_1 = create_tenant_request_convertToJSON(create_tenant_request_1);
	printf("create_tenant_request :\n%s\n", cJSON_Print(jsoncreate_tenant_request_1));
	create_tenant_request_t* create_tenant_request_2 = create_tenant_request_parseFromJSON(jsoncreate_tenant_request_1);
	cJSON* jsoncreate_tenant_request_2 = create_tenant_request_convertToJSON(create_tenant_request_2);
	printf("repeating create_tenant_request:\n%s\n", cJSON_Print(jsoncreate_tenant_request_2));
}

int main() {
  test_create_tenant_request(1);
  test_create_tenant_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_tenant_request_MAIN
#endif // create_tenant_request_TEST
