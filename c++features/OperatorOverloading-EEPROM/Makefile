CFLAGS=-g -Wall -I include
CC=g++
LIBS=-lstdc++ -lCppUTest -lCppUTestExt

all: EEPROMTest  

init:
	mkdir -p build

EEPROM.o: src/EEPROM.cpp include/EEPROM.h
	$(CC) $(CFLAGS) -c src/EEPROM.cpp -o build/EEPROM.o


EEPROMTest.o: test/EEPROMTest.cpp
	$(CC) $(CFLAGS) -c test/EEPROMTest.cpp -o build/EEPROMTest.o

EEPROMTest: init EEPROMTest.o EEPROM.o 
	$(CC) build/EEPROMTest.o build/EEPROM.o -o build/EEPROMTest $(LIBS)
	build/EEPROMTest

clean:
	rm -rf build/
