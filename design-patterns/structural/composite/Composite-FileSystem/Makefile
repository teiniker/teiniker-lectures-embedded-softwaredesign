CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: Test  

init:
	mkdir -p build

File.o: src/File.cpp include/File.h include/Node.h
	$(CC) $(CFLAGS) -c src/File.cpp -o build/File.o

Directory.o: src/Directory.cpp include/Directory.h include/Node.h 
	$(CC) $(CFLAGS) -c src/Directory.cpp -o build/Directory.o

FileSystemTest.o: test/FileSystemTest.cpp
	$(CC) $(CFLAGS) -c test/FileSystemTest.cpp -o build/FileSystemTest.o

Test: init FileSystemTest.o File.o Directory.o
	$(CC) build/FileSystemTest.o build/File.o build/Directory.o -o build/FileSystemTest $(LIBS)
	build/FileSystemTest

clean:
	rm -rf build/
