CFLAGS= -g -Wall  
CC=g++
LIBS=-lgtest -lgtest_main -pthread

all: run_test

build:
	mkdir -p build

build/resistor.o: resistor.cpp resistor.h
	$(CC) $(CFLAGS) -c resistor.cpp -o build/resistor.o

build/test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp -o build/test.o

build/test: build build/resistor.o build/test.o
	$(CC) $(CFLAGS) build/resistor.o build/test.o -o build/test $(LIBS)

run_test: build/test 
	build/test

clean:
	rm -rf build/

