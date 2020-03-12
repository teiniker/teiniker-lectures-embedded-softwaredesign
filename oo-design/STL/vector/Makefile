CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: test

init:
	mkdir -p build

VectorTest.o: test/VectorTest.cpp
	$(CC) $(CFLAGS) -c test/VectorTest.cpp -o build/VectorTest.o

test: init VectorTest.o 
	$(CC) build/VectorTest.o -o build/VectorTest $(LIBS)
	build/VectorTest 

clean:
	rm -rf build/

