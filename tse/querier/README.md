# CS50 TSE Querier
## CS50 Fall 2023
## README.md
## Pauline Nyandusi
## October 27 2023

## Introduction

###
I am using a late day for this assignment.



### QUERIER

This README outlines the detailed explanation of the querier module, an essential component of a web crawler. The querier.c program serves as a query engine that interacts with an inverted 
index to evaluate and process search queries. It returns a list of documents that 
match the query, ranked by relevance.



### Assumptions.
No assumptions you made while writing the querier.
My implementation doesnt differ from the Specs.


### Files

* `Makefile` - compilation procedure
* `querier.h` - the interface
* `querier.c` - the implementation
* `gitignore` - for ignoring the not needed files
* `fuzzquery.c` - testing file
* `testing.sh` - bashscript for testing



### Compilation

To compile, simply `make `.

### Testing

To test, simply `make test`.


Try testing with `MEMTEST` by editing Makefile to turn on that flag and then `make test`.

To test with valgrind, `make valgrind`.

