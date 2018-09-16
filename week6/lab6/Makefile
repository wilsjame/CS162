#James Wilson (wilsjame)
#CS 162 Lab 6 Makefile

#variables
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -c #-Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g #debugging info

objects = main.o

all: main

main: $(objects)
	$(CXX) $(objects) -o main 

main.o: main.cpp 
	$(CXX) $(CXXFLAGS) main.cpp

clean: 
	rm -rf $(objects) main
