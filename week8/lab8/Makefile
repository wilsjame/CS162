#James Wilson (wilsjame)
#CS 162 Lab 8 Makefile

#variables
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -c #-Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g #debugging info

objects = main.o createData.o searchVector.o sortVector.o binarySearch.o

all: main

main: $(objects)
	$(CXX) $(objects) -o main 

main.o: main.cpp createData.hpp searchVector.hpp sortVector.o binarySearch.o
	$(CXX) $(CXXFLAGS) main.cpp

createData.o: createData.cpp createData.hpp 
	$(CXX) $(CXXFLAGS) createData.cpp

searchVector.o: searchVector.cpp searchVector.hpp 
	$(CXX) $(CXXFLAGS) searchVector.cpp

sortVector.o: sortVector.cpp sortVector.hpp 
	$(CXX) $(CXXFLAGS) sortVector.cpp

binarySearch.o: binarySearch.cpp binarySearch.hpp 
	$(CXX) $(CXXFLAGS) binarySearch.cpp

clean: 
	rm -rf $(objects) main *.txt
