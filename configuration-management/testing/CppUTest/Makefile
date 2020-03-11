CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: test

init:
	mkdir -p build

SprintfTest.o: test/SprintfTest.cpp
	$(CC) $(CFLAGS) -c test/SprintfTest.cpp -o build/SprintfTest.o

test: init SprintfTest.o 
	$(CC) build/SprintfTest.o -o build/SprintfTest $(LIBS)
	build/SprintfTest -v

clean:
	rm -rf build/

