CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: UserTest  

init:
	mkdir -p build

User.o: src/User.cpp include/User.h
	$(CC) $(CFLAGS) -c src/User.cpp -o build/User.o


UserTest.o: test/UserTest.cpp
	$(CC) $(CFLAGS) -c test/UserTest.cpp -o build/UserTest.o

UserTest: init UserTest.o User.o
	$(CC) build/UserTest.o build/User.o -o build/UserTest $(LIBS)
	build/UserTest

clean:
	rm -rf build/
