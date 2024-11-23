# Makefile for 'querier' module
#
# Pauline Nyandusi, October 30th 2023


OBJS = querier.o
OBJS_2 = fuzzquery.o
LIBS = -lm
L = ../libcs50

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I../common -I../libcs50

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all


LLIBS = $L/libcs50-given.a ../common/common.a 

.PHONY: test valgrind clean
# all: querier ../libcs50/libcs50-given.a ../common/common.a

# executable depends on object files
querier: $(OBJS) $(LLIBS) 
	$(CC) $(CFLAGS) $^ $(LLIBS) -o $@

fuzzquery: $(OBJS_2) $(LLIBS) 
	$(CC) $(CFLAGS) $^ $(LLIBS) -o $@

# object files depend on include files
querier.o: ../common/pagedir.h ../libcs50/webpage.h ../libcs50/hashtable.h ../libcs50/counters.h ../common/index.h ../common/word.h ../libcs50/file.h 

all: querier 

../common/common.a: 
	$(MAKE) -C ../common

test: querier
	bash -v testing.sh &> testing.out
	

valgrind: querier testing.sh
	$(VALGRIND) ./querier ~/cs50-dev/shared/students_files/tse/output/letters-3 ~/cs50-dev/shared/students_files/tse/output/letters-3.index
	
clean:
	rm -f querier
	rm -f *~ *.o
	rm -rf *.dSYM
	$(MAKE) -C ../common clean
