CFLAGS = -std=c99 -g -Wall  
CC=gcc


all: main 

init:
	mkdir -p build

linked_list_user.o: src/linked_list_user.c include/linked_list_user.h 
	$(CC) $(CFLAGS) $(LDLIBS) -I./include -o build/linked_list_user.o -c src/linked_list_user.c 

lib: linked_list_user.o
	ar -cvq build/liblist.a build/*.o

install: lib
	mkdir -p libs
	mv build/liblist.a libs/

main.o: src/main.c  
	$(CC) $(CFLAGS) -I include -o build/main.o -c src/main.c
 
main: init install main.o  
	$(CC) $(CFLAGS) build/main.o -o build/main -L./libs -llist

clean:
	rm -rf build/ libs/ 

