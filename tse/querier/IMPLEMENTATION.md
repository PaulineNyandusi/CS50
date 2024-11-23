# CS50 TSE Crawler
## CS50 Fall 2023
## Implementation Spec
## Pauline Nyandusi
## October 27 2023

## Introduction

In this document we reference the [Requirements Specification] and [Design Specification] and focus on the implementation-specific decisions.
The knowledge unit noted that an [implementation spec]

Here we focus on the core subset:

-  Data structures
-  Control flow: pseudo code for overall flow, and for each of the functions
-  Detailed function prototypes and their parameters
-  Error handling and recovery
-  Testing plan

## Data structures 


## Control flow

The Crawler is implemented in one file `querier.c`, with four functions.

### main

The `main` function simply calls initializes and parses the arguments.
Checks that only two arguments are provided.
calls `pagedir_validate()` function on `page directory`
makes sure the `indexFileName` is writable
prints error to stderr incase of any errors and exits with a non zero status


### queryP

Pseudocode:


  get input from standard input
  Print "query:" to standard output
  While (queryInput = ReadLine from standard input) is not NULL
    Load the index from a file
    Declare index: IndexType
    Allocate memory for array to hold individual words, array of words
    Split query input into individual words and count them
    Declare wordNumbers
    Validate the query structure
      Process the query and store the result
      If array is not empty
        create a counters object
        Print the search results 
    Free dynamically allocated memory
    Delete the loaded index to free up memory
     

### queryProcessor

Pseudo-code 
    Initialize two empty sets: one for 'AND' intersections  and another for 'OR' unions 
    Initialize a reset flag as False.
    Iterate through each word in the query (arrayOfWords):
    If the word is "or":
      Merge the 'AND' set into the 'OR' set.
      Set the reset flag to False and continue to the next word.

    If the reset flag is True, 
        skip this word and continue.

    If the word is "and", 
        Skip this word and continue.

    For any other word:
        Search for the word in the index and get the matching page set (pageMatch).

    check if matching words and documents are found
        If no matching pages are found:
            Set the `reset` flag to True.
        Clear the 'AND' set.
     
    If matching pages are found:
        If the 'AND' set is empty, initialize it with the found pages.
        Otherwise, intersect the found pages with the existing 'AND' set.
After iterating through all the words, merge any remaining 'AND' set into the 'OR' set.

Return the 'OR' set as the final result.

### splitIntoWords

Pseudo-code 
Initialize a counter (count) to zero, which will keep track of the number of words found.
Determine the length of the input query string (queryInput).
Loop through each character in the input query string:
a. If the character is a whitespace:
- Skip it and move to the next character.
b. If the character is an alphabetical letter:
- Mark the beginning of the word.
- Continue scanning characters until a whitespace or the end of the string is reached.
- Null-terminate the found sequence to isolate the word.
- Normalize this word (convert to lowercase or perform other standardizations).
- Store this normalized word in the array (arrayofWords).
- Increment the word count (count).
c. If the character is not an alphabetical letter and not a whitespace:
- Report an error and exit the function with a return value of -1.
Once the loop finishes, return the total number of words found (count).


### `isAnd`

1. If the input word is null, immediately return False.
2. Compare the input word to the string "and".
   - If they match, return True.
3. If the function hasn't returned by this point, return False.


###  `isOr`

1. If the input word is null, immediately return False.
2. Compare the input word to the string "or".
   - If they match, return True.
3. If the function hasn't returned by this point, return False.


### `is_and_or`

1. Check if the input word is null. 
   - If it is, return False immediately.
2. Use the `isAnd` and `isOr` helper functions to check if the word is either "and" or "or".
   - If either function returns True, return True.
3. If the function hasn't returned by this point, return False.

Certainly, let's describe the algorithm for the `validateStructure` function in natural language.

###  `validateStructure`

1. Loop through each word in the input array (`array`), from the first to the last:
    a. If the first word in the array is either "and" or "or":
        - Display an error message indicating the invalid structure.
        - Return False immediately.
    b. For all other positions except the last:
        - Check if a word and the word immediately following it are both either "and" or "or".
            - If they are, display an error message indicating the invalid structure.
            - Return False immediately.
    c. If the last word in the array is either "and" or "or":
        - Display an error message indicating the invalid structure.
        - Return False immediately.
2. If the loop completes without returning False, then the array has a valid structure. Return True.

### countersMerge

Check if the 'AND' counter set (andIntersectSequence) is not empty.

If it's not empty, proceed to the next steps.
If the 'OR' counter set (orUnionSequence) is empty, initialize it.

Merge the 'AND' counter set into the 'OR' counter set by performing a union operation.

Delete the 'AND' counter set and set it to null.


### Pseudo-code for findcountersUnion

Validate that both counter sets are in valid memory locations.
Loop through the first counter set and update its counts based on a union with the second counter set.


### Pseudo-code for countersUnion_helper
Get the current count of a word in the given counter set.
Update the count for that word by summing its current count and the count from another counter set.


### FindcountersIntersect
Validate that both counter sets are in valid memory locations.
Create a structure that holds both counter sets.
Loop through the first counter set and update its counts based on an intersection with the second counter set.

### countersIntersection_Helper
Get the current count of a word in the first counter set.
Update the count for that word in the first counter set to be the minimum between its current count and the corresponding count in the second counter set.


### print_results
If the counter set is not null, proceed to the next steps.
Initialize a counter for the number of documents.
Count the number of documents with a positive score and print the total number.
Loop through each document to find and print the document with the largest score.
Delete the counter set.

###  itemCount
If the count is greater than 0, increment a counter that tracks the number of items with a positive score.

### getLargestScore
Update the highest score and corresponding document ID based on the current key-value pair in the counter 

### printerResultsHelper
Format the string to form the full path of the file.
Open the file for reading.
Read the first line from the file, which is presumably the URL.
Print the score, document ID, and URL to the standard output.
Close the file and free any dynamically allocated memory.


## Function prototypes

### querier

Detailed descriptions of each function's interface is provided as a paragraph comment prior to each function's implementation in `querier.c` and `querier.h` and is not repeated here.

```c
int main(const int argc, char *argv[]);
counters_t *querryProcessor(index_t *index, char **arrayOfWords, int wordNumbers);
int splitIntoWords(char **arrayOfWords, char *queryInput);
bool validateStructure(char **arrayOfWords, int wordNumbers);
void countersMerge(counters_t **andIntersectSequence, counters_t **orUnionSequence);
void FindCountersUnion(counters_t *one, counters_t *two);
void countersUnion_helper(void *arg, const int key, const int count);
void FindCountersIntersect(counters_t *one, counters_t *two);
void countersIntersect_helper(void *arg, const int key, const int count);
void print_result(counters_t *countersone, char *pageDirectory);
bool is_and_or(char *word);
bool isAnd(char *word);
bool is_and_or(char *word);


static void queryP(char *pageDirectory, const char *indexFilename);
static inline int find_smallest(const int num1, const int num2);
static void printerResultsHelper(const int score, const int documentID, char *pageDirectory);
static void itemcount(void *arg, const int key, const int count);
static void getLargest(void *arg, const int documentID, const int score);
```




## Error handling and recovery

All the command-line parameters are rigorously checked before any data structures are allocated or work begins; problems result in a message printed to stderr and a non-zero exit status.

Out-of-memory errors are handled by variants of the `mem_assert` functions, which result in a message printed to stderr and a non-zero exit status.
We anticipate out-of-memory errors to be rare and thus allow the program to crash (cleanly) in this way.

All code uses defensive-programming tactics to catch and exit (using variants of the `mem_assert` functions), e.g., if a function receives bad parameters.

That said, certain errors are caught and handled internally: for example, `pagedir_init` returns false if there is any trouble creating the `.indexerFileName` file, allowing the querier to decide what to do'

## Testing plan

Here is an implementation-specific testing plan.

### Unit testing

There are only two units (crawler and pagedir).
The crawler represents the whole system and is covered below.
The pagedir unit is tiny; it could be tested using a small C 'driver' to invoke its functions with various arguments, but it is likely sufficient to observe its behavior during the system test.


### Integration/system testing

We write a script `testing.sh` that invokes the querier several times, with a variety of command-line arguments.
First, a sequence of invocations with erroneous arguments, testing each of the possible mistakes that can be made.
Second, a run with valgrind over a moderate-sized test case 
Run that script with `bash -v testing.sh` so the output of crawler is intermixed with the commands used to invoke the crawler.
Verify correct behavior by studying the output, and by sampling the files created in the respective pageDirectories.


