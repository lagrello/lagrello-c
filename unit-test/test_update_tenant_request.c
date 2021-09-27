#ifndef update_tenant_request_TEST
#define update_tenant_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_tenant_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_tenant_request.h"
update_tenant_request_t* instantiate_update_tenant_request(int include_optional);



update_tenant_request_t* instantiate_update_tenant_request(int include_optional) {
  update_tenant_request_t* update_tenant_request = NULL;
  if (include_optional) {
    update_tenant_request = update_tenant_request_create(
      "https://api.example.com/users/login/{}"
    );
  } else {
    update_tenant_request = update_tenant_request_create(
      "https://api.example.com/users/login/{}"
    );
  }

  return update_tenant_request;
}


#ifdef update_tenant_request_MAIN

void test_update_tenant_request(int include_optional) {
    update_tenant_request_t* update_tenant_request_1 = instantiate_update_tenant_request(include_optional);

	cJSON* jsonupdate_tenant_request_1 = update_tenant_request_convertToJSON(update_tenant_request_1);
	printf("update_tenant_request :\n%s\n", cJSON_Print(jsonupdate_tenant_request_1));
	update_tenant_request_t* update_tenant_request_2 = update_tenant_request_parseFromJSON(jsonupdate_tenant_request_1);
	cJSON* jsonupdate_tenant_request_2 = update_tenant_request_convertToJSON(update_tenant_request_2);
	printf("repeating update_tenant_request:\n%s\n", cJSON_Print(jsonupdate_tenant_request_2));
}

int main() {
  test_update_tenant_request(1);
  test_update_tenant_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_tenant_request_MAIN
#endif // update_tenant_request_TEST
