CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: test

init:
	mkdir -p build

CppTest.o: test/CppTest.cpp
	$(CC) $(CFLAGS) -c test/CppTest.cpp -o build/CppTest.o

test: init CppTest.o 
	$(CC) build/CppTest.o -o build/CppTest $(LIBS)
	build/CppTest -v

clean:
	rm -rf build/

