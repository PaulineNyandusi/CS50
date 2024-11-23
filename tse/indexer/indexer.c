/*


Name: indexer.c
Author: Pauline Nyandusi
Date :  November 4th, 2023
Description: the TSE indexer is a standalone program that reads the document
files produced by the TSE crawler, builds an index, and writes that
index to a file. Its companion, the index tester, loads an index file produced by
the indexer and saves it to another file.


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libcs50/webpage.h"
#include "../libcs50/bag.h"
#include "../libcs50/hashtable.h"
#include "../common/pagedir.h"
#include "../common/word.h"
#include "../common/index.h"
#include "../libcs50/mem.h"


/**************** Local Functions ****************/
void indexBuild(const char *directory, const char *indexFileName);
void indexPage(webpage_t* webpage, int docID, index_t* index);


/**************** main() ****************/
int main(const int argc, char *argv[]) {
    // Validate the number of command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Error: Usage %s: [pageDirectory] [indexFileName]\n", argv[0]);
        exit(1);
    }

    // Extract and validate the page directory argument
    char *pageDirectory = argv[1];
    if (pageDirectory == NULL) // check if its null
    {
        fprintf(stderr, "Null Argument.\n");
        exit(3); //exit with an ertror code if null
    }

    // check if its a valid directory
    if (!pagedir_validate(pageDirectory))
    {
        fprintf(stderr, "Error: The directory is not found in Crawler\n");
        exit(2); 
    }

    // Extract index filename and validate its writability
    char *indexFilename = argv[2];

    // Open the file for writing
    FILE *fp = fopen(indexFilename, "w");
    // Check for errors during file opening
    if (fp == NULL)
    {
        fprintf(stderr, "Error index file not writable");
        exit(4);
    }

    fclose(fp); //close the file

    // Build the index based on the given directory and filename
    indexBuild(pageDirectory, indexFilename);

    return 0;
}


/**************** indexBuild() ****************/
/********check index.h for description********/
void indexBuild(const char *directory, const char *indexFileName)
{
    // Create a new index object
    index_t *newIndexObject = index_new(700);
    //initializes the doc id
    int docID = 1;
    //allocate memory for the directory, then cocantanate the directory path with id
    char *directoryPathID = mem_malloc(strlen(directory) + 15);
    sprintf(directoryPathID, "%s/%d", directory, docID);

    FILE *fp; //file pointer

    //loops over document ID numbers, counting from 1
    while ((fp = fopen(directoryPathID, "r")) != NULL)
    {
        //load a webpage from pagedir_load
        webpage_t *newPage = pagedir_load(fp);
       
       // Add the webpage to the index
        indexPage(newPage, docID, newIndexObject);
        
        // Cleanup
        webpage_delete(newPage);

        docID++; //increment docid
        // printf("%d\n", docID);
        sprintf(directoryPathID, "%s/%d", directory, docID);
        fclose(fp); //close file pointer
    }
    free(directoryPathID); //free the allocated directory path Id to avoid maloc errors

    // Save the index to a file and clean up
    index_save(newIndexObject, indexFileName);

    //delete index//cleanup
    index_delete(newIndexObject);
}

/**************** indexPage() ****************/
/********check index.h for description********/
void indexPage(webpage_t* webpage, int docID, index_t* index){
    
    int pos = 0; // Initialize the position for webpage_getNextWord
    char* nextWord; // to hold each word obtained from the webpage
    
    // Loop to go through each word in the webpage
    if (webpage == NULL) {
        printf("webapge passed was null\n");
    }
    
    while ((nextWord = webpage_getNextWord(webpage, &pos))!= NULL) {
        // Check the length of the word, skipping words with length less than 3
        if (strlen(nextWord) >= 3) {
            // Normalize the word to lower-case
            normalizeWord(nextWord);
            // Add the normalized word and its document ID to the index
            index_add(index, nextWord, docID);
            // Free the dynamically allocated memory for normalizedWord
            free(nextWord);
        } else {
            free(nextWord); // Free the dynamically allocated memory for nextWord
        }       
    }   
}










