/* 
 * word.h - header file for CS50 'word' module
 * 
 * The 'word' module provides utility functions for managing words.
 * It includes a function to normalize a word, converting all its characters to lower case.
 * This functionality is particularly useful for text processing tasks such as text search,
 * indexing, and natural language processing.
 * 
 * This header file declares the API for the 'word' module.
 * 
 * Pauline Nyandusi, October 23, 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "word.h"


/**************** normalize word() ****************/
/* see word.h for description */
char *normalizeWord(char *curr) {
    if( curr != NULL){
    // Loop through each character of the input word
    for (int i = 0; curr[i]; i++){
        // Convert each character to its lowercase equivalent
        // The result is stored in the corresponding position of newWord
        curr[i] = tolower(curr[i]);}
        return curr;
    }

    // Return the new normalized word
    return NULL;
    
}
