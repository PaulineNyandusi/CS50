
/*

Name: indextest.c
Author: Pauline Nyandusi
Date: October 23, 2023
Description: The TSE indextest is a standalone program that reads an index file 
produced by the TSE indexer, loads it into memory, and writes that index to another file. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libcs50/hashtable.h"
#include "../common/word.h"
#include "../common/index.h"

int main(const int argc, char *argv[]) {

    // Validate the number of command-line arguments

    if (argc != 3) {
        // Print an error message to the standard error stream
        fprintf(stderr, "Error: Incorrect Number of Arguments\n");
        exit(1);
    }

     // Retrieve the file paths from command-line arguments
    char *readfp = argv[1];
    
    char *writtenfp = argv[2];

    // Load the index from the file specified by readfp
    index_t *index = indexLoad(readfp);
    // Save the index to the file specified by writtenfp
    index_save(index, writtenfp);

    index_delete(index);
    // Delete the index to free memory
    return 0;

}

 
 








