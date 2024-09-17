CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: Test  

init:
	mkdir -p build

PointersAndReferencesTest.o: test/PointersAndReferencesTest.cpp
	$(CC) $(CFLAGS) -c test/PointersAndReferencesTest.cpp -o build/PointersAndReferencesTest.o

Test: init PointersAndReferencesTest.o  
	$(CC) build/PointersAndReferencesTest.o -o build/PointersAndReferencesTest $(LIBS)
	build/PointersAndReferencesTest

clean:
	rm -rf build/
