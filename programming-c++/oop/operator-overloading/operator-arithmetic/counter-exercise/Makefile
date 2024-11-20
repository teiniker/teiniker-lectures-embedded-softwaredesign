CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: Test  

init:
	mkdir -p build

Counter.o: src/Counter.cpp include/Counter.h
	$(CC) $(CFLAGS) -c src/Counter.cpp -o build/Counter.o

CounterTest.o: test/CounterTest.cpp
	$(CC) $(CFLAGS) -c test/CounterTest.cpp -o build/CounterTest.o

Test: init CounterTest.o Counter.o
	$(CC) build/CounterTest.o build/Counter.o -o build/CounterTest $(LIBS)
	build/CounterTest

clean:
	rm -rf build/
