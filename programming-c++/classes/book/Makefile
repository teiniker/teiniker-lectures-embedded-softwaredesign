CC=g++
CFLAGS= -g -Wall -I.  
LIBS=-lgtest -lgtest_main -pthread

all: run_test

build:
	mkdir -p build

build/book.o: book.cpp book.h
	$(CC) $(CFLAGS) -c book.cpp -o build/book.o

build/test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp -o build/test.o

build/test: build build/book.o build/test.o
	$(CC) $(CFLAGS) build/book.o build/test.o -o build/test $(LIBS)

run_test: build/test 
	build/test

clean:
	rm -rf build/

