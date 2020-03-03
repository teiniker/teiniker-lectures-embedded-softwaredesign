CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: main  

init:
	mkdir -p build

complex_numbers.o: src/complex_numbers.c include/complex_numbers.h
	$(CC) $(CFLAGS) -I include -c src/complex_numbers.c -o build/complex_numbers.o

main.o: src/main.c
	$(CC) $(CFLAGS) -I include -c src/main.c -o build/main.o

main: init complex_numbers.o main.o
	$(CC) $(CFLAGS) build/complex_numbers.o build/main.o -o build/complex_numbers

clean:
	rm -rf build/

