#ifndef totp_enable_response_TEST
#define totp_enable_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define totp_enable_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/totp_enable_response.h"
totp_enable_response_t* instantiate_totp_enable_response(int include_optional);



totp_enable_response_t* instantiate_totp_enable_response(int include_optional) {
  totp_enable_response_t* totp_enable_response = NULL;
  if (include_optional) {
    totp_enable_response = totp_enable_response_create(
      "0",
      "0"
    );
  } else {
    totp_enable_response = totp_enable_response_create(
      "0",
      "0"
    );
  }

  return totp_enable_response;
}


#ifdef totp_enable_response_MAIN

void test_totp_enable_response(int include_optional) {
    totp_enable_response_t* totp_enable_response_1 = instantiate_totp_enable_response(include_optional);

	cJSON* jsontotp_enable_response_1 = totp_enable_response_convertToJSON(totp_enable_response_1);
	printf("totp_enable_response :\n%s\n", cJSON_Print(jsontotp_enable_response_1));
	totp_enable_response_t* totp_enable_response_2 = totp_enable_response_parseFromJSON(jsontotp_enable_response_1);
	cJSON* jsontotp_enable_response_2 = totp_enable_response_convertToJSON(totp_enable_response_2);
	printf("repeating totp_enable_response:\n%s\n", cJSON_Print(jsontotp_enable_response_2));
}

int main() {
  test_totp_enable_response(1);
  test_totp_enable_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // totp_enable_response_MAIN
#endif // totp_enable_response_TEST
