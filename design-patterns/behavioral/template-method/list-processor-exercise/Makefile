CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: Test  

init:
	mkdir -p build

SortAlgorithm.o: src/SortAlgorithm.cpp include/SortAlgorithm.h
	$(CC) $(CFLAGS) -c src/SortAlgorithm.cpp -o build/SortAlgorithm.o

BubbleSortAsc.o: src/BubbleSortAsc.cpp include/BubbleSortAsc.h include/SortAlgorithm.h
	$(CC) $(CFLAGS) -c src/BubbleSortAsc.cpp -o build/BubbleSortAsc.o

BubbleSortDes.o: src/BubbleSortDes.cpp include/BubbleSortDes.h include/SortAlgorithm.h 
	$(CC) $(CFLAGS) -c src/BubbleSortDes.cpp -o build/BubbleSortDes.o

SortAlgorithmTest.o: test/SortAlgorithmTest.cpp
	$(CC) $(CFLAGS) -c test/SortAlgorithmTest.cpp -o build/SortAlgorithmTest.o

Test: init SortAlgorithmTest.o BubbleSortDes.o BubbleSortAsc.o SortAlgorithm.o
	$(CC) build/SortAlgorithmTest.o build/BubbleSortDes.o build/BubbleSortAsc.o build/SortAlgorithm.o -o build/SortAlgorithmTest $(LIBS)
	build/SortAlgorithmTest

clean:
	rm -rf build/
