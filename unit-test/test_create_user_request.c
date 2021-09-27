#ifndef create_user_request_TEST
#define create_user_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_user_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_user_request.h"
create_user_request_t* instantiate_create_user_request(int include_optional);



create_user_request_t* instantiate_create_user_request(int include_optional) {
  create_user_request_t* create_user_request = NULL;
  if (include_optional) {
    create_user_request = create_user_request_create(
      "0",
      "0"
    );
  } else {
    create_user_request = create_user_request_create(
      "0",
      "0"
    );
  }

  return create_user_request;
}


#ifdef create_user_request_MAIN

void test_create_user_request(int include_optional) {
    create_user_request_t* create_user_request_1 = instantiate_create_user_request(include_optional);

	cJSON* jsoncreate_user_request_1 = create_user_request_convertToJSON(create_user_request_1);
	printf("create_user_request :\n%s\n", cJSON_Print(jsoncreate_user_request_1));
	create_user_request_t* create_user_request_2 = create_user_request_parseFromJSON(jsoncreate_user_request_1);
	cJSON* jsoncreate_user_request_2 = create_user_request_convertToJSON(create_user_request_2);
	printf("repeating create_user_request:\n%s\n", cJSON_Print(jsoncreate_user_request_2));
}

int main() {
  test_create_user_request(1);
  test_create_user_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_user_request_MAIN
#endif // create_user_request_TEST
