CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: Test  

init:
	mkdir -p build

User.o: src/User.cpp include/User.h
	$(CC) $(CFLAGS) -c src/User.cpp -o build/User.o

UserTableImpl.o: src/UserTableImpl.cpp include/UserTableImpl.h include/UserTable.h
	$(CC) $(CFLAGS) -c src/UserTableImpl.cpp -o build/UserTableImpl.o

UserTableProxy.o: src/UserTableProxy.cpp include/UserTableProxy.h 
	$(CC) $(CFLAGS) -c src/UserTableProxy.cpp -o build/UserTableProxy.o

UserTableTest.o: test/UserTableTest.cpp
	$(CC) $(CFLAGS) -c test/UserTableTest.cpp -o build/UserTableTest.o

Test: init UserTableTest.o User.o UserTableImpl.o UserTableProxy.o
	$(CC) build/UserTableTest.o build/User.o build/UserTableImpl.o build/UserTableProxy.o -o build/UserTableTest $(LIBS)
	build/UserTableTest

clean:
	rm -rf build/
