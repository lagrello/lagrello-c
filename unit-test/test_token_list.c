#ifndef token_list_TEST
#define token_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define token_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/token_list.h"
token_list_t* instantiate_token_list(int include_optional);

#include "test_paging.c"


token_list_t* instantiate_token_list(int include_optional) {
  token_list_t* token_list = NULL;
  if (include_optional) {
    token_list = token_list_create(
      list_create(),
       // false, not to have infinite recursion
      instantiate_paging(0)
    );
  } else {
    token_list = token_list_create(
      list_create(),
      NULL
    );
  }

  return token_list;
}


#ifdef token_list_MAIN

void test_token_list(int include_optional) {
    token_list_t* token_list_1 = instantiate_token_list(include_optional);

	cJSON* jsontoken_list_1 = token_list_convertToJSON(token_list_1);
	printf("token_list :\n%s\n", cJSON_Print(jsontoken_list_1));
	token_list_t* token_list_2 = token_list_parseFromJSON(jsontoken_list_1);
	cJSON* jsontoken_list_2 = token_list_convertToJSON(token_list_2);
	printf("repeating token_list:\n%s\n", cJSON_Print(jsontoken_list_2));
}

int main() {
  test_token_list(1);
  test_token_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // token_list_MAIN
#endif // token_list_TEST
