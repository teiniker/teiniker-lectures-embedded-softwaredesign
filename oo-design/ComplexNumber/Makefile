CFLAGS=-g -Wall  
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: main  

init:
	mkdir -p build

ComplexNumber.o: src/ComplexNumber.cpp include/ComplexNumber.h
	$(CC) $(CFLAGS) -I include -c src/ComplexNumber.cpp -o build/ComplexNumber.o

main.o: src/main.cpp
	$(CC) $(CFLAGS) -I include -c src/main.cpp -o build/main.o

main: init ComplexNumber.o main.o
	$(CC) $(CFLAGS) build/ComplexNumber.o build/main.o -o build/main

test.o: test/test.cpp
	$(CC) $(CFLAGS) -I include -c test/test.cpp -o build/test.o

test: init test.o ComplexNumber.o
	$(CC) $(CFLAGS) build/test.o build/ComplexNumber.o -o build/test $(LIBS)
	build/test

clean:
	rm -rf build/

