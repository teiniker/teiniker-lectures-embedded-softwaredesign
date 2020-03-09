CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: test

init:
	mkdir -p build

StringTest.o: test/StringTest.cpp
	$(CC) $(CFLAGS) -c test/StringTest.cpp -o build/StringTest.o

test: init StringTest.o 
	$(CC) build/StringTest.o -o build/StringTest $(LIBS)
	build/StringTest

clean:
	rm -rf build/

