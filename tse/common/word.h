/* 
 * word.h - header file for CS50 'word' module
 * 
 * The 'word' module provides utility functions for managing words.
 * Specifically, it includes the function 'normalizeWord', which takes 
 * a word as input and returns a dynamically allocated copy of that 
 * word where all characters are converted to lowercase. 
 * 
 * Pauline Nyandusi, October 22, 2023
 */

#ifndef __WORD_H
#define __WORD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**************** normalizeWord ****************/
/* Normalizes a given word by converting all its characters to lowercase
 *
 * Parameters:
 *   word: the input word as a constant character pointer.
 *
 * We return:
 *   A dynamically allocated new string containing the normalized word, or NULL if an error occurs (e.g., memory allocation failure).
 *
 * We guarantee:
 *   The returned string will be a normalized version of the input word, with all characters converted to lowercase.
 *
 * Caller is responsible for:
 *   Deallocating the memory allocated for the new normalized word using the 'free' function.
 */
char *normalizeWord(char *word);

#endif
