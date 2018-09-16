#James Wilson (wilsjame)
#CS162 program1 Makefile

#define variables
CC=g++
CFLAGS= -c -Wall
objects = main.o Ant.o displayMenu.o getChoice.o

all: main

main: $(objects)
	$(CC) $(objects) -o main

main.o: main.cpp Ant.hpp displayMenu.hpp getChoice.hpp
	$(CC) $(CFLAGS) main.cpp

Ant.o: Ant.cpp Ant.hpp
	$(CC) $(CFLAGS) Ant.cpp

displayMenu.o: displayMenu.cpp displayMenu.hpp
	$(CC) $(CFLAGS) displayMenu.cpp

getChoice.o: getChoice.cpp getChoice.hpp
	$(CC) $(CFLAGS) getChoice.cpp

clean:  
	rm -rf $(objects) main
