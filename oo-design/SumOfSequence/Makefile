CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: CalculatorTest  

init:
	mkdir -p build

CalculatorFast.o: src/CalculatorFast.cpp include/CalculatorFast.h
	$(CC) $(CFLAGS) -c src/CalculatorFast.cpp -o build/CalculatorFast.o

CalculatorSlow.o: src/CalculatorSlow.cpp include/CalculatorSlow.h
	$(CC) $(CFLAGS) -c src/CalculatorSlow.cpp -o build/CalculatorSlow.o

CalculatorTest.o: test/CalculatorTest.cpp
	$(CC) $(CFLAGS) -c test/CalculatorTest.cpp -o build/CalculatorTest.o

CalculatorTest: init CalculatorTest.o CalculatorFast.o CalculatorSlow.o
	$(CC) build/CalculatorTest.o build/CalculatorFast.o build/CalculatorSlow.o -o build/CalculatorTest $(LIBS)
	build/CalculatorTest

clean:
	rm -rf build/
