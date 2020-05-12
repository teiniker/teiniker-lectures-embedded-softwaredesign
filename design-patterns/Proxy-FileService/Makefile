CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: FileServiceTest  

init:
	mkdir -p build

FileServiceImpl.o: src/FileServiceImpl.cpp include/FileServiceImpl.h include/FileService.h
	$(CC) $(CFLAGS) -c src/FileServiceImpl.cpp -o build/FileServiceImpl.o

FileServiceProxy.o: src/FileServiceProxy.cpp include/FileServiceProxy.h
	$(CC) $(CFLAGS) -c src/FileServiceProxy.cpp -o build/FileServiceProxy.o

FactoryImpl.o: src/FactoryImpl.cpp include/FactoryImpl.h include/Factory.h
	$(CC) $(CFLAGS) -c src/FactoryImpl.cpp -o build/FactoryImpl.o


FileServiceTest.o: test/FileServiceTest.cpp
	$(CC) $(CFLAGS) -c test/FileServiceTest.cpp -o build/FileServiceTest.o

FileServiceTest: init FileServiceTest.o FileServiceImpl.o FileServiceProxy.o FactoryImpl.o
	$(CC) build/FileServiceTest.o build/FileServiceImpl.o build/FileServiceProxy.o build/FactoryImpl.o -o build/FileServiceTest $(LIBS)
	build/FileServiceTest

clean:
	rm -rf build/
