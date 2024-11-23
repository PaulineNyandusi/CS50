# Pauline Nyandusi
## CS50 Fall 2023, Lab 2

GitHub username: PaulineNyandusi

#Introduction to Lab 2

This repository contains the solutions for the CS50 Lab 2 assignment which has three distinct programs. 
chill.c: Calculates the wind chill based on the current temperature and wind speed.
words.c: Breaks down its input into a series of words, printing one per line.
histo.c: Reads a series of positive integers from stdin and prints out a histogram.
Each program is found within its respective directorate

#Chill.C
Chill.c, calculates the "wind chill" based on the current temperature and wind speed. 

##Features.

The program can be run without any command-line arguments, and it will print a table of wind chill values for a range of temperatures and wind speeds.

When someone provides a specific temperature as a command-line argument, the program will print wind chill values for a range of wind speeds at that temperature.

When someone provides both temperature and wind speed arguments, and it prints the corresponding wind chill value.

I have a helper function: Number Checker.

The numberChecker ensures that the provided command-line arguments are valid numbers. 

I have another Helper Function: The windChillCalculation function that calculates the wind chill based on the provided temperature and wind speed, implementing the standard formula for wind chill calculation.

Uses of the WindChillCalculation.

    1.No Arguments:
    When run without arguments, the program prints a table of wind chill values for temperatures from -10 to 40 (in increments of 10)     
    wind speeds from 5 to 15 (in increments of 5).

    2.One Argument (Temperature):
    Provide a specific temperature to get wind chill values at that temperature for wind speeds from 5 to 15.

    Example:
    ./chill 20

    2.Two Arguments (Temperature and Wind Speed):
    Provide both temperature and wind speed to get the specific wind chill value for those conditions.

    Example:
    ./chill 20 10

Error Handling:
The program checks if the provided temperature and wind speed values are within acceptable ranges (temperature between -99 and 50, wind speed between 0.5 and 231).
If the inputs are out of range or in an incorrect format, the program provides an appropriate error message.

I later compile the function and execute it.


#words.c

##Introduction

words.c is a C file that processeses a series of characters and separate them into distinct words. Each word is printed on a new line. The program can process input from the standard input stream (stdin) or from specified file(s).

Features:

I have a helper function, fileInputProcessor that STORES EACH CHARACTER FROM EACH FILE, and a boolean that checks if the last read character was an alphabetic character, it is initialized to 0, false. 

It then enters a while loop where it reads each character from the file using the fgetc function until it reaches the end of the file (EOF).

If the read character is an alphabetic character (checked using the isalpha function), two actions are taken:
The character is printed to the standard output using the putchar function.
The lastCharWasAlpha flag is set to 1 (true), indicating that an alphabetic character has been found.


If the read character is not an alphabetic character but the previous character was (checked by lastCharWasAlpha), the function prints a newline character. This effectively separates words, as every sequence of alphabetic characters followed by a non-alphabetic character is considered a word.

The lastCharWasAlpha flag is then reset to 0 (false) to be ready for the next sequence of alphabetic characters.


This process continues until all characters in the file have been read and processed. Each word, defined as a sequence of alphabetic characters, is printed on a new line.


#histo.c

##introduction

histo.c is a C file that reads a series of positive integers from the standard input and print out a histogram with 16 bins. The uniqueness of this program lies in its ability to dynamically scale the bin size of the histogram based on the range of input values. It ensures that all positive integers observed on the input fit within the histogram.

Features:
The program initializes the bin size to 1 and the upper bound of the histogram to 16.

It reads integers from the standard input. If an integer is greater than the current upper bound, the program doubles the bin size and the upper bound, and then compresses the existing histogram to fit within the new bounds.

The program continues reading and categorizing integers until it reaches the end of the file (EOF).

Finally, it prints out the histogram. Each bin is represented by asterisks (*), with each asterisk representing one integer in that bin.


