/*
 * counterstest.c - test program for CS50 counters module
 *
 * usage: read names from stdin, each on one line
 *
 * This program is a "unit test" for the counters module.
 *
 *
 * Pauline Nyandusi, october 3rd, 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "counters.h"
#include "../lib/file.h"
#include <stdbool.h>


static void itemcount(void *arg, const int key, const int count);
/* **************************************** */

int main()
{

  counters_t *counters1;
  int key = 100;
  void *item = item;
  // assert(counters1 == NULL);

  counters1 = counters_new();
  // assert(counters1 != NULL);

  if (counters1 == NULL)
  {
    fprintf(stderr, "counters_new failed for counters\n");
    return 1;
  }
  else{
    printf("Successfully created counters1\n\n");
  }

  // counters add test
  counters_add(counters1, 1);
  counters_add(counters1, 2);
  counters_add(counters1, 3);
  counters_add(counters1, 4);
  counters_print(counters1, stdout);
  // assert(counters_get(counters_set, key));


  printf("test with nullcounter...\n");
  counters_add(NULL, key);

  printf("test with nullcounter and non existence keys...\n");
  assert(counters_add(NULL, 78890838) == 0);

  printf("test with a negative key...\n");
  assert(counters_add(counters1, -4) == 0);

  printf("\n");
  counters_set(counters1, 4, 2);
  counters_print(counters1, stdout);

  int count = 0;
  printf("\n");
  counters_iterate(counters1, &count, &itemcount);
  printf("count (should be 4) is %d\n\n", count);
  // deletion test

  counters_delete(counters1);
  // Check for memory leaks to make sure this was successful

  printf("Counterstest was Successful\n");
  printf("i love cs");
  return 0;
}

static void itemcount(void *arg, const int key, const int count) {
  int* items = arg;
  if (items != NULL && count > 0 && key > 0) 
     (*items)++;

}

// static itemfunc (void *arg, const int key, const int count) {

//   return 0;
// }
