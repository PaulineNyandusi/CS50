

OBJS = indexer.o
LIBS = -lm
L = ../libcs50

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I../common -I../libcs50

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all


LLIBS = $L/libcs50-given.a ../common/common.a 

.PHONY: test valgrind clean
# all: indexer ../libcs50/libcs50-given.a ../common/common.a

# executable depends on object files
indexer: $(OBJS) $(LLIBS) 
	$(CC) $(CFLAGS) $^ $(LLIBS) -o $@

indextest: indextest.o $(LLIBS)
	$(CC) $(CFLAGS) $^ $(LLIBS) -o $@
	
# object files depend on include files
indexer.o: ../common/pagedir.h ../libcs50/webpage.h ../libcs50/hashtable.h ../libcs50/counters.h ../common/index.h

indextest.o: ../libcs50/hashtable.h ../common/index.h

../common/common.a: 
	$(MAKE) -C ../common

test: indexer
	bash -v testing.sh &> testing.out

valgrind: indexer testing.sh 
	$(VALGRIND) ./indexer /thayerfs/home/f006bvq/cs50-dev/shared/students_files/tse/output/letters-1 index1.out

	
clean:
	rm -f indexer
	rm -f indextest
	rm -f *~ *.o
	rm -rf *.dSYM
	$(MAKE) -C ../common clean
