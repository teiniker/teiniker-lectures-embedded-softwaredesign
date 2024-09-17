CC=g++
CFLAGS= -g -Wall  
LIBS=-lgtest -lgtest_main -pthread

all: run_test

build:
	mkdir -p build

build/date.o: date.cpp date.h
	$(CC) $(CFLAGS) -c date.cpp -o build/date.o

build/test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp -o build/test.o

build/test: build build/date.o build/test.o
	$(CC) $(CFLAGS) build/date.o build/test.o -o build/test $(LIBS)

run_test: build/test 
	build/test

clean:
	rm -rf build/

