/*

File name: words.c
Name : Pauline Nyandusi
Date : Tuesday sept 26
Summary: A cfile that that breaks its input into a series of words, one per line. It may take input from stdin, or from files whose names are listed as arguments.

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool lastCharWasAlpha;

void fileInputProcessor(FILE *fp); //Function Declaration


int main(int argc, char *argv[]) {
  // If there are no file arguments, process the standard input
  if (argc == 1){
    fileInputProcessor(stdin);
  }

  else{
    // Loop through all provided file names as arguments
    for (int i = 1; i < argc; i++) {
      FILE *fp = fopen(argv[i], "r"); // Open the file in read mode


      // Print an error message and exit the program if the file cannot be opened
      if (fp == NULL){
        fprintf(stderr, "Error! Could not open file\n");
        exit(1);
      }

     if (*argv[i] == '-') {
      fileInputProcessor(stdin);
     }

      // Process the file to print words
      fileInputProcessor(fp);

      fclose(fp);  // Close the file after processing]
    }
  }
}

// Function to process file input and print one word per line
void fileInputProcessor(FILE *fp) {

  int c;
  int lastCharWasAlpha = 0; //Checks if the last character was alphabetic

  // Reading the file character by character until EOF
   while ((c = fgetc(fp)) != EOF) {
    if (isalpha(c)) {
        // Print the character if it is alphabetic
        putchar(c);
        lastCharWasAlpha = 1; // Set lastCharAlpha as true when an alphabetic character is found
    } 

    else if (lastCharWasAlpha) {
      // If the current character is not alphabetic but the last one was,
      // we print a newline to separate the words.
      putchar('\n');
      lastCharWasAlpha = 0; // Reset lastCharAlpha to false
    }
  }
}
