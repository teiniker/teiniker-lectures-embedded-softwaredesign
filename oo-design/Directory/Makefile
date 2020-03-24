CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: DirectoryTest  

init:
	mkdir -p build

File.o: src/File.cpp include/File.h
	$(CC) $(CFLAGS) -c src/File.cpp -o build/File.o

Directory.o: src/Directory.cpp include/Directory.h
	$(CC) $(CFLAGS) -c src/Directory.cpp -o build/Directory.o


DirectoryTest.o: test/DirectoryTest.cpp
	$(CC) $(CFLAGS) -c test/DirectoryTest.cpp -o build/DirectoryTest.o

DirectoryTest: init DirectoryTest.o Directory.o File.o
	$(CC) build/DirectoryTest.o build/Directory.o build/File.o -o build/DirectoryTest $(LIBS)
	build/DirectoryTest

clean:
	rm -rf build/
