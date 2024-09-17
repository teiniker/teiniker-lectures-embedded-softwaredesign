CFLAGS= -g -Wall  
CC=g++
LIBS=-lgtest -lgtest_main -pthread

all: run_test

build:
	mkdir -p build

build/can-msg.o: can-msg.cpp can-msg.h
	$(CC) $(CFLAGS) -c can-msg.cpp -o build/can-msg.o

build/test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp -o build/test.o

build/test: build build/can-msg.o build/test.o
	$(CC) $(CFLAGS) build/can-msg.o build/test.o -o build/test $(LIBS)

run_test: build/test 
	build/test

clean:
	rm -rf build/

