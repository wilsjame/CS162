#James Wilson (wilsjame)
#CS 162 Project2 Makefile
#define variables
CXX = g++ #C++ compiler
CXXFLAGS = -std=c++0x
CXXFLAGS += -c 
#-Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g #debugging info

objects = main.o List.o Item.o

all: main

main: $(objects)
	$(CXX) $(objects) -o main

main.o: main.cpp List.hpp 
	$(CXX) $(CXXFLAGS) main.cpp

List.o: List.cpp List.hpp Item.hpp 
	$(CXX) $(CXXFLAGS) List.cpp

Item.o: Item.cpp Item.hpp 
	$(CXX) $(CXXFLAGS) Item.cpp

clean:
	rm -rf $(objects) main
	


