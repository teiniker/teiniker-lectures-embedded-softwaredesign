CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: test

init:
	mkdir -p build

IOStreamTest.o: test/IOStreamTest.cpp
	$(CC) $(CFLAGS) -c test/IOStreamTest.cpp -o build/IOStreamTest.o

test: init IOStreamTest.o 
	$(CC) build/IOStreamTest.o -o build/IOStreamTest $(LIBS)
	build/IOStreamTest 

clean:
	rm -rf build/

