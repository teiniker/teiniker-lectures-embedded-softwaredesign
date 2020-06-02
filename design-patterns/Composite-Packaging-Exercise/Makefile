CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: Test  

init:
	mkdir -p build

Article.o: src/Article.cpp include/Article.h include/Node.h
	$(CC) $(CFLAGS) -c src/Article.cpp -o build/Article.o

Box.o: src/Box.cpp include/Box.h include/Node.h 
	$(CC) $(CFLAGS) -c src/Box.cpp -o build/Box.o

PackagingTest.o: test/PackagingTest.cpp
	$(CC) $(CFLAGS) -c test/PackagingTest.cpp -o build/PackagingTest.o

Test: init PackagingTest.o Article.o Box.o
	$(CC) build/PackagingTest.o build/Article.o build/Box.o -o build/PackagingTest $(LIBS)
	build/PackagingTest

clean:
	rm -rf build/
