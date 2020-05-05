CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: UserTest  

init:
	mkdir -p build

Mail.o: src/Mail.cpp include/Mail.h
	$(CC) $(CFLAGS) -c src/Mail.cpp -o build/Mail.o

User.o: src/User.cpp include/User.h
	$(CC) $(CFLAGS) -c src/User.cpp -o build/User.o


UserTest.o: test/UserTest.cpp
	$(CC) $(CFLAGS) -c test/UserTest.cpp -o build/UserTest.o

UserTest: init UserTest.o User.o Mail.o
	$(CC) build/UserTest.o build/User.o build/Mail.o -o build/UserTest $(LIBS)
	build/UserTest

clean:
	rm -rf build/
