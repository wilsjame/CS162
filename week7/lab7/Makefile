#James Wilson (wilsjame)
#CS 162 Lab 7 Makefile

#variables
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -c #-Wall
CXXFLAGS += -g
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g #debugging info

objects = main.o Queue.o

all: main

main: $(objects)
	$(CXX) $(objects) -o main 

main.o: main.cpp Queue.hpp 
	$(CXX) $(CXXFLAGS) main.cpp

Queue.o: Queue.cpp Queue.hpp 
	$(CXX) $(CXXFLAGS) Queue.cpp

clean: 
	rm -rf $(objects) main
