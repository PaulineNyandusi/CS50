# CS50 Lab 3
## CS50 Fall 2023
## Pauline Nyandusi

## I'm using one of my late days

### COMMON 

This README outlines the detailed explanation of the pagedir module, an essential component of a web crawler. The pagedir module manages the page directory operations, including the initialization of the page directory and the saving of web pages. It is designed to be a reusable component, anticipating future use by other modules like the Indexer and Querier.

### Usage

The *pagedir* module, defined in `pagedir.h` and implemented in `pagedir.c`, implements  and exports the following functions:

```c
bool pagedir_init(const char* pageDirectory);
void pagedir_save(const webpage_t* page, const char* pageDirectory, const int docID);
```

### Implementation

pagedir_init()
This function initializes the page directory by creating a .crawler file within it.

A pathname for the .crawler file is dynamically constructed using malloc.
The function then attempts to open this file for writing. If it fails, it returns false; otherwise, it returns true.
pagedir_save()
This function saves a webpage to a file in the page directory.

A unique document ID (docID) is used to create unique filenames.
The function constructs the pathname for this file dynamically and attempts to open it for writing.
If the file opening is successful, the function proceeds to write the webpage's content into the file. Otherwise, it exits with an error message.


Error Handling
The module provides robust error handling:

It checks for NULL file pointers after attempting to open files.
It frees dynamically allocated memory to prevent memory leaks.


### Assumptions

The page directory provided exists and is writable.
Memory allocation for dynamically created strings is successful.
The webpage_t structure passed to pagedir_save is correctly initialized and populated.


### Files

* `Makefile` - compilation procedure
* `pagedir.h` - the interface
* `pagedir.c` - the implementation


### Compilation

To compile, simply `make `.

### Testing

To test, simply `make test`.


Try testing with `MEMTEST` by editing Makefile to turn on that flag and then `make test`.

To test with valgrind, `make valgrind`.
