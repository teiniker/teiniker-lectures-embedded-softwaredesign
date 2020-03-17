CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: LCDTest  

init:
	mkdir -p build

LCD.o: src/LCD.cpp include/LCD.h
	$(CC) $(CFLAGS) -c src/LCD.cpp -o build/LCD.o


LCDTest.o: test/LCDTest.cpp
	$(CC) $(CFLAGS) -c test/LCDTest.cpp -o build/LCDTest.o

LCDTest: init LCDTest.o LCD.o 
	$(CC) build/LCDTest.o build/LCD.o -o build/LCDTest $(LIBS)
	build/LCDTest

clean:
	rm -rf build/
