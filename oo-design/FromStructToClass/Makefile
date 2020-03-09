CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: StructTest ClassTest 

init:
	mkdir -p build

StructTest.o: test/StructTest.cpp
	$(CC) $(CFLAGS) -c test/StructTest.cpp -o build/StructTest.o

StructTest: init StructTest.o 
	$(CC) build/StructTest.o -o build/StructTest $(LIBS)
	build/StructTest

ClassTest.o: test/ClassTest.cpp
	$(CC) $(CFLAGS) -c test/ClassTest.cpp -o build/ClassTest.o

ClassTest: init ClassTest.o 
	$(CC) build/ClassTest.o -o build/ClassTest $(LIBS)
	build/ClassTest

clean:
	rm -rf build/

