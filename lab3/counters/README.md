# CS50 Lab 3
## CS50 Fall 2023

### counters


A counters
 maintains an unordered collection of (key,item) pairs; any given key can only occur in the counters
 once. 


### Usage

A counter set is a set of counters, each distinguished by an integer key. It's a set - each key can only occur once in the set - and it tracks a counter for each key. It starts empty. Each time counters_add is called on a given key, the corresponding counter is incremented. The current counter value can be retrieved by asking for the relevant key.

Your counters.c should implement a set of integer counters with int keys (where keys must be non-negative) and export exactly the following functions through counters.h 

```c
counters_t* counters_new(void);
int counters_add(counters_t* ctrs, const int key);
int counters_get(counters_t* ctrs, const int key);
bool counters_set(counters_t* ctrs, const int key, const int count);
void counters_print(counters_t* ctrs, FILE* fp);
void counters_iterate(counters_t* ctrs, void* arg, void (*itemfunc)(void* arg, const int key, const int count));
void counters_delete(counters_t* ctrs);

```


### Implementation

The counters are implemented as a linked list of nodes, with each node containing an integer key and an associated counter value. The head of this list is maintained by the counters structure.


counters_new allocates and initializes a new, empty counters set.
counters_add increments the counter associated with a specific key, or initializes it if the key is new.
counters_get retrieves the current value of the counter associated with a specific key.
counters_set explicitly sets the value of the counter associated with a specific key.
counters_print prints the current state of all counters to a specified file.
counters_iterate applies a function to each counter in the set.
counters_delete deletes the counters set and frees all associated memory.


### Assumptions
 The code assumes that mem_malloc will successfully allocate memory. If allocation fails, the function will return NULL.

The code assumes that keys will be non-negative integers and that the counters_t* pointers provided to functions are valid.


The code assumes that the function pointers for counters_iterate are either valid or NULL.

The code assumes that the caller will check for NULL pointers returned by functions like counters_new and will handle them appropriately.

The code assumes that each key can only exist once in a counters set. If a key is repeated, its counter is simply incremented.



### Files

* `Makefile` - compilation procedure
* `counters
.h` - the interface
* `counters
.c` - the implementation
* `counters
test.c` - unit test driver
* `testing.out` - result of `make test &> testing.out`

### Compilation

To compile, simply `make`.

### Testing

The `counters
test.c` program reads lines from stdin and stuffs them into a counters
, then pulls them back out.
It tests a few error and edge cases.

To test, simply `make test`.
See `testing.out` for details of testing and an example test run.

Try testing with `MEMTEST` by editing Makefile to turn on that flag and then `make test`.

To test with valgrind, `make valgrind`.

