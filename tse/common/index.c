/* 
 * index.c - CS50 'index' module
 *
 * This module provides functionality for creating and manipulating an index,
 * which is a data structure built on top of a hash table. The index is used to
 * manage a collection of counters, each associated with a word (key).
 *
 * See index.h for more information.
 *
 * Pauline Nyandusi, October 23, 2023
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../libcs50/hashtable.h"
#include "../libcs50/mem.h"
#include "../libcs50/counters.h"
#include "index.h" 
#include "../libcs50/file.h"


/**************** Local Functions ****************/
/* Deletes the counters */

static void index_setter_delete(void* counter){
    // Check if the counter pointer is NULL
    if (counter != NULL) {
        // Delete the counter using the counters_delete function from libcs50
        counters_delete(counter);
    }
}

/**************** helper function ****************/
static void helperFunction(void* fp, const int key, const int number) {
    // Check if the file pointer is NULL
    if (fp == NULL) {
        // Print an error message to the standard error stream
        fprintf(stderr, "Error: Null items");
        // Exit the program with a status code of 1 to indicate an error
        exit(1);
    }
    
   fprintf(fp, " %d %d", key, number); 
}

/* Helper function for iterating through the index and printing the keys */
static void index_iterate_Printer(void* fp, const char *key, void *item) {
    // Check for NULL parameters to avoid undefined behavior
    if (fp == NULL || key == NULL || item == NULL) {
        fprintf(stderr, "Error: Null items");
        exit(1);
    }
    // Write the key to the file
    fprintf(fp, "%s", key);

    counters_t* counters1 = item;
    
    // Iterate through the counter associated with the key and print each count to the file
    counters_iterate(counters1, fp, helperFunction);

    // Write a newline character to the file for readability
    fprintf(fp, "\n");
}

/**************** index_new() ****************/
/* see index.h for description */
index_t *index_new(const int num_slots) {
    // Allocate memory for a new index structure
    index_t *index = mem_malloc(sizeof(index_t));

    // Check for memory allocation failure
    if (index == NULL) {
        return NULL; // Memory allocation failed
    }

    // Create and initialize a new hash table within the index structure
    index->table = hashtable_new(num_slots);

    // Check for hash table creation failure
    if (index->table == NULL) {
        free(index); // Free the previously allocated index structure
        return NULL; // Hashtable creation failed; return NULL
    }
    // Successfully created index with an empty hash table; return the index pointer
    return index;
}


/**************** index_add() ****************/
/* see index.h for description */
bool index_add(index_t *index, char *word, int docID) {
    // Initialize a pointer for a new counter
    counters_t *newCounter;

    // Check for invalid inputs and return false if any are found
    if (index == NULL || word == NULL || docID < 1) {
        fprintf(stderr, "Invalid input: index, word, or document_id\n");
        return false;
    }

    // Search for the word in the index's hash table
    if (hashtable_find(index->table, word)== NULL) {
        // Word doesn't exist, create a new counter
        newCounter = counters_new();
        // Check if the counter creation failed

        if (newCounter == NULL) {
            fprintf(stderr, "Failed to create a new counter\n");
            exit(5);
        }

        // Add the new counter to the hash table with the word as the key
        hashtable_insert(index->table, word, newCounter);

        // Add the document ID to the new counter and increment it
        counters_add(newCounter, docID);

        return true; // Successfully added the word and document ID
    }

    else {
        // Word already exists in the index; find
        newCounter = hashtable_find(index->table, word);

        // Increment the count associated with the document ID
        counters_add(newCounter, docID);

        return true; // Successfully incremented, return true
     }

    // An unexpected path; return false as a fail-safe
    return false;
}

void index_save(index_t *index, const char *indexFileName){
    // Open the file for writing
    FILE *fp = fopen(indexFileName, "w");

    // Check if the file was successfully opened
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open the file\n");
        exit(7);
    }

    // Iterate through the hashtable and save its contents using the helper function
    hashtable_iterate(index->table, fp, index_iterate_Printer);

    // Close the opened file
    fclose(fp);
}

 void index_delete(index_t *index) {
    // Check if the index is NULL
    if (index == NULL) {
        fprintf(stderr, "Error, Index is Null in index_delete\n");
        exit(1);
    }
    // Delete the hashtable, assuming that there's no need to free the data
    hashtable_delete(index->table, index_setter_delete); 

    // Free the memory allocated for the index
    mem_free(index);  

}


bool index_set(index_t *index, const char *word, const int docID, int count) {

    if (index == NULL || word == NULL || docID < 1 || count < 1) {
        return false;
    }

    counters_t *counter= hashtable_find(index->table, word);

    if (counter != NULL) {

        counters_set(counter, docID, count);
    }

    else {
        counters_t *newCounter = counters_new();
        counters_set(newCounter, docID, count);
        hashtable_insert(index->table, word, newCounter);
    }
    return true;
}

index_t *indexLoad (const char *readfp){
    // Open the file for reading
    FILE *fp =  fopen(readfp, "r");
     // Check if the file was opened successfully
    if (fp == NULL) {
        fprintf(stderr, "Error, Counld not read the input file\n");
        exit(2);
    }

    //initialize variable for index set
    char *word;
    int IDdoc = 0;
    int count = 0;


    // Create a new index data structure
    index_t *index = index_new(900);

     // Read words from the file until the end of file is reached
    while ((word = file_readWord(fp)) != NULL) {
        // For each word, read the associated document ID and count
        while (fscanf(fp, "%d %d", &IDdoc, &count) > 0) {
            index_set(index, word, IDdoc, count);
        }
        free(word);
    }

    fclose(fp); // Close the file
    
    return index;  // Return the populated index data structure

}

counters_t* index_find(index_t* index, char* word){

    counters_t *item = hashtable_find(index->table, word);
    
    return item;

}















    




