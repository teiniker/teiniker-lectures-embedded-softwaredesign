CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: Test  

init:
	mkdir -p build

Complex.o: src/Complex.cpp include/Complex.h
	$(CC) $(CFLAGS) -c src/Complex.cpp -o build/Complex.o

ComplexTest.o: test/ComplexTest.cpp
	$(CC) $(CFLAGS) -c test/ComplexTest.cpp -o build/ComplexTest.o

Test: init ComplexTest.o Complex.o
	$(CC) build/ComplexTest.o build/Complex.o -o build/ComplexTest $(LIBS)
	build/ComplexTest

clean:
	rm -rf build/
