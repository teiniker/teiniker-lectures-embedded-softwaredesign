CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: FileServiceTest  

init:
	mkdir -p build

FileService.o: src/FileService.cpp include/FileService.h
	$(CC) $(CFLAGS) -c src/FileService.cpp -o build/FileService.o

DataService.o: src/DataService.cpp include/DataService.h
	$(CC) $(CFLAGS) -c src/DataService.cpp -o build/DataService.o


FileServiceTest.o: test/FileServiceTest.cpp
	$(CC) $(CFLAGS) -c test/FileServiceTest.cpp -o build/FileServiceTest.o

FileServiceTest: init FileServiceTest.o FileService.o DataService.o 
	$(CC) build/FileServiceTest.o build/FileService.o build/DataService.o -o build/FileServiceTest $(LIBS)
	build/FileServiceTest

clean:
	rm -rf build/
