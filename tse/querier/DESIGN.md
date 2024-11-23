# CS50 TSE Querier
## CS50 Fall 2023
## Design Spec
## Pauline Nyandusi
## October 27 2023

## Introduction

According to the [Querier Requirements Spec](REQUIREMENTS.md), the TSE *querier* is a standalone program that which reads the index produced by the Indexer and the page files produced by the Crawler, to interactively answer written queries entered by the user.


### User interface

The querier's only interface with the user is on the command-line; it must always have two arguments. One from the crawler output and the other one from the indexer output

```
querier pageDirectory indexFilename
```

For example, if `data` is a pageDirectory in `../crawler`, and `index.out` is the output of the `../indexer`p

``` bash
$ ./querier ../crawler/data ../indexer/index.out
```

### Inputs and outputs

**Input**: inputs in the querier are command line arguments from stdin. Acceptable querries must have only alphabets. Spaces dont really matter. A querry with special characters is unacceptable. 'and' or "or" cannot appear at the beginning of the querry or at the end of the query.


**Output**: We save the index to a file using the format described in the Requirements.

### Functional decomposition into modules

We anticipate the following modules or functions:

 1. *main*, which parses arguments and initializes other modules;
 2. *querryProcessor*, which Processes search queries by evaluating an array of words against 
    an inverted index, utilizing 'AND' and 'OR' logic, and returns a counters structure 
   containing the  result;
 3. *countersMerge*, Merges two counters: one representing a sequence of intersected ('AND') queries and 
     another for unioned ('OR') queries, updating the union counter and deleting the intersect counter;
 4. *FindCountersUnion*, which Performs the union of two counters, updating the first counter based on the 
    union with the second counter;
 5. *countersUnion_helper*, which is a Helper function for `countersUnion`, updates values in the first counter 
    based on their union with values in the second counter, invoked during iteration over counters;
 6. *FindCountersIntersect*, which Performs the intersection of two counters, updating the first counter based 
    on the intersection with the second counter;
 7. *countersIntersect_helper*, which is Helper function for `countersIntersect`, updates values in the 
    first counter based on their intersection with values in the second counter, invoked during 
    iteration over counters;
 8. *splitIntoWords*, which Splits a query string into an array of normalized words and returns the count 
    of words; validates the query structure and returns -1 if invalid;
 9. *isAnd*, which Checks if a given word is 'and', returns true if so, otherwise returns false;
 10. *validateStructure*, which Validates the structural integrity of a query by ensuring proper placement 
     of 'AND' and 'OR' operators; returns true if valid, otherwise false.
 11. *isOr*, which Checks if a given word is 'or', returns true if so, otherwise returns false;
 12. *is_and_or*, which Checks if a given word is either 'AND' or 'OR', returns true if so, otherwise 
    returns false;


 13. *void queryP*, which is the main query processing loop.
 14. *inline int find_smallest*, which is designed to return the smaller of two integers.
 15. *void printerResultsHelper*, which  prints the score and document information associated with a 
     particular document ID     
 16. *void print_result*, which prints and ranks documents based on their scores.
 17. *void getLargestScore*, which updates the highest score and corresponding document ID.
 18. *void itemCount*, which increments a counter that tracks the number of items with a positive score.


And some helper modules that provide data structures:

 1. *index*, a module providing the data structure to represent the in-memory index, and functions to read and write index files;
 1. *webpage*, a module providing the data structure to represent webpages, and to scan a webpage for words;
 2. *pagedir*, a module providing functions to load webpages from files in the pageDirectory;
 4. *word*, a module providing a function to normalize a word.



### Pseudo code for logic/algorithmic flow

The querier will run as follows:

    parse the command line, validate parameters, initialize other modules
    call queryprocessor that precesses user queries

where *queryP function:*

      creates a new 'index' object based on the file provided
      uses splitwords to convert the querry into an array of words and normalizes them
      cgecks if the sequence and structure of word is valid
      Then process the querries and gets the matching documents and words
      prints the matching documents, their scores, document ids and urls
      

where *queryProcessor:*

     initializes two counter onjects that handles the and sequence and the or sequence
     Loop through each word in the array
      Merging existing sequence if the word is or
      skipping to the next word if the word is
    finally merges the andsequence and or sequence and returns the or sequence.
    

### Major data structures

The key data structure is the *counter_t*, that stores the document Ids and their word counts.

Another key data structure is the DocomentScores_t that rstores the document IDs and there scores.

## Error Handling
The program should handle all the errors, such as null pointers, invalid arguments and so on. 

