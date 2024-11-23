/* 
 * pagedir_c
 * pahedir.c is a  module that handles the pagesaver mentioned 
 * in the design (writing a page to the pageDirectory), and marking it as a 
 * Crawler-produced pageDirectory (as required in the spec). 
 *
 * Pauline Nyandusi, October 16, 2023
 */


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <webpage.h>
#include "pagedir.h"
#include "../libcs50/file.h"


/*******see pagedir.h for more descriptions********/
// Function to initialize the page directory
bool pagedir_init(const char* pageDirectory) {
    // Construct the pathname for the .crawler file in that directory
    char *crawlerPathname = malloc(strlen(pageDirectory) + strlen("/.crawler") + 1);
    strcpy(crawlerPathname, pageDirectory);
    //strcat(crawlerPathname, "/.crawler");
    sprintf(crawlerPathname, "%s/.crawler", pageDirectory);
    printf("\n%s\n", crawlerPathname);

    // Open the file for writing
    FILE *crawlerFile = fopen(crawlerPathname, "w");
    
    // Check for errors during file opening
    if (crawlerFile == NULL) {
        fprintf(stderr, "Error opening .crawler file");
        free(crawlerPathname);
        return false;
    }

    // Close the file
    fclose(crawlerFile);
    free(crawlerPathname);
    
    // Return true to indicate successful initialization
    return true;
}

/*****pagedir_save***************************************/
/*****see pagedir.h for more description************************/
void pagedir_save(const webpage_t* page, const char* pageDirectory, const int docID) {
    char cdocID[20];
    sprintf(cdocID, "%d", docID);

    //add a slash to the begining
    char strSlash[20] = "/";
    strcat(strSlash, cdocID);

    char *pagePathname = malloc(strlen(pageDirectory) + strlen(strSlash) + 100);
    strcpy(pagePathname, pageDirectory);
    fprintf(stdout, "pagePathname: %s\n", pagePathname);
    strcat(pagePathname, strSlash);

    // Open the file for writing
    FILE *page_file = fopen(pagePathname, "w");
    fprintf(stdout, "pagePathname: %s\n", pagePathname);

   if (page_file != NULL){
        fprintf(page_file, "%s\n", webpage_getURL(page));
        fprintf(page_file, "%d\n", webpage_getDepth(page));
        fprintf(page_file, "%s\n", webpage_getHTML(page));
    }
    // Check for errors during file opening
    if (page_file == NULL) {
        fprintf(stderr, "Error opening page file");
       exit(1);
    }
    fclose(page_file);

    free(pagePathname);

}

bool pagedir_validate( char* directory){

    if (directory == NULL) {
        fprintf(stderr, "Error: NULL directory");
    }

    // create string withspace for directory and /.crawler

    char path_name[strlen(directory)+20]; 
    sprintf(path_name, "%s/%s", directory, "/.crawler"); 

    // Check null-pointer argument.
    if (path_name == NULL) {
    return false;
    }

    //  open file for reading
    FILE *fp = fopen(path_name, "r"); 

    if (fp != NULL) {
        // close if file open was successful
        fclose(fp); 
        return true;
    }
    else {
        fprintf(stderr, " Cannot verify if the directory is in Crawler\n");
        return false;
    }
}


webpage_t* pagedir_load(FILE *fp){
    char *url = file_readLine(fp);
    char* depth = file_readLine(fp);
    char *html = file_readFile(fp);
    int depthInt = atoi(depth);

    webpage_t *newWebpage = webpage_new(url, depthInt, html);
    

    if (newWebpage == NULL){
        fprintf(stderr, "Errorr, webopage not successfull\n");
    }
   
    free(depth);
    
    return newWebpage;
}

    