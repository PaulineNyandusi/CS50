/*
 * set.c - CS50 'set' module
 *
 * see set.h for more information.
 *
 * Pauline Nyandusi, october 3rd, 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "set.h"
#include "mem.h"

//**************** local types ****************/
typedef struct setnode
{
  void *item;
  char *key;            // pointer to data for this item
  struct setnode *next; // link to next node
} setnode_t;

/**************** global types ****************/
typedef struct set
{
  setnode_t *head; // head of the list of items in set
} set_t;

/***************local functions************/
static setnode_t *setnode_new(char *key, void *item)
{
  setnode_t *node = mem_malloc(sizeof(setnode_t));
  if (node == NULL)
  {
    return NULL; // error in memory alocatiuon
  }

  else
  {
    node->key = key;
    node->item = item;
    node->next = NULL;
    return node;
  }
}

/**************** functions ****************/

/********** set_new() **********/
/* see set.h for description, thank you */

set_t *set_new(void)
{
  set_t *set = mem_malloc(sizeof(set_t));

  if (set == NULL)
  {
    return NULL; // error allocating set
  }

  else
  {
    // initialize the contents of set structure
    set->head = NULL;
    return set;
  }
}

/**************** set_insert ****************/
/* see set.h for description */

/**************** set_insert ****************/
bool set_insert(set_t *set, const char *key, void *item)
{

  if (set == NULL || key == NULL || item == NULL)
  {
    return false;
  }

  else
  {
    // copy the key
    char *keyCopy = malloc(strlen(key) + 1);
    strcpy(keyCopy, key);

    setnode_t *newNode = setnode_new(keyCopy, item);

    if (set_find(set, keyCopy) != NULL)
    {
      return false; // Key already exists in the set
    }

    else
    {
      // Insert the new node at the head of the list
      newNode->next = set->head;
      set->head = newNode;
      return true;
    }
  }
}

  /**************** set_find ****************/
  /* see set.h for description */
 
void *set_find(set_t * set, const char *key)
  {
    if (set == NULL || key == NULL)
    {
      return NULL;
    }
    else
    {
      // iterate the linked list to find the key
      for (setnode_t *current = set->head; current != NULL; current = current->next)
      {
        if (strcmp(current->key, key) == 0)
        {
          return current->item; // Return the associated item
        }
      }
    }
    return NULL;
  }

  /**************** set_print() ****************/
  /* see set.h for description */

  void
  set_print(set_t * set, FILE * fp, void (*itemprint)(FILE *fp, const char *key, void *item))
  {

    // Check if the file pointer is valid
    if (fp == NULL)
    {
      return;
    }

    // Check if the set is null
    if (set == NULL)
    {
      fputs("(null)", fp);
      return;
    }

    // Begin set output
    fputc('{', fp);

    // Iterate through the set
    for (setnode_t *current = set->head; current != NULL; current = current->next)
    {
      // Check if an itemprint function is provided
      if (itemprint != NULL)
      {
        // Use the itemprint function to print the current node's item
        (*itemprint)(fp, current->key, current->item);

        // If this is not the last node, print a comma to separate items
        if (current->next != NULL)
        {
          fputc(',', fp);
        }
      }
    }

    // Close set output
    fputc('}', fp);
  }

  /**************** set_iterate ****************/
 
  void
  set_iterate(set_t * set, void *arg, void (*itemfunc)(void *arg, const char *key, void *item))
  {

    if (set != NULL && itemfunc != NULL)
    {
      // call itemfunc with arg, on each item
      for (setnode_t *current = set->head; current != NULL; current = current->next)
      {
        (*itemfunc)(arg, current->key, current->item);
      }
    }
  }

  /**************** set_delete ****************/

  void
  set_delete(set_t * set, void (*itemdelete)(void *item))
  {
    if (set != NULL)
    {

      for (setnode_t *current = set->head; current != NULL;)
      {
        if (itemdelete != NULL)
        {                               // if possible...
          (*itemdelete)(current->item); // delete node's item
        }

        setnode_t *next = current->next; // remember what comes next
        mem_free(current);               // free the node
        current = next;                  // and move on to next
      }

      mem_free(set);
    }

#ifdef MEMTEST
    mem_report(stdout, "End of set_delete");
#endif
  }
