CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: Test  

init:
	mkdir -p build

GPIO.o: src/GPIO.cpp include/GPIO.h
	$(CC) $(CFLAGS) -c src/GPIO.cpp -o build/GPIO.o

Controller.o: src/Controller.cpp include/Controller.h
	$(CC) $(CFLAGS) -c src/Controller.cpp -o build/Controller.o

ControllerTest.o: test/ControllerTest.cpp
	$(CC) $(CFLAGS) -c test/ControllerTest.cpp -o build/ControllerTest.o

Test: init ControllerTest.o Controller.o GPIO.o 
	$(CC) build/ControllerTest.o build/Controller.o build/GPIO.o -o build/ControllerTest $(LIBS)
	build/ControllerTest

clean:
	rm -rf build/
