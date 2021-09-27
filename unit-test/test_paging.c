#ifndef paging_TEST
#define paging_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define paging_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/paging.h"
paging_t* instantiate_paging(int include_optional);



paging_t* instantiate_paging(int include_optional) {
  paging_t* paging = NULL;
  if (include_optional) {
    paging = paging_create(
      "0",
      "0"
    );
  } else {
    paging = paging_create(
      "0",
      "0"
    );
  }

  return paging;
}


#ifdef paging_MAIN

void test_paging(int include_optional) {
    paging_t* paging_1 = instantiate_paging(include_optional);

	cJSON* jsonpaging_1 = paging_convertToJSON(paging_1);
	printf("paging :\n%s\n", cJSON_Print(jsonpaging_1));
	paging_t* paging_2 = paging_parseFromJSON(jsonpaging_1);
	cJSON* jsonpaging_2 = paging_convertToJSON(paging_2);
	printf("repeating paging:\n%s\n", cJSON_Print(jsonpaging_2));
}

int main() {
  test_paging(1);
  test_paging(0);

  printf("Hello world \n");
  return 0;
}

#endif // paging_MAIN
#endif // paging_TEST
