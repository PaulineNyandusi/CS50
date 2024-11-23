# CS50 Lab 3
## CS50 Fall 2023

### set

A set maintains an unordered collection of (key,item) pairs; any given key can only occur in the set once. 
It starts out empty and grows as the caller inserts new (key,item) pairs. 
The caller can retrieve items by asking for their key, but cannot remove or update pairs. Items are distinguished by their key.


### Usage

The *set* module, defined in `set.h` and implemented in `set.c`, implements a set of `void*`,items with char* keys, and export exactly the following functions through set.h:

```c
set_t* set_new(void);
bool set_insert(set_t *set, const char *key, void *item);
void *set_find(set_t * set, const char *key);
void set_print(set_t * set, FILE * fp, void (*itemprint)(FILE *fp, const char *key, void *item));
void set_iterate(set_t * set, void *arg, void (*itemfunc)(void *arg, const char *key, void *item));
void set_delete(set_t * set, void (*itemdelete)(void *item));
```

### Implementation

The set is implemented as a linked list of nodes, each containing a key and an associated item. The set itself maintains a pointer to the head of the list, and each node maintains a pointer to the next node in the list.

The main data structure is 'struct set' that contains a pointer to the head of the linked list, which points to NULL when the set is empty.

Each node in the list is a `struct setnode`, a type defined internally to the module.
Each setnode includes a pointer to the `void* item` and a pointer to the next 'setnode' on the list.


To insert a new item in the set we create a new setnode to hold the `item`, and insert it at the head of the list. set_new allocates and initializes a new, empty set. If the key already exists, the function returns false.

To find an item, we use set_find which Searches for an item by its key and returns a pointer to the item if found. It does this by iterating through the linked list, comparing item till we match. 

The set-iterate function allows you to Iterates over all items in the set and alllows you to call a specified function (itemfunc) on each item.

The set_print function Prints all the contents of the set to the given file pointer, using a supplied function (itemprint) to print each item.

The set_delete deletes the set and all its items, using a supplied function (itemdelete) to delete each item.We free the memory used by the linked list nodes by traversing iteratively calling item delete function on eacyh item. Finally, we free the memory used by the struct set.


### Assumptions

The Caller provides valid set pointer, valid string pointer, and pointer to item in the set insert.

The set does nopt guarantee any specific order for the items because the items are maintened in the order that they were initially inserted.

We assume that the set_delete function frees the memory allocated.


### Files

* `Makefile` - compilation procedure
* `set.h` - the interface
* `set.c` - the implementation
* `settest.c` - unit test driver
* `testing.out` - result of `make test &> testing.out`

### Compilation

To compile, simply `make`.

### Testing

The `settest.c` program reads lines from stdin and stuffs them into a set, then pulls them back out.
It tests a few error and edge cases.

To test, simply `make test`.
See `testing.out` for details of testing and an example test run.

Try testing with `MEMTEST` by editing Makefile to turn on that flag and then `make test`.

To test with valgrind, `make valgrind`.

