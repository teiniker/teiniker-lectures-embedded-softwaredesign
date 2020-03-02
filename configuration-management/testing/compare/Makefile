
CFLAGS=-std=c99 -g -Wall
CC=gcc
INCLUDE=include
SRC=src
TEST=test
BUILD=build
UNITY=../unity

all: main test

init:
	mkdir -p build

compare.o: $(SRC)/compare.c $(INCLUDE)/compare.h
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/compare.c -o $(BUILD)/compare.o

main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)/main.c -o $(BUILD)/main.o

main: init compare.o main.o
	$(CC) $(CFLAGS) $(BUILD)/compare.o $(BUILD)/main.o -o $(BUILD)/main


unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o $(BUILD)/unity.o

compare_test.o: $(TEST)/compare_test.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -I $(UNITY) -c $(TEST)/compare_test.c -o $(BUILD)/compare_test.o

test: init unity.o compare_test.o
	$(CC) $(CFLAGS) $(BUILD)/unity.o $(BUILD)/compare_test.o -o $(BUILD)/test

clean:
	rm -rf build/

