CFLAGS=-std=c99 -g -Wall  
CC=gcc
UNITY=../unity

all: main test

init:
	mkdir -p build

linked_list.o: init src/linked_list.c
	$(CC) $(CFLAGS) -I include -o build/linked_list.o -c src/linked_list.c 

main.o: src/main.c
	$(CC) $(CFLAGS) -I include -o build/main.o -c src/main.c

main: linked_list.o main.o
	$(CC) $(CFLAGS) build/linked_list.o build/main.o -o build/linked_list


unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -o build/unity.o -c $(UNITY)/unity.c 

linked_list_test.o: test/linked_list_test.c
	$(CC) $(CFLAGS) -I include -I $(UNITY) -o build/linked_list_test.o -c test/linked_list_test.c 

test: init unity.o linked_list.o linked_list_test.o
	$(CC) $(CFLAGS) build/unity.o build/linked_list.o build/linked_list_test.o -o build/test

clean:
	rm -rf build/

