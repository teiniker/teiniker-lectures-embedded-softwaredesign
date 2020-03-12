CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: test

init:
	mkdir -p build

IntegerTest.o: test/IntegerTest.cpp
	$(CC) $(CFLAGS) -c test/IntegerTest.cpp -o build/IntegerTest.o

test: init IntegerTest.o 
	$(CC) build/IntegerTest.o -o build/IntegerTest $(LIBS)
	build/IntegerTest

clean:
	rm -rf build/

