#!/bin/bash
#Script name: testing.sh
#Name : Pauline Nyandusi
#Date : 26th sept 2023
#Summary: A bash script that tests chill.c


#!/bin/bash

# zero arguments, ensures the programs handles it when no arguments are passed
./chill

# one argument, a test for only one argument, which is temperature
./chill 32

# two arguments, a test for when temp and wing speed are inputs

./chill 32.5 10

# temp out of range, test that checks if the temperature is not out of range
./chill 55

# wind out of range, for for if the wind is out of range
./chill 10 0

# negative temperature
./chill -5 15

# negative wind speed
./chill 20 -5

# more than two arguments
./chill 32 10 50

# when its not a digit
./chill hui

#temp outt of range and wind in range 
./chill 68 10

#wind out of range and temp in range
./chill 23 567

#both out of range
./chill 53 456

#both out of rangr, lower rfangr
./chill -254 0
