

OBJS = crawler.o
LIBS = -lm
L = ../libcs50

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I$L../common

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all


LLIBS = $L/libcs50-given.a ../common/common.a

.PHONY: test valgrind clean
all: crawler ../libcs50/libcs50-given.a ../common/common.a

# executable depends on object files
crawler: $(OBJS)
	$(MAKE) -C ../common
	$(CC) $(CFLAGS) $^ $(LLIBS) -o $@

# object files depend on include files
crawler.o: $L/bag.h $L/file.h

test: testing.sh
	bash -v testing.sh

valgrind: testing.sh 
	$(VALGRIND) bash -v testing.sh
	
clean:
	rm -f crawler
	rm -f ../common/common.a
	rm -f *~ *.o
	rm -rf *.dSYM
	$(MAKE) -C ../common clean
