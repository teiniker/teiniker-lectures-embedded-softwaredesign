CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: Test  

init:
	mkdir -p build

Mail.o: src/Mail.cpp include/Mail.h
	$(CC) $(CFLAGS) -c src/Mail.cpp -o build/Mail.o


MailTest.o: test/MailTest.cpp
	$(CC) $(CFLAGS) -c test/MailTest.cpp -o build/MailTest.o

Test: init MailTest.o Mail.o
	$(CC) build/MailTest.o build/Mail.o -o build/MailTest $(LIBS)
	build/MailTest

clean:
	rm -rf build/
