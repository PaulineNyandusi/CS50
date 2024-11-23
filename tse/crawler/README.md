# CS50 Lab 3
## CS50 Fall 2023
## Pauline Nyandusi

### crawler

This document provides an in-depth explanation of the web crawler implemented in C. The code utilizes various custom and standard libraries for crawling web pages starting from a seed URL. It explores each URL to a given depth and stores the fetched web pages in a specified directory.

ishable, so the _extract_ function is free to return any _item_ from the `bag`.

### Usage

The crawler.c implements the following functions:


```c
static void parseArgs(const int argc, char *argv[],
                      char **seedURL, char **pageDirectory, int *maxDepth);
                      
static void crawl(char *seedURL, char *pageDirectory, const int maxDepth);

static void pageScan(webpage_t *page, bag_t *pagesToCrawl, hashtable_t *pagesSeen);

static void logr(const char *word, const int depth, const char *url);

```

### Implementation

Main Function
The main function serves as the entry point for the crawler. It checks the number of arguments, allocates memory for the seed URL, and initializes other variables. It then calls parseArgs to validate and initialize the parameters and crawl to begin the crawling process.

parseArgs()
This function validates the command-line arguments, normalizes the seed URL, and ensures that the page directory is appropriately initialized. Any errors in the arguments lead to the termination of the program.

crawl()
This function initiates the web crawling process. It manages the pages to be crawled using a bag data structure (bag_t) and a hashtable (hashtable_t) to keep track of seen URLs. It then starts from the seed URL and fetches the web pages iteratively while adhering to the specified maxDepth.

pageScan()
This function scans a given webpage for URLs and decides whether to add them to the list of pages to crawl or ignore them based on specific conditions. URLs are normalized before being processed, and only internal URLs are considered for further crawling.

logr()
This function logs messages to the console, indicating the crawling process's current state. It shows the depth, action word, and URL for each step.



### Assumptions

The caller provides all the necessarry arguments. 

My implementation doesnt differ at all from the one in the design specs

### Files

* `Makefile` - compilation procedure
* `crawler.c` - the implementation
* `testing.sh` - The testing bash script
* `data` - test data
* `testing.out` - result of `make test &> testing.out`

### Compilation

To compile, simply `make `.

### Testing

i have a script testing.sh that invokes the crawler several times, with a variety of command-line arguments. 

First, a sequence of invocations with erroneous arguments, testing each of the possible mistakes that can be made. 

Second, a run with valgrind over a moderate-sized test case (such as toscrape at depth 1). Third, runs over all three CS50 websites (letters at depths 0,1,2,10, toscrape at depths 0,1,2,3, wikipedia at depths 0,1,2). 

Run that script with bash -v testing.sh so the output of crawler is intermixed with the commands used to invoke the crawler. 

Verify correct behavior by studying the output, and by sampling the files created in the respective pageDirectories.


To test, simply `make test &> testing.out`

