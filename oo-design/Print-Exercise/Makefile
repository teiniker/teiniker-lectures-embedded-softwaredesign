CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: PrintTest  

init:
	mkdir -p build

Print.o: src/Print.cpp include/Print.h
	$(CC) $(CFLAGS) -c src/Print.cpp -o build/Print.o

ConsolePrint.o: src/ConsolePrint.cpp include/ConsolePrint.h
	$(CC) $(CFLAGS) -c src/ConsolePrint.cpp -o build/ConsolePrint.o

PrintTest.o: test/PrintTest.cpp
	$(CC) $(CFLAGS) -c test/PrintTest.cpp -o build/PrintTest.o

PrintTest: init PrintTest.o Print.o ConsolePrint.o
	$(CC) build/PrintTest.o build/ConsolePrint.o build/Print.o -o build/PrintTest $(LIBS)
	build/PrintTest

clean:
	rm -rf build/
