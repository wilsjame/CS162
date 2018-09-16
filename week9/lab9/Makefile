#James Wilson (wilsjame)
#CS 162 Lab 9 Makefile

#variables
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -c #-Wall
CXXFLAGS += -g
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g #debugging info

objects = main.o Buffer.o Palindrome.o

all: main

main: $(objects)
	$(CXX) $(objects) -o main 

main.o: main.cpp Buffer.hpp Palindrome.o 
	$(CXX) $(CXXFLAGS) main.cpp

Buffer.o: Buffer.cpp Buffer.hpp 
	$(CXX) $(CXXFLAGS) Buffer.cpp

Palindrome.o: Palindrome.cpp Palindrome.hpp 
	$(CXX) $(CXXFLAGS) Palindrome.cpp

clean: 
	rm -rf $(objects) main
