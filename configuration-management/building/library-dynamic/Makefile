CFLAGS = -std=c99 -g -Wall -fPIC  
CC=gcc


all: main 

init:
	mkdir -p build
	
linked_list_user.o: src/linked_list_user.c include/linked_list_user.h 
	$(CC) $(CFLAGS) $(LDLIBS) -I include -o build/linked_list_user.o -c src/linked_list_user.c  

lib: linked_list_user.o
	$(CC) -shared -o build/liblist.so build/*.o

install: init lib
	mkdir -p libs
	mv build/liblist.so libs/

main.o: src/main.c  
	$(CC) $(CFLAGS) $(LDLIBS) -I include -o build/main.o -c src/main.c  

main: install main.o
	$(CC) $(CFLAGS) $(LDLIBS) build/main.o -o build/main -L./libs -llist 

clean:
	rm -rf build/ libs/

