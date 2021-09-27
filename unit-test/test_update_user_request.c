#ifndef update_user_request_TEST
#define update_user_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_user_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_user_request.h"
update_user_request_t* instantiate_update_user_request(int include_optional);



update_user_request_t* instantiate_update_user_request(int include_optional) {
  update_user_request_t* update_user_request = NULL;
  if (include_optional) {
    update_user_request = update_user_request_create(
      "0"
    );
  } else {
    update_user_request = update_user_request_create(
      "0"
    );
  }

  return update_user_request;
}


#ifdef update_user_request_MAIN

void test_update_user_request(int include_optional) {
    update_user_request_t* update_user_request_1 = instantiate_update_user_request(include_optional);

	cJSON* jsonupdate_user_request_1 = update_user_request_convertToJSON(update_user_request_1);
	printf("update_user_request :\n%s\n", cJSON_Print(jsonupdate_user_request_1));
	update_user_request_t* update_user_request_2 = update_user_request_parseFromJSON(jsonupdate_user_request_1);
	cJSON* jsonupdate_user_request_2 = update_user_request_convertToJSON(update_user_request_2);
	printf("repeating update_user_request:\n%s\n", cJSON_Print(jsonupdate_user_request_2));
}

int main() {
  test_update_user_request(1);
  test_update_user_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_user_request_MAIN
#endif // update_user_request_TEST
