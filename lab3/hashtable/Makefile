# Makefile for 'hashtable' module
#
# David Kotz, April 2016, 2017, 2019, 2021
# updated by Xia Zhou, July 2016, 2018, January 2019

OBJS = hashtabletest.o hashtable.o ../lib/file.o ../lib/mem.o ../set/set.o hash.o
LIBS =

# uncomment the following to turn on verbose memory logging
#TESTING=-DMEMTEST

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib
CC = gcc
MAKE = make
# for memory-leak tests
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

hashtabletest: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

hashtabletest.o: hashtable.h ../lib/file.h  ../set/set.h
hashtable.o: hashtable.h ../set/set.h
../lib/file.o: ../lib/file.h
../set/set.o: ../set/set.h
hash.o: hash.h
.PHONY: test valgrind clean

# expects a file `test.names` to exist; it can contain any text.
test: hashtabletest 
	./hashtabletest &> testing.out
	
# expects a file `test.names` to exist; it can contain any text.
valgrind: hashtabletest 
	$(VALGRIND) ./hashtabletest 

clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o
	rm -f hashtabletest
	rm -f core
