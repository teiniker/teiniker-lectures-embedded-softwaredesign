CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: main  

init:
	mkdir -p build

linked_list.o: src/linked_list.c include/linked_list.h
	$(CC) $(CFLAGS) -I include -c src/linked_list.c -o build/linked_list.o

main.o: src/main.c
	$(CC) $(CFLAGS) -I include -c src/main.c -o build/main.o

main: init linked_list.o main.o
	$(CC) $(CFLAGS) build/linked_list.o build/main.o -o build/linked_list

clean:
	rm -rf build/

