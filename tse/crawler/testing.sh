#!/bin/bash

#Name: Pauline Nyandusi
#Date: 10/15/2023
#purpose


mkdir -p ../data/letters 

./crawler # Incorrect usage, 

# Less than 4 arguments
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data/letters

# Invalid URL
./crawler http://cs5.dartmouth.com/tse/letters/index.html ../data/letters 10

# Invalid directory
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../iwannagohome/letters 10

letters as seedURL at depth 0
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data/letters 0

# seedURL at depth 1
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data/letters 1

# seedURL at depth 2
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data/letters 2

# # seedURL at depth 10
# ./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ./data/letters 10

# # different seed URL
# /crawler http://cs50tse.cs.dartmouth.edu/tse/letters/D.html ./data/letters 2

# # toscrape as seedURL at depth 0
# ./crawler http://cs50tse.cs.dartmouth.edu/tse/toscrape/ ../data/toscrape 0

# # Ttoscrape as seedURL at depth 1
# •/crawler http://cs50tse.cs.dartmouth.edu/tse/toscrape/ ../data/toscrape 1

# #  toscrape as seedURL at depth 2
# ./crawler http://cs50tse.cs.dartmouth.edu/tse/toscrape/ ../data/toscrape 2

# #  toscrape as seedURL at depth 3
# ./crawler http: /http://cs50tse.cs.dartmouth.edu/tse/toscrape/ ../data/toscrape 10

# # wikipedia as seedURL at depth 0
# ./crawler https://cs50tse.cs.dartmouth.edu/tse/wikipedia/ ./data/wikipedia O

# # # Testing with wikipedia as seedURL at depth 1
# ./crawler https://cs50tse.cs.dartmouth.edu/tse/wikipedia/ •./data/wikipedia 1

# # wikipedia as seedURL at depth 2
# ./crawler https://cs50tse.cs.dartmouth.edu/tse/wikipedia/ ./data/wikipedia 2




