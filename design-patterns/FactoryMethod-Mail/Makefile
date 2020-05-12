CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: Test  

init:
	mkdir -p build

Mail.o: src/Mail.cpp include/Mail.h
	$(CC) $(CFLAGS) -c src/Mail.cpp -o build/Mail.o

FactoryImpl.o: src/FactoryImpl.cpp include/FactoryImpl.h include/Factory.h
	$(CC) $(CFLAGS) -c src/FactoryImpl.cpp -o build/FactoryImpl.o

MailTest.o: test/MailTest.cpp
	$(CC) $(CFLAGS) -c test/MailTest.cpp -o build/MailTest.o

Test: init MailTest.o Mail.o FactoryImpl.o
	$(CC) build/MailTest.o build/Mail.o build/FactoryImpl.o -o build/MailTest $(LIBS)
	build/MailTest

clean:
	rm -rf build/
