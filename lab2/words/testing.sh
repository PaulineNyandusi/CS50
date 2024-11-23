#!/bin/bash
#File name: testing.sh
#Name : Pauline Nyandusi
#Date : Tuesday sept 26
#Summary: A bash script that tests words 
# 


# when no arguments are provided
echo "This is amazing, +i cant wait for @winter term. " | ./words

# when one argument is provided
./words test.txt


# when one argument is provided (but it's not valid)
./words tessst.txt

#one argument valid, the other argument valid
./words test.txt test.txt 

#one argument valid , next argument valid
./words test.txt tesrt.txt 

#all arguments invalid
./words testt.txt tesst.txt tesst.txt

#special file format
./words '-'