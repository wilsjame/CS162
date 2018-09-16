#James Wilson (wilsjame)
#CS 162 Lab5 Makefile

#variables
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -c #-Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g #debugging info

objects = main.o reverseString.o sumArray.o triangleNum.o

all: main

main: $(objects)
	$(CXX) $(objects) -o main 

main.o: main.cpp reverseString.hpp sumArray.hpp triangleNum.hpp
	$(CXX) $(CXXFLAGS) main.cpp

reverseString.o: reverseString.cpp reverseString.hpp 
	$(CXX) $(CXXFLAGS) reverseString.cpp

sumArray.o: sumArray.cpp sumArray.hpp
	$(CXX) $(CXXFLAGS) sumArray.cpp
	
triangleNum.o: triangleNum.cpp triangleNum.hpp
	$(CXX) $(CXXFLAGS) triangleNum.cpp

clean: 
	rm -rf $(objects) main




