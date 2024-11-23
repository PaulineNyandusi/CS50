# CS50 Lab 3
## CS50 Fall 2023

### hashtable


A `hashtable` is a set of (key,item) pairs. It acts just like a set, but is far more efficient for large collections.

### Usage
Hashtable.c implement a set of void* with char* keys, and export exactly the following functions through hashtable.h 

```c
hashtable_t* hashtable_new(const int num_slots);
bool hashtable_insert(hashtable_t* ht, const char* key, void* item);
void* hashtable_find(hashtable_t* ht, const char* key);
void hashtable_print(hashtable_t* ht, FILE* fp, void (*itemprint)(FILE* fp, const char* key, void* item));
void hashtable_iterate(hashtable_t* ht, void* arg, void (*itemfunc)(void* arg, const char* key, void* item) );
void hashtable_delete(hashtable_t* ht, void (*itemdelete)(void* item) );

```



### Implementation

The hashtable is implemented as an array of setrs., therefore, memory is allocated in the hashtable as an array of set pointers. 


The hashtable_new allocates memory for a new hashtable with num_slots slots. Each slot points to a new set.

The hashtable_insert inserts a new key-value pair into the hashtable. The function utilizes a hash function to determine the appropriate slot for the key.

The hashtable_find searches for a key in the hashtable and returns the corresponding value if found.

The hashtable_print prints the hashtable to a file. This function is useful for debugging.

The hashtable_iterate iterates over each key-value pair in the hashtable and applies a user-defined function.

hashtable_delete frees all memory associated with the hashtable.


### Assumptions

The hashtable assumes that each key you badd is unique, it doesnt check for duplicate keys.

It assumes the the caller will handle memory allocations.

It also assumes that memory allocations functions like malloc and calloc will succeed.



### Files

* `Makefile` - compilation procedure
* `hashtable.h` - the interface
* `hashtable.c` - the implementation
* `hashtabletest.c` - unit test driver
* `testing.out` - result of `make test &> testing.out`

### Compilation

To compile, simply `make hashtable
.o`.

### Testing

The `hashtable
test.c` program reads lines from stdin and stuffs them into a hashtable
, then pulls them back out.


To test, simply `make test`.
See `testing.out` for details of testing and an example test run.

Try testing with `MEMTEST` by editing Makefile to turn on that flag and then `make test`.

To test with valgrind, `make valgrind`.

