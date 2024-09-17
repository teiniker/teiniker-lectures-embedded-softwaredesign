CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: OrderTest  

init:
	mkdir -p build

Product.o: src/Product.cpp include/Product.h
	$(CC) $(CFLAGS) -c src/Product.cpp -o build/Product.o

OrderLine.o: src/OrderLine.cpp include/OrderLine.h
	$(CC) $(CFLAGS) -c src/OrderLine.cpp -o build/OrderLine.o

Order.o: src/Order.cpp include/Order.h
	$(CC) $(CFLAGS) -c src/Order.cpp -o build/Order.o

OrderTest.o: test/OrderTest.cpp
	$(CC) $(CFLAGS) -c test/OrderTest.cpp -o build/OrderTest.o

OrderTest: init OrderTest.o Product.o OrderLine.o Order.o
	$(CC) build/OrderTest.o build/Product.o build/OrderLine.o build/Order.o -o build/OrderTest $(LIBS)
	build/OrderTest

clean:
	rm -rf build/
