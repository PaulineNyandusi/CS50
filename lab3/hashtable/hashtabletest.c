#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "../lib/file.h"
#include "../lib/mem.h"
#include "hash.h"


static void itemcount(void *arg, const char *key, void *item);

static void itemprint(FILE* fp, const char* key, void* item);

static void itemdelete(void* item);
/* **************************************** */

int main()
{

  hashtable_t *hashtable1;
  
  hashtable1 = hashtable_new(20);
  // assert(hashtable1 != NULL);

  if (hashtable1 == NULL)
  {
    fprintf(stderr, "hashtable_new failed for hashtable\n");
    return 1;
  }
  else{
    printf("Successfully created hashtable1\n\n");
  }


  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;

  // hashtable insert test
  hashtable_insert(hashtable1, "Pete", &a);
  hashtable_insert(hashtable1, "Sett", &b);
  hashtable_insert(hashtable1, "Abdul", &c);
  hashtable_insert(hashtable1, "Emmanuel", &d);
  hashtable_print(hashtable1, stdout, itemprint);


  //hashtable find insert
  hashtable_find(hashtable1, "Something not there");
  hashtable_find(hashtable1, "i love cs");



  printf("\n");
  hashtable_print(hashtable1, stdout, itemprint);

  int count = 0;
  printf("\n");
  hashtable_iterate(hashtable1, &count, &itemcount);
  printf("count (should be 4) is %d\n\n", count);
  // deletion test

  hashtable_delete(hashtable1, itemdelete);
  // Check for memory leaks to make sure this was successful

}


static void itemprint(FILE *fp, const char *key, void* item) {
  int *itemp = item;
  fprintf(fp, "%s:%d", key, *itemp);
}

static void itemcount(void *arg, const char *key, void *item) {
  int* items = arg;
  (*items)++;
}

static void itemdelete(void* item) {
  if (item != NULL) {
    // free(item);   
  } 
}





  