CFLAGS=-std=c99 -g -Wall  
CC=gcc

all: main

init:
	mkdir -p build

linked_list.o: init src/linked_list.c
	$(CC) $(CFLAGS) -I include -o build/linked_list.o -c src/linked_list.c 

main.o: src/main.c
	$(CC) $(CFLAGS) -I include -o build/main.o -c src/main.c

main: linked_list.o main.o
	$(CC) $(CFLAGS) build/linked_list.o build/main.o -o build/linked_list

clean:
	rm -rf build/

