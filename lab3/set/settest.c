/* 
 * settest.c - test program for CS50 set module
 *
 * usage: read names from stdin, each on one line
 *
 * This program is a "unit test" for the set module.
 * 
 *
 * Pauline Nyandusi, october 3rd, 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "set.h"
#include "file.h"


static void itemdelete(void *item);
static void itemprint(FILE *fp, const char *key, void* item);
static void itemfunc(void *arg, const char *key, void *item);
/* **************************************** */

int main() {

  set_t* set1 = NULL;          
  void *item = item;
 
  set1 = set_new();
  // assert(set1 != NULL); 

  if (set1 == NULL){
  fprintf(stderr, "set_new failed for set\n");
  return 1;
  }

  //Insert tests
  printf("\nTest with null set, good item...\n");
  set_insert(NULL, "Dartmouth", "College");

  printf("test with null chartacter...\n");
  set_insert(set1, NULL, "College"); 

  printf("test with null item...\n");
  set_insert(set1, "Dartmouth", NULL);

  printf("test with null everything...\n");
  set_insert(NULL, NULL, NULL);

  printf("test with everything...\n");
  set_insert(set1, "Dartmouth", "College");
  set_insert(set1, "Dartmouth2", "College");

  //set_find tests
  printf("test with everything...\n");
  set_find(set1, "College");

  printf("test with null set...\n");
  set_find(NULL,"College");

  printf("test with null item...\n");
  set_find(set1,NULL);

  //SET_PRINT TEST
  printf("test with null item...\n");
  set_print(set1, stdout, itemprint);

  printf("test with null set...\n");
  set_print(NULL, stdout, itemprint);

  printf("test with null FP...\n");
  set_print(set1, NULL, itemprint);

  //set_iterate test
  int pauline = 10;
  printf("test with everything...\n");
  set_iterate(set1, &pauline, itemfunc);

  printf("test with null set...\n");
  set_iterate(NULL, &pauline, itemfunc);

  printf("test with null argument...\n");
  set_iterate(set1, NULL, itemfunc);

  printf("test with null item func...\n");
  set_iterate(set1, &pauline, NULL);

  //Delete
  printf("set_delete tests\n");
  set_delete(set1, itemdelete); // Should delete the set

  // printf("set_delete tests\n");
  // set_delete(set1, NULL); 
  printf("\nset tests successful\n");
  return 0;
}

static void itemdelete(void *item) {
  if (item != NULL) {
    // free(item);   
  } 
}
static void itemprint(FILE *fp, const char *key, void* item) {
  int *itemp = item;
  fprintf(fp, "%s:%d", key, *itemp);
}

static void itemfunc(void *arg, const char *key, void *item) {
  int* items = arg;
  if (items != NULL && item != NULL && key != NULL) 
     (*items)++;

}





  