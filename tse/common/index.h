/* 
 * index.h - header file for CS50 'index' module
 * 
 * An 'index' is a data structure that maintains a mapping from words to document IDs.
 * It is implemented using a hash table and is used to manage a collection of counters,
 * each associated with a unique word (key).
 *
 * This header file declares the API for the 'index' module.
 * 
 * Pauline Nyandusi, 0ctober 23, 2023
 */

#ifndef __INDEX_H
#define __INDEX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../libcs50/file.h"
#include "../libcs50/counters.h"






/**************** global types ****************/
// typedef struct index index_t;  // opaque to users of the module
typedef struct index{
    hashtable_t *table;
    int *num_slots;
} index_t;

/**************** functions ****************/

/**************** index_new ****************/
/* Creates and return a new index data structure
 *
 * Parameters:
 *   num_slots: the number of slots for the internal hash table.
 *
 * We return:
 *   Pointer to a new index_t structure, or NULL if an error occurs (e.g., memory allocation failure).
 *
 * We guarantee:
 *   The index is initialized empty with a hash table having 'num_slots' slots.
 *
 * Caller is responsible for:
 *   Later deallocating the memory allocated for the index using appropriate functions, 
 *   such as a corresponding index_delete function.
 */
index_t *index_new(const int num_slots);

/**************** index_delete ****************/
/* Delete an existing index data structure
 *
 * Parameters:
 *   index: pointer to the index data structure to be deleted.
 *
 * We return:
 *   None. This is a void function.
 *
 * We guarantee:
 *   The index data structure and its associated hashtable will be deleted.
 *   If the index is NULL, the program will exit with an error code.
 *
 * Caller is responsible for:
 *   Ensuring that any use of the index pointer after this function call is invalid, 
 *   as the memory would have been freed.
 */
void index_delete(index_t *index);


/**************** index_add ****************/
/* Add a word and its associated document ID to an index data structure
 *
 * Parameters:
 *   index: pointer to the index data structure.
 *   word: the word to be added to the index.
 *   docID: the document ID associated with the word.
 *
 * We return:
 *   True if the word and document ID were successfully added, or False if there was an error.
 *
 * We guarantee:
 *   If the word does not exist in the index, a new entry will be created.
 *   If the word does exist, the associated counter for the document ID will be incremented.
 *
 * Caller is responsible for:
 *   Ensuring that the index is not NULL and has been properly initialized.
 *   Ensuring that the word is not NULL and the document ID is valid.
 */
bool index_add(index_t *index, char *word, int docID);

/**************** index_save ****************/
/* Save the index data structure to a file
 *
 * Parameters:
 *   index: pointer to the index data structure to be saved.
 *   indexFileName: name of the file where the index will be saved.
 *
 * We return:
 *   None. This is a void function.
 *
 * We guarantee:
 *   The index data will be saved to a file with the name specified by indexFileName.
 *   If the file cannot be opened or other errors occur, the program will exit with an error code.
 *
 * Caller is responsible for:
 *   Ensuring that 'index' is not NULL and that 'indexFileName' is a valid string.
 *   Closing the file if it was successfully opened by this function.
 */
void index_save(index_t *index, const char *indexFileName);


/**************** index_load****************/
/**
 *Loads an index from a file into an index data structure.
 *
 * This function reads an index from a file specified by the `readfp` parameter and stores it in an index data structure.
 * The index consists of words, each associated with a document ID and a count. If the file cannot be read, an error message is displayed, and the program exits.
 *
 * parameters, readfp A string representing the path to the file from which the index will be read.
 * returns, A pointer to the index data structure containing the loaded index.
 */
index_t *indexLoad (const char *readfp);



/**************** bool index_set****************/
/**
 * Sets or updates an entry in the index data structure.
 *
 * This function inserts or updates a word entry in the index data structure, 
 * associating it with a document ID and a count. The function checks for invalid inputs 
 * and returns a boolean value to indicate success or failure.
 *
 * parameters
 * index A pointer to the index data structure where the entry will be set or updated.
 *  word A string representing the word to be set or updated in the index.
 * docID An integer representing the document ID associated with the word.
 *  count An integer representing the count of the word in the document.
 * 
 * returns:
 *  A boolean value indicating whether the operation was successful.
 */
bool index_set(index_t *index, const char *word, const int docID, int count); 

/**************** index_find ****************/
/* Retrieves the counters set associated with a given word from the index data structure
 *
 * Parameters:
 *   index: pointer to an index_t structure, which encapsulates the internal hash table.
 *   word: pointer to a string representing the word to be found in the hash table.
 *
 * We return:
 *   Pointer to a counters_t structure corresponding to the word, or NULL if the word is not found 
 *   or if an error occurs (e.g., index or word is NULL).
 *
 * We guarantee:
 *   The function will search for the word in the internal hash table of the index and return the 
 *   corresponding counters set if it exists.
 *
 * Caller is responsible for:
 *   Ensuring that the pointers to index_t and the word are valid and not NULL.
 *   The caller should not deallocate the returned counters_t set; it is managed by the index.
 */
counters_t* index_find(index_t* index, char* word);



#endif