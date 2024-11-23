/*

Name: indexer.hj
Author: Pauline Nyandusi
Date: October 22, 2023
Description: 

*/
#ifndef __INDEXER_H
#define __INDEXER_H


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


/**************** indexBuild() ****************/
/* Builds an index from the given page directory
 *
 * Parameters:
 *   directory: The directory containing the webpages
 *   indexFileName: The name of the file where the index will be saved
 *
 * We return:
 *   None. This is a void function.
 *
 * We guarantee:
 *   An index will be built and saved to the specified index file.
 *
 * Caller is responsible for:
 *   Ensuring that 'directory' is valid and 'indexFileName' is writable.
 */

void indexBuild(const char *directory, const char *indexFileName);

/**************** indexPage() ****************/
/* Indexes a single webpage
 *
 * Parameters:
 *   webpage: The webpage to be indexed
 *   docID: The document ID for the webpage
 *   index: The index where the webpage will be indexed
 *
 * We return:
 *   None. This is a void function.
 *
 * We guarantee:
 *   The webpage will be indexed and the index will be updated.
 *
 * Caller is responsible for:
 *   Ensuring that 'webpage' and 'index' are not NULL and are properly initialized.
 */

void indexPage(webpage_t* webpage, int docID, index_t* index);

#endif