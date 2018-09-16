#James Wilson (wilsjame)
#CS162 lab1 Makefile

#define variables
CC=g++
CFLAGS= -c -Wall
objects = main.o determinant.o readMatrix.o

all: main 

main: $(objects)
	$(CC) $(objects) -o main

main.o: main.cpp determinant.hpp readMatrix.hpp
	$(CC) $(CFLAGS) main.cpp 

determinant.o: determinant.cpp determinant.hpp
	$(CC) $(CFLAGS) determinant.cpp 

readMatrix.o: readMatrix.cpp readMatrix.hpp
	$(CC) $(CFLAGS)  readMatrix.cpp 

clean:
	rm -rf $(objects) main
