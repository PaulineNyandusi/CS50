#!/bin/bash

# testing.sh
# Author: Pauline Nyandusi
# Date: Oct 25, 2023
# Description: Bash script to test querier.c

echo -e "home" | ./querier ~/cs50-dev/shared/students_files/tse/output/letters-3 ~/cs50-dev/shared/students_files/tse/output/letters-3.index

# or at the front
echo -e "or at the front of the input"
echo "or" | ./querier ~/cs50-dev/shared/students_files/tse/output/letters-3 ~/cs50-dev/shared/students_files/tse/output/letters-3.index
echo -e "----------------------------------------"

# Testing with wrong use of AND and OR
# and at the front

echo -e "and at the front of the input"
echo "and" | ./querier ~/cs50-dev/shared/students_files/tse/output/letters-3 ~/cs50-dev/shared/students_files/tse/output/letters-3.index
echo -e "--------------------------------------"


# 'and 'next to 'or' 
echo -e "and 'next to 'or'"
echo "home and Or playground" | ./querier ~/cs50-dev/shared/students_files/tse/output/letters-3 ~/cs50-dev/shared/students_files/tse/output/letters-3.index
echo -e "--------------------------------------"

# and at the end
echo -e "and at the end of the query"
echo "home And" | ./querier ~/cs50-dev/shared/students_files/tse/output/letters-3 ~/cs50-dev/shared/students_files/tse/output/letters-3.index
echo -e "-----------------------------------------------"

# or at the end
echo -e " OR at the end of the query"
echo "playground or" | ./querier ~/cs50-dev/shared/students_files/tse/output/letters-3 ~/cs50-dev/shared/students_files/tse/output/letters-3.index
echo -e "-----------------------------------------------"

# Testing with invalid characters
echo -e "INVALID CHARACTERS"
echo "mum? ``" | ./querier ~/cs50-dev/shared/students_files/tse/output/letters-3 ~/cs50-dev/shared/students_files/tse/output/letters-3.index
echo -e "-----------------------------------------"

# Testing with valid arguments
echo -e " VALID ARGUMENTS "
echo "home And playground" | ./querier ~/cs50-dev/shared/students_files/tse/output/letters-3 ~/cs50-dev/shared/students_files/tse/output/letters-3.index
echo -e "-----------------------------------------------"

echo "home for" | valgrind ./querier ~/cs50-dev/shared/students_files/tse/output/letters-3 ~/cs50-dev/shared/students_files/tse/output/letters-3.index



echo -e "INVALID CHARACTERS"
echo "`54`" | ./querier ~/cs50-dev/shared/students_files/tse/output/letters-3 ~/cs50-dev/shared/students_files/tse/output/letters-3.index
echo -e "-----------------------------------------------"


echo -e "FUZZY QUERRY TEST"
./fuzzquery ~/cs50-dev/shared/students_files/tse/output/toscrape-2.index 10 0 | ./querier ~/cs50-dev/shared/students_files/tse/output/toscrape-2 ~/cs50-dev/shared/students_files/tse/output/toscrape-2.index
echo -e "-----------------------------------------------"

echo -e "FUZZY QUERRY TEST"
./fuzzquery ~/cs50-dev/shared/students_files/tse/output/toscrape-2.index 10 0
echo -e "---------------------------------------"

./fuzzquery ~/cs50-dev/shared/students_files/tse/output/toscrape-2.index 100 999 | ./querier ~/cs50-dev/shared/students_files/tse/output/toscrape-2 ~/cs50-dev/shared/students_files/tse/output/toscrape-2.index


./fuzzquery ~/cs50-dev/shared/students_files/tse/output/toscrape-2.index 5 100 | ./querier ~/cs50-dev/shared/students_files/tse/output/toscrape-2 ~/cs50-dev/shared/students_files/tse/output/toscrape-2.index