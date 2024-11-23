
CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I../libcs50

OBJS = pagedir.o index.o word.o
LLIBS = common.a

.PHONY: clean

# executable depends on object files
$(LLIBS): $(OBJS)
	ar cr $(LLIBS) $(OBJS)

# object files depend on include files
pagedir.o: pagedir.h
index.o: index.h ../libcs50/hashtable.h ../libcs50/counters.h
word.o: word.h 

clean:
	rm -f *~ *.o *.a
	rm -rf core
	rm -f common.a 
