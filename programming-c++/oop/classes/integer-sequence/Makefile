CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: IntegerSequenceTest  

init:
	mkdir -p build

IntegerSequence.o: src/IntegerSequence.cpp include/IntegerSequence.h
	$(CC) $(CFLAGS) -c src/IntegerSequence.cpp -o build/IntegerSequence.o


IntegerSequenceTest.o: test/IntegerSequenceTest.cpp
	$(CC) $(CFLAGS) -c test/IntegerSequenceTest.cpp -o build/IntegerSequenceTest.o

IntegerSequenceTest: init IntegerSequenceTest.o IntegerSequence.o 
	$(CC) build/IntegerSequenceTest.o build/IntegerSequence.o -o build/IntegerSequenceTest $(LIBS)
	build/IntegerSequenceTest

clean:
	rm -rf build/
