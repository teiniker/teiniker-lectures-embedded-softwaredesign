
CFLAGS=-std=c99 -g -Wall  
CC=gcc
INCLUDE=include

all: main  

init:
	mkdir -p build

linked_list.o: init src/linked_list.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c src/linked_list.c -o build/linked_list.o

main.o: src/main.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c src/main.c -o build/main.o

main: linked_list.o main.o
	$(CC) $(CFLAGS) build/linked_list.o build/main.o -o build/linked_list

clean:
	rm -rf build/

