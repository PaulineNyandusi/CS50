
/*
 * counters.c - CS50 'set' module
 *
 * see counters.h for more information.
 *
 * Pauline Nyandusi, october 3rd, 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include "counters.h"
#include "../lib/mem.h"

/************ local types ***************/
typedef struct counternode
{
  char key;
  int count;
  struct counter *next;
} counternode_t;

/**************** global types *****************/
typedef struct counters
{
  counternode_t *head;
} counters_t;

/***************local functions************/
// new counter structure
static counternode_t *counternode_new(int key)
{
  counternode_t *node = mem_malloc(sizeof(counternode_t *));
  if (node == NULL)
  {
    return NULL; // error in memory alocatiuon
  }

  else
  {
    node->key = key;
    node->next = NULL;
    return node;
  }
}

counters_t *counters_new(void)
{
  counters_t *counters = mem_malloc(sizeof(counters_t));

  if (counters == NULL)
  {
    return NULL;
  }

  else
  {
    counters->head = NULL;
    return counters;
  }
}

/**************** counters_add ****************/

int counters_add(counters_t *ctrs, const int key)
{
  if (ctrs == NULL || key < 0)
  {
    return 0;
  }

  for (counternode_t *current = ctrs->head; current != NULL; current = current-> next){
    if (current->key == key){
      current->count++;
      return current->count;
    }
  }
 
  // If key not found, create a new node for the key and set count to 1
  counternode_t *new_counter = counternode_new(key);
  if (new_counter == NULL)
  {
    new_counter->count = 1;
    return 0;
  }

  // Add new node to the front of the list
  new_counter->next = ctrs->head;
  ctrs->head = new_counter;

  return 1;
}

/**************** counters_get ****************/
/* Return current value of counter associated with the given key.
 *
 * Caller provides:
 *   valid pointer to counterset, and key(must be >= 0)
 * We return:
 *   current value of counter associte with the given key, if present,
 *   0 if ctrs is NULL or if key is not found.
 * Note:
 *   counterset is unchanged as a result of this call.
 */
int counters_get(counters_t *ctrs, const int key)
{

  if (ctrs == NULL || key < 0)
  {
    return 0;
  }

  if (key > 0)
  {
    // Initialize a pointer to traverse the linked list
    counternode_t *current = ctrs->head;

    // Traverse the linked list to find the counter with the given key
    while (current != NULL)
    {
      if (current->key == key)
      {
        return current->count; // Return the value of the counter
      }
      current = current->next; // Move to the next node
    }

    // If execution reaches here, the key was not found in the counterset
    return 0;
  }
}

/**************** counters_set ****************/
/* Set the current value of counter associated with the given key.
 *
 * Caller provides:
 *   valid pointer to counterset,
 *   key(must be >= 0),
 *   counter value(must be >= 0).
 * We return:
 *   false if ctrs is NULL, if key < 0 or count < 0, or if out of memory.
 *   otherwise returns true.
 * We do:
 *   If the key does not yet exist, create a counter for it and initialize to
 *   the given value.
 *   If the key does exist, update its counter value to the given value.
 */
bool counters_set(counters_t *ctrs, const int key, const int count)
{

  if (ctrs == NULL || key < 0 || count < 0)
  {
    return false;
  }

  counternode_t *current = ctrs->head;

  while (current != NULL)
  {
    if (current->key == key)
    {
      current->count = count;
      return true;
    }
    current = current->next;
  }

  counternode_t *new_counter = counternode_new(key);
  if (new_counter == NULL)
  {
    return false;
  }

  new_counter->next = ctrs->head;
  ctrs->head = new_counter;

  return true;
}

/**************** counters_print ****************/
/* Print all counters; provide the output file.
 *
 * Caller provides:
 *   valid pointer to counterset,
 *   FILE open for writing.
 * We print:
 *   Nothing if NULL fp.
 *   "(null)" if NULL ctrs.
 *   otherwise, comma=separated list of key=counter pairs, all in {brackets}.
 */
void counters_print(counters_t *ctrs, FILE *fp)
{

  if (fp != NULL)
  {
    if (ctrs != NULL)
    {
      fputc('{', fp);

      counternode_t *current = ctrs->head;

      while (current != NULL)
      {
        fprintf(fp, "%d=%d", current->key, current->count);
        current = current->next;
        if (current != NULL)
        {
          fprintf(fp, ",\n ");
        }
      }
      fprintf(fp, "}");
    }
  }
}

/**************** counters_iterate ****************/
/* Iterate over all counters in the set.
 *
 * Caller provides:
 *   valid pointer to counterset,
 *   arbitrary void*arg,
 *   valid pointer to itemfunc that can handle one item.
 * We do:
 *   nothing, if ctrs==NULL or itemfunc==NULL.
 *   otherwise, call itemfunc once for each item, with (arg, key, count).
 * Note:
 *   the order in which items are handled is undefined.
 *   the counterset is unchanged by this operation.
 */
void counters_iterate(counters_t *ctrs, void *arg, void (*itemfunc)(void *arg, const int key, const int count))
{

  if (ctrs == NULL || itemfunc == NULL)
  {
    return;
  }


  // call itemfunc with arg, on each item
  counternode_t *current = ctrs->head;
  while (current != NULL)
  {
    (*itemfunc)(arg, current->key, current->count);
      current = current->next;
    }
  }


/**************** counters_delete ****************/
/* Delete the whole counterset.
 *
 * Caller provides:
 *   a valid pointer to counterset.
 * We do:
 *   we ignore NULL ctrs.
 *   we free all memory we allocate for this counterset.
 */
void counters_delete(counters_t *ctrs)
{

  if (ctrs != NULL)
  {
    counternode_t *current = ctrs->head;
    counternode_t *next;

    while (current != NULL)
    {
      next = current->next;
      mem_free(current);
      current = next;
    }

    mem_free(ctrs);
  }

}

