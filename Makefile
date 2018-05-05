CC=gcc
CFLAGS=-g -Wall
CPPFLAGS=-I.
LDFLAGS=-L.
LDLIBS=-lhash_table
SOURCES=test.c hash_table.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test
AR=ar
ARFLAGS=-rcs

all: ${EXECUTABLE}

clean:
	rm -f *.o *.a *.so ${EXECUTABLE}

%.o: %.c
	${CC} ${CPPFLAGS} ${CFLAGS} -c -o $@ $<

libhash_table.a: hash_table.o
	${AR} ${ARFLAGS} $@ $^

test: test.o libhash_table.a
	${CC} ${CFLAGS} -o $@ $< ${LDFLAGS} ${LDLIBS}

