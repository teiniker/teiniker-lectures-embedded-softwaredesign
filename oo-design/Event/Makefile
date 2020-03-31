CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: EventTest  

init:
	mkdir -p build

Time.o: src/Time.cpp include/Time.h
	$(CC) $(CFLAGS) -c src/Time.cpp -o build/Time.o

Date.o: src/Date.cpp include/Date.h
	$(CC) $(CFLAGS) -c src/Date.cpp -o build/Date.o

Event.o: src/Event.cpp include/Event.h
	$(CC) $(CFLAGS) -c src/Event.cpp -o build/Event.o

EventTest.o: test/EventTest.cpp
	$(CC) $(CFLAGS) -c test/EventTest.cpp -o build/EventTest.o

EventTest: init EventTest.o Time.o Date.o Event.o
	$(CC) build/EventTest.o build/Time.o build/Date.o build/Event.o -o build/EventTest $(LIBS)
	build/EventTest

clean:
	rm -rf build/
