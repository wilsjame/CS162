#James Wilson (wilsjame)
#CS 162 Lab 10 Makefile

#variables
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -c #-Wall
CXXFLAGS += -g
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
