#ifndef totp_enable_request_TEST
#define totp_enable_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define totp_enable_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/totp_enable_request.h"
totp_enable_request_t* instantiate_totp_enable_request(int include_optional);



totp_enable_request_t* instantiate_totp_enable_request(int include_optional) {
  totp_enable_request_t* totp_enable_request = NULL;
  if (include_optional) {
    totp_enable_request = totp_enable_request_create(
      1
    );
  } else {
    totp_enable_request = totp_enable_request_create(
      1
    );
  }

  return totp_enable_request;
}


#ifdef totp_enable_request_MAIN

void test_totp_enable_request(int include_optional) {
    totp_enable_request_t* totp_enable_request_1 = instantiate_totp_enable_request(include_optional);

	cJSON* jsontotp_enable_request_1 = totp_enable_request_convertToJSON(totp_enable_request_1);
	printf("totp_enable_request :\n%s\n", cJSON_Print(jsontotp_enable_request_1));
	totp_enable_request_t* totp_enable_request_2 = totp_enable_request_parseFromJSON(jsontotp_enable_request_1);
	cJSON* jsontotp_enable_request_2 = totp_enable_request_convertToJSON(totp_enable_request_2);
	printf("repeating totp_enable_request:\n%s\n", cJSON_Print(jsontotp_enable_request_2));
}

int main() {
  test_totp_enable_request(1);
  test_totp_enable_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // totp_enable_request_MAIN
#endif // totp_enable_request_TEST
