all: build/hello

build:
	mkdir -p build

build/_hello.cpp: hello.cpp
	cpp hello.cpp build/_hello.cpp

build/_hello.s: build/_hello.cpp
	g++ -Wall -g -S build/_hello.cpp -o build/_hello.s

build/hello.o : build/_hello.s
	as -o build/hello.o build/_hello.s

build/hello: build build/hello.o
	g++ -o build/hello build/hello.o

clean:
	rm -rf build/
