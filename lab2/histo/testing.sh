#!/bin/bash
#Script name: testing.sh
#Name : Pauline Nyandusi
#Date : 26th sept 2023
#Summary: A bash script that tests histo.c





 #"Test 1: Basic test with numbers in range [0, 16)"
echo "3 -4 5 1 7 0 8 0 15 12 3 5 3 3 3 3 3" | ./histo


#  "Test 2: Test with numbers just outside the initial range"
echo "3 -4 5 1 7 0 8 0 15 12 3 5 18" | ./histo




#"Test 4: Test using bash syntax to generate a list of numbers"
echo 150 | ./histo


#  "Test 5: A test case with no numbers"
echo "" | ./histo

