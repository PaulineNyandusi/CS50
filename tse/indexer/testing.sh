#!/bin/bash

# FileName: Testing.sh
# Author: Pauline Nyandusi
# Date: oct 23, 2023
# Description: Testing case


#invalid arguments
echo -e "Incorrect number of arguments"
./indexer  ~/cs50-/shared/studentsnot files /tse/output/letters-3


#no argument
echo -e "No argument"
./indexer 


#one argument
echo -e "One argument"
./indexer  ~/cs50-dev/shared/students_files/tse/output/letters-3 


echo -e "More than one argument"
./indexer  /thayerfs/home/f006bvq/cs50-dev/shared/students_files/tse/output/letters-3 index4.out 

./indexer /thayerfs/home/f006bvq/cs50-dev/shared/students_files/tse/output/letters-1 index5.out

./indexer /thayerfs/home/f006bvq/cs50-dev/shared/students_files/tse/output/toscrape-0 index6.out

#valid arguments

echo -e "Valid arguments"
./indexer  ~/cs50-dev/shared/students_files/tse/output/letters-3 index3.out

#indextest
echo -e "IndexTest"
./indextest /thayerfs/home/f006bvq/cs50-dev/tse-PaulineNyandusi/indexer/index7.out index.file


./indexer /thayerfs/home/f006bvq/cs50-dev/shared/students_files/tse/output/letters-1 index1.out

./indexer /thayerfs/home/f006bvq/cs50-dev/shared/students_files/tse/output/letters-2 index2.out

./indexer /thayerfs/home/f006bvq/cs50-dev/shared/students_files/tse/output/toscrape-1 index7.out
