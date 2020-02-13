CC=g++
CCFLAGS=-std=c++11
LIBS=-lm -lX

default: database.o dbDriver.o
	$(CC) database.o dbDriver.o $(CCFLAGS) -o dbDriver 

database.o: database.cpp database.h
	$(CC) $(CCFLAGS) database.cpp -c

dbDriver.o: dbDriver.cpp
	$(CC) $(CCFLAGS) dbDriver.cpp -c

run: default
	./dbDriver

clean:
	rm -f *.o
	rm -f dbDriver

