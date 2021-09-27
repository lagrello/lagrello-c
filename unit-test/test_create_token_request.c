#ifndef create_token_request_TEST
#define create_token_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_token_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_token_request.h"
create_token_request_t* instantiate_create_token_request(int include_optional);



create_token_request_t* instantiate_create_token_request(int include_optional) {
  create_token_request_t* create_token_request = NULL;
  if (include_optional) {
    create_token_request = create_token_request_create(
      "0",
      list_create()
    );
  } else {
    create_token_request = create_token_request_create(
      "0",
      list_create()
    );
  }

  return create_token_request;
}


#ifdef create_token_request_MAIN

void test_create_token_request(int include_optional) {
    create_token_request_t* create_token_request_1 = instantiate_create_token_request(include_optional);

	cJSON* jsoncreate_token_request_1 = create_token_request_convertToJSON(create_token_request_1);
	printf("create_token_request :\n%s\n", cJSON_Print(jsoncreate_token_request_1));
	create_token_request_t* create_token_request_2 = create_token_request_parseFromJSON(jsoncreate_token_request_1);
	cJSON* jsoncreate_token_request_2 = create_token_request_convertToJSON(create_token_request_2);
	printf("repeating create_token_request:\n%s\n", cJSON_Print(jsoncreate_token_request_2));
}

int main() {
  test_create_token_request(1);
  test_create_token_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_token_request_MAIN
#endif // create_token_request_TEST
